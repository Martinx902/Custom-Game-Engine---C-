/**
 * @author    Martin Pérez Villabrille
 * @copyright Copyright (c) 2023 + UDIT
 * @details   Mgine -- All rights reserved
 */

#pragma once

namespace Mgine
{
	/**
	 * @brief Represents a base controller class for entities.
	 *
	 * This class defines an abstract interface for controllers that update entities.
	 */
	class Controller
	{
	public:
		/**
		 * @brief Updates the entity controlled by this controller.
		 *
		 * This method is to be implemented by derived classes to update the state of the entity.
		 *
		 * @param entity Pointer to the entity to be updated.
		 * @param t The time elapsed since the last update.
		 */
		virtual void update(Entity* entity, float t) = 0;
	};
}