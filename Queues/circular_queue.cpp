#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
int QUEUE[MAX_SIZE];
int FRONT = -1;
int REAR = -1;

int Enqueue(int x)
{
    if((FRONT == 0 && REAR == MAX_SIZE - 1) || (REAR + 1) % MAX_SIZE == FRONT)
    {
        cout << "\nQueue Overflow";
        return 0;
    }
    else if(FRONT == -1 && REAR == -1)
    {
        FRONT = 0;
        REAR = 0;
    }
    else{REAR = (REAR + 1) % MAX_SIZE;}
    QUEUE[REAR] = x;
    cout << "\nSuccessfully queued the element: " << x;
    return 1;
}

int Dequeue()
{
    if(FRONT == -1){cout << "\nQueue Underflow";return 0;}
    else
    {
        int val = QUEUE[FRONT];
        if(FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else{FRONT = (FRONT + 1) % MAX_SIZE;}
        cout << "\nSuccessfully dequeued the element: " << val;
        return 1;
    }
}

int Front()
{
    if(FRONT == -1){cout << "\nNo Elements at front.";return 0;}
    else{cout << "\nElement at front: " << QUEUE[FRONT];return 1;}
}

int Rear()
{
    if(REAR == -1){cout << "\nNo Elements at rear.";return 0;}
    else{cout << "\nElement at rear: " << QUEUE[REAR];return 1;}
}

bool isEmpty()
{
    if(FRONT == -1){return true;}
    else{return false;}
}

bool isFull()
{
    if((FRONT==0 && REAR ==MAX_SIZE - 1) || (REAR + 1)%MAX_SIZE == FRONT){return true;}
    else{return false;}
}

int Size()
{
    if(FRONT == -1){cout << "\nQueue is Empty."; return -1;}
    else if(REAR >= FRONT){cout << "\nSize of Queue: " << REAR-FRONT + 1; return 1;}
    else{cout << "\nSize of Queue: " << MAX_SIZE-FRONT+REAR+1; return 1;}
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
