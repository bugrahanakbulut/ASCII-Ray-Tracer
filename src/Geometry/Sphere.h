#include <SFML/Graphics.hpp>
using namespace sf;

class Sphere 
{
    private :
        float _radius;
        Vector3f _position;
        Vector3f _albedo;

    public :
        Sphere(Vector3f position, float radius = 1, Vector3f albedo = Vector3f(1, 1, 1))
        {
            _radius = radius;
            _position = position;
            _albedo = albedo;
        }

        ~Sphere() 
        {

        }

        Vector3f GetPosition() 
        {
            return _position;
        }

        Vector3f GetAlbedo()
        {
            return _albedo;
        }

        float GetRadius() 
        {
            return _radius;
        }
};