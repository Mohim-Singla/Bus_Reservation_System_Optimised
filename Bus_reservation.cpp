#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

static int bus_count=0;

class Bus_data{
private:
	string name, arrival, departure, source, destination;
	int unique_id;
	string arr[20]={"0"};
public:
    friend void store();


};

class Bus_data buses[100];

void store()
{
    cout<<"Enter bus number: ";
    cin>>buses[bus_count].unique_id;
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

int main()
{
	int choice;
	cin>>choice;

}
