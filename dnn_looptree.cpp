#include <iostream>
# define ws 2

int main()
{
int size=1024;
int array[size][size]={1};
int filter[ws][ws]={1};
int 
while(size){
for(int i=0;i<size-ws+1;i++){
    for(int j=0;j<size-ws+1;j++){
        
        b[i][j]   = array[i][j] * filter[0][0] +  array[i][j+1] * filter[0][1] + array[i+1][j] * filter[1][0] + array[i+1][j+1] * filter[1][1];
        }
}
 size=size-ws+1;
 
}


    return 0;
}
