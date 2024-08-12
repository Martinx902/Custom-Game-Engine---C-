// @author Martin Pérez Villabrille
// Copyright (c) 2023 + UDIT
// Mgine -- All rights reserved

#include "..\headers\Control_System.hpp"
#include "..\headers\Entity.hpp"

namespace Mgine
{
	void Control_System::create_component
	(
		Entity* entity_id,
		const std::string& component_id,
		const rapidxml::xml_node<>* data
	)
	{
		auto component = std::make_shared<Control_Component>();

		std::string factory_id = ""; //Sacarlo de alguna etiqueta de data o mismamente de component_id

		auto factory = controller_factories[factory_id];

		component->controller = factory();

		entity_id->add_component(component_id, component);

		components.push_back(component);
	}

	void Control_System::execute(float t)
	{
		for (auto & component : components)
		{
			component->controller->update(component->get_parent(), t);
		}
	}
}