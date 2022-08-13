#include"event.h"
using namespace std;

//Yuxin Sun-CS202-PROGRAM 1
//The file is writing about the event, activity, trip and school class
//The data structure will put in another file

//event the super class of the program
//include char * name;int month;int day;int hour;int minute;
//default constructor
int SIZE=200;
event::event()
{
	name=NULL;//The event name
	//date
	month=0;
	day=0;
	hour=0;
	minute=0;
	
}
//copy constructor
event::event(const event& source)
{
	if(source.name){
		name=new char[strlen(source.name)+1];
		strcpy(name,source.name);
	}
	else
		name=NULL;
	//date part
	month=source.month;
	day=source.day;
	hour=source.hour;
	minute=source.minute;	
}
//destructor
event::~event()
{
	delete [] name;
	name=NULL;
	month=day=hour=minute=0; 
}

//display an activity
void event::display_name() const
{
	
	if(name)
	{
		cout<<name<<endl;
	}
	else
	cout<<"We don't have event"<<endl;
}

//display date
void event::display_date() const
{

	    cout<<"The time is "<< month<<" / "<<day<<"  "<<hour<<" : "<<minute<<" ."<<endl;
}

//int day; hour; minute;month;
//change or add a date
void event::add_date( )
{
	int new_month=0;
	int new_day=0;
	int new_hour=0;
	int new_minute=0;
	cout<<"Please enter the new date(Please enter the number)."<<endl;
	cout<<"1.The new month is:"<<endl;
	cin>>new_month;
	month=new_month;
	cout<<"2.The new day is:"<<endl;
	cin>>new_day;
	day=new_day;
	cout<<"3.The new hour is:"<<endl;
	cin>>new_hour;
	hour=new_hour;
	cout<<"4.The new minute is:"<<endl;
	cin>>new_minute;
	minute=new_minute;
	
	cout<<"Finaish!"<<endl;	
}
//change or add a name of the event
void event::add_name( ) {

	cout << "Enter the name of this event" << endl;

	if(name)
	{
		delete [] name;
	}

	name = new char[SIZE + 1];
	cin.get(name, SIZE);
	cin.ignore(100, '\n');
	

}

//compare two name, works of delete one 
bool event::compare_name(const char * name_cp)
{
	if(strcmp(name_cp,name)==0)
	{
		return true;
	}
	else
		return false;
}

//class activity
//	char * people,address
//default constructor
activity::activity()
{
	people=NULL;
	address=NULL;
}
//destructor
activity::~activity()
{
	delete [] people;
	people = NULL;
	delete [] address;
	address = NULL;
}
//copy constructor
activity::activity(const activity& source):event(source)
{
	if(source.people)
	{
		people=new char[strlen(source.people)+1];
		strcpy(people,source.people);	
	}
	else
	people=NULL;
	
	if(source.address)
	{
		address=new char[strlen(source.address)+1];
		strcpy(address,source.address);	
	}
	else
	address=NULL;
		
}

// add activity
void activity::add_activity()
{
	cout << "Enter the friend to play with" << endl;
	people = new char[SIZE + 1];
	cin.get(people, SIZE);
	cin.ignore(100, '\n');
	
	cout << "Enter the address of this activity" << endl;
	address = new char[SIZE + 1];
	cin.get(address, SIZE);
	cin.ignore(100, '\n');

}
//change the address of the activity
void activity::change_address( )
 {

	cout << "Enter the new address of this activity" << endl;

	if(address)
	{
		delete [] address;
	}

	address = new char[SIZE + 1];
	cin.get(address, SIZE);
	cin.ignore(100, '\n');
	

}
//change the people of the activity
void activity::change_people( )
 {

	cout << "Enter the people you will go with" << endl;

	if(people)
	{
		delete [] people;
	}

	people = new char[SIZE + 1];
	cin.get(people, SIZE);
	cin.ignore(100, '\n');
	

}

//display an activity
void activity::display() 
{
	
	cout<<"The activity name is :";
	event::display_name();
	cout<<endl;
	
	activity::display_date();
	cout<<endl;
	
	if(people)
	{
		cout<<"You will go with: "<<people<<endl; 
	}else
	  cout<<" You are alone "<<endl;
	  
	if(address)
	{
		cout<<"The address is: "<<address<<endl;
	}else
		cout<<" You forget the address "<<endl;


}

//class school
//	char * building;	char * department;	char*info;
//default constructor
school::school()
{
	building=NULL;
	department=NULL;
	info=NULL;
}
//destructor
school::~school(){
	delete [] building;
	building = NULL;
	delete [] department;
	department = NULL;
	delete[] info;
	info=NULL;
}
//copy constructor
school::school(const school& source):event(source)
{
	if(source.building)
	{
		building=new char[strlen(source.building)+1];
		strcpy(building,source.building);	
	}
	else
	building=NULL;
	
	if(source.department)
	{
		department=new char[strlen(source.department)+1];
		strcpy(department,source.department);	
	}
	else
	department=NULL;
	
	if(source.info)
	{
		info=new char[strlen(source.info)+1];
		strcpy(info,source.info);	
	}
	else
	info=NULL;	
}

// add building or department
void school::add_school_event()
{
	cout << "Enter the building of this meetint" << endl;
	building = new char[SIZE + 1];
	cin.get(building, SIZE);
	cin.ignore(100, '\n');
	
	cout << "Enter the department of this meenting" << endl;
	department = new char[SIZE + 1];
	cin.get(department, SIZE);
	cin.ignore(100, '\n');
	
	cout << "Enter other information of this meenting" << endl;
	info = new char[SIZE + 1];
	cin.get(info, SIZE);
	cin.ignore(100, '\n');
}
//change the building of the school event
void school::change_building( ) {

	cout << "Enter the new building of this meeting" << endl;

	if(building)
	{
		delete [] building;
	}

	building = new char[SIZE + 1];
	cin.get(building, SIZE);
	cin.ignore(100, '\n');
	

}
//display a school event
void school::display() 
{
	
	cout<<"The school event name is :";
	event::display_name();
	cout<<endl;
	
	event::display_date();
	cout<<endl;
	
	if(building)
	{
		cout<<"The meenting is on the: "<<building<<endl; 
	}else
	  cout<<" The system don't have the building information "<<endl;
	  
	if(department)
	{
		cout<<"The department is: "<<department<<endl;
	}else
		cout<<"  "<<endl;
	
	if(info)
	{
		cout<<"The other information is: "<<info<<endl;
	}else
		cout<<"That's all. "<<endl;
	
}

//class trip
//	char * dest,trans,
//default constructor
trip::trip()
{
	dest=NULL;
	trans=NULL;
}
//destructor
trip::~trip()
{
	delete [] trans;
	trans = NULL;
	delete [] dest;
	dest = NULL;
}
//copy constructor
trip::trip(const trip& source):event(source)
{
	if(source.trans)
	{
		trans=new char[strlen(source.trans)+1];
		strcpy(trans,source.trans);	
	}
	else
	trans=NULL;
	
	if(source.dest)
	{
		dest=new char[strlen(source.dest)+1];
		strcpy(dest,source.dest);	
	}
	else
	dest=NULL;
		
}



// add trip
void trip::add_trip()
{
	cout << "Enter the vehicle" << endl;
	trans = new char[SIZE + 1];
	cin.get(trans, SIZE);
	cin.ignore(100, '\n');
	
	cout << "Enter the destination" << endl;
	dest = new char[SIZE + 1];
	cin.get(dest, SIZE);
	cin.ignore(100, '\n');

}
//change the destination of the activity
void trip::change_dest( )
 {

	cout << "Enter the new destination of this trip" << endl;

	if(dest)
	{
		delete [] dest;
	}

	dest = new char[SIZE + 1];
	cin.get(dest, SIZE);
	cin.ignore(100, '\n');
	

}
//change the trans of the trip
void trip::change_trans( )
 {

	cout << "Enter the new transportation" << endl;

	if(trans)
	{
		delete [] trans;
	}

	trans = new char[SIZE + 1];
	cin.get(trans, SIZE);
	cin.ignore(100, '\n');
	

}

//display a trip
void trip::display() 
{
	
	cout<<"The trip is :";
	event::display_name();
	cout<<endl;
	
	event::display_date();
	cout<<endl;
	
	if(trans)
	{
		cout<<"You will take: "<<trans<<endl; 
	}else
	  cout<<" You haven't decided how to get there "<<endl;
	  
	if(dest)
	{
		cout<<"The destination is: "<<dest<<endl;
	}else
		cout<<" You haven't decided the destination "<<endl;
	

}


