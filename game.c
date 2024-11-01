// 14-feb-2016
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>

int x,y,xe,xs,lx,ly,s=0,k=0,sc=0,xm,ym,tw,th,page,chnc=3,yax,limit=0,a=0,b=0;
char scr[20],ch=1;
float lby;

int oner,twor,thrr,four,fivr;
int oney,twoy,thry,fouy,fivy,cy;


union REGS i,o;

void key (int *k,int *x,int *y)
{
i.x.ax=3;
int86(51,&i,&o);
*k=o.x.bx;
*x=o.x.cx;
*y=o.x.dx;
}

void style(){
setbkcolor(3);
setcolor(1);
settextjustify(1,1);
settextstyle(6,0,2);
}

void scores(int scrs){
setcolor(13);
sprintf(scr,"%d",scrs);
outtextxy(xe+(xs/2),th+th+20,scr);
setcolor(15);
}
void chance(int ch){

   while(ch>=1){

	ellipse(xe+(xs/2),yax,0,360,13,20);
	floodfill(xe+(xs/2),yax,15);
	yax-=75;
	ch-=1;
   }
}
void lifes(int *c){

if(*c%(y/5)==0 && a==0){
lx=(s==1)?four:four+xs;
lby=y-(((y/5)*3)+20);
ly=0;
s=1-s;
b=0;
}

if(*c%(y/5)==0){
a++;
limit=1;
}
if(a==1 && limit){
bar(40,y-20,xs-40,lby);
ellipse(lx,fivy-10,0,360,7,10);
floodfill(lx,fivy-10,getcolor());
lby+=1.5;
b++;
}

if(a==2 && limit){
bar(40,y-20,xs-40,lby);
ellipse(lx,ly=y-10,0,360,7,10);
floodfill(lx,y-10,getcolor());
lby+=1.5;
}
if(a==3){
lx=0;
limit=0;
a++;
}
if(a==4)
a++;
if(a==5){
c=1;
a=0;
}
}

int main(void)
{
   int gd= 0, gm;
   int cx,cxc,lifex,speed=35,c=1;

   i.x.ax=1;

   initgraph(&gd, &gm, "C:\\turboc3\\bgi");

	if (graphresult() != grOk)
	{
		printf("Graphics Error occured: %s\n", grapherrormsg(graphresult()));
		getch();
		clrscr();
		exit(1);
	}
   int86(0x33,&i,&o);

   x=getmaxx();
   y=getmaxy();

   xs=x/6;
   xe=x-xs;

   settextstyle(1,0,2);
   tw=(textwidth("INSTRUCTION")/2);
   th=textheight("H");


 menu:

   i.x.ax=4;
   int86(0x33,&i,&o);
   o.x.cx=10;
   o.x.dx=10;

   while(1){
   cleardevice();
   style();

   key(&k,&xm,&ym);

   if(xm>(x/2)-tw && xm <(x/2)+tw && ym>(100-th) &&ym<110){
	bar((x/2)-tw,100-th,(x/2)+tw,120);

	if(k==1){
	page=1;
	break;

	}}

   if(xm>(x/2)-tw && xm <(x/2)+tw && ym>(150-th) &&ym<160){
	bar((x/2)-tw,150-th,(x/2)+tw,160);

	if(k==1){
	page=2;
	break;
	}}

   if(xm>(x/2)-tw && xm <(x/2)+tw && ym>(200-th) &&ym<210){
	bar((x/2)-tw,200-th,(x/2)+tw,210);

	if(k==1){
	page=3;
	break;
	}}

   if(xm>(x/2)-tw && xm <(x/2)+tw && ym>(250-th) &&ym<260){
	bar((x/2)-tw,250-th,(x/2)+tw,260);

	if(k==1)    {
	closegraph();
	exit(1);
	}

      }

   outtextxy(x/2,100,"NEW GAME");
   outtextxy(x/2,150,"INSTRUCTION");
   outtextxy(x/2,200,"DEVOLPER");
   outtextxy(x/2,250,"EXIT");
 k=0;
 delay(300);
  }
   loop:

   setbkcolor(7);
   oney= 0;
   twoy=y/5;
   thry=twoy*2;
   fouy=twoy*3;
   fivy=twoy*4;

   cy=y-12;

   oner=(rand()%(xs*3))+xs;
   twor=(rand()%(xs*3))+xs;
   thrr=(rand()%(xs*3))+xs;
   four=(rand()%(xs*3))+xs;
   fivr=(rand()%(xs*3))+xs;

   cx=fivr+(xs/2);



if(page==1){
	setcolor(13);
	outtextxy(xe+(xs/2),th+10,"SCORE:");
	outtextxy(xe+(xs/2),y-50,"LIFES");

	setfillstyle(1,12);
	bar(15,20,xs-23,th+50);
	outtextxy(xs/2,40,"EXIT");
	setfillstyle(1,3);
	bar(15,th+70,xs-23,th*2+100);
	outtextxy(xs/2,th+90,"PAUSE");
	outtextxy(xe+(xs/2),th+10,"SCORE:");
	setcolor(15);

 while(chnc>=1){
   do{
	yax=y-100;
	key(&k,&xm,&ym);

	setfillstyle(1,7);
	bar(xs,0,xe,y);
	bar(0,th*2+101,xs-9,y);
	bar(xs+9,0,x,th*3+20);

	setfillstyle(1,1);
	chance(chnc);
	scores(sc);
	lifes(&c);

	bar(xs,oney,oner,oney+10);
	bar(oner+xs,oney,xe,oney+10);

	bar(xs,twoy,twor,twoy+10);
	bar(twor+xs,twoy,xe,twoy+10);

	bar(xs,thry,thrr,thry+10);
	bar(thrr+xs,thry,xe,thry+10);

	bar(xs,fouy,four,fouy+10);
	bar(four+xs,fouy,xe,fouy+10);

	bar(xs,fivy,fivr,fivy+10);
	bar(fivr+xs,fivy,xe,fivy+10);

	circle(cx,cy,12);
	floodfill(cx,cy,15);

	   if(kbhit())
		ch=getch();

		       if(ch==75 && cx-12>xs)
				cx-=6;

		       else if(ch==77 && cx+12<xe)
				cx+=6;

		       else if(ch==32)
				getch();

		       else if(ch=='x'||ch=='X')
				break;
		       ch=1;

	   if(oney==(y/5))
	   {
		fivy=fouy;
		fouy=thry;
		thry=twoy;
		twoy=oney;
		fivr=four;
		four=thrr;
		thrr=twor;
		twor=oner;

		oney=0;
		oner=(rand()%(xs*3)+xs);
		sc+=10;
	   }

	oney++;
	twoy++;
	thry++;
	fouy++;
	fivy++;

	c++;

	if(xm>=15 && xm<=xs-23 && ym>=20 && ym<=th+50 && k==1){
	closegraph();
	exit(1);
	}

	if(xm>=15 && xm<=xs-23 && ym>=th+70 && ym<=(th*2)+100 && k==1){
	k=0;
	getch();
	}

	if((cx+20>=lx && cx+20<=lx+5 || cx-20<=lx && cx-20>=lx-5) && ly==y-10){
	if(chnc<3)
	chnc++;
	a=3;
	}
	delay(speed);
     }while((cx-10>fivr && cx+10<(fivr+xs))||fivy+8<(y-20));

chnc--;
if(chnc>=1){
cleardevice();
c=1;
a=0;
yax=y-100;
setfillstyle(1,1);
chance(chnc);
setfillstyle(11,8);
scores(sc);
setcolor(13);
outtextxy(x/2,200,"Press any key to continue");
getch();
goto loop;}
}
}

 if(page==2){
    cleardevice();
    setbkcolor(3);
    setcolor(15);
    settextjustify(1,1);
    outtextxy(x/2,100,"GAME.C");
    outtextxy(x/2,170,"Pass the ball between adjacent lines.");
    outtextxy(x/2,220,"Left and right arrow keys can move bal.");
    outtextxy(x/2,270,"While pressing any key returns to main menu");
    getch();
    goto menu;

 }
 if(page==3){
 cleardevice();
 setbkcolor(3);
 setcolor(15);
 settextjustify(1,1);
 outtextxy(x/2,200,"Devolped by XXXXXXXXXXXXX");
 outtextxy(x/2,400,"Press any key to main menu ");
 getch();
 goto menu;
 }

     oner=1;
     setfillstyle(11,10);
     setcolor(10);

     while(oner<y){
     circle(cx,y,oner);
     oner++;
     }
     setcolor(9);

     delay(500);
     cleardevice();
     floodfill(10,10,15);
     settextstyle(10,0,2);
     sprintf(scr,"YOUR SCORE: %d",sc);
     outtextxy(x/2,150,scr);
   getch();
   closegraph();
   return 0;

}
