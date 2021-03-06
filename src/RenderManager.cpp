/*
** RenderManager.cpp for Gauntlet
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 07 13:36:28 2017 Guillaume CAUCHOIS
// Last update Thu Jun 15 20:52:35 2017 Thomas Fossaert
*/

#include "RenderManager.hpp"

/*****************************************************************************/
RenderManager::RenderManager()
{
  this->_factory["DOODAD"]	= std::bind(&RenderManager::createDoodadObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
  this->_factory["BOSS"]	= std::bind(&RenderManager::createBossObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
  this->_factory["SKELETON"]	= std::bind(&RenderManager::createSkeletonObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
  this->_factory["ZOMBIE"]	= std::bind(&RenderManager::createZombieObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
  this->_factory["SPAWNER"]	= std::bind(&RenderManager::createSpawnerObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
  this->_factory["FOOD"]	= std::bind(&RenderManager::createFoodObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
  this->_factory["GOLD"]	= std::bind(&RenderManager::createGoldObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
  this->_factory["KEY"]		= std::bind(&RenderManager::createKeyObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
  this->_factory["MAGE"]	= std::bind(&RenderManager::createMageObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
  this->_factory["WARRIOR"]	= std::bind(&RenderManager::createWarriorObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
  this->_factory["TANK"]	= std::bind(&RenderManager::createTankObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
  this->_factory["ARCHER"]	= std::bind(&RenderManager::createArcherObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
  this->_factory["GATE"]	= std::bind(&RenderManager::createGateObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
}

RenderManager::~RenderManager()
{
  for (auto it = this->_entities.begin(); it != this->_entities.end(); ++it)
    delete *it;
}

/*****************************************************************************/

/**
 * GameObject Factory Creation
 * @return GameObject*
 */
GameObject	*RenderManager::createGameObject(const std::string &type, const Position &pos, const Position &scale, const Ogre::Quaternion &orientation, const std::string &texture)
{
  static int	i = 1;
  GameObject	*gObj;

  if (this->_factory.find(type) == this->_factory.end())
    throw IndieException("Cannot generate the GameObject from type \"" + type + "\"");
  gObj = this->_factory[type](i++, pos, scale, orientation, texture);
  if (gObj)
    this->_entities.push_back(gObj);
  else
    throw IndieException("Cannot generate the GameObject");
  return (gObj);
}

/******************************************************************************
 * Create Unit GameObject
 * @param id
 * @param position
 * @param scale
 * @param texture
 * @return GameObject
 */
GameObject	*RenderManager::createDoodadObject(int id, const Position &position, const Position &scale, const Ogre::Quaternion &orientation, const std::string &texture)
{
  return (new Doodad(position.getXPosition(), position.getYPosition(), position.getZPosition(), id, scale.getXPosition(), scale.getYPosition(), scale.getZPosition(), orientation, texture));
}

GameObject	*RenderManager::createBossObject(int id, const Position &position, const Position &, const Ogre::Quaternion &, const std::string &)
{
  return (new Boss(position.getXPosition(), position.getYPosition(), position.getZPosition(), id));
}

GameObject	*RenderManager::createSkeletonObject(int id, const Position &position, const Position &, const Ogre::Quaternion &, const std::string &)
{
  return (new Skeleton(position.getXPosition(), position.getYPosition(), position.getZPosition(), id));
}

GameObject	*RenderManager::createZombieObject(int id, const Position &position, const Position &, const Ogre::Quaternion &, const std::string &)
{
  return (new Zombie(position.getXPosition(), position.getYPosition(), position.getZPosition(), id));
}

GameObject	*RenderManager::createSpawnerObject(int id, const Position &position, const Position &, const Ogre::Quaternion &, const std::string &)
{
  return (new Spawner(position.getXPosition(), position.getYPosition(), position.getZPosition(), id));
}

GameObject	*RenderManager::createFoodObject(int id, const Position &position, const Position &, const Ogre::Quaternion &, const std::string &)
{
  return (new foodStack(position.getXPosition(), position.getYPosition(), position.getZPosition(), id));
}

GameObject	*RenderManager::createGoldObject(int id, const Position &position, const Position &, const Ogre::Quaternion &, const std::string &)
{
  return (new goldStack(position.getXPosition(), position.getYPosition(), position.getZPosition(), id));
}

GameObject	*RenderManager::createGateObject(int id, const Position &position, const Position &, const Ogre::Quaternion &, const std::string &)
{
  return (new gate(position.getXPosition(), position.getYPosition(), position.getZPosition(), id));
}

GameObject	*RenderManager::createKeyObject(int id, const Position &position, const Position &, const Ogre::Quaternion &, const std::string &)
{
  return (new key(position.getXPosition(), position.getYPosition(), position.getZPosition(), id));
}

GameObject	*RenderManager::createWarriorObject(int id, const Position &position, const Position &, const Ogre::Quaternion &, const std::string &)
{
  return (new Warrior("Warrior", position.getXPosition(), position.getYPosition(), position.getZPosition()));
}

GameObject	*RenderManager::createMageObject(int id, const Position &position, const Position &, const Ogre::Quaternion &, const std::string &)
{
  return (new Mage("Mage", position.getXPosition(), position.getYPosition(), position.getZPosition()));

}

GameObject	*RenderManager::createArcherObject(int id, const Position &position, const Position &, const Ogre::Quaternion &, const std::string &)
{
  return (new Archer("Archer", position.getXPosition(), position.getYPosition(), position.getZPosition()));

}

GameObject	*RenderManager::createTankObject(int id, const Position &position, const Position &, const Ogre::Quaternion &, const std::string &)
{
  return (new Tank("Tank", position.getXPosition(), position.getYPosition(), position.getZPosition()));
}

/* Entities utils */
std::vector<GameObject *>	&RenderManager::getEntitiesVector(void)
{
  return (this->_entities);
}

GameObject* RenderManager::searchEntities(const std::string & search)
{
  for (auto &it :this->_entities)
    {
      if (!search.compare(it->getEntity()->getName()))
        return (it);
    }
  return (nullptr);
}

void RenderManager::eraseEntities(GameObject *obj)
{
  int i = 0;

  for (auto &it :this->_entities)
    {
      if (it == obj)
        this->_entities.erase(this->_entities.begin() + i);
      i++;
    }
}
