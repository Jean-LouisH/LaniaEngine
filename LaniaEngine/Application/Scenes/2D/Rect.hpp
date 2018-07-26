/**
*                      This file is part of:
*                          Lania Engine
*           https://jean-louish.github.io/LaniaEngine/
*
* Rect
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include <stdint.h>

namespace Lania
{
	typedef struct Rect
	{
		double width;
		double height;

		Rect():
			width(0.0),
			height(0.0)
		{}
	}Rect;
}
