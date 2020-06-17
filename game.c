#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#define m 5000
int main(void)
{
	int n,hp=4,money=0,ch,time=0;
	char arr[m];
	char arr1[m];
	char arr2[m];
	char arr3[m];
	char arr4[m];
	char arr5[m];
	char arr6[m];
	char arr7[m];
	char arr8[m];
	char arr9[m];
	char arr10[m];
	char arr11[m];
	char arr12[m];
	char arr13[m];
	char arr14[m];
	char arr15[m];
	char arr16[m];
	char arr17[m];
	char arr18[m];


	int a=open("wake1",O_RDONLY);
	n=read(a,arr,100000);
	printf("%s ",arr);
	scanf("%d",&ch);
	if(ch==2)
	{
		hp+=1;
		time+=20;
	}
	close(a);
	printf("\n");
	//arr[0]={0};

	a=open("eat",O_RDONLY);
	n=read(a,arr1,10000);
	printf("%s",arr1);
	scanf("%d",&ch);
	close(a);
	printf("\n");
	switch(ch) //아침 먹기 선택
	{
		case 1:
			a=open("eat1",O_RDONLY);
			//arr[0]={0};
			n=read(a,arr2,10000);
			printf("%s",arr2);
			scanf("%d",&ch);
			if(ch==1)//편의점 
			{
				time+=6;
				hp+=1;
			}
			else
			{
				time+=12;
				hp=hp+2;
			}
			close(a);
			break;
		case 2:
			break;
	}
	printf("\n");
	
	//arr[0]={0};
	close(a);
	a=open("walk",O_RDONLY);
	n=read(a,arr3,10000);
	printf("%s",arr3);
	scanf("%d",&ch);
	if(ch==1)
	{
		hp=hp-1;
		time+=2;
	}
	else
	{
		time+=5;
	}
	close(a);
	printf("\n");
	//arr[0]={0};

	a=open("coffee",O_RDONLY);
	n=read(a,arr4,10000);
	printf("%s",arr4);
	scanf("%d",&ch);
	printf("\n");
	close(a);
	switch(ch)
	{
		case 1:
			//arr[0]={0};
			a=open("wherecoffee",O_RDONLY);
			n=read(a,arr5,10000);
			printf("%s",arr5);
			scanf("%d",&ch);
			if(ch==2)
			{
				hp=hp-2;
				time+=18;
				printf("\n");
				close(a);
				//arr[0]={0};

				a=open("path",O_RDONLY);
				n=read(a,arr6,10000);
				printf("%s",arr6);
				scanf("%d",&ch);
				//arr[0]={0};
				close(a);
				if(ch==1)
					break;
				else
				{
					hp=hp-1;
					time+=5;
				}
			}
			else
			{
				hp=hp-1;
				time+=10;
			}

		case 2:
			break;
	}
	close(a);
	printf("\n");
	//arr[0]={0};

	a=open("howtogo",O_RDONLY);
	n=read(a,arr7,10000);
	printf("%s",arr7);
	scanf("%d",&ch);
	close(a);
	printf("\n");
	//arr[0]={0};
	if(ch==1)//걸어가는 경우 혹은 퀴복드 
	{
		hp-=1;
		a=open("where",O_RDONLY);
		arr[0]='\n';
		n=read(a,arr8,10000);
		printf("%s",arr8);
		scanf("%d",&ch);
		close(a);
			//arr[0]={0};
		printf("\n");
		if(ch==1) // 다리 지나서 가기
		{
			close(a);
			arr[0]='\n';
			a=open("take",O_RDONLY);
			n=read(a,arr9,10000);
			printf("%s",arr9);
			scanf("%d",&ch);
			if(ch==1) // 건덕이와 사진찍기
			{
				time+=5;
				hp=hp-1;
			}
			printf("\n");
			close(a);
				//arr[0]={0};

			a=open("break",O_RDONLY);
			n=read(a,arr10,10000);
			printf("%s",arr10);
			scanf("%d",&ch);
			printf("\n");
			close(a);
				//arr[0]={0};
			if(ch==1)
			{
				hp=hp+1;
				time+=5;
			}
				
		}
		else // 학생회관
		{
			close(a);
			a=open("cu",O_RDONLY);
			n=read(a,arr11,10000);
			printf("%s",arr11);
			scanf("%d",&ch);
			if(ch==1)
				time+=3;
			printf("\n");
			close(a);
				//arr[0]={0};

			a=open("workship",O_RDONLY);
			n=read(a,arr12,10000);
			printf("%s",arr12);
			scanf("%d",&ch);
				//arr[0]={0};
			if(ch==1)
			{
				time+=7;
				hp=hp-1;
			}

		}
	}
	
	else{
		close(a);
		a=open("qcheck",O_RDONLY);
		n=read(a,arr13,10000);
		printf("%s",arr13);
		scanf("%d",&ch);
		close(a);
		printf("\n");
			//arr[0]={0};
		if(ch==1) //학생회관
		{
			a=open("cu",O_RDONLY);
			n=read(a,arr14,10000);
			printf("%s",arr14);
			scanf("%d",&ch);
			if(ch==1)
				time+=3;
			close(a);
				//arr[0]={0};
			printf("\n");

			a=open("friend",O_RDONLY);
			n=read(a,arr15,10000);
			printf("%s",arr15);
			scanf("%d",&ch);
			//arr[0]={0};
			if(ch==1)//친구 대려다 주기
			{
				time+=4;
				hp=hp+1;
			}
			else
				printf("당신의 우정은 파괴되었습니다.");
		}

		else // 정문 선택
		{
			a=open("sing",O_RDONLY);
			n=read(a,arr16,10000);
			printf("%s",arr16);
			scanf("%d",&ch);
			if(ch==1)
			{
				time+=6;
				hp=hp-1;
			}
			printf("\n");
			close(a);
				//arr[0]={0};
				
			a=open("join",O_RDONLY);
			n=read(a,arr17,10000);
			printf("%s",arr17);
			scanf("%d",&ch);
				//arr[0]={0};
			if(ch==1)
				time+=3;
		}
	}
	printf("\n");
	//arr[0]="";
	close(a);

	a=open("wait",O_RDONLY);
	n=read(a,arr18,10000);
	printf("%s",arr18);
	scanf("%d",&ch);
	if(ch==1)
		time+=6;

	printf("드디어 모든 선택을 다 했다, 당신의 결과는??");
	printf("\n");
	if(time>50)
		printf("당신은 9시 전에 수업에 들어가지 못했다. FAIL");
	if(hp<=0)
		printf("당신은 모든 체력을 소진하여 병원에 가야만 한다. FAIL");
	if(hp>0 && time<=50)
		printf("당신은 제 시간에 수업 장소에 도착했다. SUCCESS");
}
