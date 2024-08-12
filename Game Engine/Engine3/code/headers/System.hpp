/**
 * @author    Martin Pérez Villabrille
 * @copyright Copyright (c) 2023 + UDIT
 * @details   Mgine -- All rights reserved
 */

#pragma once

#include "Task.hpp"
#include <memory>
#include <string>
#include "rapid_xml/rapidxml.hpp"

namespace Mgine
{
	class Entity;
	class Component;
	class Scene;

	/**
	 * @brief Base class for system implementations.They will be the ones updating especified components of the entities on scene.
	 */
	class System : public Task
	{
	public:

		/**
		 * @brief Constructs a System object with a given priority and scene.
		 *
		 * @param given_priority The priority of the system.
		 * @param given_scene    Pointer to the scene.
		 */
		System(unsigned given_priority, Scene* given_scene) : Task(given_priority, given_scene) {}

		/**
		 * @brief Virtual method to create a component for an entity.
		 *
		 * @param entity_id    Pointer to the entity.
		 * @param component_id ID of the component to create.
		 * @param data         Pointer to the XML node containing component data.
		 */
		virtual void create_component
		(
			Entity* entity_id,
			const std::string& component_id,
			const rapidxml::xml_node<>* data
		) = 0;
	};
}