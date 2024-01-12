/**
 * Project Untitled
 */

#include "WheeledRobot.h"

/**
 * WheeledRobot implementation
 */

/**
 * @param distance
 * @param angle
 * @return void
 */
void RWA2::WheeledRobot::move(double distance, double angle)
{
    if (distance <= 100.0)
    {
        if (battery_.get_current_charge() < distance)
        {
            // charge the battery
            battery_.start_charging();
        }
        rotate(angle);
        accelerate(2.0);
        std::chrono::seconds duration(static_cast<int>(distance - 2.0));
        std::this_thread::sleep_for(duration);
        decelerate(2.0);
        brake();
        std::cout << WheeledRobot::model_ << " drove" << distance << " m." << std::endl;
    }
    return;
}

/**
 * @return void
 */
void RWA2::WheeledRobot::print_status()
{
    std::cout << "Position of the mobile robot is (" << position_.first << ", "
              << position_.second << ")" << '\n';
    std::cout << "Orientation of the mobile robot is " << orientation_
              << " degrees" << '\n';
    std::cout << "Velocity of the mobile robot is " << speed_ << '\n';
    std::cout << "Battery " << battery_.get_battery_model() << " has charge " << battery_.get_current_charge() << '\n';

    std::cout << WheeledRobot::model_ << "Has : " << number_of_wheels_
              << " wheels "
              << " Desired speed : " << desired_speed_ << std::endl;
    return;
}

/**
 * @param angle
 * @return void
 */
void RWA2::WheeledRobot::rotate(double angle)
{
    std::cout << WheeledRobot::model_ << " rotated" << angle << " degrees."
              << std::endl;
    return;
}

/**
 * @param amount
 * @return void
 */
void RWA2::WheeledRobot::accelerate(double amount)
{
    while (speed_ < desired_speed_)
    {
        speed_ += amount;
        std::chrono::seconds duration(static_cast<int>(0.5));
        std::this_thread::sleep_for(duration);
    }
    std::cout << WheeledRobot::model_ << " has reached the desired speed of" << desired_speed_ << " m/s." << std::endl;
    return;
}

/**
 * @param amount
 * @return void
 */
void RWA2::WheeledRobot::decelerate(double amount)
{
    while (speed_ >= 0.0)
    {
        speed_ -= amount;
        std::chrono::seconds duration(static_cast<int>(0.5));
        std::this_thread::sleep_for(duration);
    }
    std::cout << WheeledRobot::model_ << " has reached the desired speed of" << desired_speed_ << " m/s." << std::endl;
    return;
}

/**
 * @param Parameter1
 */
void RWA2::WheeledRobot::brake()
{
    speed_ = 0.0;
    return;
}
