#pragma once

#include "cocos2d.h"

class MajorScene : public cocos2d::Layer
{
public:
	virtual bool init();

	/*��������,�ͱ����,���������볡����,�����س���;*/
	static cocos2d::Scene* createScene();

	/*��̬����,����һ��LoginScene�෵��ָ��,���Զ�����init;*/
	CREATE_FUNC(MajorScene);
};