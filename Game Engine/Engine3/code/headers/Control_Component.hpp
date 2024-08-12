/**
 * @author    Martin Pérez Villabrille
 * @copyright Copyright (c) 2023 + UDIT
 * @details   Mgine -- All rights reserved
 */

#pragma once

#include <memory>

#include "Component.hpp"
#include "Controller.hpp"

namespace Mgine
{
	/**
	 * @brief Component responsible for controlling entities.
	 */
	class Control_Component : public Component
	{
	public:

		std::shared_ptr<Controller> controller; ///< Pointer to the controller associated with the entity.

	public:

		/**
		 * @brief Constructs a Control Component object.
		 * @param entity Pointer to the entity associated with this control component.
		 */
		Control_Component(Entity* entity) : Component(entity), controller(nullptr) {}

		/**
		 * @brief Default constructor.
		 * @details Constructs a Control_Component object with a null entity pointer and a null controller pointer.
		 */
		Control_Component() : Component(nullptr), controller(nullptr) {}

		/**
		 * @brief Parses XML node to extract control data.
		 * @param node Pointer to the XML node containing control data.
		 * @param entity Pointer to the entity associated with this control component.
		 */
		void parse(const rapidxml::xml_node<>* node, Entity* entity) override { }
	};
}