#include "Ennemies.hpp"

/*static const sf::Color ghost_color = sf::Color::Red;
static const float ghost_speed = 60.f;
static const float ghost_radius = 16.f;
*/
Ennemies::Ennemies() {

}

/*void Ennemies::initializationEnnemy(Ennemies &ennemies, const sf::Vector2f &position)
{
    ennemies.direction = Direction::NONE;
    ennemies.shape.setRadius(ghost_radius);
    ennemies.shape.setFillColor(ghost_color);
    ennemies.shape.setPosition(position);
}

void Ennemies::changeEnemyDirection(Ennemies &ennemies)
{
    switch (ennemies.direction)
    {
        case Direction::UP:
            ennemies.direction = Direction::DOWN;
            break;
        case Direction::DOWN:
            ennemies.direction = Direction::LEFT;
            break;
        case Direction::LEFT:
            ennemies.direction = Direction::RIGHT;
            break;
        case Direction::RIGHT:
            ennemies.direction = Direction::NONE;
            break;
        case Direction::NONE:
            ennemies.direction = Direction::UP;
            break;
    }
}

void Ennemies::moveEnnemy(Ennemies &ennemies, float time)
{
    const float status = ghost_speed * time;

    sf::Vector2f movement(0.f, 0.f);
    switch (ennemies.direction)
    {
        case Direction::UP:
            movement.y -= status;
            break;
        case Direction::DOWN:
            movement.y += status;
            break;
        case Direction::LEFT:
            movement.x -= status;
            break;
        case Direction::RIGHT:
            movement.x += status;
            break;
        case Direction::NONE:
            changeEnemyDirection(ennemies);
            break;
    }
    const sf::FloatRect ghostBounds = ennemies.shape.getGlobalBounds();
    if (mur(mur, ghostBounds, movement))
     {
         changeEnemyDirection(ennemies);
     }
     ennemies.shape.move(movement);
}*/

Ennemies::~Ennemies() {

}
