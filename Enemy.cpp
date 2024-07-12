#include "Enemy.h"

Enemy::Enemy() : Object("Goblins", "Two small green creatures, weilding spears", ENEMY_ID, false)
{
	name = Object::Name();
	desc = Object::Description();

}

Enemy::~Enemy()
{

}