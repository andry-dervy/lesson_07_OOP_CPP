#include "card.h"

void Card::Flip() {
  m_IsFaceUp = !(m_IsFaceUp);
}

int Card::GetValue() const {
  int value = 0;
  if (m_IsFaceUp)
  {
    value = m_rank;
    if (value > 10)
      value = 10;
  }
  return value;
}

std::ostream& operator<<(std::ostream& out, const Card &card)
{
  if(!card.isFaceUp())
    out << "XX";
  else
  {
    switch (card.m_suit)
    {
      case CLUBS: out << "[CLUBS,"; break;
      case DIAMONDS: out << "[DIAMONDS,"; break;
      case HEARTS: out << "[HEARTS,"; break;
      case SPADES: out << "[SPADES,"; break;
    }
    switch (card.m_rank)
    {
      case ACE: out << "ACE]"; break;
      case KING: out << "KING]"; break;
      case QUEEN: out << "QUEEN]"; break;
      case JACK: out << "JACK]"; break;
      case TEN: out << "TEN]"; break;
      case NINE: out << "NINE]"; break;
      case EIGHT: out << "EIGHT]"; break;
      case SEVEN: out << "SEVEN]"; break;
      case SIX: out << "SIX]"; break;
      case FIVE: out << "FIVE]"; break;
      case FOUR: out << "FOUR]"; break;
      case THREE: out << "THREE]"; break;
      case TWO: out << "TWO]"; break;
    }
  }

  return out;
}
