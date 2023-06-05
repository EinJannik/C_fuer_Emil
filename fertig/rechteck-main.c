#include<stdio.h>
#include"rectangle.h"

int main(void)
{
    double min_x = 3.5, max_x = 106.9;
    double min_y = 1.1, max_y = 14.5;

    double area = rect_area(min_x, max_x, min_y, max_y);
    printf("Fläche: %.02lf\n", area);
    double circ = rect_circ(min_x, max_x, min_y, max_y);
    printf("Umfang: %.02lf\n", circ);
    double ratio = aspect_ratio(min_x, max_x, min_y, max_y);
    printf("Verhältnis: %.02lf", ratio);

    return 0;
}