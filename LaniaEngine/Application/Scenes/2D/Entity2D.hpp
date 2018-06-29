/**
*                      This file is part of:
*                          Lania Engine
*           https://jean-louish.github.io/LaniaEngine/
*
* Entity2D
*
* Component reference points in the 2D scene graph.
*
* Copyright (c) 2017 Jean-Louis Haywood. All rights reserved.
*/

#pragma once

#include <stdint.h>
#include <Application/Scenes/2D/Transform2D.hpp>
#include <Core/DataStructures/Map.hpp>

namespace Lania
{
	enum components2D
	{
		CAMERA2D,
		RIGIDBODY2D,
		POSITION,
		SPRITE,
		STATICBODY2D,
		VELOCITY,
	};

	typedef struct Entity2D
	{
		uint64_t id;
		Transform2D transform;
		Map<uint8_t, uint64_t> components;
		Map<uint64_t, Entity2D*> children;
		Entity2D* parent;
	}Entity2D;
}
