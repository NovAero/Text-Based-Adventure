#include "Object.h"

#define ENEMY_ID 3

class Enemy : public Object {
public:

	Enemy();

	~Enemy();

private:

	String name;
	String desc;

	int itemID = ENEMY_ID;

};