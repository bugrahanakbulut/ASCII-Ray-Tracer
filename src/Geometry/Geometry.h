class Geometry
{
    public :
        virtual RayHit CheckGeometryRayIntersection(Ray ray) = 0;

        virtual Vector3f GetPosition() = 0;

        virtual void SetPosition(Vector3f position) = 0;
};