#include <iostream>
using namespace std;

//need to have base case : the easiest condition 
//each result is based on the previous one  
//when think about it, think it as another seperate function 
int fib(int n) {
    if(n=0){
        return 0;

    }
    else if(n==1 || n==2){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
        
    }

 bool isPowerOfFour(int n) {
        
    }

int main(){
    return 0;
}


