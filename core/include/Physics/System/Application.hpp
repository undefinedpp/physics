#pragma once
#include <Physics/System/Window.hpp>
#include <Physics/System/Exception.hpp>
#include <Physics/Graphics/Drawable.hpp>
#include <iostream>

#define RETURN_SUCCESS 0
#define RETURN_STD_EXCEPTION -1
#define RETURN_PHYSICS_EXCEPTION -2
#define RETURN_UNKNOWN_EXCEPTION -3

namespace physics
{
    class Application
    {
    public:
        Application()
        {}

        virtual void OnStart() = 0;
        virtual void OnUpdate(PHYSICS_INTERNAL_TYPE delta_time) = 0;
    private:
        virtual void InitializeWindow(const WindowSize& size, const std::wstring& title, const WindowOptions& options) = 0;
        virtual void WindowLoop() = 0;
    public:
        virtual void Draw(Drawable& drawable) = 0;

        [[nodiscard]]
        virtual int Start(const WindowSize& size, const std::wstring& title, const WindowOptions& options = WindowOptions::Default)
        {
            #ifdef PHYSICS_DEBUG
            try
            {
            #endif
                //Initialization
                InitializeWindow(size, title, options);

                //Calling the Application's OnStart event method
                OnStart();

                //Start the main window loop
                WindowLoop();
            #ifdef PHYSICS_DEBUG
            }
            catch(const Exception& exception)
            {
                std::cout << "[PHYSICS EXCEPTION] An exception has been thrown. "
                 "Please contact the developers of this project. " << exception << '\n';
                return RETURN_PHYSICS_EXCEPTION;
            }
            catch(const std::exception& exception)
            {
                std::cout << "[STANDARD EXCEPTION] " << exception.what() << '\n';
                return RETURN_STD_EXCEPTION;
            }
            catch(...)
            {
                std::cout << "[PHYSICS UNKNOWN EXCEPTION]!\n";
                return RETURN_UNKNOWN_EXCEPTION;
            }
            #endif

            return RETURN_SUCCESS;
        }
    };
}