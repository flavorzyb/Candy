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
        inline unsigned int getColor() const {return m_color;}
        inline unsigned int getRow() const {return m_row;}
        inline unsigned int getCol() const {return m_col;}
    
    public:
        static Element * create(unsigned int color, unsigned int row, unsigned int col);
        static void setWidth(unsigned int width);
        static void setHeight(unsigned int height);
        static inline unsigned int getWidth() {return s_width;}
        static inline unsigned int getHeight() {return s_height;}
    
    private:
        Element(unsigned int color, unsigned int row, unsigned int col);
        Element(const Element & e);
        Element & operator = (const Element & e);
    
    private:
        static unsigned int s_width;
        static unsigned int s_height;
    
    private:
        unsigned int m_color;
        unsigned int m_row;
        unsigned int m_col;
};

#endif /* defined(__Candy__Element__) */
