// @author Martin Pérez Villabrille
// Copyright (c) 2023 + UDIT
// Mgine -- All rights reserved

#include <fstream>
#include <iostream>

#include "..\headers\Scene.hpp"
#include "..\headers\System_Factory.hpp"

namespace Mgine
{
	Scene::Scene(const string& path) : input_task(2, this), message_dispatcher(3, this)
	{
		//Add basic scene tasks

		kernel.add(&input_task);
		kernel.add(&message_dispatcher);

		load_scene(path);
	}

	bool Scene::load_scene(const string& path)
	{
		ifstream file(path, ifstream::binary);

		if (file.good())
		{
			file.seekg(0, ifstream::end);
			size_t size = file.tellg();
			file.seekg(0, ifstream::beg);

			string xml_data(size, '\0');

			file.read(&xml_data[0], size);
			file.close();

			//Data to xml
			xml_document<> document;
			document.parse<0>(xml_data.data());
			xml_node<>* scene_node = document.first_node();

			//Load scene
			if (scene_node && string(scene_node->name()) == "scene")
			{
				parse_entity(scene_node);
			}

			return true;
		}

		return false;
	}

	void Scene::parse_entity(xml_node<>* scene_node)
	{
		//All the entities of the scene
		for
			(
				auto  child = scene_node->first_node();
				child;
				child = child->next_sibling()
				)
		{
			string child_name = string(child->name());

			//Create game window
			if (child_name == "window")
			{
				string name;
				string width;
				string height;
				string str_fullscreen;
				bool fullscreen = false;

				for
					(
						auto  window_node = child->first_attribute();
						window_node;
						window_node = window_node->next_attribute()
						)
				{
					if (string(window_node->name()) == "name")       name = string(window_node->value());
					else if (string(window_node->name()) == "width")      width = string(window_node->value());
					else if (string(window_node->name()) == "height")     height = string(window_node->value());
					else if (string(window_node->name()) == "fullscreen") str_fullscreen = string(window_node->value());
				}

				if (str_fullscreen == "true")
					fullscreen = true;
				else if (str_fullscreen == "false")
					fullscreen = false;

				window = new Window(name, stoi(width), stoi(height), fullscreen);
			}

			//If we find a new entity save it and create its components
			if (child_name == "entity")
			{
				auto entity = make_shared< Entity >(this);
				auto id_attribute = child->first_attribute("name");

				if (id_attribute)
				{
					string id = id_attribute->value();
					entities[id] = entity;

					//Parse the components from the nodes
					for
						(
							xml_node<>* component_node = child->first_node();
							component_node;
							component_node = component_node->next_sibling()
							)
					{
						if (component_node->type() == node_element)
						{
							if (string(component_node->name()) == "component")
								parse_components(component_node, id, entity.get());
						}
					}
				}
			}
		}
	}

	void Scene::parse_components(xml_node<>* component_node, string& id, Entity* entity)
	{
		string type;
		bool new_system_created = false;

		type = component_node->first_attribute("type")->value();

		//If no system yet created make a new one
		if (systems.count(type) == 0)
		{
			shared_ptr<System_Factory> st;
			st.reset(new System_Factory());
			systems[type] = st->create_system(type, this);
			new_system_created = true;
		}

		//Create the component in the system
		System* system = systems[type].get();
		system->create_component(entity, id, component_node);

		//Add it to the kernel if the system is new
		if (new_system_created)
			kernel.add(system);
	}
}