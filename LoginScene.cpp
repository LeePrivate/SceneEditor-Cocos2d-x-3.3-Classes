#include "LoginScene.h"
#include "Button/CommonButton.h"

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
	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height - 50));
	this->addChild(label, 1);

	//��������;
	auto sprite = Sprite::create("LoginBG.jpg");

	// ���þ�������;
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);

	//���ò˵�;
	LoginMenu* loginMenu = LoginMenu::create();
	loginMenu->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
	this->addChild(loginMenu);

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

/*-----------------------------------------------------------------------------------------------------LoginMenu-----------------------------------------------------------------------*/

cocos2d::ui::Button* LoginMenu::createStartButton()
{
	//����һ��UI Button;
	ui::Button* pStartButton = ui::Button::create("UIButton\\BlueButton.png", "UIButton\\Login_BT_S.png");
	//��������;
	pStartButton->setTitleText("Start");
	//��������;
	pStartButton->setTitleFontName("fonts/HKHBT_W12_0.TTC");
	//���������С;
	pStartButton->setTitleFontSize(48);
	//����������ɫ;
	pStartButton->setTitleColor(Color3B::BLACK);

	//����buttonλ��;
	//Size size = Director::getInstance()->getVisibleSize();
	//pStartButton->setPosition(Vec2(size.width / 2, size.height / 2 + 80));

	//�õ�title����Ⱦ��Ҳ���� Lable, ���˲��������ֵ�λ�����ⶼ��������������;
	//�����Ҫ�����ֵ�λ��,��Ҫ�Լ�ʵ��,�����Ǽ̳л����Լ�дһ�������button �� label ����;
	/*Label* lable = pStartButton->getTitleRenderer();*/



	//�������������������ô���ɵ�Buttonͼ�ͻᰴ�����õ�ContentSize���Զ�����(ע��ͼƬֻ�ܴ�С�Ŵ�);
	//btn->setScale9Enabled(true);

	//btn->setContentSize(Vec2(200,30));

	return pStartButton;
}

cocos2d::ui::Button* LoginMenu::createFunButton()
{
	ui::Button* pStartButton = ui::Button::create("UIButton\\BlueButton.png", "UIButton\\Login_BT_S.png");
	pStartButton->setTitleText("Fun");
	pStartButton->setTitleFontName("fonts/HKHBT_W12_0.TTC");
	pStartButton->setTitleFontSize(48);
	pStartButton->setTitleColor(Color3B::BLACK);
	
	return pStartButton;
}

cocos2d::ui::Button* LoginMenu::createOtherButton()
{
	ui::Button* pStartButton = ui::Button::create("UIButton\\BlueButton.png", "UIButton\\Login_BT_S.png");
	pStartButton->setTitleText("Other");
	pStartButton->setTitleFontName("fonts/HKHBT_W12_0.TTC");
	pStartButton->setTitleFontSize(48);
	pStartButton->setTitleColor(Color3B::BLACK);

	return pStartButton;
}

bool LoginMenu::init()
{
	/*����Ҫ��ʼ�������;*/
	if (!Layer::init())
	{
		return false;
	}
	ui::Button* startBtn = createStartButton();
	
	ui::Button* funBtn = createFunButton();
	
	ui::Button* otherBtn = createOtherButton();
	
	startBtn->setPositionY(160);
	funBtn->setPositionY(80);
	otherBtn->setPositionY(0);

	addChild(startBtn);
	addChild(funBtn);
	addChild(otherBtn);

	return true;
}
