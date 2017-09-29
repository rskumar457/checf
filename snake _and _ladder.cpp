#include <iostream> //header file for input output
#include <cstdlib>  //header file for random variable
using namespace std; //standard library
class snl  //defining node as class snl class for doubly liunked list
{
	public:
	int data;
	snl *next;
	snl *prev;
	snl() //defining constructer
	{
		data=0;
		next=NULL;
		prev=NULL;
	}
 };
 class game  //defining game class for creating board of snake and ladder and playing 
{ 	
	public:
	snl *head;  //pointers used for creating board
	snl *temp; //
	snl *p1;//pointers for pointing players position
	snl *p2;//
	int score1; //variablre for passing score as parameter
	int choice;
	int i; //variable for for loop
	game()  //defining constructer
	{
		head=NULL;
		temp=NULL;
	}
	void create()  //funtion for creating node
	{
		snl *newnode=new snl();
		head=newnode;
		temp=newnode;
		p1=head;
		p2=head;		
	}
	void insert(int value)  //funtion for creating whole board
	{
		if(head==NULL)
		{
			cout<<"\n no list is created";
			return;
		}
		else
		{
			snl *newnode=new snl;
			temp->data=value;
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}
	}
	int dice() //funtion for random varible
	{
		return(rand()%6+1);
	}
	int check(int score,int j,int choice2)  //function for checking snake and ladder
	{
		if(head==NULL)
		{
			cout<<"\n board is not created";
			return 0;
		}
		else
		{
			switch(score) //changing score as snake and ladder comes
			{
				case 98:
					score1=3;	
					break;
				case 93:
					score1=76;	
					break;
				case 61:
					score1=25;
					break;
				case 32:
					score1=8;
					break;
				case 36:
					score1=95;
					break;
				case 9:
					score1=30;
					break;
				case 63:
					score1=85;
					break;
				case 15:
					score1=68;
					break;
				default :
					score1=score;	
					break;
			}
			if(choice2==1)
			{
				if(score1>score and score1<100)  //condition if ladder comes
				{
					for(i=score;i<score1+j;i++)
					{
						p1=p1->next;
					}	
				}
				else if(score1<score)  //condition if snake comes
				{
					for(i=score1;i<score-j;i++)
					{
						p1=p1->prev;
					}
				}
				else if(score1==score)  //condition if no change occur
				{
					for(i=0;i<j;i++)
					{
						p1=p1->next;
					}
				}
			}
			else if(choice2==2)
			{
				if(score1>score and score1<100)	//condition if ladder comes
				{
					for(i=score;i<score1+j;i++)
					{
						p2=p2->next;
					}	
				}
				else if(score1<score)	//condition if snake comes
				{
					for(i=score1;i<score-j;i++)
					{
						p2=p2->prev;
					}
				}
				else if(score1==score) //condition if no change occur
				{
					for(i=0;i<j;i++)
					{
						p2=p2->next;
					}
				}
			}				
		}
	return score1;  //returning new score to main function
	}
	void display() // funtion for displayinfg board and snakes and ladders
	{
		cout<<"\n your board is ready";
		cout<<"\n ";
		cout<<"\n  ----------------------------------------";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n |91  |92 |93 |94 |95 |96 |97 |98 |99 |100|";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n  ----------------------------------------";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n |90  |89 |88 |87 |86 |85 |84 |83 |82 |81 |";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n  ----------------------------------------";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n |71  |72 |73 |74 |75 |76 |77 |78 |79 |80 |";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n  ----------------------------------------";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n |70  |69 |68 |67 |66 |65 |64 |63 |62 |61 |";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n  ----------------------------------------";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n |51  |52 |53 |54 |55 |56 |57 |58 |59 |60 |";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n  ----------------------------------------";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n |50  |49 |48 |47 |46 |45 |44 |43 |42 |41 |";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n  ----------------------------------------";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n |31  |32 |33 |34 |35 |36 |37 |38 |39 |40 |";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n  ----------------------------------------";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n |30  |29 |28 |27 |26 |25 |24 |23 |22 |21 |";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n  ----------------------------------------";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n |11  |12 |13 |14 |15 |16 |17 |18 |19 |20 |";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n  ----------------------------------------";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n |1   |2  |3  |4  |5  |6  |7  |8  |9  |10 |";
		cout<<"\n |    |   |   |   |   |   |   |   |   |   |";
		cout<<"\n  ----------------------------------------";
		cout<<"\n ";
		cout<<"\n------------- SNAKES----------";
		cout<<"\n 98 to 3";
		cout<<"\n 93 to 76";
		cout<<"\n 61 to 25";
		cout<<"\n 32 to 8";
		cout<<"\n ";
		cout<<"\n -------------LADDERS----------";
		cout<<"\n 36 to 95";
		cout<<"\n 9 to 30";
		cout<<"\n 63 to 85";
		cout<<"\n 15 to 68";
		cout<<"\n ****************BEST OF LUCK******************";
	}
}; 
int main()
{
	game fun; //creating object
	int i;
	int choice1;
	int choice;
	int score1=1; //storing score of player 1 but first initializing it as 1
	int score2=1; //storing score of player  but first initializing it as 1
	int y;  //variable for storing random variable
	cout<<"\n ";																			//	
	cout<<"\n *********************WELCOME TO SNAKE AND LADER GAME**************************";//
	cout<<"\n ***********************I WISH YOU HAVE A GOOD GAME****************************";//
	do//
	{	cout<<"\n ";//
		cout<<"\n 1.CREATE LIST";//
		cout<<"\n 2.CREATE PLAYING BOARD";//				MENU
		cout<<"\n 3.PLAY GAME";	//
		cout<<"\n 4.EXIT";//
		cout<<"\n enter your choice	:	";//
		cin>>choice1;
		switch(choice1)
		{
			case 1: //case for creating first node
				fun.create();  //calling create function
				break;
			case 2: //case for creating board
				for(i=1;i<=100;i++)
				{
					fun.insert(i);  //calling insert function
				}
				break;
			case 3: //case for playing game
				fun.display();  //calling display function
				do
				{
				cout<<"\n player 1 your turn press 1 to continue	:	";
				cin>>i;
				if(i==1)
				{					
					y=fun.dice();  //calling random variable function
					score1=score1+y;
					if(score1==100)
					{
						cout<<"\n player 1 is the winner";
						return score1;
					}	
					else if(score1>100)  //condition if score is greater than hundred
					{
							score1=score1-y;
							cout<<"\n your score can't be greater than 100";
							cout<<"\n so it remains same"<<score1;
					}
					else
					{
						choice=1;					
						score1=fun.check(score1,y,choice); //calling check function 
						cout<<"\n numder on dice is	:	"<<y;
						cout<<"\n your score is		:	"<<score1;			
					}
				}
				cout<<"\n player 2 your turn press 1 to continue	:	";
				cin>>i;
				if(i==1)
				{
					y=fun.dice();
					score2=score2+y;
					if(score2==100)  //calling random variable function
					{
						cout<<"\n player 2 is the winner";
						return  score2;
					}
					else if(score2>100)   //condition if score is greater than hundred
					{
						score2=score2-y;
						cout<<"\n your score can't be greater than 100";
						cout<<"\n so it remains same"<<score2;
					}
					else
					{
						choice=2;
						score2=fun.check(score2,y,choice); //calling check function 
						cout<<"\n numder on dice is	:	"<<y;
						cout<<"\n your score is		:	"<<score2;
					}
				}
			}while(score1!=100 or score2!=100);
			break;
			case 4:  //case for exit
				cout<<"\n !!!!!!!!!!!!!!!!THANK YOU FOR PLAYING!!!!!!!!!!!!!!!!!!!";
				break;
			default:  //default case
				cout<<"\n please enter a valid choice";
				break;			 
		}	
	}while(choice1!=4);// close do while loop
	return 0;
}
//output
/* |    |   |   |   |   |   |   |   |   |   |
 |11  |12 |13 |14 |15 |16 |17 |18 |19 |20 |
 |    |   |   |   |   |   |   |   |   |   |
  ----------------------------------------
 |    |   |   |   |   |   |   |   |   |   |
 |1   |2  |3  |4  |5  |6  |7  |8  |9  |10 |
 |    |   |   |   |   |   |   |   |   |   |
  ----------------------------------------

------------- SNAKES----------
 98 to 3
 93 to 76
 61 to 25
 32 to 8

 -------------LADDERS----------
 36 to 95
 9 to 30
 63 to 85
 15 to 68
 ****************BEST OF LUCK******************
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       6
 your score is          :       7
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       6
 your score is          :       7
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       5
 your score is          :       12
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       5
 your score is          :       12
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       6
 your score is          :       18
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       5
 your score is          :       17
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       1
 your score is          :       19
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       1
 your score is          :       18
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       5
 your score is          :       24
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       3
 your score is          :       21
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       6
 your score is          :       30
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       6
 your score is          :       27
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       2
 your score is          :       8
 player 2 your turn press 1 to continue :
1

 numder on dice is      :       4
 your score is          :       31
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       2
 your score is          :       10
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       6
 your score is          :       37
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       2
 your score is          :       12
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       3
 your score is          :       40
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       4
 your score is          :       16
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       1
 your score is          :       41
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       4
 your score is          :       20
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       1
 your score is          :       42
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       3
 your score is          :       23
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       4
 your score is          :       46
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       5
 your score is          :       28
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       5
 your score is          :       51
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       4
 your score is          :       8
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       3
 your score is          :       54
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       3
 your score is          :       11
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       6
 your score is          :       60
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       6
 your score is          :       17
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       1
 your score is          :       25
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       6
 your score is          :       23
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       1
 your score is          :       26
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       4
 your score is          :       27
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       5
 your score is          :       31
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       6
 your score is          :       33
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       2
 your score is          :       33
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       2
 your score is          :       35
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       1
 your score is          :       34
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       6
 your score is          :       41
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       4
 your score is          :       38
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       3
 your score is          :       44
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       4
 your score is          :       42
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       4
 your score is          :       48
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       3
 your score is          :       45
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       4
 your score is          :       52
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       2
 your score is          :       47
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       6
 your score is          :       58
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       5
 your score is          :       52
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       6
 your score is          :       64
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       3
 your score is          :       55
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       5
 your score is          :       69
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       4
 your score is          :       59
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       4
 your score is          :       73
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       2
 your score is          :       25
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       6
 your score is          :       79
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       4
 your score is          :       29
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       2
 your score is          :       81
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       5
 your score is          :       34
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       5
 your score is          :       86
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       6
 your score is          :       40
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       3
 your score is          :       89
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       1
 your score is          :       41
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       1
 your score is          :       90
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       5
 your score is          :       46
 player 1 your turn press 1 to continue :       1

 numder on dice is      :       5
 your score is          :       95
 player 2 your turn press 1 to continue :       1

 numder on dice is      :       3
 your score is          :       49
 player 1 your turn press 1 to continue :       1

 player 1 is the winner
--------------------------------
Process exited after 26.97 seconds with return value 100
Press any key to continue . . .
*/
