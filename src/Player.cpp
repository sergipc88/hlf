#include "Player.h"
#include <stdlib.h>
#include <sstream>
#include <iostream>

// Constructors/Destructors
//  

Player::Player () {
	boards_[BOARD_MY_FLEET] = new Board(BOARD_TYPE_FLEET);
	boards_[BOARD_RIVAL] = new Board(BOARD_TYPE_RIVAL);
	setChrono(0);

}

Player::~Player () {

	if(boards_[BOARD_MY_FLEET] != NULL){
		delete boards_[BOARD_MY_FLEET];
		boards_[BOARD_MY_FLEET] = NULL;
	}

	if(boards_[BOARD_RIVAL] != NULL){
			delete boards_[BOARD_RIVAL];
			boards_[BOARD_RIVAL] = NULL;
		}

}

void Player::genRandomGame(){
	genRandomShip(4,1);
	genRandomShip(3,2);
	genRandomShip(3,3);
	genRandomShip(2,4);
	genRandomShip(2,5);
	genRandomShip(2,6);

};
void Player::genManualGame(){};


void Player::genRandomShip(unsigned char size, unsigned char id){


	unsigned char x;
	unsigned char  y;
	Shipdirection dir;
	bool bok = true;

	do
	{
		x = rand()%10;
		y = rand()%10;
		dir = (Shipdirection) (rand()%2) ;
		if(dir == 0){
			dir = DIR_HORIZONTAL;
		}else{
			dir = DIR_VERTICAL;
		}


		bok = boards_[BOARD_MY_FLEET]->placeShip(x,y,size,dir,id);
	}
	while(!bok);

};


const string& Player::getName() const{return name_;};
void Player::setName(const string& name){name_ = name;};

time_t Player::getChrono() const{return chrono_;};
void Player::setChrono(time_t chrono){chrono_ = chrono;};

void Player::setGameMode(Mode){};
Mode Player::getGameMode() const{return boards_[BOARD_MY_FLEET]->getMode() ;};

void Player::newGame() {};

string Player::dump() const
{
	stringstream ss ;


	ss << "     -------------------Tu Tablero----------------------"<<endl;
	ss << " " << endl;
	ss << "        0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |" << endl;
	ss << " " << endl;
	ss << boards_[BOARD_MY_FLEET]->dump() << endl ;
	cout << endl;
	ss << " " << endl;
	ss << "        0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |" << endl;
	ss << " " << endl;
	ss << "     ------------------Tablero Rival--------------------"<<endl;
	ss << " " << endl;
	ss << boards_[BOARD_RIVAL]->dump() << endl ;

	return ss.str() ;

}






void Player::sendShot(unsigned char x, unsigned char y, CellStatus status){

	  unsigned char id = boards_[BOARD_MY_FLEET]->posId(x,y);

	  boards_[BOARD_RIVAL]->writeShot(x,y,status);

	  if(status == CELL_STATUS_SUNK){

		  boards_[BOARD_MY_FLEET]->shipSunk(id);
	  }

}




	CellStatus Player::receiveShot(unsigned char x, unsigned char y){

    CellStatus currentStatus = boards_[BOARD_MY_FLEET]->posStatus(x,y);
    CellStatus newStatus = CELL_STATUS_UkNOWN;

    unsigned char id = boards_[BOARD_MY_FLEET]->posId(x,y);

    if(currentStatus == CELL_STATUS_SHIP_OK){

    newStatus = boards_[BOARD_MY_FLEET]->receiveShot(id,x,y);

     boards_[BOARD_MY_FLEET]->writeShot(x,y, newStatus);

     	 	if(newStatus == CELL_STATUS_SUNK){
     	 		boards_[BOARD_MY_FLEET]->shipSunk(id);
     	 	}


    }else{
    	newStatus = currentStatus;
    }






    return newStatus;
}




