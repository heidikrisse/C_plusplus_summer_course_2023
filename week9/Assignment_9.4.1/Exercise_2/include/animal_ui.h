// animal_ui.h
#ifndef ANIMAL_UI_H
#define ANIMAL_UI_H

#include "animal.h"

/* Exercise 3: Function takes animal reference as a parameter
 * and demonstrates the functions of the object */
void show_animal_info(const Animal &animal);

template <class T>
inline constexpr bool always_false_v = false;

#endif
