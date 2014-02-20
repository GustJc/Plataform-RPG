#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
class Position;
class Renderer;
class GameObject;
class Animation;
class Collider;
class AudioSource;
class RigidBody;

class Component
{
    public:
        Component();
        virtual ~Component();

        std::string getName();
        std::string getTagName();
        bool getTag(std::string tagName);


        virtual void onEnable();
        virtual void onDisable();
        virtual void onLoad();

        virtual void onUpdate();
        virtual void onRender();


// Component variables
        Position*       position    = nullptr; //The Position attached to the gameObject, null if not
        Renderer*       renderer    = nullptr; //The Renderer attached to the gameObject, null if not
        GameObject*     gameObject  = nullptr; //GameObject component is attached to
        Animation*      animation   = nullptr; //The animation attached to the component, null if not
        Collider*       collider    = nullptr; //The collider attached to the component, null if not
        AudioSource*    audio       = nullptr; //The audioSource attached to the component, null if not
        RigidBody*      rigidBody   = nullptr; //The rigidbody attached to the component, null if not
    protected:
        std::string m_componentName = "None";
        std::string m_tagName = "None";
};

#endif // COMPONENT_H
