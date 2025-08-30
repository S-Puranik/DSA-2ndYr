// Name: Siddhant Puranik Roll: A-327
#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;
int QUEUE[MAX_SIZE];
int FRONT = -1;
int REAR = -1;

void Enqueue(int x)
{
    if(FRONT == -1 && REAR == -1)
    {
        FRONT = 0;
        REAR = 0;
    }
    else{REAR = (REAR + 1) % MAX_SIZE;}
    QUEUE[REAR] = x;
}

int Dequeue()
{
    if(FRONT == -1){return -1;}
    int val = QUEUE[FRONT];
    if(FRONT == REAR)
    {
        FRONT = -1;
        REAR = -1;
    }
    else{FRONT = (FRONT + 1) % MAX_SIZE;}
    return val;
}

int Josephus(int n, int k)
{
    FRONT = -1;
    REAR = -1;

    for(int i = 1; i <= n; i++){Enqueue(i);}

    while(!false)
    {
        for(int i = 1; i < k; i++)
        {
            int temp = Dequeue();
            Enqueue(temp);
        }

        int eliminated = Dequeue();
        cout << "\nEliminated: " << eliminated;

        if(FRONT == REAR)
        {
            int survivor = Dequeue();
            cout << "\n\nSurvivor: " << survivor << endl;
            return survivor;
        }
    }
}

int main()
{
    int n, k;
    cout << "Enter number of people: ";
    cin >> n;
    cout << "Enter step count (k): ";
    cin >> k;

    Josephus(n, k);

    return 0;
}

