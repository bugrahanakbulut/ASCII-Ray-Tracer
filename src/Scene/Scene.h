using namespace std;

class Scene
{
    private:
        vector<Geometry *> _sceneGeometries;
    public:
        Camera Camera;

        void InitScene();

        void UpdateScene(float timePassed);

        RayHit TraceRay(Ray ray);
};

void Scene::InitScene()
{
    Sphere *s = (Sphere *) malloc(sizeof (Sphere));

    s = new Sphere(Vector3f(0, 0, 5), 1.25, Vector3f(1, 1, 1));

    _sceneGeometries.push_back(s);
}

RayHit Scene::TraceRay(Ray ray)
{
    RayHit hit;

    for(Geometry * geom : _sceneGeometries)
    {
        RayHit curHit = geom->CheckGeometryRayIntersection(ray);

        if (curHit.Distance < hit.Distance)
        {
            hit = curHit;
        }
    }

    return hit;
}

void Scene::UpdateScene(float timePassed)
{
    float pos = cos(timePassed);

    for(Geometry * geom : _sceneGeometries)
    {
        Vector3f curPos = geom->GetPosition();

        geom->SetPosition(Vector3f(curPos.x, pos, curPos.z));
    }
}