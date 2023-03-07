#pragma once
#include <string>
#include <Physics/Math/Vector2.hpp>
#include <Physics/Math/Color.hpp>

namespace physics
{
    using WindowSize = _Vector2<uint16_t>;
    
    enum WindowOptions
    {
        None = 0, 
        Close = 1 << 0,
        Resize = 1 << 1,
        Fullscreen = 1 << 2,
        Default = Close | Resize
    };

    class Window
    {
    public:
        Window() = default;

        virtual Window* Init(const WindowSize& size, const std::wstring& title, const WindowOptions& options = WindowOptions::Default) = 0;
        
        virtual void SetVSync(bool enabled) = 0;
        virtual void SetSize(const WindowSize& size) = 0;
        virtual void SetTitle(const std::wstring& title) = 0;
        virtual void SetClearColor(const Color& color) = 0;

        virtual bool GetVSync() const = 0;
        virtual const WindowSize& GetSize() const = 0;
        virtual const std::wstring& GetTitle() const = 0;
        virtual const Color& GetClearColor() const = 0;
        virtual bool GetFrame() const = 0; 

        virtual void Clear() = 0;
        virtual void PollEvents() = 0;
        virtual void SwapBuffers() = 0;
    };
}