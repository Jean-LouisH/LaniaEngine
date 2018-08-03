/**
*                      This file is part of:
*                          Lania Engine
*           https://jean-louish.github.io/LaniaEngine/
*
* Static Body 2D
*
* Component that interfaces with direct manipulation and scripting.
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
* License: https://github.com/Jean-LouisH/LaniaEngine/blob/master/LICENSE
*/

#pragma once

#include <stdint.h>
#include <Application/Scenes/2D/Vector2.hpp>
#include <Application/Scenes/2D/Entity2D.hpp>

namespace Lania
{
	typedef struct StaticBody2D
	{
		EntityID entityID;
		double elasticity_ratio;
		double friction_ratio;
		Vector2 constantVelocity_px_per_s;
		Vector2 constantAngularVelocity_rad_per_s;

		StaticBody2D() :
			elasticity_ratio(0.0),
			friction_ratio(0.0)
		{}
	}StaticBody2D;
}
