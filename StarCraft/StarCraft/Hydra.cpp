#include "Hydra.h"
using namespace std;

Hydra::Hydra(int hp, int power) :Entity(hp, power) {
	_kind = HYDRA;
	cout << "	HYDRA ����" << endl;
}

bool Hydra::Attack(Entity * pEnemy)
{
	int leftHP = 0;
	cout << "Hydra�� ��븦 �����մϴ�. (ü��: " << pEnemy->getHP() << " ) ";
	leftHP = pEnemy->getHP() - HYDRA_POWER;
	pEnemy->setHP(leftHP);

	if (leftHP < 0){
		cout << " ---> ��밡 �׾����ϴ�."<< endl;
		return true;
	}
	else{
		cout << " ---> ����� ���� ü�� : " << leftHP << endl;
		return false;
	}
}