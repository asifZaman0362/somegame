#include "rendersystem.hpp"
#include "drawable.hpp"
#include "scene.hpp"
#include "registry.hpp"
#include "game.hpp"

template<typename T>
inline T* get_comp(Entity e, ECTable *table) {
    return static_cast<T*> ((*table)[e][ComponentRegistry<T>::GetId()].get());
}

void RenderSystem::update(float, ECTable* ectable) const {
    int component_id = ComponentRegistry<DrawableComponent>::GetId();
    for (auto entity : entities) {
        auto drawable = get_comp<DrawableComponent>(entity, ectable)->drawable;
        Game::get_window_surface().draw(*drawable);
    }
}
