#pragma once
#include <iostream>
using namespace std;
struct point// a struct for point
{
	int x;
	int y;
};

class shape// an abstract class
{
protected:
      point *p;//Array for position of points
	  int size;//size of the points array
	  int color;//colorof the shape
	  bool fill;// Whether the shape is filled or not
public:
	virtual void draw()=0;//virtual function of draw
	virtual bool lieson(point _p)=0;// Checks whether a point passed is in the shape or not
	virtual void setcolor(int _color)=0;// Sets the color of the shape
	virtual void setfill(bool _fill)=0;//sets whether the shape is filled or not
	virtual void setpoint(point *_p,int _count)=0;//sets the points array andits size
};

class Line:public shape//inherited class for line.inherited from shape
{
  public:
       Line();
	virtual void draw();
	virtual bool lieson(point _p);
	virtual void setcolor(int _color);
	virtual void setfill(bool _fill);
	virtual void setpoint(point *_p,int _count);
};

class Triangle:public shape//class for triangle
{
public:
	Triangle();
	virtual void draw();
	virtual bool lieson(point _p);
	virtual void setcolor(int _color);
	virtual void setfill(bool _fill);
	virtual void setpoint(point *_p,int _count);

};

class Rect:public shape//class for rectange
{
public:
	Rect();
	virtual void draw();
	virtual bool lieson(point _p);
	virtual void setcolor(int _color);
	virtual void setfill(bool _fill);
	virtual void setpoint(point *_p,int _count);
};
class polygon:public shape//polygon shape
{
public:
	polygon();
	virtual void draw();
	virtual bool lieson(point _p);
	virtual void setcolor(int _color);
	virtual void setfill(bool _fill);
	virtual void setpoint(point *_p,int _count);
};

class Circle:public shape//circle class
{
private:
	double radius;// radius of circle
public:
	Circle();
virtual void draw();
	virtual bool lieson(point _p);
	virtual void setcolor(int _color);
	virtual void setfill(bool _fill);
	virtual void setpoint(point *_p,int _count);
};

class Curve:public shape//class for curve
{
public:
	Curve();
	virtual void draw();
	virtual bool lieson(point _p);
	virtual void setcolor(int _color);
	virtual void setfill(bool _fill);
	virtual void setpoint(point *_p,int _count);
};