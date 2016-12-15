#include <stdio.h>
#include <stdbool.h>
#define N 4

int maze[N][N] = {{1,0,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,1}};

int rat_move(int x, int y){
    if(x==N-1 && y==N-1){
        //reached the end
        printf("[%d][%d]\n",x,y);
        return 1;
    }else if (x>N-1 || y>N-1){
        //going out of bounds
        return 0;
    }
    else if(!maze[x][y]){
        //entered unsafe area
        return 0;
    }else if (rat_move(x+1,y) || rat_move(x,y+1)){
        printf("[%d][%d]\n",x,y);
        return 1;
    }
    return 0;
}


int main(){
    printf("\n status is %d",rat_move(0,0));
    return 0;
}
