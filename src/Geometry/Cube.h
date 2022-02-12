#include <SFML/Graphics.hpp>

using namespace sf;

class Cube
{
    private :
        float _size;
        Vector3f _position;
    
    public :
        Cube(float size = 1);

        float GetSize() 
        {
            return _size;
        }
};

Cube::Cube(float size = 1) 
{
    _size = size;
}

Cube::~Cube() 
{

}