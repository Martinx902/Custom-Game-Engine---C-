// @author Martin Pérez Villabrille
// Copyright (c) 2023 + UDIT
// Mgine -- All rights reserved

#include "..\headers\Scene.hpp"
#include"..\headers\Entity.hpp"

namespace Mgine
{
	Entity::Entity(Scene* given_parent)
		: parent(given_parent), transform(this) {}

	Entity::~Entity() { components.clear(); }

	Component* Entity::get_component_by_id(const std::string& id)
	{
		auto item = components.find(id);

		if (item != components.end())
		{
			return item->second.get();
		}

		return nullptr;
	}
}