#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<errno.h>
#define m 5000
#define size 5000
#include "kucd_3.c"
#include "sp_fmain.h"

int main (void)
{
	int num;
	printf("학교 가는길....\n");
	printf("이 게임은 체력과 자금을 효율적으로 사용하여 제시간 안에 학교에 도착해야 합니다!! 그럼 GOOD LUCK...\n");
	game_main();
	scanf("%d", &num);
	switch(num){
		case 1:{
			printf("게임을 시작합니다.\n");
			gmstart();
			break;
		       }
	      	case 2:
			printf("이 게임의 제작자는 건국대학교 스마트ICT융합공학과 학생들입니다\n");
			printf("201912308 구준모\n");
			printf("201912310 김규빈\n");
			printf("201912315 김성유\n");
			printf("201912334 이형철\n");
			printf("201912336 임한결\n");
			break;
		case 3:
			printf("게임을 종료합니다.\n");
			break;
			return 0;
			
	}
	
}

