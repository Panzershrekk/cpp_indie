/*
** Pc.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Fri Jun 16 13:53:15 2017 Thomas Fossaert
*/

#ifndef		_PC_HPP_
# define	_PC_HPP_
# include	<iostream>
# include	<string>
# include	"GameObject/Character/Character.hpp"
# include	"Input/eventType.hpp"
# include "NewMOC.hpp"

class Device;

class Pc : public Character
{
public:
  Pc(const std::string &, int, int, int);
  Pc(Pc const &);
  Pc& operator=(Pc const &);
  virtual ~Pc();

  void			setDevice(Device *);
  void			setName(const std::string &);
  Device		*getDevice(void) const;
  const std::string	&getName(void) const;
  int			getSpeed(void) const;

  void		moveDown(const Ogre::FrameEvent &, Ogre::Vector3 &, Ogre::Vector3 &, CollisionTools*, Ogre::SceneManager*);
  void		moveUp(const Ogre::FrameEvent &, Ogre::Vector3 &, Ogre::Vector3 &, CollisionTools*, Ogre::SceneManager*);
  void		moveLeft(const Ogre::FrameEvent &, Ogre::Vector3 &, Ogre::Vector3 &, CollisionTools*, Ogre::SceneManager*);
  void		moveRight(const Ogre::FrameEvent &, Ogre::Vector3 &, Ogre::Vector3 &, CollisionTools*, Ogre::SceneManager*);

private:
  std::string						_name;
public:
  std::map<eventType, std::function<void(const Ogre::FrameEvent &, Ogre::Vector3 &, Ogre::Vector3 &, CollisionTools*, Ogre::SceneManager*)> >	_event;
};

#endif
