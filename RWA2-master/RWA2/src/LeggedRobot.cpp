/**
 * Project Untitled
 */

#include "LeggedRobot.h"

/**
 * LeggedRobot implementation
 */

/**
 * @param distance
 * @param angle
 * @return void
 */

void RWA2::LeggedRobot::move(double distance, double angle)
{
    int battery_request = distance * leg_strength_ * 100 + leg_strength_ * battery_required_kick_;

    if (distance <= max_distance_)
    {

        if (battery_.get_current_charge() < battery_request)
        {
            battery_.start_charging();
        }
        get_sensor_reading(5); // check how to write this
        rotate(angle);
        jump(distance);
        kick();
        print_status();
    }
    else
    {
        std::cout << LeggedRobot::model_ << "cannot move the given distance due to insufficient battery capacity";
    }
}

/**
 * @return void
 */
void RWA2::LeggedRobot::print_status()
{
    std::cout << "Position of the mobile robot is (" << position_.first << ", " << position_.second << ")" << '\n';
    std::cout << "Orientation of the mobile robot is " << orientation_ << " degrees" << '\n';
    std::cout << "Velocity of the mobile robot is " << speed_ << '\n';
    std::cout << "Battery " << battery_.get_battery_model() << " has charge " << battery_.get_current_charge() << '\n';

    std::cout << LeggedRobot::model_ << "has " << number_of_legs_ << " legs "
              << " and can jump at height : " << height_ << " with leg strength " << leg_strength_ << "\n";
}

/**
 * @param angle
 * @return void
 */
void RWA2::LeggedRobot::rotate(double angle)
{
    std::cout << LeggedRobot::model_ << "rotated " << angle << " degrees.";
}

/**
 * @return void
 */
void RWA2::LeggedRobot::kick()
{
    std::cout << LeggedRobot::model_ << "kicks with a strength of" << leg_strength_;
    battery_.discharge(leg_strength_ * battery_required_kick_);
}

/**
 * @param amount
 * @return void
 */
void RWA2::LeggedRobot::jump(double amount)
{
    std::cout << LeggedRobot::model_ << "jumps at a height of" << leg_strength_ * amount << "  cm above the ground";
    battery_.discharge(leg_strength_ * 100 * amount);
}