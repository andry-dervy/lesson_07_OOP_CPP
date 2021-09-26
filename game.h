#ifndef GAME_H
#define GAME_H

#include <vector>
#include <list>
#include <memory>
#include "deck.h"
#include "house.h"
#include "player.h"

namespace blackjack
{

  class Game
  {
  private:
    std::shared_ptr<Deck> deck;
    std::shared_ptr<House> house;
    std::vector<Player*> players;
  public:
    Game(const std::list<std::string> &names);
    ~Game();
    void play();
  };

  void bj_main();
}
#endif // GAME_H
