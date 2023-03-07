#pragma once
#include <Physics/Math/Body.hpp>

namespace physics
{
    class StaticBody : public Body
    {
    public:
        StaticBody(Collider& collider)
            :Body(collider)
        {}

        virtual void Update(PHYSICS_INTERNAL_TYPE delta_time) override final {}
    };
}