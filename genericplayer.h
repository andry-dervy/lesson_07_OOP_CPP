#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include "hand.h"
#include <iostream>

namespace blackjack
{

  class GenericPlayer: public Hand
  {
  private:
    std::string name;
  public:
    GenericPlayer(std::string aName = "")
      :name(aName){}
    virtual ~GenericPlayer(){};
    virtual bool IsHitting() const =0;
    bool IsBoosted() const;
    void Bust() const;

    const std::string& getName() const
      {return name;}
    void setName(const std::string& aName)
      {name = aName;}
    friend const std::ostream& operator<<(std::ostream& out, const GenericPlayer &gp);
  };

}
#endif // GENERICPLAYER_H
