/**
 * @author    Martin Pérez Villabrille
 * @copyright Copyright (c) 2023 + UDIT
 * @details   Mgine -- All rights reserved
 */

#pragma once

namespace Mgine
{
	class Scene;

	/**
	 * @brief Represents a task to be executed by the engine.
	 */
	class Task
	{
	protected:

		unsigned priority; ///< Priority of the task.
		Scene* scene;      ///< Pointer to the scene.

	public:

		/**
		 * @brief Constructs a Task object.
		 *
		 * @param given_priority The priority of the task.
		 * @param given_scene    Pointer to the scene.
		 */
		Task(unsigned given_priority, Scene* given_scene) : priority(given_priority), scene(given_scene) {}

		/**
		 * @brief Initializes the task. It can be an action needed to be done before executing it.
		 */
		virtual void initialize() {};

		/**
		 * @brief Finalizes the task. It can be an action needed to be done before finalizing it.
		 */
		virtual void finalize() {};

		/**
		 * @brief Executes the task. The behaviour will depend on the task.
		 *
		 * @param t The time elapsed since the last update.
		 */
		virtual void execute(float t) = 0;

	public:

		/**
		 * @brief Overloaded less than operator to compare tasks by priority so that they can be sorted and executed in order.
		 *
		 * @param other The task to compare with.
		 * @return true if this task has lower priority than the other task, false otherwise.
		 */
		bool operator < (const Task& other) const
		{
			return this->priority < other.priority;
		}
	};
}