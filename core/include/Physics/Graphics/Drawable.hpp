#pragma once
#include <Physics/Math/Matrix.hpp>
#include <Physics/System/Application.hpp>
#include <Physics/Graphics/Vertex.hpp>

namespace physics
{
    struct Rotation
    {
        PHYSICS_INTERNAL_TYPE Angle;
        Vector2 Origin = 0;
    };

    class Drawable
    {
    public:
        Drawable(size_t count)
            :m_Vertices(count ? new Vertex[count] : nullptr), m_VertexCount(count)
        {}

        Drawable(const Drawable& other)
            :m_Vertices(other.m_VertexCount ? new Vertex[other.m_VertexCount] : nullptr), m_VertexCount(other.m_VertexCount),
            m_Translation(other.m_Translation), m_Scale(other.m_Scale), m_Rotation(other.m_Rotation)
        {
            for(size_t i = 0; i < m_VertexCount; i++)
            {
                m_Vertices[i] = other.m_Vertices[i];
            }
        }

        Drawable(Drawable&& other)
            :m_Vertices(other.m_Vertices), m_VertexCount(other.m_VertexCount),
            m_Translation(other.m_Translation), m_Scale(other.m_Scale), m_Rotation(other.m_Rotation)
        {
            other.m_Vertices = nullptr;
            other.m_VertexCount = 0;
        }

        Drawable& operator= (const Drawable& other)
        {
            *this = Drawable(other);
            return *this;
        }

        virtual ~Drawable()
        {
            delete[] m_Vertices;
        }

        void SetPosition(const Vector2& position)
        {
            m_Translation = position;
        }

        void SetScale(const Vector2& scale)
        {
            m_Scale = scale;
        }

        void SetRotation(const Rotation& rotation)
        {
            m_Rotation = rotation;
        }

        void SetTransform(const Vector2& position, const Vector2& scale, const Rotation& rotation)
        {
            m_Translation = position;
            m_Scale = scale;
            m_Rotation = rotation;
        }

        inline const Vertex* GetVertices() const { return m_Vertices; }
        inline Vertex* GetVertices() { return m_Vertices; }
        inline size_t GetVertexCount() const { return m_VertexCount; }
        inline const Vector2& GetPosition() const { return m_Translation; }
        inline const Vector2& GetScale() const { return m_Scale; }
        inline const Rotation& GetRotation() const { return m_Rotation; }
    protected:
        size_t m_VertexCount;
        Vertex* m_Vertices;
        Vector2 m_Translation, m_Scale;
        Rotation m_Rotation;
    };
}