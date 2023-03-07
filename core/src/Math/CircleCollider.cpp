#include <Physics/Math/CircleCollider.hpp>
#include <Physics/Math/RectangleCollider.hpp>
#include <Physics/Math/Collision.hpp>

namespace physics
{
    const bool CircleCollider::CollidesWith(const Collider& collider) const
    {
        return collider.CollidesWith(*this);
    }

    const bool CircleCollider::CollidesWith(const Vector2& point) const
    {
        return Collision::CircleToPoint(*this, point);
    }

    const bool CircleCollider::CollidesWith(const RectangleCollider& collider) const
    {
        return Collision::RectangleToCircle(collider, *this);
    }

    const bool CircleCollider::CollidesWith(const CircleCollider& collider) const
    {
        return Collision::CircleToCircle(*this, collider);
    }
}