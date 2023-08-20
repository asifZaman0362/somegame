#include "registry.hpp"
#include "component.hpp"
#include "drawable.hpp"

template <>
int ComponentRegistry<Component>::counter = 0;

template <typename T>
int ComponentRegistry<T>::GetId() {
    static int id = ComponentRegistry<Component>::counter++;
    return id;
}

// Register components here
// Kind of hacky but necessary
auto _ = ComponentRegistry<DrawableComponent>::GetId();
//
