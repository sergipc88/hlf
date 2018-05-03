/*
 * Cell.cpp
 *
 *  Created on: 12 abr. 2018
 *      Author: pedro
 */

#include "Cell.h"
#include <sstream>

Cell::Cell() {
	setStatus(CELL_STATUS_UkNOWN) ;
	setId(CELL_NO_SHIP_ID);
}

Cell::~Cell() {
	// TODO Auto-generated destructor stub
}



void Cell::setStatus(CellStatus status){ status_ = status ;} ;
CellStatus Cell::getStatus() const{return status_;}

void Cell::setId(unsigned char id){id_ = id;} ;
unsigned char Cell::getId() const{ return id_;} ;

string Cell::dump(){
	stringstream ss ;


	if(getId() != CELL_NO_SHIP_ID){
		ss <<(unsigned int)getId();

		switch (getStatus()){
			case CELL_STATUS_UkNOWN : ss<<  " U";break;
			case CELL_STATUS_WATER :ss<<" W";break;
			case CELL_STATUS_DAMAGE :ss<< " D";break;
			case CELL_STATUS_SUNK :ss<< " S";break;
			case CELL_STATUS_SHIP_OK  :ss<< "O";break;
			}

	}

	else{
		switch (getStatus()){
					case CELL_STATUS_UkNOWN : ss<<  " U";break;
					case CELL_STATUS_WATER :ss<<" W";break;
					case CELL_STATUS_DAMAGE :ss<< " D";break;
					case CELL_STATUS_SUNK :ss<< " S";break;
					case CELL_STATUS_SHIP_OK  :ss<< " O";break;
					}
	}
	return ss.str();
}

//	ss <<(unsigned int)getId();

