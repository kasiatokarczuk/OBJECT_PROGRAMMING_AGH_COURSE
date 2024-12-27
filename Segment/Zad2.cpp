#include <iostream>

#include "Segment.h"

int main()
{

    Segment seg1(Point(1, 1), Point(2, 2));
    cout << "seg1= " << seg1 << endl;

    cout << "Enter the coordinates of the segment's endpoints x1 y1 x2 y2: ";
    cin >> seg1;
    cout << "seg1= " << seg1 << endl;

    cout << "Enter the rotation angle in degrees: ";
    int alpha = 0;
    cin >> alpha;

    cout << "Rotation of the segment: " << seg1 << " by angle " << alpha;
    seg1.Rotate(alpha);
    cout << " == " << seg1 << endl;

    Segment seg2(seg1);
    cout << "seg2 = " << seg2 << endl;
    return 0;

}

