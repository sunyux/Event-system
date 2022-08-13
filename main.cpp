#include <iostream>
#include <cstring>
#include "event.h"

//These file is test of the assignment1
//Yuxin Sun-CS202-Assignment 1 
//main.cpp
using namespace std;
void activity_option(activity_manage&a_activity_manage);
void school_option(school_manage&a_school_manage);
void trip_option();
int main()
{
	
	activity_manage a_activity_manage;
	school_manage a_school_manage;
	int choose = 0;
	while(true) {
        cout << "------------------------------------------------------" << endl;
		cout << ">>>>>>>>> Welcome to use the activity system! <<<<<<<<<" << endl;
		cout << "            Please choose a function :)               " << endl;
		cout << "            Enter'0' to quit the system               " << endl;
		cout << "            Enter'1' to use activity system                 " << endl;
		cout << "            Enter'2' to use school event system           " << endl;
		cout << "            Enter'3' to use trip system          " << endl;
		cout << "------------------------------------------------------" << endl;
		cout << "            Please enter your choose                  " << endl;
		cin>>choose;
		cin.ignore(100,'\n');
		switch(choose) {
        case 0:
            cout <<"   Thanks for using the system     "<<endl;
			cout <<"   Have a good day! ^-^           "<<endl;
			return 0;
        case 1:
			cout << "Are you ready for the activity? " << endl;
			cout << endl;
			activity_option(a_activity_manage);			
			break;
		case 2:
			cout << "Are you ready for the school event? " << endl;
			cout << endl;
			school_option(a_school_manage);
			break;
		case 3:
			cout << "Are you ready for the trip ? " << endl;
			cout << endl;
			trip_option();
			break;
		default:
            cout << "     Wrong choose, please check again.  " << endl;
		}
	}
	cout<<"     Wrong choose,please check again.       "<<endl;
	return 0;
}

//The option of activity
void activity_option(activity_manage&a_activity_manage) 
{
	int option_a=0;
           cout << "Select activity option: " << endl;
		   cout << endl;
        cout << "1. Add a activity" << endl;
        cout << "2. display all activity " << endl; 
        cout << "3. change the activity time " << endl; 
		cout << endl;

        cin >> option_a;
        
    while(cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << "Wrong choose.";
                                cin >> option_a;
                        }

                        cin.clear();
                        cin.ignore(100, '\n');
        switch (option_a)
        {
        case 1:
		{
    		activity new_activity;
    		new_activity.add_activity();
    		new_activity.add_name();
    		new_activity.add_date();
    		a_activity_manage.add_activity(new_activity);
    	}
        	break;
        case 2:
			a_activity_manage.display_activity();
            break;
        case 3:
        {
			activity new_activity;
    		new_activity.add_activity();
    		new_activity.add_name();
    		new_activity.add_date();
    		a_activity_manage.add_activity(new_activity);
        }
        default:
        cout << "Wrong choose! " << endl;
        }

}


void school_option(school_manage&a_school_manage)
{
	int school_type=0;
        int option_join=0;
        int option_host=0;

	cout << "Select an school event type: " << endl;
	cout << "1. Just attend" << endl;
	cout << "2. Host the event" << endl;
	cout << endl;
	
	cin >> school_type;
        while(cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << "Wrong choose.";
                                cin >> school_type;
                        }

                        cin.clear();
                        cin.ignore(100, '\n');

	if (school_type == 1) {
        cout << "Select event option: " << endl;
	cout << endl;
        cout << "1. Add a event" << endl;
        cout << "2. read all event " << endl; 
		cout << endl;

        cin >> option_join;
	while(cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << "Wrong choose.";
                                cin >> option_join;
                        }

                        cin.clear();
                        cin.ignore(100, '\n');
        switch (option_join)
        {
        case 1:
		{
			school new_school;
			new_school.add_name();
			new_school.add_school_event();
			new_school.add_date();
	
		
			a_school_manage.add_school_join(new_school);

		}
         break;
        case 2:
		a_school_manage.display_school_join();
        break;
        default:
        cout << "Wrong choose! " << endl;
        }

   }

	if (school_type == 2) {
        cout << "Select event option: " << endl;
	cout << endl;
        cout << "1. Add a event" << endl;
        cout << "2. read all event " << endl; 
		cout << endl;

        cin >> option_host;
	while(cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << "Wrong choose.";
                                cin >> option_host;
                        }

                        cin.clear();
                        cin.ignore(100, '\n');
        switch (option_host)
        {
        case 1:
		{
			school new_school;
			new_school.add_name();
			new_school.add_school_event();
			new_school.add_date();
	
		
			a_school_manage.add_school_host(new_school);

		}
         break;
        case 2:
		a_school_manage.display_school_host();
        break;
        default:
        cout << "Wrong choose! " << endl;
        }

   }

   }

void trip_option() 
{
    
	int option_t=0;
           cout << "Select activity option: " << endl;
		   cout << endl;
        cout << "1. Add a trip" << endl;
        cout << "2. display all trips " << endl; 
		cout << endl;

        cin >> option_t;
       	int num=0;
		cout<<"How many trips you want to add?"<<endl;
   		 cin>>num;
   	    vector<trip> new_trip(num);
        
    while(cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << "Wrong choose.";
                                cin >> option_t;
                        }

                        cin.clear();
                        cin.ignore(100, '\n');
        switch (option_t)
        {
		case 1:
		{
        for(int i=0;i<num;++i)
          {
		  	new_trip[i].add_name();
    		new_trip[i].add_trip();
    		new_trip[i].add_date();
    	}
    	cout<<"finash it!"<<endl;
    	}
    	break;
    	case 2:
    		{
    			 for(int i=0;i<num;++i)
          			{
		  				new_trip[i].display();
    	 			}
			}
			break;
    }
    
}






