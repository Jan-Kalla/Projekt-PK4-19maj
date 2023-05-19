#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H
#include "Character.h"
class PlayerCharacter :
    public Character
{
private:
    //Zmienne

    //Funkcje inicjalizuj¹ce
    void OpenVariables();
    void OpenComponents();
public:
    PlayerCharacter(float x, float y, sf::Texture& texture_sheet);
    ~PlayerCharacter();
    //Metody
    virtual void update(const float& time);
};
#endif
