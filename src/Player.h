
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Board.h"

#define NUM_BOARDS 2
#define BOARD_MY_FLEET 0
#define BOARD_RIVAL 1



class Player
{

  string name_;
  time_t chrono_ ;

  Board* boards_[NUM_BOARDS];





private:

  void genRandomShip(unsigned char size, unsigned char id);



public:

  Player ();

    virtual ~Player ();

    void genRandomGame();
    void genManualGame();

    const string& getName() const;
    void setName(const string& name);
    time_t getChrono() const;
    void setChrono(time_t chrono);

    void setGameMode(Mode);
    Mode getGameMode() const;

    void newGame() ;
    string dump() const;

    void sendShot(unsigned char x, unsigned char y, CellStatus status);
    CellStatus receiveShot(unsigned char x, unsigned char y);

};


#endif // PLAYER_H
