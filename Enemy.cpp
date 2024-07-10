#include "Enemy.h"

Enemy::Enemy() : Object("Goblin", "A small green creature, weilding a knife", ENEMY_ID, false)
{
	name = Object::Name();
	desc = Object::Description();


}

Enemy::Enemy(const char* name, const char* description)
{
	this->name = name;
	desc = description;
}

Enemy::~Enemy()
{
}

bool Enemy::CanPickup()
{
	return canPickup;
}