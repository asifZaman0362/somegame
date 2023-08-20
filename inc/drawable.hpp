#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "component.hpp"
#include <SFML/Graphics/Drawable.hpp>

struct DrawableComponent : public Component {
    sf::Drawable* drawable;
};

#endif
