#ifndef QUIZSCREEN_HPP
#define QUIZSCREEN_HPP

#include <SFML/Graphics.hpp>
#include "cscreen.hpp"
using namespace std;

class QuizScreen : public cscreen
{
private:
   
public:
    QuizScreen();
    ~QuizScreen();
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input);
    virtual void update(MainMenu& mainmenu, wstring& passedContent);
    virtual void render(sf::RenderWindow& App);
};


#endif