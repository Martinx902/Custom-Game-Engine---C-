// @author Martin Pérez Villabrille
// Copyright (c) 2023 + UDIT
// Mgine -- All rights reserved

#include <algorithm>
#include <SDL.h>

#include "../headers/Input_Task.hpp"
#include "../headers/Scene.hpp"

namespace Mgine
{
	void Input_Task::execute(float t)
	{
		SDL_Event event;

		while (SDL_PollEvent(&event) > 0)
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:

				switch ((event.key.keysym.sym))
				{
				case SDLK_ESCAPE:
					scene->stop_scene();
					break;
				}

				break;

			case SDL_QUIT:
				scene->stop_scene();
				break;
			}
		}
	}

	bool Input_Task::key_pressed(const KeyCode key) const
	{
		const Uint8* state = SDL_GetKeyboardState(nullptr);

		switch (key)
		{
		case JUMP:
			return state[SDL_SCANCODE_SPACE];

		case MOVE_R:
			return state[SDL_SCANCODE_D];

		case MOVE_L:
			return state[SDL_SCANCODE_A];

		case MOVE_U:
			return state[SDL_SCANCODE_W];

		case MOVE_D:
			return state[SDL_SCANCODE_S];

		default:
			return false;
		}

		return false;
	}

	float Input_Task::get_axis(const KeyCode positiveKey, const KeyCode negativeKey) const
	{
		const Uint8* state = SDL_GetKeyboardState(nullptr);

		float axisValue = 0.0f;

		if (state[positiveKey])
			axisValue += 1.0f;

		if (state[negativeKey])
			axisValue -= 1.0f;

		axisValue = std::clamp(axisValue, -1.0f, 1.0f);

		return axisValue;
	}
}