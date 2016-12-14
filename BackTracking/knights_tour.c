#include <stdio.h>
#include <stdbool.h>
/* Matrix to store the visited blocks */
bool chess_board[8][8] = {false};

/* Recursive function to calculate each move */
bool move(int x, int y, int count){
    /* If out of bounds return false straight away */
    //printf("[%d,%d], %d\n",x,y,count);
    if( x > 7 || y > 7 || x < 0 || y < 0){
        return false;
    }

    if (!chess_board[x][y]){
        /* not visited yet; Visit it now */
        chess_board[x][y] = true;
        count ++;

        if((count == 63) || 
                 move (x+2, y-1, count) ||
                 move (x+2, y+1, count) ||
                 move (x-2, y-1, count) ||
                 move (x-2, y+1, count) ||
                 move (x+1, y+2, count) ||
                 move (x-1, y+2, count) ||
                 move (x+1, y-2, count) ||
                 move (x-1, y-2, count)
                ){
            /* If all boxes visted return true */
                    /* OR */
            /*either of the 8 moves returns true*/
            printf("%d ",(x + y*8));
            return true;
        }else{
            chess_board[x][y] = false;
            return false;
        }
    }else{
        /* Box is already visited */
        return false;
    }
}


int main(){
    move(0,0,0);
}
