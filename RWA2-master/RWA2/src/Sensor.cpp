/**
 * Project Untitled
 */


#include "Sensor.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <random>
/**
 * Sensor implementation
 */


/**
 * @param duration
 * @return void
 */
void RWA2::Sensor::read_data(unsigned int duration) {
    
    std::cout << "Sensor " << model_ << "  gathering data for "<< duration << " seconds";

    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::random_device rd;  // Random device engine, usually based on
    std::mt19937 gen(rd());  // Initializes with the random device
    std::uniform_real_distribution<> dis(1.0, 30.0);
    for (int i = 0; i < data_.size(); ++i) {
        data_[i] = dis(gen);
    }
    std::cout << "Sensor " << model_ << " read data: 0";
    for (int i = 0; i < data_.size(); ++i) {
        std::cout << data_[i]<<" , " ;
    }
    std::cout << '\n';
    
}

std::array<double, 50> RWA2::Sensor::get_sensor_data() {
    return data_;
}