// @author Martin Pérez Villabrille
// Copyright (c) 2023 + UDIT
// Mgine -- All rights reserved

#pragma once

#include <Controller.hpp>
#include <Entity.hpp>

using namespace Mgine;

namespace Demo
{
	class Number_Controller : public Controller
	{
		void update(Entity* entity, float t) override
		{
			entity->get_transform().rotation.y += 1.f * t;
		}
	};
}

