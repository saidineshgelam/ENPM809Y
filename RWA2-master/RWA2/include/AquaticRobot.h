/**
 * Project Untitled
 */

#pragma once

#include "MobileRobot.h"

namespace RWA2
{

    class AquaticRobot final : public MobileRobot
    {
    public:
        /**
         * @param distance
         * @param angle
         */
        virtual void move(double distance, double angle) override;

        void print_status();

        AquaticRobot(std::string bot_model, double x, double y, double orientation, std::string battery_model, int current_charge, bool has_fins_, double depth_, bool is_diving_)
            : MobileRobot(bot_model, x, y, orientation, battery_model, current_charge), has_fins_{has_fins_}, depth_{depth_}, is_diving_{is_diving_}
        {
        }

    protected:
        /**
         * @param angle
         */
        void rotate(double angle);

    private:
        bool has_fins_;
        double depth_ = 0.0;
        bool is_diving_ = false;

        /**
         * @param depth
         */
        void dive(double depth);

        void surface();
    };
} // namespace RWA2