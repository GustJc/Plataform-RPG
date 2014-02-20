Plataform-RPG
=============

Plataform Game and Engine


##Installation and Support

This project is not yet ready for easy installation and multi-plataform support.

It can in theory be used on linux or mac as it uses SFML for its API, but none of it is tested or adapted yet.

The repository contains the .dll files of SFML and a CodeBlocks Project, but to make it work you'll need to need to link it yourself agains: 
```
-lsfml-main
-lsfml-system
-lsfml-graphics
-lsfml-window
-lsfml-audio
```

##Architecture and Components

The game engine is based of components structure such as a GameObject can contains several components that will add functionality for its behavior.

The components added have a basic TagName with will tell where in the GameObject code it'll execute it's function. That way a component with a tag "Render" will execute its onRender() code along with the gameObjects its associated with.

Every component have a reference of its parent GameObject name gameObject. 

Some components --are-- will be restricted such as a GameObject will only be allowed to have one of that type. Like a Physics Engine rigidBody or a main Renderer component. 

The Components are structured in a way that will all have null references to other components in its base class.
If a component does not uses its base class references, it just stays null (testing, may be removed as it already has access to gameobject and can self-register its elements)

The GameObject will have references for its main components objects which will be null if a component using that type is not present. The Components objects can be such as:
  * Position (Holds a position, rotation and deslocation of anchor of gameObject)
  * Renderer   (Render object in screen, can be textured and --depends-- will depend on Position)
    * ShaderRender (Render an Object using a shader which can be parameterized
  * Collider (Holds a collider and tells if it has collided with other objects collider)
  * RigidBody (Add Physics to a GameObject, may require a collider for certain actions)
  * Others
  
The Component can access several hotstops of a GameObject, such as:
  * onRender
  * onUpdate
  * onDisable
  * onEnable
  * Others
