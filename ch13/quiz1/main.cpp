#include "monsters.h"

int main()
{
    Monsters::Monster torg{ Monsters::ogre, "Torg", 145 };
    Monsters::printMonster(torg);

    Monsters::Monster blurp{ Monsters::slime, "Blurp", 23 };
    Monsters::printMonster(blurp);

    return 0;
}
