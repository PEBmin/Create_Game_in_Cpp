#ifndef __ARMY_H_
#define __ARMY_H_

#include "Entity.h"
#include "Zergling.h"
#include "Hydra.h"
#include<iostream>
#include<random>
#include<list>
#include<string>

using namespace std;

class Army
{
	//랜덤 값 생성을 위한 객체들 
	random_device rd;
	default_random_engine __generator{ rd() };
	uniform_real_distribution<double> __distribution;

	//랜덤 값을 얻기 위한 함수 
	double getRandom() { return __distribution(__generator); }

protected:
	static int _MAX_ENTITY;			//각 군대마다 가질 수 있는 최대 병사 수
	static float _HYDRA_RATIO;		//군대 생성 시 HYDRA 비율 
	string _name;					//군대의 이름 문자열 
	list<Entity*> _members;			//병사 객체의 주소를 담는 리스트 
	int _money;						//현재 남아 있는 금액 

public:
	Army(const string &name, int n, const int money);
	const string & getName();
	int getCount();
	void printStatus();

	Entity * getEntity(int n);

	void removeEntity(int n);

	void Attack(Army &Enemy);
};

#endif
