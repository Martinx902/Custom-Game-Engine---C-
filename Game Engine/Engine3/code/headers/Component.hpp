/**
 * @author    Martin Pérez Villabrille
 * @copyright Copyright (c) 2023 + UDIT
 * @details   Mgine -- All rights reserved
 */

#pragma once

#include "rapid_xml/rapidxml.hpp"

namespace Mgine
{
	class Entity;

	/**
	 * @brief Base class for all entities components.
	 */
	class Component
	{
	protected:

		Entity* parent; ///< Pointer to the parent entity of this component.

	public:

		/**
		 * @brief Constructs a Component object.
		 * @param entity Pointer to the entity that owns this component.
		 */
		Component(Entity* entity) : parent(entity) {}

		/**
		 * @brief Virtual destructor.
		 */
		~Component() {}

		/**
		 * @brief Gets the parent entity of this component.
		 * @return Pointer to the parent entity.
		 */
		Entity* get_parent()
		{
			return parent;
		}

		/**
		 * @brief Parses XML node to extract component data.
		 * @param node Pointer to the XML node containing component data.
		 * @param entity Pointer to the entity associated with this component.
		 */
		virtual void parse(const rapidxml::xml_node<>* node, Entity* entity) = 0;
	};
}