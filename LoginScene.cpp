#include "LoginScene.h"
#include "Button/CommonButton.h"

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
	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height - 50));
	this->addChild(label, 1);

	//创建精灵;
	auto sprite = Sprite::create("LoginBG.jpg");

	// 设置精灵坐标;
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);

	//设置菜单;
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
	//创建一个UI Button;
	ui::Button* pStartButton = ui::Button::create("UIButton\\BlueButton.png", "UIButton\\Login_BT_S.png");
	//设置文字;
	pStartButton->setTitleText("Start");
	//设置字体;
	pStartButton->setTitleFontName("fonts/HKHBT_W12_0.TTC");
	//设置字体大小;
	pStartButton->setTitleFontSize(48);
	//设置字体颜色;
	pStartButton->setTitleColor(Color3B::BLACK);

	//设置button位置;
	//Size size = Director::getInstance()->getVisibleSize();
	//pStartButton->setPosition(Vec2(size.width / 2, size.height / 2 + 80));

	//得到title的渲染器也就是 Lable, 除了不能设置字的位置以外都可以在这里设置;
	//如果需要设置字的位置,需要自己实现,不管是继承还是自己写一个类包含button 和 label 都行;
	/*Label* lable = pStartButton->getTitleRenderer();*/



	//如果给上这两个函数那么生成的Button图就会按照设置的ContentSize来自动缩放(注意图片只能从小放大);
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
	/*总是要初始化父类层;*/
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
