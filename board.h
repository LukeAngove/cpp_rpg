#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <tuple>
#include <map>

#include "element.h"
#include "sphere.h"
#include "move.h"

/**
 * @brief 
 * 
 */
class Board {
  public:
  Board();
  // count accepts int inputs rather than Element so that it can
  // deal with bitwise operations on inputs.
  int count(const int sphereType=Element::ALL, const int gemType=Element::ALL) const;
  
  bool isMoveValid(const std::vector<Move>) const;
  void doMoves(const std::vector<Move>);

  // void removeGem(const Element, const Element);

  void setSphere(const Element, const Sphere);
  Sphere getSphere(const Element) const;


  private:
  std::map<Element, Sphere> _spheres;

  // bool isMoveValidSingle(const std::tuple<Element, Element, Element>) const;
};

#endif
