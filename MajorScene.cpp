#include "MajorScene.h"

USING_NS_CC;

Scene* MajorScene::createScene()
{
	/*创建场景;*/
	auto scene = Scene::create();

	/*创建本类,本类是继承于Layer;*/
	auto layer = MajorScene::create();

	/*将本类加入到场景中;*/
	scene->addChild(layer);

	/*返回场景;*/
	return scene;
}

bool MajorScene::init()
{
	/*总是要初始化父类层;*/
	if (!Layer::init())
	{
		return false;
	}
	//Todo :

	return true;
}

