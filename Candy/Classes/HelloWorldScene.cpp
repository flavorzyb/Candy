#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "ElementBox.h"
#include "Element.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCLayerColor * layer = CCLayerColor::create(ccc4(250, 150, 250, 255), winSize.width, winSize.height);
    addChild(layer);

    // add elment list texutre
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("element_list.plist");
    
    Element::setWidth(102);
    Element::setHeight(102);
    
    ElementBox * eb = ElementBox::create();
    eb->initElement();
    eb->setAnchorPoint(ccp(0,0));
    eb->setPosition(ccp((winSize.width - eb->getContentSize().width) /2 , (winSize.height - eb->getContentSize().height) /2));
    addChild(eb);
    
    return true;
}