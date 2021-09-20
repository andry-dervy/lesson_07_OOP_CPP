#ifndef PLAYER_H
#define PLAYER_H

#include "genericplayer.h"
#include <iostream>
#include <sstream>

class Player: public GenericPlayer
{
private:
  static int id;
public:
  Player(std::string aName = "Player");
  Player(const Player &p);
  ~Player();

  bool IsHitting() const;
  void Win() const;
  void Lose() const;
  void Push() const;
};

#endif // PLAYER_H
