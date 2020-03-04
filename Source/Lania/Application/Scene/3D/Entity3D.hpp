/**
*                      This file is part of:
*                          Lania
*           https://jean-louish.github.io/Lania/
*
* Entity3D
*
* Component reference points in the 3D scene graph.
* Contains transform data for components that attach to it.
* Can be inherited by other entity3Ds.
*
* Copyright (c) 2017-2020 Jean-Louis Haywood. All rights reserved.
* License: https://github.com/Jean-LouisH/Lania/blob/master/LICENSE
*/

#pragma once

#include "../../../Utilities/Definitions/Constants.hpp"
#include "../../../Utilities/Definitions/Aliases.hpp"
#include "../../../Utilities/Mathematics/Transform3D.hpp"
#include "../../../Utilities/GenericCollections/Set.hpp"
#include "../../../Utilities/GenericCollections/Vector.hpp"
#include "../../../Utilities/GenericCollections/Map.hpp"
#include "../../../Utilities/GenericCollections/String.hpp"


namespace Lania
{
	typedef struct Entity3D
	{
		enum Components
		{
			NO_COMPONENT,
			CAMERA_3D,
			RIGID_BODY_3D,
			SPRITE_3D,
			BOX_COLLIDER_3D,
			POINT_LOCK_3D,
		};

		Transform3D transform;
		Vector<EntityID> children;
		EntityID parent;
		Map<ComponentType, ComponentListIndex> components;
		Set<String> tags;
		Vector<String> shaders3D;
		Vector<ScriptIndex> scripts;

		Entity3D() :
			parent(NO_ENTITY)
		{}
	}Entity3D;
}
