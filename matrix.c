#include <stdio.h>

#define ROWS 8
#define COLS 10

void printmat(const int* mat, unsigned int rows, unsigned int cols){
    for(unsigned int row =0; row < rows; row++){
        for(unsigned int col=0; col<cols; col++){
            printf("%3d", mat[(row*cols+ col)]);
        }
        printf("\n");
    }
}

void transpose(int* dst, const int* src, unsigned int rows, unsigned int cols){
    for(unsigned int row =0; row < rows; row++){
        for(unsigned int col=0; col<cols; col++){
            dst[(col * rows)+row]= src[(row * cols)+col];
        }
    }    
}

int main(void){
    int mat[ROWS][COLS];
    for(unsigned int row =0; row < ROWS; row++){
        for(unsigned int col=0; col<COLS; col++){
            mat[row][col]= row+1 + col+1;
        }
    }
    printmat((const int*) mat, ROWS, COLS);
    int tmat[ROWS][COLS];
    transpose((int*) tmat,(const int*)mat, ROWS, COLS);
    printmat((const int*)tmat, COLS, ROWS);

    return 0;
}