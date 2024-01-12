/**
 * Project Untitled
 */

#include "AerialRobot.h"

#include <chrono>
#include <thread>
/**
 * AerialRobot implementation
 */

/**
 * @return void
 */
void RWA2::AerialRobot::print_status()
{

    std::cout << "Position of the mobile robot is (" << position_.first << ", " << position_.second << ")" << '\n';
    std::cout << "Orientation of the mobile robot is " << orientation_ << " degrees" << '\n';
    std::cout << "Velocity of the mobile robot is " << speed_ << '\n';
    
    std::cout << AerialRobot::model_ << "Has Wings : " << std::boolalpha << has_wings_ << " Altitude : " << altitude_ << " Is Flying :" << std::boolalpha << is_flying_ << '\n';
}
/**
 * @param distance
 * @param angle
 * @return void
 */
void RWA2::AerialRobot::move(double distance, double angle)
{

    if (distance <= max_distance_)
    {

        if (battery_.get_current_charge() < (max_distance_))
        {
            battery_.start_charging();
        }
        get_sensor_reading(4);

        take_off(distance);
        rotate(angle);
        land();
        std::cout << AerialRobot::model_ << " reached an altitude of " << distance << "meters and then landed."
                  << "/n";
        std::cout << " Current Battery Charge : " << battery_.get_current_charge();
        print_status();
    }
    else
    {
        std::cout << AerialRobot::model_ << " insufficient battery capacity to cover given distance";
    }
}

/**
 * @param angle
 * @return void
 */
void RWA2::AerialRobot::rotate(double angle)
{
    orientation_ = orientation_ + angle;
    std::cout << AerialRobot::model_ << "rotated " << orientation_ << " degrees" << '\n';
}

/**
 * @param altitude
 * @return void
 */
void RWA2::AerialRobot::take_off(double altitude)
{
    if (!is_flying_)
    {
        int time{0};

        if (has_wings_)
        {
            time = altitude / 3.0;
        }
        else
        {
            time = altitude / 1.5;
        }
        std::cout << AerialRobot::model_ << "taking off... " << time << '\n';

        std::chrono::seconds duration(time);
        std::this_thread::sleep_for(duration);

        std::cout << AerialRobot::model_ << "took off and reached the altitude: " << altitude << '\n';
        altitude_ = altitude;
        is_flying_ = true;
        battery_.discharge(altitude_);
    }
}

/**
 * @return void
 */
void RWA2::AerialRobot::land()
{

    if (is_flying_)
    {
        int time{0};

        if (has_wings_)
        {
            time = altitude_ / 4.0;
        }
        else
        {
            time = altitude_ / 2.0;
        }
        std::cout << AerialRobot::model_ << "landing... ";

        std::chrono::seconds duration(time);
        std::this_thread::sleep_for(duration);

        std::cout << AerialRobot::model_ << "landed: ";
        altitude_ = 0.0;
        is_flying_ = false;
        battery_.discharge(altitude_ * bat_req_per_m_);
    }
}