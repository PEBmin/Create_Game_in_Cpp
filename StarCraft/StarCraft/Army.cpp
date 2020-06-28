#include "Army.h"
using namespace std;

int Army::_MAX_ENTITY = 100;
float Army::_HYDRA_RATIO = 0.3f;

Army::Army(const string & name, int n, const int money) 
{
	_name = name;
	_money = money;

	cout << "새군단을 생성합니다." << endl;

	if (n > _MAX_ENTITY)			  
	{
		n = _MAX_ENTITY;		  
	}

	// n만큼의 유닛을 money에 맞게 생성.
	for (int i = 0; i < n; i++)
	{
		if (getRandom() > _HYDRA_RATIO)	   
		{
			// 돈이 50원 밑이면 반복문 정지
			if (_money < 50)	break;	   
			else
			{
				Entity* zer = new Zergling();
				_members.push_back(zer);
				_money -= ZERGLING_PRICE;
			}
		}
		else						    
		{
			// 돈이 150원 밑이면 반복문 정지
			if (_money < 150)	break;		    
			else
			{
				Entity* hyd = new Hydra();
				_members.push_back(hyd);
				_money -= HYDRA_PRICE;
			}
		}
	}
	cout << endl;
}
	

const string & Army::getName()
{
		return _name;
}

int Army::getCount()
{
	return _members.size();
}

void Army::printStatus()
{
	int Z_num = 0;
	int H_num = 0;
	int Sum_Hp = 0;

	for (auto & p : _members)			    // _member 리스트 확인
	{
		if (p->getKind() == 1)			    // 리스트의 종류가 히드라 일 때
		{
			H_num++;					    // 히드라 수 증가
			Sum_Hp += p->getHP();   
		}

		else					            // 리스트 종류가  저글링
		{
			Z_num++;			            // 저글링 수 증가
			Sum_Hp += p->getHP();   
		}
	}
	cout << getName() << " (Zergling : " << Z_num << ","
		<< " Hydra : " << H_num << ")" << endl;
	cout << "\t남은 HP : " << Sum_Hp << "\n" << endl;
}


Entity * Army::getEntity(int n)
{
	// iterator를 선언함
	list<Entity*>::iterator it = _members.begin();
	// n만큼 반복자를 이동
	advance(it, n);
	return (*it);
}

void Army::removeEntity(int n)
{
	list<Entity*>::iterator it = _members.begin();
	advance(it, n);
	delete *it;
	_members.erase(it);
}

void Army::Attack(Army& Enemy)
{
	int me = 0;
	int enemy = 0;
	bool result;

	// 0~1의 값을 랜덤으로 받아 유닛의 갯수를 곱해줌
	// int로 소수점을 없애서 n번째 유닛이 선택됨.
	me = (int)(getRandom()*_members.size());
	enemy = (int)(getRandom()*Enemy._members.size());

	cout << getName() << " 군대의 " << me << "가" <<
		" 상대의 " << enemy << "를" << " 공격합니다." << endl;

	result = (getEntity(me))->Attack(Enemy.getEntity(enemy));

	if (result == true)
	{
		Enemy.removeEntity(enemy);
	}
}
