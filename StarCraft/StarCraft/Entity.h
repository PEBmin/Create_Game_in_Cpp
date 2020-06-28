#ifndef __ENTITY_H_
#define __ENTITY_H_
#include<iostream>

const int ZERGLING_HP = 100;
const int ZERGLING_POWER = 23;
const int ZERGLING_PRICE = 50;
const int HYDRA_HP = 340;
const int HYDRA_POWER = 48;
const int HYDRA_PRICE = 150;

class Entity
{
protected:
	enum Kind { ZERGLING, HYDRA };

	const int _maxHP;
	Kind _kind;
	int _hp;
	int _power;

public:
	Entity(int hp, int power);
	Kind getKind();
	int getHP();
	bool setHP(int HP);
	virtual bool Attack(Entity * pEnemy) = 0;
};

#endif