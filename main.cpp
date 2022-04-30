#include "Lists.hpp"
#include <iostream>
#include <random>
#include <functional>
using namespace std;


void frequency_histogram(int ar[], int size){  /*function that calculates the frequency of the ar's elements that
                                                 includes the lists's (L) elements*/
                                                 
  Chain<int> histogram;  //creation of histogram list

  bool* check = new bool[size];  //create a topic dynamic array (check) that helps to find the frequency od the list's elements

  for(int i=0;i<size;i++){   //initialize the dynamic array with false state
    check[i] = false;
  }

   for(int i=0; i<size; i++){  
      if(check[i]== true){
         continue;
      }
      int count = 1;                     //create a counter that inlcludes the frequency of every element in array(ar)
      for(int j = i+1; j<size; j++){    
                                          
         if (ar[i] == ar[j]){           //check if the element of array(ar) is equal with next one
            check[j] = true;           //set true to array (check) when the condition the equality is true
            count++;                  //increase count

         }
      }

  //    cout<<"frequency of "<<ar[i]<<" is: " << count << endl;

      histogram.Append(count);   //import count in new list histogram
   
   }

    cout << "The elements of the 'histogram' list are: ";
    histogram.Output(cout);   //print histogram's elements

    delete [] check;       //delete the dynamic array(check)
}


void bubble_sort(int ar[], int n){  //function that sorts the elements of array (ar)  
  for(int i=0; i<n-1; i++){
    for(int j=0; j<n-1; j++){
      if(ar[j]>ar[j+1]){
         swap(ar[j], ar[j + 1]);
      }
    }
  }
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
   
    int* ar = new int[n]; //create dynamic array 
    for (int i=0; i < n; i++){                         
      int data_element = random_element();       
      L.Append(data_element);                   //import elements on L 
      ar[i]=data_element;                      //import the same elements on ar
    }

    cout<<"\nThe elements of the 'L' list are: ";
    L.Output(cout);
    cout<<endl;
    cout<<endl;
    
    bubble_sort(ar, n);                       //call the bubble_sort function
    
    cout<<"\nThe elements of the 'L' list sorted are: ";
    
    int i;
    for (i = 0; i < n; i++)
        cout << ar[i] << " ";  //print the list's L elements through ar array
    cout << endl;

    frequency_histogram(ar, n); //call frequency_histogram function
   
   
    delete [] ar; //delete the dynamic array (ar)

    return 0;
 }