#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} point_t;
typedef struct {
    point_t p;
    int radius;
} circle_t;

float distance(point_t* p1, point_t* p2){
    int dx = p1->x - p2->x;
    int dy = p1->y - p2->y;
    return sqrt((dx)*(dx) + (dy)*(dy));
} 

int collision(circle_t* c1, circle_t* c2){
    float dist = distance(&(c1->p), &(c2->p));
    float r2 = c1->radius + c2->radius;
    if(dist>r2){
        return 0;
    }else{
        return 1;
    } 
}

int fill_circles(circle_t* circles, unsigned int n){
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i<n; i++){
        circles[i].p.x = rand() % 30;
        circles[i].p.y = rand() % 30;
        circles[i].radius = (rand() % 10)+1;
    }
    return 0;
}

int collisionloop(circle_t* circles, unsigned int n){
    for(unsigned int i=0; i<n; i++){
        for(unsigned int j=i+1; j<n; j++){
            printf("Circle %u & Circle %u collide: %d\n", i+1, j+1, collision(&circles[i], &circles[j]));
        }
    }
}

int main(void){
    unsigned int n;
    point_t a = {
        .x = 0,
        .y = 0
    };
    point_t b = {
        .x = 3,
        .y = 4
    };
    circle_t c1 = {
        .p = a,
        .radius = 5
    };
    circle_t c2 = {
        .p = b,
        .radius = 1
    };; //;
    printf("Distance of a & b: %.3f\n", distance(&a, &b));
    printf("Circles collide: %d\n", collision(&c1, &c2));
    printf("How many circles do you want?\n");
    scanf("%u", &n);
    circle_t* circles = malloc(n * sizeof(circle_t));
    fill_circles(circles, n);
    collisionloop(circles, n);
    free(circles);
    return 0;
}