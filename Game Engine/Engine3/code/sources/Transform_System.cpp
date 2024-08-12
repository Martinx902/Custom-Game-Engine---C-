// @author Martin Pérez Villabrille
// Copyright (c) 2023 + UDIT
// Mgine -- All rights reserved

#include "../headers/Transform_System.hpp"
#include "../headers/Render_Component.hpp"

#include <glm/mat4x4.hpp>

namespace Mgine
{
	void Transform_System::create_component
	(
		Entity* entity_id,
		const string& component_id,
		const xml_node<>* data
	)
	{
		string component_type = data->first_attribute("type")->value();

		shared_ptr< Transform_Component > transform_component(new Transform_Component(entity_id));

		transform_component->parse(data, entity_id);

		entity_id->add_component(component_type, transform_component);

		entity_id->set_transform(*transform_component);

		components.push_back(transform_component);
	}

	void Transform_System::execute(float t)
	{
		for (auto& component : components)
		{
			mat4 transform_matrix =
				component.get()->get_parent()->get_transform().get_transform_matrix();

			auto model_component = dynamic_cast<Render_Component*>(component->get_parent()->get_component_by_id("render"));

            if (model_component->type == model_component->MODEL)
            {
                model_component->get_parent()->get_transform().rotation.z += 0.001f * t/2;
            }

			model_component->get_object()->set_transformation(transform_matrix);
		}
	}
}