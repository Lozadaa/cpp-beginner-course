#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdFunctions.h"

namespace
{
void init_vehicle(Ad::Types::VehicleType &vehicle,
                  const std::int32_t id,
                  const float speed_kph,
                  const float distance_m,
                  const Ad::Types::LaneAssociationType lane)
{
    vehicle.id = id;
    vehicle.speed_mps = Ad::Utils::kph_to_mps(speed_kph);
    vehicle.distance_m = distance_m;
    vehicle.lane = lane;
}
} // namespace

namespace Ad
{
  namespace Utils
  {
    float kph_to_mps(const float kph){
      return kph / 3.6F;
    }

    namespace Data
    {
      Ad::Types::VehicleType init_ego_vehicle(){
        return Ad::Types::VehicleType{
            .id = Ad::Constants::EGO_VEHICLE_ID,
            .lane = Ad::Types::LaneAssociationType::CENTER,
            .speed_mps = Ad::Utils::kph_to_mps(135.0F),
            .distance_m = 0.0F,
        };
      }
      Ad::Types::NeighborVehiclesType init_vehicles(){
        auto vehicles = Ad::Types::NeighborVehiclesType{};
        
        init_vehicle(vehicles.vehicles_left_lane[0], 1, 150, -80, Ad::Types::LaneAssociationType::LEFT);
        init_vehicle(vehicles.vehicles_left_lane[1], 2, 130, -50, Ad::Types::LaneAssociationType::LEFT);
        init_vehicle(vehicles.vehicles_center_lane[0], 3, 100, 30, Ad::Types::LaneAssociationType::CENTER);
        init_vehicle(vehicles.vehicles_center_lane[0], 4, 100, 30, Ad::Types::LaneAssociationType::CENTER);
        init_vehicle(vehicles.vehicles_right_lane[0], 5, 80, 50, Ad::Types::LaneAssociationType::RIGHT);
        init_vehicle(vehicles.vehicles_right_lane[1], 6, 60, -80, Ad::Types::LaneAssociationType::RIGHT);

        return vehicles;
      }
    } // namespace Data
  }

  namespace Visualize
  {

    void print_vehicle(const Ad::Types::VehicleType &vehicle)
    {
    }

    void print_neighbor_vehicles(const Ad::Types::NeighborVehiclesType &vehicles)
    {
    }

    void print_scene(const Ad::Types::VehicleType &ego_vehicle,
                    const Ad::Types::NeighborVehiclesType &vehicles)
    {
      std::cout << '          L  C  R  ' << '\n';
      for(std::int16_t i = -Ad::Constants::VIEW_RANGE_M; i <= Ad::Constants::VIEW_RANGE_M; i += 20){
        std::cout << i << '\n';
      }
    }

  } // namespace Visualize
} // namespace Add
