#include<iostream>
#include<string>
#include<process.h>
#include<ctype.h>
#include<conio.h>
using namespace std;

//class having the record of customer
class bill{
     private:
     int choice;
     long unsigned int tel_no;
     long unsigned int con_no;
     char name[60];
     char add[300];
     char city[40];
     long unsigned int op_rdg;
     long unsigned int cl_rdg;
     long unsigned int met_calls;
     long unsigned int free_calls;
     long unsigned int charge_calls;
     float met_charge;
     float rent;
     float debits;
     float tax;
     float credits;
     float gross_amt;
     float surcharge;
     long unsigned int net_amt_bef;
     long unsigned int net_amt_aft;
    public:
      void menu();
      void admin();
      void customer();
      void add();
      void showdata();
   };
   void bill::menu(){
      p:
      system("cls");
      int choice;
      cout<<"\n\n\t\tControl Panel";
      cout<<"\n\n 1.Admin";
      cout<<"\n 2.Customer";
      cout<<"\n 3.Exit";
      cout<<"\n\n Enter your Choice";
      cin>>choice;
      switch(choice)
      {
         case 1:
            admin();
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
      cout<<"\n 4. Show record";
      cout<<"\n 6: Go Back";
      cout<<"\n\n Enter your Choice";
      cin>>choice;
      switch(choice)
      {
         case 1:
            add();
            break;
         case 2:
            break;
         case 3:
            break;
         case 4:
            break;
         case 5:
            break;
         case 6:
            menu();  
         default:
            cout<<"\n\n Invalid value..please try again";
      }
      getch();
      goto p;
   }
   void bill::customer()// Customer function of bill class 
   {
      system ("cls");
      cout<<"\n\n\t\tCustomer Panel";
      cout<<"\n\n 1. Total "
   }
   void main(){
      bill b;
      b.menu();
   }
   
  


