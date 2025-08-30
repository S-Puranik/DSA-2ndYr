// Name: Siddhant Puranik Roll: A-327
#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
int QUEUE[MAX_SIZE];
int FRONT = -1;
int REAR = -1;

int Enqueue(int x)
{
    if(REAR == MAX_SIZE -1)
    {
            cout << "\nQueue Overflow";
            return 0;
    }
    else if(FRONT == -1 && REAR == -1)
    {
        FRONT = 0;
        REAR = 0;
    }
    else{REAR++;}
    QUEUE[REAR] = x;
    cout << "\nSuccessfully queued the element: " << x;
    return 1;
}

int Dequeue()
{
    if(FRONT == -1 || FRONT > REAR){cout<< "\nQueue Underflow"; return 0;}
    else{
        int val = QUEUE[FRONT];
        FRONT++;
        cout << "\nSuccessfully dequeued the element: " << val;
        return 1;
    }
}

int Front()
{
    if(FRONT == -1 || FRONT > REAR){cout<< "\nNo Elements at front."; return 0;}
    else{cout<< "\nElement at front: " << QUEUE[FRONT];return 1;}
}

int Rear()
{
    if(REAR == -1 || FRONT > REAR){cout<< "\nNo Elements at rear."; return 0;}
    else{return QUEUE[REAR]; return 1;}
}

bool isEmpty()
{
    if(FRONT == -1 || FRONT > REAR){return true;}
    else{return false;}
}

bool isFull()
{
    if(REAR == MAX_SIZE-1){return true;}
    else{return false;}
}

int Size()
{
    if(FRONT == -1 || FRONT > REAR){cout << "\nQueue is Empty."; return -1;}
    else{cout << "\nSize of Queue: "<< REAR-FRONT+1; return 1;}
}

int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Rear();
    Enqueue(50);
    Size();
    if(isFull()){cout<<"\nQueue is Full.";}
    else{cout << "Queue is not full.";}
    Enqueue(50);
    Rear();
    Dequeue();
    Dequeue();
    Front();
    Dequeue();
    Size();
    Dequeue();
    Front();
    Dequeue();
    if(isEmpty()){cout<<"\nQueue is Empty.";}
    else{cout<< "queue is not empty.";}
    Dequeue();
    Front();
}
