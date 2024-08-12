/**
 * @author    Martin Pérez Villabrille
 * @copyright Copyright (c) 2023 + UDIT
 * @details   Mgine -- All rights reserved
 */

#pragma once

#include <chrono>

namespace Mgine
{
	/**
	 * @brief A simple timer utility class for measuring elapsed time.
	 */
	class Timer
	{
		std::chrono::steady_clock::time_point start_timestamp; ///< Store the start time point

	public:
		/**
		 * @brief Default constructor.
		 * @details Initializes the timer by calling the reset() method.
		 */
		Timer()
		{
			reset(); // Initialize the timer
		}

		/**
		 * @brief Resets the timer by updating the start timestamp.
		 */
		void reset()
		{
			start_timestamp = std::chrono::high_resolution_clock::now();
		}

		/**
		 * @brief Calculates the elapsed time since the last reset.
		 * @return The elapsed time in seconds.
		 */
		float elapsed_seconds()
		{
			auto current_timestamp = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float, std::milli> difference = current_timestamp - start_timestamp;
			return difference.count();
		}
	};
}