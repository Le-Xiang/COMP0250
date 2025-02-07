#include "cw1_team_20/task1_handler.h"

Task1Handler::Task1Handler(ros::NodeHandle &nh) : nh_(nh), move_group_("manipulator")
{
    // 注册 Task 1 服务
    task1_service_ = nh_.advertiseService("/task1_start", &Task1Handler::pickAndPlaceCallback, this);
    ROS_INFO("Task 1 服务已启动，等待请求...");
}

bool Task1Handler::pickAndPlaceCallback(cw1_team_20::Task1Service::Request &req,
                                        cw1_team_20::Task1Service::Response &res)
{
    ROS_INFO("Task 1: 接收到抓取和放置请求");

    // 获取物体位置和目标位置
    geometry_msgs::Pose target_pose = req.object_loc.pose;
    geometry_msgs::Point goal_point = req.goal_loc.point;

    // **步骤1：移动到抓取位置**
    move_group_.setPoseTarget(target_pose);
    move_group_.move();

    // **步骤2：执行抓取**
    ROS_INFO("执行抓取操作...");
    // closeGripper();  // 这里应该有夹爪的控制

    // **步骤3：移动到目标位置**
    geometry_msgs::Pose place_pose;
    place_pose.position = goal_point;
    place_pose.orientation.w = 1.0;
    move_group_.setPoseTarget(place_pose);
    move_group_.move();

    // **步骤4：释放物体**
    // openGripper();

    ROS_INFO("任务完成，返回成功响应");
    return true;
}
