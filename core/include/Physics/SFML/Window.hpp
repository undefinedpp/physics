#pragma once
#include <Physics/System/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Physics/SFML/Convert.hpp>

namespace physics::SFML
{
    class Window : public physics::Window
    {
    public:
        Window()
            :m_VSync(false), m_Title(L"")
        {}

        virtual Window* Init(const WindowSize& size, const std::wstring& title, const WindowOptions& options = WindowOptions::Default) override
        {
            m_Title = title;
            int sf_style = 0;
            if(options & WindowOptions::Close) sf_style |= sf::Style::Close;
            if(options & WindowOptions::Resize) sf_style |= sf::Style::Resize;
            if(options & WindowOptions::Fullscreen) sf_style |= sf::Style::Fullscreen;
            m_Window.create(sf::VideoMode(size.x, size.y), sf::String(title), sf_style);
            return this;
        }
        
        void SetVSync(bool enabled) override
        {
            m_VSync = enabled;
            m_Window.setVerticalSyncEnabled(enabled);
        }

        void SetSize(const WindowSize& size) override
        {
            m_Window.setSize(sf::Vector2u{size.x, size.y});
        }

        void SetTitle(const std::wstring& title) override
        {
            m_Window.setTitle(sf::String(title));
        }
        
        void SetClearColor(const Color& color) override
        {
            m_ClearColor = color;
        }

        bool GetVSync() const override { return m_VSync; }

        const WindowSize& GetSize() const override
        { 
            m_Size = WindowSize{(uint16_t)m_Window.getSize().x, (uint16_t)m_Window.getSize().y};
            return m_Size; 
        }

        const std::wstring& GetTitle() const override { return m_Title; }
        const Color& GetClearColor() const override { return m_ClearColor; }
        bool GetFrame() const override { return m_Window.isOpen(); }

        virtual void Clear() override
        {
            m_Window.clear(Convert::ColorToSFML(m_ClearColor));
        }

        virtual void PollEvents() override
        {
            sf::Event event;
            while(m_Window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    m_Window.close();
                else if(event.type == sf::Event::Resized)
                {
                    sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                    m_Window.setView(sf::View(visibleArea));
                }
            }
        }

        virtual void SwapBuffers() override
        {
            m_Window.display();
        }

        inline sf::RenderWindow& GetInternalWindow() { return m_Window; }
    private:
        mutable WindowSize m_Size;
        Color m_ClearColor;
        std::wstring m_Title;
        sf::RenderWindow m_Window;
        bool m_VSync;
    };
}