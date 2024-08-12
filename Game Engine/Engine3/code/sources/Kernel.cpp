// @author Martin Pérez Villabrille
// Copyright (c) 2023 + UDIT
// Mgine -- All rights reserved

#include "..\headers\Kernel.hpp"
#include "..\headers\Timer.hpp"

namespace Mgine
{
	void Kernel::initialize()
	{
		for (auto task : tasks)
		{
			task->initialize();
		}
	}

	void Kernel::finalize()
	{
		for (auto task : tasks)
		{
			task->finalize();
		}
	}

	void Kernel::run()
	{
		exit = false;

		Timer frame_timer;

		frame_duration = 1.f / 60.f;

		initialize();

		do
		{
			frame_timer.reset();
			
			for (auto task : tasks)
			{
				task->execute(frame_duration);
			}

			frame_duration = frame_timer.elapsed_seconds();

		} while (!exit);

		finalize();
	}
}