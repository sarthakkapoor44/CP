#include<iostream>

void myPrint(){}

template<typename T,typename... args>
void myPrint(T val,args... var2){
    std::cout<< val << std::endl;
    myPrint(var2...);
    return ;
}

int main(){
//    myPrint(1,2,5.6f,"Hello world");
   const int MAX_AGE = 100;
   int * a = new int;
   a = (int*)&MAX_AGE;
   *a = 5;
   std::cout<< a<<" "<< &MAX_AGE<<std::endl;
   std::cout<< MAX_AGE;

}