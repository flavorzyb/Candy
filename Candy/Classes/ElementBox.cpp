//
//  ElementBox.cpp
//  Candy
//
//  Created by admin on 14-12-23.
//
//

#include "ElementBox.h"
#include "Element.h"
USING_NS_CC;

const unsigned int ElementBox::DEFAULT_ROWS = 5;
const unsigned int ElementBox::DEFAULT_COLS = 6;

ElementBox::ElementBox(unsigned int rows, unsigned int cols):
      CCLayer()
    , m_rows(rows)
    , m_cols(cols)
    , m_elementArray(NULL)
{
    m_elementArray = CCArray::create();
    m_elementArray->retain();
}

ElementBox::~ElementBox()
{
    m_elementArray->release();
}

ElementBox * ElementBox::create(unsigned int rows, unsigned int cols)
{
    ElementBox * result = new ElementBox(rows, cols);
    if (result && result->init())
    {
        result->setTouchEnabled(true);
        result->setTouchMode(kCCTouchesOneByOne);
        result->autorelease();
        return result;
    }
    
    delete result;
    
    return NULL;
}

bool ElementBox::initElement()
{
    if ((m_rows < 1) || (m_cols < 1))
    {
        return false;
    }
    
    unsigned int w = Element::getWidth();
    unsigned int h = Element::getHeight();
    
    for (int x = 0; x < m_rows; x++)
    {
        for (int y = 0; y < m_cols; y++)
        {
            Element * e = Element::create((x*m_cols + y) % 4, x, y);
            e->setPosition(ccp(x * w, y*h));
            m_elementArray->addObject(e);
            addChild(e);
        }
    }
    
    setContentSize(ccp(m_rows*w, m_cols * h));
    
    return true;
}

bool ElementBox::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCPoint pt = convertToNodeSpace(pTouch->getLocation());
    CCRect rect(0, 0, getContentSize().width, getContentSize().height);
    if (!rect.containsPoint(pt))
    {
        return false;
    }
    
    CCObject * pOb = NULL;
    Element * e = NULL;
    CCARRAY_FOREACH(m_elementArray, pOb)
    {
        e = (Element *) pOb;
        if (e != NULL)
        {
            
        }
    }
    
    CCLOG("touch...................");
    return true;
}

void ElementBox::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    
}

void ElementBox::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
}

void ElementBox::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
}
