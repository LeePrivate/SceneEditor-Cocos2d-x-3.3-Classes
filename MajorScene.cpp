#include "MajorScene.h"
#include "LoginScene.h"

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

	//得到整个屏幕的Size;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//得到整个屏幕的origin;
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//创建文字Lable;
	auto label = Label::createWithTTF("Welcome to use scene editor second scene!", "fonts/HKHBT_W12_0.TTC", 48);
	label->setColor(Color3B::BLACK);

	// 设置lable坐标;
	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height - 50));
	this->addChild(label, 1);

	//创建精灵;
	auto sprite = Sprite::create("LoginBG_2.jpg");

	// 设置精灵坐标;
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);

	this->addChild(createChangeSceneButton());


	return true;
}

cocos2d::ui::Button* MajorScene::createChangeSceneButton()
{
	ui::Button* pStartButton = ui::Button::create("UIButton\\BlueButton.png");
	pStartButton->setTitleText("ChangeScene");
	pStartButton->setTitleFontName("fonts/HKHBT_W12_0.TTC");
	pStartButton->setTitleFontSize(48);
	pStartButton->setTitleColor(Color3B::BLACK);

	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	pStartButton->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	
	pStartButton->addTouchEventListener(CC_CALLBACK_2(MajorScene::changeScene, this));

	return pStartButton;
}

void MajorScene::changeScene(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	/*清空缓存;*/
	Director::getInstance()->purgeCachedData();
	/*创建新的场景;*/
	Scene* pScene = LoginScene::createScene();
	/*用新场景替换旧场景,如果为了提高来回切换场景的效率可以使用 pushScene 或是 popScene;*/
	Director::getInstance()->replaceScene(pScene);
}
