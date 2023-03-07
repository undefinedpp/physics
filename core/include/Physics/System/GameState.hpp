#pragma once
#include <iostream>

namespace physics
{
    class GameState
    {
    public:
        virtual void OnStart() = 0;
        virtual void OnUpdate(float delta_time) = 0;

        virtual void OnDestroy()
        {
            #ifdef PHYSICS_DEBUG
            std::cout << "[GameState OnDestroy event]\n";
            #endif
        }

        virtual void OnHide()
        {
            #ifdef PHYSICS_DEBUG
            std::cout << "[GameState OnHide event]\n";
            #endif
        }

        virtual void OnEnable()
        {
            #ifdef PHYSICS_DEBUG
            std::cout << "[GameState OnEnable event]\n";
            #endif
        }

        void SetToDestroy(bool set = true)
        {
            m_ToBeDestroyed = set;
        }
    private:
        bool m_ToBeDestroyed = false;
    protected:
        const class Application* m_Application;
    };
}