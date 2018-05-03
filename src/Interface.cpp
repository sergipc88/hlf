#include "Interface.h"

// Constructors/Destructors
//  

Interface::Interface () {
initAttributes();
}

Interface::~Interface () {

	if(players_[PLAYER_A] != NULL ){

		delete players_[PLAYER_A] ;
		players_[PLAYER_A] = NULL ;

	}

	if(players_[PLAYER_B] != NULL ){

			delete players_[PLAYER_B] ;
			players_[PLAYER_B] = NULL ;

		}

}



void Interface::initAttributes () {
  setTurno_(0);
  players_[PLAYER_A] = new Player ;
  players_[PLAYER_B] = new Player ;
}

