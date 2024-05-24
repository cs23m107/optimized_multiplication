#include<iostream>
#include<chrono>
#define size 4096
#define blocksize 16
int main(){

    int **A = (int **)malloc(sizeof(int *)*size);
    int **B = (int **)malloc(sizeof(int *)*size);
    int **C = (int **)malloc(sizeof(int *)*size);

    for(int i=0;i<size;i++){
        A[i] = (int *)malloc(sizeof(int)*size);
        B[i] = (int *)malloc(sizeof(int)*size);
        C[i] = (int *)malloc(sizeof(int)*size);
        for(int j=0;j<size;j++){
            A[i][j] = 1;
            B[i][j] = 1;
            C[i][j] = 0;
        } 
   }
   

auto start = std::chrono::high_resolution_clock::now();
   for(int i=0;i<size;i=i+blocksize){
    int p=0,q=0;
    for(int j=0;j<size;j=j+blocksize){
        
        for(int k=0;k<size;k=k+blocksize){
            
            for(int l=j;l<blocksize+j;l++){

                for(int m=k;m<blocksize+k;m++){

                    for(int n=i;n<blocksize+i;n++){
                         C[p][q]+=A[l][n] * B[n][m];
                    }q++;
                }p++; q=k;
            }p=j;q=q+blocksize;
        } p = p+blocksize;q=0;
    }
  
   }

   auto end = std::chrono::high_resolution_clock::now();

auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

std::cout<<"Time = "<<duration<<std::endl;

  /* for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            std::cout<<C[i][j]<<" ";
        }
        std::cout<<""<<std::endl;
    }*/

   return 0;
}