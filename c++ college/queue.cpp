#include <iostream>
using namespace std;

class Queue
{
	int rear, front;
	int size;
	int *arr;
    public:
	Queue(int s)
	{
	front = rear = -1;
	size = s;
	arr = new int[s];
	}

	void enQueue(int value){
		if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1)))
		{
			cout<<"===Queue is full==="<<endl;
			return;
		}
		else if (front == -1)
		{
			front = rear = 0;
			arr[rear] = value;
		}
		else if (rear == size-1 && front != 0)
		{
			rear = 0;
			arr[rear] = value;
		}
		else
		{
			rear++;
			arr[rear] = value;
		}

	}
	int deQueue(){
		if (front == -1)
		{
			cout<<"===Queue is empty=="<<endl;
			return -1;
		}

		int data = arr[front];
		arr[front] = -1;
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else if (front == size-1)
			front = 0;
		else
			front++;

		return data;

	}
	void displayQueue(){
		if (front == -1)
	{
		cout<<"===Queue is empty=="<<endl;
		return;
	}
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++)
			cout<<arr[i]<<" ";
	}
	else
	{
		for (int i = front; i < size; i++)
			cout<<arr[i]<<" ";

		for (int i = 0; i <= rear; i++)
			cout<<arr[i]<<" ";
	}
	cout<<endl;
	}
};

int main()
{
	Queue q(5);
	q.enQueue(5);
	q.enQueue(36);
	q.enQueue(49);
	q.enQueue(-6);

	q.displayQueue();

	q.deQueue();
	q.deQueue();

	q.displayQueue();

	q.enQueue(9);
	q.enQueue(85);
	q.enQueue(41);

	q.displayQueue();

	q.enQueue(45);
	return 0;
}

