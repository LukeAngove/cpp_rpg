#ifndef SPHERE_H
#define SPHERE_H

#include <map>

#include "element.h"


/**
 * A representation of the spheres present in the game board.
 * 
 * Extends the map class, as we want to use most of their functionality.
 * However, tihs class allows us to have constructors that ensure that the
 * map has keys for all the different elements and no extraneous keys,
 * as well as constructors that allow various formats of the number of gems present
 * in a sphere to control how many of each type of gem are in the sphere when
 * created. 
 * 
 */
class Sphere : public std::map<Element, int> {
  public:
    // Creates a sphere with no gems
    Sphere();

    // Creates a sphere contating gems specified by the input map.
    // The map has element keys that map to the number of gems of that element in the sphere.
    Sphere(std::map<Element, int>);

    // Creates a sphere contating gems specified by the input vector.
    // Each instance of an element in the vector adds 1 gem of that element to the sphere. 
    Sphere(std::vector<Element>);

    // checks if the current sphere is equal to the input.
    bool equal(Sphere) const;

    // counts the number of gems with types matching the gemType mask
    int count(int gemType = Element::ALL) const;
};


#endif
