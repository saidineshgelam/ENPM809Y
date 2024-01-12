/**
 * Project Untitled
 */

#include <chrono>
#include <thread>

#include "Battery.h"

/**
 * Battery implementation
 */

/**
 * @return void
 */
void RWA2::Battery::start_charging()
{
    int charge_time_ = 0;
    if (!is_charging_)
    {
        if (model_ == "Li-ion")
        {
            charge_time_ = ((100 - current_charge_) / 2);
        }
        else if (model_ == "LiFePO4")
        {
            charge_time_ = ((100 - current_charge_) / 4);
        }
        is_charging_ = true;
        std::cout << "battery" << model_ << " is charging" << '\n';
        std::chrono::seconds duration(charge_time_);
        std::this_thread::sleep_for(duration);
        stop_charging();
        current_charge_ = int(100);
    }
}

/**
 * @param amount
 * @return void
 */
void RWA2::Battery::discharge(double amount)
{
    current_charge_ = current_charge_- amount;
    std::cout << "Current_charge: " << current_charge_ << '\n';
}

/**
 * @return void
 */
void RWA2::Battery::stop_charging()
{
    is_charging_ = false;
    std::cout << "Battery" << model_ << "is fully charged" << '\n';
}