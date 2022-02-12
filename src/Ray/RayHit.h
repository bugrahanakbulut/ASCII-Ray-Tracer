using namespace sf;
using namespace std;

class RayHit
{
    public :
        RayHit();

        Vector3f Position;
        Vector3f Normal;
        Vector3f Albedo;
        float Distance;
};

RayHit::RayHit()
{
    Albedo = Vector3f(0, 0, 0);
    Distance = numeric_limits<float>::max();
    Normal = Vector3f (0, 0, 0);
    Albedo = Vector3f(0, 0, 0);
}
