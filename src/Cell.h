

#ifndef CELL_H_
#define CELL_H_

#include <string>

#define  CELL_NO_SHIP_ID 0

using namespace std ;

typedef enum CellStatus{

	CELL_STATUS_UkNOWN = 0,
	CELL_STATUS_WATER = 1,
	CELL_STATUS_DAMAGE = 2,
	CELL_STATUS_SUNK = 3,
	CELL_STATUS_SHIP_OK = 4
} CellStatus ;


class Cell
{

	CellStatus status_ ;
	unsigned char id_ ;


public:

	Cell();
	Cell(CellStatus status_, unsigned char);
	virtual ~Cell();



void setStatus(CellStatus) ;
CellStatus getStatus() const ;

void setId(unsigned char) ;
unsigned char getId() const ;

string dump() ;
};

#endif /* CELL_H_ */
