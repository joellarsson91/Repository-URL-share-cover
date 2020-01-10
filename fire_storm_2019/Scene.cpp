#include "Scene.h"

namespace fs19 {


	Scene::Scene()  {

	}



	Scene::~Scene() {
		for (Sprite* s : spriteList) {
			delete[] s;
		}
	}

	void Scene::addSprites(Sprite* s) {
		spriteList.push_back(s);
	}



}

