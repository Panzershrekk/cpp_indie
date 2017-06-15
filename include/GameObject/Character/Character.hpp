/*
** Character.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Thu Jun 15 14:31:35 2017 Thomas Fossaert
*/

#ifndef		_CHARACTER_HPP_
# define	_CHARACTER_HPP_

# include "GameObject/GameObject.hpp"

class Character : public GameObject
{
public:
  Character(int x, int y, int z);
  Character(Character const &);
  Character& operator=(Character const &);
  virtual ~Character();

  void  setScore(int);
  void  gainHealth(int);

protected:
  enum State
  {
    IDLE,
    STAND,
    RUN,
    WALK,
    ATTACK,
    DIE
  };

  int		_health;
  int		_attack;
  int		_cooldown;
  int		_speed;
  int		_range;
  int   _score;
  State	_state;
  std::map<State, Animation*>	_animations;
  Animation* _currentAnimation;

  /* Classes */

  void launchAnimation(const Ogre::FrameEvent& fe, State state);
  void		takeDamage(int dmg);
  void		attack(Character *target);
  bool		isAlive() const;
  void		getDistance() const;
  int		getRange(void) const;

  /*virtual void		setOgreBase(Ogre::SceneManager*);
  virtual Ogre::Vector3	launchScript(Ogre::SceneNode *);
  virtual void		Animate(const Ogre::FrameEvent&);*/
};

#endif
