#pragma once
#include <cstdint>

namespace physics
{
    /// @brief color represented in normalized RGBA (0-1) space
    struct Color
    {
        float r, g, b, a;
        Color(float red, float green, float blue, float alpha = 1.0f)
            :r(red), g(green), b(blue), a(alpha)
        {}
        
        Color(float n = 0.0f)
            :r(n), g(n), b(n), a(n)
        {}

        static Color FromHex(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
        {
            return Color(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
        }

        static Color FromRed(float red, float alpha = 1.0f)
        {
            return Color(red, 0.0f, 0.0f, alpha);
        }

        static Color FromGreen(float green, float alpha = 1.0f)
        {
            return Color(0.0f, green, 0.0f, alpha);
        }

        static Color FromBlue(float blue, float alpha = 1.0f)
        {
            return Color(0.0f, 0.0f, blue, alpha);
        }

        Color operator+(const Color& other) const
        {
            return Color(this->r + other.r, this->g + other.g, this->b + other.b, this->a + other.a);
        }

        Color operator-(const Color& other) const
        {
            return Color(this->r - other.r, this->g - other.g, this->b - other.b, this->a - other.a);
        }

        Color operator*(const Color& other) const
        {
            return Color(this->r * other.r, this->g * other.g, this->b * other.b, this->a * other.a);
        }

        Color operator/(const Color& other) const
        {
            return Color(this->r / other.r, this->g / other.g, this->b / other.b, this->a / other.a);
        }

        Color operator*(float scalar) const
        {
            return Color(this->r * scalar, this->g * scalar, this->b * scalar, this->a * scalar);
        }

        Color operator/(float scalar) const
        {
            return Color(this->r / scalar, this->g / scalar, this->b / scalar, this->a / scalar);
        }

        Color& operator+=(const Color& other)
        {
            *this = *this + other;
            return *this;
        }

        Color& operator-=(const Color& other)
        {
            *this = *this - other;
            return *this;
        }

        Color& operator*=(const Color& other)
        {
            *this = *this * other;
            return *this;
        }

        Color& operator/=(const Color& other)
        {
            *this = *this / other;
            return *this;
        }

        Color& operator*=(float scalar)
        {
            *this = *this * scalar;
            return *this;
        }

        Color& operator/=(float scalar)
        {
            *this = *this / scalar;
            return *this;
        }

        Color clamp()
        {
            return Color(
                Functions::Clamp(this->r, 0.0f, 1.0f), 
                Functions::Clamp(this->g, 0.0f, 1.0f),
                Functions::Clamp(this->b, 0.0f, 1.0f),
                Functions::Clamp(this->a, 0.0f, 1.0f));
        }

        friend std::ostream& operator << (std::ostream& os, const Color& col)
        {
            os << '[' << col.r << ", " << col.g << ", " << col.b << ", " << col.a << ']';
            return os;
        }

        const static Color PureRed, PureGreen, PureBlue, PureYellow, PureCyan, PureMagenta,
                           White, Black, Gray50, Gray25, Gray75;
    };
}