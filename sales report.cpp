
//============================================================================
// Name        : Assingnment1.cpp
// Author      : ritik
// title    :   salesperson@mishop
// Batch & Block : B4-2
// Roll no. :  432
//============================================================================

#include <iostream>  //header file
using namespace std;//standard library
class customer_mi{   //opening class
public:

    // declaring variables
    string customer_name;  //variable for storing customer name
    int customer_id;    //variable for storing  customer id
    string product_name;   //variable for storing  product name
    int product_amount;//variable for storing  product amount
    long cutomer_mobile_number; //variable for storing  customer mobile number
    customer_mi(){  //declaring constructor
        customer_name="no name";
        customer_id=99999999;
        product_name="no name";
        product_amount=99999999;
        cutomer_mobile_number=99999999;


        } //closing constructor
    void getdata() { //opening input function
        cout<<"\n enter the name of the customer    :    ";
        cin>>customer_name;
        cout<<"\n enter the id of customer        :    ";
        cin>>customer_id;
        cout<<"\n enter the name of bought product    :    ";
        cin>>product_name;
        cout<<"\n enter the price of product    :    ";
        cin>>product_amount;
        cout<<"\n enter customer mobile number    :    ";
        cin>>cutomer_mobile_number;
        cout<<"*************CUSTOMER DETAILS ARE UPDATED******************************";
    }   //closing input function
    void display(){   //opening display function
        cout<<"\n *************CUSTOMER DETAILS************************";
        cout<<"\n";
        cout<<"\n customer id    :    "<<customer_id;
        cout<<"\n name of  customer     :    "<<customer_name;
        cout<<"\n name of product    :    "<<product_name;
        cout<<"\n price of product    :    "<<product_amount;
        cout<<"\n customer's mobile number is    :    "<<cutomer_mobile_number;
    }// closing display function
};// closing class
int main() {//opening main function
    // declaring variables
    int i;  // variable for for loop
    int choice;  // variable for storing choice
    customer_mi acust[15];  // creating array of object
    int customer_number=0;   //initializing  customer number as 0
    int existing_id;   //variable for searching
    int flag;  //counter variable

    do
    {  //opening do while loop
        // for displaying menu of choices to the user
        cout<<"\n **************MI mobile store**************************************** ";
        cout<<"\n 1.Add customer";
        cout<<"\n 2.Display details of the customer";
        cout<<"\n 3.exit";
        cout<<"\n 4.search";
        cout<<"\n enter your choice	:	";
        cin>>choice;
        cout<<"\n last customer number is	:	 "<< customer_number;
        cout<<"\n please enter customer number incremented by 1 if asked";
        if (choice==1){  //conditional statement for adding customer
        cout<<"\n enter customer number	:	";
        cin>>customer_number;
        }
        switch(choice)
        { //opening switch case
        case 1: // first case for adding new customer
            for(i=customer_number-1;i<customer_number;i++){ //opening for loop for adding new customer
            acust[i].getdata(); //calling get data function
            }  //closing for loop
            break; //breaking case 1
        case 2: //second case for displaying customer details customer
            for(i=0;i<customer_number;i++)//opening for loop for displaying whole details
            acust[i].display(); //calling display function
            break; //breaking of case 2
        case 3:  //third case is for exit
            cout<<"\n *******Thank you for visiting******************";
            cout<<"\n ***********Visit Again*************************";
            break; //breaking of case 3
        case 4:   //fourth case is for searching
            cout<<"\n enter customer id    :    ";
            cin>>existing_id;

            for(i=0;i<15;i++)  //opening for loop searching
                    {
                        if (acust[i].customer_id==existing_id)  //comparing whether customer is in record or not
                        {
                            flag=i;
                            break;
                        }
                        else
                        {
                            flag=15;
                        }
                    }
            if (flag!=15)  //comparing value of flag for displaying customer details
            {
                acust[flag].display();  //displaying customer details
            }
            else
            {
                cout<<"\n no such record found";
            }
            break; //breaking case 4

        default:  //opening default case for any value other than choices
            cout<<"/n please enter a valid input";
            break;
     }
    }while(choice!=3);  //closing do while loop
    return 0;  //returning value zero
}//closing main function
//output
/*
 **************MI mobile store**************************************** 
 1.Add customer
 2.Display details of the customer
 3.exit
 4.search
 enter your choice1

 last customer number is 0
 please enter customer number incremented by 1 if asked
 enter customer number1

 enter the name of the customer    :    ram

 enter the id of customer        :    34

 enter the name of bought product    :    mi

 enter the price of product    :    3456

 enter customer mobile number    :    764575858
*************CUSTOMER DETAILS ARE UPDATED******************************
 **************MI mobile store**************************************** 
 1.Add customer
 2.Display details of the customer
 3.exit
 4.search
 enter your choice1

 last customer number is 1
 please enter customer number incremented by 1 if asked
 enter customer number2

 enter the name of the customer    :    sam

 enter the id of customer        :    36

 enter the name of bought product    :    mii

 enter the price of product    :    7564

 enter customer mobile number    :    2367464775
*************CUSTOMER DETAILS ARE UPDATED******************************
 **************MI mobile store**************************************** 
 1.Add customer
 2.Display details of the customer
 3.exit
 4.search
 enter your choice4

 last customer number is 2
 please enter customer number incremented by 1 if asked
 enter customer id    :    34

 *************CUSTOMER DETAILS************************

 customer id    :    34
 name of  customer     :    ram
 name of product    :    mi
 price of product    :    3456
 customer's mobile number is    :    764575858
 **************MI mobile store**************************************** 
 1.Add customer
 2.Display details of the customer
 3.exit
 4.search
 enter your choice4

 last customer number is 2
 please enter customer number incremented by 1 if asked
 enter customer id    :    36

 *************CUSTOMER DETAILS************************

 customer id    :    36
 name of  customer     :    sam
 name of product    :    mii
 price of product    :    7564
 customer's mobile number is    :    2367464775
 **************MI mobile store**************************************** 
 1.Add customer
 2.Display details of the customer
 3.exit
 4.search
 enter your choice2

 last customer number is 2
 please enter customer number incremented by 1 if asked
 *************CUSTOMER DETAILS************************

 customer id    :    34
 name of  customer     :    ram
 name of product    :    mi
 price of product    :    3456
 customer's mobile number is    :    764575858
 *************CUSTOMER DETAILS************************

 customer id    :    36
 name of  customer     :    sam
 name of product    :    mii
 price of product    :    7564
 customer's mobile number is    :    2367464775
 **************MI mobile store**************************************** 
 1.Add customer
 2.Display details of the customer
 3.exit
 4.search
 enter your choice3

 last customer number is 2
 please enter customer number incremented by 1 if asked
 *******Thank you for visiting****************
 *************Visit Again*********************
 */


