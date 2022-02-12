#include <SFML/System/Vector3.hpp>
#include <cmath>

using namespace sf;

class VectorExtensions
{
    public :
        static float Magnitude(Vector3f vector)
        {
            return pow(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2), 0.5);
        }

        static Vector3f Normalize(Vector3f vector)
        {
            float mag = Magnitude(vector);

            return Vector3f(vector.x / mag, vector.y / mag, vector.z / mag);
        }

        static float Dot(Vector3f v1, Vector3f v2)
        {
            return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
        }
};
