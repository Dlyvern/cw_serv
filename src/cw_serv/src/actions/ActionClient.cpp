#include "actions/ActionClient.hpp"

ActionClient::ActionClient() : rclcpp::Node("ActionClient")
{
    m_ActionClient = rclcpp_action::create_client<action_interface::action::Cmd>(this, "ActionClient");
    RCLCPP_INFO(this->get_logger(), "Action client is running");
}

void ActionClient::Start(const Command &command, int id,std::chrono::seconds serverTimeOut)
{
    m_Target = command.GetTarget();
    m_Operation = command.GetOperation();
    m_Arguments = command.GetArguments();
    m_TimeLimit = command.GetTimeLimit();
    m_ClientId = id;

    if(m_ActionClient->wait_for_action_server(serverTimeOut))
    {
        RCLCPP_ERROR(this->get_logger(), "Could not connect to action server");
        return;
    }

    RCLCPP_INFO(this->get_logger(), "Connected to action server");

    SendGoal();
}

void ActionClient::SendGoal()
{
    using namespace std::placeholders;

    auto send_goal_options = rclcpp_action::Client<action_interface::action::Cmd>::SendGoalOptions();

    send_goal_options.goal_response_callback = std::bind(&ActionClient::GoalResponse, this, std::placeholders::_1);

    send_goal_options.feedback_callback = std::bind(&ActionClient::GoalFeedback, this, _1, _2);

    send_goal_options.result_callback = std::bind(&ActionClient::GoalResult, this, _1);

    auto goal_msg = action_interface::action::Cmd::Goal();

    goal_msg.target = m_Target;
    goal_msg.operation = m_Operation;
    goal_msg.args = m_Arguments;
    goal_msg.time_limit = m_TimeLimit;

    m_ActionClient->async_send_goal(goal_msg, send_goal_options);
}

void ActionClient::GoalFeedback(rclcpp_action::ClientGoalHandle<action_interface::action::Cmd>::SharedPtr, const std::shared_ptr<const action_interface::action::Cmd::Feedback> feedback)
{
    RCLCPP_INFO(this->get_logger(), "Progress: %s", std::to_string(feedback->progress).c_str());
}

void ActionClient::GoalResponse(rclcpp_action::ClientGoalHandle<action_interface::action::Cmd>::SharedPtr future)
{
    auto goal_handle = future.get();
    if (!goal_handle)
    {
        RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
    }
    else
    {
        RCLCPP_INFO(this->get_logger(), "Goal accepted by server, waiting for result");
    }
}


void ActionClient::GoalResult(const rclcpp_action::ClientGoalHandle<action_interface::action::Cmd>::WrappedResult & result)
{
    switch (result.code)
    {
        case rclcpp_action::ResultCode::SUCCEEDED:
            break;
        case rclcpp_action::ResultCode::ABORTED:
            RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
            return;
        case rclcpp_action::ResultCode::CANCELED:
            RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
            return;
        default:
            RCLCPP_ERROR(this->get_logger(), "Unknown result code");
            return;
    }

    std::stringstream ss;

    ss << "Result received: ";

    RCLCPP_INFO(this->get_logger(), "%s", ss.str().c_str());
}