#pragma once
#include <Physics/System/Application.hpp>
#include <Physics/SFML/Convert.hpp>
#include <unordered_map>

namespace physics::SFML
{
    class Application : public physics::Application
    {
    public:
        Application()
            :m_DeltaTime(0.0f), m_Time(0.0f), m_PreviousTime(0.0f)
        {}

        virtual void Draw(Drawable& drawable) override
        {
            const auto& vertices = drawable.GetVertices();
            sf::VertexArray sf_vertices(sf::Triangles, drawable.GetVertexCount());

            for(size_t i = 0; i < drawable.GetVertexCount(); i++)
            {
                const Vertex& vertex = vertices[i];
                sf_vertices[i].position = 
                    Convert::VectorToSFML(
                        vertex.Position * drawable.GetScale() + drawable.GetPosition()
                    );
                sf_vertices[i].color = Convert::ColorToSFML(
                    vertex.Color
                );
            }

            m_Window.GetInternalWindow().draw(sf_vertices);
        }

        void InitializeWindow(const WindowSize& size, const std::wstring& title, const WindowOptions& options) override 
        {
            m_Window.Init(size, title, options);
        }

        void WindowLoop() override 
        {
            m_PreviousTime = m_Time = m_Clock.getElapsedTime().asMicroseconds();
            while(m_Window.GetFrame())
            {
                m_PreviousTime = m_Time;
                m_Time = m_Clock.getElapsedTime().asMicroseconds();
                m_DeltaTime = (m_Time - m_PreviousTime) / 1e+6f;
                m_Window.Clear();

                OnUpdate(m_DeltaTime);

                m_Window.SwapBuffers();
                m_Window.PollEvents();
            }
        }

        inline const Window& GetWindow() const { return m_Window; }
        inline Window& GetWindow() { return m_Window; }
    private:
        sf::Clock m_Clock;
        float m_PreviousTime, m_Time, m_DeltaTime;
        Window m_Window;
    };
}