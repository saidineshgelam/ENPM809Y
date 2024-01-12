/**
 * Project Untitled
 */

#pragma once

#include "MobileRobot.h"

namespace RWA2
{

    class AerialRobot final : public MobileRobot
    {
    public:
        AerialRobot(std::string bot_model, double x, double y, double orientation, std::string battery_model, int current_charge, bool has_wings, double altitude, bool is_flying) : MobileRobot(bot_model, x, y, orientation, battery_model, current_charge), has_wings_{has_wings},
                                                                                                                                                                                      altitude_{altitude}, is_flying_{is_flying}
        {
            //
        }
        void land();

        /**
         * @param distance
         * @param angle
         */
        virtual void move(double distance, double angle) override;

        virtual void print_status() override;

    protected:
        /**
         * @param angle
         */
        virtual void rotate(double angle) override;

    private:
        bool has_wings_;
        double altitude_{0.0};
        bool is_flying_{false};
        int max_distance_{50};
        int bat_req_per_m_{2};

        /**
         * @param altitude
         */
        void take_off(double altitude);
    };

} // namespace RWA2