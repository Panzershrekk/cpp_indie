/*
** Melee.hpp for melee in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/include
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Wed May 24 11:22:02 2017 Adrien Warin
** Last update Fri May 26 16:39:00 2017 Adrien Warin
*/

#ifndef MELEE_HPP_
#define  MELEE_HPP_

#include <iostream>
#include "GameObject/Character/Pc/Pc.hpp"

class Melee : public Pc
{
    private:

    public:
        Melee (const std::string &, int, int, int);
        Melee(Melee const &);
        Melee& operator=(Melee const &);
        virtual ~Melee ();
};

#endif
