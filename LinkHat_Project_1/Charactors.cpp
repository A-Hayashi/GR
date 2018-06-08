#include "Charactors.h"


/*--------------------------*/
/*    8x16フォント          */
/*--------------------------*/
#define BIN (unsigned char)((((((((0
#define O )*2+1
#define _ )*2

const unsigned char paw8x16ascii[][16]={
/* ' ' ASCII=00H [No.0] */
{
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ 
},

/* '(' ASCII=28H [No.40] */
{
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ O O _ ,
	BIN	_ _ _ _ O O O _ ,
	BIN	_ _ _ O O O _ _ ,
	BIN	_ _ _ O O _ _ _ ,
	BIN	_ _ O O O _ _ _ ,
	BIN	_ _ O O _ _ _ _ ,
	BIN	_ _ O O _ _ _ _ ,
	BIN	_ _ O O _ _ _ _ ,
	BIN	_ _ O O _ _ _ _ ,
	BIN	_ _ O O O _ _ _ ,
	BIN	_ _ _ O O _ _ _ ,
	BIN	_ _ _ O O O _ _ ,
	BIN	_ _ _ _ O O O _ ,
	BIN	_ _ _ _ _ O O _ ,
	BIN	_ _ _ _ _ _ _ _ 
},

/* ')' ASCII=29H [No.41] */
{
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ O O _ _ _ _ ,
	BIN	_ _ O O O _ _ _ ,
	BIN	_ _ _ O O O _ _ ,
	BIN	_ _ _ _ O O _ _ ,
	BIN	_ _ _ _ O O O _ ,
	BIN	_ _ _ _ _ O O _ ,
	BIN	_ _ _ _ _ O O _ ,
	BIN	_ _ _ _ _ O O _ ,
	BIN	_ _ _ _ _ O O _ ,
	BIN	_ _ _ _ O O O _ ,
	BIN	_ _ _ _ O O _ _ ,
	BIN	_ _ _ O O O _ _ ,
	BIN	_ _ O O O _ _ _ ,
	BIN	_ _ O O _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ 
},

/* '^' ASCII=5EH [No.94] */
{
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ O O O O _ _ ,
	BIN	_ O O O O O O _ ,
	BIN	_ O O _ _ O O _ ,
	BIN	_ O _ _ _ _ O _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ 
},
/* '_' ASCII=5FH [No.95] */
{
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ ,
	BIN	_ O O _ _ _ O O ,
	BIN	_ O O O O O O O ,
	BIN	_ _ O O O O O _ ,
	BIN	_ _ _ _ _ _ _ _ 
}
};

#undef BIN
#undef O
#undef _

/*--------------------------*/
/*   16x16フォント          */
/*--------------------------*/
#define BIN (unsigned short int)((((((((((((((((0
#define O )*2+1
#define _ )*2

const unsigned short int paw16x16kanji[][16]={
/* '　' SJIS=8140H [No.0(0-0)]*/
{
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
},

/* '笑' SJIS=8FCEH [No.2773(32-78)]*/
{
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ O O _ _ _ _ _ O O _ _ _ _ _ ,
	BIN	_ _ O O O O O O _ O O O O O O _ ,
	BIN	_ O O O O O O O O O O O O O O _ ,
	BIN	_ O O _ _ O O _ O O _ _ O O _ _ ,
	BIN	_ O O _ _ O O _ O O _ _ O O _ _ ,
	BIN	_ _ O O O O O O O O O O O O _ _ ,
	BIN	_ _ O O O O O O O O O O O _ _ _ ,
	BIN	_ _ _ _ _ _ O O _ _ _ _ _ _ _ _ ,
	BIN	_ O O O O O O O O O O O O O O _ ,
	BIN	_ O O O O O O O O O O O O O O _ ,
	BIN	_ _ _ O O O _ _ _ _ O O O _ _ _ ,
	BIN	_ _ O O O _ _ _ _ _ _ O O O _ _ ,
	BIN	_ O O O _ _ _ _ _ _ _ _ O O O _ ,
	BIN	_ O O _ _ _ _ _ _ _ _ _ _ O O _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
},

/* '眠' SJIS=96B0H [No.4059(46-48)]*/
{
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ O O O O _ _ O O O O O O O _ _ ,
	BIN	_ O O O O O _ O O O O O O O O _ ,
	BIN	_ O O _ O O _ O O _ _ _ _ O O _ ,
	BIN	_ O O _ O O _ O O _ _ _ _ O O _ ,
	BIN	_ O O O O O _ O O O O O O O O _ ,
	BIN	_ O O O O O _ O O O O O O O O _ ,
	BIN	_ O O _ O O _ O O _ _ O O _ _ _ ,
	BIN	_ O O _ O O _ O O O O O O O O _ ,
	BIN	_ O O O O O _ O O O O O O O O _ ,
	BIN	_ O O O O O _ O O _ _ _ O O _ _ ,
	BIN	_ O O _ O O _ O O _ _ _ O O _ _ ,
	BIN	_ O O _ O O _ O O _ _ _ _ O O _ ,
	BIN	_ O O O O O _ O O O O _ _ O O _ ,
	BIN	_ O O O O O _ _ O O O _ _ O O _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
}
};

#undef BIN
#undef O
#undef _

/*--------------------------*/
/*   32x16フォント          */
/*--------------------------*/
#define BIN (unsigned long int)((((((((((((((((((((((((((((((((0
#define O )*2+1
#define _ )*2

const unsigned long int icon_font32x16[][16]={
/* '	[[[[[ Font Data ]]]]] */
/* 空白 */
{
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
},
#ifndef USE_FONT32X32
/* いいね */
{
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ O O _ O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ O _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ O _ O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ O _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ O O _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ O O O O O _ O O O _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O O O _ _ _ _ _ O O O _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O _ _ _ _ _ _ _ _ O O O O O O O _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O O O O O O _ _ _ _ _ O _ O _ O _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ O _ _ _ O O O _ _ _ _ O _ O _ O _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ O O O O O O O O _ _ _ O _ O _ O _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ O O _ _ _ O O O _ _ _ O _ O _ O _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ O O O O O O O _ O O O O O O O _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ O O _ _ _ O O O O O _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ O O O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ 
},
/* ？ */
{
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ O O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ O O O O O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ O O O O O O O O O O O _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ O O _ _ _ _ O O O O _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O O _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
},
/* スマイル */
{
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ O O O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ O O O O O _ _ O O O O O _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ O O O O _ _ _ _ _ _ O O O O _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ O O _ _ _ _ _ _ _ _ _ _ O O _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O _ _ O O O _ _ O O O _ _ O O _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O _ _ O O O _ _ O O O _ _ O O _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ O O _ _ O O _ _ _ _ _ _ O O _ _ O O _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ O O _ _ O O _ _ _ _ _ _ O O _ _ O O _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O _ _ O O _ _ _ _ O O _ _ O O _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O O _ O O O _ _ O O O _ O O O _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ O O _ _ O O O O O O _ _ O O _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ O O O O _ _ _ _ _ _ O O O O _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ O O O O O _ _ O O O O O _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ O O O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ 
},
/* イルミ D */
{
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O 
},
/* イルミ E */
{
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
},
/* イルミ F */
{
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
},
/* イルミ G */
{
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
},
/* イルミ H */
{
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ _ _ ,
	BIN	_ _ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ _ ,
	BIN	_ _ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ _ ,
	BIN	_ _ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ _ ,
	BIN	_ _ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ _ ,
	BIN	_ _ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ _ ,
	BIN	_ _ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ _ ,
	BIN	_ _ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ _ ,
	BIN	_ _ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ _ ,
	BIN	_ _ _ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
},
/* イルミ I */
{
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ _ ,
	BIN	_ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ ,
	BIN	_ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ ,
	BIN	_ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ ,
	BIN	_ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ ,
	BIN	_ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ ,
	BIN	_ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ ,
	BIN	_ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ ,
	BIN	_ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ ,
	BIN	_ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ ,
	BIN	_ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ ,
	BIN	_ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ ,
	BIN	_ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ ,
	BIN	_ _ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
},
/* イルミ J */
{
	BIN	_ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ ,
	BIN	_ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ ,
	BIN	_ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ ,
	BIN	_ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ ,
	BIN	O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O ,
	BIN	O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O ,
	BIN	O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O ,
	BIN	O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O ,
	BIN	O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O ,
	BIN	O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O ,
	BIN	O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O ,
	BIN	O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O ,
	BIN	_ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ ,
	BIN	_ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ ,
	BIN	_ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ ,
	BIN	_ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ 
}
#endif // USE_FONT32X32
};

/*--------------------------*/
/*   32x16フォント          */
/*--------------------------*/
#define BIN (unsigned long int)((((((((((((((((((((((((((((((((0
#define O )*2+1
#define _ )*2

const unsigned long int icon_font32x32[][32]={
/* '	[[[[[ Font Data ]]]]] */
/* 空白 */
{
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
},
#ifdef USE_FONT32X32
/* いいね */
{
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ O O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O _ O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ O O _ _ _ O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O _ _ _ O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O _ _ _ O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O O _ _ O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ O O O _ _ O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ O O O _ _ _ O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ O O O _ _ _ O O O _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ O O O _ _ _ _ O O O _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ O O O _ _ _ _ _ O O O _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ O O O O O O O O _ _ _ _ _ _ O O _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ O O O O O O _ _ _ _ _ _ _ _ _ _ O O O O _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O O O O _ _ _ _ _ ,
	BIN	_ _ O O O _ _ O O O O O O O _ _ _ _ _ _ _ _ _ _ _ O O _ _ _ _ _ ,
	BIN	_ _ O O O O O O O O _ O O O O _ _ _ _ _ _ _ _ _ _ O O O O O _ _ ,
	BIN	_ _ O O O _ _ _ _ _ _ O O O O _ _ _ _ _ _ _ _ _ _ O O O O O _ _ ,
	BIN	_ _ _ O O O O _ _ O O O O O O O _ _ _ _ _ _ _ _ _ O O O _ _ _ _ ,
	BIN	_ _ _ O O O O O O O O O _ O O O _ _ _ _ _ _ _ _ _ O O O _ _ _ _ ,
	BIN	_ _ _ O O O _ _ _ _ _ _ O O O O O _ _ _ _ _ _ _ _ O O O _ _ _ _ ,
	BIN	_ _ _ O O O O _ _ _ O O O O O O O _ _ _ _ _ _ _ _ O O O _ _ _ _ ,
	BIN	_ _ _ _ O O O O O O O O O _ O O O _ _ _ _ _ _ _ _ O O O _ _ _ _ ,
	BIN	_ _ _ _ _ O O _ _ _ _ _ _ O O O O O _ _ _ _ _ _ _ O O O O O _ _ ,
	BIN	_ _ _ _ _ O O O _ _ _ O O O O O O _ _ _ _ O O O O O O O O O _ _ ,
	BIN	_ _ _ _ _ _ O O O O O O O O _ O O O _ _ O O O _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ O O O _ _ _ _ O O O O O O O O _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ O O O O _ O O O O O O O O O _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O O O O O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
},
/* ？ */
{
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O O O O _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ O O O O O O O O O O O O O _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ O O O O O O O O O O O O O O O O _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ O O O O O O O O O O O O O O O O O O _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ O O O O O O O O O O O O O O O O O O O O _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ O O O O O O O O O O O O O O O O O O O O O _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ O O O O O O O O O _ _ _ _ _ O O O O O O O O _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ O O O O O O _ _ _ _ _ _ _ _ O O O O O O O _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ O O O O _ _ _ _ _ _ _ _ _ O O O O O O O _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O _ _ _ _ _ _ _ _ _ O O O O O O O _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O O O O O _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O O O O O O _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O O O O O O _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O O O O O _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ O O O O O O O O _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ O O O O O O O O _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ O O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ O O O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ O O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ O O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ O O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ O O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ O O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ O O O O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ O O O O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ O O O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ O O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ O O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
},
/* どぐろまーく */
{
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ O O O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ O O O O O O O O O O O O _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ O O O O O O O O O O O O _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ O O O O O O O O O O O O O O _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O O O O O O O O O O O O O O O _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O O O O O O O O O O O O O O O _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O O O O O O O O O O O O O O O _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O O O _ _ O O O O _ _ O O O O _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O O O _ _ O O O O _ _ O O O O _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O O O _ _ O O O O _ _ O O O _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ O O O O _ O O O O _ O O O _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ O O O O O O _ _ O O O O O _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ O O O O O _ _ O O O O O _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ O O O _ O O _ O O O _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ O O _ O O _ O O _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ O O O _ _ O O O _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ O O O O _ _ _ _ O O O O _ _ _ _ O O O O _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ O O O O O _ _ _ _ _ _ _ _ _ _ O O O O O _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ O O O O O O O _ _ _ _ _ _ O O O O O O O _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ O O O O O O O O O O O O O O O O O O O O O _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ O O O O O O O O O _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ O O O O O O _ _ _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ O O O O O O O O O O _ _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ O O O O O _ _ O O O O O _ _ _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ O O O O O O O _ _ _ _ O O O O O O O _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ O O O O O O O _ _ _ _ _ _ O O O O O O O _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ O O O O O O _ _ _ _ _ _ _ _ O O O O O O O _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ O O O O O O _ _ _ _ _ _ _ _ O O O O O O _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ O O O _ _ _ _ _ _ _ _ _ _ O O O _ _ _ _ _ _ _ _ ,
	BIN	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
}
#endif // USE_FONT32X32
};

#undef BIN
#undef O
#undef _


/* コンストラクタ */
Charactors::Charactors(void)
{
}

void* Charactors::getChar(font_t font, char index)
{
    void* ptr = NULL;

    switch (font)
    {
        case font_type_8x16:
          ptr = (void*)&paw8x16ascii[index];
          break;
        case font_type_16x16:
          ptr = (void*)&paw16x16kanji[index];
          break;
        case font_type_32x16:
          ptr = (void*)&icon_font32x16[index];
          break;
        case font_type_32x32:
          ptr = (void*)&icon_font32x32[index];
          break;
        default:
          break;
    }
    return ( ptr);
}
void Charactors::getSize(font_t font, int* width, int*height)
{
    static const struct
    {
        int width;
        int height;
    } font_size_table[font_t_count] = { {8, 16}, {16,16}, {32,16}, {32,32} };
    
    *width = font_size_table[font].width;
    *height = font_size_table[font].height;
}
