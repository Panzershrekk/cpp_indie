/*
** Script.cpp for script in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/src/Script
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Mon May 22 15:24:56 2017 Adrien Warin
** Last update Thu Jun 01 11:38:22 2017 Thomas Fossaert
*/

#include "Script.hpp"

Script::Script ()
{
}

Script::~Script ()
{
}

Ogre::Vector3 Script::ZombieScript(Ogre::SceneNode *current, Ogre::SceneNode *target)
{
  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

  if (current->getPosition().x < target->getPosition().x)
    dirVec.x = 75;
  if (current->getPosition().x > target->getPosition().x)
    dirVec.x = -75;
  if (current->getPosition().z > target->getPosition().z)
    dirVec.z = -75;
  if (current->getPosition().z < target->getPosition().z)
    dirVec.z = 75;

  return (dirVec);
}

void Script::test()
{
}
