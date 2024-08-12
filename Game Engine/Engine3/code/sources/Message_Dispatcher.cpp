// @author Martin P�rez Villabrille
// Copyright (c) 2023 + UDIT
// Mgine -- All rights reserved

#include "../headers/Message_Dispatcher.hpp"

namespace Mgine
{
	void Message_Dispatcher::execute(float t)
	{
		for (auto& message : messages)
		{
			auto& listeners = messageListeners[message.id];

			for (auto& listener : listeners)
			{
				listener->handle(message);
			}
		}
	}
}