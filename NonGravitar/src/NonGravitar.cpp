//============================================================================
// Name        : NonGravitar.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Astronave.hpp"
using namespace std;
using namespace sf;

int windowHeight = 900; //altezza
int windowWidth = 900;  //larghezza
int main(){
	//creazione finestra di gioco
    RenderWindow window(VideoMode(windowHeight,windowWidth), "Non-Gravitar");
    //tasti freccia
    bool buttonUp, buttonDown, buttonLeft, buttonRight = false;

    //astronave
    Astronave * astronave = new Astronave();
    Texture astronaveTexture;
    astronaveTexture.loadFromFile("data/images/spaceship.png");
    Sprite astronaveSprite(astronaveTexture);

    //font
    Font arcadeFont;
    arcadeFont.loadFromFile("data/fonts/ARCADECLASSIC.TTF");
    Text home("Non Gravitar",arcadeFont,50);
    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        //movimento

        //tasti premuti
        if(Keyboard::isKeyPressed(Keyboard::Right)){
        	if(astronaveSprite.getPosition().x + astronave->xvel < windowWidth - astronaveSprite.getGlobalBounds().width){
        		buttonRight = true;
        	}else{
        		buttonRight = false;
        	}
        }
        if(Keyboard::isKeyPressed(Keyboard::Left)){
        	if( astronaveSprite.getPosition().x + astronave->xvel > 0){
        		buttonLeft = true;
        	}else{
        		buttonLeft = false;
        	}
        }
        if(Keyboard::isKeyPressed(Keyboard::Up)){
        	if(astronaveSprite.getPosition().y + astronave->yvel > 0){
        		buttonUp = true;
        	}else{
        		buttonUp = false;
        	}
        }
        if(Keyboard::isKeyPressed(Keyboard::Down)){
        	if(astronaveSprite.getPosition().y + astronave->yvel < window.getSize().y -astronaveSprite.getGlobalBounds().height ){
        		buttonDown = true;
        	}else{
        		buttonDown = false;
        	}
        }

        //tasti non premuti
        if(!(Keyboard::isKeyPressed(Keyboard::Right))) buttonRight = false;
        if(!(Keyboard::isKeyPressed(Keyboard::Left))) buttonLeft = false;
        if(!(Keyboard::isKeyPressed(Keyboard::Up))) buttonUp = false;
        if(!(Keyboard::isKeyPressed(Keyboard::Down))) buttonDown = false;
        astronave->update(buttonUp,buttonDown,buttonLeft,buttonRight);
        window.clear();

        window.draw(astronaveSprite);
        astronaveSprite.move(Vector2f(astronave->xvel,astronave->yvel)); //sposta lo sprite
        window.draw(home);
        window.display();
    }

    return 0;
}
