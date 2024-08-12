/**
 * @author    Martin Pérez Villabrille
 * @copyright Copyright (c) 2023 + UDIT
 * @details   Mgine -- All rights reserved
 */

#pragma once

#include "Task.hpp"

namespace Mgine
{
	/**
	 * @brief Task responsible for handling input.
	 */
	class Input_Task : public Task
	{
	public:

		/**
		 * @brief Enumeration of key codes.
		 */
		enum KeyCode
		{
			EXIT,   ///< Exit key code.
			JUMP,   ///< Jump key code.
			MOVE_R, ///< Move right key code.
			MOVE_L, ///< Move left key code.
			MOVE_U, ///< Move up key code.
			MOVE_D  ///< Move down key code.
		};

	public:

		/**
		 * @brief Constructs an Input Task object with a given priority and scene.
		 *
		 * @param given_priority The priority of the task.
		 * @param given_scene    Pointer to the scene.
		 */
		Input_Task(unsigned given_priority, Scene* given_scene) : Task(given_priority, given_scene) {}

		/**
		 * @brief Destructor for the Input_Task class.
		 */
		~Input_Task() {}

		/**
		 * @brief Executes input handling operations.
		 *
		 * @param t Elapsed time.
		 */
		void execute(float t);

		/**
		 * @brief Checks if a specific key is pressed.
		 *
		 * @param key The key code to check.
		 * @return true if the key is pressed, false otherwise.
		 */
		bool key_pressed(const KeyCode key) const;

		/**
		 * @brief Gets the axis value based on positive and negative keys.
		 *
		 * @param positiveKey The positive key code.
		 * @param negativeKey The negative key code.
		 * @return float The axis value.
		 */
		float get_axis(const KeyCode positiveKey, const KeyCode negativeKey) const;
	};
}