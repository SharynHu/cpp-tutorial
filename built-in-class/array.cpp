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


    //-----------------------initialization--------------------------------------
    int yams[3] = {1,2,3};
    int *potatoes;
    cout<<typeid(potatoes).name();  //outpus Pi, means pointer to integer.
    potatoes = yams;
    for(int i=0;i<3;i++){
        cout<<potatoes[i]<<" ";
    }
    cout<<endl;

    // You cannot initalize an array using another array
    int *tomatoes[3];
    cout<<typeid(tomatoes).name();  //outpus Pi, means pointer to integer.
    // tomatoes = yams; err: array cannot be left value of an expression because it's not a variable.

    //-----------------------sizeof operator-------------------------------------
    // The size of operator works differently on staticly allocated arrays and dynamicly allocated arrays.
    // For a static array, sizeof operator will output the size of the whole array, i.e., how many bytes this array uses.
    // For a dynamic array, sizeof operator does not know how many bytes it uses, thus it outputs the size of the pointer. For a 32-bit machine, it's 4. For a 64-bit machine, it's 8.
    // Sizeof operator is evaluated at compile time.
    cout<<"The size of yams array is "<<sizeof(yams)<<endl; //outpus 12, that is 3*(4 bytes)=12 bytes
    const int num_yums = 3;
    int* yams_dynamic = new int[num_yums];
    cout<<"The size of the dynamic yams array is "<<sizeof(yams_dynamic)<<endl; //outputs 8
}