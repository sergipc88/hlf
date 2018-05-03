/*
 * Hlf.cpp
 *
 *  Created on: 10 abr. 2018
 *      Author: pedro
 */
#include <iostream>
#include "Interface.h"
#include <stdlib.h>
using namespace std;



int main(){
	srand(time(NULL));
//	Board b ;
//	b.setMode(MODE_BASIC) ;
	Player p1;
	Player p2;

	p1.newGame();
	p2.newGame();
	p1.genRandomGame();
	p2.genRandomGame();
	cout << p1.dump();
	cout << p2.dump();
	CellStatus status;




	while(true){
		int x;
				cin >> x;
		int y;
				cin >> y;

		status = p2.receiveShot(x,y);

		p1.sendShot(x,y,status);

		cout << p1.dump();
	}

//	b.writeShot(2,4,CELL_STATUS_DAMAGE);
//	b.writeShot(2,5,CELL_STATUS_WATER);
//	b.writeShot(2,3,CELL_STATUS_DAMAGE);


/*
 *
 *  unsigned char x = 3;
 *  unsigned char y = 7;
 *
 *  status = p2.receiveShot(x,y);
 *
 *  p1.sendShot(x,y,status);
 *
 *
 *
 *  //esto va en plpayer
 *  bool sendShot(unsigned x, unsigned char y, Cellstatus status);
 *
 *
 *
 *
 *
 *
 *
 *
 */




	return 0;
}

