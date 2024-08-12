/**
  * @author    Martin Pérez Villabrille
  * @copyright Copyright (c) 2023+ Martin Pérez Villabrille.
  *            All rights reserved
  */

#pragma once

#include <map>
#include <string>
#include <memory>

#include "Entity.hpp"
#include "Kernel.hpp"
#include "Window.hpp"
#include "Input_Task.hpp"
#include "Control_System.hpp"
#include "Message_Dispatcher.hpp"
#include "rapid_xml/rapidxml.hpp"

using namespace rapidxml;
using namespace std;

namespace Mgine
{
	/**
	 * @brief Represents a scene in Mgine.
	 *
	 * The Scene class manages entities, systems, and executes the game loop.
	 */
	class Scene
	{
		Message_Dispatcher message_dispatcher;	  ///< Manages message dispatching between listeners.

		map<string, shared_ptr<Entity>> entities; ///< All entities in the scene.
		map<string, shared_ptr<System>> systems;  ///< All systems in the scene.

		Input_Task input_task;					  ///< Handles input-related tasks.

		Kernel  kernel;							  ///< Runs the tasks of the scene.

		Window* window;							  ///< Pointer to the SDL window associated with the scene.

	public:

		/**
		 * @brief Constructor for the Scene class.
		 *
		 * @param path The path to the scene xml file.
		 */
		Scene(const string& path);

		/**
		 * @brief Executes the game loop, updating all the tasks added to the kernel
		 */
		void execute()
		{
			kernel.run();
		}

		/**
		 * @brief Retrieves an entity by its ID.
		 *
		 * @param entity_id The ID of the entity, it's the type of the xml file (render, transform, audio...).
		 * @return A pointer to the entity if found, nullptr otherwise.
		 */
		Entity* get_entity_by_id(const string& entity_id)
		{
			if (entities[entity_id])
				return entities[entity_id].get();
			else
				return nullptr;
		}

		/**
		 * @brief Retrieves the game window.
		 *
		 * @return A pointer to the game window.
		 */
		Window* get_window()
		{
			return window;
		}

		/**
		 * @brief Retrieves the game window (const version).
		 *
		 * @return A pointer to the game window.
		 */
		const Window* get_window() const
		{
			return window;
		}

		/**
		 * @brief Stops the current scene. It stops updating the tasks, but doesnt close the window, it can be
		 * activated again if needed.
		 */
		void stop_scene()
		{
			kernel.stop();
		}

	private:

		/**
		 * @brief Loads the scene data from the specified path.
		 *
		 * @param path The path to the scene data.
		 * @return True if the scene is loaded successfully, false otherwise.
		 */
		bool load_scene(const string& path);

		/**
		 * @brief Parses an entity node from the XML scene data.
		 *
		 * @param scene_node The XML node representing an entity.
		 */
		void parse_entity(xml_node<>* scene_node);

		/**
		 * @brief Parse XML nodes representing components of an entity.
		 *
		 * @param component_node The XML node representing a component.
		 * @param id The unique identifier of the entity.
		 * @param entity Pointer to the entity.
		 */
		void parse_components(xml_node<>* component_node, string& id, Entity* entity);
	};
}