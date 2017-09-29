/*name-Ritik Kumar
/Batch & Block :- B4-2
/Roll No.:-432
/Title:-Design and implement a program to generate a computerized 
telephone directory for a cellular service consisting of name and
cell phone number. Present the user with a menu that allows the
user to search the directory for a specified record, insert a 
new record, delete an existing record, or print the entire phone list.
*/
#include <iostream>  //header file input ouput
#include <cstring>  //header file for string operation
using namespace std;  //standard lib
class node  //opening node class
{
	public:  //acess specifier
	char custname[15];  //variable for storing name 
	long int mobno;  //variable for storing mobile number 
	node *left; 	//pointer of node type
	node *right;	//pointer of node type
	node()                  //constructor
	{
		custname[15]='\0';
		mobno=999999;
		left=NULL;
		right=NULL;
	}
};//closing node class
class phonebook  //
{
	public:	//acess specifier
	node *root;	//pointer of node type
	node *temp;	//pointer of node type
	node *ptr;	//pointer of node type
	phonebook()	//constructor
	{
		root=NULL;
		temp=NULL;
		ptr=NULL;
	}
	void add()	//function for adding new conntact without recursion
	{
		int choice; 
		node *newnode=new node; //creating new node
		cout<<"\n enter name of customer	:	";
		cin>>newnode->custname;
		cout<<"\n enter mobile of customer	:	";
		cin>>newnode->mobno;
		if(root==NULL) //condition for saving first contact
		{
			root=newnode;
			return;
		}
		else
		{
			temp=root;
			do
			{ 	
				if(strcmp(temp->custname,newnode->custname)<0) //comparing data for deciding the direction of pointer 
				{
					if(temp->right==NULL)  //condition for adding contact in right
					{
						temp->right=newnode;
						return; 
					}
					else 
					{
						temp=temp->right;
					}
				}
				else if(strcmp(temp->custname,newnode->custname)>0)	//comparing data for deciding the direction of pointer 
				{
					if(temp->left==NULL)	//condition for adding contact in left
					{
						temp->left=newnode;	
						return;
					}
					else
					{
						temp=temp->left;
					}				
				}
				else  //condition if this customer name alerady exist
				{
					cout<<"\n contact of this number already exist in your phonebook";
					cout<<"\n what do you want-----";
					cout<<"\n 1.craete a new contact";
					cout<<"\n 2.update existing contact or you want to replace it";
					cout<<"\n enter your choice";
					cin>>choice;
					do{
						switch(choice)
						{
							case 1:		//case for creating new contact
								if(temp->left==NULL)  		//
								{								
									temp->left=newnode;		//
									return;
								}
								else if(temp->right==NULL)	//
								{
									temp->right=newnode;	//conditions for adding new contact
									return;
								}
								else						//
								{
									newnode->left=temp->left;
									temp->left=newnode;		//
									return;
								}
								break;						//
							case 2:  //case for replaicng new information from old one
								update(temp->custname);   // calling update funtiion for updating customer details
								delete newnode;
								break;
							default: //default case
								cout<<"\n please enter a valid input";
								break;
						}
					}while(choice>2);
				}	
			}while(1==1);		
		}
	}
	void inorder(node *temp)  //funtion for recursively dispalying contacts in inorder 
	{
		if(temp==NULL)
		{
			return;
		}
		inorder(temp->left);
		cout<<"\n ----------------------------------------------------------------------------";
		cout<<"\n name of the person is	:	"<<temp->custname;
		cout<<"\n mobile number of the person is	:	"<<temp->mobno;
		cout<<"\n ----------------------------------------------------------------------------";
		inorder(temp->right);
	}
	void preorder(node *temp)	//funtion for recursively dispalying contacts in preorder
	{
		if(temp==NULL)
		{
			return;
		}
		cout<<"\n ----------------------------------------------------------------------------";
		cout<<"\n name of the person is	:	"<<temp->custname;
		cout<<"\n mobile number of the person is	:	"<<temp->mobno;
		cout<<"\n ----------------------------------------------------------------------------";
		preorder(temp->left);
		preorder(temp->right);
	}
	void postorder(node *temp)	//funtion for recursively dispalying contacts in postorder
	{
		if(temp==NULL)
		{
			return;
		}
		postorder(temp->left);
		postorder(temp->right);
		cout<<"\n ----------------------------------------------------------------------------";
		cout<<"\n name of the person is	:	"<<temp->custname;
		cout<<"\n mobile number of the person is	:	"<<temp->mobno;
		cout<<"\n ----------------------------------------------------------------------------";
	}
	void display(int x)  // funtion for the choosing the way of display
	{
		if (root==NULL)
		{
			cout<<"\n no contact is saved in  your phonebook";
			return;
		}
		else
		{
			switch(x)
			{
				case 1:
					inorder(root);  //calling inorder funtion 
					break;
				case 2:
					preorder(root);	//calling preorder funtion
					break;
				case 3:
					postorder(root); //calling postorder funtion
					break;
				default:
					cout<<"please enter a valid input";
					break;
			}
		}

	}
	node *search(char name[])  //funtion for serching person by his name
	{
		if (root==NULL)  //checking whether contact exist or not
		{
			cout<<"\n no contact is saved in  your phonebook";
			return root;
		}
		else
		{
			temp=root;
			do{
				if(strcmp(temp->custname,name)>0)  //
				{
					temp=temp->left;			  //	comparing names for deciding direction of traversing
				}
				else if(strcmp(temp->custname,name)<0)
				{								 //
					temp=temp->right;
				}								
				else							
				{										//if person found
					cout<<"\n contact found";
				    cout<<"\n --------------------------------------------------------------------------";
					cout<<"\n name of the person is	:	"<<temp->custname;
					cout<<"\n mobile number of the person is	:	"<<temp->mobno;
					cout<<"\n --------------------------------------------------------------------------";
					return temp;
				}
				if(temp==NULL)  //contion if given name not found
				{
					cout<<"\n no such record found";
					return temp;
				}
			}while(temp!=NULL);
		}		
	}
	void update(char name[])  //condition for upating mobile number of person
	{
		if (root==NULL)	//checking whether contact exist or not
		{
			cout<<"\n no contact is saved in  your phonebook";
			return;
		}
		ptr=search(name);  //storing address of person in ponter named ptr
		if(ptr!=NULL)  //condition for updating mobile number
		{
		cout<<"\n enter new mobile number of customer	:	";
		cin>>ptr->mobno;
		cout<<"\n contact is successfully updated";
		}
		else  //if person not found
		{
			cout<<"\n so we cannot update given  contact";	
		}
	}
	node *del(node *temp,char name[])  //function for deleting contact 
	{
		int i=0; //initialization of variablre for loop
		if (root==NULL)	//checking whether contact exist or not
		{
			cout<<"\n no contact is saved in  your phonebook";
			return root;
		}
		else if(temp==NULL)	//if person not found
		{
			cout<<"\n no such record found";
			return temp;
		}
		else
		{
			if(strcmp(temp->custname,name)>0)			//
			{
				temp->left=del(temp->left,name);		//
			}
			else if(strcmp(temp->custname,name)<0)		//	comparing names for deciding direction of traversing
			{
				temp->right=del(temp->right,name);		//
			}
			else		// if person found and further performing deletion operation 
			{
				if(temp->right==NULL && temp->left==NULL)  //condition if node have no child
				{
					delete temp;
					return NULL;
				}
				else if(temp->left==NULL)  // condition if only right child
				{
					return temp->right;
				}
				else if(temp->right==NULL)	// condition if only right child
				{
					return temp->left;
				}
				else			//condition if both childs are there 
				{
					ptr=temp->right;
					while(ptr->left!=NULL)
					{
						ptr=ptr->left;
					}
					while(temp->custname[i]!=' ')
					{
						temp->custname[i]=ptr->custname[i];
						i++;
					}
					ptr->custname[15]=name[15];
					temp->right=del(temp->right,name);
					delete ptr;
				}
			}
		}		
	}
	void  addrecursion(node *temp,string name)  //adding new contact via recursion
	{
		if(temp==NULL)  //condition for saving first contact
		{
			node *newnode=new node;
			for(int i=0;i<15;i++)
			{
			newnode->custname[i]=name[i];
			}
			cout<<"\n enter the mobile number of person		:	";
			cin>>newnode->mobno;
			root=newnode;
			return ;
		}
		else
		{ 
			if(temp->custname>name)//comparing data for deciding the direction of pointer 
			{
				if(temp->left==NULL)  //checking whether node have left child or not
				{
					node *newnode=new node;
					for(int i=0;i<15;i++)
					{
					newnode->custname[i]=name[i];
					}
					cout<<"\n enter the mobile number of person		:	";
					cin>>newnode->mobno;
					temp->left=newnode;
					return ;
				}
				else
				{
					addrecursion(temp->left,name);	//caling recursion function with left
				}
			}
			else if(temp->custname<name)
			{
				if(temp->right==NULL)	//checking whether node have right child or not
				{
					node *newnode=new node;
					for(int i=0;i<15;i++)
					{
						newnode->custname[i]=name[i];
					}
					cout<<"\n enter the mobile number of person		:	";
					cin>>newnode->mobno;
					temp->right=newnode;
					return ;
				}
				else
				{
					addrecursion(temp->right,name);	//caling recursion function with right
				}
			}
		}
	}
};

int main()
{
	char name[15];  //variable storing name and passing it through function
	phonebook contact;  //creating object of class phonebook
	int choice;  //variable for choosing option
	cout<<"WELCOME";//
	do
	{
		cout<<"\n 1.add contact	without recursion";//
		cout<<"\n 2.add contact with recursion";//
		cout<<"\n 3.display";//
		cout<<"\n 4.search";//
		cout<<"\n 5.update";//                   ************MENU****************
		cout<<"\n 6.delete";//
		cout<<"\n 7.exit";//
		cout<<"\n enter your choice	:	";//
		cin>>choice;
		switch (choice)
		{
			case 1: //case for adding contact without recursion
				contact.add(); // calling add function
				break;
			case 2: //case for adding contat recursively
				cout<<"\n enter the name of the  person		:	";
				cin>>name;
				contact.addrecursion(contact.root,name); // calling recusively adding 
				break;
			case 3:  //case for displaying whole phonebook
				cout<<"\n 1.inorder";
				cout<<"\n 2.preorder";
				cout<<"\n 3.postorder";
				cout<<"\n select the way in which you want to see your contacts";
				cin>>choice;
				contact.display(choice);  //calling display function
				break;
			case 4: // case for searching contact of a person
				cout<<"\n enter the name of the  person		:	";
				cin>>name;
				contact.search(name);  //calling searching function
				break;
			case 5:  //case for updating mobile number of a person
				cout<<"\n enter the name of the  person		:	";
				cin>>name;
				contact.update(name);//calling update function 
				break;
			case 6: //case for de;eting contact of a person
				cout<<"\n enter the name of the  person		:	";
				cin>>name;
				contact.del(contact.root,name);  //calling delete function
				break;
			case 7:  //case for exit
				cout<<"\n THANK YOU";
				break;
			default : //default case
				cout<<"\n please enter a valid choice";
				break;
		}
	}while(choice!=7);  //condition for breaking do while loop
	return 0;  //returninng zero 
} //closing main function
/*output
 3.display
 4.search
 5.update
 6.delete
 7.exit
 enter your choice      :       2

 enter the name of the  person          :       saraaf

 enter the mobile number of person              :       56435

 1.add contact  without recursion
 2.add contact with recursion
 3.display
 4.search
 5.update
 6.delete
 7.exit
 enter your choice      :       3

 1.inorder
 2.preorder
 3.postorder
 select the way in which you want to see your contacts1

 ----------------------------------------------------------------------------
 name of the person is  :       mithil
 mobile number of the person is :       687453
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       nitesh
 mobile number of the person is :       65664
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       rawAL
 mobile number of the person is :       36151
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       rishav
 mobile number of the person is :       874564
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       ritik
 mobile number of the person is :       8765132
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       saraaf
 mobile number of the person is :       56435
 ----------------------------------------------------------------------------
 1.add contact  without recursion
 2.add contact with recursion
 3.display
 4.search
 5.update
 6.delete
 7.exit
 enter your choice      :       3

 1.inorder
 2.preorder
 3.postorder
 select the way in which you want to see your contacts2

 ----------------------------------------------------------------------------
 name of the person is  :       ritik
 mobile number of the person is :       8765132
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       rishav
 mobile number of the person is :       874564
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       mithil
 mobile number of the person is :       687453
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       nitesh
 mobile number of the person is :       65664
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       rawAL
 mobile number of the person is :       36151
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       saraaf
 mobile number of the person is :       56435
 ----------------------------------------------------------------------------
 1.add contact  without recursion
 2.add contact with recursion
 3.display
 4.search
 5.update
 6.delete
 7.exit
 enter your choice      :       3

 1.inorder
 2.preorder
 3.postorder
 select the way in which you want to see your contacts2

 ----------------------------------------------------------------------------
 name of the person is  :       ritik
 mobile number of the person is :       8765132
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       rishav
 mobile number of the person is :       874564
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       mithil
 mobile number of the person is :       687453
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       nitesh
 mobile number of the person is :       65664
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       rawAL
 mobile number of the person is :       36151
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       saraaf
 mobile number of the person is :       56435
 ----------------------------------------------------------------------------
 1.add contact  without recursion
 2.add contact with recursion
 3.display
 4.search
 5.update
 6.delete
 7.exit
 enter your choice      :       3

 1.inorder
 2.preorder
 3.postorder
 select the way in which you want to see your contacts3

 ----------------------------------------------------------------------------
 name of the person is  :       rawAL
 mobile number of the person is :       36151
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       nitesh
 mobile number of the person is :       65664
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       mithil
 mobile number of the person is :       687453
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       rishav
 mobile number of the person is :       874564
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       saraaf
 mobile number of the person is :       56435
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       ritik
 mobile number of the person is :       8765132
 ----------------------------------------------------------------------------
 1.add contact  without recursion
 2.add contact with recursion
 3.display
 4.search
 5.update
 6.delete
 7.exit
 enter your choice      :       4

 enter the name of the  person          :       mithil

 contact found
 --------------------------------------------------------------------------
 name of the person is  :       mithil
 mobile number of the person is :       687453
 --------------------------------------------------------------------------
 1.add contact  without recursion
 2.add contact with recursion
 3.display
 4.search
 5.update
 6.delete
 7.exit
 enter your choice      :       4

 enter the name of the  person          :       tushar

 no such record found
 1.add contact  without recursion
 2.add contact with recursion
 3.display
 4.search
 5.update
 6.delete
 7.exit
 enter your choice      :       4

 enter the name of the  person          :       rishav

 contact found
 --------------------------------------------------------------------------
 name of the person is  :       rishav
 mobile number of the person is :       874564
 --------------------------------------------------------------------------
 1.add contact  without recursion
 2.add contact with recursion
 3.display
 4.search
 5.update
 6.delete
 7.exit
 enter your choice      :       5

 enter the name of the  person          :       nitesh

 contact found
 --------------------------------------------------------------------------
 name of the person is  :       nitesh
 mobile number of the person is :       65664
 --------------------------------------------------------------------------
 enter new mobile number of customer    :       889745

 contact is successfully updated
 1.add contact  without recursion
 2.add contact with recursion
 3.display
 4.search
 5.update
 6.delete
 7.exit
 enter your choice      :       4

 enter the name of the  person          :       nitesh

 contact found
 --------------------------------------------------------------------------
 name of the person is  :       nitesh
 mobile number of the person is :       889745
 --------------------------------------------------------------------------
 1.add contact  without recursion
 2.add contact with recursion
 3.display
 4.search
 5.update
 6.delete
 7.exit
 enter your choice      :       6

 enter the name of the  person          :       mithil

 1.add contact  without recursion
 2.add contact with recursion
 3.display
 4.search
 5.update
 6.delete
 7.exit
 enter your choice      :       3

 1.inorder
 2.preorder
 3.postorder
 select the way in which you want to see your contacts1

 ----------------------------------------------------------------------------
 name of the person is  :       nitesh
 mobile number of the person is :       889745
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       rawAL
 mobile number of the person is :       36151
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       rishav
 mobile number of the person is :       874564
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       ritik
 mobile number of the person is :       8765132
 ----------------------------------------------------------------------------
 ----------------------------------------------------------------------------
 name of the person is  :       saraaf
 mobile number of the person is :       56435
 ----------------------------------------------------------------------------
 1.add contact  without recursion
 2.add contact with recursion
 3.display
 4.search
 5.update
 6.delete
 7.exit
 enter your choice      :       7

 THANK YOU
--------------------------------
Process exited after 189.3 seconds with return value 0
Press any key to continue . . .
*/
