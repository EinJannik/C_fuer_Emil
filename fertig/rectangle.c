#include<stdio.h>
#include<math.h>

double rect_area(double min_x, double max_x, double min_y, double max_y)
{
    return((max_x - min_x)*(max_y - min_y));
}

double rect_circ(double min_x, double max_x, double min_y, double max_y)
{
    return((max_x-min_x)*2+(max_y-min_y)*2);
}

double aspect_ratio(double min_x, double max_x, double min_y, double max_y)
{
    return((max_x - min_x)/(max_y - min_y));
}