//
// Created by Romain FOUYER on 2019-06-26.
//

#include "SystemManager.hpp"

rfecs::managers::SystemManager &rfecs::managers::SystemManager::getInstance()
{
    static rfecs::managers::SystemManager sm;

    return sm;
}

rfecs::managers::SystemManager::SystemManager()
: _timeScale(1), _last(std::chrono::steady_clock::now())
{
}

rfecs::managers::SystemManager::~SystemManager()
{
    for (auto &it : _systems)
        delete it.second;
}

void rfecs::managers::SystemManager::runningTime()
{
    auto now = std::chrono::steady_clock::now();
    std::chrono::nanoseconds elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>((now - _last) * _timeScale);

    for (auto &it : _systems) {
        if (it.second->getState() == rfecs::systems::STARTED)
            it.second->onUpdate(elapsedTime.count());
    }
    _last = now;
}

float rfecs::managers::SystemManager::getTimeScale() const
{
    return _timeScale;
}

void rfecs::managers::SystemManager::setTimeScale(float newTimeScale)
{
    _timeScale = newTimeScale;
}