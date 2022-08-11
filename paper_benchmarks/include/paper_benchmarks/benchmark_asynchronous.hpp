#ifndef BENCHMARK_ASYNCHRONOUS_H
#define BENCHMARK_ASYNCHRONOUS_H

#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include "paper_benchmarks/scene.hpp"
#include "paper_benchmarks/primitive_pick_and_place.hpp"

rclcpp::Node::SharedPtr node;
std::shared_ptr<primitive_pick_and_place> pnp_1;
std::shared_ptr<primitive_pick_and_place> pnp_2;

tray_helper blue_tray_1(4,4,0.11,-0.925);
tray_helper red_tray_1(4,4,-0.425,-0.925);
tray_helper blue_tray_2(4,4,0.11,0.925);
tray_helper red_tray_2(4,4,-0.425,0.925);

bool panda_1_busy = true;
bool panda_2_busy = false;

const rclcpp::Logger LOGGER = rclcpp::get_logger("benchmark_asynchronous");
void main_thread();
bool executeTrajectory(std::shared_ptr<primitive_pick_and_place> pnp,moveit_msgs::msg::CollisionObject& object,tray_helper* tray);

#endif