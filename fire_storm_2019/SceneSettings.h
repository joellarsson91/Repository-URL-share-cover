#ifndef SCENESETTINGS_H
#define SCENESETTINGS_H
#include "Scene.h"

namespace fs19 {
	//b�rjat planka fr�n Scene0, kanske �r helt fel?
	class SceneSettings : public Scene
	{

	public:

		SceneSettings();
		~SceneSettings();

		void populateSpriteList();

};
}

#endif