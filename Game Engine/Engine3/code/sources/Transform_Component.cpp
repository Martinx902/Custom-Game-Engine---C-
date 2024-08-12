// @author Martin Pérez Villabrille
// Copyright (c) 2023 + UDIT
// Mgine -- All rights reserved

#include <string>

#include "../headers/Transform_Component.hpp"
#include "../headers/Entity.hpp"
#include "../headers/Scene.hpp"

#include <Render_Node.hpp>

namespace Mgine
{
	mat4 Transform_Component::get_transform_matrix()
	{
		mat4 matrix(1);

		matrix = glm::translate(matrix, position);
		matrix = glm::scale(matrix, scale);
		matrix = glm::rotate(matrix, rotation.x, vec3(1, 0, 0));
		matrix = glm::rotate(matrix, rotation.y, vec3(0, 1, 0));
		matrix = glm::rotate(matrix, rotation.z, vec3(0, 0, 1));

		if (transform_parent)
			return transform_parent->get_transform_matrix() * matrix;
		else
			return matrix;
	}

	void Transform_Component::parse(const xml_node<>* node, Entity* entity)
	{
		for (xml_attribute<>* attribute = node->first_attribute(); attribute; attribute = attribute->next_attribute())
		{
			if (string(attribute->name()) == "pos_x")	position.x = stof(attribute->value());
			else if (string(attribute->name()) == "pos_y")  position.y = stof(attribute->value());
			else if (string(attribute->name()) == "pos_z")	position.z = stof(attribute->value());

			else if (string(attribute->name()) == "rot_x")	rotation.x = stof(attribute->value());
			else if (string(attribute->name()) == "rot_y")	rotation.y = stof(attribute->value());
			else if (string(attribute->name()) == "rot_z")	rotation.z = stof(attribute->value());

			else if (string(attribute->name()) == "scl_x")	scale.x = stof(attribute->value());
			else if (string(attribute->name()) == "scl_y")	scale.y = stof(attribute->value());
			else if (string(attribute->name()) == "scl_z")	scale.z = stof(attribute->value());

			//Set parent by getting the entity on the scene with the specified id
			else if (string(attribute->name()) == "parent")
			{
				if (entity->get_scene()->get_entity_by_id(string(attribute->value())))
				{
					transform_parent = &entity->get_scene()->get_entity_by_id(string(attribute->value()))->get_transform();
				}
			}
		}
	}
}