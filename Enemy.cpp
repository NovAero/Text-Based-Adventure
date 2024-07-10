#include "Enemy.h"

Enemy::Enemy() : Object("Goblin", "A small green creature, weilding a knife", ENEMY_ID, false)
{
	name = Object::Name();
	desc = Object::Description();


}

Enemy::~Enemy()
{
}
