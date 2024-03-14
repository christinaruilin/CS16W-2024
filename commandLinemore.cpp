#include <iostream>
using namespace std;
#include <string>
#include <cstring>
// int main( int argc, char* argv[]){
//     if(argc!=2){
//         cout << "Usage"<< " invalid input numher"<< endl;
//         return 1;
//     }
//     string text= argv[1]; //之所以可以用sting直接来使用就是因为在c++当中有一写char和string的隐形转换
//     string reversed; 

//    for(int i=text.size()-1; i >=0; i--){
//     reversed+=text[i];

//    }
//    cout << reversed<< endl;
//    return 0; 

    


// }

//另外一种写法就是直接用cstring进行遍历

int main(int argc, char* argv[]){
    if(argc!=2){
        cout << "usage"<< "invalid input"<< endl;
        return 1;
    }
    char* text=argv[1];
    int length=strlen(text);
    char* reversed= new char[length+1];//新建一个cstring然后规定cstring的长度
    //cstring的时候要确保就是多给一些空间因为后面都是\0
    reversed[length]='\0'; //确保cstring最后是以

    for(int i=0; i <length;i++){
        reversed[i]=text[length-1-i];
    }
    cout <<reversed<< endl;
    return 1;

}



