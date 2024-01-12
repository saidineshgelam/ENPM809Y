/**
 * Project Untitled
 */

#pragma once

#include <iostream>
#include <memory>
#include <thread>
#include <utility>

namespace RWA2
{

    class Battery
    {
    public:
        Battery(std::string model, int current_charge, bool is_charging) : model_{model},
                                                                           current_charge_{current_charge},
                                                                           is_charging_{is_charging}
        {

            // hi
        }
        Battery()
        {

            // initialize variables here
        }
        void start_charging();

        /**
         * @param amount
         */
        void discharge(double amount);

        double get_current_charge() { return current_charge_; }

        std::string get_battery_model() { return model_; }

    private:
        std::string model_;
        int current_charge_;
        bool is_charging_;

        void stop_charging();
    };

} // namespace RWA2