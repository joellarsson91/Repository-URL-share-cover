#ifndef SCENESETTINGS_H
#define SCENESETTINGS_H
#include "Scene.h"

namespace fs19 {
	//börjat planka från Scene0, kanske är helt fel?
	class SceneSettings : public Scene
	{

	public:

		SceneSettings();
		~SceneSettings();

		void populateSpriteList();

};
}

#endif