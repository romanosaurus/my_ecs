//
// Created by Romain FOUYER on 2019-06-26.
//

#ifndef TESTECS_COMPONENT_HPP
#define TESTECS_COMPONENT_HPP

#include "Entity.hpp"

namespace rfecs {

    namespace components {

        class Component {
        public:
            Component(entities::Entity &entity);
            virtual ~Component() {};

            entities::Entity &getEntity();

        private:
            entities::Entity &_entity;
        };

    }

}

#else

namespace rfecs {
    namespace components {
        class Component;
    }
}

#endif //TESTECS_COMPONENT_HPP
