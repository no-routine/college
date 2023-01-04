#include<iostream>
#include<string>
#include<process.h>
#include<ctype.h>

using namespace std;

//class having the record of customer
class bill{
     private:
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
      void getdata();
      void showdata();
   };
   void bill::menu(){
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
            break;
         case 2:
            customer();
            break;
         case 3:
            exit(0);
         default:
            cout<<"\n\n Invalid value..please try again";
      }


   }  
   void main(){
      bill b;
      b.menu();
   }
   
  


