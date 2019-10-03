//
// Created by Romain FOUYER on 2019-06-26.
//

#include "Component.hpp"

rfecs::components::Component::Component(rfecs::entities::Entity &entity)
: _entity(entity)
{}

rfecs::entities::Entity& rfecs::components::Component::getEntity()
{
    return _entity;
}