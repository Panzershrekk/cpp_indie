/*
** Doodad.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
// Last update Mon Jun 12 09:09:21 2017 Thomas Fossaert
*/

#include "GameObject/Doodad/Doodad.hpp"

Doodad::Doodad(int x, int y, int z, int id, int Sx, int Sy, int Sz, const std::string &deco) : GameObject(x, y, z)
{
  this->_id = id;
  this->_Sx = Sx;
  this->_Sy = Sy;
  this->_Sz = Sz;
  this->_deco = deco;
  mPosition = new Position(x, y, z);
  mNodeName = "DoodadNode" + std::to_string(id);
}

Doodad::Doodad(Doodad const & other) : GameObject(other)
{
  this->_id = other._id;
}

Doodad& Doodad::operator=(Doodad const & other)
{
  this->_id = other._id;
  return *this;
}

Doodad::~Doodad() {}

void	Doodad::setOgreBase(Ogre::SceneManager* mSceneMgr)
{
  mEntity = mSceneMgr->createEntity("Doodad" + std::to_string(_id), _deco);

  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(mNodeName, mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(this->_Sx, this->_Sy, this->_Sz);
  mNode->setOrientation(0, 0, 0, 0);
  if (_deco == "cube.mesh")
    mEntity->setMaterialName("Examples/Rocky");
}