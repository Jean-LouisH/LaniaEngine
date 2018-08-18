#include "Physics2D.hpp"
#include <math.h>
#include <Constants.hpp>

void Lania::Physics2D::detectCollisions(
	List<DynamicCollisionEvent2D>* collisionEvents,
	Entity2D* entities, 
	RigidBody2D* rigidBodies,
	int rigidBodyCount,
	BoxCollider2D* boxColliders, 
	int boxColliderCount)
{
	collisionEvents->clear();

	for (int i = 0; i < boxColliderCount; i++)
	{
		Vector2* position1 = &entities[boxColliders[i].entityID].transform.position_px;
		AABB2D* aabb1 = &boxColliders[i].aabb;

		for (int j = 0; j < boxColliderCount; j++)
		{
			if (i != j)
			{
				Vector2* position2 = &entities[boxColliders[j].entityID].transform.position_px;
				AABB2D* aabb2 = &boxColliders[j].aabb;

				double box1left = position1->x + aabb1->min_px.x;
				double box1right = position1->x + aabb1->max_px.x;
				double box1top = position1->y + aabb1->max_px.y;
				double box1bottom = position1->y + aabb1->min_px.y;

				double box2left = position2->x + aabb2->min_px.x;
				double box2right = position2->x + aabb2->max_px.x;
				double box2top = position2->y + aabb2->max_px.y;
				double box2bottom = position2->y + aabb2->min_px.y;

				if (!(box2left > box1right ||
					box2right < box1left ||
					box2top < box1bottom ||
					box2bottom > box1top))
				{
					Entity2D* entity1 = &entities[boxColliders[i].entityID];
					Entity2D* entity2 = &entities[boxColliders[j].entityID];

					if (entity1->components.count(RIGIDBODY2D) &&
						entity2->components.count(RIGIDBODY2D))
					{
						DynamicCollisionEvent2D collisionEvent;
						RigidBody2D* rigidBody1 = &rigidBodies[entity1->components.at(RIGIDBODY2D)];
						RigidBody2D* rigidBody2 = &rigidBodies[entity2->components.at(RIGIDBODY2D)];
						collisionEvent.first.entityID = boxColliders[i].entityID;
						collisionEvent.first.collider = BOXCOLLIDER2D;
						collisionEvent.first.elasticity_ratio = rigidBody1->elasticity_ratio;
						collisionEvent.first.mass_kg = rigidBody1->mass_kg;
						collisionEvent.first.velocity_px_per_s = rigidBody1->velocity_px_per_s;
						collisionEvent.first.rotation_rad = entity1->transform.rotation_rad;

						collisionEvent.second.entityID = boxColliders[j].entityID;
						collisionEvent.second.collider = BOXCOLLIDER2D;
						collisionEvent.second.elasticity_ratio = rigidBody2->elasticity_ratio;
						collisionEvent.second.mass_kg = rigidBody2->mass_kg;
						collisionEvent.second.velocity_px_per_s = rigidBody2->velocity_px_per_s;
						collisionEvent.second.rotation_rad = entity2->transform.rotation_rad;
						collisionEvents->push_back(collisionEvent);
					}
					else
					{

					}
				}
			}
		}
	}
}

void Lania::Physics2D::handleCollisions(
	DynamicCollisionEvent2D* collisionEvents,
	int collisionEventCount,
	RigidBody2D* rigidBodies)
{

}

void Lania::Physics2D::decelerate(
	RigidBody2D* rigidBodies,
	int rigidBodyCount)
{
	for (int i = 0; i < rigidBodyCount; i++)
	{
		rigidBodies[i].velocity_px_per_s.x *= pow(rigidBodies[i].drag_ratio.x, S_PER_UPDATE);
		rigidBodies[i].velocity_px_per_s.y *= pow(rigidBodies[i].drag_ratio.y, S_PER_UPDATE);
	}
}

void Lania::Physics2D::force(
	RigidBody2D* rigidBodies,
	int rigidBodyCount)
{

}

void Lania::Physics2D::gravitate(
	RigidBody2D* rigidBodies, 
	int rigidBodyCount)
{
	for (int i = 0; i < rigidBodyCount; i++)
	{
		rigidBodies[i].velocity_px_per_s.y -= 
			EARTH_GRAVITY * S_PER_UPDATE * rigidBodies[i].gravity_scale;
	}
}

void Lania::Physics2D::displace(
	Entity2D* entities,
	RigidBody2D* rigidBodies,
	int rigidBodyCount)
{
	for (int i = 0; i < rigidBodyCount; i++)
	{
		RigidBody2D* rigidBody = &rigidBodies[i];
		entities[rigidBody->entityID].transform.position_px.x +=
			rigidBody->velocity_px_per_s.x * S_PER_UPDATE;
		entities[rigidBody->entityID].transform.position_px.y +=
			rigidBody->velocity_px_per_s.y * S_PER_UPDATE;
	}
}

void Lania::Physics2D::lock(
	Entity2D* entities,
	PointLock2D* pointLocks,
	int pointLockCount)
{
	for (int i = 0; i < pointLockCount; i++)
	{
		PointLock2D* pointLock = &pointLocks[i];
		entities[pointLock->entityID].transform.position_px.x =
			pointLock->point.x;
		entities[pointLock->entityID].transform.position_px.y =
			pointLock->point.y;
	}
}