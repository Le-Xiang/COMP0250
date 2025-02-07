#include "cw1_team_20/task1_handler.h"

int main(int argc, char** argv) {
    ros::init(argc, argv, "task1_node");
    ros::NodeHandle nh;

    // 启动 Task 1 处理类
    Task1Handler task1_handler(nh);

    ros::spin();
    return 0;
}

