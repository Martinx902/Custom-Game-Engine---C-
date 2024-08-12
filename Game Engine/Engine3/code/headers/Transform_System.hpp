/**
 * @author    Martin Pérez Villabrille
 * @copyright Copyright (c) 2023 + UDIT
 * @details   Mgine -- All rights reserved
 */

#pragma once

#include<memory>
#include<list>
#include<string>

#include "System.hpp"
#include "Scene.hpp"

namespace Mgine
{
	/**
	 * @brief Represents a system responsible for managing the transforms components of the Entities.
	 *
	 * This system updates transform components of entities.
	 */
	class Transform_System : public System
	{
		std::list < std::shared_ptr< Component > > components;	///< List of all transform components.

	public:

		/**
		 * @brief Constructs a Transform_System object.
		 *
		 * @param given_priority The priority of the system.
		 * @param given_scene    Pointer to the scene.
		 */
		Transform_System(unsigned given_priority, Scene* given_scene) : System(given_priority, given_scene) {}

		/**
		 * @brief Creates a Transform_System object to be added to the kernel.
		 *
		 * @param scene Pointer to the scene.
		 * @return std::shared_ptr<System> Shared pointer to the created Transform_System object.
		 */
		static std::shared_ptr<System> create(Scene* scene)
		{
			return  std::shared_ptr<System>(new Transform_System(0, scene));
		}

		/**
		 * @brief Creates a transform component for an entity based on XML data.
		 *
		 * @param entity_id    Pointer to the entity.
		 * @param component_id ID of the component.
		 * @param data         Pointer to the XML node containing component data.
		 */
		void create_component
		(
			Entity* entity_id,
			const std::string& component_id,
			const rapidxml::xml_node<>* data
		)
			override;

		/**
		 * @brief Executes the transform system. Updating all the transform components on scene.
		 *
		 * @param t The time elapsed since the last update.
		 */
		void execute(float t) override;
	};
}