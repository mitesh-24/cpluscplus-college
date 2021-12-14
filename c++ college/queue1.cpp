#include<iostream>
using namespace std;

class CQueue
{
    public:
    int *array,Size;
    int front,back;
    CQueue(int size)
    {
        Size=size;
        array= new int[size];
        front = back = -1;
    }

    int isFull()
    {
        if((front==back+1)||(front == 0 &&back== Size-1))
            return 1;
        return 0;
    }
    
    int isEmpty()
    {
        if (front == -1) return 1;
    return 0;
    }

    void enqueue(int value)
    {
        cout<<"Pushing the value : "<<value<<endl;
        if (isFull())
            cout<<"Can not push "<<value<<", The Circular Queue is Full."<<endl;
        else
        {
            if (front == -1) front = 0;
            back = (back + 1) % Size;
            array[back] = value;
        }
    }

    int dequeue()
    {
    int element;
    if (isEmpty()) {
        cout<<"The Circular Queue is empty. \n"<<endl;
        return -1;
    }
        element = array[front];
        if (front ==back) {
        front = -1;
        back = -1;
        }

        else {
        front = (front + 1) % Size;
        }
        cout<<"Popping out the value :"<<element<<endl;
        return element;
    
    }

    void Show(){
        int i;
        if (isEmpty()) cout<<"The Circular Queue is empty.\n"<<endl;
        else
        {
            cout<<"----------------------\n";
            cout<<"The Circular Queue is : ";
            for (i=front; i!=back;i= (i+1)%Size)
                cout<<array[i]<<" ";
        cout<<array[i]<<endl;
        cout<<endl;
        }
    }
};

int main() {
   int ch, val, size;
   cout<<"Enter the size of Queaue :"; cin>>size;
   CQueue CQ(size);
    do {
        cout<<" 1)Enqueue\n";
        cout<<" 2)Dequeue\n";
        cout<<" 3)Display\n";
        cout<<" 4)Exit\n";
        cout<<" -------------- \n";

        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch) {
            case 1:
            cout<<"Input for insertion: ";
            cin>>val;
            CQ.enqueue(val);
            CQ.Show();
            break;

            case 2:
            CQ.dequeue();
            CQ.Show();
            break;

            case 3:
            CQ.Show();
            break;

            case 4:
            cout<<"Exit\n";
            break;
            default: cout<<"Incorrect!\n";
        }
    }while(ch != 4);
   return 0;
}