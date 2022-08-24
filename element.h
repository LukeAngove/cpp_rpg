#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>

/**
 * Contains the elements used, as well as any
 * categories of elements.
 * 
 * Elements have bit values to allow for easy 
 * use of multiple elements through bitwise 
 * operations rather than vectors or similar.
 * 
 */
enum Element {
  FIRE=0b10000,
  WATER=0b01000,
  EARTH=0b00100,
  SPIRIT=0b00010,
  LIGHTNING=0b00001,
  ALL=Element::FIRE | Element::WATER | Element::EARTH | Element::SPIRIT | Element::LIGHTNING,
};

// contains all elements being used in the game.
const std::vector<Element> ELEMENTLIST = {Element::FIRE, Element::WATER, Element::LIGHTNING, Element::EARTH, Element::SPIRIT};

// checks if an element is in a given search mask.
bool elementInSearch(const Element, const int searchMask);

#endif
