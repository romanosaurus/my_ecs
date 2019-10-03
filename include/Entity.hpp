//
// Created by Romain FOUYER on 2019-06-26.
//

#ifndef RFECS_ENTITY_HPP
#define RFECS_ENTITY_HPP

#include <unordered_map>
#include <typeindex>
#include <string>
#include <iostream>

#include "Component.hpp"

namespace rfecs {

    namespace entities {

        class Entity {
        public:
            Entity(unsigned int id, const std::string &name);
            ~Entity() {};

            template <typename C, typename... Args>
            void assignComponent(Args... arguments)
            {
                auto comp = new C(*this, arguments...);

                _components.insert(std::make_pair(std::type_index(typeid(C)), comp));
            }

            template <typename Comp>
            Comp *getComponent()
            {
                for (auto &it : _components) {
                    if (std::type_index(typeid(Comp)) == it.first) {
                        return reinterpret_cast<Comp *>(it.second);
                    }
                }
                return nullptr;
            }

            template <typename C>
            bool hasComponent() const
            {
                for (auto &it : _components)
                    if (std::type_index(typeid(C)) == it.first)
                        return true;
                return false;
            }

            template <typename C>
            bool hasComponents() const
            {
                for (auto &it : _components)
                    if (std::type_index(typeid(C)) == it.first)
                        return true;
                return false;
            }

            template <typename C, typename D, typename... O>
            bool hasComponents() const
            {
                return hasComponent<C>() && hasComponents<D, O...>();
            }

            const unsigned int &getId() const;
            const std::string &getName() const;
        protected:
            unsigned int _id;
            std::string _name;

            std::unordered_map<std::type_index, components::Component *> _components;
        };

    }

}

#else

namespace rfecs {
    namespace entities {
        class Entity;
    }
}


#endif //RFECS_ENTITY_HPP
