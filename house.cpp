#include "house.h"

bool House::IsHitting() const
{
  if(getTotal() > 16)
    return false;
  else
    return true;
}

void House::FlipFirstCard()
{
  if(!cards.empty() && !cards.front()->isFaceUp())
    cards.front()->Flip();
}
