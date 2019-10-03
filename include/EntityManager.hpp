//
// Created by Romain FOUYER on 2019-06-26.
//

#ifndef TESTECS_ENTITYMANAGER_HPP
#define TESTECS_ENTITYMANAGER_HPP

#include <unordered_map>
#include <functional>
#include <type_traits>

#include "Entity.hpp"

namespace rfecs {

    namespace managers {

        class EntityManager {
        public:
            static EntityManager &getInstance();
            ~EntityManager();

            entities::Entity *getEntityById(int id);
            entities::Entity *getEntityByName(const std::string &name);
            std::vector<entities::Entity *> getEntitiesByName(const std::string &name);

            void createEntity(const std::string &name);

            /*void entities::EntityManager::applyToEach(
                    typename std::common_type<std::function<void(EntityHandler, components::ComponentHandler<C>, components::ComponentHandler<Others>...)>>::type func, bool onlyEnabled)
            {*/

            template <typename C, typename... Other>
            void applyToEach(
                    typename std::common_type<std::function<void(entities::Entity *, C *, Other *...)>>::type func
                    )
            {
                for (auto &entity : _entities) {
                    if (entity.second->hasComponents<C, Other...>()) {
                        func(entity.second, entity.second->getComponent<C>(), entity.second->getComponent<Other>()...);
                    }
                }
            }

            EntityManager(const EntityManager &other) = delete;
            EntityManager(EntityManager &other) = delete;
        private:
            EntityManager();

        private:
            int _maxId;
            std::unordered_map<int, entities::Entity *> _entities;

        };
    }
}


#endif //TESTECS_ENTITYMANAGER_HPP
