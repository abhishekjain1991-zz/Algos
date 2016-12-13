#include <stdio.h>
#include <string.h>

char a[3] = "ABC";

void swap(char *x, char *y)
{
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void permute(int start, int end){
    if(start == end){
        printf("%s\n",a);
    }

    int index = start;
    while(index < end){
        swap(a+start,a+index);
        permute(start+1,end);
        swap(a+start,a+index);
        index++;
    }
}

void main(){
    permute(0,3);
}

