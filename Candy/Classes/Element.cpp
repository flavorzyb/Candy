//
//  Element.cpp
//  Candy
//
//  Created by admin on 14-12-23.
//
//

#include "Element.h"
USING_NS_CC;

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

Element * Element::create(unsigned int color, unsigned int row, unsigned int col)
{
    Element * result = new Element(color, row, col);
    if (result && result->init())
    {
        result->autorelease();
        return result;
    }
    
    delete result;
    
    return NULL;
}
