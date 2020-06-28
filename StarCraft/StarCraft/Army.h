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
	//���� �� ������ ���� ��ü�� 
	random_device rd;
	default_random_engine __generator{ rd() };
	uniform_real_distribution<double> __distribution;

	//���� ���� ��� ���� �Լ� 
	double getRandom() { return __distribution(__generator); }

protected:
	static int _MAX_ENTITY;			//�� ���븶�� ���� �� �ִ� �ִ� ���� ��
	static float _HYDRA_RATIO;		//���� ���� �� HYDRA ���� 
	string _name;					//������ �̸� ���ڿ� 
	list<Entity*> _members;			//���� ��ü�� �ּҸ� ��� ����Ʈ 
	int _money;						//���� ���� �ִ� �ݾ� 

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
