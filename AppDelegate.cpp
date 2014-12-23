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
	/*屏幕适配;
	（1）kResolutionNoBorder：超出屏幕的部分会被裁剪，两侧没有黑边，铺满屏幕，按图片原始比例显示，图片不变形(适配宽度!)。
	（2）kResolutionShowAll：整个游戏界面是可见的，会按原始比例进行缩放，图片不变形，但两侧可能会留有黑边，不铺满屏幕。
	（3）kResolutionExactFit：整个游戏界面是可见的，图片可能会进行拉伸或者压缩处理，铺满屏幕，图片会变形。
	 ( 4 )kResolutionFixedHeight (适配高,不变形);
     ( 5 )kResolutionFixedWidth(适配宽,不变形);*/
	//glview->setDesignResolutionSize(1024, 768, kResolutionNoBorder);

	//得到屏幕尺寸;
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
