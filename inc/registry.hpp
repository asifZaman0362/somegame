#ifndef REGISTRY_HPP
#define REGISTRY_HPP

template <typename T>
class ComponentRegistry {
   public:
    static int GetId();
    static int counter;
};

#endif
