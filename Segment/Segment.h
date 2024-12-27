#pragma once
#include <iostream>
using namespace std;

#define PI 3.14159265358979


//----------------POINT-----------------
struct Point
{
    Point(double px=0, double py=0);
    Point(const Point& pt); //copy constructor


    void setX(double px);
	void setY(double py);
	void setPoint(double px, double py);
    void setPoint(const Point& pt); //new setPoint (set point using another point)

    double getX() const;
    double getY() const;

    friend ostream& operator << ( ostream& out, const Point& p );
    friend istream& operator >> ( istream& in, Point& p );

    void Turn(double alpha);  //turn point around the origin (in radians)
    void Move(double px, double py); //move point by a vector defined by a point (vector end point)
    void Move(const Point& pt); //new move (vector end point in the origin coordinate system)


    double mx;
    double my;

};



//------------INLINE FUNCTIONS-----------------
inline void Point::setX(double px)
{
    mx = px;
}

inline void Point::setY(double py)
{
    my = py;
}

inline double Point::getX() const
{
    return mx;
}

inline double Point::getY() const
{
    return my;
}



//--------------SEGMENT-----------------------
class Segment
{
public:
    //Segment(); no default constructor
    Segment(double x1=0, double x2=0, double y1=0, double y2=0);
    Segment(const Point& pt1, const Point& pt2); 
    Segment(const Segment& segm); //copy constructor for segment


    Segment& operator = ( const Segment& s );  //new assignment operator, must return reference to object


public:
    void setPt1(double ptx1, double pty1);  
    void setPt1(const Point& pt);  

    void setPt2(double ptx2, double pty2);  
    void setPt2(const Point& pt); 

    void setSegm(double ptx1, double ptx2, double pty1 ,double pty2 );  
    void setSegm(const Point& pt1, const Point& pt2); 


public:
    const Point& getPt1() const;
    const Point& getPt2() const;

    friend ostream& operator << ( ostream& out, const Segment& pt );
    friend istream& operator >> ( istream& in, Segment& pt );

    void Move(double vx, double vy);
    void Move(const Point& pt); 
    void Rotate(int alpha); //rotate segment by alpha degrees around the segment center

private:
    Point srodek();  //calculates the center point of the segment (returns Point)
    double ave(double x, double y);  
    double radian(int alpha);   //converts degrees to radians

private:
    Point mPt1; //segment endpoints
    Point mPt2;
};




//----------------INLINE FUNCTIONS-------------
inline void Segment::setPt1(double ptx1, double pty1)
{
    mPt1.setPoint( ptx1, pty1 );            
}

inline void Segment::setPt2(double ptx2, double pty2)
{
    mPt2.setPoint (ptx2, pty2 );           
}

inline const Point& Segment::getPt1() const
{
    return mPt1;
}

inline const Point& Segment::getPt2() const
{
    return mPt2;
}

inline double Segment::ave(double x, double y)
{
    return (x + y) / 2;
}

inline double Segment::radian(int alpha)
{
    return alpha * PI / 180;
}