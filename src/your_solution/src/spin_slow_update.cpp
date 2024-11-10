#include "spin_slow_update.h"

int main(int argc, char *argv[]) 
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SlowSolution>());
  rclcpp::shutdown();
  return 0;
}

SlowSolution::SlowSolution() : Node("slowsolution")
{
  // RCLCPP_INFO(this->get_logger(), "Remove this statement from spin_slow_update.cpp");
  publisher_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("predictedpos", 10);
  subscription_ = this->create_subscription<std_msgs::msg::Float64MultiArray>(
    "measuredpos", 10, std::bind(&SlowSolution::topic_callback, this, _1)
  );
}

void SlowSolution::topic_callback(const std_msgs::msg::Float64MultiArray& msg) const
{
  RCLCPP_INFO(this->get_logger(), "I heard: %f %f", msg.data[0], msg.data[1]);
  publisher_->publish(msg);
}