

#ifndef DEF_KEYANDGAMEPAD_H //��d�C���N���[�h�֎~

#define DEF_KEYANDGAMEPAD_H

#define PAD_MAX 16

//�p�b�h�̍\����
typedef struct{
	int pad[PAD_MAX];
}PAD;

//�R���t�B�O�̍\����
typedef struct{
	int left,up,right,down,shot,bom,slow,start;
}CONFIG;


void Keyboard_Update();

int Keyboard_Get(int KeyCode);

void pad_init();

void GetHitPadStateAll();

int CheckStatePad(int Handle);

#endif