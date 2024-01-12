/**
 * Project Untitled
 */

#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include "Battery.h"
#include "Sensor.h"

namespace RWA2
{

    class MobileRobot
    {
    public:
        /**
         * @param distance
         * @param angle
         */
        MobileRobot(std::string bot_model, double x, double y, double orientation, std::string battery_model, int current_charge) : model_{bot_model}, position_{x, y}, orientation_{orientation}, battery_{battery_model, current_charge, false}
                // MobileRobot(double x, double y, double orientation) : position_{x, y}, orientation_{orientation}, battery_{model_, 100, false}

        {
            //
        }

        // MobileRobot()
        // {
        //     //empty body/
        //     // initiaize vars here
        // }

        virtual void move(double distance, double angle);

        virtual void print_status();
        void add_sensor(std::unique_ptr<RWA2::Sensor> sensor);

        /**
         * @brief Get the sensor reading
         * @param period period of the sensor reading
         * @return double
         */
        std::array<double, 50> get_sensor_reading(int period);

    protected:
        std::pair<double, double> position_;
        double orientation_;
        double speed_ = 0.0;
        RWA2::Battery battery_;
        std::vector<std::unique_ptr<RWA2::Sensor>> sensors_;
        std::string model_;

        /**
         * @param angle
         */
        virtual void rotate(double angle) = 0;

    private:
        std::array<double, 50> sensor_reading;
    };

} // namespace RWA2