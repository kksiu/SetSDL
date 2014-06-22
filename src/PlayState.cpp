//
//  PlayState.cpp
//  SetSDL
//
//  Created by Kenneth Siu on 5/31/14.
//
//

#include "PlayState.h"
#include "Constants.h"
#include "Game.h"
#include "Enums.h"
#include "InputHandler.h"
#include <sstream>
#include <string>
#include <cstdlib>

const std::string PlayState::s_menuID = "PLAY";
int CARD_WIDTH = 140;
int CARD_HEIGHT = 90;
int WIDTH_PADDING = 50;
int HEIGHT_PADDING = 50;

//split string methods
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}


void PlayState::update() {
    
    std::vector<CardObject*> selectedCards;
    
	for (size_t i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
        
        //check if it has been selected
        CardObject *card = (CardObject*)m_gameObjects[i];
        if(card->getSelected()) {
            selectedCards.push_back(card);
        }
	}
    
    //check to see if there are at least 3 cards that have been selected
    if(selectedCards.size() >= 3) {
        //check to see if the cards are a set
        bool isSet = PlayState::checkSet(selectedCards);
        
        // TODO what to do when there is a set!
        if(isSet) {
        }
        
        //set selected cards back to not selected
        for(size_t i = 0; i < selectedCards.size(); i++) {
            selectedCards[i]->setSelected(false);
        }
    }
    
    //remove vector
    selectedCards.clear();
}

void PlayState::render() {
    //render all the objects
    for(size_t i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

bool PlayState::onEnter() {
    
    //load all the cards
    PlayState::loadCards();
    std::cout << "Done Loading Cards" << std::endl;
    
    //load random group of cards into the game (4 x 3)
    PlayState::loadRandomInitialCards();
    
    
    std::cout << "Entering Play State" << std::endl;
    return true;
}


bool PlayState::onExit() {
    //remove all the cards (using the onExit)
    for(size_t i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
    }
    
    m_gameObjects.clear();
    
    removeTextures();
    
    std::cout << "Exiting Play State" << std::endl;
    return true;
}

bool PlayState::loadCards() {
    //have to load all images
    for(const std::string* p = &images[0]; p != &images[81]; ++p) {
        if(!TextureManager::Instance()->load(*p, *p, Game::Instance()->getRenderer())) {
            std::cout << "FAILED" << std::endl;
            return false;
        }
        
        //parse image to figure out what kind of properties it holds
        std::vector<std::string> strVec = split(*p, '_');
        
        color colVar;
        shading shadeVar;
        number numVar;
        shape shapeVar;
        
        if(strVec[1].compare("1") == 0) {
            numVar = number::ONE;
        } else if(strVec[1].compare("2") == 0) {
            numVar = number::TWO;
        } else {
            numVar = number::THREE;
        }
        
        if(strVec[2].compare("oct") == 0) {
            shapeVar = shape::OCTAGON;
        } else if(strVec[2].compare("star") == 0) {
            shapeVar = shape::STAR;
        } else {
            shapeVar = shape::TRIANGLE;
        }
        
        if(strVec[3].compare("empty") == 0) {
            shadeVar = shading::EMPTY;
        } else if(strVec[3].compare("grad") == 0) {
            shadeVar = shading::MID;
        } else {
            shadeVar = shading::FULL;
        }
        
        if(strVec[4].compare("blue.png") == 0) {
            colVar = color::BLUE;
        } else if(strVec[4].compare("green.png") == 0) {
            colVar = color::GREEN;
        } else {
            colVar = color::RED;
        }
        
        //now load the card object based off of the image
        GameObject *card = new CardObject(new LoaderParams(0, 0, CARD_WIDTH, CARD_HEIGHT, *p), colVar, shadeVar, numVar, shapeVar);
        
        //now push the card into game objects
        m_leftCards.push_back(card);
    }
    
    std::cout << "All Images Loaded" << std::endl;
    return true;
}

void PlayState::removeTextures() {
    
    int sizeOfImgArr = sizeof(images) / sizeof(images[0]);
    for(size_t i = 0; i < sizeOfImgArr; i++) {
        TextureManager::Instance()->clearFromTextureMap(images[i]);
    }
}

void PlayState::loadRandomInitialCards() {
    //find the size of initial array and load random cards off of it
    int sizeOfCardArray = (int) m_leftCards.size();
    
    //loop through as many cards as needed
    for(size_t i = 0; i < INITIAL_CARDS_NUM; i++) {
        //get a random card off of the array
        int nextCard = rand() % sizeOfCardArray;
        
        CardObject* card = (CardObject*) m_leftCards[nextCard];
        
        //let the multiplier lay out based on where it is in for loop
        int x_multiplier = i % 4;
        int y_multiplier = floor(i / 4);
        
        //set the position of the card
        int x = (WIDTH * .4) + ((CARD_WIDTH + WIDTH_PADDING) * x_multiplier);
        int y = (HEIGHT * .05) + ((CARD_HEIGHT + HEIGHT_PADDING) * y_multiplier);
        
        //add this card to the screen
        Vector2D position = Vector2D(x, y);
        card->setPosition(position);
        
        m_gameObjects.push_back(card);
        
        //remove card from the left cards array
        m_leftCards.erase(m_leftCards.begin() + nextCard);
        
        //remove one from card array
        sizeOfCardArray--;
    }
    
}

bool PlayState::checkSet(std::vector<CardObject*> selectedCards) {
    //check to see if there are 3 cards in the set
    if(selectedCards.size() < 3) {
        return false;
    }
    
    //check color
    bool colorSame = false;
    if((selectedCards[0]->getColor() == selectedCards[1]->getColor()) &&
       (selectedCards[1]->getColor() == selectedCards[2]->getColor())) {
        colorSame = true;
    }
    
    bool colorDifferent = false;
    if((selectedCards[0]->getColor() != selectedCards[1]->getColor()) &&
       (selectedCards[1]->getColor() != selectedCards[2]->getColor()) &&
       (selectedCards[2]->getColor() != selectedCards[0]->getColor())) {
        colorDifferent = true;
    }
    
    //check number
    bool numSame = false;
    if((selectedCards[0]->getNumber() == selectedCards[1]->getNumber()) &&
       (selectedCards[1]->getNumber() == selectedCards[2]->getNumber())) {
        numSame = true;
    }
    
    bool numDifferent = false;
    if((selectedCards[0]->getNumber() != selectedCards[1]->getNumber()) &&
       (selectedCards[1]->getNumber() != selectedCards[2]->getNumber()) &&
       (selectedCards[2]->getNumber() != selectedCards[0]->getNumber())) {
        numDifferent = true;
    }
    
    //check shape
    bool shapeSame = false;
    if((selectedCards[0]->getShape() == selectedCards[1]->getShape()) &&
       (selectedCards[1]->getShape() == selectedCards[2]->getShape())) {
        shapeSame = true;
    }
    
    bool shapeDifferent = false;
    if((selectedCards[0]->getShape() != selectedCards[1]->getShape()) &&
       (selectedCards[1]->getShape() != selectedCards[2]->getShape()) &&
       (selectedCards[2]->getShape() != selectedCards[0]->getShape())) {
        shapeDifferent = true;
    }
    
    //check shading
    bool shadeSame = false;
    if((selectedCards[0]->getShading() == selectedCards[1]->getShading()) &&
       (selectedCards[1]->getShading() == selectedCards[2]->getShading())) {
        shadeSame = true;
    }
    
    bool shadeDifferent = false;
    if((selectedCards[0]->getShading() != selectedCards[1]->getShading()) &&
       (selectedCards[1]->getShading() != selectedCards[2]->getShading()) &&
       (selectedCards[2]->getShading() != selectedCards[0]->getShading())) {
        shadeDifferent = true;
    }
    
    //if all traits are either different or the same, return true
    if((colorSame || colorDifferent) && (numSame || numDifferent) &&
       (shapeSame || shapeDifferent) && (shadeSame || shadeDifferent)) {
        return true;
    }
    
    //if the conditions don't match, return false
    return true;
}
