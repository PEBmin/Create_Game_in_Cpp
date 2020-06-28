#include "Zergling.h"
using namespace std;

Zergling::Zergling(int hp, int power ) :Entity(hp, power) {
	_kind = ZERGLING;
	cout << "	ZERGLING ����" << endl;
}

bool Zergling::Attack(Entity * pEnemy)
{
	int leftHP = 0;
	cout << "Zergling�� ��븦 �����մϴ�. (ü��: " << pEnemy->getHP() << " ) ";
	leftHP = pEnemy->getHP() - ZERGLING_POWER;    
	pEnemy->setHP(leftHP);
	
	if (leftHP < 0){
		cout << " ---> ��밡 �׾����ϴ�." << endl;
		return true;
	}
	else{
		cout << " --> ����� ���� ü�� : " << leftHP << endl;
		return false;
	}
}
