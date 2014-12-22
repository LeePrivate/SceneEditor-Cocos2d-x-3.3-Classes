#include "LoginScene.h"

USING_NS_CC;

Scene* LoginScene::createScene()
{
	/*��������;*/
	auto scene = Scene::create();

	/*��������,�����Ǽ̳���Layer;*/
	auto layer =  LoginScene::create();

	/*��������뵽������;*/
	scene->addChild(layer);

	/*���س���;*/
	return scene;
}

bool LoginScene::init()
{
	/*����Ҫ��ʼ�������;*/
	if (!Layer::init())
	{
		return false;
	}

	//�����رհ�ťImage�ͻص�;
	MenuItemImage* pCloseItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(LoginScene::menuCloseCallback, this));

	//�õ�������Ļ��Size;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//�õ�������Ļ��origin;
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//����closeItem������;
	pCloseItem->setPosition(Vec2(origin.x + visibleSize.width - pCloseItem->getContentSize().width / 2, origin.y + pCloseItem->getContentSize().height / 2));
	//����һ��Menu,����closeItem;
	auto menu = Menu::create(pCloseItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	//��������Lable;
	auto label = Label::createWithTTF("Welcome to use scene editor !", "fonts/HKHBT_W12_0.TTC", 48);
	label->setColor(Color3B::BLACK);

	// ����lable����;
	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

	//��������;
	auto sprite = Sprite::create("LoginBG.jpg");

	// ���þ�������;
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite, 0);

	return true;
}

void LoginScene::menuCloseCallback(cocos2d::Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
		MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
		return;
#endif

		Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		exit(0);
#endif
}

