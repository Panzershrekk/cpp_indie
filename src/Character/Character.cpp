/*
** Character.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Mon May 22 09:55:22 2017 Thomas Fossaert
*/

#include "Character.hpp"

Character::Character()
{
}

Character::Character(Character const & other)
{
  (void) other;
}

Character& Character::operator=(Character const & other)
{
  (void) other;
  return *this;
}

void Character::getDamage()
{

}

void Character::attack()
{

}

bool Character::isAlive()
{
    return (false);
}

void Character::getDistance()
{

}

size_t Character::getRange()
{
  return (_range);
}
