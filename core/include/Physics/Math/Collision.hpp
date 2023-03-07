#pragma once
#include <Physics/Math/Vector2.hpp>

namespace physics
{
    class Collision
    {
    public:
        static const bool RectangleToRectangle(const class RectangleCollider&, const class RectangleCollider&);
        static const bool RectangleToCircle(const class RectangleCollider&, const class CircleCollider&);
        static const bool CircleToCircle(const class CircleCollider&, const class CircleCollider&);

        static const bool RectangleToPoint(const class RectangleCollider&, const Vector2&);
        static const bool CircleToPoint(const class CircleCollider&, const Vector2&);
    };
}