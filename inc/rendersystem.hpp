#ifndef RENDER_SYSTEM_HPP
#define RENDER_SYSTEM_HPP

#include "scene.hpp"
#include "system.hpp"

class RenderSystem : System {
    void update(float, ECTable*) const;
};

#endif
