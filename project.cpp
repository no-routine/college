#include<iostream>
#include<string>
#include<process.h>
#include<ctype.h>
#include<conio.h>
#include<fstream>
using namespace std;

//class having the record of customer
class bill{
     private:
     int choice;
     int tel_no;
     char name[60];
     char addr[300];
     char city[40];
     int net_calls;
     int free_calls;
     int charge_calls;
     float net_charge;
     float tax;
     float gross_amt;
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
            for (int i=1;i<=6;i++){
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
      cout<<"\n 4. Show record";
      cout<<"\n 6: Go Back";
      cout<<"\n\n Enter your Choice:";
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
      system("cls");
      fstream file;
      cout<<"\n\n\t\t Add new record";
      cout<<"\n Telephone no:  "<<endl;
      cin>>tel_no;
      cout<<"Name:"<<endl;
      cin>>name;
      cout<<"Address:"<<endl;
      cin>>addr;
      cout<<"City:"<<endl;
      cin>>city;
      cout<<"Total calls made:"<<endl;
      cin>>net_calls;
      cout<<"Free calls allowed"<<endl;
      cin>>free_calls;
      cout<<"Tax to be paid:"<<endl;
      cin>>tax;
   }
   int main(){
      bill b;
      b.menu();
      return 0;
   }
   
  


