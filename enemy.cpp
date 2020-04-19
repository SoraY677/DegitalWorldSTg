
#include <math.h>
#include "DxLib.h"
#include "enemy.h"
#include "stage.h"
#include "enemy_data.h"

extern int stage_count;


//‰Šú‰»
void enemy_init(){
	
}


//“G‚ÌˆÚ“®ƒpƒ^[ƒ“‚O
void enemy_pattern0(ENEMY *Enemy){
	int t = Enemy->cnt;
	if (t==0)
		Enemy->vy=2;///‰º‚ª‚Á‚Ä‚­‚é
	if(t==60)
		Enemy->vy=0;//Ž~‚Ü‚é
	//“o˜^‚³‚ê‚½ŽžŠÔ‚¾‚¯‘ØÝ‚µ‚Ä
	if (t==60+Enemy->wait)
		Enemy->vy=-2;//ã‚ª‚Á‚Ä‚¢‚­
	
}

//‚ ‚¢‚Ä‚¢‚é“G”Ô†‚ðŒŸõ
  int enemy_num_search(ENEMY *Enemy){

	  if (Enemy->flag==0){
		  return 1;
        }
	   return -1;
	  }


//“Gƒf[ƒ^‚Ì“o˜^
void enemy_enter(ENEMY *Enemy,ENEMY_ORDER Enemy_order){
        Enemy->flag=1;//ƒtƒ‰ƒO
		Enemy->cnt =0;//ƒJƒEƒ“ƒ^
		Enemy->pattern=Enemy_order.pattern;//ˆÚ“®ƒpƒ^[ƒ“
        Enemy->direction=1;//Œü‚«
		Enemy->x = Enemy_order.x;//À•W
		Enemy->y = Enemy_order.y;
		Enemy->speed = Enemy_order.sp;//ƒXƒs[ƒh
		Enemy->bltime=	Enemy_order.bltime;//’e–‹”­ŽËŽžŠÔ
		Enemy->kind=Enemy_order.knd;//Ží—Þ
		Enemy->blkind =Enemy_order.blknd;//’e–‹‚ÌŽí—Þ
		Enemy->blkind2=Enemy_order.blknd2;//’e‚ÌŽí—Þ
		Enemy->color=Enemy_order.col;//F
		Enemy->wait=Enemy_order.wait;//’â‘ØŽžŠÔ
		Enemy->hp=Enemy_order.hp;//‘Ì—Í
		Enemy->hp_max=Enemy->hp;//Å‘å‘Ì—Í
		Enemy->vx=0;//…•½¬•ª‚Ì‘¬“x
		Enemy->vy=0;//‚’¼¬•ª‚Ì‘¬“x
		Enemy->angle=0;//Šp“x
		//—Ž‚Æ‚·ƒAƒCƒeƒ€
		for(int j=0;j<6;j++)
			Enemy->item_n[j] = Enemy_order.item_n[j];
		
      }
//“G‚Ìs“®
void enemy_act(ENEMY *Enemy){
	
		
			enemy_pattern0(Enemy);
			Enemy->x += cos(Enemy->angle)*Enemy->speed;
			Enemy->y += sin(Enemy->angle)*Enemy->speed;
			Enemy->x += Enemy->vx;
			Enemy->y += Enemy->vy;
			Enemy->cnt++;
			Enemy->image_num = (Enemy->cnt%16)/2;
			//“G‚ª‰æ–Ê‚©‚çŠO‚ê‚½‚çÁ‚·
			if(Enemy->x<-50 || FIELD_MAX_X+50<Enemy->x || Enemy->y<-50 || FIELD_MAX_Y+50<Enemy->y)
				Enemy->flag=0;
		
	
}

//•`ŽÊ
void enemy_Draw(ENEMY Enemy,int image){
	Enemy.img = image;
	DrawRotaGraph(Enemy.x,Enemy.y,1.0,0.0,Enemy.img,TRUE);
   
}







