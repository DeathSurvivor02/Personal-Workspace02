// WordApp.h
#ifndef WORDAPP_H
#define WORDAPP_H


#include "Letter.h"  

class WordApp {
private:
    std::vector<Letter> theword;

public:
    WordApp(std::string word);

    void hide(char character);

    void display();

    bool isWordGuessed();

    int getRemainingGuesses();
};

#endif
