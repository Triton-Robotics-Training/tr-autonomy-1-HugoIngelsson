#ifndef YOUR_SOLUTION_SRC_SPIN_SLOW_UPDATE_H_
#define YOUR_SOLUTION_SRC_SPIN_SLOW_UPDATE_H_

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "std_msgs/msg/string.hpp"
using ArrayMsg = std_msgs::msg::Float64MultiArray;
using namespace std::chrono_literals;
using std::placeholders::_1;

class SlowSolution : public rclcpp::Node {
 public:
  SlowSolution();
 private:
  // your code here
  void topic_callback(const std_msgs::msg::Float64MultiArray& msg) const;
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr publisher_;
  rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr subscription_;
};

#endif //YOUR_SOLUTION_SRC_SPIN_SLOW_UPDATE_H_
