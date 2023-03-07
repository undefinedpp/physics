#pragma once
#include <Physics/System/Exception.hpp>

namespace physics
{
    /// @brief Generic MxN column-major representation of a matrix 
    /// @tparam T type of values of the matrix
    template <class T, size_t ROWS, size_t COLUMNS>
    class _Matrix
    {
    private:
        T m[ROWS][COLUMNS];
    public:
        _Matrix()
            :m{0}
        {}

        static constexpr _Matrix Identity()
        {
            _Matrix matrix;
            for(size_t i = 0; i < std::min(COLUMNS, ROWS); i++)
                matrix[i][i] = (T)1;
            return matrix;
        }

        template <class U>
        _Matrix operator+(const _Matrix<U, ROWS, COLUMNS>& other)
        {
            _Matrix matrix;
            for(size_t i = 0; i < ROWS; i++)
                for(size_t j = 0; j < COLUMNS; j++)
                    matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
            return matrix;
        }

        template <class U>
        _Matrix operator-(const _Matrix<U, ROWS, COLUMNS>& other)
        {
            _Matrix matrix;
            for(size_t i = 0; i < ROWS; i++)
                for(size_t j = 0; j < COLUMNS; j++)
                    matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
            return matrix;
        }

        template <class U, size_t OTHER_COLUMNS>
        _Matrix operator*(const _Matrix<U, COLUMNS, OTHER_COLUMNS>& other)
        {
            _Matrix<T, ROWS, OTHER_COLUMNS> matrix;
            for(size_t r = 0; r < ROWS; r++)
                for (size_t c = 0; c < OTHER_COLUMNS; c++)
                    for(size_t i = 0; i < COLUMNS; i++)
                        matrix[r][c] += (*this)[r][i] * U(other[i][c]);
        }

        static _Matrix<T, 3, 3> Rotation2D(float theta)
        {
            _Matrix<T, 3, 3> matrix;
            matrix.at[0][0] = std::cos(theta);
            matrix.at[1][0] = std::sin(theta);
            matrix.at[0][1] = -std::sin(theta);
            matrix.at[1][1] = std::cos(theta);
            matrix.at[2][2] = 1.0f;
        }

        static _Matrix<T, 3, 3> Translation2D(float x, float y)
        {
            _Matrix<T, 3, 3> matrix = Identity();
            matrix[0][2] = x;
            matrix[1][2] = y;
            return matrix;
        }

        static _Matrix<T, 3, 3> Scale2D(float x, float y)
        {
            _Matrix<T, 3, 3> matrix;
            matrix[0][0] = x;
            matrix[1][1] = y;
            matrix[2][2] = 1;
        }

        T* operator[](size_t index)
        {
            return m[index];
        }

        const T* const operator[](size_t index) const
        {
            return m[index];
        }

        // T& operator[](size_t index)
        // {
        //     #ifdef PHYSICS_DEBUG
        //     if(index > ROWS * COLUMNS - 1)
        //         throw PHYSICS_EXCEPTION("Tried to access index [" + std::to_string(index) + "] of a " +
        //         std::to_string(ROWS) + "x" + std::to_string(COLUMNS) + " matrix (max is " + 
        //         std::to_string(ROWS * COLUMNS - 1) + ")");
        //     #endif
        //     return m[index];
        // }

        // T& at(size_t index)
        // {
        //     return (*this)[index];
        // }

        // T& at(size_t row, size_t column)
        // {
        //     #ifdef PHYSICS_DEBUG
        //     if(row > ROWS - 1 || column > COLUMNS - 1)
        //         throw PHYSICS_EXCEPTION("Tried to access element [" + std::to_string(row) + ", " +
        //             std::to_string(column) + "] of a " + std::to_string(ROWS) + "x" + std::to_string(COLUMNS) + 
        //             " matrix (max is [" + std::to_string(ROWS - 1) + ", " + std::to_string(COLUMNS - 1) + "])");
        //     #endif
        //     return m[row + column * ROWS];
        // }
    };

    //Primary square matrix type definitions
    using Matrix2 = _Matrix<PHYSICS_INTERNAL_TYPE, 2, 2>;
    using Matrix3 = _Matrix<PHYSICS_INTERNAL_TYPE, 3, 3>;
    using Matrix4 = _Matrix<PHYSICS_INTERNAL_TYPE, 4, 4>;

    //Square 2x2 definitions 
    using Matrix2f64 = _Matrix<double, 2, 2>;
    using Matrix2f32 = _Matrix<float, 2, 2>;
    
    using Matrix2u64 = _Matrix<uint64_t, 2, 2>;
    using Matrix2u32 = _Matrix<uint32_t, 2, 2>;
    using Matrix2u16 = _Matrix<uint16_t, 2, 2>;
    using Matrix2u8 = _Matrix<uint8_t, 2, 2>;

    using Matrix2i64 = _Matrix<int64_t, 2, 2>;
    using Matrix2i32 = _Matrix<int32_t, 2, 2>;
    using Matrix2i16 = _Matrix<int16_t, 2, 2>;
    using Matrix2i8 = _Matrix<int8_t, 2, 2>;

    using Matrix2b = _Matrix<bool, 2, 2>;

    using Matrix2x2f64 = _Matrix<double, 2, 2>;
    using Matrix2x2f32 = _Matrix<float, 2, 2>;
    
    using Matrix2x2u64 = _Matrix<uint64_t, 2, 2>;
    using Matrix2x2u32 = _Matrix<uint32_t, 2, 2>;
    using Matrix2x2u16 = _Matrix<uint16_t, 2, 2>;
    using Matrix2x2u8 = _Matrix<uint8_t, 2, 2>;

    using Matrix2x2i64 = _Matrix<int64_t, 2, 2>;
    using Matrix2x2i32 = _Matrix<int32_t, 2, 2>;
    using Matrix2x2i16 = _Matrix<int16_t, 2, 2>;
    using Matrix2x2i8 = _Matrix<int8_t, 2, 2>;

    using Matrix2x2b = _Matrix<bool, 2, 2>;

    //Square 3x3 definitions 
    using Matrix3f64 = _Matrix<double, 3, 3>;
    using Matrix3f32 = _Matrix<float, 3, 3>;
    
    using Matrix3u64 = _Matrix<uint64_t, 3, 3>;
    using Matrix3u32 = _Matrix<uint32_t, 3, 3>;
    using Matrix3u16 = _Matrix<uint16_t, 3, 3>;
    using Matrix3u8 = _Matrix<uint8_t, 3, 3>;

    using Matrix3i64 = _Matrix<int64_t, 3, 3>;
    using Matrix3i32 = _Matrix<int32_t, 3, 3>;
    using Matrix3i16 = _Matrix<int16_t, 3, 3>;
    using Matrix3i8 = _Matrix<int8_t, 3, 3>;

    using Matrix3b = _Matrix<bool, 3, 3>;

    using Matrix3x3f64 = _Matrix<double, 3, 3>;
    using Matrix3x3f32 = _Matrix<float, 3, 3>;
    
    using Matrix3x3u64 = _Matrix<uint64_t, 3, 3>;
    using Matrix3x3u32 = _Matrix<uint32_t, 3, 3>;
    using Matrix3x3u16 = _Matrix<uint16_t, 3, 3>;
    using Matrix3x3u8 = _Matrix<uint8_t, 3, 3>;

    using Matrix3x3i64 = _Matrix<int64_t, 3, 3>;
    using Matrix3x3i32 = _Matrix<int32_t, 3, 3>;
    using Matrix3x3i16 = _Matrix<int16_t, 3, 3>;
    using Matrix3x3i8 = _Matrix<int8_t, 3, 3>;

    using Matrix3x3b = _Matrix<bool, 3, 3>;
    
    //Square 4x4 definitions
    using Matrix4f64 = _Matrix<double, 4, 4>;
    using Matrix4f32 = _Matrix<float, 4, 4>;
    
    using Matrix4u64 = _Matrix<uint64_t, 4, 4>;
    using Matrix4u32 = _Matrix<uint32_t, 4, 4>;
    using Matrix4u16 = _Matrix<uint16_t, 4, 4>;
    using Matrix4u8 = _Matrix<uint8_t, 4, 4>;

    using Matrix4i64 = _Matrix<int64_t, 4, 4>;
    using Matrix4i32 = _Matrix<int32_t, 4, 4>;
    using Matrix4i16 = _Matrix<int16_t, 4, 4>;
    using Matrix4i8 = _Matrix<int8_t, 4, 4>;

    using Matrix4b = _Matrix<bool, 4, 4>;

    using Matrix4x4f64 = _Matrix<double, 4, 4>;
    using Matrix4x4f32 = _Matrix<float, 4, 4>;
    
    using Matrix4x4u64 = _Matrix<uint64_t, 4, 4>;
    using Matrix4x4u32 = _Matrix<uint32_t, 4, 4>;
    using Matrix4x4u16 = _Matrix<uint16_t, 4, 4>;
    using Matrix4x4u8 = _Matrix<uint8_t, 4, 4>;

    using Matrix4x4i64 = _Matrix<int64_t, 4, 4>;
    using Matrix4x4i32 = _Matrix<int32_t, 4, 4>;
    using Matrix4x4i16 = _Matrix<int16_t, 4, 4>;
    using Matrix4x4i8 = _Matrix<int8_t, 4, 4>;

    using Matrix4x4b = _Matrix<bool, 4, 4>;
}  
