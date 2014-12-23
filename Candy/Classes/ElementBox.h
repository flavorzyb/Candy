//
//  ElementBox.h
//  Candy
//
//  Created by admin on 14-12-23.
//
//

#ifndef __CANDY__ELEMENTBOX__
#define __CANDY__ELEMENTBOX__
#include "cocos2d.h"

class ElementBox : public cocos2d::CCLayer
{
    public:
        virtual ~ElementBox();
        static ElementBox * create(unsigned int rows = DEFAULT_ROWS, unsigned int cols = DEFAULT_COLS);
        inline unsigned int getRows() const {return m_rows;}
        inline unsigned int getCols() const {return m_cols;}
    
    private:
        ElementBox(unsigned int rows, unsigned int cols);
        ElementBox(const ElementBox & eb);
        ElementBox & operator = (const ElementBox & eb);
    
    private:
        static const unsigned int DEFAULT_ROWS;
        static const unsigned int DEFAULT_COLS;
    
    private:
        unsigned int m_rows;
        unsigned int m_cols;
    
};
#endif /* defined(__Candy__ElementBox__) */
