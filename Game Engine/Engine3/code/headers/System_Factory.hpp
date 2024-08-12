/**
 * @author    Martin Pérez Villabrille
 * @copyright Copyright (c) 2023 + UDIT
 * @details   Mgine -- All rights reserved
 */

#pragma once

#include <map>
#include <string>
#include <memory>

#include "Render_System.hpp"
#include "Transform_System.hpp"
#include "System.hpp"

namespace Mgine
{
	/**
	 * @brief Factory class for creating new systems.
	 */
	class System_Factory
	{
		typedef std::shared_ptr<System>(*Factory) (Scene* scene);  ///< Function pointer type for creating systems.
		std::map<std::string, Factory> systems;					   ///< Map to store system factories.

	public:

		/**
		 * @brief Constructs a System_Factory object and initializes it with default systems.
		 */
		System_Factory()
		{
			add_system("render", Render_System::create);
			add_system("transform", Transform_System::create);
		}

		/**
		 * @brief Adds a system to the factory.
		 *
		 * @param name The name of the system.
		 * @param type The factory function to create the system.
		 */
		void add_system(const std::string& name, Factory type)
		{
			systems[name] = type;
		}

		/**
		 * @brief Creates a system by name.
		 *
		 * @param name  The name of the system to create.
		 * @param scene Pointer to the scene.
		 * @return A shared pointer to the created system, or nullptr if the system name is not found.
		 */
		std::shared_ptr<System> create_system(const std::string& name, Scene* scene)
		{
			if (systems.count(name))
			{
				return systems[name](scene);
			}
			return std::shared_ptr<System>();
		}
	};
}