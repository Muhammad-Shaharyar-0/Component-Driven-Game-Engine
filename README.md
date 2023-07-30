# Games Architecture - Lab H - DDM

This week you will learn how to use Systems with the Entity-Component-System architecture.
You will also implement a Resource Manager.

---

## Task 1 - [Not required in lab book]
1. Open up the code and take a look around
2. Make changes to the code so that the `PhysicsSystem` either has `position` as well as the current data of `velocity` and `max speed`, or implement separate components for `position` and `velocity`
    - Remember to take the `Vector4 position` out of `GameObject` and you will need to add a mechanism for other parts of the code to retrieve the GameObject’s position
    - You may find that having a sperate `PositionComponent` (and separate `VelocityComponent`) is useful as this could be added to each `GameObject` as a direct replacement for removing the `Vector4 position` from `GameObject`


---

## Task 2 - [Not required in lab book]
1. Currently the `Game` stores a list of meshes
2. Create a `ResourceManager` in the Asteroid Engine to store things like this instead
    - It should cache resources if they have already been loaded, so that we don't get duplicates
    - Use a `std::map` (or similar) using the filename or name as a key (first) and use the resource pointer/reference as the value (second)


---
