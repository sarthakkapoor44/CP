#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void generate_int(int count,char* filename){
FILE *file  = fopen(filename,"w");
while(count--){
    int val = rand()%(1000001);
    fprintf(file,"%d\n",val);
    }
    fclose(file);
}
int main(){
    int count=10000;
    for(int i=0;i<10;i++){
        int num = count*(1<<i);
        char filename[50];
        sprintf(filename,"i%d0k.txt",1<<i);
        generate_int(num,filename);
    }
    return 0;
}