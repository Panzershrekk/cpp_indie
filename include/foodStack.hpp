/*
** foodStack.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Mon May 22 10:01:29 2017 Thomas Fossaert
*/

#ifndef _FOODSTACK_HPP_
# define _FOODSTACK_HPP_

#include "Loot.hpp"

class foodStack : public Loot
{
public:
  foodStack();
  foodStack(foodStack const &);
  foodStack& operator=(foodStack const &);
  //virtual ~foodStack();

  /* Classes */

  void increaseHealth();
};

#endif
