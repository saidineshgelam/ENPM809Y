/**
 * Project Untitled
 */

#pragma once

#include <iostream>
#include <memory>
#include <thread>
#include <utility>
#include <array>

namespace RWA2
{

    class Sensor final
    {
    public:
        Sensor(std::string model)
            : model_{model}{}

        void read_data(unsigned int duration);
        std::array<double, 50> get_sensor_data();

    private:
        std::string model_;
        std::array<double, 50> data_;

    }; // class Sensor

} // namespace RWA2