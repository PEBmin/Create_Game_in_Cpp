#include "Entity.h"
#include "Army.h"

using namespace std;

int main(int argc, const char * argv[]) {

	Army ME("��", 100, 1000);
	Army ENEMY("��", 100, 1000);

	ME.printStatus();
	ENEMY.printStatus();

	while (1)
	{
		ME.Attack(ENEMY); if (ENEMY.getCount() == 0) break;
		ENEMY.Attack(ME); if (ME.getCount() == 0) break;

		ME.printStatus();
		ENEMY.printStatus();
	}
	ME.printStatus();
	ENEMY.printStatus();

	Army * pWin = NULL;
	if (ME.getCount())
		pWin = &ME;
	else
		pWin = &ENEMY;

	cout << pWin->getName() << " ���밡 �̰���ϴ�." << endl;

	return 0;
}