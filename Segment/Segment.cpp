#include "Segment.h"
#include <math.h>


Point::Point(double px/*=0*/, double py/*=0*/)
{
	setPoint(px, py);
}

Point::Point(const Point& pt)
{
	*this = pt;
}


void Point::setPoint(double px, double py)
{
	setX( px );
	setY( py );

}


void Point::setPoint(const Point& pt)
{
	setX( pt.getX() );
	setY( pt.getY() );

}


ostream& operator<<(ostream& out, const Point& p)
{
	out << "[" << p.getX() << ", " << p.getY() << "]";
	return out;
}


istream& operator>>(istream& in, Point& p)
{
	double temp;
	in >> temp;
	p.setX(temp);
	in >> temp;
	p.setY(temp);

	return in;
}



void Point::Turn(double alpha) 
{
	Point p(*this);
	setX(p.getX() * cos(alpha) - p.getY() * sin(alpha));
	setY(p.getX() * sin(alpha) + p.getY() * cos(alpha));
}


void Point::Move(double px, double py)
{
	setX(getX() + px);
	setY(getY() + py);

}


void Point::Move(const Point& pt)
{
	setX(getX() + pt.getX());
	setY(getY() + pt.getY());
}


Segment::Segment(double x1/*=0*/, double x2/*=0*/, double y1/*=0*/, double y2/*=0*/)
{
	setSegm( x1, x2, y1, y2 );
}


Segment::Segment(const Point& pt1, const Point& pt2)
{
	setSegm( pt1, pt2 );
}


Segment::Segment(const Segment& segm )
{
	*this = segm;
}

void Segment::setPt1(const Point& pt)
{
	setPt1(pt.getX(), pt.getY());
}

void Segment::setPt2(const Point& pt)
{
	setPt2(pt.getX(), pt.getY());
}


void Segment::setSegm(double ptx1, double ptx2, double pty1, double pty2)
{
	setPt1( ptx1, pty1 );
	setPt2( ptx2, pty2 );
}


void Segment::setSegm(const Point& pt1, const Point& pt2)
{
	setPt1( pt1 );
	setPt2( pt2 );
}

Segment& Segment::operator = (const Segment& s)  
{
	setSegm(s.getPt1(), s.getPt2());
	return *this;
}

ostream& operator<<(ostream& out, const Segment& pt)
{
	out << pt.getPt1() << "--" << pt.getPt2();
	return out;
}

istream& operator>>(istream& in, Segment& pt)
{
	Point x;
	in >> x; 
	pt.setPt1(x);
	in >> x;
	pt.setPt2(x.getX(), x.getY());  
	return in;
}

void Segment::Move(double vx, double vy)
{
	mPt1.Move( vx, vy );
	mPt2.Move( vx, vy );
}

void Segment::Move(const Point& pt) //nowa
{
	mPt1.Move( pt );   
	mPt2.Move( pt );
}

void Segment::Rotate(int alpha)
{
	double radians = radian(alpha);
	Point middlePt = this->srodek();

	Move(-middlePt.getX(), -middlePt.getY());
	mPt1.Turn(radians);
	mPt2.Turn(radians);
	Move(Point(middlePt.getX(), middlePt.getY()));

}


Point Segment::srodek()  
{
	Point pt;
	pt.setX(ave(mPt1.getX(), mPt2.getX()));
	pt.setY(ave(mPt1.getY(), mPt2.getY()));
	return pt;
}



