#include "renderController.h"


Camera::Camera(Vector position, Vector angls, CameraConfig conf)
{
    this->position = position;
    this->angles = angls;
    this->config = conf;
};

void Camera::rotate(Vector rotationAngles)
{
    angles.rotate(rotationAngles.x, rotationAngles.y, rotationAngles.x);
}

void Camera::move(Vector newPosition)
{
    position.sub(newPosition);
};

void Camera::moveTo(Vector newPosition)
{
    this->position = newPosition;
};

RenderController::RenderController(Camera camera, RenderConfig conf)
{
    this->camera = camera;
    this->config = conf;
};

void RenderController::setObject(BaseObjectInterface &obj){
    objects.push_front(&obj);
}

Vector RenderController::rayMarching(Ray ray)
{
    return Vector(0, 0, 0);
}

Ray RenderController::rayMarchingStep(Ray ray)
{
    return Ray(Vector(), Vector());
}

void RenderController::run()
{
    sf::RenderWindow window(sf::VideoMode(config.WinWidth, config.WinHeight), "Render!");
    sf::RectangleShape figure(sf::Vector2f(120, 50));
    figure.setPosition(250.f, 250.f);
    figure.setFillColor(sf::Color::Green);

    CameraConfig cnf = camera.config;
    double pixelSizeX = cnf.ViewingAngleX / cnf.resolutionX;
    double pixelSizeY = cnf.ViewingAngleY / cnf.resolutionY;
    for(double i=-cnf.ViewingAngleX/2; i<cnf.ViewingAngleX/2; i = i + pixelSizeX)
    {
        for(double j=-cnf.ViewingAngleY/2; j<cnf.ViewingAngleY/2; j = j + pixelSizeY)
        {
            //printf("i = %f\n", i);
            //printf("j = %f\n", j);
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(figure);
        window.display();

        return;
    }
};