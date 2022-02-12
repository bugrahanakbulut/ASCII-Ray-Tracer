#include <cmath>
#include <limits>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector3.hpp>

#include "src/Extensions/VectorExtensions.h"
#include "src/Geometry/Sphere.h"
#include "src/Ray/RayHit.h"
#include "src/Ray/Ray.h"
#include "src/Scene/Camera.h"
#include "src/Scene/Scene.h"

using namespace std;

sf::Text * DrawLuminanceChar(sf::Font font, int x, int y, int lumIndex, sf::Color color)
{
    char luminanceChars[6] = ".*#o0";

    sf::Text * text = new sf::Text();
    text->setFont(font);
    text->setCharacterSize(12.5);
    text->setString(luminanceChars[lumIndex]);
    text->setFillColor(color);
    text->setPosition(x, y);

    return text;
}

int main()
{
    int screenWidth = 800;
    int screenHeight = 800;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "ASCII Ray Tracing");

    sf::Font font;
    font.loadFromFile("Sudo-Regular.ttf");

    Vector3f cameraPosition(0, 0, 0);
    Vector3f cameraDirection(0, 0, 1);

    Camera cam(cameraPosition, cameraDirection);

    Vector3f lightColor(1, 0, 0);
    // Vector3f lightDirection(-0.25, -1, -0.25);
    Vector3f lightDirection(-1, -1, -1);

    Sphere s(Vector3f(0, 0, 5), 2, Vector3f(1, 0, 0));

    float timePassed = 0;
    clock_t lastExecutedTime = clock();

    while (window.isOpen())
    {
        window.clear();

        lightDirection = Vector3f (cos(timePassed), -1, -1);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (int y = -screenHeight / 2; y <= screenHeight / 2; y+=10)
        {
            for (int x = -screenWidth / 2; x <= screenWidth / 2; x+=10)
            {
                Vector3f rayOrigin = cam.ScreenToWorldPosition(Vector2f(x, y), Vector2f(screenWidth, screenHeight));

                Ray ray(rayOrigin, cameraDirection);

                RayHit hit;

                hit = ray.SphereRayIntersection(s, hit);

                if (hit.Distance < numeric_limits<float>::max())
                {
                    Vector3f N = VectorExtensions::Normalize(hit.Normal);
                    Vector3f L = VectorExtensions::Normalize(lightDirection);
                    float lambert = max((float) 0, min((float) 1, VectorExtensions::Dot(N, L)));
                    Vector3f diffuseLight = lambert * lightColor;

                    Vector3f V = VectorExtensions::Normalize(cameraPosition - hit.Position);
                    Vector3f R = -L - 2.f * N * VectorExtensions::Dot(N, -L);
                    Vector3f H = VectorExtensions::Normalize(L + V);

                    float specularLight = max((float) 0, min((float) 1, VectorExtensions::Dot(H, N) * (lambert > 0)));
                    specularLight = pow(specularLight, 200);

                    hit.Albedo = Vector3f (
                            diffuseLight.x * s.GetAlbedo().x + specularLight,
                            diffuseLight.y * s.GetAlbedo().y + specularLight,
                            diffuseLight.z * s.GetAlbedo().z + specularLight);

                    sf::Uint8 r = 255 * hit.Albedo.x;
                    sf::Uint8 g = 255 * hit.Albedo.y;
                    sf::Uint8 b = 255 * hit.Albedo.z;

                    int charIndex = (int) (lambert * 4);

                    window.draw(*DrawLuminanceChar(font, x + (screenWidth / 2), y + (screenHeight / 2), charIndex, sf::Color(r, g, b)));
                }
                else
                {
                    window.draw(*DrawLuminanceChar(font, x + (screenWidth / 2), y + (screenHeight / 2), 1, sf::Color(0, 0, 255)));
                }
            }
        }

        float timeBetweenFrames = float(clock() - lastExecutedTime) / CLOCKS_PER_SEC;

        timePassed += timeBetweenFrames;

        lastExecutedTime = clock();

        cout << "Time Between Frames : " << timeBetweenFrames << endl;

        cout << "Avarage FPS : " << 1 / timeBetweenFrames << endl;

        window.display();
    }

    return 0;
}