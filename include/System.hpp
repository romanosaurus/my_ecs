//
// Created by Romain FOUYER on 2019-06-26.
//

#ifndef TESTECS_SYSTEM_HPP
#define TESTECS_SYSTEM_HPP

#include <string>

namespace rfecs {

    namespace systems {

        enum SyState
        {
            STARTED,
            STOPPED
        };

        class System {
        public:
            explicit System(const std::string &name);
            virtual ~System() = default;

            virtual void onInit() = 0;
            virtual void onUpdate(float elapsedTime) = 0;
            virtual void onClose() = 0;

            const std::string &getName() const;

            SyState getState() const;
            void setState(SyState newState);

        protected:
            std::string _name;
            SyState _state;
        };

    }

}


#endif //TESTECS_SYSTEM_HPP
