#include <stdio.h> 
#include <stdlib.h> 
#define N 8 

void backTrack(int*, int*, int*, int*, int, void (*)(int*));
void print(int*);

int main(void) { 
    int column[N] = {0};        // 同行是否有皇后
    int slash[2 * N] = {0};     // 右上至左下是否有皇后 
    int backSlash[2 * N] = {0}; // 左上至右下是否有皇后 
    int queens[N] = {0}; 

    backTrack(column, slash, backSlash, queens, 0, print); 
    
    return 0; 
} 

void backTrack(int* column, int* slash, int* backSlash, 
               int* queens, int i, void (*take)(int*)) { 
    if(i >= N) { 
        take(queens); 
    } 
    else { 
        int j;
        for(j = 0; j < N; j++) {
            if(isVisitable(i, j, column, slash, backSlash)) { 
                queens[i] = j; 
                column[j] = slash[i + j] = backSlash[i - j + N] = 1; 
                backTrack(column, slash, backSlash, queens, i + 1, take); 
                column[j] = slash[i + j] = backSlash[i - j + N] = 0;
            } 
        }
    }
}

int isVisitable(int i, int j, int* column, int* slash, int* backSlash) {
   return !(column[j] || slash[i + j] || backSlash[i - j + N]);
}

void print(int* queens) {
    int x, y;
    for(y = 0; y < N; y++) {
        for(x = 0; x < N; x++) {
            printf(" %c", queens[y] == x ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}
