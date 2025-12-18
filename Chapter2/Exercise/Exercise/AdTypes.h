#pragma once

#include <cstdint>

#include "AdConstants.h"

namespace Ad {
    namespace Types {
        enum class LaneAssociationType
        {
            UnknownLane,
            LeftLane,
            CenterLane,
            RightLane,
        };

        struct VehicleType
        {
            int32_t Id;
            LaneAssociationType Lane;
            float Speed;
            float RelativeDistance;
        };
    }
}
