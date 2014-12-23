#pragma once

#include "Config.h"


class LoginScene : public cocos2d::Layer
{
public:
	virtual bool init();

	/*��������,�ͱ����,���������볡����,�����س���;*/
	static cocos2d::Scene* createScene();

	/*�رհ�ť�Ļص�����;*/
	void menuCloseCallback(cocos2d::Ref* pSender);

	/*��̬����,����һ��LoginScene�෵��ָ��,���Զ�����init;*/
	CREATE_FUNC(LoginScene);
};

class LoginMenu : public  cocos2d::Layer
{
public:
	//��дinti();
	virtual bool init() override;

	CREATE_FUNC(LoginMenu);

protected:
	//Start ��ť;
	cocos2d::ui::Button* createStartButton();
	//Fun ��ť;
	cocos2d::ui::Button* createFunButton();
	//Other ��ť;
	cocos2d::ui::Button* createOtherButton();
};