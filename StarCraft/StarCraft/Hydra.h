#include "Entity.h"

class Hydra :public Entity
{
public:
	Hydra(int hp = HYDRA_HP, int power = HYDRA_POWER);
	bool Attack(Entity * pEnemy);
};