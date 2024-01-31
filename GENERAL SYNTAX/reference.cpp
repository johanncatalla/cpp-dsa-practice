#include <iostream>
int main()
{   
    enum Points { point2d = 2, point2w,
                  point3d = 3, point3w};
    Points pt2d = point2d;
    std::cout << pt2d << std::endl;
    pt2d = point2w;
    std::cout << pt2d;
    return 0;
}