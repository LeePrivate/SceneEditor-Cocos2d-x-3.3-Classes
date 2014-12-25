#pragma once

#include "cocos2d.h"
#include "cocos-ext.h"
#include "ui/CocosGUI.h"

class MajorScene : public cocos2d::Layer
{
public:
	virtual bool init();

	/*��������,�ͱ����,���������볡����,�����س���,�л�������ʱ��ҲҪ�����������;*/
	static cocos2d::Scene* createScene();

	/*��̬����,����һ��LoginScene�෵��ָ��,���Զ�����init;*/
	CREATE_FUNC(MajorScene);

protected:
	cocos2d::ui::Button*  createChangeSceneButton();

	void changeScene(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);

};

