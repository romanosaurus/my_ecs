# RFECS

My Entity Component System

## What is an Entity Component System ?

An ECS is a game development project architecture, where **Components** are object
with data in iit.

For example a Transform component where the player position/rotation/scale are stocked.

An **Entity** is an object who has one or many composants

For example a Player Entity who has the Transform Component and an Attribute Components

All those components are managed by **Systems**, who apply logic on them.
