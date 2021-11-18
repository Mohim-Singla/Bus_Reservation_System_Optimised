#include <iostream>
#include <vector>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

static int bus_count=0;

class Bus_data{

private:

	string name, arrival, departure, source, destination;
	int unique_id;

	string seat_data[20];
	int vacancy=20;

public:

    friend void store();
    friend void reservation();
    friend void display_bus_data(int check);

};

static class Bus_data buses[100] ;

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
        cout<<"Something went wrong!!! Please try again"<<endl;
        return;
    }
}

void display_bus_data(int check)
{

    if (check==0)
    {
        cout<<"Available buses are: ";

        for (int i=1;i<=bus_count;i++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    cout<<"Enter Bus number: ";

    int choice;
    cin>>choice;

    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;

    cout<<"Bus unique id: "<<buses[choice-1].unique_id<<setw(40)<<"Bus driver name: "<<buses[choice-1].name<<endl;

    cout<<"\nDeparture time: "<<buses[choice-1].departure<<setw(32)<<"Arrival time: "<<buses[choice-1].arrival<<endl;

    cout<<"\nSource city: "<<buses[choice-1].source<<endl;

    cout<<"Destination: "<<buses[choice-1].destination<<endl<<endl;

    cout<<"--------------------------------------------------------------------------"<<endl;

    if (check==0)
    {
        cout<<"--------------------------------------------------------------------------"<<endl;
        return;
    }

    cout<<"----------------------------Reservation status----------------------------"<<endl;

    if (buses[choice-1].vacancy==20)
    {
        cout<<"No seat reserved. Current vacancy :"<<buses[choice-1].vacancy<<endl;
    }

    for (int i=20;i>buses[choice-1].vacancy;i--)
    {
        cout<<"Seat number: "<<21-i<<setw(45)<<"Passenger name: "<<buses[choice-1].seat_data[20-i]<<endl;
    }

    cout<<"Seat Vacancy: "<<buses[choice-1].vacancy<<endl;

    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
}

int main()
{
	int choice;

	while(1)
    {
        cout<<setw(12)<<"\n\n\t\t\t1) Storing bus information"<<endl;
        cout<<setw(12)<<"\t\t\t2) Access Reservation Portal"<<endl;
        cout<<setw(12)<<"\t\t\t3) View all the info available"<<endl;
        cout<<setw(12)<<"\t\t\t4) Show specific bus data"<<endl;
        cout<<setw(12)<<"\t\t\t5) Exit the program."<<endl;
        cout<<setw(12)<<"\t\t\tEnter choice: ";

        cin>>choice;

        switch (choice)
        {

        case 1:
            store();
            break;

        case 2:
            reservation();
            break;

        case 3:
            display_bus_data(1);
            break;

        case 4:
            display_bus_data(0);
	    break;
        case 5:
            return 0;

        }
    }

    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<"-----------------------Thank you!!! Do Visit Again!-----------------------";

    return 0;
}
