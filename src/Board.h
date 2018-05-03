
#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include "Cell.h"

typedef enum Shipdirection{
	DIR_HORIZONTAL = 0 ,
	DIR_VERTICAL = 1

}
Shipdirection;

typedef enum Mode{

	MODE_BASIC = 0,
	MODE_CLASSIC = 1

} Mode;

typedef enum BoardType{
	BOARD_TYPE_FLEET = 0,
	BOARD_TYPE_RIVAL = 1
} BoardType ;


#define BOARD_NUM_CELL 10


class Board
{
	Cell board_[BOARD_NUM_CELL][BOARD_NUM_CELL];
	Mode mode_ ;
	BoardType type_;

private:

	void initBoard();
	bool shipInLimits(unsigned char x, unsigned char y,unsigned char size, Shipdirection dir);
	bool placeShipBasic(unsigned char x, unsigned char y,unsigned char size, Shipdirection dir, unsigned char id);
	void placeShipBoard(unsigned char x, unsigned char y,unsigned char size, Shipdirection dir, unsigned char id);

public:

	string dump();
	Board ();
	Board(BoardType);
	virtual ~Board ();


	bool writeShot(unsigned char x, unsigned char y, CellStatus status);
	CellStatus readtShot(unsigned char x, unsigned char y)const ;

	bool placeShip(unsigned char x, unsigned char y,unsigned char size, Shipdirection dir, unsigned char id);


	Mode getMode() const ;
	void setMode(Mode) ;
	void clearBoard();

	void setType(BoardType);
	BoardType getType() const;

	CellStatus posStatus(unsigned char x, unsigned char y);
	unsigned char  posId(unsigned char x, unsigned char y);

	CellStatus receiveShot(int id_ship, unsigned char x, unsigned char y);
	void shipSunk(unsigned char id);
};


#endif // BOARD_H
