#pragma once
#include <cmath>
#include <cstdint>
#include <ostream>
#include <Physics/Math/Matrix.hpp>

namespace physics
{
    /// @brief Two-component vector represented using the cartesian coordinate system
    /// @tparam T 
    template <class T>
    struct _Vector2
    {
        T x, y;
        
        /// @brief Vector from (x, y) cartesian coordinates
        /// @param x 
        /// @param y 
        _Vector2(T x, T y)
            :x(x), y(y)
        {}

        /// @brief Vector from scalar with x, y to be equal to the scalar
        /// @param n 
        _Vector2(T n = (T)0)
            :x(n), y(n)
        {}

        /// @brief Implicit conversion from _Vector<U> to _Vector<T>
        /// @tparam The template parameter of the vector
        /// @param vec The vector
        template <class U>
        _Vector2(const _Vector2<U>& vec)
            :x(vec.x), y(vec.y)
        {}

        /// @brief Vector from polar coordinates
        /// @param length 
        /// @param angle Angle from the y'y axis
        /// @return The vector in cartesian coordinates (does not affect functionality)
        static _Vector2 FromPolar(T length, T angle)
        {
            return _Vector2(length * std::cos(angle), length * std::sin(angle));
        }

        /// @brief Sum of two vectors
        /// @param other
        template <class U>
        _Vector2 operator+(const _Vector2<U>& other) const
        {
            return _Vector2(this->x + (T)other.x, this->y + (T)other.y);
        }

        /// @brief Difference of two vectors
        /// @param other
        template <class U>
        _Vector2 operator-(const _Vector2<U>& other) const
        {
            return _Vector2(this->x - (T)other.x, this->y - (T)other.y);
        }

        /// @brief The vector, every component of which is equal to 
        /// the product of the corresponding components of the input vectors
        /// @param other
        template <class U>
        _Vector2 operator*(const _Vector2<U>& other) const
        {
            return _Vector2(this->x * (T)other.x, this->y * (T)other.y);
        }

        /// @brief The vector, every component of which is equal to 
        /// the ratio between the corresponding components of the input vectors
        /// @param other
        template <class U>
        _Vector2 operator/(const _Vector2<U>& other) const
        {
            return _Vector2(this->x / (T)other.x, this->y / (T)other.y);
        }

        /// @brief Multiplication of all components by single scalar
        /// @param scalar 
        _Vector2 operator*(T scalar) const
        {
            return _Vector2(this->x * scalar, this->y * scalar);
        }

        /// @brief Division of all components by single scalar
        /// @param scalar
        _Vector2 operator/(T scalar) const
        {
            return _Vector2(this->x / scalar, this->y / scalar);
        }

        template <class U>
        _Vector2& operator+=(const _Vector2<U>& other)
        {
            *this = *this + other;
            return *this;
        }

        template <class U>
        _Vector2& operator-=(const _Vector2<U>& other)
        {
            *this = *this - other;
            return *this;
        }

        template <class U>
        _Vector2& operator*=(const _Vector2<U>& other)
        {
            *this = *this * other;
            return *this;
        }

        template <class U>
        _Vector2& operator/=(const _Vector2<U>& other)
        {
            *this = *this / other;
        }

        _Vector2& operator*=(T scalar)
        {
            *this = *this * scalar;
            return this;
        }

        _Vector2& operator/=(T scalar)
        {
            *this = *this * scalar;
        }

        /// @brief Negative of vector
        _Vector2& operator-() const
        {
            return _Vector2(-this->x, -this->y);
        }

        /// @brief Dot product of two vectors
        /// @param other, vector
        template <class U>
        T dot(const _Vector2<U>& other) const
        {
            return this->x * other.x + this->y * other.y;
        }

        /// @brief Dot product between a vector and itself
        T dot() const
        {
            return this->x * this->x + this->y * this->y;
        }

        /// @brief Operator for the length of a vector
        /// @return The length of the vector
        T operator!() const
        {
            return std::sqrt(dot());
        }

        _Vector2 normalize() const
        {
            T length = !(*this);
            return *this / length;
        }

        constexpr static _Vector2 One()
        {
            return _Vector2(1.0f);
        } 

        constexpr static _Vector2 Zero()
        {
            return _Vector2(0.0f);
        }

        constexpr static _Vector2 X()
        {
            return _Vector2{1.0f, 0.0f};
        }

        constexpr static _Vector2 Y()
        {
            return _Vector2{0.0f, 1.0f};
        }

        constexpr static _Vector2 FromMatrix(const _Matrix<T, 3, 1>& matrix)
        {
            return _Vector2{matrix[0][0] / matrix[2][0], matrix[1][0] / matrix[2][0]};
        }

        constexpr static _Matrix<T, 3, 1>& ToMatrix(const _Vector2& vector)
        {
            _Matrix<T, 3, 1> ret;
            ret[0][0] = vector.x;
            ret[1][0] = vector.y;
            ret[2][0] = 1.0f;
            return ret;
        }

        /// @brief Checks if both components of vector are greater than 
        /// the equivelant components of the specified vector
        /// @param other 
        template <class U>
        bool operator>(const _Vector2<U>& other) const
        {
            return this->x > other.x && this->y > other.y;
        }

        /// @brief Checks if both components of vector are less than 
        /// the equivelant components of the specified vector
        /// @param other 
        template <class U>
        bool operator<(const _Vector2<U>& other) const
        {
            return this->x < other.x && this->y < other.y;
        }

        /// @brief Checks if both components of vector are greater or equal to 
        /// the equivelant components of the specified vector
        /// @param other 
        template <class U>
        bool operator>=(const _Vector2<U>& other) const
        {
            return this->x >= other.x && this->y >= other.y;
        }

        /// @brief Checks if both components of vector are less than or equal to 
        /// the equivelant components of the specified vector
        /// @param other 
        template <class U>
        bool operator<=(const _Vector2<U>& other) const
        {
            return this->x <= other.x && this->y <= other.y;
        }

        /// @brief Checks if both components of vector are equal to 
        /// the equivelant components of the specified vector
        /// @param other 
        template <class U>
        bool operator==(const _Vector2<U>& other) const
        {
            return this->x == other.x && this->y == other.y;
        }

        /// @brief Checks if both components of vector are not equal to 
        /// the equivelant components of the specified vector
        /// @param other 
        template <class U>
        bool operator!=(const _Vector2<U>& other) const
        {
            return this->x != other.x && this->y != other.y;
        }

        /// @brief Operator << to be used with std::ostream
        /// @param os, the output stream
        /// @param vec, the vector to be appended to the stream
        /// @return Input stream with the vector appended
        friend std::ostream& operator << (std::ostream& os, const _Vector2& vec)
        {
            os << '[' << vec.x << ", " << vec.y << ']';
            return os;
        }
    };

    /// @brief PHYSICS_INTERNAL_TYPE is a macro set in CMakeLists.txt
    using Vector2 = _Vector2<PHYSICS_INTERNAL_TYPE>;
    
    using Vector2f64 = _Vector2<double>;
    using Vector2f32 = _Vector2<float>;
    
    using Vector2u64 = _Vector2<uint64_t>;
    using Vector2u32 = _Vector2<uint32_t>;
    using Vector2u16 = _Vector2<uint16_t>;
    using Vector2u8 = _Vector2<uint8_t>;

    using Vector2i64 = _Vector2<int64_t>;
    using Vector2i32 = _Vector2<int32_t>;
    using Vector2i16 = _Vector2<int8_t>;
    using Vector2i8 = _Vector2<int8_t>;

    using Vector2b = _Vector2<bool>;
}