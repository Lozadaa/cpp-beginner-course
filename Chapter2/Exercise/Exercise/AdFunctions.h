#pragma once

#include "AdTypes.h"
namespace Ad{
    namespace Utils {
        // namespace Ad::Utils
        float kph_to_mps(const float kph);
    }

    namespace Data {
        // namespace Ad::Data
        Ad::Types::VehicleType init_ego_vehicle();
    }

    namespace Visualize {
        // namespace Ad::Visualize
        void print_vehicle(const Ad::Types::VehicleType vehicle);
    }
}
