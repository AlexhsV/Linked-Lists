#include "Lists.hpp"
#include <iostream>
#include <random>
#include <functional>
using namespace std;

/*
  int partition(int arr[], int start, int end){
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}
*/



void frequency_histogram(int ar[], int size){  /*συναρτηση υπολογισμου συχνοτητας εμφανισης στοιχειων στον πινακα ar 
                                                 ο οποιος περιεχει τα στοιχεια της λιστας L*/
                                                 
  Chain<int> histogram;  //δημιουργια λιστας histogram

  bool* check = new bool[size];  //δημιουργια ενος τοπικου δυναμικου πινακα check που βοηθα στην ευρεση συχνοτητας των στοιχειων

  for(int i=0;i<size;i++){   //αρχικοποιηση δυναμικου πινακα με το false
    check[i] = false;
  }

   for(int i=0; i<size; i++){  
      if(check[i]== true){
         continue;
      }
      int count = 1;                     //ορισμος μετρητη ο οποιος μετραει την συχνοτητα εμφανισης ενος στοιχειου στον πινακα ar
      for(int j = i+1; j<size; j++){    
                                          
         if (ar[i] == ar[j]){           //ελεγχος ισοτητας μεταξυ του στοιχειου με το επομενο στον πινακα ar 
            check[j] = true;           //εκχωριση της τιμης true στον πινακα check οταν ισχυει η συνθηκη 
            count++;                  //αυξηση μετρητη count

         }
      }

  //    cout<<"frequency of "<<ar[i]<<" is: " << count << endl;

      histogram.Append(count);   //εισαγωγη count στην νεα λιστα histogram
   
   }

    cout << "The elements of the 'histogram' list are: ";
    histogram.Output(cout);   //εμφανιση  στοιχειων της λιστας histogram

    delete [] check;       //διαγραφη του τοπικου δυναμικου πινακα check
}


void bubble_sort(int ar[], int n){  //συναρτηση ταξινομησησης με ορισματα τον πινακα ar  
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
   
    int* ar = new int[n]; //ορισμος δυναμικου πινακα

    for (int i=0; i < n; i++){                         
      int data_element = random_element();       
      L.Append(data_element);                   //εισαγωγη στοιχειων στην L 
      ar[i]=data_element;                      //εισαγωγη των ιδιων στοιχειων στον πινακα ar
    }

    cout<<"\nThe elements of the 'L' list are: ";
    L.Output(cout);
    cout<<endl;
    cout<<endl;
    
    bubble_sort(ar, n);                       //κληση συναρτησης για ταξινομηση πινακα ar
  //quickSort(ar, 0, n - 1);
    cout<<"\nThe elements of the 'L' list sorted are: ";
    
    int i;
    for (i = 0; i < n; i++)
        cout << ar[i] << " ";  //εμγανιση στοιχειων λιστας L μεσω του πινακα ar
    cout << endl;

    frequency_histogram(ar, n); //κληση συναρτησης υπολογισμου συχνοτητας
   
   
    delete [] ar; //διαγραφη δυναμικου πινακα ar

    return 0;
 }