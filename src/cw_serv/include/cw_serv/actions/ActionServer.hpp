#ifndef ACTION_SERVER_HPP
#define ACTION_SERVER_HPP

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "action_interface/action/cmd.hpp"

class ActionServer : public rclcpp::Node
{
private:
    std::unordered_map<rclcpp_action::GoalUUID, std::shared_ptr<const action_interface::action::Cmd::Goal>>m_Goals;

    //key1:"Tester" = value1(key2"TestBasic" = value2FunctionTestBasic)
    std::unordered_map<std::string, std::unordered_map<std::string, std::function<void(void)>>>m_AllActionsFromModulesAndSubmodules;

    rclcpp_action::Server<action_interface::action::Cmd>::SharedPtr m_ActionServer;
    std::string m_Name;

    std::function<void ()> m_ExecuteFunction;

    rclcpp_action::GoalResponse HandleGoal(const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const action_interface::action::Cmd::Goal> goal);

    rclcpp_action::CancelResponse HandleCancelGoal(const std::shared_ptr<rclcpp_action::ServerGoalHandle<action_interface::action::Cmd>> goal_handle);

    void HandleAcceptedGoal(const std::shared_ptr<rclcpp_action::ServerGoalHandle<action_interface::action::Cmd>> goal_handle);

public:
    ActionServer();

    void Start(std::unordered_map<std::string, std::unordered_map<std::string, std::function<void(void)>>>& actions);
};

#endif //ACTION_SERVER_HPP