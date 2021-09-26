#include "game.h"

namespace blackjack
{

  Game::Game(const std::list<std::string> &names)
  {
    players.resize(names.size());
    auto it = players.begin();
    for(const std::string &n: names)
    {
      *it = new Player(n);
      ++it;
    }
    house = std::make_shared<House>();
    deck = std::make_shared<Deck>();
    deck->Populate();
    deck->Shuffle();
  }

  Game::~Game()
  {
    for(auto& p: players)
      if(p != nullptr)
      {
        delete p;
        p = nullptr;
      }
  }

  void Game::play()
  {
    deck->Shuffle();
    //каждому игроку по две стартовые карты
    for(int i = 0; i < 2; ++i)
    {
      deck->Deal(*house);
      for(auto& p: players)
        deck->Deal(*p);
    }
    //первая карта дилера прячется
    house->getCards()[0]->Flip();
    //выводится информация о картах игроков
    GenericPlayer *gp;
    gp = dynamic_cast<GenericPlayer*>(house.get());
    std::cout << *gp;
    for(const auto p: players)
    {
      gp = dynamic_cast<GenericPlayer*>(p);
      std::cout << *gp;
    }
    //раздаются игрокам дополнительные карты
    for(auto& p: players)
    {
      while (deck->AdditionalCards(*p))
      {
        gp = dynamic_cast<GenericPlayer*>(p);
        std::cout << *gp;
      }
    }
    //показывается первая карта дилера
    house->getCards()[0]->Flip();
    do
    {
      gp = dynamic_cast<GenericPlayer*>(house.get());
      std::cout << *gp;
    }
    while (deck->AdditionalCards(*house));

    //определение победителя
    for(auto& p: players)
    {
      //Если блэкджек у игрока
      if(p->getCards().size() == 2 &&
         p->getTotal() == 21)
      {
        //Если блэкджек у дилера
        if(house->getCards().size() == 2 &&
           house->getTotal() == 21)
          p->Push();
        else
          p->Win();
      }
      //Если перебор у игрока
      else if(p->getTotal() > 21)
      {
        p->Lose();
      }
      //Иначе
      else if(house->getTotal() > 21 ||
         p->getTotal() > house->getTotal())
        p->Win();
      else if(p->getTotal() == house->getTotal())
        p->Push();
      else
        p->Lose();
    }
    //Руки всех игроков очищаются
    house->Clear();
    for(auto& p: players)
    {
      p->Clear();
    }
  }

  int inputIntPositive()
  {
    int n;
    while (true)
    {
      std::cin >> n;
      if (std::cin.fail())
      {
        std::cout << "Require enter an integer!" << std::endl;
        std::cin.clear();
        std::cin.ignore(32767, '\n');
      }
      else if (n <= 0)
      {
        std::cout << "Require enter an positive integer!" << std::endl;
        std::cin.clear();
        std::cin.ignore(32767, '\n');
      }
      else
      {
        return n;
      }
    }
  }

  bool isContinuingTheGame()
  {
    while(true)
    {
      std::cout << "Is continuing the game?" << std::endl;
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

  void bj_main()
  {
    std::cout << "Enter a number of players: ";
    int n_players = inputIntPositive();
    std::list<std::string> namesOfPlayers;
    for(int i = 0; i < n_players; ++i)
    {
      std::cout << "Enter a name of the player "
                << i+1 << ": ";
      std::string name;
      std::cin >> name;
      namesOfPlayers.push_back(name);
    }

    Game game(namesOfPlayers);
    do
    {
      game.play();
    }
    while(isContinuingTheGame());
  }
}
