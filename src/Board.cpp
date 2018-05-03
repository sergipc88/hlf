#include "Board.h"
#include <iostream>
#include <sstream>
// Constructors/Destructors
//  

Board::Board (BoardType t)
{
	setMode(MODE_BASIC);
	setType(t);
	initBoard();

}

Board::~Board () {

}


void  Board::initBoard(){

	CellStatus cs = CELL_STATUS_UkNOWN;
	if(getType() == BOARD_TYPE_FLEET)cs = CELL_STATUS_WATER;


	for (unsigned char i = 0; i < BOARD_NUM_CELL; i++){

		for (unsigned char j = 0; j< BOARD_NUM_CELL; j++){

			board_[i][j].setStatus(cs);
			board_[i][j].setId(CELL_NO_SHIP_ID);
		}
	}

}


bool Board::writeShot(unsigned char x, unsigned char y, CellStatus status){

	board_[x][y].setStatus(status);
bool bok = true;
return bok;
}

bool Board::shipInLimits(unsigned char x, unsigned char y,unsigned char size, Shipdirection dir){
	int pos;
	bool put = true;
	if(dir ==  DIR_HORIZONTAL){pos= x + size;}
	else if(dir == DIR_VERTICAL){pos= y + size;}

	if(pos>BOARD_NUM_CELL){put = false;}
	else if(pos<BOARD_NUM_CELL){put = true;}

	return put;
};

void Board::setType(BoardType type){
	type_ = type;
};

BoardType Board::getType() const {
	return type_;
};




string Board::dump(){

	stringstream ss ;
	char eje[] = {'A','B','C','D','E','F','G','H','I','J'};

	for (int j = 0; j < BOARD_NUM_CELL; j++){
			ss << eje[j] << "   ";

			for (int i = 0; i < BOARD_NUM_CELL; i++){

			ss << " | "<<board_[i][j].dump();


			}
			ss << " |" << endl;
			ss << "     ---------------------------------------------------"<<endl;
		}

	return ss.str() ;

}



bool Board::placeShip(unsigned char x, unsigned char y,unsigned char size, Shipdirection dir, unsigned char id)
{
	bool bOk = true ;

	if(getMode() == MODE_BASIC)
	{
		bOk = placeShipBasic(x,y,size,dir,id) ;
	}
	else
	{
		// CLASSIC ...!
	}
	return bOk;
}

bool Board::placeShipBasic(unsigned char x, unsigned char y,unsigned char size, Shipdirection dir, unsigned char id)
{
	bool bOk = true ;

	if (shipInLimits(x, y, size, dir)) {
		int ships = 0;
		for (unsigned char i = 0; i < size; i++) {

			if (dir == DIR_HORIZONTAL) {ships = ships + board_[x + i][y].getId();}
			else if (dir == DIR_VERTICAL) {ships = ships + board_[x][y + i].getId();}
		}
		if (ships != 0) {
			bOk = false;
		}
		else
		{
			placeShipBoard(x,y,size,dir,id);
		}

	}else {
		bOk = false;
	}

return bOk;
}


void Board::placeShipBoard(unsigned char x, unsigned char y,unsigned char size, Shipdirection dir, unsigned char id){

	for (unsigned char i = 0; i < size; i++) {


				if (dir == DIR_HORIZONTAL) {
					board_[x + i][y].setStatus(CELL_STATUS_SHIP_OK);
					board_[x + i][y].setId(id);
				}
				else if (dir == DIR_VERTICAL) {
					board_[x][y+i].setStatus(CELL_STATUS_SHIP_OK);
					board_[x][y+i].setId(id);
				}
			}

}

Mode Board::getMode() const {return mode_;}
void Board::setMode(Mode m) {mode_ = m ;}

void Board::clearBoard(){initBoard();}

CellStatus Board::posStatus(unsigned char x, unsigned char y){
	CellStatus status = board_[x][y].getStatus();

	return status;
}



unsigned char Board::posId(unsigned char x, unsigned char y){

	unsigned char id = board_[x][y].getId();

	return id;
}


CellStatus Board::receiveShot(int id_ship, unsigned char x, unsigned char y){
	CellStatus status = CELL_STATUS_SUNK ;
	CellStatus newStatus = CELL_STATUS_SUNK  ;

	int id;

	for (unsigned char i = 0; i < BOARD_NUM_CELL; i++){

			for (unsigned char j = 0; j< BOARD_NUM_CELL; j++){

				id = board_[i][j].getId();
				status = board_[i][j].getStatus();

					if(i == x && j == y){

					}else{

						if(id != CELL_NO_SHIP_ID && id == id_ship && status == CELL_STATUS_SHIP_OK){

							newStatus = CELL_STATUS_DAMAGE;

						}else{

						}
					}
			}
	}

		return newStatus ;

}

void Board::shipSunk(unsigned char id_ship){

	unsigned char id;
	for (unsigned char i = 0; i < BOARD_NUM_CELL; i++){

				for (unsigned char j = 0; j< BOARD_NUM_CELL; j++){

					id = board_[i][j].getId();

					if(id == id_ship){
						board_[i][j].setStatus(CELL_STATUS_SUNK);
					}

				}
		}

}



