/*
** foodStack.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
// Last update Thu Jun 15 14:12:07 2017 Thomas Fossaert
*/

#include "GameObject/Loot/foodStack.hpp"

foodStack::foodStack(int x, int y, int z, int id) : Loot(x, y, z, id)
{
  mPosition = new Position(x, y, z);
  mNodeName = "foodStackNode" + std::to_string(id);
}

foodStack::foodStack(foodStack const & other) : Loot(other)
{
}

foodStack& foodStack::operator=(foodStack const &)
{
  return *this;
}

foodStack::~foodStack()
{

}

void foodStack::setOgreBase(Ogre::SceneManager* mSceneMgr)
{

  mEntity = mSceneMgr->createEntity("foodStack" + std::to_string(_id), "world_expansion04_doodads_pandaren_pa_food_bakedwildfowl_01.m2_.mesh");
  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(mNodeName, mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(100.0f,100.0f, 100.0f);
  mNode->setOrientation(1,0,0,0);
}

void foodStack::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
  this->_unset = new Particle("test" + std::to_string(_id), "Examples/getFood", mSceneMgr, mNode);
}

bool foodStack::isTaken(Pc const & other)
{
  if (this->mPosition == other.getPosition())
    return (true);
  return (false);
}
