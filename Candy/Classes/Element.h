//
//  Element.h
//  Candy
//
//  Created by admin on 14-12-23.
//
//

#ifndef __CANDY__ELEMENT__
#define __CANDY__ELEMENT__
#include "cocos2d.h"

class Element : public cocos2d::CCSprite
{
    public:
        virtual ~Element();
        static Element * create(unsigned int color, unsigned int row, unsigned int col);
        inline unsigned int getColor() const {return m_color;}
        inline unsigned int getRow() const {return m_row;}
        inline unsigned int getCol() const {return m_col;}
    
    private:
        Element(unsigned int color, unsigned int row, unsigned int col);
        Element(const Element & e);
        Element & operator = (const Element & e);
    
    private:
        unsigned int m_color;
        unsigned int m_row;
        unsigned int m_col;
};

#endif /* defined(__Candy__Element__) */
