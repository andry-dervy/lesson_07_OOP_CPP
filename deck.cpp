#include <algorithm>
#include <functional>
#include "deck.h"

namespace blackjack
{

  Deck::Deck()
    : countCards(0)
  {
  }

  Deck::~Deck()
  {
    for(auto& c: cards)
    {
      if(c != nullptr)
      {
        delete c;
        c = nullptr;
      }
    }
  }

  void Deck::Populate()
  {
    cards.resize(SIZE_FULL_DECK);
    for(int i = 0; i < AMOUNT_SUITS; ++i)
    {
      suit s;
      switch (i)
      {
        case 0: s = CLUBS; break;
        case 1: s = DIAMONDS; break;
        case 2: s = HEARTS; break;
        case 3: s = SPADES; break;
      }

      for(int j = 0; j < AMOUNT_RANKS; ++j)
      {
        rank r;
        switch (j)
        {
          case 0: r = TWO; break;
          case 1: r = THREE; break;
          case 2: r = FOUR; break;
          case 3: r = FIVE; break;
          case 4: r = SIX; break;
          case 5: r = SEVEN; break;
          case 6: r = EIGHT; break;
          case 7: r = NINE; break;
          case 8: r = TEN; break;
          case 9: r = JACK; break;
          case 10: r = QUEEN; break;
          case 11: r = KING; break;
          case 12: r = ACE; break;
        }

        cards[j+i*AMOUNT_RANKS] = new Card(s,r);
      }
    }
  }

  int Rand(int n)
  {
    srand( time(0) );
    return rand()%n;
  }

  void Deck::Shuffle()
  {
    cards.clear();
    Populate();
    std::random_shuffle(cards.begin(),cards.end(),
                        Rand);
    countCards = 0;
  }

  void Deck::Deal(Hand& aHand)
  {
    if(countCards == SIZE_FULL_DECK)
      return;
    cards[countCards]->Flip();
    aHand.Add(cards[countCards]);
    ++countCards;
  }

  bool Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
  {
    if(aGenericPlayer.getTotal() >= 21)
      return false;
    if(aGenericPlayer.IsHitting())
    {
      Deal(aGenericPlayer);
      return true;
    }
    return false;
  }

}
