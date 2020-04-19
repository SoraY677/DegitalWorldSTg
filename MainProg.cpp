#include "DxLib.h"
#include "KEYandGAMEPAD.h"
#include "playerMgr.h"
#include "stage.h"
#include "enemyMgr.h"
#include "enemy_data.h"

//ループ中に行うこと
int ProcessLoop(){
	Keyboard_Update();//キーボードの入力状態の更新
	GetHitPadStateAll();//ゲームパッドの入力状態の更新
	return 0;
}

int func_state = 0;//処理の状態
int stage_count;


//メインプログラム
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	//ウィンドウモード変更,DxLibを初期化,裏画面処理,背景を白に設定
	ChangeWindowMode(FALSE),DxLib_Init(),SetDrawScreen( DX_SCREEN_BACK),SetGraphMode(1920,1440,16),SetBackgroundColor(255,255,255);

	

	//ループ(表画面に描写,メッセージ処理,画面クリア,ループ中に行うその他の処理)
	while (ScreenFlip()==0  && ProcessMessage()==0 && ClearDrawScreen()==0 && ProcessLoop()==0 ){

		//func_stateの値によって処理内容を変える
		switch(func_state){

	    //最初の初期化
		case 0:
			    pad_init();//ゲームパッドのコンフィグ初期化
                func_state=99;  
			    break;

        //ステージ前初期化
		case 99:
			load_story();//データ読み込み
			PlayerMgr_Init();//プレイヤーの初期化
			enemyMgr_init();//敵の初期化
			load_board();//ボードのロード
			func_state=100;
			break;

		//ステージ内の処理
		case 100:
			stage_count++;

			enemyMgr_enter();//敵登録


			PlayerMgr_calc();
			PlayerMgr_Update();//プレイヤーの動き
			enemyMgr_act();//敵の動き
			
            PlayerMgr_Draw();//プレイヤーの描写
			enemyMgr_Draw();//敵の描写
            graph_board();//ボードの描写

			
		    break;

	    //エラーが起きたとき
	    default:
			printfDx("不明なエラー");
			break;
		
		}
		if(Keyboard_Get(KEY_INPUT_ESCAPE)==1) break;

	}

	PlayerMgr_Fin();//プレイヤーの終了処理

	DxLib_End();
	return 0;
}
