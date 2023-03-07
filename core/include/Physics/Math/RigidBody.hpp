#pragma once
#include <Physics/Math/Body.hpp>

namespace physics
{
    class RigidBody : public Body
    {
    public:
        RigidBody(Collider& collider, PHYSICS_INTERNAL_TYPE mass,
            float weight_scale = 9.8f, float weight_direction = 3.14159f)
            :Body(collider), m_Mass(mass), m_Weight(Vector2::FromPolar(weight_scale, weight_direction))
        {}

        virtual void Update(PHYSICS_INTERNAL_TYPE delta_time) override 
        {
            m_Velocity += m_Acceleration * delta_time + m_Weight * delta_time;
            m_Collider.Position += m_Velocity * delta_time + m_Acceleration * (PHYSICS_INTERNAL_TYPE)0.5 * delta_time * delta_time;
            m_Acceleration = (PHYSICS_INTERNAL_TYPE)0;
        }

        void ApplyForce(const Vector2& force)
        {
            m_Acceleration += force / m_Mass;
        }
    private:
        PHYSICS_INTERNAL_TYPE m_Mass;
        Vector2 m_Velocity, m_Acceleration, m_Weight;
    };
}