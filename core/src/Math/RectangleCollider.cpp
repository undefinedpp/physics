#include <Physics/Math/RectangleCollider.hpp>
#include <Physics/Math/CircleCollider.hpp>
#include <Physics/Math/Collision.hpp>

namespace physics
{
    const bool RectangleCollider::CollidesWith(const Collider& collider) const
    {
        return collider.CollidesWith(*this);
    }

    const bool RectangleCollider::CollidesWith(const Vector2& point) const
    {
        return Collision::RectangleToPoint(*this, point);
    }

    const bool RectangleCollider::CollidesWith(const RectangleCollider& collider) const
    {
        return Collision::RectangleToRectangle(*this, collider);
    }

    const bool RectangleCollider::CollidesWith(const CircleCollider& collider) const
    {
        return Collision::RectangleToCircle(*this, collider);
    }
}