#include <algorithm>

#include "board.h"
#include "movemap.h"

Board::Board() {
  for (auto element : ELEMENTLIST) {
    Sphere sphere({element});
    _spheres.insert({element, sphere});
  };
}

Sphere Board::getSphere(const Element sphereType) const {
  for (auto sphere : _spheres) {
    if (elementInSearch(sphere.first, sphereType)) {
      return(sphere.second);
    }
  }
  return {};
}

void Board::setSphere(const Element sphereType, const Sphere gems) {
  for (auto sphere : _spheres) {
    if (elementInSearch(sphere.first, sphereType)) {
      _spheres.at(sphereType) = gems;
    }
  }
}

int Board::count(const int sphereType, const int gemType) const {
  int count = 0;
  for (auto& sphere : _spheres) {
    if (elementInSearch(sphere.first, sphereType)) {
      count = count + sphere.second.count(gemType);
    }    
  }

  return count;
}

bool Board::isMoveValid(const std::vector<Move> moves) const {

  MoveMap moveMap(moves);
  for (auto sphere : ELEMENTLIST) {
    for (auto gem : ELEMENTLIST) {
      if (moveMap.inputCount(sphere, gem) > count(sphere, gem)) {
        return false;
      }
    }
  }
  
  return true;
}

void Board::doMoves(std::vector<Move> moves) {
  MoveMap moveMap(moves);
  for (auto sphere : ELEMENTLIST) {
    for (auto gem : ELEMENTLIST) {
      int newNumGems = count(sphere, gem) - moveMap.inputCount(sphere, gem);
      newNumGems = newNumGems + moveMap.outputCount(sphere, gem);
      _spheres.at(sphere).at(gem) = newNumGems;
    }
  } 
}
