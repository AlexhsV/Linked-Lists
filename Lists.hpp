#include <iostream>
using namespace std;


/*In this project we excluded the rest of the methods which are used for linked list functionality because this specific
purpose we did not need them*/

template<class T>
class Chain;


template<class T>
class ChainNode{
    friend Chain<T>;

private:
    T data;
    T data2;
    ChainNode<T> *link;
};
template <class T>
class Chain{

public:
    Chain(){first = 0;}   // constructor
    ~Chain() ;  // destructor

    Chain<T>& Append(const T& x);
    Chain<T>& AppendH(const T& x, const T& b);
    int countInt(const T& x) const;

    void Output(ostream& out) const;

    void OutputH(ostream& out) const;



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

//Append for L list
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

// Append for histogram list (two elements in each node)
template <class T>
Chain<T>& Chain<T>::AppendH(const T& x, const T& b)       //b is the frequency
{// Add x at right end
    // Add b at right end
    ChainNode<T> *y;
    y= new ChainNode<T>;
    y->data = x;
    y ->data2 = b;
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

//Output for L list
template<class T>
void Chain<T>::Output(ostream& out) const
{//Insert the chain elements into the stream out.
    ChainNode<T> *current;

    for(current = first;current;current = current->link){
        cout <<current->data<<"  ";

    }
}


//overload <<
template<class T>
ostream& operator<<(ostream& out,const Chain<T>& x)
{
    x.Output(out);
    return out;
}

//Count the frequency of each element
template<class T>
int Chain<T>::countInt(const T& x) const {
    ChainNode<T>* current = first;
    int intCount = 0;
    while (current && (current->link!=NULL)) {   //check if current is pointing and a node and if the link of the node is different from NULL
        if (current->data == x)   //checking if the data in the node is the same as the element we passed as an argument
            intCount++;
        current = current->link;
    }
    if(current->link==NULL && (current->data==x))  //check for data in last node
    {
        intCount++;
    }
    return intCount;
}

//Output for histogram list(two elements in each node)
template<class T>
void Chain<T>::OutputH(ostream& out) const
{//Insert the chain elements into the stream out.
    ChainNode<T> *current;

    for(current = first;current;current = current->link){
        cout <<"data: "<<current->data<<"  ";
        cout <<"frequency of data: "<<current->data2<<"  ";
        cout<<endl;
    }
}