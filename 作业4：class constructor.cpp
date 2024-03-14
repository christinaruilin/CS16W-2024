#include <iostream>
using namespace std;


/**************************作业题1.************************************************/

class ZooAnimal  
{
private:
	char *name;
	int cageNumber;
	int weightDate;
	int weight;
public:
   ZooAnimal(char *who, int cage, int date,int weight){
	name=new char[20];//because it asks to initialize to 20 characters 
	strcpy(name, who);
	cageNumber=cage;
	weightDate=date;
	weight=weight;
   }
   ZooAnimal(){
	name="Nameless";
	cageNumber=9999;
	weightDate=101;
	weight=100;
   }
   int getCageNumber()const{
	return cageNumber;
   }
    
};

// 1.  Create the ZooAnimal constructor function.  The function has 4
// parameters -- a character string followed by three integer parameters.
// In the constructor function dynamically allocate the name field (20
// characters), copy the character string parameter into the name field,
// and then assign the three integer parameters to cageNumber,
// weightDate, and weight respectively.




// 2.  Modify the constructor function for ZooAnimal above.  
// Provide default values of "Nameless" for name, 9999 for
// cageNumber, 101 (January 1) for weightDate, and 100 for weight.




// 3.  Write a ZooAnimal member conversion function that converts a type
// ZooAnimal to produce a value of type int.  The function should simply
// return the cageNumber data member.


/**************************作业题2.************************************************/

// create a custom String class in C++ with basic functionalities

// 1.Constructor with no arguments: This allocates the storage for the string object 
//   in the heap and assign the value as a NULL character.

// 2.Constructor with only one argument : It accepts a pointer to a character or we can say 
//   if we pass an array of characters, accepts the pointer to the first character in the array then the constructor of 
//   the String class allocates the storage on the heap memory of the same size as of the passed array 
//   and copies the contents of the array to that allocated memory in heap. It copies the contents using 
//   the strcpy() function declared in cstring library. 
//   Before doing the above operation it checks that if the argument passed is a NULL pointer then 
//   it behaves as a constructor with no arguments.

// (如果copy constructor和move constructor未学过,3\4可不做)

// 3.Copy Constructor: It is called when any object created of the same type from 
//   an already created object then it performs a deep copy. It allocates new space on the 
//   heap for the object that is to be created and copies the contents of the passed object(that is passed as a reference).

// 4.Move Constructor: It is typically called when an object is initialized(by direct-initialization or copy-initialization) 
//   from rvalue of the same type. It accepts a reference to an rvalue of an object of the type of custom string class.

class String{
	public :
	   String(){
		str=new char[1];
        *str='/0'; //在cstring当中 表示结尾的就是这个‘/0’ 所以在使用cstring的时候需要注意最后nullptr的情况
	   }

	   String(const char *s) {
        if (s == nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
    }
	
	private:
	    char* str;

};




int main(int argc, char const *argv[])
{
	
	return 0;
}