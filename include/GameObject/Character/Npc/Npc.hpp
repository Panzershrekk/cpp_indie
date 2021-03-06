/*
** Npc.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Sat Jun 17 17:55:45 2017 Thomas Fossaert
*/

#ifndef _NPC_HPP_
#define _NPC_HPP_

#include <iostream>
#include "GameObject/Character/Character.hpp"

class Npc : public Character
{
protected:
  int _id;
  bool _hasAttacked;
public:
  Npc(int x, int y, int z, int id);
  Npc(Npc const &);
  Npc& operator=(Npc const &);
  virtual ~Npc();

  void setAttackStatus(bool stat);
  bool getAttackStatus() const;
};

#endif
