//
// Created by Romain FOUYER on 2019-06-27.
//

#ifndef TESTECS_RFECSWRAPPER_HPP
#define TESTECS_RFECSWRAPPER_HPP

#include "SystemManager.hpp"
#include "EntityManager.hpp"

struct RFECSWrapper
{
    RFECSWrapper();

    rfecs::managers::SystemManager &systemManager;
    rfecs::managers::EntityManager &entityManager;
};

#endif //TESTECS_RFECSWRAPPER_HPP
