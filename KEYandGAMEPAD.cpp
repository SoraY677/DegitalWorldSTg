#include "DxLib.h"
#include "KEYandGAMEPAD.h"

static int Key[256];

//キーの状態の更新
void Keyboard_Update(){
          char tmpKey[256];//すべてのキーの入力状態の格納用
		  GetHitKeyStateAll(tmpKey);//すべてのキーの状態を取得
          //キーが押されているか確認
		  for( int i=0; i<256; i++){
			  //i番目のキーに入力があった場合
			  if (tmpKey[i] != 0){
				  Key[i]++;  //i番目のキーに加算していく
		      //何も押されていなければ
	      } else {
				  Key[i] = 0;//0にする
			  }
	 }
}

//KeyCodeのキーの状態を取得する
int Keyboard_Get (int KeyCode){
	return Key[KeyCode];//KeyCodeの入力状態を返す
}

PAD pad;

CONFIG configpad;

//パッドの初期化
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



//キーとゲームパッドのどちらが押されているか判定する関数
void input_pad_or_key(int *p,int k){
	*p = *p>k ? *p : k;
}

//パッドとキーのすべての入力状態の更新
void GetHitPadStateAll(){
	int i,PadInput,mul=1;
	PadInput= GetJoypadInputState( DX_INPUT_PAD1 ); //パッドの入力状態を取得
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

//渡されたパッドキーの番号の入力状態を返す。
int CheckStatePad(int Handle){
	if (0<=Handle && Handle<PAD_MAX){
		return pad.pad[Handle];
	}
	else{
		printfDx("CheckStatePadに渡した値が不正です\n");
		return -1;
	}
}