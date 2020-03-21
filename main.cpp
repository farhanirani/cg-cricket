#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<unistd.h>

float x,y,xc=1050,yc=900,r=813, bowlerhandx, bowlerhandy = 420;

void initial()  //for inital runup and bat swing
{
	cleardevice();
	
	//batsman
	x=400;
	setfillstyle(SOLID_FILL,BLUE);
	setcolor(WHITE);
	circle(x-60,450,18);
	floodfill(x-60,450,WHITE);
	
	//bowler
	x=1100;
	bowlerhandx = x+40;
	while(x>900)
	{
		setfillstyle(SOLID_FILL,GREEN);
		setcolor(WHITE);
		circle(x,450,18);
		floodfill(x,450,WHITE);
		line(x,468,x,535);
		//bowler hand
		line(x,500,bowlerhandx,400);
		line(x,500,x+20,540);
		line(x,535,x+15,575);
		line(x,535,x-15,575);
		//ball
		setfillstyle(SOLID_FILL,RED);
		setcolor(WHITE);
		circle(bowlerhandx,400,10);
		floodfill(bowlerhandx,400,WHITE);
		
		
		delay(10);
		
		//to overwrite
		setfillstyle(SOLID_FILL,BLACK);
		floodfill(x,450,BLACK);
		setcolor(BLACK);
		circle(x,450,18);
		line(x,468,x,535);
		line(x,500,bowlerhandx,400);
		line(x,500,x+20,540);
		line(x,535,x+15,575);
		line(x,535,x-15,575);
		//ball
		setfillstyle(SOLID_FILL,BLACK);
		floodfill(bowlerhandx,400,WHITE);
		setcolor(BLACK);
		circle(bowlerhandx,400,10);
		
		x-=2;
		bowlerhandx-=2.8;
	}
	
	//bowler last pos
	setfillstyle(SOLID_FILL,GREEN);
	setcolor(WHITE);
	circle(x,450,18);
	floodfill(x,450,WHITE);
    line(x,468,x,535);
	line(x,500,bowlerhandx,400);
	line(x,500,x+20,540);
	line(x,535,x+15,575);
	line(x,535,x-15,575);

	
	x=500;
}

void six()  //for ball to go for a six
{
	initial();
	
	while(x<1400)  //doing this without erasing the full screen
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
	initwindow(1300,700);
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

