#include "hand.h"

Hand::~Hand()
{
  for(auto& c: cards)
  {
    delete c;
  }
}

int Hand::getTotal() const {
  int sum = 0;
  for(const auto& c: cards)
  {
    if(c->GetRank() == ACE)
      sum += 11;
    else
      sum += c->GetValue();
  }
  for(const auto& c: cards)
    if(c->GetRank() == ACE)
      sum -= 10;
  return sum;
}

void Hand::Clear()
{
  for(auto& pCard: cards)
  {
    delete pCard;
  }
  cards.clear();
}
