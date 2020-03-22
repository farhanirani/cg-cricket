#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<unistd.h>

float x,y,xc=1050,yc=870,r=813, bowlerhandx, bowlerhandy = 420, batsmanx, batsmany;

void initial()  //for inital runup and bat swing
{
	cleardevice();
	
	//batsman
	x=220;
	setfillstyle(SOLID_FILL,BLUE);
	setcolor(WHITE);
	circle(x,450,18);
	floodfill(x,450,WHITE);
	line(x,468,x,535);
	line(x,535,x+15,575);
	line(x,535,x-15,575);
	
	batsmany = 400;
	while(batsmany < 600)
	{
		batsmanx = 220 - sqrt(10000 - pow((500-batsmany),2));
		line(x,500,batsmanx,batsmany);
		delay(1);
		batsmany+=2;
	}

	//bowler
	x=1100;
	bowlerhandx = x+40;
	//runup
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
		
		delay(1);
		
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
	
	//bowlers last pos
	setfillstyle(SOLID_FILL,GREEN);
	setcolor(WHITE);
	circle(x,450,18);
	floodfill(x,450,WHITE);
    line(x,468,x,535);
	line(x,500,bowlerhandx,410);
	line(x,500,x+20,540);
	line(x,535,x+15,575);
	line(x,535,x-15,575);
	
	x=bowlerhandx;
	//ball throw   .................................
	int xc1 = 873, yc1 = 723, rc1 = 323;
	while(x>600)
	{
		y = yc1 - sqrt(rc1*rc1 - pow((x-xc1),2));
		
		setfillstyle(SOLID_FILL,RED);
		setcolor(WHITE);
		circle(x,y,10);
		floodfill(x,y,WHITE);
		
		delay(10);
		
		setfillstyle(SOLID_FILL,BLACK);
		floodfill(x,y,WHITE);
		setcolor(BLACK);
		circle(x,y,10);
		
		x-=3;
	}
	xc1 = 431; yc1 = 640; rc1 = 190;
	while(x>350)
	{
		y = yc1 - sqrt(rc1*rc1 - pow((x-xc1),2));
		
		setfillstyle(SOLID_FILL,RED);
		setcolor(WHITE);
		circle(x,y,10);
		floodfill(x,y,WHITE);
		
		delay(10);
		
		setfillstyle(SOLID_FILL,BLACK);
		floodfill(x,y,WHITE);
		setcolor(BLACK);
		circle(x,y,10);
		
		x-=3;
	}
	
	//hits bat..................................
	
	
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

