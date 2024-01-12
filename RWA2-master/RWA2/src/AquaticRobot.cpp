/**
 * Project Untitled
 */

#include "AquaticRobot.h"

/**
 * AquaticRobot implementation
 */

/**
 * @return void
 */
void RWA2::AquaticRobot::print_status()
{
    std::cout << "Position of the mobile robot is (" << position_.first << ", " << position_.second << ")" << '\n';
    std::cout << "Orientation of the mobile robot is " << orientation_ << " degrees" << '\n';
    std::cout << "Velocity of the mobile robot is " << speed_ << '\n';
    std::cout << AquaticRobot::model_ << "Has Fins : " << std::boolalpha << has_fins_ << " Depth : " << depth_ << " Is Diving : " << std::boolalpha << is_diving_ << '\n';
    std::cout << "Battery " << battery_.get_battery_model() << " has charge " << battery_.get_current_charge() << '\n';

    return;
}

/**
 * @param angle
 *
 * @return void
 */
void RWA2::AquaticRobot::rotate(double angle)
{
    orientation_ = orientation_ + angle;

    std::cout << "THE" << AquaticRobot::model_ << " rotated" << angle << " degrees" << std::endl;
    return;
}

/**
 * @param depth
 */
void RWA2::AquaticRobot::dive(double depth)
{
    int swim_time_{0};
    if (!is_diving_)
    {
        std::cout << "Robot is not diving\n";

        if (has_fins_)
        {
            // it has fins and travels at 2 m/s
            speed_ = 2;
            swim_time_ = depth / speed_;
        }
        else
        {
            // it does nt have fins and travels at 1 m/s
            speed_ = 1;
            swim_time_ = depth / speed_;
        }
        // sleep code for the duration of the dive
        std::chrono::seconds duration(swim_time_);
        std::this_thread::sleep_for(duration);
        depth_ = depth;
        is_diving_ = true;
        battery_.discharge(depth_); // Consume battery charge
    }
}

void RWA2::AquaticRobot::surface()
{
    int swim_time_{0};

    if (is_diving_)
    {
        std::cout << "Robot is diving\n";
        if (has_fins_)
        {
            // it has fins and travels at 4 m/s
            swim_time_ = depth_ / 4;
        }
        else
        {
            // it does not have fins and travels at 2 m/s
            swim_time_ = depth_ / 2;
        }
        // sleep code for the duration of the dive
        std::chrono::seconds duration(swim_time_);
        std::this_thread::sleep_for(duration);
        depth_ = 0.0;
        is_diving_ = false;
        battery_.start_charging();
    }
}

/**
 * @param distance
 * @param angle
 * @return void
 */
void RWA2::AquaticRobot::move(double distance, double angle)
{
    if (distance <= 50)
    {
        if (battery_.get_current_charge() < distance * 2)
        {
            // charge the battery
            battery_.start_charging();
            // Dive
        }
        get_sensor_reading(5);

        rotate(angle);
        std::cout << "Moving forward " << distance << " m\n";
        dive(distance);
        std::cout << "Robot moved forward " << distance << " m\n";
        // Surface
        std::cout << "Moving backward " << depth_ << " m\n";
        surface();
        std::cout << "Robot moved backward " << depth_ << " m\n";

        std::cout << AquaticRobot::model_ << " reached a depth of " << distance
                  << "meters and then surfaced.";

        print_status();
    }

    return;
}