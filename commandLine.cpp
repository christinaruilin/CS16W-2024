#include <iostream>
using namespace std;
#include <cstdlib>

// int main(int argc, char* argv[]){
//     if(argc!=4){
//         cout << "Usage"<< "Invalid input"<< endl;
//         return 1; //记住在command line的过程中 需要return 1
//     }
//     string op=argv[1];
//     double num1= atof(argv[2]);
//     double num2= atof(argv[3]);
//     double result=0.0;
//     if(op=="add"){
//         result=num1+num2;
//         cout << result<< endl;
//     }
//     else if(op=="sub") {
//         result=num1-num2;
//         cout << result<< endl;
//     }
//     else{
//         cout << "not valid operator"<< endl;
//         return 1; 
//     }
    
//     return 0; 
// }
 
//是4 因为传进去4个参数 然后第一个是main 所以是四个参数
// 然后要是打印出来所有的参数的话就直接 

// int main(int argc, char* argv[]){
//     if(argc!=5){
//         cout << "Usage"<< " Invalid input"<< endl;
//         return 1;


//     }
//     double result=0.0;
//     for(int i=1; i < argc; i++){
//         result+=atof(argv[i]);
        
//     }
//     cout<< result;
//     return 0;

// }

//参数搜索器 
//这种题就需要使用到c++里面自带的函数 更好的帮助完成这个代码

int main(int argc, char* argv[]){
    if(argc!=3){
        cout << "Usage"<< " Invalid input"<< endl;
        return 1;
    }
    string target = argv[1];
    string text= argv[2];

    int count=0;
    int pos= text.find(target); //找到第一次出现的index
    while(pos!=string::npos){
        count++;
        pos=text.find(target, pos+1); //这个函数的意思就是从pos后面的位置继续找 
    }
    cout << target<< " appears"<< count << " times"<< endl;
    return 0;




}
