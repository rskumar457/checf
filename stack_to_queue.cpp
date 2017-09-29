#include <iostream> // inliuding header file
#define true 1   //definining true as 1
#define false -1	//definining false as -1
using namespace std;  // standard library
class stack  //opening class named stack
{
	public:
	int top=-1;  //initializing top as -1  
	int Isempty() //funtion for checking condition for underflow
	{
		if(top==-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int Isfull(int size)  //function for checking condition for overflow
	{
		if(top>=size-1)
		{
			return true;	
		}	
		else
		{
			return false;
		}
	}
	void push(int x,int S[],int size)  //funtion for pushing elemennt into stack
	{
		if(Isempty()>0)  //condition for first element pushing into stack
		{
			top=0;
			S[top]=x;
		}
		else if(Isfull(size)>0) //stack overflow
		{
			cout<<"\n SORRY, you can't push element into stack it is already full";
		}
		else // pusing elemeng into stack
		{
			S[++top]=x;	//first incrementing top and then pushing element into stack
		}	
	}
	int pop(int S[]) //function for poping element from stack
	{
		int poped;
		if(Isempty()>0)  //underflow condition
		{
			cout<<"\n SORRY, you can't pop element from stack it is empty";
			return 0;
		}
		else if(top==0)  //condition for poping last element
		{
			poped=S[top];
			top=-1;
			cout<<"\n"<<poped<<" is poped from stack";
			return poped;	
		}
		else  // condition for poping element from stack
		{
			poped=S[top];
			top--;  //decrementing top
			cout<<"\n"<<poped<<" is poped from stack";
			return poped;	
		}	
	}		
}; //closing class named stack
class queue : public stack //opening class named queue inherits properties of base class 
{
	public:
	int front=-1;  //intializing fornt as -1
	int rear=-1;	//intializing rear as -1
	int qIsempty() // funtion for queue is uderflow
	{
		if(front==rear && rear==-1)
		{
			return true;
		}
		return false;
	}
	int qIsfull(int size) // function for queue is overflow
	{
		if(front==(rear+1)%size)
		{
			return true;
		}
		return false;
	}
	void enqueue(int size,int Q[],int S[]) //funtion for enqueing element in queue poped from stack
	{
		int y;
		y=pop(S); //poping element from stack 
		if(y!=0) // condition  for checking whether any element is poped or not 
		{
			if(qIsempty()>0) //condition for enqueuing first element into queue
			{
				front=0;
				rear=0;
				Q[rear]=y;
				cout<<"\n"<<y<<" is enqueued into queue from stack";
			}
			else if(qIsfull(size)>0) // condition if queue is overflow
			{
				cout<<"\n sorry queue is full you can't enter a element in queue";
			}
			else //enqueing element into queue poped from stack  
			{
				rear=(rear+1)%size; //incrementing rear
				Q[rear]=y; //storing elment into queue
				cout<<"\n"<<y<<" is enqueued into queue from stack";
			}
		}
	}
	void display(int Q[],int S[],int size) //funtion for displaying status of stack and queue
	{
		int i; //counter variable
		if(qIsempty()>0 && Isempty()>0) //condition if both stack and queue are empty
		{
			cout<<"\n no element in stack";
			cout<<"\n no element in queue";	
		}
		else if(Isempty()>0 && qIsempty()<0) //conditon if stack is empty and queue is not
		{
			cout<<"\n no element in stack";	
			cout<<"\n elements in queue are :-";
			for(i=front;i<rear+1;i++)  //loop for displaying elements in queue
			{
				cout<<"\n "<<Q[i]<<" "<<" at "<<i<<" position";
			}
		}
		else if(qIsempty()>0 && Isempty()<0) //conditon if queue is empty and stack is not
		{
			cout<<"\n no element in queue";	
			cout<<"\n elements in stack are	:-";
			for(i=0;i<top+1;i++) //loop for displaying elements in stack
			{
				cout<<"\n "<<S[i]<<" "<<" at "<<i<<" position";
			}
		}
		else if(qIsempty()<0 && Isempty()<0) //conditon if stack and queue both are not empty
		{
			cout<<"\n elements in stack are	:-";
			for(i=0;i<top+1;i++) //loop for displaying elements in stack
			{
				cout<<"\n "<<S[i]<<" "<<" at "<<i<<" position";
			}
			cout<<"\n elements in queue are :-";
			for(i=front;i<rear+1;i++) //loop for displaying elements in queue
			{
				cout<<"\n "<<Q[i]<<" "<<" at "<<i<<" position";
			}
		}	
	}
};
int main()
{
	int a; //variable for pasing element into stack
	queue q;  // creating objectof derived class
	int choice;  //variable for chioice
	int size; // variable for storing size of array
	cout<<"\n Enter the size of stack	:	";
	cin>>size;
	int S[size];  //declaring array for stack
	int Q[size]; //declaring array for queue
	do
	{
		cout<<"\n 1.Enter the element in stack";     				//
		cout<<"\n 2.Delete element from stack and insert it in queue";//
		cout<<"\n 3.Display status of stack and queue";				//				MENU
		cout<<"\n 4.Exit";											//
		cout<<"\n Enter your choice	:	";							//
		cin>>choice;
		switch(choice)
		{
			case 1: // CASE FOR PUSHING ELEMENT INTO QUEUE
				cout<<"\n Enter the element	:	";
				cin>>a;
				q.push(a,S,size); //CALLING PUSH FUNCTION
				break;
			case 2: //CASE FOR ENQUEING ELEMENT INTO QUEUE
				q.enqueue(size,Q,S);  //CALLING ENQUEUE FUNCTION
				break;
			case 3: //CASE FOR DISPLAYING ELEMENT SATTUS OF STACK AND QUEUE
				q.display(Q,S,size); // CALLING DISPLAY FUNCTION
				break;
			case 4: //CASE FOR EXIT
				break;
			default : //DEDFULT CASE
				cout<<"\n plaease enter a valid input ";
				break;	
		}
	}while(choice!=4); // CONDITION FOR BREAKING DO WHILE LOOP
	return 0; // RETURNING ZERO
}
/*output

 Enter the size of stack        :       5

 1.Enter the element in stack
 2.Delete element from stack and insert it in queue
 3.Display status of stack and queue
 4.Exit
 Enter your choice      :       1

 Enter the element      :       64

 1.Enter the element in stack
 2.Delete element from stack and insert it in queue
 3.Display status of stack and queue
 4.Exit
 Enter your choice      :       195

 plaease enter a valid input
 1.Enter the element in stack
 2.Delete element from stack and insert it in queue
 3.Display status of stack and queue
 4.Exit
 Enter your choice      :       1

 Enter the element      :       95

 1.Enter the element in stack
 2.Delete element from stack and insert it in queue
 3.Display status of stack and queue
 4.Exit
 Enter your choice      :       1

 Enter the element      :       23

 1.Enter the element in stack
 2.Delete element from stack and insert it in queue
 3.Display status of stack and queue
 4.Exit
 Enter your choice      :       1

 Enter the element      :       2

 1.Enter the element in stack
 2.Delete element from stack and insert it in queue
 3.Display status of stack and queue
 4.Exit
 Enter your choice      :       1

 Enter the element      :       38

 1.Enter the element in stack
 2.Delete element from stack and insert it in queue
 3.Display status of stack and queue
 4.Exit
 Enter your choice      :       1

 Enter the element      :       73

 SORRY, you can't push element into stack it is already full
 1.Enter the element in stack
 2.Delete element from stack and insert it in queue
 3.Display status of stack and queue
 4.Exit
 Enter your choice      :       2

38 is poped from stack
38 is enqueued into queue from stack
 1.Enter the element in stack
 2.Delete element from stack and insert it in queue
 3.Display status of stack and queue
 4.Exit
 Enter your choice      :       3

 elements in stack are  :-
 64  at 0 position
 95  at 1 position
 23  at 2 position
 2  at 3 position
 elements in queue are :-
 38  at 0 position
 1.Enter the element in stack
 2.Delete element from stack and insert it in queue
 3.Display status of stack and queue
 4.Exit
 Enter your choice      :       2

2 is poped from stack
2 is enqueued into queue from stack
 1.Enter the element in stack
 2.Delete element from stack and insert it in queue
 3.Display status of stack and queue
 4.Exit
 Enter your choice      :       3

 elements in stack are  :-
 64  at 0 position
 95  at 1 position
 23  at 2 position
 elements in queue are :-
 38  at 0 position
 2  at 1 position
 1.Enter the element in stack
 2.Delete element from stack and insert it in queue
 3.Display status of stack and queue
 4.Exit
 Enter your choice      :       2

23 is poped from stack
23 is enqueued into queue from stack
 1.Enter the element in stack
 2.Delete element from stack and insert it in queue
 3.Display status of stack and queue
 4.Exit
 Enter your choice      :       2

95 is poped from stack
95 is enqueued into queue from stack
 1.Enter the element in stack
 2.Delete element from stack and insert it in queue
 3.Display status of stack and queue
 4.Exit
 Enter your choice      :       2

64 is poped from stack
64 is enqueued into queue from stack
 1.Enter the element in stack
 2.Delete element from stack and insert it in queue
 3.Display status of stack and queue
 4.Exit
 Enter your choice      :       2

 SORRY, you can't pop element from stack it is empty
 1.Enter the element in stack
 2.Delete element from stack and insert it in queue
 3.Display status of stack and queue
 4.Exit
 Enter your choice      :       3

 no element in stack
 elements in queue are :-
 38  at 0 position
 2  at 1 position
 23  at 2 position
 95  at 3 position
 64  at 4 position
 1.Enter the element in stack
 2.Delete element from stack and insert it in queue
 3.Display status of stack and queue
 4.Exit
 Enter your choice      :       4

--------------------------------
Process exited after 54.64 seconds with return value 0
Press any key to continue . . .
*/
