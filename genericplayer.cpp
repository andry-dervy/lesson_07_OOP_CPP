#include "genericplayer.h"

bool GenericPlayer::IsBoosted() const
{
  if(getTotal() > 21)
    return true;
  return false;
}

void GenericPlayer::Bust() const
{
  std::cout << "Player "
            << name
            << " gets busted."
            << std::endl;
}

const std::ostream& operator<<(std::ostream& out, const GenericPlayer &gp)
{
  out << "Player " << gp.getName() <<
         " have got cards: ";
  for(const auto c: gp.getCards())
    out << *c;

  out << ". Total: " << gp.getTotal();
  out << std::endl;

  return out;
}
