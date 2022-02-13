#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Ray 
{
    private :
        Vector3f _origin;
        Vector3f _direction;

    public :
        Ray(Vector3f origin, Vector3f direction) 
        {
            _origin = origin;
            _direction = direction;
        }

        Vector3f GetOrigin() 
        {
            return _origin;
        }

        Vector3f GetDirection() 
        {
            return _direction;
        }

        // RayHit SphereRayIntersection(Sphere sphere, RayHit hit);
};


/*
RayHit Ray::SphereRayIntersection(Sphere sphere, RayHit hit)
{
    Vector3f distance = _origin - sphere.GetPosition();

    float p1 = -1 * VectorExtensions::Dot(_direction, distance);
    float p2sqr = pow(p1, 2) - VectorExtensions::Dot(distance, distance) + pow(sphere.GetRadius(), 2);

    if (p2sqr < 0)
    {
        return hit;
    }

    float p2 = sqrt(p2sqr);
    float t = p1 - p2 > 0 ? p1 - p2 : p1 + p2;

    RayHit curHit;

    if (t > 0 && t < hit.Distance)
    {
        curHit.Distance = t;
        curHit.Position = _origin + t * _direction;
        curHit.Normal = VectorExtensions::Normalize(curHit.Position - sphere.GetPosition());
        curHit.Albedo = sphere.GetAlbedo();
    }

    return curHit;
}*/
