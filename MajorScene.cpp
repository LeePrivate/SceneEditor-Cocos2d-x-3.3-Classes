#include "MajorScene.h"

USING_NS_CC;

Scene* MajorScene::createScene()
{
	/*��������;*/
	auto scene = Scene::create();

	/*��������,�����Ǽ̳���Layer;*/
	auto layer = MajorScene::create();

	/*��������뵽������;*/
	scene->addChild(layer);

	/*���س���;*/
	return scene;
}

bool MajorScene::init()
{
	/*����Ҫ��ʼ�������;*/
	if (!Layer::init())
	{
		return false;
	}
	//Todo :

	return true;
}

