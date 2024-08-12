/**
 * @author    Martin Pérez Villabrille
 * @copyright Copyright (c) 2023 + UDIT
 * @details   Mgine -- All rights reserved
 */

#pragma once

#include <string>
#include <tuple>
#include <map>

namespace Mgine
{
	/**
	 * @brief Structure representing a message and its data.
	 */
	struct Message
	{
		std::string id;									///< Identifier of the message
		using Parameter = std::tuple<>;					///< Type alias for message parameters (no parameters in this case)
		std::map<std::string, Parameter> parameters;	///< Map of parameter names to their values
	};
}