#include "Zergling.h"
using namespace std;

Zergling::Zergling(int hp, int power ) :Entity(hp, power) {
	_kind = ZERGLING;
	cout << "	ZERGLING 생성" << endl;
}

bool Zergling::Attack(Entity * pEnemy)
{
	int leftHP = 0;
	cout << "Zergling이 상대를 공격합니다. (체력: " << pEnemy->getHP() << " ) ";
	leftHP = pEnemy->getHP() - ZERGLING_POWER;    
	pEnemy->setHP(leftHP);
	
	if (leftHP < 0){
		cout << " ---> 상대가 죽었습니다." << endl;
		return true;
	}
	else{
		cout << " --> 상대의 남은 체력 : " << leftHP << endl;
		return false;
	}
}
