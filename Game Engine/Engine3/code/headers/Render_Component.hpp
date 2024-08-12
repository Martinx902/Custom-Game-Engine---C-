/**
 * @author    Martin Pérez Villabrille
 * @copyright Copyright (c) 2023 + UDIT
 * @details   Mgine -- All rights reserved
 */

#pragma once

#include <memory>
#include <Node.hpp>

#include "Component.hpp"

using namespace std;
using namespace rapidxml;

namespace Mgine
{
	/**
	 * @brief Component representing a renderable object, its data and behaviour.
	 */
	class Render_Component : public Component
	{
		shared_ptr<glt::Node> renderObj;		///< Pointer to the renderable object

	public:

		/**
		 * @brief Enumerates different types of renderable objects.
		 */
		enum Render_Type
		{
			MODEL = 0,							///< Model render type
			CAMERA,								///< Camera render type
			LIGHT								///< Light render type
		};

		Render_Type type;						///< Type of the renderable object

		/**
		 * @brief Struct to store type-specific rendering data.
		 */
		struct TypeData
		{
			string path = "";					///< Path to the renderable object file
			float fov = 20;						///< Field of view for camera renderable objects
			float near = 1;						///< Near plane for camera renderable objects
			float far = 10;						///< Far plane for camera renderable objects
			float ratio = 1;					///< Aspect ratio for camera renderable objects
		} data;

	public:

		/**
		 * @brief Constructor.
		 * @param entity Pointer to the entity this component belongs to.
		 */
		Render_Component(Entity* entity) : Component(entity) {}

		/**
		 * @brief Parses XML node to extract renderable object data.
		 * @param node Pointer to the XML node containing renderable object data.
		 * @param entity Pointer to the entity associated with this renderable object.
		 */
		void parse(const xml_node<>* node, Entity* entity) override;

		/**
		 * @brief Gets the pointer to the renderable object (const version).
		 * @return Pointer to the renderable object.
		 */
		const shared_ptr<glt::Node> get_object() const
		{
			return renderObj;
		}

		/**
		 * @brief Gets the pointer to the renderable object.
		 * @return Pointer to the renderable object.
		 */
		shared_ptr<glt::Node> get_object()
		{
			return renderObj;
		}

		/**
		 * @brief Sets the renderable object.
		 * @param given_object Pointer to the renderable object to set.
		 */
		void set_render_obj(shared_ptr<glt::Node> given_object)
		{
			renderObj = given_object;
		}

	private:

		/**
		 * @brief Parses model-specific renderable object data.
		 * @param node Pointer to the XML node containing model data.
		 * @param attribute Pointer to the XML attribute containing model data.
		 */
		void parse_model(const xml_node<>* node, xml_attribute<>* attribute);

		/**
		 * @brief Parses camera-specific renderable object data.
		 * @param node Pointer to the XML node containing camera data.
		 * @param attribute Pointer to the XML attribute containing camera data.
		 */
		void parse_camera(const xml_node<>* node, xml_attribute<>* attribute);
	};
}