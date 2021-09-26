#include "player.h"

namespace blackjack
{

  int Player::id = 0;

  Player::Player(std::string aName)
    :GenericPlayer(aName)
  {
    ++id;
    if(aName == "Player")
    {
      std::stringstream ss;
      ss << aName << id;
      setName(ss.str());
    }
  }

  Player::Player(const Player &p)
    :GenericPlayer(p.getName())
  {
    cards = p.cards;
  }

  Player::~Player()
  {
  }

  bool Player::IsHitting() const
  {
    while(true)
    {
      std::cout << "Does " << getName() << " need a new card?" << std::endl;
      std::string answer;
      std::cin >> answer;

      if(std::cin.fail())
      {
        std::cout << "For answer, enter y[es] or n[o]: " << std::endl;
        std::cin.clear();
        std::cin.ignore(32767, '\n');
      }
      else if(answer == "y" || answer == "yes" ||
              answer == "Y" || answer == "YES")
      {
        return true;
      }
      else if(answer == "n" || answer == "no" ||
              answer == "N" || answer == "NO")
      {
        return false;
      }
    }
  }

  void Player::Win() const
  {
    std::cout << "Player " << getName()
              << " is win." << std::endl;
  }

  void Player::Lose() const
  {
    std::cout << "Player " << getName()
              << " is lose." << std::endl;
  }

  void Player::Push() const
  {
    std::cout << "Player " << getName()
              << " is draw." << std::endl;
  }

}
