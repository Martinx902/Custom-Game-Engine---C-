/**
 * @author    Martin Pérez Villabrille
 * @copyright Copyright (c) 2023 + UDIT
 * @details   Mgine -- All rights reserved
 */

#pragma once

#include <string>
#include <memory>
#include <map>

#include "Transform_Component.hpp"
#include "Component.hpp"

namespace Mgine
{
	class Scene;

	/**
	 * @brief Entity class representing an object in the scene.
	 *
	 * This class represents an entity in the scene. An entity is composed of components
	 * that define its behavior and properties and can be defined in the XML document.
	 */
	class Entity
	{
		std::map<std::string, std::shared_ptr<Component>> components; ///< Map of components associated with this entity, they will determine its behaviour

		Scene* parent;												  ///< Pointer to the parent scene

		Transform_Component transform;								  ///< Transform component representing the entity's position, rotation, and scale

	public:

		/**
		 * @brief Constructs a new Entity object with a given parent scene.
		 *
		 * @param given_parent Pointer to the parent scene.
		 */
		Entity(Scene* given_parent);

		/**
		 * @brief Default constructor.
		 *
		 * Initializes the entity with a null parent and a default transform.
		 */
		Entity() : parent(nullptr), transform(this) {}

		/**
		 * @brief Destructor for the Entity class.
		 */
		~Entity();

		/**
		 * @brief Adds a component to the entity.
		 *
		 * @param id Identifier for the component.
		 * @param component Pointer to the component to add.
		 */
		void add_component(const std::string& id, std::shared_ptr<Component> component)
		{
			components[id] = component;
		}

		/**
		 * @brief Gets a component by its identifier.
		 *
		 * @param id Identifier of the component to retrieve.
		 * @return Pointer to the component if found, nullptr otherwise.
		 */
		Component* get_component_by_id(const std::string& id);

		/**
		 * @brief Gets the transform component of the entity.
		 *
		 * @return Reference to the transform component.
		 */
		Transform_Component& get_transform()
		{
			return transform;
		};

		/**
		 * @brief Gets the transform component of the entity (const version).
		 *
		 * @return Reference to the transform component.
		 */
		const Transform_Component& get_transform() const
		{
			return transform;
		};

		/**
		 * @brief Sets the transform component of the entity.
		 *
		 * @param given_transform The transform component to set.
		 */
		void set_transform(Transform_Component given_transform)
		{
			transform = given_transform;
		}

		/**
		 * @brief Gets the parent scene of the entity.
		 *
		 * @return Pointer to the parent scene.
		 */
		Scene* get_scene()
		{
			return parent;
		};

		/**
		 * @brief Gets the parent scene of the entity (const version).
		 *
		 * @return Pointer to the parent scene.
		 */
		const Scene* get_scene() const
		{
			return parent;
		};
	};
}