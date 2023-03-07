#pragma once
#include <Physics/Graphics/Drawable.hpp>

namespace physics
{
    class RectangleShape : public Drawable
    {
    public:
        RectangleShape(const Vector2& position = 0.0f, const Vector2& size = 0.0f, const Color& color = Color::Black)
            :Drawable(6)
        {
            CalculateVertices();
            SetPosition(position);
            SetScale(size);
            SetColor(color);
        }

        void CalculateVertices()
        {
            m_Vertices[0] = Vertex{
                {-0.5f,  -0.5f}, Color::White};
            
            m_Vertices[1] = Vertex{
                {+0.5f,  -0.5f}, Color::White};

            m_Vertices[2] = Vertex{
                {+0.5f,  +0.5f}, Color::White};

            m_Vertices[3] = Vertex{
                {+0.5f,  +0.5f}, Color::White};

            m_Vertices[4] = Vertex{
                {-0.5f,  +0.5f}, Color::White};

            m_Vertices[5] = Vertex{
                {-0.5f, -0.5f}, Color::White};
        }

        void SetColor(const Color& color)
        {
            m_Color = color;
            for(size_t i = 0; i < m_VertexCount; i++)
            {
                m_Vertices[i].Color = color;
            }
        }

        inline const Color& GetColor() const { return m_Color; }
    private:
        Color m_Color;        
    };
}