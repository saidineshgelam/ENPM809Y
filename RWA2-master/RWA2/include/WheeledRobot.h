/**
 * Project Untitled
 */

#pragma once


#include "MobileRobot.h"

namespace RWA2 {

class WheeledRobot final : public MobileRobot
{
private:
    int number_of_wheels_ = 2;
    double wheel_diameter_;
    double desired_speed_;


    /**
     * @param amount
     */
    void accelerate(double amount);

    /**
     * @param amount
     */
    void decelerate(double amount);

    /**
     * @param Parameter1
     */
    void brake();
public:
    /**
     * @param distance
     * @param angle
     */
    virtual void move(double distance, double angle) override;

    virtual void print_status() override;

    WheeledRobot( std::string bot_model, double x, double y, double orientation, std::string battery_model, int current_charge, int number_of_wheels_, double wheel_diameter_, double desired_speed_)
      :MobileRobot(bot_model, x, y, orientation, battery_model, current_charge), number_of_wheels_{number_of_wheels_}, wheel_diameter_{wheel_diameter_}, desired_speed_{desired_speed_}{
      }

protected:
    /**
     * @param angle
     */
    virtual void rotate(double angle) override;


};
}
// namespace RWA2
