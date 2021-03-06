/*
** Animation.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src/Animation
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue May 30 12:34:40 2017 Thomas Fossaert
** Last update Fri Jun 16 16:38:10 2017 Pierre
*/

#include <OgreFrameListener.h>
#include "Animation.hpp"

Animation::Animation(std::string const& name, bool looping, double speed, double dist, double castingTime)
{
  this->_name = name;
  this->_animationState = NULL;
  this->_looping = looping;
  this->_dist = dist;
  this->_speed = speed;
  this->_castingTime = castingTime;
}

Animation::~Animation ()
{

}

void	Animation::setSpeed(double speed)
{
  this->_speed = speed;
}

bool	Animation::isLooping() const
{
  return (this->_looping);
}

void	Animation::addTime(float t)
{
  if (this->_animationState && this->_speed > 0.000001)
  {
    if (this->_dist > 0.000001)
      this->_animationState->addTime(t * this->_animationState->getLength() / (this->_dist / this->_speed));
    else
      this->_animationState->addTime(t * this->_animationState->getLength() / this->_speed);
  }
}

bool	Animation::hasEnded() const
{
  return (this->_animationState->hasEnded());
}

bool	Animation::isCasted() const
{
  if (this->_animationState)
    return (this->_animationState->getTimePosition() / this->_animationState->getLength() > this->_castingTime);
  return false;
}

void Animation::launch(const Ogre::FrameEvent& fe, Ogre::Entity *entity)
{
  this->_animationState = entity->getAnimationState(this->getName());
  this->_animationState->setLoop(!this->_looping);
  this->_animationState->setEnabled(true);
  this->_animationState->addTime(fe.timeSinceLastFrame);
}

void 	Animation::enable()
{
  if (this->_animationState)
    this->_animationState->setEnabled(true);
}

void 	Animation::disable()
{
  if (this->_animationState)
    this->_animationState->setEnabled(false);
}

const std::string	&Animation::getName() const
{
  return (this->_name);
}

Ogre::AnimationState *Animation::getAnimationState() const
{
  return (this->_animationState);
}

Ogre::AnimationState *Animation::initAnimation(Ogre::AnimationState *AnimationState, const std::string&, Ogre::Entity *entity)
{
  AnimationState = entity->getAnimationState("Walk");
  AnimationState->setLoop(true);
  AnimationState->setEnabled(true);
  return (AnimationState);
}


Ogre::AnimationState *Animation::simpleAnimation(Ogre::AnimationState *AnimationState, const std::string& anim, const Ogre::FrameEvent& fe, Ogre::Entity *entity)
{
  AnimationState = entity->getAnimationState(anim);
  AnimationState->setLoop(true);
  AnimationState->setEnabled(true);
  AnimationState->addTime(fe.timeSinceLastFrame);
  return (AnimationState);
}

Ogre::AnimationState *Animation::loopAnimation(Ogre::AnimationState *AnimationState, const std::string & anim, const Ogre::FrameEvent& fe, Ogre::Entity *entity)
{
  if (AnimationState->getTimePosition() + fe.timeSinceLastFrame > AnimationState->getLength())
  {
    AnimationState = entity->getAnimationState(anim);
    AnimationState->setLoop(true);
    AnimationState->setEnabled(true);
  }
  return (AnimationState);
}
