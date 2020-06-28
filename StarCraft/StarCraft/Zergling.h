#include "Entity.h"

class Zergling :public Entity
{
public:
	Zergling(int hp = ZERGLING_HP, int power = ZERGLING_POWER);
	bool Attack(Entity * pEnemy);
};