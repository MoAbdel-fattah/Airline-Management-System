#include <iostream>
#include<fstream>
#include<windows.h>
#include<sstream>
using namespace std;

class Airline{
string Flight;
string Des;
string Dep;
int Seats;
public:
	Airline(string flight, string des,string dep,int seats){
		Flight = flight;
		Des = des;
		Dep = dep;
		Seats = seats;
	}
	
	
	
	
string getFlight(){
	return Flight;
}	
string getDes(){
	return Des;
}	
string getDep(){
	return Dep;
}	

int getSeat(){
	return Seats;
}	

update(string flight){
	ifstream in("H:/Flights.txt");
	ofstream out("H:/Flights_Temp.txt");
	
	
	string line;
	while(getline(in,line)){
		int pos = line.find(flight);
		if(pos != string::npos){
			
			int current = Seats-1;
			Seats = current;
			stringstream ss;
			ss<<current;
			string strCurrent = ss.str();
			
			int seatPos = line.find_last_of(':');
			line.replace(seatPos + 2, string::npos, strCurrent);
		} 
		out<<line<<endl;
	}
	out.close();
	in.close();
	remove("H:/Flights.txt");
	rename("H:/Flights_Temp.txt", "H:/Flights.txt");
	cout<<"Seat Reserved Successfully"<<endl;

}

};

display(){
	ifstream in("H:/Flights.txt");
	if(!in){
		cout<<"Error: File can not Open!"<<endl;
	}
	else{
		string line;
		while(getline(in,line)){
			cout<<line<<endl;
		}
	}
}

int main(){
	Airline flight1("F50","Egypt","NewYork",50);
	Airline flight2("F51","Egypt","Berlin",30);
	Airline flight3("F52","Egypt","Makka",2);
	
	ofstream out("H:/Flights.txt");
	if(!out){
		cout<<"Error:File can not open!"<<endl;
	}
	else{
	out<<"\t"<<flight1.getFlight()<<" : "<<flight1.getDes()<<" : "<<flight1.getDep()<<" : "<<flight1.getSeat()<<endl<<endl;
	out<<"\t"<<flight2.getFlight()<<" : "<<flight2.getDes()<<" : "<<flight2.getDep()<<" : "<<flight2.getSeat()<<endl<<endl;
	out<<"\t"<<flight3.getFlight()<<" : "<<flight3.getDes()<<" : "<<flight3.getDep()<<" : "<<flight3.getSeat()<<endl<<endl;
	
cout<<"Data Saved Suuccessfully"<<endl;
out.close();
}
	
	
bool exit = false;
while(!exit){
	system("cls");
	cout<<"\t Welcome To Airline Management Systems"<<endl;
	cout<<"\t *************************************"<<endl;
	cout<<"\t 1.Reserve A Seat."<<endl;
	cout<<"\t 2.Exit."<<endl;
	cout<<"\t 3.Enter Your Choice:";
int val;
cin>>val;

if(val==1){
	system("cls");
	display();
	string flight;
	cout<<"Enter Flight No: ";
	cin>>flight;
	
	if(flight == flight1.getFlight() && flight1.getSeat() > 0){
		flight1.update(flight);
	}
	else if(flight1.getSeat() <= 0){
		cout<<"Sorry,Seat Not Available"<<endl;
	}
		if(flight == flight2.getFlight() && flight2.getSeat() > 0){
		flight2.update(flight);
	}
	else if(flight2.getSeat() <= 0){
		cout<<"Sorry,Seat Not Available"<<endl;
	}
		if(flight == flight3.getFlight() && flight3.getSeat() > 0){
		flight3.update(flight);
	}
	else if(flight3.getSeat() <= 0){
		cout<<"Sorry,Seat Not Available"<<endl;
	}
	Sleep(5000);
}

else if(val==2){
	system("cls");
	exit= true;
	cout<<"Good Luck!"<<endl;
	Sleep(3000);
}
}
}
