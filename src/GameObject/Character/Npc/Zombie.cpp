/*
** Zombie.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
// Last update Wed Jun 14 20:23:17 2017 Thomas Fossaert
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
  this->_animations[RUN] = new Animation("Run", false, this->_speed, 125);
  this->_animations[ATTACK] = new Animation("Attack", false, 1, 0, 0.5);
  this->_animations[WALK] = new Animation("Walk", false, 1, 0, 0.5);
  this->mAnimation = this->_animations[RUN];
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
  //mEntity = mSceneMgr->createEntity("Zombie", "character_scourge_male_scourgemale_hd.m2_Geoset_000-Main.mesh");
  mEntity = mSceneMgr->createEntity("Zombie" + std::to_string(_id), "creature_northrendghoul2_northrendghoul2.mesh");
  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(mNodeName, mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(1.7f, 1.7f, 1.7f);
}

void Zombie::launchScript(Ogre::SceneManager *mSceneMgr, GameObject *target, const Ogre::FrameEvent& fe)
{
  /*mSceneMgr->getSceneNode(mNodeName)->translate(
    mScript->ZombieScript(mSceneMgr->getSceneNode(mNodeName), target) * fe.timeSinceLastFrame,
    Ogre::Node::TS_LOCAL);*/
  Ogre::Vector3 move = mScript->ZombieScript(this, target);

  if (move == Ogre::Vector3::ZERO){
    this->launchAnimation(fe, IDLE);
    mAnimationState = this->mAnimation->getAnimationState();
  }
  else if (move.x == 1){
    this->launchAnimation(fe, ATTACK);
    mAnimationState = this->mAnimation->getAnimationState();
  }
  else
    {
      this->launchAnimation(fe, RUN);
      mAnimationState = this->mAnimation->getAnimationState();
      mSceneMgr->getSceneNode(mNodeName)->translate(move * fe.timeSinceLastFrame,Ogre::Node::TS_LOCAL);
    }
}

void Zombie::initScript(CollisionTools* tool)
{
  mScript->setCollision(tool, mEntity);
}

void Zombie::Animate(const Ogre::FrameEvent& fe)
{

}

void Zombie::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}
