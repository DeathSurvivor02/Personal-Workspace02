#include <iostream>
#include "WordApp.h"
#include "Letter.h"  

using namespace std;

WordApp::WordApp(std::string word) {
    for (char c : word) {
        Letter L(c);
        theword.push_back(L);
    }
}

void WordApp::hide(char character) {
    for (Letter &l : theword) {
        if (l.value == character) {
            l.visible = false;
        }
    }
}

void WordApp::display() {
    for (Letter l : theword) {
        char v = (l.visible) ? l.value : '-';
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

bool WordApp::isWordGuessed() {
    for (const Letter &l : theword) {
        if (l.visible) {
            return false;
        }
    }
    return true;
}

int WordApp::getRemainingGuesses() {
    int remainingGuesses = 0;
    for (const Letter &l : theword) {
        if (l.visible) {
            remainingGuesses++;
        }
    }
    return remainingGuesses;
}