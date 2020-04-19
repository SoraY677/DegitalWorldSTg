

#ifndef DEF_ENEMY_H

#define DEF_ENEMY_H

#define ENEMY_MAX 30

#include "enemy_data.h"

typedef struct{
	double x,y;//座標
	double vx,vy;//速度成分
    double speed;//スピード
	double angle;//角度
	//フラグ,カウンタ,移動パターン,向き,敵の種類,HP,最大HP,落とすアイテム,画像
	int flag,cnt,pattern,direction,kind,hp,hp_max,item_n[6],img,image_num;
	//弾幕開始時間, 弾幕の種類,弾の種類,色,状態,待機時間,停滞時間
	int bltime,blkind,blkind2,color,state,wtime,wait;
}ENEMY;



void enemy_init();

void enemy_pattern0(ENEMY *Enemy);

void enemy_enter(ENEMY *Enemy, ENEMY_ORDER Enemy_order);

void enemy_act(ENEMY *Enemy);

void enemy_Draw(ENEMY Enemy,int image);

#endif