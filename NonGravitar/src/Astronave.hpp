/*
 * Astronave.h
 *
 *
 *      Author: Mango
 */

#ifndef ASTRONAVE_HPP_
#define ASTRONAVE_HPP_

class Astronave {
protected:
	int hp = 5; //default 5
	int fuel = 10;//default 10

public:
	//velocità
	float xvel;
	float yvel;

	//posizione
	float xpos;
	float ypos;

	//direzione
	bool facingUp;
	bool facingDown;
	bool facingLeft;
	bool facingRight;


	Astronave(){
		xvel = 0;
		yvel = 0;
		xpos = 0;
		ypos = 0;
		facingUp = false;
		facingDown= false;
		facingRight = false;
		facingLeft = false;
	}

	int getHp(){
		return this->hp;
	}
	int getFuel(){
		return this->fuel;
	}
	//collisioni
	void decHp(){
		hp --;
	}
	void decFuel(){
		fuel--;
	}
	//aggiorna la velocità e la direzione dell' astronave
	void update(bool up, bool down, bool left, bool right){
		float shift= 0.017;
		if(up){
			yvel = -shift;
			facingUp = true;
		}
		if(down){
			facingDown = true;
			yvel = shift;
		}
		if(left){
			facingLeft = true;
			xvel = -shift;
		}
		if(right){
			facingRight = true;
			xvel = shift;
		}
		//se non viene premuto alcun tasto, l'astronave rimane ferma
		if(!(left||right)){
			xvel =0;
		}
		if(!(up||down)){
			yvel =0;
		}
		xpos += xvel;
		ypos +=yvel;
	}
	void collide(float maxWidth, float maxHeight){
		if(xpos){
			xvel =0;
		}
	}
};

#endif /* ASTRONAVE_HPP_ */
