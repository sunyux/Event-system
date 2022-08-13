#include"event.h"
using namespace std;

//node_event class
//The class is working for the data structure 
//the node-xx class is store next and node class
//the manage class is work for the node
//All of these node classes are derived class for the class at event.cpp
//CLL-activity
//Array of LLL-school


//node activity class-CLL
// CONSTRUCTOR
node_activity::node_activity():next(NULL)
{
}

//destructor
node_activity::~node_activity()
{
	next=NULL;
}

//copy constructor
node_activity::node_activity(const activity & source):activity(source)
{	
	next=NULL;
}

//connect to the next
node_activity*&node_activity :: go_next_activity()
{
	return next;
}

void node_activity::connect_next(node_activity *& connection) 
{
	if(next)
	{
		delete next;
	}
	next = connection;
}

//activity manage class-to manage the cll
//constructor
activity_manage::activity_manage():rear(NULL)
{
}

//COPY constructor
activity_manage::activity_manage(const activity_manage & to_copy)
{
	rear=NULL;
}
//Destructor
activity_manage::~activity_manage()
{
	if(rear)
	{
		delete_all(rear);
		rear = NULL;
	}
}
int activity_manage::delete_all(node_activity *& rear)
{
	if(rear)
	{
		delete_all(rear->go_next_activity());
		delete rear;
		rear=NULL;
	}
	return 0;
}

//add the new node in the CLL
bool activity_manage::add_activity(const activity&a_activity) 
{
	if(!rear)
	{
		rear= new node_activity;	
		return 1;
	}
	node_activity*newnode=new node_activity;
	node_activity*temp=add_act(rear);
	temp->connect_next(newnode);
	return 1;
}

node_activity*& activity_manage::add_act(node_activity *& rear)
{
	if (rear->go_next_activity()) {
		return add_act(rear->go_next_activity());
	}

	return rear;

}

//display the CLL
//cycles through apmanage for display
void activity_manage::display_activity( ) 
{
	if(!rear)
		return;
	display_activity(rear->go_next_activity());
}

void activity_manage::display_activity(node_activity * rear) 
{
	if(rear == this->rear)
	{
		display_activity(rear->go_next_activity());
		return;
	}
	display_activity(rear->go_next_activity());
}

//school event class
node_school::node_school()
{
	next=NULL;
}

//destructor for the node_school
node_school::~node_school()
{
	next=NULL;
}
//copy constructor 
node_school::node_school(const school & source):school(source)
{
	next=NULL;
}

//move to the next point 
node_school*& node_school::go_next()
{	
	return next;
}

//connect with next point
void node_school::connect_next(node_school * to_next)
{
	if(next)
	{
		delete next;
	}
	next = to_next;
}

//school manage class
//constructor 
school_manage::school_manage()
{
	table = NULL;
	table = new node_school*[TABLE_SIZE];
	for(int i = 0; i < TABLE_SIZE; i++) {
		
		table[i] = NULL;
	}

}

//copy constructor 
school_manage::school_manage(const school_manage&source)
{
	for (int i = 0; i < TABLE_SIZE; i++) {
		table[i] = NULL;
		table[i] = source.table[i];
	}
}


//destructor 
school_manage::~school_manage()
{
	for(int i = 0; i < TABLE_SIZE; i++) {
			
		delete_all(table[i]);
	}
	delete [] table;
	table = NULL;
}
//delete the whole data in the school manage
void school_manage::delete_all(node_school*& head)
{
	if (head) {
		delete_all(head->go_next());
		delete head;
		head = NULL;
	}
}
	

//add a new school that join it
bool school_manage::add_school_join(const school&a_school)
{
	if(table[0] == NULL) {
		table[0] = new node_school(a_school);
		return true;
	} else {
		node_school* newnode = new node_school(a_school);
		node_school* temp = add_school(table[0]);
		temp->connect_next(newnode);
		return true;
	}

}

//add a new school
bool school_manage::add_school_host(const school&a_school)
{
	if(table[1] == NULL) {
		table[1] = new node_school(a_school);
		return true;
	} else {
		node_school* newnode = new node_school(a_school);
		node_school* temp = add_school(table[1]);
		temp->connect_next(newnode);
		return 0;
	}
}

//add a school in school manage
node_school*& school_manage::add_school(node_school*& head) {

	if (head->go_next()) {
		return add_school(head->go_next());
	}

	return head;
}

//display the join school 
void school_manage::display_school_join()
{
	if(table[0] == NULL)
	{
		cout << "You school event is empty!" << endl;
	}else
	{
		display(table[0]);
	}
}

//display the host event
void school_manage::display_school_host()
{
	if(table[1] == NULL)
	{
		cout << "You school event is empty!" << endl;
	}else
	{
		display(table[1]);
	}
}

//display
void school_manage::display(node_school* head) {
	
	if(head->go_next()) {
		display(head->go_next());
	}
	
	head->display();	
}


