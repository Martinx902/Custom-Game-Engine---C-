/**
 * @author    Martin Pérez Villabrille
 * @copyright Copyright (c) 2023 + UDIT
 * @details   Mgine -- All rights reserved
 */

#pragma once

#include "Component.hpp"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

using namespace rapidxml;
using namespace std;
using namespace glm;

namespace Mgine
{
	/**
	 * @brief Component representing transformation properties and behaviour of an entity on scene.
	 */
	class Transform_Component : public Component
	{
	public:

		Transform_Component* transform_parent;	///< Pointer to the parent transformation component

		vec3 position;							///< Position vector
		vec3 scale;								///< Scale vector
		vec3 rotation;							///< Euler rotation angles

	public:

		/**
		 * @brief Constructor for the transform component.
		 * @param entity Pointer to the entity this component belongs to.
		 */
		Transform_Component(Entity* entity) :
			Component(entity),
			position(vec3(0, 0, 0)),
			scale(vec3(0, 0, 0)),
			rotation(vec3(0, 0, 0)),
			transform_parent(nullptr)
		{}

		/**
		 * @brief Calculates the transformation matrix based on position, rotation, and scale. Uses OpenGLToolkit for calculations.
		 * @return Transformation matrix.
		 */
		mat4 get_transform_matrix();

		/**
		 * @brief Parses XML node to extract transformation data to create a new component.
		 * @param node Pointer to the XML node containing transformation data.
		 * @param entity Pointer to the entity associated with this transformation.
		 */
		void parse(const xml_node<>* node, Entity* entity) override;

		/**
		 * @brief Gets the pointer to the parent transformation component.
		 * @return Pointer to the parent transformation component.
		 */
		Transform_Component* get_transform_parent()
		{
			return transform_parent;
		}

		/**
		 * @brief Gets the pointer to the parent transformation component (const version).
		 * @return Pointer to the parent transformation component.
		 */
		const Transform_Component* get_transform_parent() const
		{
			return transform_parent;
		}
	};
}