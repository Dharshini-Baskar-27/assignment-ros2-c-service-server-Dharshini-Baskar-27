#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/empty.hpp"

class ServiceServerNode : public rclcpp::Node
{
public:
  ServiceServerNode() : Node("service_server_node")
  {
    service_ = this->create_service<std_srvs::srv::Empty>(
      "reset_counter",
      std::bind(&ServiceServerNode::handle_service, this,
                std::placeholders::_1, std::placeholders::_2)
    );

    RCLCPP_INFO(this->get_logger(), "Service Server ready: /reset_counter");
  }

private:
  void handle_service(
    const std::shared_ptr<std_srvs::srv::Empty::Request>,
    std::shared_ptr<std_srvs::srv::Empty::Response>)
  {
    RCLCPP_INFO(this->get_logger(), "Reset service called");
  }

  rclcpp::Service<std_srvs::srv::Empty>::SharedPtr service_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ServiceServerNode>());
  rclcpp::shutdown();
  return 0;
}
