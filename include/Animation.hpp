/*
** Animation.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue May 30 12:29:30 2017 Thomas Fossaert
** Last update Tue May 30 13:24:21 2017 Thomas Fossaert
*/

#ifndef _Animation_HPP_
#define _Animation_HPP_

#include <OgreSkeleton.h>
#include "BaseGauntlet.hpp"

class Animation
{
public:
  Animation();
  Animation(Animation const &);
  Animation& operator=(Animation const &);
  ~Animation();

  /* Classes */
  Ogre::AnimationState *simpleAnimation(Ogre::AnimationState *, const std::string&, const Ogre::FrameEvent&, Ogre::Entity *);
};

#endif