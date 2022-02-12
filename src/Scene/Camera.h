class Camera
{
private :

public :
    Camera(Vector3f position, Vector3f rotation)
    {
        Position = position;
        Rotation = rotation;

        ViewportSize = Vector2f(10, 10);
        NearClipping = 0.01;
        FarClipping = 25;
    }

    ~Camera()
    {

    }

    Vector3f ScreenToWorldPosition(Vector2f screenPos, Vector2f screenSize);

    Vector3f Position;
    Vector3f Rotation;
    Vector2f ViewportSize;
    float NearClipping;
    float FarClipping;
};

Vector3f Camera::ScreenToWorldPosition(Vector2f screenPos, Vector2f screenSize)
{
    // inverse projection of orthogonal according to the camera
    float left = Position.x - ViewportSize.x / 2;
    float right = Position.x + ViewportSize.x / 2;
    float top = Position.y + ViewportSize.y / 2;
    float bottom = Position.y - ViewportSize.y / 2;

    Vector2f normalizedScreenCoord(((float) screenPos.x) / (screenSize.x / 2), (float ) screenPos.y / (screenSize.y / 2));

    float rayOriginX = normalizedScreenCoord.x * (right - left) / 2;
    float rayOriginY = normalizedScreenCoord.y * (top - bottom) / 2;

    return Vector3f(rayOriginX, rayOriginY, Position.z);
}
