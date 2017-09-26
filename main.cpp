#include "graphics.h"
#include "shapes.h"
#include <iostream>
using namespace std;
shape** resize(shape **_s,int &_size)// for resizing of the allshapes array
{
	shape **temp=new shape *[_size*2];
	for(int i=0;i<_size;i++)
	{
		temp[i]=_s[i];
	}
	_size=_size*2;
	delete []_s;
	_s=temp;
	return _s;
}
void menu()
{
	setcolor(BLUE);
	outtextxy(350,10,"PAINT");
	setcolor(WHITE);
	line(700,0,700,699);
	rectangle(700,0,800,100);//Triangle
	rectangle(800,0,899,100);//Rectangle
	rectangle(700,100,800,200);//circle
	rectangle(800,100,899,200);//polygon
	rectangle(700,200,800,300);//line
	rectangle(800,200,899,300);//curve
	rectangle(700,300,899,400);//eraser
	rectangle(700,400,899,450);//paintbucket
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(700,450,800,500);//Blue
	floodfill(705,457, WHITE);
	setfillstyle(SOLID_FILL,RED);
	rectangle(800,450,899,500);//Red
	floodfill(805,457, WHITE);
	setfillstyle(SOLID_FILL,MAGENTA);
	rectangle(700,500,800,550);//magenta
	floodfill(705,545, WHITE);
	setfillstyle(SOLID_FILL,GREEN);
	rectangle(800,500,899,550);//Green
	floodfill(810,510,WHITE);
	setfillstyle(SOLID_FILL,YELLOW);
	rectangle(700,550,800,600);//yellow
	floodfill(705,556,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	rectangle(800,550,899,600);//White
	floodfill(855,560, WHITE);
	rectangle(700,600,800,699);//save
	rectangle(800,600,899,699);//load

	setcolor(BLUE);
	outtextxy(720,50,"TRIANGLE");
	setcolor(RED);
	outtextxy(810,50,"RECTANGLE");
	setcolor(BLUE);
	outtextxy(720,150,"CIRCLE");
	setcolor(RED);
	outtextxy(810,150,"POLYGON");
	setcolor(BLUE);
	outtextxy(720,250,"LINE");
	setcolor(RED);
	outtextxy(810,250,"OPENCURVE");
	setcolor(YELLOW);
	outtextxy(740,350,"ERASER TOOL");
	setcolor(WHITE);
	outtextxy(750,425,"PAINT BUCKET");
	setcolor(GREEN);
	setcolor(BROWN);
	outtextxy(735,465,"BLUE");
	outtextxy(835,465,"RED");
	outtextxy(725,515,"MAGENTA");
	outtextxy(825,515,"GREEN");
	outtextxy(725,565,"YELLOW");
	outtextxy(825,565,"WHITE");
	outtextxy(720,650,"LOAD FILE");
	outtextxy(820,650,"SAVE FILE");
}

int main()
{

	initwindow(900, 700,"Windows BGI");//BGI window
	menu();//menu
	//*********************************************VARIABLES******************************************************************************//
	int option=0;//for selection of shapes
	int coloroption=0;//for selesction of color
	int typeoption=0;//for selection of bucket or eraser
	int size=20;//initial size of allshapes array
	int mousx=0;//takes x co-ordinates of mouseclick
	int mousy=0;//takes y coordiantes of mouseclick
	int mousx1=0;//takes x coordiantes for bucket
	int mousy1=0;//takes y coordinates for bucket
	int x1=0,y1=0,x2=0,y2=0;//to store co-ordinates of mouseclick
	shape **allshapes;// A double pointer for an abstract class shapes
	int count=0;//number of shapes drawn
	int fillpolygon[20];
	point pnt[100];//Array for number of points
	int pointindex=0;//index numberof points
	int polygonpointcount;//index for number of points of polygons
	int curvecount;//index for number of points in a curve
	point check;
	allshapes=new shape* [size];//initializes shapes with the initial size
	setcolor(WHITE);
	bool flag=true;
	//***********************************************************************************************************************************//
	//**********************************************************EXECUTION LOOP*********************************************************//
	while(1)
	{
		if(count>size-1)
		{
			allshapes=resize(allshapes,size);
		}
		while(!ismouseclick(WM_LBUTTONDOWN));
		getmouseclick(WM_LBUTTONDOWN,mousx,mousy);
		//*********************************************************For drawing shapes****************************************************//
		if(mousx<=800 && mousx>=700 && mousy>=0 &&  mousy<=100)//triangle
		{
			option=1;//option 1 for triangle
		}
		//**********************************Triangle*********************************************************************//
		if(option==1){
			allshapes[count]=new Triangle;//point a pointer array to a triangle at index count
			while(!ismouseclick(WM_LBUTTONDOWN));
			getmouseclick(WM_LBUTTONDOWN, pnt[0].x,pnt[0].y);
			putpixel( pnt[0].x,pnt[0].y,15);
			while(!ismouseclick(WM_LBUTTONDOWN));
			getmouseclick(WM_LBUTTONDOWN, pnt[1].x,pnt[1].y);
			putpixel(pnt[1].x,pnt[1].y,15);
			while(!ismouseclick(WM_LBUTTONDOWN));
			getmouseclick(WM_LBUTTONDOWN, pnt[2].x,pnt[2].y);
			putpixel(pnt[2].x,pnt[2].y,15);
			allshapes[count]->setpoint(pnt,3);//sets the points and number of points		 
			allshapes[count]->draw();//calls draw of triangle
			count++;//increments the count
		}
		//***************************************************************************************************************************************//
		if(mousx<=899 && mousx>=800 && mousy>=0 &&  mousy<=100)//rectangle
		{
			option=2;//option 2 is for rectangle
		}
		//*****************************************************RECTANGLE********************************************************************//
		if (option==2)
		{
			allshapes[count]=new Rect;//points towards a rectangle
			while(!ismouseclick(WM_LBUTTONDOWN));
			getmouseclick(WM_LBUTTONDOWN, x1, y1);
			putpixel(x1,y1,15);
			pnt[0].x=x1; 
			pnt[0].y=y1;
			while(!ismouseclick(WM_LBUTTONDOWN));
			getmouseclick(WM_LBUTTONDOWN, x2, y2);
			putpixel(x2,y2,15);
			pnt[1].x=x2;
			pnt[1].y=y2;
			allshapes[count]->setpoint(pnt,2);		 //sets points and number of points
			allshapes[count]->draw();//calls draw of rectangle
			count++;//increments the index
		}
		//*************************************************************************************************************//
		if(mousx<=800 && mousx>=700 && mousy>=100 &&  mousy<=200)//circle
		{

			option=3;//option 3 for circle
		}
		//******************************************************CIRCLE***************************************************//
		if(option==3)
		{

			allshapes[count]=new Circle;//pints to a new circle
			while(!ismouseclick(WM_LBUTTONDOWN));

			getmouseclick(WM_LBUTTONDOWN, x1, y1);
			if(x1<700){
				putpixel(x1,y1,15);
				pnt[0].x=x1; 
				pnt[0].y=y1;
			}
			while(!ismouseclick(WM_LBUTTONDOWN));

			getmouseclick(WM_LBUTTONDOWN, x2, y2);
			if(x2<700){
				putpixel(x2,y2,15);
				pnt[1].x=x2;
				pnt[1].y=y2;
			}
			allshapes[count]->setpoint(pnt,2);// sets points and number of points		 
			allshapes[count]->draw();//calls draw of circle also sets the radius of the circle inthis function
			count++;//increments the index
		}//******************************************************************************************************************//
		if(mousx<=899 && mousx>=800 && mousy>=100 &&  mousy<=200)//polygon
		{
			option=4;//option 4 is a polygon
		}
		//**********************************************************POLYGON***************************************************//
		if(option==4)
		{

			allshapes[count]=new polygon;
			point *p = new point[15];   int ind = 0;
			while(!ismouseclick(WM_RBUTTONDOWN))
			{
				if(ismouseclick(WM_LBUTTONDOWN) )            // draw polygon
				{
					int _x = mousex(), _y = mousey();
					p[ind].x=_x;
					p[ind].y=_y;
					fillpolygon[2*ind]=_x;
					fillpolygon[2*ind+1]=_y;
					putpixel(_x,_y,15);
					ind++;
					clearmouseclick(WM_LBUTTONDOWN);
				}
			}
			clearmouseclick(WM_RBUTTONDOWN);
			allshapes[count]->setpoint(p,ind);
			allshapes[count]->draw();
		}		

		//**********************************************************************************************************************//
		if(mousx<=800 && mousx>=700 && mousy>=200 &&  mousy<=300)//line
		{
			option=5;//option 5 is given to line
		}
		//******************************************************************LINE************************************************//
		if(option==5)
		{
			allshapes[count]=new Line;//points towards a line
			while(!ismouseclick(WM_LBUTTONDOWN));
			getmouseclick(WM_LBUTTONDOWN, x1, y1);
			putpixel(x1,y1,15);
			pnt[0].x=x1; 
			pnt[0].y=y1;
			while(!ismouseclick(WM_LBUTTONDOWN));
			getmouseclick(WM_LBUTTONDOWN, x2, y2);
			putpixel(x2,y2,15);
			pnt[1].x=x2;
			pnt[1].y=y2;
			allshapes[count]->setpoint(pnt,2);//sets the two points		 
			allshapes[count]->draw();//calls draw of line
			count++;//increments the count
		}
		//***********************************************************************************************************************//
		if(mousx<=899 && mousx>=800 && mousy>=200 &&  mousy<=300)//curve
		{
			option=6;//option 6 is for a curve
		}
		//***************************************************************CURVE*****************************************************//
		if(option==6)
		{
			allshapes[count]=new Curve;
			point *cp = new point[15];   int cind = 0;
			while(!ismouseclick(WM_RBUTTONDOWN))
			{
				if(ismouseclick(WM_LBUTTONDOWN) )            // draw curve
				{
					int _x = mousex(), _y = mousey();
					putpixel(_x,_y,15);
					cp[cind].x=_x;
					cp[cind].y=_y;
					cind++;
					clearmouseclick(WM_LBUTTONDOWN);
				}
			}
			clearmouseclick(WM_RBUTTONDOWN);
			allshapes[count]->setpoint(cp,cind);
			allshapes[count]->draw();
		}		
		if(mousx<=800 && mousx>=700 && mousy>=600 &&  mousy<=699)//save
		{
			option=7;
		}
		if(option==7)
		{
			 writeimagefile("paint.bmp");
			 cout<<"save successful";
		}
		if(mousx<=899 && mousx>=800 && mousy>=600 &&  mousy<=699)//load
		{
			option=8;
		}
		if(option==8)
		{
			char arr[10];
			cout<<"enter name of image";
			cin>>arr;
			printimage(arr);
			cout<<"load image successful";
		}
		//**************************************************************************************************************************//
		//**************************************************************************************************************************//   
		if(mousx<=899 && mousx>=700 && mousy>=400 &&  mousy<=450)//check for bucket
		{
			cout<<"paint bucket";
			option=11;//option given to paint bucket
		}
		if(mousx<=899 && mousx>=700 && mousy>=300 &&  mousy<=400)//check for eraser
		{
			cout<<"ERASER";
			option=12;//option given to eraser
		}
		//*******************************************Eraser selected*******************************************************************//
		if(option==12)
		{
			while(!ismouseclick(WM_LBUTTONDOWN));
			getmouseclick(WM_LBUTTONDOWN,x1,y1);
				pnt[0].x=x1;
				pnt[0].y=y1;
				for(int i=0;i<count;i++)
				{
					if (allshapes[i]->lieson(pnt[0]))
					{
						setcolor(BLACK);
						allshapes[i]->draw();
						delete [] allshapes[i];
					}
				}
			}
		//****************************************************Bucket selected************************************************************//
		if(option==11)
		{
			while(!ismouseclick(WM_LBUTTONDOWN));

			getmouseclick(WM_LBUTTONDOWN,mousx1,mousy1);
			if(mousx1>700)
			{
				if(mousx1<=800 && mousx1>=700 && mousy1>=450 &&  mousy1<=500)
				{
					coloroption=1;//Blue color selected
					cout<<"Blue selected";
				}
				if(mousx1<=899 && mousx1>=800 && mousy1>=450 &&  mousy1<=500)
				{

					coloroption=2;//RED color selected
					cout<<"red selescted";
				}
				if(mousx1<=800 && mousx1>=700 && mousy1>=500 &&  mousy1<=550)
				{
					coloroption=3;//Magenta color selected
					cout<<"magenta selscted";
				}
				if(mousx1<=899 && mousx1>=800 && mousy1>=500 &&  mousy1<=550)
				{
					coloroption=4;//GREEN color selected
					cout<<"Green selected";
				}
				if(mousx1<=800 && mousx1>=700 && mousy1>=550 &&  mousy1<=600)
				{
					coloroption=5;//YELLOW color selected
					cout<<"yellow selected";
				}
				if(mousx1<=899 && mousx1>=800 && mousy1>=550 &&  mousy1<=600)
				{
					coloroption=6;//WHITE color selected
					cout<<"WHITE SELECTED";
				}
			//*******************************************BLUE FILL***********************************************************//
			if(coloroption==1)
			{
				while(!ismouseclick(WM_LBUTTONDOWN));
				getmouseclick(WM_LBUTTONDOWN,check.x,check.y);
				for(int i=0;i<count;i++)
				{
					if(allshapes[i]->lieson(check)==true)
					{
						cout<<"blue filled";
						setfillstyle(SOLID_FILL,BLUE);
						floodfill(check.x,check.y,WHITE);
					}
				}
			}
			//****************************************************************************************************************//
			//**********************************************RED FILL***********************************************************//
			if(coloroption==2)
			{
				while(!ismouseclick(WM_LBUTTONDOWN));
				getmouseclick(WM_LBUTTONDOWN,check.x,check.y);
				for(int i=0;i<count;i++)
				{
					if(allshapes[i]->lieson(check)==false)
					{
						cout<<"red filled";
						setfillstyle(SOLID_FILL,RED);
						floodfill(check.x,check.y,WHITE);
					}
				}
			}
			//**************************************************************************************************************************//
			//******************************************* MAGENTA FILL****************************************************************//
			if(coloroption==3)
			{
				while(!ismouseclick(WM_LBUTTONDOWN));
				getmouseclick(WM_LBUTTONDOWN,check.x,check.y);
				for(int i=0;i<count;i++)
				{
					if(allshapes[i]->lieson(check)==false)
					{
						cout<<"magenta filled";
						setfillstyle(SOLID_FILL,MAGENTA);
						floodfill(check.x,check.y,WHITE);
					}
				}
			}
			//*********************************************************************************************************************//
			//*****************************************GREEN FILL*****************************************************************//	
			if(coloroption==4)
			{
				while(!ismouseclick(WM_LBUTTONDOWN));
				getmouseclick(WM_LBUTTONDOWN,check.x,check.y);
				for(int i=0;i<count;i++)
				{
					if(allshapes[i]->lieson(check)==false)
					{
						cout<<"green filled";
						setfillstyle(SOLID_FILL,GREEN);
						floodfill(check.x,check.y,WHITE);
					}
				}
			}
			//********************************************************************************************************************//
			//***********************************************YELLOW FILL*************************************************************//
			if(coloroption==5)
			{
				while(!ismouseclick(WM_LBUTTONDOWN));
				getmouseclick(WM_LBUTTONDOWN,check.x,check.y);
				for(int i=0;i<count;i++)
				{
					if(allshapes[i]->lieson(check)==false)
					{
						cout<<"yellow filled";
						setfillstyle(SOLID_FILL,YELLOW);
						floodfill(check.x,check.y,WHITE);
					}
				}
			}
			//***************************************************************************************************************//
			//************************************WHITE FILL****************************************************************//
			if(coloroption==6)
			{
				while(!ismouseclick(WM_LBUTTONDOWN));
				getmouseclick(WM_LBUTTONDOWN,check.x,check.y);
				for(int i=0;i<count;i++)
				{
					if(allshapes[i]->lieson(check)==false)
					{
						cout<<" white filled";
						setfillstyle(SOLID_FILL,WHITE);
						floodfill(check.x,check.y,WHITE);
					}
				}
			}
			//**********************************************************************************************************//
		}

	}
}
	//************************************************************EXECUTION LOOP ENDED**********************************************//
	//end of main
}