#include "MajorScene.h"
#include "LoginScene.h"

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

	//�õ�������Ļ��Size;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//�õ�������Ļ��origin;
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//��������Lable;
	auto label = Label::createWithTTF("Welcome to use scene editor second scene!", "fonts/HKHBT_W12_0.TTC", 48);
	label->setColor(Color3B::BLACK);

	// ����lable����;
	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height - 50));
	this->addChild(label, 1);

	//��������;
	auto sprite = Sprite::create("LoginBG_2.jpg");

	// ���þ�������;
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
	/*��ջ���;*/
	Director::getInstance()->purgeCachedData();
	/*�����µĳ���;*/
	Scene* pScene = LoginScene::createScene();
	/*���³����滻�ɳ���,���Ϊ����������л�������Ч�ʿ���ʹ�� pushScene ���� popScene;*/
	Director::getInstance()->replaceScene(pScene);
}
