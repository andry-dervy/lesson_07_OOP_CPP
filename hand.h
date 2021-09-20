#ifndef HAND_H
#define HAND_H

#include "card.h"
#include <vector>

class Hand
{
protected:
  std::vector<Card*> cards;
public:
  Hand(){}
  virtual ~Hand();

  void Add(Card *card){cards.push_back(card);}
  const std::vector<Card*>& getCards() const
    {return cards;};
  void Clear();
  int getTotal() const;
};

#endif // HAND_H
