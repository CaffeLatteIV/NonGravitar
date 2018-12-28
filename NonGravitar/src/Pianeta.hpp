/*
 * Pianeta.h
 *
 *  Created on: 26 dic 2018
 *      Author: Mango
 */


#ifndef PIANETA_HPP_
#define PIANETA_HPP_
#include "Bunker.hpp"
#include <list>

using namespace std;

class Pianeta {
protected:
	int circonferenza;
	list <Bunker> bunkerList;

public:
	Pianeta();
};

#endif /* PIANETA_HPP_ */
