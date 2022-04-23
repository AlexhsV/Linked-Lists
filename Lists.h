#include <iostream>
using namespace std;

template<class T>
class Chain;


template<class T>
class ChainNode{
    friend Chain<T>;
    
    private:
        T data;
        ChainNode<T> *link;
};
template <class T>
class Chain{
    
    public:
        Chain(){first = 0;}   // constructor
        ~Chain() ;  // destructor

        bool IsEmpty() const {return first == 0;}
        int Length() const ;

        // return the k'th element of list 
        int Find(int k) const;
        // return true if k'th exist and put it in x. return false otherwise
        bool Find_List(int k, T& x) const;
        

        // return position of x
        int Search(const T& x) const;
        
        Chain<T>& Append(const T& x);

        // delete all apearances of k'th element 
        

        // insert x just after k'th element
        Chain<T>& Insert(int k, const T& x);
        //Delete k'th element 
        Chain<T>& Delete(int k);
        Chain<T>& Replace(int k, const T& x);
        
        void Swap(int i,int j);//swaps 2 elements of the given chain
        void Output(ostream& out) const;
    private:
        ChainNode<T> *first;//pointer to first node
        ChainNode<T> *last;//pointer to last node

};

