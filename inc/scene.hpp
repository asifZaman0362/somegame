#ifndef SCENE_HPP
#define SCENE_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include <vector>

#include "component.hpp"

#define MAX_COMPONENTS 64

typedef unsigned long long Entity;
typedef std::shared_ptr<Component> ComponentPtr;

// naive entity component table (TODO: make proper later maybe if necessary)
// terrible cache locality (TODO: swap rows with columns...
//                              ...right now components are fetched per entity...
//                              ...every iteration [comp1, comp2, comp3, ...] is fetched...
//                              ...but only one of these is used inside a system's update loop...
//                              ...fetching the same component (of the same type i.e) requires fetching...
//                              ...another row [c1, c2, c3, ...]. But if stored as c1: [e1, e2, e3, ...]...
//                              ...                                                c2: [e1, e2, e3, ...]...
//                              ...for every iteration inside the update for each system fetching a single...
//                              ...row suffices, no need to fetch a new row for every new entity...
//                              ...dont change now but at some point, please do...
typedef std::unordered_map<Entity, ComponentPtr[MAX_COMPONENTS]> ECTable;

class Scene {
    std::vector<Entity> entities;
    std::string name;
    ECTable entity_component_table;

    void init();
    void on_pause();
    void on_resume();
    void on_update(float);
    void on_draw();
};

#endif
