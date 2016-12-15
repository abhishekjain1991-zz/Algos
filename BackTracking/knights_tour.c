#include <stdio.h>
#include <stdbool.h>
#define N 8
/* Matrix to store the visited blocks */
bool chess_board[N][N] = {false};

/* Recursive function to calculate each move */
bool move(int x, int y, int count){
    /* If out of bounds return false straight away */
    if( x > N-1 || y > N-1 || x < 0 || y < 0){
        return false;
    }

    if (!chess_board[x][y]){
        /* not visited yet; Visit it now */
        chess_board[x][y] = true;
        count ++;

        if((count == N*N) || 
               move (x+2, y+1, count) ||
               move (x+1, y+2, count) ||
               move (x-1, y+2, count) ||
               move (x-2, y+1, count) ||
               move (x-2, y-1, count) ||
               move (x-1, y-2, count) ||
               move (x+1, y-2, count) ||
               move (x+2, y-1, count)
              ){
            /* If all boxes visted return true */
                    /* OR */
            /*either of the 8 moves returns true*/
            printf("%d ",(x + y*N));
            return true;
        }else{
            count --;
            chess_board[x][y] = false;
            return false;
        }
    }else{
        /* Box is already visited */
        return false;
    }
}


int main(){
    if(!move(0,0,0)){
        printf ("Sorry no result found: Try different starting co-ordinates\n");
    }
}
