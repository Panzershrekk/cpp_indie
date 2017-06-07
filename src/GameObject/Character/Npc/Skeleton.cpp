/*
** Skeleton.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Mon Jun 05 16:11:17 2017 Thomas Fossaert
*/

#include "GameObject/Character/Npc/Skeleton.hpp"

Skeleton::Skeleton(int x, int y, int z, int id) : Npc(x, y, z, id)
{
  this->_health = 2;
  this->_attack = 1;
  this->_range = 5;
  mPosition = new Position(x, y, z);
  mScript = new Script();
  mNodeName = "SkeletonNode" + std::to_string(id);
}

Skeleton::Skeleton(Skeleton const & other) : Npc(other)
{
  (void)other;
}

Skeleton& Skeleton::operator=(Skeleton const & other)
{
  (void) other;
  return *this;
}

Skeleton::~Skeleton() {}

void Skeleton::setOgreBase(Ogre::SceneManager* mSceneMgr)
{
  mEntity = mSceneMgr->createEntity("Skeleton", "character_scourge_male_scourgemale_hd.m2_Geoset_000-Main.mesh");

  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(mNodeName, mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(100.0f, 100.0f, 100.0f);
  mNode->setOrientation(1,1,0,0);
}

Ogre::Vector3 Skeleton::launchScript(Ogre::SceneManager *mSceneMgr, Ogre::SceneNode *target)
{
  Ogre::Vector3 nextMove = Ogre::Vector3::ZERO;
  nextMove = mScript->SkeletonScript(mSceneMgr->getSceneNode("SkeletonNode1"), target);
  //mPosition->setPosition(nextMove.x, nextMove.y, nextMove.z);
  return (nextMove);
}

void Skeleton::Animate(const Ogre::FrameEvent& fe)
{
  mAnimationState = mAnimation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
}
