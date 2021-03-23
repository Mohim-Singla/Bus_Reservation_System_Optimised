#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

static int bus_count=0;

class Bus_data{
private:
	string name, arrival, departure, source, destination;
	int unique_id;
	string seat_data[20];
public:

	int vacancy=20;
    friend void store();
    friend void reservation();




};

class Bus_data buses[100];

void store()
{
    cout<<"Bus number: "<<bus_count+1<<endl;
    buses[bus_count].unique_id=bus_count+1;
    cout << "Enter Driver's name: ";
    cin>>buses[bus_count].name;
    cout<<"Enter arrival time: ";
    cin>>buses[bus_count].arrival;
    cout<<"Enter departure time: ";
    cin>>buses[bus_count].departure;
    cout<<"Enter source city: ";
    cin>>buses[bus_count].source;
    cout<<"Enter destination: ";
    cin>>buses[bus_count].destination;

    bus_count++;
}

void reservation()
{
    cout<<"Enter bus number: ";
    int choice;
    cin>>choice;
    if (choice>bus_count||choice<=0)
    {
        cout<<"Invalid Choice"<<endl;
        return;
    }

    if(buses[choice-1].vacancy == 0)
    {
        cout<<"Seats full.Sorry."<<endl;
    }
    else if (buses[choice-1].vacancy != 0)
    {
        cout<<"Enter Passenger's name: ";
        cin>>buses[choice-1].seat_data[20-buses[choice-1].vacancy];
        buses[choice-1].vacancy-=1;
        cout<<"----------------------------------------------"<<endl;
        cout<<"Seat booked successfully. Seat number: "<<(20-buses[choice-1].vacancy)<<endl;
        cout<<"----------------------------------------------"<<endl;
    }
    else
    {
        return;
    }
}

int main()
{
	int choice;

	while(1)
    {

        cout<<setw(12)<<"1) Storing bus information"<<endl;
        cout<<setw(12)<<"2) Access Reservation Portal"<<endl;
        cout<<setw(12)<<"3) View bus data"<<endl;
        cout<<setw(12)<<"4) Show all the Buses available"<<endl;
        cout<<setw(12)<<"5) Exit the program."<<endl;
        cout<<setw(12)<<"Enter choice: ";

        cin>>choice;
        switch (choice)
        {
        case 1:
            store();
            break;
        case 2:
            reservation();
            break;
        case 5:
            return 0;
        }


    }
    return 0;
}
