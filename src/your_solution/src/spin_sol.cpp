#include "spin_sol.h"

int main(int argc, char *argv[]) 
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SpinSolution>());
  rclcpp::shutdown();
  return 0;
}

//your code here
SpinSolution::SpinSolution() : Node("spinsolution") 
{
  publisher_ = this->create_publisher<ArrayMsg>("predictedpos", 10);
  timer_ = this->create_wall_timer(
    1ms, std::bind(&SpinSolution::timer_callback, this));
  pos_sub_ = this->create_subscription<ArrayMsg>(
    "measuredpos", 10, std::bind(&SpinSolution::pos_callback, this, std::placeholders::_1));
  vel_sub_ = this->create_subscription<ArrayMsg>(
    "measuredvel", 10, std::bind(&SpinSolution::vel_callback, this, std::placeholders::_1));

  pos.data.push_back(0); pos.data.push_back(0);
  vel.data.push_back(0); vel.data.push_back(0);
}

void SpinSolution::timer_callback()
{
  ArrayMsg msg;
  msg.data.push_back(pos.data[0] + t*vel.data[0]);
  msg.data.push_back(pos.data[1] + t*vel.data[1]);
  t += 0.001;

  publisher_->publish(msg);
  if ((int)(t*1000)%100 == 0) // print every 1/10th of a second
    RCLCPP_INFO(this->get_logger(), "Published: %f %f", msg.data[0], msg.data[1]);
}

void SpinSolution::pos_callback(const ArrayMsg& msg)
{
  pos.data[0] = msg.data[0];
  pos.data[1] = msg.data[1];
  t = 0.00;
}

void SpinSolution::vel_callback(const ArrayMsg& msg)
{
  vel.data[0] = msg.data[0];
  vel.data[1] = msg.data[1];
}
