#include "Lists.hpp"
#include <iostream>
#include <random>
#include <functional>
using namespace std;

void frequency(int arr[], int size){
  Chain<int> histogram;

   bool check[size];
   for(int i=0;i<size;i++){
      check[i] = false;
   }

   for(int i=0; i<size; i++){
      if(check[i]== true){
         continue;
      }
      int count = 1;
      for(int j = i+1; j<size; j++){
         if (arr[i] == arr[j]){
            check[j] = true;
            count++;

         }
      }

      cout<<"frequency of "<<arr[i]<<" is: " << count << endl;

      histogram.Append(count);

      
   }

   histogram.Output(cout);
}

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
   
 
    int ar[n] = {};
    for (int i=0; i < n; i++){
      int data_element = random_element();
   //   cout << data_element << endl ;
      L.Append(data_element);
      ar[i]=data_element;
      cout<<endl;
      cout<<ar[i];
      cout<<endl;
      
    }


    int temp;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(ar[j]>ar[j+1])
                {
                    temp=ar[j];
                    ar[j]=ar[j+1];
                    ar[j+1]=temp;
                }
            }
            cout<<ar[i]<<endl;
        }


    cout << "Length = " << L.Length() << endl;
    cout<<"THE ELEMENTS OF THE LIST ARE: ";
    L.Output(cout);
    cout<<endl;
    frequency(ar, n);
   
   
    
   

    return 0;
 }