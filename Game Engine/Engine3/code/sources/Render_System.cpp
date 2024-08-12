// @author Martin Pérez Villabrille
// Copyright (c) 2023 + UDIT
// Mgine -- All rights reserved

#include <Cube.hpp>
#include <Node.hpp>
#include <Render_Node.hpp>
#include <Model.hpp>
#include <Model_Obj.hpp>
#include <Camera.hpp>
#include <Light.hpp>

#include "../headers/Render_Component.hpp"
#include "../headers/Render_System.hpp"

using namespace glt;

namespace Mgine
{
	Render_System::Render_System(unsigned given_priority, Scene* given_scene) : System(given_priority, given_scene)
	{
		renderer.reset(new Render_Node);

		window = scene->get_window();
	}

	void Render_System::create_component
	(
		Entity* entity_id,
		const string& component_id,
		const xml_node<>* data
	)
	{
		string component_type = data->first_attribute("type")->value();

		shared_ptr<Render_Component> render_component(new Render_Component(entity_id));

		render_component->parse(data, entity_id);

		entity_id->add_component(component_type, render_component);

		parse_component(component_id, render_component);

		components.push_back(render_component);
	}

	void Render_System::parse_component(const string& component_id, shared_ptr<Render_Component> render_component)
	{
		if (render_component->type == render_component->MODEL)
		{
			//MODEL

			shared_ptr< Model  > model(new Model_Obj(render_component->data.path));

			renderer->add(component_id, model);

			render_component->set_render_obj(model);
		}
		else if (render_component->type == render_component->CAMERA)
		{
			//CAMERA

			shared_ptr< Camera > camera
			(
				new Camera
				(
					render_component->data.fov,
					render_component->data.near,
					render_component->data.far,
					render_component->data.ratio
				)
			);

			renderer->add(component_id, camera);

			render_component->set_render_obj(camera);
		}
		else if (render_component->type == render_component->LIGHT)
		{
			//LIGHT

			shared_ptr< Light  > light(new Light);

			renderer->add(component_id, light);

			render_component->set_render_obj(light);
		}
	}

	void  Render_System::execute(float t)
	{
		window->clear();

		renderer->render();

		window->swap_buffers();
	}
}