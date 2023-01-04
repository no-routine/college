#include<iostream>
#include<string>
#include<process.h>
#include<ctype.h>
#include<dos.h>
#include<direct.h>
#include<fstream>
#include<windows.h>
using namespace std;

//class having the record of customer
class consumer€
   {
     public:
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
      void getdata();
      void showdata();
   };
void consumer::getdata(){
    cout <<"enter "
} 
  


