#ifndef CARD_H
#define CARD_H

#include <iostream>

namespace blackjack
{

  enum rank {
    ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING
  };
  enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

  const int AMOUNT_SUITS = 4;
  const int AMOUNT_RANKS = 13;

  class Card
  {
  private:
    suit m_suit;
    rank m_rank;
    bool m_IsFaceUp;
  public:
    Card(suit aSuit = HEARTS,rank aRank = TWO, bool aIsFaceUp = false)
      :m_suit(aSuit),m_rank(aRank),m_IsFaceUp(aIsFaceUp){}
    ~Card(){}
    void Flip();
    int GetValue() const;
    rank GetRank() const {return m_rank;}
    bool isFaceUp() const {return m_IsFaceUp;}
    friend std::ostream& operator<<(std::ostream& out, const Card &card);
  };

}

#endif // CARD_H
