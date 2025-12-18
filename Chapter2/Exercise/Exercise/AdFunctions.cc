#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdFunctions.h"

namespace Ad{
    namespace Utils {
        float kph_to_mps(const float kph){
            return kph * 3.6F;
        }
    }

    namespace Data {
        Ad::Types::VehicleType init_ego_vehicle(){
            return {
                .Id = Ad::Constants::EGO_VEHICLE_ID,
                .Speed= Ad::Utils::kph_to_mps(135.0F),
                .Lane= Ad::Types::LaneAssociationType::CenterLane,
                .RelativeDistance = 0.0F
            };
        }
    }


    namespace Visualize {
        void print_vehicle(const Ad::Types::VehicleType vehicle){
            std::cout << "Id: " << vehicle.Id << '\n';
            std::cout << "Speed: " << vehicle.Speed << '\n';
            std::cout << "Distance: " << vehicle.RelativeDistance << '\n';
            std::cout << "Lane: " << static_cast<int>(vehicle.Lane) << '\n';
        }
    }
}
