#pragma once
#include <Physics/Math/Collider.hpp>

namespace physics
{
    /// @brief mathematical representation of a circle with the position being the center of the shape
    struct CircleCollider : public Collider
    {
        PHYSICS_INTERNAL_TYPE Radius = 0;
        const bool CollidesWith(const Collider& collider) const override;
        const bool CollidesWith(const Vector2& point) const override;
        const bool CollidesWith(const class RectangleCollider& collider) const override;
        const bool CollidesWith(const class CircleCollider& collider) const override;
    };
}