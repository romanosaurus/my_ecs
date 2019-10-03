//
// Created by Romain FOUYER on 2019-06-26.
//

#include "EntityManager.hpp"

#include <vector>
#include <iostream>

rfecs::managers::EntityManager &rfecs::managers::EntityManager::getInstance()
{
    static rfecs::managers::EntityManager em;

    return em;
}

rfecs::managers::EntityManager::EntityManager()
        : _maxId(0)
{}

rfecs::managers::EntityManager::~EntityManager()
{
    for (auto &it : _entities)
        delete it.second;
}

rfecs::entities::Entity *rfecs::managers::EntityManager::getEntityById(int id)
{
    return _entities.at(id);
}

rfecs::entities::Entity *rfecs::managers::EntityManager::getEntityByName(const std::string &name)
{
    for (auto &it : _entities) {
        if (it.second->getName() == name)
            return it.second;
    }
    return nullptr;
}

std::vector<rfecs::entities::Entity *> rfecs::managers::EntityManager::getEntitiesByName(const std::string &name)
{
    std::vector<rfecs::entities::Entity *> fetchEntities;

    for (auto &it : _entities)
        if (it.second->getName() == name)
            fetchEntities.push_back(it.second);

    return fetchEntities;
}

void rfecs::managers::EntityManager::createEntity(const std::string &name)
{
    auto *newEntity = new rfecs::entities::Entity(_maxId, name);

    _entities.insert(std::make_pair(_maxId, newEntity));
    _maxId++;
    std::cout << "Entity : " << name << " created" << std::endl;
}