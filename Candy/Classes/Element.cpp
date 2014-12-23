//
//  Element.cpp
//  Candy
//
//  Created by admin on 14-12-23.
//
//

#include "Element.h"
USING_NS_CC;

unsigned int Element::s_width = 0;
unsigned int Element::s_height = 0;

Element::Element(unsigned int color, unsigned int row, unsigned int col):
      CCSprite()
    , m_color(color)
    , m_row(row)
    , m_col(col)
{
}

Element::~Element()
{
}

static char s_frameName[256] = {0};

static char s_frameNameFormat[] =  "element%d.png";

Element * Element::create(unsigned int color, unsigned int row, unsigned int col)
{
    sprintf(s_frameName, s_frameNameFormat, color);
    
    CCSpriteFrame * frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(s_frameName);
    if (frame == NULL)
    {
        return NULL;
    }
    
    Element * result = new Element(color, row, col);
    
    if (result && result->initWithSpriteFrame(frame))
    {
        result->autorelease();
        return result;
    }
    
    delete result;
    
    return NULL;
}

void Element::setWidth(unsigned int width)
{
    s_width = width;
}

void Element::setHeight(unsigned int height)
{
    s_height = height;
}