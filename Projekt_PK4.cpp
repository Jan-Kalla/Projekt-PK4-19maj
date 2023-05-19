// Projekt_PK4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
//#include <windows.h> - Tu jest błąd "Rect.inl"
#include  <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <vector>
//#include <locale.h>
#include "Game.h"

int main()
{
    //setlocale(LC_CTYPE, "Polish");
    //std::cout << "żółć";
    // Zwierze z1;
   //z1.dodaj_zwierze();
   //z1.glos();
   //farmer(z1);
   //PlayerCharacter p("Yisgrammor", "brak", 84, 200,100,300);
   //Character* point;
   //point = &p;
   //point->view();
    Game game;
    game.run();

    
    return 0;
}