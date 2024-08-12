/**
 * @author    Martin Pérez Villabrille
 * @copyright Copyright (c) 2023 + UDIT
 * @details   Mgine -- All rights reserved
 */

#pragma once

#include <Render_Node.hpp>
#include <list>
#include <string>
#include <memory>

#include "System.hpp"
#include "Scene.hpp"
#include "Window.hpp"
#include "Render_Component.hpp"

using namespace std;
using namespace glt;
using namespace rapidxml;

namespace Mgine
{
	/**
	 * @brief System responsible for rendering components on screen.
	 */
	class Render_System : public System
	{
		unique_ptr< Render_Node > renderer;				///< Unique pointer to the render node.

		Window* window;									///< Pointer to the window.

		list < shared_ptr< Component > > components;	///< List of components to render.

	public:

		/**
		 * @brief Constructs a Render System object with a given priority and scene.
		 *
		 * @param given_priority The priority of the system.
		 * @param given_scene    Pointer to the scene.
		 */
		Render_System(unsigned given_priority, Scene* given_scene);

		/**
		 * @brief Static method to create a Render System instance for the System Factory.
		 *
		 * @param scene Pointer to the scene.
		 * @return shared_ptr<System> Shared pointer to the created system.
		 */
		static shared_ptr<System> create(Scene* scene)
		{
			return shared_ptr<System>(new Render_System(1, scene));
		}

		/**
		 * @brief Method to create a render component for an entity.
		 *
		 * @param entity_id    Pointer to the entity.
		 * @param component_id ID of the component to create.
		 * @param data         Pointer to the XML node containing component data.
		 */
		void create_component
		(
			Entity* entity_id,
			const string& component_id,
			const xml_node<>* data
		) override;

		/**
		 * @brief Method to execute rendering operations. It updates the render each frame, clears the buffers and swaps them.
		 *
		 * @param t Elapsed time.
		 */
		void execute(float t) override;

	private:

		/**
		 * @brief Parses a render component based on some xml data that was given beforehand.
		 *
		 * @param component_id      ID of the component.
		 * @param render_component  Shared pointer to the render component.
		 */
		void parse_component(const string& component_id, shared_ptr<Render_Component> render_component);
	};
}