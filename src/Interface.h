
#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <vector>
#include "Player.h"
#include "Board.h"

#define NUM_PLAYERS 2
#define PLAYER_A 0
#define PLAYER_B 1





class Interface
{
	char turno_;
	Player* players_[NUM_PLAYERS] ;



public:

	void setTurno_ (char new_var)
	{
      turno_ = new_var;
	}


	char getTurno_ ()
	{
	  return turno_;
	}
  Interface ();

  virtual ~Interface ();


protected:

private:
  void initAttributes () ;

};

#endif // INTERFACE_H
