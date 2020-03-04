/**
*                      This file is part of:
*                          Lania
*           https://jean-louish.github.io/Lania/
*
* Aliases
*
* Contains type aliases used throughout the engine.
*
* Copyright (c) 2017-2020 Jean-Louis Haywood. All rights reserved.
* License: https://github.com/Jean-LouisH/Lania/blob/master/LICENSE
*/

#pragma once

#include <stdint.h>

namespace Lania
{
	using EntityID = uint64_t;
	using LayerType = uint8_t;
	using LayerID = uint64_t;
	using ComponentType = uint8_t;
	using ComponentListIndex = uint64_t;
	using ScriptIndex = uint32_t;
}
