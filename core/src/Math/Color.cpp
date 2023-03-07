#include <Physics/Math/Color.hpp>

namespace physics
{
    const Color Color::PureRed = Color{1.0f, 0.0f, 0.0f, 1.0f};
    const Color Color::PureGreen = Color{0.0f, 1.0f, 0.0f, 1.0f};
    const Color Color::PureBlue = Color{0.0f, 0.0f, 1.0f, 1.0f};
    
    const Color Color::PureYellow = Color{1.0f, 1.0f, 0.0f, 1.0f};
    const Color Color::PureCyan = Color{0.0f, 1.0f, 1.0f, 1.0f};
    const Color Color::PureMagenta = Color{1.0f, 0.0f, 1.0f, 1.0f};

    const Color Color::White = Color{1.0f, 1.0f, 1.0f, 1.0f};
    const Color Color::Gray75 = Color{0.75f, 0.75f, 0.75f, 0.75f};
    const Color Color::Gray50 = Color{0.5f, 0.5f, 0.5f, 0.5f};
    const Color Color::Gray25 = Color{0.25f, 0.25f, 0.25f, 0.25f};
    const Color Color::Black = Color{0.0f, 0.0f, 0.0f, 0.0f};
}