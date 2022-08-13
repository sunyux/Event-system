#include<iostream>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<string>

//event.h
//Yuxin sun program1 CS202
//These file is writint the class of program1
//The program 1 is about events the three types of event are 
//activity, trip and school event
//I put the time and event name in the event class
//Other information put in the activity, trip and school event class
//The activity, trip and school event id derived class of event class
//Becuase every event need time and name
//The data structor will be array of linear linked list(for trip)
//Circle linked list(for activity)
//Linear linked list(for school event)

//The base class-event class include time and name
class event
{
	public:
		event();
		event(const event& source);
		~event();
		void display_name() const;
		void display_date() const;
		bool compare_name(const char * name_cp);
		void add_name( );
		void add_date( );
		protected:
			char * name;
			int month;
			int day;
			int hour;
			int minute;
};

//The school event are ebents at school like club meeting, lecture
//This class is the base class for the node_school class 
//and the derived class for event class

class school: public event
{
	public:
		school();
		school(const school &source);
		~school();
		void display();
		void add_school_event();
		void change_building();
	
	protected:
		char * building;
		char * department;
		char*info;
};
//The node class for the school
//The derived class for the school class
//LLL
class node_school:public school
{
	public:
	node_school();
	~node_school();
	node_school(const school & source);
	node_school *& go_next();

	void connect_next(node_school * to_next);
	
	protected:
		node_school * next;
	
};

//The manage of school node class, 
//has a relationship with node_school class
class school_manage
{
	public:
	
		school_manage();	
		school_manage(const school_manage & source);
		~school_manage();
		bool add_school_join(const school&a_school);
		bool add_school_host(const school&a_school);
		void display_school_join();
		void display_school_host();
		bool change_school(char*name);
		
		
		
	
	private:
		node_school ** table;
		int copy(node_school *& new_head,node_school * source);
		void delete_all(node_school *& head);
		node_school *& add_school(node_school*& head);
		int remove(node_school *& head, char * to_remove);
		void display(node_school* head);
};


//The activity are activity with friends like swimming, zoo
//This class is the base class for the node_activity class 
//and the derived class for event class
class activity: public event
{
	public:
		activity();
		activity(const activity &source);
		~activity();
		void display();
		void add_activity();
		void change_address();
		void change_people();
	
	protected:
		char * people;//WHO PLAY WITH
		char * address;
};
//The node class for the activity 
//The derived class of activity class
//		CLL
class node_activity:public activity
{
	public:
	node_activity();
	~node_activity();
	node_activity(const activity & source);
	node_activity *& go_next_activity();
	void connect_next(node_activity *& connection);
	
	protected:
		node_activity * next;
	
};

//The manage of activity node class, 
//has a relationship with node activity class
class activity_manage
{
	public:
	
		activity_manage();	
		activity_manage(const activity_manage & to_copy);
		~activity_manage();
		bool add_activity(const activity&a_activity);
		void display_activity();
		
	
	private:
		node_activity * rear;
		int copy_data(activity_manage *& new_rear, activity_manage * source);
		int delete_all(node_activity *& rear);
		node_activity *& add_act(node_activity*& rear);
		void display_activity(node_activity* rear);
};
//The trip are activity with long distance
//This class is the base class for the node_trip class 
//and the derived class for event class
class trip: public event
{
		public:
		trip();
		trip(const trip & source);
		~trip();
		void mark();
		void add_trip();
		void change_dest();
		void change_trans();
		void display();
	protected:
		char * dest;
		char*trans;
		
};

//The node of the trip class
//The derived class of trip class
class node_trip:public trip
{
	public:
		node_trip();
		~node_trip();
		node_trip(const trip & source);
		node_trip *& go_next();
		void connect_next(node_trip * to_next);
	protected:
		node_trip * next;
		
		
		
};

//The manage of trip node class, 
//has a relationship with node_trip class

class trip_manage
{
	public:
		trip_manage();
		~trip_manage();
		trip_manage(const trip_manage&source);
		bool add_trip(const trip& a_trip);
		void display();
		
	protected:
		node_trip ** table;
		node_trip*& add_trip(node_trip *& head);
		void delete_all(node_trip*& head);
		void copy(node_trip *& new_head, node_trip* source);
		void display(node_trip * head);
	};
const int TABLE_SIZE = 10;

