#include "Entity.h"
using namespace std;

Entity::Entity(int hp, int power) :_maxHP(hp)		
{
	_hp = hp;
	_power = power;
}

Entity::Kind Entity::getKind()
{
	return _kind;
}

int Entity::getHP()
{
		return Entity::_hp;
}

bool Entity::setHP(int HP)
{
	_hp = HP;

	if (HP > _maxHP){
		return false;
	}
	else 
		return true;
}
