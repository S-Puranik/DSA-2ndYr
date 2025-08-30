#include <iostream>
#include <cstring>
using namespace std;

const int MAX_REQUESTS = 100;
const int MAX_TICKETS = 10;

string bookingQueue[MAX_REQUESTS];
string cancellationQueue[MAX_REQUESTS];
int frontB = -1, rearB = -1;
int frontC = -1, rearC = -1;
int Tickets = MAX_TICKETS;

int EnqueueBooking(string name)
{
    if((rearB + 1) % MAX_REQUESTS == frontB)
    {
        cout << "\nBooking Queue Full.";
        return 0;
    }
    if(frontB == -1 && rearB == -1)
    {
        frontB = 0;
        rearB = 0;
    }
    else
    {
        rearB = (rearB + 1) % MAX_REQUESTS;
    }
    bookingQueue[rearB] = name;
    cout << "\nBooking request added for: " << name;
    return 1;
}

int EnqueueCancellation(string name)
{
    if((rearC + 1) % MAX_REQUESTS == frontC)
    {
        cout << "\nCancellation Queue Full.";
        return 0;
    }
    if(frontC == -1 && rearC == -1)
    {
        frontC = 0;
        rearC = 0;
    }
    else
    {
        rearC = (rearC + 1) % MAX_REQUESTS;
    }
    cancellationQueue[rearC] = name;
    cout << "\nCancellation request added for: " << name;
    return 1;
}

string DequeueBooking()
{
    if(frontB == -1)
    {
        return "";
    }
    string name = bookingQueue[frontB];
    if(frontB == rearB)
    {
        frontB = -1;
        rearB = -1;
    }
    else
    {
        frontB = (frontB + 1) % MAX_REQUESTS;
    }
    return name;
}

string DequeueCancellation()
{
    if(frontC == -1)
    {
        return "";
    }
    string name = cancellationQueue[frontC];
    if(frontC == rearC)
    {
        frontC = -1;
        rearC = -1;
    }
    else
    {
        frontC = (frontC + 1) % MAX_REQUESTS;
    }
    return name;
}

void ProcessBooking()
{
    if(Tickets <= 0)
    {
        cout << "\nNo tickets available at the moment.";
        return;
    }

    if(frontB == -1)
    {
        cout << "\nNo booking requests in the queue.";
        return;
    }

    string name = DequeueBooking();
    Tickets--;
    cout << "\nTicket successfully allocated to: " << name;
    cout << "\nTickets left: " << Tickets;
}

void ProcessCancellation()
{
    if(frontC == -1)
    {
        cout << "\nNo cancellation requests in the queue.";
        return;
    }

    string name = DequeueCancellation();
    Tickets++;
    cout << "\nTicket successfully cancelled for: " << name;
    cout << "\nTickets available now: " << Tickets;

    if(frontB != -1)
    {
        cout << "\nProcessing pending booking request due to cancellation...";
        ProcessBooking();
    }
}

void DisplayStatus()
{
    cout << "\n--- Current System Status ---";
    cout << "\nAvailable Tickets: " << Tickets;

    cout << "\nBooking Queue: ";
    if(frontB == -1)
    {
        cout << "Empty";
    }
    else
    {
        int i = frontB;
        while(true)
        {
            cout << bookingQueue[i] << " ";
            if(i == rearB) break;
            i = (i + 1) % MAX_REQUESTS;
        }
    }

    cout << "\nCancellation Queue: ";
    if(frontC == -1)
    {
        cout << "Empty";
    }
    else
    {
        int i = frontC;
        while(true)
        {
            cout << cancellationQueue[i] << " ";
            if(i == rearC) break;
            i = (i + 1) % MAX_REQUESTS;
        }
    }

    cout << endl;
}

int main()
{
    int choice;
    string name;

    while(true)
    {
        cout << "\n\n Railway Reservation Menu:";
        cout << "\n1. Add Booking Request";
        cout << "\n2. Add Cancellation Request";
        cout << "\n3. Process Booking";
        cout << "\n4. Process Cancellation";
        cout << "\n5. Display Status";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nEnter passenger name for booking: ";
                cin >> name;
                EnqueueBooking(name);
                break;

            case 2:
                cout << "\nEnter passenger name for cancellation: ";
                cin >> name;
                EnqueueCancellation(name);
                break;

            case 3:
                ProcessBooking();
                break;

            case 4:
                ProcessCancellation();
                break;

            case 5:
                DisplayStatus();
                break;

            case 6:
                cout << "\nExiting...";
                return 0;

            default:
                cout << "\nInvalid choice.";
        }
    }
}
