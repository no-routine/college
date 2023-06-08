#include<iostream>
#include<string>
#include<process.h>
#include<ctype.h>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<iomanip>
using namespace std;
//class having the record of customer
class bill{
     private:
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
     fstream file;
    public:
      void menu();
      void admin();
      void customer();
      void add();
      void search();
      void edit();
      void dele();
      void show();
      void calculate();
      void infor();
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
      cout<<"\n 5. Show record";
      cout<<"\n 6: Go Back";
      cout<<"\n\n Enter your Choice:";
      cin>>choice;
      switch(choice)
      {
         case 1:
            add();
            break;
         case 2:
         	search();
            break;
         case 3:
         	edit();
            break;
         case 4:
         	dele();
            break;
         case 5:
            show();
			break; 
		 case 6:
		 	menu(); 
         default:
            cout<<"\n\n Invalid value..please try again";
            exit(0);
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
         	infor();
            break;
         case 2:
            menu();
         default:
            cout<<"\n\n Invalid value..please try again";
            exit(0);
      }
      getch();
      goto p;
   }  
   void bill::add()//function for adding new customer record
   { 
      p:
	  system("cls");
      fstream file;
      int tel,ne,f,charge, found=0;
      string n,a,c;
      float t, gross, net;
      cout<<"\n\n\t\t Add new record"<<endl;
      cout<<"\n Telephone no: ";
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
      file.open("data.txt",ios::in);
      if(!file)
      {
      	file.open("data.txt",ios::app|ios::out);
      	file<<" "<<tel_no<<" "<<name<<" "<<addr<<" "<<city<<" "<<net_calls<<" "<<free_calls<<" "<<charge_calls<<" "<<net_charge<<" "<<tax<<" "<<gross_amt<<"\n";
		file.close();   
	  }
	  else
	  {
	  	file>>tel>>n>>a>>c>>ne>>f>>charge>>net>>t>>gross;
	  	while(!file.eof())
	  	{
	  		if (tel == tel_no)
	  		{
	  			found=found+1;
			  }
			  file>>tel>>n>>a>>c>>ne>>f>>charge>>net>>t>>gross;
		  }
		  file.close();
		  if(found == 1){
		  	cout<<"Telephone no already exists."<<endl;
		  	goto p;
		  }
		  else
		  {
		  	file.open("data.txt",ios::app|ios::out);
      		file<<" "<<tel_no<<" "<<name<<" "<<addr<<" "<<city<<" "<<net_calls<<" "<<free_calls<<" "<<charge_calls<<" "<<net_charge<<" "<<tax<<" "<<gross_amt<<"\n";
			file.close();   
		  }
	  }
   }
   void bill::search() //search function of bill class
   {
   	system("cls");
   	fstream file;
   	int t_n, found=0;
	cout<<"\n\n\t\t\Search record";
   	cout<<"\n\n Enter the telephone no to search: ";
   	cin>>t_n;
   	file.open("data.txt",ios::in);
   	if(!file)
   	{
   		cout<<"\n\n File doesn't exist..";
	   }
	   else
	   {
	   	file>>tel_no>>name>>addr>>city>>net_calls>>free_calls>>charge_calls>>net_charge>>tax>>gross_amt;
	   	while(!file.eof())
	   	{
	   		if(t_n == tel_no)
	   		{
	   			system("cls");
	   			cout<<"\n\n\t\tSearch record";
	   			cout<<"\n\n Telephone no: "<<tel_no;
	   			cout<<"\n\n Name: "<<name;
	   			cout<<"\n\n Address: "<<addr;
	   			cout<<"\n\n City: "<<city;
	   			cout<<"\n\n Total calls made: "<<net_calls;
	   			cout<<"\n\n Free calls: "<<free_calls;
	   			cout<<"\n\n Charge Calls: "<<charge_calls;
	   			cout<<"\n\n Net Charge: "<<net_charge;
	   			cout<<"\n\n Tax amount: "<<tax;
	   			cout<<"\n\n Total amount: "<<gross_amt;
	   			found++;
			   }
			   file>>tel_no>>name>>addr>>city>>net_calls>>free_calls>>charge_calls>>net_charge>>tax>>gross_amt;
			   
		   }
		   file.close();
		   if (found == 0){
		   	cout<<"\n\n Record not found";
		   }
	   }	
   }
   void bill::edit()//edit function of bill class
   {
   	system("cls");
   	fstream file,file1;
   	int t_n, found=0,tel,ne,f,charge;
    string n,a,c;
    float t, gross, net;
	cout<<"\n\n\t\t\  Edit record";
   	cout<<"\n\n Enter the telephone no to edit: ";
   	cin>>t_n;
   	file.open("data.txt",ios::in);
   	if(!file)
   	{
   		cout<<"\n\n File opening error..";
	   }
	   else
	   {
	   	file1.open("data1.txt",ios::app|ios::out);
	   	file>>tel_no>>name>>addr>>city>>net_calls>>free_calls>>charge_calls>>net_charge>>tax>>gross_amt;
	   	while(!file.eof())
	   	{
	   		if(t_n == tel_no)
	   		{
	   			cout<<"\n\n New Telephone no: ";
	   			cin>>tel;
	   			cout<<"\n\n New Name: ";
				getline(cin>>ws,n);
	   			cout<<"\n\n New Address: ";
				cin>>a;
	   			cout<<"\n\n New City Name: ";
				cin>>c;
	   			cout<<"\n\n Total calls made: ";
				cin>>ne;
	   			cout<<"\n\n Free calls: ";
				cin>>f;
			   	charge = ne - f;
   				net = charge*2;
   				t = net*0.13;
   				gross = net + t;
	   			cout<<"\n\n Charge Calls: "<<charge;
	   			cout<<"\n\n Net Charge: "<<net;
	   			cout<<"\n\n Tax amount: "<<t;
	   			cout<<"\n\n Total amount: "<<gross;
	   			file1<<" "<<tel<<" "<<n<<" "<<a<<" "<<c<<" "<<ne<<" "<<f<<" "<<charge<<" "<<net<<" "<<t<<" "<<gross<<endl;
	   			cout<<"\n\nRecord edited successfully";
				found++;
			   }
			   else{
			   	file1<<" "<<tel_no<<" "<<name<<" "<<addr<<" "<<city<<" "<<net_calls<<" "<<free_calls<<" "<<charge_calls<<" "<<net_charge<<" "<<tax<<" "<<gross_amt<<"\n";
			   }
			   file>>tel_no>>name>>addr>>city>>net_calls>>free_calls>>charge_calls>>net_charge>>tax>>gross_amt;
		   }
		   file.close();
		   file1.close();
		   remove("data.txt");
		   rename("data1.txt","data.txt");
		   if (found == 0){
		   	cout<<"\n\n Record not found";
		   }
		}   
	}	

   	void bill::dele()//delete function of bill class
   	{
   	system("cls");
   	fstream file,file1;
   	int t_n, found=0;
	cout<<"\n\n\t\t\Delete record";
   	cout<<"\n\n Enter the telephone no to delete: ";
   	cin>>t_n;
   	file.open("data.txt",ios::in);
   	if(!file)
   	{
   		cout<<"\n\n File opening error..";
	   }
	   else
	   {
	   	file1.open("data1.txt",ios::app|ios::out);
	   	file>>tel_no>>name>>addr>>city>>net_calls>>free_calls>>charge_calls>>net_charge>>tax>>gross_amt;
	   	while(!file.eof())
	   	{
	   		if(t_n == tel_no){
	   			cout<<"\n\n Product deleted sucessfully..";
	   			found++;
			   }
			else{
				file1<<" "<<tel_no<<" "<<name<<" "<<addr<<" "<<city<<" "<<net_calls<<" "<<free_calls<<" "<<charge_calls<<" "<<net_charge<<" "<<tax<<" "<<gross_amt<<"\n";
			}   	
			file>>tel_no>>name>>addr>>city>>net_calls>>free_calls>>charge_calls>>net_charge>>tax>>gross_amt;
			}
		file.close();
		file1.close();
		remove("data.txt");
		rename("data1.txt","data.txt");
		if (found == 0){
		cout<<"\n\n Record not found";
 		}
	}
}
void bill::show()//show function for bill class
{
	system("cls");
   	fstream file;
	cout<<"\n\n\t\t\ All records";
   	file.open("data.txt",ios::in);
   	if(!file)
   	{
   		cout<<"\n\n File opening error..";
	   }
	else
   {
	   cout<<left<<setw(15)<< "\n\n Telephone no"<<right<<setw(10)<< "Name"<<setw(15) << "Address" <<setw(15)<< "City" <<setw(15)<<"Total Calls" <<setw(15)<< "Free calls" <<setw(15)<< "Charge calls" <<setw(15)<< "Net charge"<<setw(15)<<  "Tax amount" <<setw(15)<< "Gross amount";
	   file>>tel_no>>name>>addr>>city>>net_calls>>free_calls>>charge_calls>>net_charge>>tax>>gross_amt;
	   while(!file.eof())
	   {
	   	cout<<"\n\n"<<left<<setw(15)<<tel_no<<right<<setw(10)<<name<<setw(15) <<addr<<setw(15) <<city<<setw(15) <<net_calls<<setw(15) <<free_calls<<setw(15) <<charge_calls<<setw(15) <<net_charge<<setw(15) <<tax<<setw(15) <<gross_amt<<endl;
		file>>tel_no>>name>>addr>>city>>net_calls>>free_calls>>charge_calls>>net_charge>>tax>>gross_amt;
		   }	
	   }
	   file.close();
}
	void bill::infor()//bill generation 
	{
		system("cls");
		fstream file;
		int t_n, found=0;
		cout<<"\n\n\t\t\Bill";
		cout<<"\n\n Enter the telephone no : ";
		cin>>t_n;
   	file.open("data.txt",ios::in);
   	if(!file)
   	{
   		cout<<"\n\n File doesn't exist..";
	   }
	   else
	   {
	   	file>>tel_no>>name>>addr>>city>>net_calls>>free_calls>>charge_calls>>net_charge>>tax>>gross_amt;
	   	while(!file.eof())
	   	{
	   		if(t_n == tel_no)
	   		{
	   			system("cls");
	   			cout<<"\n\n\t\t Bill";
	   			cout<<"\n\n Telephone no: "<<tel_no;
	   			cout<<"\n\n Name: "<<name;
	   			cout<<"\n\n Address: "<<addr;
	   			cout<<"\n\n City: "<<city;
	   			cout<<"\n\n Total calls made: "<<net_calls;
	   			cout<<"\n\n Free calls: "<<free_calls;
	   			cout<<"\n\n Charge Calls: "<<charge_calls;
	   			cout<<"\n\n Net Charge: "<<net_charge;
	   			cout<<"\n\n Tax amount: "<<tax;
	   			cout<<"\n\n Total amount: "<<gross_amt;
	   			found++;
			   }
			   file>>tel_no>>name>>addr>>city>>net_calls>>free_calls>>charge_calls>>net_charge>>tax>>gross_amt;
			   
		   }
		   file.close();
		   if (found == 0){
		   	cout<<"\n\n Record not found";
		   }
	   }	
		}	
	
   int main(){
      bill b;
      b.menu();
	   cout<<"Fork this"<<endl;
      return 0;
   }
   
