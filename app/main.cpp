#include "../Framework/XCoreApplication.h"
#include "GameCtrl.h"

int main(int argc, char *argv[])
{
    XCoreApplication a(argc, argv);

    GameCtrl game;
    game.init();

    a.exec();
}
