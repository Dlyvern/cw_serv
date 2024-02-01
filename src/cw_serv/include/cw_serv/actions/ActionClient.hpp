#ifndef ACTION_CLIENT_HPP
#define ACTION_CLIENT_HPP

#include <functional>
#include <future>
#include <memory>
#include <string>
#include <sstream>

#include "action_interface/action/cmd.hpp"

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

#ifndef COMMAND_HPP
#include "cw_structs/Command.hpp"
#endif

class ActionClient : public rclcpp::Node
{
private:
    rclcpp_action::Client<action_interface::action::Cmd>::SharedPtr m_ActionClient;

    std::vector<std::string> m_Target{};
    int m_ClientId{0};
    std::string m_Operation{" "};
    std::vector<std::string>m_Arguments{};
    int32_t m_TimeLimit{0};
    int32_t m_Progress{0};

    void SendGoal();

    void GoalResponse(rclcpp_action::ClientGoalHandle<action_interface::action::Cmd>::SharedPtr future);

    void GoalFeedback(rclcpp_action::ClientGoalHandle<action_interface::action::Cmd>::SharedPtr, const std::shared_ptr<const action_interface::action::Cmd::Feedback> feedback);

    void GoalResult(const rclcpp_action::ClientGoalHandle<action_interface::action::Cmd>::WrappedResult & result);

public:
    ActionClient();

    void Start(const Command& command, int id, std::chrono::seconds serverTimeOut = std::chrono::seconds(10));
};

#endif //ACTION_CLIENT_HPP