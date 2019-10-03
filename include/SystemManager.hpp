//
// Created by Romain FOUYER on 2019-06-26.
//

#ifndef TESTECS_SYSTEMMANAGER_HPP
#define TESTECS_SYSTEMMANAGER_HPP

#include "System.hpp"

#include <typeindex>
#include <unordered_map>
#include <chrono>

namespace rfecs {

    namespace managers {

        class SystemManager {
        public:
            static SystemManager &getInstance();
            ~SystemManager();

            template <typename Syst>
            Syst *getSystem()
            {
                for (auto &it : _systems) {
                    if (it.first == std::type_index(typeid(Syst)))
                        return reinterpret_cast<Syst *>(it.second);
                }
                return nullptr;
            }

            template <typename Syst, typename... Args>
            void newSystem(Args... arguments)
            {
                auto newSystem = new Syst(arguments...);

                _systems.insert(std::make_pair(std::type_index(typeid(Syst)), newSystem));
            }

            template <typename Syst>
            void startSystem()
            {
                for (auto &it : _systems) {
                    if (it.first == std::type_index(typeid(Syst))) {
                        it.second->onInit();
                        it.second->setState(rfecs::systems::STARTED);
                    }
                }
            }

            template <typename Syst>
            void stopSystem()
            {
                for (auto &it : _systems) {
                    if (it.first == std::type_index(typeid(Syst))) {
                        it.second->onClose();
                        it.second->setState(rfecs::systems::STOPPED);
                    }
                }
            }

            void runningTime();

            float getTimeScale() const;
            void setTimeScale(float newTimeScale);

            SystemManager(const SystemManager &other) = delete;
            SystemManager(SystemManager &other) = delete;
        private:
            SystemManager();
        private:
            std::unordered_map<std::type_index, systems::System *> _systems;
            float _timeScale;
            std::chrono::steady_clock::time_point _last;
        };

    }

}


#endif //TESTECS_SYSTEMMANAGER_HPP
