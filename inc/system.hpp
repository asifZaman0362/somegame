#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "scene.hpp"

class System {
    friend class Scene;
    virtual void update(float, ECTable const*) const = 0;
    void register_entity(const Entity);

   protected:
    std::vector<Entity> entities;
};

#endif
