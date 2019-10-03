//
// Created by Romain FOUYER on 2019-06-26.
//

#include "System.hpp"

rfecs::systems::System::System(const std::string &name)
: _name(name), _state(STOPPED)
{
}

const std::string& rfecs::systems::System::getName() const
{
    return _name;
}

rfecs::systems::SyState rfecs::systems::System::getState() const
{
    return _state;
}

void rfecs::systems::System::setState(rfecs::systems::SyState newState)
{
    _state = newState;
}