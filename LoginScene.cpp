#include "LoginScene.h"

USING_NS_CC;

Scene* LoginScene::createScene()
{
	/*创建场景;*/
	auto scene = Scene::create();

	/*创建本类,本类是继承于Layer;*/
	auto layer =  LoginScene::create();

	/*将本类加入到场景中;*/
	scene->addChild(layer);

	/*返回场景;*/
	return scene;
}

bool LoginScene::init()
{
	/*总是要初始化父类层;*/
	if (!Layer::init())
	{
		return false;
	}

	//创建关闭按钮Image和回调;
	MenuItemImage* pCloseItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(LoginScene::menuCloseCallback, this));

	//得到整个屏幕的Size;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//得到整个屏幕的origin;
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//设置closeItem的坐标;
	pCloseItem->setPosition(Vec2(origin.x + visibleSize.width - pCloseItem->getContentSize().width / 2, origin.y + pCloseItem->getContentSize().height / 2));
	//设置一个Menu,包含closeItem;
	auto menu = Menu::create(pCloseItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	//创建文字Lable;
	auto label = Label::createWithTTF("Welcome to use scene editor !", "fonts/HKHBT_W12_0.TTC", 48);
	label->setColor(Color3B::BLACK);

	// 设置lable坐标;
	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

	//创建精灵;
	auto sprite = Sprite::create("LoginBG.jpg");

	// 设置精灵坐标;
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

