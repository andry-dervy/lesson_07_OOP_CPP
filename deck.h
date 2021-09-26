#ifndef DECK_H
#define DECK_H

#include "hand.h"
#include "genericplayer.h"

namespace blackjack
{

  #define SIZE_FULL_DECK AMOUNT_SUITS*AMOUNT_RANKS

  class Deck : public Hand
  {
  private:
    int countCards;
  public:
    Deck();
    ~Deck();
    void Populate();
    void Shuffle();
    void Deal(Hand& aHand);
    bool AdditionalCards(GenericPlayer& aGenerlcPlayer);
  };

}
#endif // DECK_H
