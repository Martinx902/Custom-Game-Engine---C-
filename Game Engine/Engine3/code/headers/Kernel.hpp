/**
 * @author    Martin Pérez Villabrille
 * @copyright Copyright (c) 2023 + UDIT
 * @details   Mgine -- All rights reserved
 */

#pragma once

#include <list>
#include "Task.hpp"

namespace Mgine
{
	/**
	 * @brief The Kernel class manages a list of tasks, updates them and controls their execution, it's the backbone of the engine,
	 * if a task is not added it will not be executed. It can be paused and restarted again later.
	 */
	class Kernel
	{
		std::list<Task*> tasks; ///< List of tasks to execute
		bool exit;              ///< Flag to indicate whether the kernel should exit
		float frame_duration;   ///< Duration of each frame

	public:

		/**
		 * @brief Adds a task to the list of tasks. Enabling its execution.
		 * @param task Pointer to the task to add.
		 */
		void add(Task* task)
		{
			tasks.push_back(task);
			tasks.sort();
		}

		/**
		 * @brief Initializes the kernel, starting the execution of all the tasks added to it and activating any sub-action
		 * that a task may have had that needed to be done before starting.
		 */
		void initialize();

		/**
		 * @brief Finalizes the kernel. Stops the updating of its tasks and activates any sub-action that a task may have had
		 * that needed to be done before stoping.
		 */
		void finalize();

		/**
		 * @brief Runs the kernel. Updates all the tasks added to the list.
		 */
		void run();

		/**
		 * @brief Stops the kernel, it can be restarted again if needed.
		 * @details Sets the exit flag to true, indicating that the kernel should stop execution.
		 */
		void stop()
		{
			exit = true; // Set the exit flag to true
		}
	};
}