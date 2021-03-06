
#include <math.h>
#include "DxLib.h"
#include "enemy.h"
#include "stage.h"
#include "enemy_data.h"

extern int stage_count;


//初期化
void enemy_init(){
	
}


//敵の移動＝パターン０
void enemy_pattern0(ENEMY *Enemy){
	int t = Enemy->cnt;
	if (t==0)
		Enemy->vy=2;///下がってくる
	if(t==60)
		Enemy->vy=0;//止まる
	//登録された時間だけ滞在して
	if (t==60+Enemy->wait)
		Enemy->vy=-2;//上がっていく
	
}

//あいている敵番号を検索
  int enemy_num_search(ENEMY *Enemy){

	  if (Enemy->flag==0){
		  return 1;
        }
	   return -1;
	  }


//敵データの登録
void enemy_enter(ENEMY *Enemy,ENEMY_ORDER Enemy_order){
        Enemy->flag=1;//フラグ
		Enemy->cnt =0;//カウンタ
		Enemy->pattern=Enemy_order.pattern;//移動パターン
        Enemy->direction=1;//向き
		Enemy->x = Enemy_order.x;//座標
		Enemy->y = Enemy_order.y;
		Enemy->speed = Enemy_order.sp;//スピード
		Enemy->bltime=	Enemy_order.bltime;//弾幕発射時間
		Enemy->kind=Enemy_order.knd;//種類
		Enemy->blkind =Enemy_order.blknd;//弾幕の種類
		Enemy->blkind2=Enemy_order.blknd2;//弾の種類
		Enemy->color=Enemy_order.col;//色
		Enemy->wait=Enemy_order.wait;//停滞時間
		Enemy->hp=Enemy_order.hp;//体力
		Enemy->hp_max=Enemy->hp;//最大体力
		Enemy->vx=0;//水平成分の速度
		Enemy->vy=0;//垂直成分の速度
		Enemy->angle=0;//角度
		//落とすアイテム
		for(int j=0;j<6;j++)
			Enemy->item_n[j] = Enemy_order.item_n[j];
		
      }
//敵の行動
void enemy_act(ENEMY *Enemy){
	
		
			enemy_pattern0(Enemy);
			Enemy->x += cos(Enemy->angle)*Enemy->speed;
			Enemy->y += sin(Enemy->angle)*Enemy->speed;
			Enemy->x += Enemy->vx;
			Enemy->y += Enemy->vy;
			Enemy->cnt++;
			Enemy->image_num = (Enemy->cnt%16)/2;
			//敵が画面から外れたら消す
			if(Enemy->x<-50 || FIELD_MAX_X+50<Enemy->x || Enemy->y<-50 || FIELD_MAX_Y+50<Enemy->y)
				Enemy->flag=0;
		
	
}

//描写
void enemy_Draw(ENEMY Enemy,int image){
	Enemy.img = image;
	DrawRotaGraph(Enemy.x,Enemy.y,1.0,0.0,Enemy.img,TRUE);
   
}







