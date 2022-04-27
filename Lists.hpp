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
        void EachNode(int n) const;
    private:
        ChainNode<T> *first;//pointer to first node
        ChainNode<T> *last;//pointer to last node

};





template<class T>
Chain<T> :: ~Chain()
{//Chain destructor. Delete all nodes in chain
    ChainNode<T> *next;//next node
    while(first)
    {
        next = first->link;
        delete first;
        first = next;

    }

}

template<class T>
int Chain<T>::Length() const
{// Return the number of elements in the chain
    ChainNode<T> *current = first;
    int len = 0;
    while(current)
    {
        len++;
        current=  current->link;
    }
    return len;

}

template<class T>
int Chain<T>::Find(int k) const
{// Set x to k'th element in the chain.
 //Return -1 if no k'th; return x otherwise.
    if(k<1) 
        throw out_of_range("Invalid element location in Find");// no k'th
    ChainNode<T> *current = first;
    int index = 1;//index of current
    while (current && index < k )
    {
        current = current->link;
        index++;
        
    }
     
    if(current){    
       int x = current->data;
        return x;
    }

    return -1;    
     
}

template<class T>
bool Chain<T>::Find_List(int k, T& x) const
{// Set x to the k'th element in the chain.
    // Return false if no k'th; return true otherwise.
    if (k < 1) return false;
        ChainNode<T> *current = first;
    int index = 1; // index of current
    while (index < k && current) 
    {
        current = current->link;
        index++;
    }
    if (current)
     {
        x = current->data;
        return true;
    }
    return false; // no k'th element
}




template<class T>
int Chain<T>::Search(const T& x) const
{//Locate x.Return position of x if found
 //return 0 if x not in the chain.
    ChainNode<T> *current = first;
    int index = 1;//index of current
    while (current && current->data !=x)
    {
        current = current->link;
        index++;
    }
    if(current)
        return index;
    return 0;   
}


template<class T>
Chain<T>& Chain<T>::Delete(int k)
{// Set x to the k'th element and delete it.
// throw outofbounds exception if no k'th element.
    if (k < 1 || !first )
        throw out_of_range("Invalid element location in Delete");// no k'th

    // p will eventually point to k'th node
    ChainNode<T> *p = first;

    //move p to k'th &remove from chain
    if(k==1)//p already at k'th
        first = first->link; // remove 
    else
    {
        ChainNode<T> *q = first;
        for (int index =1; index< k-1 && q;index++)
        {
            q=q->link;
        }    
        if(!q || !q->link)
            throw out_of_range("Invalid element location in Delete");//no k'th
        p = q->link;//k'th
        if(p==last)
            last = q;
        q->link = p->link;//remove from chain

    }
    
    delete p;
    return *this;       

}



template<class T>
Chain<T>& Chain<T>::Insert(int k, const T& x)
{//Insert x after k'th.
//throw exception if no k'th.
//throw exception if no space.
    if (k<0)
        throw length_error("No space in list to add new element in Insert");
    //p will eventually point to k'th
    ChainNode<T> *p = first;
    for (int index= 1;index <k && p; index++)
    {//move p to k'th
        p = p->link;
    }    
    if (k > 0 && !p)
        throw out_of_range("Invalid element location in Insert");

    //insert
    ChainNode<T> *y = new ChainNode<T>;
    y->data = x;
    if (k)
    {//Insert after p
        y->link = p->link;
        p->link = y;

    }else
    {//insert as first element
        y->link = first;
        first = y;

    }
        

    if(!y->link)
        last =y;//new last element    
    return *this;

}

template<class T>
Chain<T>& Chain<T>::Replace(int k, const T& x)
{//Insert  k'th with x.
//throw exception if no k'th.

    
    //p will eventually point to k'th
    ChainNode<T> *p = first;
    for (int index= 1;index <k && p; index++)
    {//move p to k'th
        p = p->link;
    }    
    if (k > 0 && !p)
        throw out_of_range("Invalid element location in Replace");

    p->data =x;
    return *this;

}

template <class T>
Chain<T>& Chain<T>::Append(const T& x)
{// Add x at right end.
    ChainNode<T> *y;
    y= new ChainNode<T>;
    y->data = x;
    y->link = 0;
    if(first)
    {//chain is not empty
        last->link =y;
        last =y;

    }
    else // chain is empty
        first = last = y;


    
    return *this;



}

template <class T>
void Chain<T>::Swap(int i , int j)
{
    //swaps i with j.
   int temp;
   ChainNode<T> *currentlink = first;
   ChainNode<T> *currentlink2=first;
   int index =1;
   while(currentlink && index<j)
   {
       currentlink=currentlink->link;
       index+=1;//moving index to j
   }
   temp=currentlink->data;//saving data of j
   
   index=1;
   while(currentlink2 && index<i)
   {
       currentlink2=currentlink2->link;
        index+=1;//moving index to i.
   }
   currentlink->data=currentlink2->data;//puts i's data to j's
   currentlink2->data=temp;//puts temp's(j's)data to i's.

}

template<class T>
void Chain<T>::Output(ostream& out) const
{//Insert the chain elements into the stream out.
    ChainNode<T> *current;

    for(current = first;current;current = current->link){
        cout <<current->data<<"  ";

    }
}

/*
template<class T>
void Chain<T>::EachNode(int n) const
{//Insert the chain elements into the stream out.
    ChainNode<T> *current;

    int myarrayValues[n]; 
    int myarrayPlithos[n];      //arxikopoihsh me 0?
    for(current = first;current;current = current->link){
            static int count = -1;
            int ar = current->data ;

            int i = 0;
            bool F = false;
            while (i < count){                  //checks if ar is already inside the array
                if (ar == myarrayValues[i]){
                    int myarrayPlithos[i]= myarrayPlithos[i] + 1;
                    F = true;
                    break;
                }
                i++;
            }

             count == i;
            if (F == false){
                count++;
                myarrayValues[count] = ar;
                myarrayPlithos[count] = 1;
            }
               
   }

    for(int i=0; i < n; i++){
        cout << myarrayValues[i] << " , " << myarrayPlithos[i] << endl;
    }

}
*/

//overload <<
template<class T>
ostream& operator<<(ostream& out,const Chain<T>& x)
{

    x.Output(out);
    return out;
}
