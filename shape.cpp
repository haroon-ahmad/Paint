#include"shapes.h"
#include "graphics.h"
//********************************************implemenation of class line*************************************************************//
Line::Line()
{
	size=2;
	p=new point [size];//as a line is drawn by 2 points so given asize of 2
	 color=WHITE;//sets white by default
	 fill=false;//sets by default

}
void Line::setfill(bool _fill)
{
	fill=_fill;
}
bool Line::lieson(point _p)
{
	cout<<"alled";
	if(p[0].x==_p.x && p[0].y==_p.y)//checking if the point given is any of the two points of lines
		return true;
	if(p[1].x==_p.x && p[1].y==_p.y)
		return true;

	return false;
}
void Line::setcolor(int _color)
{
	color=_color;
}
void Line::draw()
{
	cout<<"draw line";
	line(p[0].x,p[0].y,p[1].x,p[1].y);//function of drawing a line
}
void Line::setpoint(point *_p,int _count)
{
	p[0]=_p[0];//sets the points
	p[1]=_p[1];
}
//*************************************************************************************************************************************//
//************************************************Implementaion of class rectangle******************************************************//
Rect::Rect()
{
	size=2;
	p=new point [size];//as  we require two points for the drawing of a rectangle
	 color=WHITE;
	 fill=false;

}
void Rect::setfill(bool _fill)
{
	fill=_fill;
}
bool Rect::lieson(point _p)
{
	if(_p.x<=p[1].x && _p.x>=p[0].x && _p.y>=p[1].y && _p.y<=p[0].y)//checks if the point is within the rectangle
	{
		return true;
	}
	return false;
}
void Rect::setcolor(int _color)
{
	color=_color;
}
void Rect::draw()
{
	cout<<"Rectangle";
	rectangle(p[0].x,p[0].y,p[1].x,p[1].y);//function to draw a rectangle
}
void Rect::setpoint(point *_p,int _count)
{
	p[0]=_p[0];
	p[1]=_p[1];//sets the two points
}
//**************************************************************************************************************************************//
//****************************************************implemetnation of circle*********************************************************//
Circle::Circle()
{
	size=2;
	p=new point [size];//one point is midpoint and other on the circumference of desired circle
	 color=WHITE;
	 fill=false;

}
void Circle::setfill(bool _fill)
{
	fill=_fill;
}
bool Circle::lieson(point _p)
{
	cout<<"\ncalled\n";
	int _radius;
	float s=(_p.x-p[0].x)*(_p.x-p[0].x)+(_p.y-p[0].y)*(_p.y-p[0].y);//takes out the radius of a point given and checks whether the point lies within the circle
	_radius=sqrt(s);
	if(_radius<=radius)
		return true;
	return false;
}
void Circle::setcolor(int _color)
{
	color=_color;
}
void Circle::draw()
{
	cout<<"draw circle";
	int x=(p[1].x-p[0].x)*(p[1].x-p[0].x);
		int y=(p[1].y-p[0].y)*(p[1].y-p[0].y);
		float s=x+y;
		radius=sqrt(s);//takesoutradius
		if( (700-p[0].x)<radius)//cheks if circle is enoughto fit in the window
			return;
		circle(p[0].x,p[0].y,radius);
}
void Circle::setpoint(point *_p,int _count)
{
	p[0]=_p[0];
	p[1]=_p[1];//sets the two points
}
//*****************************************************************************************************************************************//
//***********************************************************implemntation of polygon******************************************************//
polygon::polygon()
{
	size=0;
	p=NULL;//because we do not know the sizeof polygon
	 color=WHITE;
	 fill=false;

}
void polygon::setpoint(point *_p,int _count)
{
	size=_count;
	p=new point[_count];//initiizes the array with number of points given by user
	for(int i=0;i<_count;i++)
	{
		p[i]=_p[i];//loop to set the points
	}
	cout<<"polygon";
}
void polygon::setfill(bool _fill)
{
	fill=_fill;
}
bool polygon::lieson(point _p)//checks if point lies in the polygon
{
      int   i, j=size-1 ;
  bool  flag=false      ;

  for (i=0; i<size; i++) {
    if ((p[i].y< _p.y && p[j].y>=_p.y ||   p[j].y< _p.y && p[i].y>=_p.y)   &&  (p[i].x<=_p.x || p[j].x<=_p.x))
	{
      flag^=(p[i].x+(_p.y-p[i].y)/(p[j].y-p[i].y)*(p[j].x-p[i].x)<_p.x); 
	}
    j=i; 
  }

  return flag;
}
void polygon::setcolor(int _color)
{
	color=_color;
}
void polygon::draw()
{
	cout<<"draw Polygon";
	for(int i=0;i<size-1;i++)
	{
		line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);//draws the polygon by connecting the points with lines
	}
	line(p[size-1].x,p[size-1].y,p[0].x,p[0].y);
}
//***************************************************************************************************************************************//

//****************************************************implemention of triangle**********************************************************//
Triangle::Triangle()
{
	size=0;
	p=new point [3];//user gives three points
	 color=WHITE;
	 fill=false;

}
void Triangle::setpoint(point *_p,int _count)
{
	for(int i=0;i<_count;i++)
	{
		p[i]=_p[i];
	}
}
void Triangle::setfill(bool _fill)
{
	fill=_fill;
}
bool Triangle::lieson(point _p)//checksif point lies in the triangle same as polygon
{
      int   i, j=size-1 ;
  bool  flag=false      ;

  for (i=0; i<size; i++) {
    if ((p[i].y< _p.y && p[j].y>=_p.y ||   p[j].y< _p.y && p[i].y>=_p.y)   &&  (p[i].x<=_p.x || p[j].x<=_p.x))
	{
      flag^=(p[i].x+(_p.y-p[i].y)/(p[j].y-p[i].y)*(p[j].x-p[i].x)<_p.x); 
	}
    j=i; 
  }

  return flag;
}
void Triangle::setcolor(int _color)
{
	color=_color;
}
void Triangle::draw()
{
	line(p[0].x,p[0].y,p[1].x,p[1].y);//connects the points
	line(p[1].x,p[1].y,p[2].x,p[2].y);
	line(p[2].x,p[2].y,p[0].x,p[0].y);
}
//****************************************************************************************************************************************//

//*****************************************************implemenation of curve***********************************************************//
Curve::Curve()
{
	size=0;
	p=NULL;//initializes with null
	 color=WHITE;
	 fill=false;

}
void Curve::setpoint(point *_p,int _count)
{
	size=_count;
	p=new point[_count];//initiizes the array with number of points given by user
	for(int i=0;i<_count;i++)
	{
		p[i]=_p[i];//loop to set the points
	}
}
void Curve::setfill(bool _fill)
{
	fill=_fill;
}
bool Curve::lieson(point _p)//checks if point is on any of the two endpoints
{
     if(p[0].x==_p.x && p[0].y==_p.y)
		return true;
	if(p[size].x==_p.x && p[size].y==_p.y)
		return true;

  return false;
}
void Curve::setcolor(int _color)
{
	color=_color;
}
void Curve::draw()
{
	cout<<"draw curve";
	for(int i=0;i<size-1;i++)
	{
		line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);//draws the polygon by connecting the points with lines
	}
}
//******************************************************************************************************************************************//