//
//  ElementBox.cpp
//  Candy
//
//  Created by admin on 14-12-23.
//
//

#include "ElementBox.h"

USING_NS_CC;

const unsigned int ElementBox::DEFAULT_ROWS = 5;
const unsigned int ElementBox::DEFAULT_COLS = 6;

ElementBox::ElementBox(unsigned int rows, unsigned int cols):
      CCLayer()
    , m_rows(rows)
    , m_cols(cols)
{
}

ElementBox::~ElementBox()
{
}

ElementBox * ElementBox::create(unsigned int rows, unsigned int cols)
{
    ElementBox * result = new ElementBox(rows, cols);
    if (result && result->init())
    {
        result->autorelease();
        return result;
    }
    
    delete result;
    
    return NULL;
}
