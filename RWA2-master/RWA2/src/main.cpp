#include <iostream>
#include <memory>
#include <vector>

#include "MobileRobot.h"
#include "AerialRobot.h"
#include "LeggedRobot.h"
#include "WheeledRobot.h"
#include "AquaticRobot.h"

void get_status(const std::vector<std::unique_ptr<RWA2::MobileRobot>> &robots)
{
    for (auto it = robots.cbegin(); it != robots.cend(); ++it)
{
    const auto &robot = *it;
    robot->print_status();
}
}
void move_robot(const std::vector<std::unique_ptr<RWA2::MobileRobot>> &robots)
{
    for (auto it = robots.cbegin(); it != robots.cend(); ++it)
{
    const auto &robot = *it;
    robot->move(5.0, 5.0);
}
}
void add_sensor(const std::vector<std::unique_ptr<RWA2::MobileRobot>> &robots)
{
   for (const auto &robot : robots)
{
    // Generate a random number (0 or 1)
    int randomValue = std::rand() % 2;

    // Add a sensor based on the random number
    if (randomValue == 0)
    {
        robot->add_sensor(std::make_unique<RWA2::Sensor>("OSDome"));
    }
    else
    {
        robot->add_sensor(std::make_unique<RWA2::Sensor>("LD-MRS"));
    }
}

}
int main()
{
    std::vector<std::unique_ptr<RWA2::MobileRobot>> mobile_robots;
    std::unique_ptr<RWA2::MobileRobot> spot_robot =
        std::make_unique<RWA2::LeggedRobot>("Spot", 0.0, 0.0, 0.0, "Li-ion", 10, 2, 0.5, 2);
    std::unique_ptr<RWA2::MobileRobot> crazyflie_robot =
        std::make_unique<RWA2::AerialRobot>("CrazyFlie", 0.0, 0.0, 0.0, "LiFePO4", 70, false, 0, false);
    std::unique_ptr<RWA2::MobileRobot> sofi_robot =
        std::make_unique<RWA2::AquaticRobot>("Sofi", 0.0, 0.0, 0.0, "Li-ion", 90, true, 10, false);
    std::unique_ptr<RWA2::MobileRobot> turtlebot_robot =
        std::make_unique<RWA2::WheeledRobot>("Turtlebot", 3.0, 0.0, 0.0, "LiFePO4", 20, 2, 0.1, 2);
    std::unique_ptr<RWA2::MobileRobot> erle_plane_robot =
        std::make_unique<RWA2::AerialRobot>("Erle-Plane", 0.0, 0.0, 0.0, "Li-ion", 30, true, 0, false);

    mobile_robots.push_back(std::move(erle_plane_robot));
    mobile_robots.push_back(std::move(crazyflie_robot));
    mobile_robots.push_back(std::move(turtlebot_robot));
    mobile_robots.push_back(std::move(sofi_robot));
    mobile_robots.push_back(std::move(spot_robot));
    add_sensor(mobile_robots);
    move_robot(mobile_robots);
    get_status(mobile_robots);
}