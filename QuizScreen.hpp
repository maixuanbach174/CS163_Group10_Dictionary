#ifndef QUIZSCREEN_HPP
#define QUIZSCREEN_HPP

#include <SFML/Graphics.hpp>
#include "cscreen.hpp"
#include "TitleBar.hpp"
#include <vector>
#include <thread>
#include <chrono>
#include "Button.h"
using namespace std;

class QuizScreen : public cscreen
{
public:
    int index = 0;
    int correct = 0;
    vector<wstring>  random;
    void resetAnswerBox();
    bool isNext = true;
private:
    Button nextButton;
    TitleBar titleBar;
    sf::RectangleShape * answerBox = nullptr;
    sf::Text * answerText = nullptr;
    sf::Sprite nextIcon;
    sf::Text questionText;
    sf::Texture nextTexture;
    sf::Font answerFont;
public:
    QuizScreen();
    ~QuizScreen();
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input);
    virtual void update(MainMenu& mainmenu, vector<vector<wstring>*>& passedContent);
    virtual void render(sf::RenderWindow& App);
    void handleAnswerBox();
    int handleAnswerBoxClick(sf::Vector2i mousePos);
    void HandleNextColor(sf::RenderWindow& App);
    void HandleNextClick(sf::Vector2i mousepos);
    void wrapText(sf::Text& text, float maxWidth);
};


#endif