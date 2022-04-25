#include "Lists.hpp"
#include <iostream>
#include <random>
#include <functional>
using namespace std;

int main() {
    
    Chain<int> L;
    
    int n;
    do {
        cout << "Enter the size of the list, named 'L': ";
        cin >> n;
        if (n <= 0){
            cout << "Invalid size, please try again!\n" << "TIP: (the size of the list must be an integer greater than 0)\n \n";
        }
    } while (n <= 0);

    default_random_engine generator;
    uniform_int_distribution<int> data_element_distribution(0, 100);
    auto random_element = bind(data_element_distribution, generator);
   
    
    for (int i=0; i < n; i++){
      int data_element = random_element();
   //   cout << data_element << endl ;
      L.Append(data_element);
    }


    cout << "Length = " << L.Length() << endl;

    

    
  



    return 0;
 }