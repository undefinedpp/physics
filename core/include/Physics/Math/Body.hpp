#pragma once
#include <optional>
#include <Physics/Math/Collider.hpp>

namespace physics
{
    class Body
    {
    public:
        Body(Collider& collider)
            :m_Collider(collider)
        {}

        inline void SetPosition(const Vector2& position) 
        {
            m_Collider.Position = position;
        }

        inline const Vector2& GetPosition() const { return m_Collider.Position; } 
        inline const Collider& GetCollider() const { return m_Collider; }

        virtual void Update(PHYSICS_INTERNAL_TYPE delta_time) = 0;
    protected:
        Collider& m_Collider;
    };
}