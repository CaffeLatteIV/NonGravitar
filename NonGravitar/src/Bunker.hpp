/*
 * Bunker.h
 *
 *  Created on: 26 dic 2018
 *      Author: Mango
 */

#ifndef BUNKER_HPP_
#define BUNKER_HPP_

class Bunker {
protected:
	int hp; //base 1
public:
	Bunker(int hp = 1){
		this->hp=hp;
	}
	// se la vita finisce restituisce true
	bool decHp(){
		if(hp-1<=0){
			return true;
		}else{
			hp--;
			return false;
		}
	}
};

#endif /* BUNKER_HPP_ */
