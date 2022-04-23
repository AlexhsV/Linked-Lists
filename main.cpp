#include "Lists.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    do {
        cout << "Enter the size of the list, named 'L': ";
        cin >> n;
        if (n <= 0){
            cout << "Invalid size, please try again!\n" << "TIP: (the size of the list must be an integer greater than 0)\n \n";
        }
    } while (n <= 0);
    cout << n;

    Chain<int> L;

    cout << "Length = " << L.Length() << endl;


  /*  default_random_engine generator;
    uniform_int_distribution<int> data_element_distribution(0, 100);
    auto random_element = bind(data_element_distribution, generator);
    int data_element = random_element();
  */



    return 0;
 }