/**
 * Project Untitled
 */

#include "MobileRobot.h"

/**
 * MobileRobot implementation
 */

/**
 * @param distance
 * @param angle
 * @return void
 */
void RWA2::MobileRobot::move(double distance, double angle)
{
}

/**
 * @return void
 */
void RWA2::MobileRobot::print_status()
{
    std::cout << "Position of the mobile robot is (" << position_.first << ", " << position_.second << ")" << '\n';
    std::cout << "Orientation of the mobile robot is " << orientation_ << " degrees" << '\n';
    std::cout << "Velocity of the mobile robot is " << speed_ << '\n';
}

/**
 * @param angle
 * @return void
 */
void RWA2::MobileRobot::rotate(double angle)
{
    orientation_ = orientation_ + angle;
    std::cout << "Rotating " << orientation_ << " degrees" << '\n';
}

void RWA2::MobileRobot::add_sensor(
    std::unique_ptr<RWA2::Sensor> sensor)
{
    sensors_.push_back(std::move(sensor));
}

std::array<double, 50> RWA2::MobileRobot::get_sensor_reading(int period){
  for (auto it = sensors_.begin(); it != sensors_.end(); ++it) {
    (*it)->read_data(period);
}

  for (auto it = sensors_.begin(); it != sensors_.end(); ++it) {
    sensor_reading = (*it)->get_sensor_data();
}

  return sensor_reading;
}