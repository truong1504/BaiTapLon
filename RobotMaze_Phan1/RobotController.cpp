#include "logic/MazeLogic.h"

void BrokenController(IRobot& robot);

int main()
{
    MazeLogic maze_logic = MazeLogic();
    maze_logic.start(BrokenController);

    return 0;
}


int isTargetSouth(IRobot &robot){
    int targetSouth;
    if (robot.getLocationY()<9)
        targetSouth = 1;
    else
        targetSouth = -1;
    return targetSouth;
}

void BrokenController(IRobot& robot)
{
    int random_number;
    int direction;

    random_number = rand() % 4;

    if (random_number == 0){
        direction = IRobot::NORTH;
        robot.printLog("NORTH");
    }
    else if (random_number == 1){
        direction = IRobot::EAST;
        robot.printLog("EAST");
    }
    else if (random_number == 2){
        direction = IRobot::SOUTH;
        robot.printLog("SOUTH");
    }
    else{
        direction = IRobot::WEST;
        robot.printLog("WEST");
    }

    robot.setHeading(direction);

    robot.advance();
}

