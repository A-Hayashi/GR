#ifndef CHARACTORS_H
#define CHARACTORS_H

#include "Common.h"

class Charactors
{
public:
    typedef enum 
    {
        font_type_8x16 = 0,
        font_type_16x16,
        font_type_32x16,
        font_type_32x32,

        font_t_count
        
    } font_t;

    Charactors(void);
    void* getChar(font_t font, char index);
    void getSize(font_t font, int* width, int*height);
private:
};

#endif /* CHARACTORS_H */
