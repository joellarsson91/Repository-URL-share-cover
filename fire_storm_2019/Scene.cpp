#include "Scene.h"

namespace fs19 {


	Scene::Scene()  {

	}



	Scene::~Scene() {
		spriteList.clear();
	}

	void Scene::addSprites(Sprite* s) {
		spriteList.push_back(s);
	}



}

