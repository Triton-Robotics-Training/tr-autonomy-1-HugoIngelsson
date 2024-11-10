#ifndef YOUR_SOLUTION_SRC_SPIN_SOL_H_
#define YOUR_SOLUTION_SRC_SPIN_SOL_H_

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
using ArrayMsg = std_msgs::msg::Float64MultiArray;
using namespace std::chrono_literals;

class SpinSolution : public rclcpp::Node {
 public:
    SpinSolution();
 private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<ArrayMsg>::SharedPtr publisher_;
    rclcpp::Subscription<ArrayMsg>::SharedPtr pos_sub_, vel_sub_;

    void pos_callback(const ArrayMsg& msg);
    void vel_callback(const ArrayMsg& msg);
    void timer_callback();

    ArrayMsg pos, vel;
    double t = 0.00;
};

#endif //YOUR_SOLUTION_SRC_SPIN_SOL_H_
