#include <Physics/Math/Collider.hpp>
#include <Physics/Math/RectangleCollider.hpp>
#include <Physics/Math/CircleCollider.hpp>

namespace physics
{
    const bool Collider::CollidesWith(const RectangleCollider& collider) const
    {
        return collider.CollidesWith(*this);
    }

    const bool Collider::CollidesWith(const CircleCollider& collider) const
    {
        return collider.CollidesWith(*this);
    }
}