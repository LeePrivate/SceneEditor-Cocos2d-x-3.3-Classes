#pragma once

#include "cocos2d.h"

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

