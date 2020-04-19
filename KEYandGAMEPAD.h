

#ifndef DEF_KEYANDGAMEPAD_H //二重インクルード禁止

#define DEF_KEYANDGAMEPAD_H

#define PAD_MAX 16

//パッドの構造体
typedef struct{
	int pad[PAD_MAX];
}PAD;

//コンフィグの構造体
typedef struct{
	int left,up,right,down,shot,bom,slow,start;
}CONFIG;


void Keyboard_Update();

int Keyboard_Get(int KeyCode);

void pad_init();

void GetHitPadStateAll();

int CheckStatePad(int Handle);

#endif