// Copyright 2021 RobosoftAI Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*****************************************************************************************************************
 *
 * 	 Authors: Pablo Inigo Blasco, Brett Aldrich
 *
 ******************************************************************************************************************/
#pragma once

#include <rclcpp/rclcpp.hpp>
#include <smacc2/client_bases/smacc_action_client.hpp>
#include <smacc2/component.hpp>
#include <std_msgs/msg/string.hpp>

namespace cl_nav2z
{
// this component is used to switch the current planner and controller interacting
// with the remote navigation2 stack nodes (bt_navigator, planner_server, controller_server)
class CpPlannerSwitcher : public smacc2::ISmaccComponent
{
public:
  CpPlannerSwitcher();

  void onInitialize() override;

  void setDesiredGlobalPlanner(std::string);

  void setDesiredController(std::string);

  void commitPublish();

  // STANDARD PLANNERS

  void setBackwardPlanner(bool commit = true);

  void setUndoPathBackwardPlanner(bool commit = true);

  void setForwardPlanner(bool commit = true);

  void setPureSpinningPlanner(bool commit = true);

  // sets ROS defaults local and global planners
  void setDefaultPlanners(bool commit = true);

private:
  std::string desired_planner_;

  std::string desired_controller_;

  bool set_planners_mode_flag_;

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr planner_selector_pub_;

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr controller_selector_pub_;

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr goal_checker_selector_pub_;
};
}  // namespace cl_nav2z