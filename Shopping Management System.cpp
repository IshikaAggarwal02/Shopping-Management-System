//Shopping Management System using Data Structures 
//Here, we have used arrays, linked list, stack and queues.

#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<sstream>
#include<windows.h>
#include"queue1.h"
#include"animation.h"
#include"stackme.h"

using namespace std;

int search(int);
int display();
string check(int); //<------- Used for checking the quantity

struct node
 {
	int ID;
	string fName;
	double fPrice;
	int quantity;
    struct  node* next;
};

struct node *head=NULL;

/////////////////////////////To insert a product
 void beg()
{
	system("cls");
	int id,quant;           //  quant    for quantity
	string name;
	double pre;            //  pre for price
	struct node *t=new node;
	struct node *p=head;

	cout<<"\nEnter Product ID:"<<endl;
	cin>>id;
	t->ID=id;
	cout<<"\nEnter Product Name: "<<endl;
	cin>>name;
	t->fName=name;
	cout<<"\nEnter Product Price:"<<endl;
	cin>>pre;
	t->fPrice=pre;
	cout<<"\nEnter Product Quantity: ";
	cin>>quant;
	t->quantity=quant;
	if(head==NULL)
	{
	t->next=head;
	head=t;
	}
	else
	{
		while(p->next!=NULL)
    {
		p=p->next;
                        }
        p->next=t;
        t->next=NULL;
		
	}	
	system("cls");
    cout<<"\n\n!!! This product is Inserted !!!\n\n\n";

	}

///////////////////////To search an item in the list
	int search(int id)                     
 {
 	int count=1;
 	struct node *p=head;
 	while(p!=NULL)
 	{
 		if(p->ID==id)
 			break;
 		else
 			count++;
 			p=p->next;
	}
 	return count;
 }
 ////////////////////////////To generate hash function
 int hash(int x, int mod)
{
	return x % mod;

}

/////////////////////////////To delete a product
	void delPro()
	{
		system("cls");
		display();
		int id;
		struct node *cur=head;
		struct node *pre=head;
		cout<<"\n\nEnter ID to Delete the Product:\n\n";
		cin>>id;
		 if (head == NULL)
    {
    	system("cls");
        cout<<"!! List is empty !!"<<endl;
    }
	int pos=0;
	int count=display();          //   to display total products/nodes
	pos=search(id);               //   to check whether the desired node exists or not
	if(pos<=count){

		while(cur->ID!=id){                //To delete intermediate products
			pre=cur;
			cur=cur->next;
}
		pre->next=cur->next;
		system("cls");
		cout<<"\n<< Item is deleted >>\n";
	}else{
		cout<<"\n<<< Not found >>\n\n";
	}
	}

////////////////////////////////To modify a particular product
	void modify()
	{
		int id;
		double pre;        //    pre for price
		string pName;
		int nid; int nq;     //   pName for new name
		if (head == NULL)
    {
    	system("cls");
        cout<<"List is empty"<<endl;
    }
        else
	{    
	    display();
		cout<<"\n\nEnter ID to modify product Name and its price:\n";
		cin>>id;
		struct node *cur=head;
		int pos=0;
		int count=display();     //To display total products/nodes
	    pos=search(id);			//To check whether the desired node exists or not
	                            
	    if(pos<=count)
    {
		while(cur->ID!=id)
        {
			cur=cur->next;
		}
		cout<<"\nOld ID : "<<cur->ID<<endl;
		cout<<"\nOld Name : "<<cur->fName<<endl;
		cout<<"\nOld Price : "<<cur->fPrice<<endl;
		cout<<"\nOld Quantity : "<<cur->quantity<<endl;

		cout<<endl<<endl;
		cout<<"Enter new ID:"<<endl;
		cin>>nid;
		cur->ID=nid;
		cout<<"Enter new Name:"<<endl;
		cin>>pName;
		cur->fName=pName;
		cout<<"Enter new Price:"<<endl;
		cin>>pre;
		cur->fPrice=pre;
		cout<<"Enter new Quantity:"<<endl;
		cin>>nq;
		cur->quantity=nq;
	}

	    else
    {
		cout<<id<<" is not found!\n\n";
	}
	}
}

//////////////////////////////To display all of the products

int display()
{
		system("cls");
		int c=0;             //   c for count products
		struct node *p=head;
		cout<<"Existing products are:\n";
		cout<<"ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
		cout<<"=================================================================|\n";
		while(p!=NULL)
		{
			cout<<p->ID<<"\t\t"<<p->fName<<"\t\t\t"<<p->fPrice<<"\t\t\t"<<check(p->quantity)<<"\n"; //    call   check func and pass quantity
			p=p->next;
			c=c+1;
		}
		cout<<"\nTotal products in our store is : "<<c<<"\n\n\n";
		return c;
		
}
////////////////////////////////////////////////////////////////////////////////////////
	    string check(int quant)

	{              //Check function
	    int a = quant;
       stringstream ss;
       ss << a;
       string quantity = ss.str();

	    	if(quant<=0)
	    	return "Out of stock!";
	    	else
	    	return quantity;
		}

///////////////////////////////////////////////////////////////////////
	void buy()
	{
        system("cls");
        display();
		string products[20];	//To display sold items
		int pay=0,no,c=0,price,id,i=1; //c is cart

        if(head==NULL)
        {
	    	cout<<"\nThere is no items to buy. Kindly add to cart! \n\n";
        }
	    else
        {
			cout<<"\nHow many items you wannt to buy:"<<endl;
			cin>>no; 
        	int count=display();           //To store no of nodes in cart
			while (i<=no)
        	{
				struct node *cur=head;
            	int quant,cho;   a:           //   quant   for quantity and cho is for choice
            	cout<<"\nEnter ID of the product that you want to buy: "<<endl;
            	int id,pos=0;
            	cin>>id;
            	if(id==-1){system("cls"); return;	}
	        	pos=search(id);
	        	if(pos<=count)
        		{
	                //     item is available in store
		 			while(cur->ID!=id)
        			{
						cur=cur->next;
		 			}
           			cout<<"Enter the Quantity of the item that you want:";
	       			cin>>quant;
	       			if(cur->quantity<quant)
           			{
               			cout<<"\n\n\t\t\t----The Quantity You Entered is not available---"<<endl;
               			goto a;
               		}
          			products[c]=cur->fName;   //Names of the product that you want to buy in array form 
		   			c++;   
		   	        
					pay=pay+(cur->fPrice*quant);         //To calculate Bill
	       			cur->quantity=cur->quantity-quant;           //To modify quantity
	       			i++;
				}
	    		else
        		{    
             
					cout<<"\n------This item is not available in our store at this time :(-------\n\n";
		    	}	
			}
        string customer;
        cout<<"\n\t\t Enter Your Name :"; 
		cin>>customer;
        enqueue(customer);
	    system("cls");
        cout<<"\n\n\n\nItems Purchased are : ";
        for(int i=0;i<no;i++)	//To display the purchased items
      {              
        cout<<products[i]<<"  ";
       }
        price=pay*(0.90);           //    with 10% discount
	    cout<<"\nOriginal price : "<<pay;
        cout<<"\nAfter 10% discount: "<<price<<"\nThank you for shopping with us! :D \n\n";

         

         
          }
            }


//////Administrator Portal

void administrator()
{
	system("cls");
	int ch;													//ch is for choice
	
	do					//Providing choices for the admin
	{
		cout<<"\t\t---------------------------------------------"<<endl;
		cout<<"\t\t|		Administrator Portal      |"<<endl;
		cout<<"\t\t---------------------------------------------"<<endl;
		
		cout<<"\t\t     Enter 1 to Insert New Product    "<<endl;
		cout<<"\t\t     Enter 2 to Display All Products   "<<endl;
		cout<<"\t\t     Enter 3 for Modify Existing Product"<<endl;
		cout<<"\t\t     Enter 4 for Delete A Product"<<endl;
		cout<<"\t\t     Enter 5 for Customers List "<<endl;
		cout<<"\t\t     Enter 6 for Dequeue Customer"<<endl;
		//cout<<"\t\t     Enter 7 for Generate Hash"<<endl;
		cout<<"\t\t     Enter 0 for Main Menu"<<endl;
		
		cout<<"\nEnter Your Choice: "<<endl;
		cin>>ch;

		switch(ch)
		{
			case 1:
				beg();
				break;
			case 2:
				system("cls");
				display();
				break;
			case 3:
				modify();
				break;
			case 4:
				delPro();
				break;
			case 5:
				system("cls");
				cout<<"\t|------------Customer Names List------------|"<<endl;			
				displayQueue();
				break;
			case 6:
				system("cls");	
				cout<<"\t|------------Customer Names List------------|"<<endl;			
				dequeue();
				displayQueue();
				break;
			/*case 7:
				int x, mod;
				cout<<"\nEnter the element to generate the hash: "<<endl;
				cin>>x;
				cout<<"\nOut of Total Number: "<<endl;
				cin>>mod;
				cout<<"\nHash of "<<x<<" is: "<<hash(x,mod)<<endl;
				break; */
			default:
				system("cls");		
		}
	}
	while(ch!=0);
}

/////Main Function or Driver's Code

int main()
{
	for(int i=0;i<=51;i++)
    {
     	push(i);
	}
	
	gotoxy(17,5);
	cout<<"--------------------------------------------------"<<endl;
	gotoxy(17,7);
	cout<<"|            Shopping Club System                 |"<<endl;
	gotoxy(17,9);
	cout<<"--------------------------------------------------"<<endl;
   	gotoxy(17,11);
   	cout<<"|Project Implemented by: Ishika Aggarwal |\n"<<endl;
   	gotoxy(17,13);
   	cout<<"Registration No: 11904047"<<endl;
    
    system("pause");
	system("cls");
	
	int ch;
	while(ch!=3)		//Choice for main message
	{

    cout<<"\n\t\t|========Main Menu========|";
      cout<<"\n\n";
	cout<<"\t\t 1. Administrator\n";
	cout<<"\t\t 2. Customer\n";
	cout<<"\t\t 3. Exit\n";

	cout<<"\nEnter Your choice: ";
	cin>>ch;
	switch(ch)
		{
			case 1:
				administrator();
				break;
			case 2:
				cout<<endl<<endl;
				bpop();
				system("pause");
	    		buy();
	    		break;
	    	case 3:
    			cout<<"\n\n\t\t\t\t\tHappy Shopping! Please Visit Us Again! :D \t\t\t\t";
    			break;
		}
	}
	return 0;	
}

