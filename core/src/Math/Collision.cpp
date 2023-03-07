#include <Physics/Math/Collision.hpp>
#include <Physics/Math/RectangleCollider.hpp>
#include <Physics/Math/CircleCollider.hpp>
#include <Physics/Math/Functions.hpp>

namespace physics
{
    const bool Collision::RectangleToRectangle(const RectangleCollider& rectangle1, const RectangleCollider& rectangle2)
    {
        return rectangle1.Position + rectangle1.Size / 2.0f > rectangle2.Position - rectangle2.Size / 2.0f
            && rectangle2.Position + rectangle2.Size / 2.0f > rectangle1.Position - rectangle1.Size / 2.0f; 
    }

    const bool Collision::RectangleToCircle(const RectangleCollider& rectangle, const CircleCollider& circle)
    {
        return CircleToPoint(circle, 
            Functions::Clamp(
                circle.Position, rectangle.Position - rectangle.Size / 2.0f,
                rectangle.Position + rectangle.Size / 2.0f));
    }

    const bool Collision::CircleToCircle(const CircleCollider& circle1, const CircleCollider& circle2)
    {
        return !Vector2(circle1.Position - circle2.Position) < circle1.Radius + circle2.Radius;
    }

    const bool RectangleToPoint(const RectangleCollider& rectangle, const Vector2& point)
    {
        return point > rectangle.Position - rectangle.Size / 2.0f && point < rectangle.Position + rectangle.Size / 2.0f;
    }

    const bool CircleToPoint(const CircleCollider& circle, const Vector2& point)
    {
        return !Vector2(circle.Position - point) < circle.Radius;
    }
}