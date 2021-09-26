#include "hand.h"

namespace blackjack
{

  Hand::~Hand()
  {
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
    if(sum > 21)
      for(const auto& c: cards)
        if(c->GetRank() == ACE)
          sum -= 10;
    return sum;
  }

  void Hand::Clear()
  {
    cards.clear();
  }

}
