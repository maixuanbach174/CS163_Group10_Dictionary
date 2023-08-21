#include "QuizScreen.hpp"

QuizScreen::QuizScreen() 
: nextButton(70, 50, 200, 175)
{
    titleBar.lineshape.setSize(sf::Vector2f(1450.f, 15.f));
    titleBar.titleShape.setSize(sf::Vector2f(1450.f, 100.f));
    titleBar.titleShape.setFillColor(sf::Color(225, 185, 0, 255));
    titleBar.lineshape.setFillColor(sf::Color(134, 84, 6, 255));
    titleBar.titleShape.setPosition(sf::Vector2f(100.f, 0.f));
    titleBar.lineshape.setPosition(sf::Vector2f(100.f, 100.f));
    titleBar.titleFont.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/menuFont.ttf");
    titleBar.titleText.setFont(titleBar.titleFont);
    titleBar.titleText.setString("Quiz");
    titleBar.titleText.setCharacterSize(40);
    titleBar.titleText.setFillColor(sf::Color::White);
    titleBar.titleText.setPosition(sf::Vector2f(250.f, 25.f));
    titleBar.isMove = false;

    answerBox = new sf::RectangleShape[4];
    answerText = new sf::Text[4];
    answerFont.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/arial.ttf");
    for(int i = 0; i < 4; i++)
    {
        answerBox[i].setSize(sf::Vector2f(550.f, 200.f));
        answerText[i].setFont(answerFont);
        answerText[i].setCharacterSize(30);
        answerText[i].setFillColor(sf::Color::White);
    }

    answerBox[0].setPosition(sf::Vector2f(200.f, 400.f));
    answerText[0].setPosition(sf::Vector2f(250.f, 430.f));
    answerBox[0].setFillColor(sf::Color(100, 100, 255, 255));
    answerBox[1].setPosition(sf::Vector2f(850.f, 400.f));
    answerText[1].setPosition(sf::Vector2f(900.f, 430.f));
    answerBox[1].setFillColor(sf::Color(8, 143, 143, 255));
    answerBox[2].setPosition(sf::Vector2f(200.f, 700.f));
    answerBox[2].setFillColor(sf::Color(225, 185, 0, 255));
    answerText[2].setPosition(sf::Vector2f(250.f, 730.f));
    answerBox[3].setPosition(sf::Vector2f(850.f, 700.f));
    answerBox[3].setFillColor(sf::Color(255,114,118,255));
    answerText[3].setPosition(sf::Vector2f(900.f, 730.f));
    questionText.setFont(answerFont);
    questionText.setCharacterSize(30);
    questionText.setFillColor(sf::Color::White);
    questionText.setPosition(sf::Vector2f(200.f, 250.f));
    nextTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/RightIcon.png");
    nextIcon.setTexture(nextTexture);
    nextIcon.setPosition(sf::Vector2f(200.f, 165.f));
    
}

QuizScreen::~QuizScreen() {
    delete[] answerBox;
    delete[] answerText;
}

void QuizScreen::processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input)
{
    sf::Event event;
    while(App.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            App.close();
            break;
        case sf::Event::KeyReleased:
            mainmenu.HandleUserInput(event.key.code, App);
            break;
        case sf::Event::GainedFocus:
            mainmenu.mIsPaused = false;
            break;
        case sf::Event::LostFocus : 
            mainmenu.mIsPaused = true;
            break;
        case sf::Event::MouseMoved :
            mainmenu.HandleMenuColor(App);
            HandleNextColor(App);
            break;
        case sf::Event::MouseButtonPressed : 
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousepos = sf::Mouse::getPosition(App);
                mainmenu.HandleMenuClick(mousepos);
                int tmp = handleAnswerBoxClick(mousepos);
                if(tmp != -1)
                {
                    handleAnswerBox();
                }
                HandleNextClick(mousepos);
            }
            break;
        default:
            break;
        }
    }
}

void QuizScreen::update(MainMenu& mainmenu, vector<vector<wstring>*>& passedContent)
{
    if(isNext)
    {
        resetAnswerBox();\
        wstring question;
        if(index == 0)
            question = L"Which of the following is the meaning of " + random[0] + L" ?";
        else
            question = L"Which of the following means: \"" + random[0] + L"\" ?";
        questionText.setString(question);
        for(int i = 0; i < 4; ++i)
        {
            answerText[i].setString(random[i + 1]);
        }
        isNext = false;

        wrapText(questionText, 1400.f);
        for(int i = 0; i < 4; ++i)
        {
            wrapText(answerText[i], answerBox[i].getGlobalBounds().width - 10.f);
        }
    }

    if(mainmenu.openedMenu != titleBar.isMove)
    {
        if(mainmenu.openedMenu)
        {
            titleBar.Move(mainmenu.movement);
            for(int i = 0; i < 4; ++i)
            {
                answerBox[i].move(mainmenu.movement);
                answerText[i].move(mainmenu.movement);
            }
            questionText.move(mainmenu.movement);
            nextButton.rect.move(mainmenu.movement);
            nextIcon.move(mainmenu.movement);
            nextButton.position += mainmenu.movement;
        } else
        {
            titleBar.Move(-1.f * mainmenu.movement);
            for(int i = 0; i < 4; ++i)
            {
                answerBox[i].move(-1.f * mainmenu.movement);
                answerText[i].move(-1.f * mainmenu.movement);
            }
            questionText.move(-1.f * mainmenu.movement);
            nextButton.rect.move(-1.f * mainmenu.movement);
            nextIcon.move(-1.f * mainmenu.movement);
            nextButton.position -= mainmenu.movement;
        }

        titleBar.isMove = mainmenu.openedMenu;
    }
}

void QuizScreen::render(sf::RenderWindow& App)
{
    App.draw(titleBar.titleShape);
    App.draw(titleBar.titleText);
    App.draw(titleBar.lineshape);
    App.draw(questionText);
    App.draw(nextButton.rect);
    App.draw(nextIcon);
    for(int i = 0; i < 4; i++)
    {
        App.draw(answerBox[i]);
        App.draw(answerText[i]);
    }
}

void QuizScreen::handleAnswerBox()
{
    answerBox[correct].setFillColor(sf::Color::Green);
    for(int i = 0; i < 4; ++i)
    {
        if(i != correct)
        {
            answerBox[i].setFillColor(sf::Color::Red);
        }
    }
}

void QuizScreen::resetAnswerBox()
{
    answerBox[0].setFillColor(sf::Color(100, 100, 255, 255));
    answerBox[1].setFillColor(sf::Color(8, 143, 143, 255));
    answerBox[2].setFillColor(sf::Color(225, 185, 0, 255));
    answerBox[3].setFillColor(sf::Color(255,114,118,255));
}

int QuizScreen::handleAnswerBoxClick(sf::Vector2i mousePos)
{
    for(int i = 0; i < 4; ++i)
    {
        if(answerBox[i].getGlobalBounds().contains(mousePos.x, mousePos.y))
        {
            return i;
        }
    }

    return -1;
}

void QuizScreen::HandleNextColor(sf::RenderWindow& App)
{
    sf::Vector2i mousepos= sf::Mouse::getPosition(App);

    if(nextButton.isInBound(mousepos))
    {
        nextButton.rect.setFillColor(sf::Color(50, 50, 100, 255));
    } else nextButton.rect.setFillColor(sf::Color::Transparent);
}

void QuizScreen::HandleNextClick(sf::Vector2i mousepos)
{
    if(nextButton.isInBound(mousepos))
    {
        nextButton.rect.setFillColor(sf::Color::Transparent);
        isNext = true;
    }
}

void QuizScreen::wrapText(sf::Text& text, float maxWidth)
{
    wstring line;
    wstring wrappedText;
    wstring textString = text.getString();
    for(wchar_t c : textString)
    {
        sf::Text temp; 
        temp.setFont(answerFont);  
        temp.setCharacterSize(40);
        temp.setString(line + c);
        if(temp.getGlobalBounds().width > maxWidth)
        {
            wrappedText += line + L'-' + L'\n';
            line = c;
        } else
        {
            line += c;
        }
    }
    wrappedText += line;
    text.setString(wrappedText);
}


