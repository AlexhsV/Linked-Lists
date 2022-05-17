#include "Lists.hpp"
#include <iostream>
#include <random>
#include <functional>
using namespace std;

int main() {

   Chain<int> L;
   Chain<int> histogram;
   int n;
   cout << "Enter the size of the list 'L':  ";
   cin >> n;
   while (n <= 0){
      cout << "Invalid size, please try again!\n" << "TIP: (the size of the list must be an integer greater than 0): ";
      cin >> n;
      cout << endl;     }

   default_random_engine generator;
   uniform_int_distribution<int> data_element_distribution(0, 100);
   auto random_element = bind(data_element_distribution, generator);

   for (int i = 0; i < n; i++) {        //insert at the right end random elements to L list
      int data_element = random_element();
      L.Append(data_element);
   }
   cout << "\nThe elements of the 'L' list are: ";  //print elements of L list using Output
   L.Output(cout);
   cout << endl;
   cout << endl;

   //checking if numbers within the limit (0,100) are in L
   for (int i = 0; i < 100; i++) {
      int a = L.countInt(i);      //'a' stores the multitude of each number
      if(a != 0)                     //checking if the number (i) is in L then 'a' will be different from zero
      {
         histogram.AppendH(i,a);
      }

   }
   cout<<"The elements of the 'histogram' list are: \""<<endl;
   histogram.OutputH(cout);

   return 0;
}