#include "actions/ActionServer.hpp"

ActionServer::ActionServer() : rclcpp::Node("ActionServer")
{
//    m_ActionServer = rclcpp_action::create_server<action_interface::action::Cmd>
//    (
//            this,
//            "ActionServer",
//            std::bind(&ActionServer::HandleGoal, this, std::placeholders::_1, std::placeholders::_2),
//            std::bind(&ActionServer::HandleCancelGoal, this, std::placeholders::_1),
//            std::bind(&ActionServer::HandleAcceptedGoal, this, std::placeholders::_1)
//    );

    RCLCPP_INFO(this->get_logger(), "Action server is running");
}

rclcpp_action::GoalResponse ActionServer::HandleGoal(const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const action_interface::action::Cmd::Goal> goal)
{
    RCLCPP_INFO(this->get_logger(), "Got a new goal");
    m_Goals[uuid] = goal;

    std::string target  = goal->target[0];
    std::string operation = goal->operation;

    m_ExecuteFunction = m_AllActionsFromModulesAndSubmodules.find(target)->second.find(operation)->second;

    return rclcpp_action::GoalResponse::REJECT;
}

rclcpp_action::CancelResponse ActionServer::HandleCancelGoal(const std::shared_ptr<rclcpp_action::ServerGoalHandle<action_interface::action::Cmd>> goal_handle)
{
    goal_handle->abort(nullptr);

    return rclcpp_action::CancelResponse::REJECT;
}

void ActionServer::HandleAcceptedGoal(const std::shared_ptr< rclcpp_action::ServerGoalHandle<action_interface::action::Cmd>> goal_handle)
{
    goal_handle->execute();
}

void ActionServer::Start(std::unordered_map<std::string, std::unordered_map<std::string, std::function<void(void)>>> &actions)
{
    m_AllActionsFromModulesAndSubmodules = actions;
}