// @author Martin Pérez Villabrille
// Copyright (c) 2023 + UDIT
// Mgine -- All rights reserved

#include <string>

#include "../headers/Render_Component.hpp"
#include "../headers/rapid_xml/rapidxml.hpp"

namespace Mgine
{
	void Render_Component::parse(const xml_node<>* node, Entity* entity)
	{
		xml_attribute<>* attribute = node->first_attribute()->next_attribute();

		string name = string(attribute->value());

		if (name == "modelObj")
		{
			type = MODEL;

			parse_model(node, attribute);
		}
		else if (name == "camera")
		{
			type = CAMERA;

			parse_camera(node, attribute);
		}
		else if (name == "light")
		{
			type = LIGHT;
		}
	}

	void Render_Component::parse_model(const xml_node<>* node, xml_attribute<>* attribute)
	{
		if (string(attribute->next_attribute()->name()) == "mesh_path")
		{
			data.path = string(attribute->next_attribute()->value());
		}
	}

	void Render_Component::parse_camera(const xml_node<>* node, xml_attribute<>* attribute) 
	{
		for 
		(
			xml_attribute<>* attribute = node->first_attribute()->next_attribute()->next_attribute(); 
			attribute; attribute = 
			attribute->next_attribute()
		)
		{
			if (string(attribute->name())	   == "fov"  )	data.fov   = stof(attribute->value());
			else if (string(attribute->name()) == "near" )  data.near  = stof(attribute->value());
			else if (string(attribute->name()) == "far"  )	data.far   = stof(attribute->value());
			else if (string(attribute->name()) == "ratio")	data.ratio = stof(attribute->value());
		}
	}
}