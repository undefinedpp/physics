#include <Physics/SFML/Window.hpp>
#include <Physics/SFML/Application.hpp>
#include <Physics/Graphics/RectangleShape.hpp>
#include <Physics/Math/Matrix.hpp>
#include <Physics/Math/Body.hpp>
#include <Physics/Math/RigidBody.hpp>
#include <Physics/Math/StaticBody.hpp>
#include <memory>

class Demo : public physics::SFML::Application
{
public:
    Demo()
        :m_Shape(0.0f, 100.0f, physics::Color::PureRed)
    {}

private:
    void OnStart() override   
    {}

    void OnUpdate(float delta_time) override
    {
        static float t = 0.0f;
        t += delta_time;
        
        float sin2 = std::sin(t) * std::sin(t);

        m_Shape.SetPosition(GetWindow().GetSize() / 2.0f);
        m_Shape.SetScale(300.0f * sin2);
        m_Shape.SetColor(physics::Color::FromRed(sin2));
        GetWindow().SetClearColor(physics::Color::FromRed(1.0f - sin2));
        Draw(m_Shape);
    }
public:
    physics::RectangleShape m_Shape;
};

int main()
{
    Demo application;
    return application.Start(physics::WindowSize{800, 600}, L"Demo", physics::WindowOptions::Default);
}