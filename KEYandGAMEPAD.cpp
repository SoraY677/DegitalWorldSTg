#include "DxLib.h"
#include "KEYandGAMEPAD.h"

static int Key[256];

//�L�[�̏�Ԃ̍X�V
void Keyboard_Update(){
          char tmpKey[256];//���ׂẴL�[�̓��͏�Ԃ̊i�[�p
		  GetHitKeyStateAll(tmpKey);//���ׂẴL�[�̏�Ԃ��擾
          //�L�[��������Ă��邩�m�F
		  for( int i=0; i<256; i++){
			  //i�Ԗڂ̃L�[�ɓ��͂��������ꍇ
			  if (tmpKey[i] != 0){
				  Key[i]++;  //i�Ԗڂ̃L�[�ɉ��Z���Ă���
		      //����������Ă��Ȃ����
	      } else {
				  Key[i] = 0;//0�ɂ���
			  }
	 }
}

//KeyCode�̃L�[�̏�Ԃ��擾����
int Keyboard_Get (int KeyCode){
	return Key[KeyCode];//KeyCode�̓��͏�Ԃ�Ԃ�
}

PAD pad;

CONFIG configpad;

//�p�b�h�̏�����
void pad_init(){
	 configpad.down=0;
	  configpad.left=1;
      configpad.right=2;
      configpad.up=3;
      configpad.bom=4;
      configpad.shot=5;
      configpad.slow=11;
      configpad.start=13;
}



//�L�[�ƃQ�[���p�b�h�̂ǂ��炪������Ă��邩���肷��֐�
void input_pad_or_key(int *p,int k){
	*p = *p>k ? *p : k;
}

//�p�b�h�ƃL�[�̂��ׂĂ̓��͏�Ԃ̍X�V
void GetHitPadStateAll(){
	int i,PadInput,mul=1;
	PadInput= GetJoypadInputState( DX_INPUT_PAD1 ); //�p�b�h�̓��͏�Ԃ��擾
	for(i=0;i<16;i++){
		if(PadInput & mul) pad.pad[i]++;
		else               pad.pad[i]=0;
		mul *=2;
	}
	input_pad_or_key(&pad.pad[configpad.left]   ,Keyboard_Get(KEY_INPUT_LEFT    ));
    input_pad_or_key(&pad.pad[configpad.up]     ,Keyboard_Get(KEY_INPUT_UP      ));
    input_pad_or_key(&pad.pad[configpad.right]  ,Keyboard_Get(KEY_INPUT_RIGHT   ));
    input_pad_or_key(&pad.pad[configpad.down]   ,Keyboard_Get(KEY_INPUT_DOWN    ));
    input_pad_or_key(&pad.pad[configpad.shot]   ,Keyboard_Get(KEY_INPUT_Z       ));
    input_pad_or_key(&pad.pad[configpad.bom]    ,Keyboard_Get(KEY_INPUT_X       ));
    input_pad_or_key(&pad.pad[configpad.slow]   ,Keyboard_Get(KEY_INPUT_LSHIFT  ));
    input_pad_or_key(&pad.pad[configpad.start]  ,Keyboard_Get(KEY_INPUT_ESCAPE  ));
	    
}

//�n���ꂽ�p�b�h�L�[�̔ԍ��̓��͏�Ԃ�Ԃ��B
int CheckStatePad(int Handle){
	if (0<=Handle && Handle<PAD_MAX){
		return pad.pad[Handle];
	}
	else{
		printfDx("CheckStatePad�ɓn�����l���s���ł�\n");
		return -1;
	}
}