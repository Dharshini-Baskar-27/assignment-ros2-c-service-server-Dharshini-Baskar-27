#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

class ServiceServerNode : public rclcpp::Node
{
public:
  ServiceServerNode() : Node("service_server_node")
  {
    service_ = this->create_service<example_interfaces::srv::AddTwoInts>(
      "add_two_ints",
      std::bind(&ServiceServerNode::handle_service, this, _1, _2));

    RCLCPP_INFO(this->get_logger(), "Service Server ready: /add_two_ints");
  }

private:
  void handle_service(
    const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
    std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response)
  {
    response->sum = request->a + request->b;
    RCLCPP_INFO(this->get_logger(),
      "Received request: a=%ld b=%ld → sum=%ld",
      request->a, request->b, response->sum);
  }

  rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ServiceServerNode>());
  rclcpp::shutdown();
  return 0;
}

