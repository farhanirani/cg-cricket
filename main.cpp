#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<unistd.h>

float x,y,xc=1000,yc=1200,r=1000;
void initial()  //for inital runup and bat swing
{
	cleardevice();
	
	//batsman
	x=300;
	setfillstyle(SOLID_FILL,BLUE);
	setcolor(WHITE);
	circle(x-60,450,18);
	floodfill(x-60,450,WHITE);
	
	//bowler
	x=850;
	while(x>700)
	{
		setfillstyle(SOLID_FILL,GREEN);
		setcolor(WHITE);
		circle(x,450,18);
		floodfill(x,450,WHITE);
		
		delay(10);
		
		setfillstyle(SOLID_FILL,BLACK);
		floodfill(x,450,BLACK);
		setcolor(BLACK);
		circle(x,450,18);
		
		x-=2;
	}
	
	//bowler last pos
	setfillstyle(SOLID_FILL,GREEN);
	setcolor(WHITE);
	circle(x,450,18);
	floodfill(x,450,WHITE);
	
	x=300;
}

void six()  //for ball to go for a six
{
	initial();
	
	while(x<1100)  //doing this without erasing the full screen
	{
		y = yc - sqrt(r*r - pow((x-xc),2));
		
		setfillstyle(SOLID_FILL,RED);
		setcolor(WHITE);
		circle(x,y,10);
		floodfill(x,y,WHITE);
		
		delay(10);
		
		setfillstyle(SOLID_FILL,BLACK);
		floodfill(x,y,WHITE);
		setcolor(BLACK);
		circle(x,y,10);
		
		
		x+=4;
	}	
}

void four()
{
	initial();
}


main()
{
	int  choice, totalscore=0 ;                            
	initwindow(1000,700);
	six();
   while(1)
   {
   		system("CLS");
		printf("\n\n                    TOTAL SCORE    :::::     %d    ",totalscore); 
		printf("\n\n\n\n1 : SIX   2 : FOUR  3 : OUT\n\n\nEnter choice : ");
		scanf("%d",&choice);
		if(choice==1) {
			six();
			totalscore+=6;
		}
		else if(choice==2) {
			four();
			totalscore+=4;
		}
		else if(choice==3) {
			system("CLS");
			printf("\n\n********************   YOUR TOTAL SCORE IS  :::::    %d     *******************\n",totalscore);
			printf("**************  GOOD GAME, WELL PLAYED!!   **********************");
			exit(1);
		}
		
   	
   }
   
   getch();
}

///*	Test thu vien winbgim.h	*/
//
//#include <winbgim.h> 
//
//main(int argc, char *argv[])
//{
//	initwindow(300, 300);					// init window graphics
//	setbkcolor(1);							// set background
//   	cleardevice();
//	setcolor(14);							// set text color
//	outtextxy(50,100,"Graphics in Dev-C++");// print text in window graphics
//	while(!kbhit()) delay(1);				// pause screen	
//}

