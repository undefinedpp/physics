#pragma once
#include <SFML/System.hpp>
#include <Physics/Math/Vector2.hpp>
#include <Physics/Math/Color.hpp>

namespace physics::SFML
{
    class Convert
    {
    public:
        // Note: we are using sf::Vector2f here and not sf::Vector2<PHYSICS_INTERNAL_TYPE>
        // because of SFML's choice to require float template parameters in most cases, 
        // thus rendering using anything other than floats useless
        static sf::Vector2f VectorToSFML(const Vector2& vector)
        {
            return sf::Vector2f{(float)vector.x, (float)vector.y};
        }

        template <class T>
        static Vector2 VectorFromSFML(const sf::Vector2<T>& vector)
        {
            return Vector2{(PHYSICS_INTERNAL_TYPE)vector.x, (PHYSICS_INTERNAL_TYPE)vector.y};
        }

        static sf::Color ColorToSFML(const Color& color)
        {
            return sf::Color{uint8_t(color.r * 255), uint8_t(color.g * 255), uint8_t(color.b * 255), uint8_t(color.a * 255)};
        }

        static Color ColorFromSFML(const sf::Color& color)
        {
            return Color{color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f};
        }
    };
}