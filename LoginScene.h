#pragma once

#include "Config.h"


class LoginScene : public cocos2d::Layer
{
public:
	virtual bool init();

	/*创建场景,和本类层,将本类层加入场景中,并返回场景;*/
	static cocos2d::Scene* createScene();

	/*关闭按钮的回调函数;*/
	void menuCloseCallback(cocos2d::Ref* pSender);

	/*静态方法,创建一个LoginScene类返回指针,会自动调用init;*/
	CREATE_FUNC(LoginScene);
};

class LoginMenu : public  cocos2d::Layer
{
public:
	//重写inti();
	virtual bool init() override;

	CREATE_FUNC(LoginMenu);

protected:
	//Start 按钮;
	cocos2d::ui::Button* createStartButton();
	//Fun 按钮;
	cocos2d::ui::Button* createFunButton();
	//Other 按钮;
	cocos2d::ui::Button* createOtherButton();
};