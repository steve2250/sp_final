#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<time.h>
#define m 5000
#define size 5000
void show(int hp, int tt, int money)
{
	if(tt<60)
		printf("................\n* 체력: %d, 걸린 시간: %d분, 자금: %d *\n", hp, tt, money);
	else
		printf("................\n* 체력: %d, 걸린 시간: %d시간 %d분, 자금: %d *\n", hp, tt/60, tt%60, money);
}
int gmstart() {
	int route;
	int n, hp = 4, money = 0, ch, tt = 0;
	char openMent[m];

	// 기숙사에서 출발하는 경우
	char arr[m]; char arr1[m]; char arr2[m]; char arr3[m]; char arr4[m];
	char arr5[m]; char arr6[m]; char arr7[m]; char arr8[m]; char arr9[m];
	char arr10[m]; char arr11[m]; char arr12[m]; char arr13[m]; char arr14[m];
	char arr15[m]; char arr16[m]; char arr17[m]; char arr18[m];

	// 지방에서 출발하는 경우
	char Alram[m];  char Alram_Y[m]; char Alram_N[m]; char Breakfast[m]; 
	char Bus_next[m]; char Bus_traffic[m]; char Fail[m]; char Fail_N[m];
	char Fail_Y[m]; char GotoKU[m]; char Hungry[m]; char KTX[m]; char KTX_fin[m];
	char KTX_hungry[m]; char KTX_random[m]; char KU[m]; char KU_club[m];
	char KU_club_F[m]; char KU_duck[m]; char KU_duck_cute[m]; char KU2[m];
	char KU2_karaoke[m]; char KU2_karaoke_T[m]; char Subway[m]; char Subway_card[m];
	char Subway_jobsang[m]; char Subway_js_T[m]; char Subway_next[m]; 
	char Taxi_fast[m]; char Taxi_traffic[m];

	int opening = open("./opening.txt", O_RDONLY);
	read(opening, openMent, 10000);
	puts(openMent);
	close(opening);
	scanf("%d", &route);

	if (route == 1) {// 서울에서 출발하는 경우
		char buff[size], buff1[size], buff2[size], buff3[size], buff4[size], buff5[size];
		int choice=0, fd=0, hp=1, tt=0, money=0, random=0;

		fd=open("./Wakeup.txt", O_RDONLY);
		read(fd, buff, size);
		puts(buff);
		close(fd);

		scanf("%d", choice);

		if(choice==1) //늦잠을 잤는지 판단
		{
			scanf("%d", &choice);

			if(choice == 1)
			{
				if(random=rand()%100<40)
				{
					tt+=30;
					printf("당신은 늦잠을 잤습니다! \n");
				}
			}
			else
			{
				if(random=rand()%100<20)
				{
					tt+=30;
					printf("당신은 늦잠을 잤습니다! \n");
				}
			}

		}
		else
		{
			scanf("%d", &choice);

			if(choice==1)
			{
				if(random=rand()%100<50)
				{
					tt+=30;
					printf("당신은 늦잠을 잤습니다! \n");
				}
			}
			else
			{
				if(random=rand()%100<30)
				{
					tt+=30;
					printf("당신은 늦잠을 잤습니다! \n");
				}
			}
		}

		show(hp, tt, money);
		
		fd=open("./S_Breakfast.txt", O_RDONLY);
		read(fd, buff1, size);
		puts(buff1);
		close(fd);
		
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				hp++;
				tt+=15;
				break;

			case 2:
				hp+=3;
				tt+=25;
				break;

			case 3:
				hp+=2;
				tt+=20;
				break;

			case 4:
				break;
		}

		show(hp, tt, money);

		fd=open("./Search.txt", O_RDONLY);
		read(fd, buff2, size);  
		puts(buff2);
		close(fd);

		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				tt+=10;
				//50%확률로 자금+1
				money++;
			case 2:
				tt+=15;
				//25% 확률로 자금 +2
				money+=2;
			case 3:
				tt+=5;
				//25% 확률로 자금+1
				money++;
			default:
				while(1)
				{
					printf("더 뒤지시겠습니까? 1.yes, 2.no\n");
					scanf("%d", &choice);

					if(choice==1)
					{
						scanf("%d", &choice);
						switch(choice)
						{
							case 1:
								tt+=10;
								money++;
								break;
							case 2:
								tt+=15;
								money+=2;
								break;
							case 3:
								tt+=5;
								money++;
								break;
						}   
					}
					else
						break;
				}
		}

		show(hp,tt,money);

		fd=open("./GoSubway.txt", O_RDONLY);
		read(fd, buff3, size);
		puts(buff3);
		close(fd);

		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				tt+=10;
				break;
			case 2:
				if(money<1)
				{
					printf("자금 부족! 다른 선택지를 고르시오.\n");

					while(1)
					{
						 scanf("%d", &choice);

						  if(choice==1)
						  {
							  tt+=10;
							  break;
						  }
						  else if(choice==2)
							  printf("자금 부족! 다른 선택지를 고르시오: \n");
						  else
						  {
							  hp--;
							  tt+=5;
							  break;
						  }
					}
				}
				else
				{
					money--;
					tt+=5;
				}

				break;

			case 3:
				hp--;
				tt+=5;
				break;
		}
		show(hp,tt,money);

		fd=open("./S_Subway.txt", O_RDONLY);
		read(fd, buff4, size);
		puts(buff4);
		close(fd);

		if(money<1)
		{
			printf("돈이 없어 집에서 가져왔다(걸린 시간 +30분, 자금 +1)\n");
			tt+=30;
			money++;
		}

		printf("지하철 비용을 내고 탑승한다(걸린 시간 +30분, 자금-1)\n");
		tt+=30;
		money--;

		show(hp, tt, money);
		fd=open("./GoBuilding.txt", O_RDONLY);
		read(fd,buff5,size);
		puts(buff5);
		close(fd);

		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				if(money<1)
				{
					printf("자금 부족! 다른 선택지를 고르시오.\n");

					while(1)
					{
						scanf("%d", &choice);

						if(choice == 1)
							printf("자금 부족! 다른 선택지를 고르시오. \n");
						else if(choice == 2)
							printf("자금 부족! 다른 선택지를 고르시오. \n");
						else if(choice == 3)
						{
							hp-=2;
							tt+=10;
							break;
						}
						
						else
						{
							tt+=20;
							break;
						}
					}
				}

				else
				{
					money--;
					tt+=10;
				}
			case 2:
				if(money<1)
				{
					printf("자금 부족! 다른 선택지를 고르시오. \n");

					while(1)
					{
						scanf("%d", &choice);

						if(choice == 1)
							printf("자금 부족! 다른 선택지를 고르시오.\n");
						else if(choice == 2)
							printf("자금 부족! 다른 선택지를 고르시오.\n");
						else if(choice == 3)
						{
							hp-=2;
							tt+=10;
							break;
						}
						else
						{
							tt+=20;
							break;
						}
					}
				}

				else
				{
					money--;
					hp--;
					tt+=5;
				}

				break;
			case 3:
				hp-=2;
				tt+=10;
			case 4:
				tt+=20;
		}
		show(hp, tt, money);

		if(hp<=0)
			printf("\n당신은 과도한 체력 소모로 인해 병원에 실려갔습니다.\n몸조리를 잘했어야죠.\n");
		else
		{
			if(tt<100)
				printf("\n당신은 우여곡절 끝에 강의실 자리에 앉았습니다.\n교수님의 출석 부르는 소리가 강의실을 매우기 시작하네요.\n");
			else
				 printf("\n갖은 노력에도 불구하고, 당신은 지각을 하였습니다.\n좀 미리미리 다니세요.\n");
		}

	}

	else if (route == 2) { // 기숙사에서 출발하는 경우
		int a = open("wake1", O_RDONLY);
		n = read(a, arr, 100000);
		printf("%s ", arr);
		scanf("%d", &ch);
		if (ch == 2)
		{
			hp += 1;
			tt += 20;
		}
		close(a);
		printf("\n");
		//arr[0]={0};
		a = open("eat", O_RDONLY);
		n = read(a, arr1, 10000);
		printf("%s", arr1);
		scanf("%d", &ch);
		close(a);
		printf("\n");
		switch (ch) //아침 먹기 선택
		{
		case 1:
			a = open("eat1", O_RDONLY);
			//arr[0]={0};
			n = read(a, arr2, 10000);
			printf("%s", arr2);
			scanf("%d", &ch);
			if (ch == 1)//편의점
			{
				tt += 6;
				hp += 1;
			}
			else
			{
				tt += 12;
				hp = hp + 2;
			}
			close(a);
			break;
		case 2:
			break;
		}
		printf("\n");

		//arr[0]={0};
		close(a);
		a = open("walk", O_RDONLY);
		n = read(a, arr3, 10000);
		printf("%s", arr3);
		scanf("%d", &ch);
		if (ch == 1)
		{
			hp = hp - 1;
			tt += 2;
		}
		else
		{
			tt += 5;
		}
		close(a);
		printf("\n");
		//arr[0]={0};
		a = open("coffee", O_RDONLY);
		n = read(a, arr4, 10000);
		printf("%s", arr4);
		scanf("%d", &ch);
		printf("\n");
		close(a);
		switch (ch)
		{
		case 1:
			//arr[0]={0};
			a = open("wherecoffee", O_RDONLY);
			n = read(a, arr5, 10000);
			printf("%s", arr5);
			scanf("%d", &ch);
			if (ch == 2)
			{
				hp = hp - 2;
				tt += 18;
				printf("\n");
				close(a);
				//arr[0]={0};
				a = open("path", O_RDONLY);
				n = read(a, arr6, 10000);
				printf("%s", arr6);
				scanf("%d", &ch);
				//arr[0]={0};
				close(a);
				if (ch == 1)
					break;
				else
				{
					hp = hp - 1;
					tt += 5;
				}
			}
			else
			{
				hp = hp - 1;
				tt += 10;
			}
		case 2:
			break;
		}
		close(a);
		printf("\n");
		//arr[0]={0};
		a = open("howtogo", O_RDONLY);
		n = read(a, arr7, 10000);
		printf("%s", arr7);
		scanf("%d", &ch);
		close(a);
		printf("\n");
		//arr[0]={0};
		if (ch == 1)//걸어가는 경우 혹은 퀴복드
		{
			hp -= 1;
			a = open("where", O_RDONLY);
			arr[0] = '\n';
			n = read(a, arr8, 10000);
			printf("%s", arr8);
			scanf("%d", &ch);
			close(a);
			//arr[0]={0};
			printf("\n");
			if (ch == 1) // 다리 지나서 가기
			{
				close(a);
				arr[0] = '\n';
				a = open("take", O_RDONLY);
				n = read(a, arr9, 10000);
				printf("%s", arr9);
				scanf("%d", &ch);
				if (ch == 1) // 건덕이와 사진찍기
				{
					tt += 5;
					hp = hp - 1;
				}
				printf("\n");
				close(a);
				//arr[0]={0};
				a = open("break", O_RDONLY);
				n = read(a, arr10, 10000);
				printf("%s", arr10);
				scanf("%d", &ch);
				printf("\n");
				close(a);
				//arr[0]={0};
				if (ch == 1)
				{
					hp = hp + 1;
					tt += 5;
				}

			}
			else // 학생회관
			{
				close(a);
				a = open("cu", O_RDONLY);
				n = read(a, arr11, 10000);
				printf("%s", arr11);
				scanf("%d", &ch);
				if (ch == 1)
					tt += 3;
				printf("\n");
				close(a);
				//arr[0]={0};
				a = open("workship", O_RDONLY);
				n = read(a, arr12, 10000);
				printf("%s", arr12);
				scanf("%d", &ch);
				//arr[0]={0};
				if (ch == 1)
				{
					tt += 7;
					hp = hp - 1;
				}
			}
			printf("드디어 모든 선택을 다 했다, 당신의 결과는??");
			printf("\n");
			if (tt > 50)
				printf("당신은 9시 전에 수업에 들어가지 못했다. FAIL");
			if (hp <= 0)
				printf("당신은 모든 체력을 소진하여 병원에 가야만 한다. FAIL");
			if (hp > 0 && tt <= 50)
				printf("당신은 제 시간에 수업 장소에 도착했다. SUCCESS");
		}

		else {
			close(a);
			a = open("qcheck", O_RDONLY);
			n = read(a, arr13, 10000);
			printf("%s", arr13);
			scanf("%d", &ch);
			close(a);
			printf("\n");
			//arr[0]={0};
			if (ch == 1) //학생회관
			{
				a = open("cu", O_RDONLY);
				n = read(a, arr14, 10000);
				printf("%s", arr14);
				scanf("%d", &ch);
				if (ch == 1)
					tt += 3;
				close(a);
				//arr[0]={0};
				printf("\n");
				a = open("friend", O_RDONLY);
				n = read(a, arr15, 10000);
				printf("%s", arr15);
				scanf("%d", &ch);
				//arr[0]={0};
				if (ch == 1)//친구 대려다 주기
				{
					tt += 4;
					hp = hp + 1;
				}
				else
					printf("당신의 우정은 파괴되었습니다.");
			}
			else // 정문 선택
			{
				a = open("sing", O_RDONLY);
				n = read(a, arr16, 10000);
				printf("%s", arr16);
				scanf("%d", &ch);
				if (ch == 1)
				{
					tt += 6;
					hp = hp - 1;
				}
				printf("\n");
				close(a);
				//arr[0]={0};

				a = open("join", O_RDONLY);
				n = read(a, arr17, 10000);
				printf("%s", arr17);
				scanf("%d", &ch);
				//arr[0]={0};
				if (ch == 1)
					tt += 3;
			}
		}
		printf("\n");
		//arr[0]="";
		close(a);
		a = open("wait", O_RDONLY);
		n = read(a, arr18, 10000);
		printf("%s", arr18);
		scanf("%d", &ch);
		if (ch == 1)
			tt += 6;

		printf("드디어 모든 선택을 다 했다, 당신의 결과는??");
		printf("\n");
		if (tt > 50)
			printf("당신은 9시 전에 수업에 들어가지 못했다. FAIL");
		if (hp <= 0)
			printf("당신은 모든 체력을 소진하여 병원에 가야만 한다. FAIL");
		if (hp > 0 && tt <= 50)
			printf("당신은 제 시간에 수업 장소에 도착했다. SUCCESS");
	}

	else if (route == 3) {// 지방에서 출발하는 경우
		int fd, ch, num, hungry, station, random;

		fd = open("./Alram.txt", O_RDONLY);
		read(fd, Alram, 10000);
		puts(Alram);
		close(fd);
		scanf("%d", &ch);

		if (ch == 1) {
			fd = open("./Alram_Y.txt", O_RDONLY);
			read(fd, Alram_Y, 10000);
			puts(Alram_Y);
			close(fd);
		}

		else if (ch == 2)
		{
			fd = open("./Alram_N.txt", O_RDONLY);
			read(fd, Alram_N, 10000);
			puts(Alram_N);
			close(fd);

			hp += 1;
			tt += 15;
		}

		fd = open("./Breakfast.txt", O_RDONLY);
		read(fd, Breakfast, 10000);
		puts(Breakfast);
		close(fd);
		scanf("%d", &ch);

		if (ch == 1) {
			tt += 20;
			hp += 4;
		}

		else if (ch == 2) {
			tt += 10;
			hp += 2;
		}

		else if (ch == 3) {
			tt += 5;
			hp += 2;
		}

		else if (ch == 4) {
			hungry = 1;
			hp -= 2;
			printf("좀 배가 고프네...\n");
		}

		fd = open("./KTX.txt", O_RDONLY);
		read(fd, KTX, 10000);
		puts(KTX);
		close(fd);
		scanf("%d", &ch);

		random = rand() % 100;

		if (ch == 1) {
			tt += 20;
			money -= 3;

			if (random < 20) {
				fd = open("./KTX_random.txt", O_RDONLY);
				read(fd, KTX_random, 10000);
				puts(KTX_random);
				close(fd);
				scanf("%d", &num);
				switch (num) {
				case 2:
					tt += 30;
					money -= 6;
				}
			}
		}

		else if (ch == 2) {
			tt += 10;
			money -= 1;
			if (random < 20) {
				fd = open("./KTX_random.txt", O_RDONLY);
				read(fd, KTX_random, 10000);
				puts(KTX_random);
				close(fd);
				scanf("%d", &num);

				if (num == 2) {
					tt += 15;
					money -= 2;
				}
			}
		}

		if (hungry == 1) {
			fd = open("./KTX_hungry.txt", O_RDONLY);
			read(fd, KTX_hungry, 10000);
			puts(KTX_hungry);
			close(fd);
			scanf("%d", &ch);

			switch (ch) {
			case 2:
				tt += 10; money -= 2; hp += 2;
			}
		}

		fd = open("./KTX_fin.txt", O_RDONLY);
		read(fd, KTX_fin, 1000);
		puts(KTX_fin);
		close(fd);
		money -= 4;

		fd = open("./GotoKU.txt", O_RDONLY);
		read(fd, GotoKU, 1000);
		puts(GotoKU);
		close(fd);
		scanf("%d", &ch);

		if (ch == 1) {
			random = rand() % 100;
			fd = open("./Subway.txt", O_RDONLY);
			read(fd, Subway, 1000);
			puts(Subway);
			close(fd);
			scanf("%d", &num);
			money -= 2;

			if (num == 1) {
				tt += 30; station = 1;
			}
			if (num == 2) {
				tt += 32; station = 2;
			}

			if (random < 5) {
				fd = open("./Subway_jobsang.txt", O_RDONLY);
				read(fd, Subway_jobsang, 1000);
				puts(Subway_jobsang);
				close(fd);
				scanf("%d", &num);

				if (num == 1) {
					fd = open("./Subway_js_T.txt", O_RDONLY);
					read(fd, Subway_js_T, 1000);
					puts(Subway_js_T);
					close(fd);
					money -= 3; hp -= 1;
				}
			}

			else if (random >= 5 && random < 15) {
				fd = open("./Subway_card.txt", O_RDONLY);
				read(fd, Subway_card, 1000);
				puts(Subway_card);
				close(fd);
				tt += 5; money -= 3;
			}

			else if (random >= 15 && random < 45) {
				fd = open("./Subway_next.txt", O_RDONLY);
				read(fd, Subway_next, 1000);
				puts(Subway_next);
				close(fd);
				tt += 10;
			}
		}

		else if (ch == 2) {
			random = rand() % 100;
			tt += 70; money -= 1; hp -= 3;
			if (random < 5) {
				fd = open("./Bus_next.txt", O_RDONLY);
				read(fd, Bus_next, 1000);
				puts(Bus_next);
				close(fd);
				tt += 10;
			}

			else if (random >= 5 && random < 25) {
				fd = open("./Bus_traffic.txt", O_RDONLY);
				read(fd, Bus_traffic, 1000);
				puts(Bus_traffic);
				close(fd);
				tt += 20;
			}
			station = 1;
		}

		else if (ch == 3) {
			random = rand() % 100;
			tt += 30; money -= 3; hp -= 1;
			if (random < 10) {
				fd = open("./Taxi_fast.txt", O_RDONLY);
				read(fd, Taxi_fast, 10000);
				puts(Taxi_fast);
				close(fd);
				tt -= 5;
			}

			else if (random >= 10 && random < 30) {
				fd = open("./Taxi_traffic.txt", O_RDONLY);
				read(fd, Taxi_traffic, 1000);
				puts(Taxi_traffic);
				close(fd);
				tt += 15;
			}
			station = 1;
		}

		if (station == 1) {
			fd = open("./KU.txt", O_RDONLY);
			read(fd, KU, 10000);
			puts(KU);
			close(fd);
			scanf("%d", &ch);

			random = rand() % 10;

			switch (ch) {
			case 1:
				tt += 5;
				hp -= 3;

			case 2:
				tt += 10;
			}

			if (random < 4) {
				fd = open("./KU_duck.txt", O_RDONLY);
				read(fd, KU_duck, 10000);
				puts(KU_duck);
				close(fd);
				scanf("%d", &num);

				if (num == 2) {
					fd = open("./KU_duck_cute.txt", O_RDONLY);
					read(fd, KU_duck_cute, 10000);
					puts(KU_duck_cute);
					close(fd);
					tt += 3; hp += 1;
				}
			}

			else if (random >= 4 && random < 7) {
				fd = open("./KU_club.txt", O_RDONLY);
				read(fd, KU_club, 10000);
				puts(KU_club);
				close(fd);
				scanf("%d", &num);

				if (num == 2) {
					fd = open("./KU_club_F.txt", O_RDONLY);
					read(fd, KU_club_F, 10000);
					puts(KU_club_F);
					close(fd);
					tt += 10; hp -= 2;
				}
			}
		}

		else if (station == 2) {
			fd = open("./KU2.txt", O_RDONLY);
			read(fd, KU2, 10000);
			puts(KU2);
			close(fd);
			scanf("%d", &ch);

			random = rand() % 10;

			switch (ch) {
			case 1:
				tt += 5;
				hp -= 3;

			case 2:
				tt += 10;
			}

			if (random < 4) {
				fd = open("./KU_club.txt", O_RDONLY);
				read(fd, KU_club, 10000);
				puts(KU_club);
				close(fd);
				scanf("%d", &num);

				if (num == 2) {
					fd = open("./KU_club_F.txt", O_RDONLY);
					read(fd, KU_club_F, 10000);
					puts(KU_club_F);
					close(fd);
					tt += 10; hp -= 2;
				}
			}

			else if (random >= 4 && random < 7) {
				fd = open("./KU2_karaoke.txt", O_RDONLY);
				read(fd, KU2_karaoke, 10000);
				puts(KU2_karaoke);
				close(fd);
				scanf("%d", &num);

				if (num == 2) {
					fd = open("./KU2_karaoke_T.txt", O_RDONLY);
					read(fd, KU2_karaoke_T, 10000);
					puts(KU2_karaoke_T);
					close(fd);
					tt += 30; money -= 2; hp -= 2;
				}
			}
		}
		else
			printf("프로그램을 다시 시작해주세요~\n");

		printf("드디어 모든 선택을 다 했다, 당신의 결과는??");
		printf("\n");
		if (tt > 120)
			printf("당신은 9시 전에 수업에 들어가지 못했다. FAIL");
		if (hp <= 0)
			printf("당신은 모든 체력을 소진하여 병원에 가야만 한다. FAIL");
		if (hp > 0 && tt <= 120)
			printf("당신은 제 시간에 수업 장소에 도착했다. SUCCESS");
	}

	return 0;
}
