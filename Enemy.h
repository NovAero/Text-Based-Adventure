#include "Object.h"

class Enemy : public Object {
public:

	Enemy();
	Enemy(const char* name, const char* description);

	~Enemy();

public:

	void Attack();

	void Hurt(int damage);

	bool CanPickup() override;

private:

	String name;
	String desc;

	bool canPickup = false;
	bool invisible = false;

	int health = 15;
	const int maxHealth = 15;


	int dmgClamp[2] = { 1,6 };

	int itemID = ENEMY_ID;

};