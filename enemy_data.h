#ifndef DEF_ENEMY_DATA

#define DEF_ENEMY_DATA

#define ENEMY_ORDER_MAX 500 

//敵のデータ(テキストから得たデータの代入用)
typedef struct{
	//カウンタ,移動パターン,敵の種類
	int cnt,pattern,knd;
	//初期化と移動スピード
	double x,y,sp;
	//弾幕開始時間,弾幕の種類,色,体力,弾の種類,滞在時間,アイテム(6種類)
	int bltime,blknd,col,hp,blknd2,wait,item_n[6];
}ENEMY_ORDER;

void load_story();

#endif

