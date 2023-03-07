#pragma once
#include <Physics/Math/Collider.hpp>

namespace physics
{
    /// @brief base collider class
    struct  Collider
    {
        Vector2 Position = 0;
        virtual const bool CollidesWith(const Collider& collider) const = 0;
        virtual const bool CollidesWith(const Vector2& point) const = 0;
        virtual const bool CollidesWith(const class RectangleCollider& collider) const;
        virtual const bool CollidesWith(const class CircleCollider& collider) const;
    };
}