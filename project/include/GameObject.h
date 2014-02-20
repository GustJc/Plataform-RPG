#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class Position;
class Renderer;
class GameObject;
class Animation;
class Collider;
class AudioSource;
class RigidBody;

#include <vector>
#include "Component.h"

namespace sf
{
    class RenderWindow;
}
class GameObject
{
    public:
        GameObject();
        virtual ~GameObject();

        void onEnable();
        void onDisable();

        void Update();
        void Render();

        //Adds component to object, gives error ir dependency not meet or already a component of concurrent type
        void addComponent(Component* component);
        //Returns Component of type T if it exists, else nullprt
        template<class T>
        T* getComponent();

        void setActive(bool state);

        sf::RenderWindow*   window;
    protected:
        // Component variables
        Position*       position    = nullptr; //The Position attached to the gameObject, null if not
        Renderer*       renderer    = nullptr; //The Renderer attached to the gameObject, null if not
        GameObject*     gameObject  = nullptr; //GameObject component is attached to
        Animation*      animation   = nullptr; //The animation attached to the component, null if not
        Collider*       collider    = nullptr; //The collider attached to the component, null if not
        AudioSource*    audio       = nullptr; //The audioSource attached to the component, null if not
        RigidBody*      rigidBody   = nullptr; //The rigidbody attached to the component, null if not
    private:
        bool m_isActive;
        std::vector<Component*> mComponentList;
};

#endif // GAMEOBJECT_H
