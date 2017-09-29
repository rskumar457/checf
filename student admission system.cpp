#include <iostream>  // Header file
using namespace std;  // Standard library
class node  //opening node class
{

	public:
	int rno;    //variable rno for storing roll number of student
	string studentname;  //variable studentname for storing name  of student
	node *next;  //creating pointer of node type
	float sscmarks;  //variable ssc for storing ssc marks  of student
	float hscmarks;  //variable hsc for storing ssc marks  of student
	float jeemarks;  //variable jee for storing jee marks  of student
	node()  //defining constructor
	{
		rno=0;
		sscmarks=0;
		hscmarks=0;
		jeemarks=0;
		next=NULL;
	}
}; //closing node class
class list  
{			//opening list class
	public:
	string studentname;  //variable studentname for storing name  of student
	node *head;  //creating pointer of node type
	node *last;	//creating pointer of node type
	node *temp;	//creating pointer of node type
	list()	//defining constructor
	{
		head=NULL;
		last=NULL;                                                                   
		
	}
	void create()   //function for creating new node
	{
		node *newnode=new node();  // creating new node
		head =newnode;   //ponter of node type storing address of new node
		last=newnode;	//ponter of node type storing address of new node
		
	}
	void insert(float ssc,float hsc,float jee)  //function for insertion 
	{
		if(head==NULL)  //checking any node is created or not
		{
			cout<<"\n no list is created";
		}
		else
		{
			temp=last;  // storing address of last node in temp
			node *newnode=new node();   // creating new node
			last->next=newnode; //linking previous and new node
			last=newnode;  // assinning location of new node to pointr named last
			last->rno=(temp->rno)+1;   //incrementing roll number
			last->sscmarks=ssc;  // storing ssc marks of student in node
			last->hscmarks=hsc;	// storing hsc marks of student in node
			last->jeemarks=jee;	// storing jee marks of student in node
			cout<<"\n Enter your name	:	";
			cin>>last->studentname;
			cout<<"\n your roll number is 	:	"<<last->rno;
		}
		cout<<"\n ****************INSERTION PROCESS COMPLETED SUCESSFULLY*******************";
	}
	void display()  //function for displaying required output
	{
		if(head==NULL)	//checking any node is created or not
		{
			cout<<"\n no list is created";
		}
		else
		{
			temp=head->next;	//assigning the location of pointer name temp
			cout<<"\n Name of student"<<"\t"<<"Roll number ";
			while(temp!=NULL) //loop for displaying required
			{
				cout<<"\n "<<temp->studentname<<"\t\t\t"<<temp->rno;
				temp=temp->next;
			}
		}
	}  //closing display function
	void search()  // funtion for search operation
	{	int search;  //variable for serching
		if(head==NULL)	//checking any node is created or not
		{
		cout<<"\n no list is created";
		}
		else
		{
			temp=head;	//assigning the location to pointer name temp of head
			cout<<"\n enter roll number of student	:	";
			cin>>search;
			while(temp!=NULL or temp->rno==search) // loop for serarch operation
			{
				if(temp->rno==search)   //checking whether student found or not
				{	
				cout<<"\n entered roll number "<<search<<" is found";
				cout<<"\n name of student is	:	"<<temp->studentname;
				return;   // used to come out from funtion
				}
				else
				{
				temp=temp->next;  // updatind temp
				}
			}
			if(temp==NULL) // condition if student not found
			{
				cout<<"\n no such student found";
			}
		}
	}  // closing search function
	 void delete_data() // funtion for performing delete operation
    {
        if(head==NULL)	//checking any node is created or not
        {
            cout<<"\n list us not created";
        }
        else
        {
            int data;  // variable used for delete operation
            int count=0;  // initializing checking variable
            cout<<"\n enter the roll number of student you want to delete        :    ";
            cin>>data;
            node *p; //creating pointer of node type
            temp=head;	//assigning the location to pointer name trav of head
            while(temp!=NULL )  //loop for delete operation
            {
                if(temp->rno==data)  // cheching condition whether data found or not 
                {
                    if(temp!=head and temp!=last)  // checking whether data is in between head and last
                    {
                        p->next=temp->next;  //linking nodes 
                        temp=NULL; // assigning pointer trav as null
                        delete temp; // deleting trav
                        count=1;	//assinging count as 1
                    }
                    else if(temp==head)  // checking whether data is at head 
                    {
                        head=temp->next;  //linking nodes 
                        temp=NULL; // assigning pointer trav as null
                        count=1;	//assinging count as 1
                        delete temp; // deleting trav
                    }
                    else
                    {
                        last=p;  //linking nodes 
                        temp=NULL; // assigning pointer trav as null
                        count=1; //assinging count as 1
                        delete temp; // deleting trav
                    }
                }
                else  // if list is already created
                {
                    p=temp;  // updating p
                    temp=temp->next;  // updating trav
                }
            }
            cout<<"\n ******************GIVEN STUDENT DATA IS DELETED SUCESSFULLY SUCESSFULLY******************";
            if(count==0)  // if entered detail is not found
            {
                cout<<"\n no such record found"    ;
            }
        }
    } // closing delete function
}; //closing list class
int main()
{
	float sscmarks;  // variable for stronin ssc marks and passing it as partameter to insert funtion
	float hscmarks;	// variable for stronin ssc marks and passing it as partameter to insert funtion
	float jeemarks;	// variable for stronin ssc marks and passing it as partameter to insert funtion
	int choice;  //variable for choice
	double total;  // variable for totaling
	list compdept;  // creating object of compurter dedartment
	list mechdept; // creating object of mechanical  dedartment
	list etxdept;  // creating object of electronics dwepartment dedartment
	do // opening do while loop
	{
		cout<<"\n *******************WELCOME TO OUR COLLEGE*************************";//
		cout<<"\n 1.create list";														//
		cout<<"\n 2.Insert record in list";												//
		cout<<"\n 3.search record in list";												//creating menu
		cout<<"\n 4.delete record record from list";									//
		cout<<"\n 5.display record";													//
		cout<<"\n 6.exit";																//
		cout<<"\n Enter your choice		:	";											//
		cin>>choice;																	//
		switch(choice)
		{
			case 1:
				compdept.create();  // creating node for computer department
				mechdept.create();	 // creating node for  mechanical department
				etxdept.create();	 // creating node for electronics department
				cout<<"\n *********************LIST IS CREATED SUCESSFULLY*************************";
				break;
			case 2:{cout<<"\n *********************OPENED INSERT MODULE*************************"; //case for performing insert operation
				cout<<"\n enter your SSC marks	:	";
				cin>>sscmarks;
				cout<<"\n enter your HSC marks	:	";
				cin>>hscmarks;
				cout<<"\n enter your JEE marks	:	";
				cin>>jeemarks;
				total=(.2*sscmarks+.2*hscmarks+.6*jeemarks);  // calculating total
				if(total>90)  // checking eligibility of student
				{
					cout<<"\n *************************CONGRATULATIONS**************************";
					cout<<"\n you are eligible for all three department";
					cout<<"\n select your department";	
					cout<<"\n 1.Computer department";
					cout<<"\n 2.Mechanical department";
					cout<<"\n 3.Electronics department";
					cout<<"\n enter your choice(1/2/3)	:	";
					cin>>choice;
					switch(choice)
					{
						case 1:  // case for inserting student in computer department
							compdept.insert(sscmarks,hscmarks, jeemarks); // calling insert function by value
							cout<<"\n ***************welcome to COMPUTER department*********************";
							break;
						
						case 2:  // case for inserting student in  mechanical department
							mechdept.insert(sscmarks,hscmarks, jeemarks); // calling insert function by value
							cout<<"\n ***************welcome to MECHANICAL department*********************";
							//mechdept.count(choice1);
							break;
						
						case 3:  // case for inserting student in  mechanical department
							etxdept.insert(sscmarks,hscmarks, jeemarks); // calling insert function by value
							cout<<"\n *************welcome to ELECTRONICS department**********************";
							break;
						
						
						default:
							cout<<"\n invalid choice";
							cout<<"\n please enter a valid choice";
							break;
							
						}
					
				}
				else if(total>80)
				{
					cout<<"\n *************************CONGRATULATIONS**************************";
					cout<<"\n you are eligible for MECHANICAL AND ELECTRONICS department";
					cout<<"\n select your department";
					cout<<"\n 1.Mechanical department";
					cout<<"\n 2.Electronics department";
					cout<<"\n enter your choice(1/2)	:	";
					cin>>choice;
					switch(choice)
					{
						case 1:	// case for inserting student in  mechanical department
							mechdept.insert(sscmarks,hscmarks, jeemarks);   // calling insert function by value
							cout<<"\n ***************welcome to mechanical department*********************";
							break;
						case 2:	// case for inserting student in  electronics  department
							etxdept.insert(sscmarks,hscmarks, jeemarks);   // calling insert function by value
							cout<<"\n *************welcome to electronics department**********************";
							break;
						default:
							cout<<"Please enter a valid choice	:	";
							break;
					}
				}
				else if(total>70)
				{	
					cout<<"\n *************************CONGRATULATIONS**************************";
					cout<<"\n you are eligible ELECTRONICS department";
					etxdept.insert(sscmarks,hscmarks, jeemarks);	// calling insert function by value
					cout<<"\n *************welcome to electronics department**********************";
				}
				else
				{
					cout<<"\n Dear student, you are not eligible for this college ";
					cout<<"\n Better luck next time";
				}
		    	break;
		    }
			case 3: // case for searching operation
				cout<<"\n *********************OPENED SEARCHING MODULE*************************";
				cout<<"\n 1.Computer department";
				cout<<"\n 2.Mechanical department";
				cout<<"\n 3.Electronics depatment";
				cout<<"\n Enter students department choice(1/2/3)	:	";
				cin>>choice;
				switch(choice)
				{
					case 1:
						compdept.search();	// calling search function by object
						break;
					case 2:
						mechdept.search();	// calling search fuction by object
						break;
					case 3:
						etxdept.search();	// calling search function by object
						break; 
					default:
						cout<<"Please enter a valid choice";
						break;	
				}
				break;
			case 4: // case for delete operation
				cout<<"\n *********************OPENED DELETE MODULE*************************";
				cout<<"\n 1.Computer department";
				cout<<"\n 2.Mechanical department";
				cout<<"\n 3.Electronics depatment";
				cout<<"\n Enter your students department choice(1/2/3)	:	";
				cin>>choice;
				switch(choice)
				{
					case 1:
						compdept.delete_data(); // calling delete function by object
						break;
					case 2:
						mechdept.delete_data();	// calling delete fuction by object
						break;
					case 3:
						etxdept.delete_data();	// calling delete function by object
						break;
					default:
						cout<<"Please enter a valid choice";
						break;
				}
				break;
			case 5: // case for  displaying
				cout<<"\n ***********************list of COMPUTER department students***********************";
				compdept.display();	// calling display function by object
				cout<<"\n **********************list of MECHANICAL depatrment students**********************";
				mechdept.display();	// calling display function by object
				cout<<"\n **********************list of ELECTRONICS depatrment students**********************";
				etxdept.display();	// calling display function by object
				break;
			case 6:// case for exit
				cout<<"!!!!!!!!!!THANK YOU FOR CHOOSING OUR COLLEGE!!!!!!!!!!!!";
				break;
			default:
				cout<<"Please enter a valid choice	:	";
				break;									
		}
	}while(choice!=6); // condition for exiting main menu
return 0; // returnig zero
} // closing main function
// output
/*
 *******************WELCOME TO OUR COLLEGE*************************
 1.create list
 2.Insert record in list
 3.search record in list
 4.delete record record from list
 5.display record
 6.exit
 Enter your choice              :       1

 *********************LIST IS CREATED SUCESSFULLY*************************
 *******************WELCOME TO OUR COLLEGE*************************
 1.create list
 2.Insert record in list
 3.search record in list
 4.delete record record from list
 5.display record
 6.exit
 Enter your choice              :       2

 *********************OPENED INSERT MODULE*************************
 enter your SSC marks   :       99

 enter your HSC marks   :       98

 enter your JEE marks   :       95

 *************************CONGRATULATIONS**************************
 you are eligible for all three department
 select your department
 1.Computer department
 2.Mechanical department
 3.Electronics department
 enter your choice(1/2/3)       :       1

 Enter your name        :       sam

 your roll number is    :       1
 ****************INSERTION PROCESS COMPLETED SUCESSFULLY*******************
 ***************welcome to COMPUTER department*********************
 *******************WELCOME TO OUR COLLEGE*************************
 1.create list
 2.Insert record in list
 3.search record in list
 4.delete record record from list
 5.display record
 6.exit
 Enter your choice              :       2

 *********************OPENED INSERT MODULE*************************
 enter your SSC marks   :       85

 enter your HSC marks   :       98

 enter your JEE marks   :       96

 *************************CONGRATULATIONS**************************
 you are eligible for all three department
 select your department
 1.Computer department
 2.Mechanical department
 3.Electronics department
 enter your choice(1/2/3)       :       1

 Enter your name        :       lun

 your roll number is    :       2
 ****************INSERTION PROCESS COMPLETED SUCESSFULLY*******************
 ***************welcome to COMPUTER department*********************
 *******************WELCOME TO OUR COLLEGE*************************
 1.create list
 2.Insert record in list
 3.search record in list
 4.delete record record from list
 5.display record
 6.exit
 Enter your choice              :       2

 *********************OPENED INSERT MODULE*************************
 enter your SSC marks   :       78

 enter your HSC marks   :       85

 enter your JEE marks   :       86

 *************************CONGRATULATIONS**************************
 you are eligible for MECHANICAL AND ELECTRONICS department
 select your department
 1.Mechanical department
 2.Electronics department
 enter your choice(1/2) :       1

 Enter your name        :       bella

 your roll number is    :       1
 ****************INSERTION PROCESS COMPLETED SUCESSFULLY*******************
 ***************welcome to mechanical department*********************
 *******************WELCOME TO OUR COLLEGE*************************
 1.create list
 2.Insert record in list
 3.search record in list
 4.delete record record from list
 5.display record
 6.exit
 Enter your choice              :       2

 *********************OPENED INSERT MODULE*************************
 enter your SSC marks   :       78

 enter your HSC marks   :       98

 enter your JEE marks   :       98

 *************************CONGRATULATIONS**************************
 you are eligible for all three department
 select your department
 1.Computer department
 2.Mechanical department
 3.Electronics department
 enter your choice(1/2/3)       :       2

 Enter your name        :       mike

 your roll number is    :       2
 ****************INSERTION PROCESS COMPLETED SUCESSFULLY*******************
 ***************welcome to MECHANICAL department*********************
 *******************WELCOME TO OUR COLLEGE*************************
 1.create list
 2.Insert record in list
 3.search record in list
 4.delete record record from list
 5.display record
 6.exit
 Enter your choice              :       2

 *********************OPENED INSERT MODULE*************************
 enter your SSC marks   :       74

 enter your HSC marks   :       76

 enter your JEE marks   :       76

 *************************CONGRATULATIONS**************************
 you are eligible ELECTRONICS department
 Enter your name        :       john

 your roll number is    :       1
 ****************INSERTION PROCESS COMPLETED SUCESSFULLY*******************
 *************welcome to electronics department**********************
 *******************WELCOME TO OUR COLLEGE*************************
 1.create list
 2.Insert record in list
 3.search record in list
 4.delete record record from list
 5.display record
 6.exit
 Enter your choice              :       2

 *********************OPENED INSERT MODULE*************************
 enter your SSC marks   :       85

 enter your HSC marks   :       71

 enter your JEE marks   :       72

 *************************CONGRATULATIONS**************************
 you are eligible ELECTRONICS department
 Enter your name        :       tim

 your roll number is    :       2
 ****************INSERTION PROCESS COMPLETED SUCESSFULLY*******************
 *************welcome to electronics department**********************
 *******************WELCOME TO OUR COLLEGE*************************
 1.create list
 2.Insert record in list
 3.search record in list
 4.delete record record from list
 5.display record
 6.exit
 Enter your choice              :       5

 ***********************list of COMPUTER department students********************
***
 Name of student        Roll number
 sam                    1
 lun                    2
 **********************list of MECHANICAL depatrment students*******************
***
 Name of student        Roll number
 bella                  1
 mike                   2
 **********************list of ELECTRONICS depatrment students******************
****
 Name of student        Roll number
 john                   1
 tim                    2
 *******************WELCOME TO OUR COLLEGE*************************
 1.create list
 2.Insert record in list
 3.search record in list
 4.delete record record from list
 5.display record
 6.exit
 Enter your choice              :       3

 *********************OPENED SEARCHING MODULE*************************
 1.Computer department
 2.Mechanical department
 3.Electronics depatment
 Enter students department choice(1/2/3)        :       1

 enter roll number of student   :       2

 entered roll number 2 is found
 name of student is     :       lun
 *******************WELCOME TO OUR COLLEGE*************************
 1.create list
 2.Insert record in list
 3.search record in list
 4.delete record record from list
 5.display record
 6.exit
 Enter your choice              :       4

 *********************OPENED DELETE MODULE*************************
 1.Computer department
 2.Mechanical department
 3.Electronics depatment
 Enter your students department choice(1/2/3)   :       1

 enter the roll number of student you want to delete        :    1

 ******************GIVEN STUDENT DATA IS DELETED SUCESSFULLY SUCESSFULLY********
**********
 *******************WELCOME TO OUR COLLEGE*************************
 1.create list
 2.Insert record in list
 3.search record in list
 4.delete record record from list
 5.display record
 6.exit
 Enter your choice              :       5

 ***********************list of COMPUTER department students********************
***
 Name of student        Roll number
 lun                    2
 **********************list of MECHANICAL depatrment students*******************
***
 Name of student        Roll number
 bella                  1
 mike                   2
 **********************list of ELECTRONICS depatrment students******************
****
 Name of student        Roll number
 john                   1
 tim                    2
 *******************WELCOME TO OUR COLLEGE*************************
 1.create list
 2.Insert record in list
 3.search record in list
 4.delete record record from list
 5.display record
 6.exit
 Enter your choice              :       6
!!!!!!!!!!THANK YOU FOR CHOOSING OUR COLLEGE!!!!!!!!!!!!
--------------------------------
Process exited after 153.2 seconds with return value 0
Press any key to continue . . .*/
