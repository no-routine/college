#include<iostream>
#include<string>
#include<process.h>
#include<ctype.h>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
//class having the record of customer
class bill{
     private:
    int customer_no; 
     int choice;
     int tel_no;
     string name;
     string addr;
     string city;
     int net_calls;
     int free_calls;
     int charge_calls;
     float net_charge;
     float tax;
     float gross_amt;
     long unsigned int net_amt_bef;
     long unsigned int net_amt_aft;
     fstream phonerecout;
    public:
      void menu();
      void admin();
      void customer();
      void add();
      void search();
      void showdata();
      void calculate();
   };
   
   void bill::calculate(){//function to calculate charge calls, net charge and gross amt
   	
   	charge_calls = net_calls - free_calls;
   	net_charge = charge_calls*2;
   	tax = net_charge*0.13;
   	gross_amt = net_charge + tax;
   }
   
   
   void bill::menu(){//menu to allow user to chose between admin or customer
      p:
      system("cls");
      int choice;
      char ch;
      string pass;
      cout<<"\n\n\t\tControl Panel";
      cout<<"\n\n 1.Admin";
      cout<<"\n 2.Customer";
      cout<<"\n 3.Exit";
      cout<<"\n\n Enter your Choice:";
      cin>>choice;
      switch(choice)
      {
         case 1:
            system("cls");       
            cout<<"\n\n\t\tLogin system";
            cout<<"\n\n Password:";
            for (int i=1;i<=6;i++){//create password for admin login 
               ch=getch();
               pass += ch;
               cout<<"*";
            }
            if(pass=="qwerty")
            {
               admin();
            }
            else
            {
               cout<<"\nInvalid Password"<<endl;
            }
            break;
         case 2:
            customer();
         case 3:
            exit(0);
         default:
            cout<<"\n\n Invalid value..please try again";
      }
      getch();
      goto p;
   }  
   void bill::admin()//admin function of bill
   {
      p:
      system("cls");
      cout<<"\n\n\t\tAdmin Panel";
      cout<<"\n\n 1.Add New customer";
      cout<<"\n 2. Search info/record about customer";
      cout<<"\n 3. Edit information/record";
      cout<<"\n 4. Delete record";
      cout<<"\n 5: Go Back";
      cout<<"\n\n Enter your Choice:";
      cin>>choice;
      switch(choice)
      {
         case 1:
            add();
            break;
         case 2:
         	search()
            break;
         case 3:
            break;
         case 4:
            break;
         case 5:
            menu();  
         default:
            cout<<"\n\n Invalid value..please try again";
      }
      getch();
      goto p;
   }
   void bill::customer()// Customer function of bill class 
   {
      p:
      system ("cls");
      cout<<"\n\n\t\tCustomer Panel";
      cout<<"\n\n 1. Total Charge";
      cout<<"\n 2. Go Back";
      cout<<"\n\n Enter your Choice:";
      cin>>choice;
      switch(choice)
      {
         case 1:
            break;
         case 2:
            menu();
         default:
            cout<<"\n\n Invalid value..please try again";
      }
      getch();
      goto p;
   }  
   void bill::add()//function for adding new customer record
   {
   	phonerecout.open("record.txt",ios::app);
      system("cls");
      srand(time(0));
      cout<<"\n\n\t\t Add new record"<<endl;
      customer_no = 1000 + (rand() % 10000);
      cout<<"Customer number: "<<customer_no;
      cout<<"\n Telephone no:  ";
      cin>>tel_no;
      cout<<"Name: ";
      getline(cin>>ws,name);
      cout<<"Address:" ;
      getline(cin,addr);
      cout<<"City: ";
      getline(cin,city);
      cout<<"Total calls made: ";
      cin>>net_calls;
      cout<<"Free calls allowed: ";
      cin>>free_calls;
      calculate();
      cout<<"Charged calls: "<<charge_calls<<endl;
      cout<<"Net Charge: "<<net_charge<<endl;
      cout<<"Tax to be paid:"<<tax<<endl;
      cout<<"gross amount:"<<gross_amt<<endl;
      phonerecout<<customer_no<<" "<<tel_no<<" "<<name<<" "<<addr<<" "<<city<<" "<<net_calls<<" "<<free_calls<<" "<<charge_calls<<" "<<net_charge<<" "<<tax<<" "<<gross_amt<<endl;
      phonerecout.close();
	  exit(0);
   }
   void bill::search()
   {
   	phonerecout.open("record.txt",ios::in,ios::binary);
	   if(!phonerecout){
	   	cout<<"\nFile not found";
	   }
	   else{
	   	phonerecout.read()
	   }
   }
   int main(){
      bill b;
      b.menu();
      return 0;
   }
   
