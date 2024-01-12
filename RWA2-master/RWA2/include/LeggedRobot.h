/**
 * Project Untitled
 */
#pragma once

#include "MobileRobot.h"

namespace RWA2
{

    class LeggedRobot final : public MobileRobot
    {
    public:
        /**
         * @param distance
         * @param angle
         */
        LeggedRobot(std::string bot_model, double x, double y, double orientation, std::string battery_model, int current_charge, int leg_strength, double height, int number_of_legs) : MobileRobot(bot_model, x, y, orientation, battery_model, current_charge), leg_strength_{leg_strength},
                                                                                                                                                                                         height_{height},
                                                                                                                                                                                         number_of_legs_{number_of_legs}
        {
            //
        }

        virtual void move(double distance, double angle) override;

        virtual void print_status() override;

    protected:
        /**
         * @param angle
         */
        virtual void rotate(double angle) override;

    private:
        double height_;
        int leg_strength_;
        int number_of_legs_{2};
        int battery_required_kick_{1};
        double max_distance_{1.0};
        void kick();

        /**
         * @param amount
         */
        void jump(double amount);
    }; // class LeggedRobot

} // namespace RWA2