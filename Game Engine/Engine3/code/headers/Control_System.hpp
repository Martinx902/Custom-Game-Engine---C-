/**
 * @author    Martin Pérez Villabrille
 * @copyright Copyright (c) 2023 + UDIT
 * @details   Mgine -- All rights reserved
 */

#pragma once

#include <list>
#include <map>
#include <string>
#include <memory>

#include "System.hpp"
#include "Control_Component.hpp"

namespace Mgine
{
	/**
	 * @brief A system responsible for controlling the control components on entities.
	 */
	class Control_System : public System
	{
	public:

		typedef std::shared_ptr<Controller>(*Controller_Factory) ();		///< Defines a factory for creating controllers.

		std::list < std::shared_ptr< Control_Component > > components;		///<  List of control components.

		std::map< std::string, Controller_Factory > controller_factories;	///<  Map of controller factories

	public:

		/**
		 * @brief Creates a control component for an entity.
		 *
		 * @param entity_id     Pointer to the entity.
		 * @param component_id  The ID of the control component.
		 * @param data          Pointer to the XML node containing component data.
		 */
		void create_component
		(
			Entity* entity_id,
			const std::string& component_id,
			const rapidxml::xml_node<>* data
		) override;

		/**
		 * @brief Executes control components of the entities, updating whatever code they have.
		 *
		 * @param t Elapsed time.
		 */
		void execute(float t) override;
	};
}