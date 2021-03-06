#pragma once

#include "cocos2d.h"
#include "cocos-ext.h"
#include "ui/CocosGUI.h"

class MajorScene : public cocos2d::Layer
{
public:
	virtual bool init();

	/*创建场景,和本类层,将本类层加入场景中,并返回场景,切换场景的时候也要调用这个函数;*/
	static cocos2d::Scene* createScene();

	/*静态方法,创建一个LoginScene类返回指针,会自动调用init;*/
	CREATE_FUNC(MajorScene);

protected:
	cocos2d::ui::Button*  createChangeSceneButton();

	void changeScene(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);

};

