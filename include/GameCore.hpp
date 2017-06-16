/*
** GameCore.hpp for Gauntlet
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 14 11:07:10 2017 Guillaume CAUCHOIS
** Last update Thu Jun 15 10:42:53 2017 Thomas Fossaert
*/

#ifndef		_GAME_CORE__HPP_
#define		_GAME_CORE__HPP_

# include <Terrain/OgreTerrain.h>
# include <Terrain/OgreTerrainGroup.h>
# include <vector>
# include "BaseGauntlet.hpp"
# include "Position.hpp"
# include "Animation.hpp"
# include "Audio/Music.hpp"
//# include "GameObject/Character/Script.hpp"
# include "GameObject/Character/Npc/Zombie.hpp"
# include "GameObject/Character/Npc/Skeleton.hpp"
# include "GameObject/Doodad/Doodad.hpp"
# include "MapManager.hpp"

class GameCore : public BaseGauntlet
{
  public:
    GameCore();
    virtual ~GameCore();

    void		setCurrMusicName(std::string);
    std::string		getCurrMusicName() const;

  protected:
    virtual void createScene(void);
    virtual bool frameRenderingQueued(const Ogre::FrameEvent &evt);
    virtual bool processUnbufferedInput(const Ogre::FrameEvent& fe);

    std::unordered_map<std::string, Music *>	_mmusic;
    std::string					_currentMusic;
    Ogre::AnimationState			*mAnimationState;
    Ogre::AnimationState			*mAnimationStateZombie;
    Ogre::Entity				*mEntity;
    Ogre::Entity				*mZombieEnt;
    Animation					*_animation;
    Ogre::SceneNode				*mNode;
    Ogre::SceneNode				*mZombie;
    Position					*mPosition;
    MapManager					*map;
    GameObject					*warrior;
};

#endif			/* !_GAME_CORE__HPP_! */
