using namespace sf;

class Sphere : public Geometry
{
    private :
        float _radius;
        Vector3f _position;
        Vector3f _albedo;

    public :
        Sphere(Vector3f position, float radius, Vector3f albedo = Vector3f(1, 1, 1))
        {
            _radius = radius;
            _position = position;
            _albedo = albedo;
        }

        ~Sphere() 
        {

        }

        Vector3f GetPosition() override
        {
            return _position;
        }

        void SetPosition(Vector3f pos) override
        {
            _position = pos;
        }

        Vector3f GetAlbedo()
        {
            return _albedo;
        }

        float GetRadius() 
        {
            return _radius;
        }

        RayHit CheckGeometryRayIntersection(Ray ray) override;
};

RayHit Sphere::CheckGeometryRayIntersection(Ray ray)
{
    RayHit hit;

    Vector3f distance = ray.GetOrigin() - GetPosition();

    float p1 = -1 * VectorExtensions::Dot(ray.GetDirection(), distance);
    float p2sqr = pow(p1, 2) - VectorExtensions::Dot(distance, distance) + pow(GetRadius(), 2);

    if (p2sqr < 0)
    {
        return hit;
    }

    float p2 = sqrt(p2sqr);
    float t = p1 - p2 > 0 ? p1 - p2 : p1 + p2;

    if (t > 0 && t < hit.Distance)
    {
        hit.Distance = t;
        hit.Position = ray.GetOrigin() + t * ray.GetDirection();
        hit.Normal = VectorExtensions::Normalize(hit.Position - GetPosition());
        hit.Albedo = GetAlbedo();
    }

    return hit;
}