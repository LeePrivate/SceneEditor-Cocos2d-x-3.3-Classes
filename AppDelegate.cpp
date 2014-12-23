#include "AppDelegate.h"
#include "LoginScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("Scene Editor");
		
		
        director->setOpenGLView(glview);
    }
	/*��Ļ����;
	��1��kResolutionNoBorder��������Ļ�Ĳ��ֻᱻ�ü�������û�кڱߣ�������Ļ����ͼƬԭʼ������ʾ��ͼƬ������(������!)��
	��2��kResolutionShowAll��������Ϸ�����ǿɼ��ģ��ᰴԭʼ�����������ţ�ͼƬ�����Σ���������ܻ����кڱߣ���������Ļ��
	��3��kResolutionExactFit��������Ϸ�����ǿɼ��ģ�ͼƬ���ܻ�����������ѹ������������Ļ��ͼƬ����Ρ�
	 ( 4 )kResolutionFixedHeight (�����,������);
     ( 5 )kResolutionFixedWidth(�����,������);*/
	//glview->setDesignResolutionSize(1024, 768, kResolutionNoBorder);

	//�õ���Ļ�ߴ�;
	//const Size& winSize = director->getWinSize();
	

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = LoginScene::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
