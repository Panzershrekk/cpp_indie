/*
** Zombie.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
// Last update Sat Jun 10 15:13:35 2017 Thomas Fossaert
*/

#include "GameObject/Character/Npc/Zombie.hpp"

Zombie::Zombie(int x, int y, int z, int id) : Npc(x, y, z, id)
{
  this->_health = 2;
  this->_attack = 1;
  mPosition = new Position(x, y, z);
  mScript = new Script();
  mNodeName = "ZombieNode" + std::to_string(id);
  this->_animations[IDLE] = new Animation("Stand", false);
  this->_animations[WALK] = new Animation("Run", false, this->_speed, 125);
  this->_currentAnimation = this->_animations[WALK];
}

Zombie::Zombie(Zombie const & other) : Npc(other)
{
  (void)other;
}

Zombie& Zombie::operator=(Zombie const & other)
{
  (void) other;
  return *this;
}

Zombie::~Zombie() {}

void Zombie::setOgreBase(Ogre::SceneManager* mSceneMgr)
{
  mEntity = mSceneMgr->createEntity("Zombie" + std::to_string(_id), "creature_northrendghoul2_northrendghoul2.mesh");
  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(mNodeName, mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(1.7f, 1.7f, 1.7f);
  mNode->setOrientation(1,1,0,0);
}

void Zombie::launchScript(Ogre::SceneManager *mSceneMgr, Ogre::SceneNode *target, const Ogre::FrameEvent& fe)
{
  mSceneMgr->getSceneNode(mNodeName)->translate(
    mScript->ZombieScript(mSceneMgr->getSceneNode(mNodeName), target) * fe.timeSinceLastFrame,
    Ogre::Node::TS_LOCAL);
  if (mScript->ZombieScript(mSceneMgr->getSceneNode(mNodeName), target) == Ogre::Vector3::ZERO){
    this->launchAnimation(fe, IDLE);
    mAnimationState = this->_currentAnimation->getAnimationState();
  }
  else{
    this->launchAnimation(fe, WALK);
    mAnimationState = this->_currentAnimation->getAnimationState();
  }
}

void Zombie::Animate(const Ogre::FrameEvent& fe)
{
  //this->launchAnimation(WALK);
  //mAnimationState = mAnimation->simpleAnimation(mAnimationState, "Run", fe, mEntity);
}

void Zombie::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}
