#include<stdio.h>
#include<Windows.h>
#include<stdbool.h>
//https://sourceforge.net/projects/tdm-gcc/
void Goto(int x,int y){
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}

main(){
	int x=60, y=0,key=0,player=60,point=0;
	bool pointx=true,pointy=true;;
	while(1){
		system("cls");
		Goto(0,0);
		printf("현재 점수: %d",point);
		Goto(x,y);
		printf("*");
		//printf("%d %d",x,y);
		if(x==0) pointx=true;
		if(y==1) pointy=true;
		if(x==119) pointx=false;
		if(y==28){
			if(player<=x&&x<=player+9){
				pointy=false;
				point++;
			}else break;
		}
		if(pointx) x++;
		else x--;
		if(pointy) y++;
		else y--;
		if (kbhit()){   //키보드 입력 확인 (true / false)
            key = getch();
			switch(key){
				case 77:player+=4;break;
				//case 80:printf("↓");break;
				case 75:player-=4;break;
				//case 72:printf("↑");break;
				default: if (player>=109) player = 108; else if (player <= 0) player = 0;
			}
		}
		Goto(player,29);
		printf("========");
		Sleep(100);
	}
	printf("사망하였습니다.");
	Sleep(5000);
}
