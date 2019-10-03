//
// Created by Romain FOUYER on 2019-06-27.
//

#include "RFECSWrapper.hpp"

RFECSWrapper::RFECSWrapper()
: systemManager(rfecs::managers::SystemManager::getInstance()),
  entityManager(rfecs::managers::EntityManager::getInstance())
{

}