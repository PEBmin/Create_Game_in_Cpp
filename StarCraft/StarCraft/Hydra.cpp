#include "Hydra.h"
using namespace std;

Hydra::Hydra(int hp, int power) :Entity(hp, power) {
	_kind = HYDRA;
	cout << "	HYDRA 생성" << endl;
}

bool Hydra::Attack(Entity * pEnemy)
{
	int leftHP = 0;
	cout << "Hydra가 상대를 공격합니다. (체력: " << pEnemy->getHP() << " ) ";
	leftHP = pEnemy->getHP() - HYDRA_POWER;
	pEnemy->setHP(leftHP);

	if (leftHP < 0){
		cout << " ---> 상대가 죽었습니다."<< endl;
		return true;
	}
	else{
		cout << " ---> 상대의 남은 체력 : " << leftHP << endl;
		return false;
	}
}