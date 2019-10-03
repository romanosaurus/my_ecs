//
// Created by Romain FOUYER on 2019-06-26.
//

#include "../include/Entity.hpp"

rfecs::entities::Entity::Entity(unsigned int id, const std::string &name)
: _id(id), _name(name)
{
}

const unsigned int &rfecs::entities::Entity::getId() const
{
    return _id;
}

const std::string & rfecs::entities::Entity::getName() const
{
    return _name;
}