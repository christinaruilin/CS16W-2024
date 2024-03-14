#include <iostream>
using namespace std;
//using class need a blue print 

class DayOfYear{
    public: //这个是公用的 accessible by the object 
         void output(); //member function declaration just declare it 
         //可以只在class 里面declare 在class 外面写definition
         //也可以在class里面直接declare和definition 
        

    private://use within the class or use the public access function to access the private value 
          int month;
         int day;

}; //this is the whole class
//different classes can have same nameed member function 比如说不同的class里面可以有一样的function 但是access的对象不一样 

//constructor can be used to initialize member variable when an object is declared 
//a constructor is a member function that is usually public 
//a constructor is automatically called when an ovjectc of the class is delcared 
DayOfYear::DayOfYear(){
    


}

void DayOfYear:: output(){ //必须要include 这个class 如果在class外面进行definition :: 是scope 的标志
    cout << "month = "<< month;
    cout << endl;

}