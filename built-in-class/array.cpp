#include <iostream>
#include <typeinfo>
#include <string.h>

using namespace std;


int main(){
    //----------------------------------------------------------------------
    //1. 数组是一种复合类型,loans的类型不是“数组”，而是“float数组”。
    float loans1[20];
    string s1 = typeid(loans1).name();
    cout<<s1<<endl; //The output is A20_f, meaning that the type of loans1 is array with 20 floats.
    
    float loans2[30];
    string s2 = typeid(loans2).name();
    cout<<s2<<endl; //The output is A30_f, meaning that the type of loans2 is array with 30 floats.
    
    int loans3[30];
    string s3 = typeid(loans3).name();
    cout<<s3<<endl; //The output is A30_i, meaning that the type of loans3 is array with 30 ints.

    //----------------------------------------------------------------------
    //2. the compiler won't check the index of the array, just a warning.
    cout<<loans1[21]<<endl;   // The output is 0
    
}