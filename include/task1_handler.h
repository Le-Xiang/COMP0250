#ifndef TASK1_HANDLER_H_
#define TASK1_HANDLER_H_

#include <ros/ros.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PointStamped.h>
#include "cw1_team_20/Task1Service.h"  // 确保 srv 头文件正确

class Task1Handler
{
public:
    Task1Handler(ros::NodeHandle &nh);

    // 任务 1 的回调函数
    bool pickAndPlaceCallback(cw1_team_20::Task1Service::Request &req,
                              cw1_team_20::Task1Service::Response &res);

private:
    ros::NodeHandle nh_;
    moveit::planning_interface::MoveGroupInterface move_group_;
    ros::ServiceServer task1_service_;
};

#endif // TASK1_HANDLER_H_
