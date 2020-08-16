#include <iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>
#include<sstream>
#include<ctime>
using namespace std;
int count=0;
class car_rental{
	struct car{
		char id[10], name[20],seats[10],price[10],availability[10];
	};
	public: void add();
	        void search();
		    void booking1();
			void unpack();
			void booking();

};
class user
{
	struct customer{
		char name[20],address[100],seats[10],driver[3];
		char phone[10];
	};
	public: void login();

};
class admin1{
	struct admin{
		char name[10];
		char password[10];
	};
	public: void authenticity();
};
void car_rental :: add()
{
	char buffer[100],temp[50],id[10],temp1[50],name[20],name2[20];
	int pos1 , flag=0;
	car c;
	fstream out;
	out.open("index.txt",ios::in |ios ::out|ios::app);
	cout<<"Enter Id \n";
	cin>>c.id;
	cout<<"Enter CAR Name \n"<<endl;
	cin>>c.name;
	cout<<"Enter Seats \n"<<endl;
	cin>>c.seats;
	cout<<"Enter price(per km) \n"<<endl;
	cin>>c.price;
	cout<<"Enter Availability(# of available cars) \n"<<endl;
	cin>>c.availability;
	while(1)
	{
	   out.getline(temp,50,'$');
	   if(out.eof())
	   break;
	   sscanf(temp,"%[^|]|%[^|]|%d|$",id , name ,&pos1);
	   if(strcmp(c.id,id)==0)
	   {
	   	flag=1;

	   	break;

	   }

	}
	out.close();
	if(flag==1)
	cout<<"\n primary key constraint violation, record not inserted\n";
	else
	{
		fstream out1,out;
    out1.open("cardetails.txt",ios::out|ios::app);
    out.open("index.txt",ios::out|ios::app);
    out1.seekp(0,ios::end);
    long pos=out1.tellp();
    sprintf(buffer,"%s|%s|%s|%s|%s|$",c.id,c.name,c.seats,c.price,c.availability);
    out1<<buffer;
    sprintf(temp1,"%s|%s|%ld|$",c.id,c.name,pos);
    out<<temp1;

    out1.close(); out.close();
  }
}
void car_rental::unpack(){
	car c;
	int n=0;
	char buffer[100],temp[50];
	fstream ifile1,ifile2;
	ifile1.open("cardetails.txt",ios::in);
	ifile2.open("index.txt",ios::in);
	cout<<"id car name  seats price "<<endl;
	while(n<count){

	ifile1.getline(buffer,100,'$');
	sscanf(buffer,"%[^|]|%[^|]|%[^|]|%[^|]|%[^$]",c.id,c.name,c.seats,c.price,temp);


	cout<<c.id<<"	"<<c.name<<"	 "<<c.seats<<"	 "<<c.price<<"	 "<<endl;
	n++;

	}
	ifile1.close();
	ifile2.close();
}

void car_rental::search()
{int n=0;
  char buffer[100],temp[50],name[20],id[10],name1[20];
  int pos,flag=0; car c;
  cout<<"\nEnter Name to be searched: \n\t";
  cin>>name;
  fstream in2,in1;
  car_rental cr;
  in2.open("index.txt",ios::in);
  in1.open("cardetails.txt",ios::in);
  while(n<count)
  {
    in2.getline(temp,50,'$');
    if(in2.eof())
      break;
    sscanf(temp,"%[^|]|%[^|]|%d|$",id,name1,&pos);
    in1.getline(buffer,100,'$');
    sscanf(buffer,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^$]",c.id,c.name,c.seats,c.price,c.availability,temp);
    if(strcmp(name,name1)==0)
    {
      flag=1;
      	cout<<"id name    seats price availability"<<endl;
      cout<<c.id<<"  "<<c.name<<"    "<<c.seats<<"     "<<c.price<<"   "<<c.availability;
    }
    n++;
  }
  if(flag==0)
  cout<<"\ncar does not exist";
  in1.close();
  in2.close();
}
void user :: login(){
	customer cr;
	user u;
	int flag90=0;
	char buffer[100],temp[50],req[3],name2[20],phone1[10],phone2[10],phone3[10];
	int pos1, flag=0;
	int phone[10];
	fstream ofile,ofile1;
	cout<<"enter the user details\n"<<endl;
		cout<<"\nenter name\n";
		cin>>cr.name;

//cin>>name2;
//for(int i=0;name2[i];i++)
//{
//	if((!isalpha(name2[i])))
//	{
//		cout<<" re enter name:";
//		cin.get();
//		cin.getline(name2,20);
//		i=0;
//	}
//
//}
//for(int j=0;name2[j];j++)
//cr.name[j]=name2[j];
//
int count;
	cout<<"\nenter the area of residence\n";
	cin>>cr.address;
	     cout<<"\nenter the phone number\n";
     cin>>phone1;
   count=1;
    int n=strlen(phone1);

    for(int x=0; x<10; x++)
	{
    	if(isalpha(phone1[x]))
		{
    		cout<<"\nenter numbers\n";
    		cin>>phone2;
    		count=2;
    		int gg =strlen(phone2);
    		n=gg;
    		break;
    		}
	}


     if(n!=10 )
      {
		cout<<"\nenter 10 digit phone number\n";
		cin>>phone3;
		 int d=strlen(phone3);
		 count=3;
	      n=d;

	  }


	 if(n==10){

	 for(int z=0; z<10; z++)
	 {
	 	if(count==1)
	 	{
	 		if(isdigit(phone1[z]))
				 flag90=1;
		 }
		 if(count==2)
		 {
		 if(isdigit(phone2[z]))
				 flag90=1;
		 }
		  if(count==3)
		 {
		 if(isdigit(phone3[z]))
				 flag90=1;
		 }

	}
}
if(flag90==1)
{
	if(count==1)
	 	{
	 			for(int j=0; j<10; j++)
				cr.phone[j]=phone1[j];
		 }
		 if(count==2)
		 {
		 	for(int j=0; j<10; j++)
				cr.phone[j]=phone2[j];
		 }
		  if(count==3)
		 {
		 	for(int j=0; j<10; j++)
				cr.phone[j]=phone3[j];
		 }
}





	 ofile.open("index1.txt",ios::out|ios::app);
	ofile1.open("user1.txt",ios::out|ios::app);
	ofile1.seekp(0,ios::end);
    long pos=ofile1.tellp();
	sprintf(buffer,"%s|%s|%s|$",cr.name,cr.address,cr.phone);
	sprintf(temp,"%s|%s|%ld|$",cr.name,cr.phone,pos);
	ofile<<temp;
	ofile1<<buffer;
	ofile.close();
	ofile1.close();
}

void admin1::authenticity()
{
fstream ifile;
  	char name[10],buffer[100],temp[100],password[10];
  	int n=0,flag=0,ch;
  	car_rental cr;
  	admin a;
  	ifile.open("admin.txt",ios::in);
  	cout<<"\nenter name\n";
  	cin>>name;
  	cout<<"\nenter password\n";
  	cin>>password;
  	 while(n<=4)
  {
    ifile.getline(buffer,100,'$');
    sscanf(buffer,"%[^|]|%[^|]|%[^$]",a.name,a.password,temp);

    if(strcmp(name,a.name)== 0 && strcmp(password,a.password)==0)
    {
      flag=1;

      	for(;;)
         {
    cout<<"\n enter 1:add 2:exit \n"<<endl;

    cin>>ch;
    switch(ch)
    {
      case 1: cr.add(); break;

      default: exit(0);
    }
  }
    }
    n++;
  }

  	if(flag==0)
  		cout<<"\ninvalid username or password\n";
ifile.close();

}

void car_rental::booking1()
{
    car c;

	char name1[20] , id[10];
	int pos;
	int f=0;
	int n=0 , date1,month1,year1;
	int amount=0;
	string ch;
	char name[20],number[20],buffer[100],temp[100];
	char no,yes,YES,NO,No,Yes,Y,N;
	int ndays,month,date,year;
	cout<<"\nselect car\n";
	cin>>name;
	cout<<"\nyou want assistance of driver?\n";
	cin>>ch;
	cout<<"\nenter the starting date of the trip\n";

	cout<<"\nenter date\n";
	cin>>date1;
	int mn=5;
	if(date1<=0 || date1>31 )
	{
		cout<<"\nenter valid date\n";
		exit(0);
	}
	cout<<"\nenter month\n";
	cin>>month1;
	if(month1<5){
		cout<<"\nenter proper month\n";
		exit(0);
	}
	month=month1;

	cout<<"\nenter year\n";
	cin>>year1;
	if(year1==2020)
	year=year1;
	else
	exit(0);
	if(date1<29 && month1==5 && year1==2020)
	{
		printf("enter valid date");
		exit(0);
	}
	cout<<"\nnumber of days\n";
	cin>>ndays;
	fstream ifile1,ifile2;
	ifile1.open("cardetails.txt",ios::in);
	ifile2.open("index.txt",ios::in);
	fstream ofile;
	ofile.open("cardetails2.txt",ios::out);
	if(ch=="no"||ch=="NO"||ch=="No"||ch=="N")
	{
                cout<<" No need of driver \n";
		while(n<count)
		{
		ifile2.getline(temp,50,'$');
    		if(ifile2.eof())
      		break;
    		sscanf(temp,"%[^|]|%[^|]|%d|$",id,name1,&pos);
    		ifile1.getline(buffer,100,'$');
    		sscanf(buffer,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^$]",c.id,c.name,c.seats,c.price,c.availability,temp);
    		if(strcmp(name,name1)==0)
    			{	f=1;
    				int r=atoi(c.availability);
			    	if(r>0)
					{

			    		cout<<"\nenter your name and license number\n";
			    		cin>>name>>number;

					cout<<"\nyour car is booked\n"<<endl;
					int amt=atoi(c.price);
					int m=atoi(c.availability);
					m--;
					stringstream s2;
					s2<<m;
					string str2=s2.str();
					strcpy(c.availability,str2.c_str());
					amount=amount+amt*ndays;
					cout<<"\namount to be paid: \n\t"<<amount;
					}
					else
					cout<<"\ncar is not available\n";
				}

			sprintf(buffer,"%s|%s|%s|%s|%s|$",c.id,c.name,c.seats,c.price,c.availability);
			ofile<<buffer;
			n++;
		}
		if(f==0)
				cout<<"\ncar not found . pls select the car from the list\n";
		ofile.close();
		ifile1.close();
		ifile2.close();
		remove("cardetails.txt");
		std::rename("cardetails2.txt","cardetails.txt");
	}
	if(ch=="yes"||ch=="YES"||ch=="Yes"||ch=="Y")
	{
	        cout<<" Driver Needed \n";
		while(n<count)
		{
			ifile2.getline(temp,50,'$');
    		if(ifile2.eof())
      		break;
    		sscanf(temp,"%[^|]|%[^|]|%d|$",id,name1,&pos);
    		ifile1.getline(buffer,100,'$');
    		sscanf(buffer,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^$]",c.id,c.name,c.seats,c.price,c.availability,temp);
    		    		
    		 if(strcmp(name,name1)==0)
    			{f=1;
    				int r=atoi(c.availability);
			    	if(r>0)
					{

					cout<<"\nyour car is booked\n"<<endl;
					int amt=atoi(c.price);
					int m=atoi(c.availability);
					m--;
					stringstream s2;
					s2<<m;
					string str2=s2.str();
					strcpy(c.availability,str2.c_str());
					amount=amount+amt*ndays+700*ndays;
					cout<<"\namount to be paid: \n"<<amount;
					}
					else
					cout<<"\ncar is not available\n";
				}

			sprintf(buffer,"%s|%s|%s|%s|%s|$",c.id,c.name,c.seats,c.price,c.availability);
			ofile<<buffer;
			n++;
		}
		if(f==0)
				cout<<"\ncar not found . pls select the car from the list\n";
		ofile.close();
		ifile1.close();
		ifile2.close();
		remove("cardetails.txt");
		std::rename("cardetails2.txt","cardetails.txt");
 }
}

int main()
{
  char buffer[100];
  car_rental cr;

  //cr.add();
  int kb,ch;
  user u;

  admin1 a;
  fstream ifile;
  ifile.open("cardetails.txt",ios::in);
  //cr.add();
   while(!ifile.eof()){
  	ifile.getline(buffer,100,'$');
  	count++;
  }
  count--;
  cout<<"\n\n\t\tWELCOME TO CAR RENTAL SYSTEM\t\t\n\n";

  cout<<"\n\n\t Enter 1 for user login and  2 for admin login\t\n\n";
  cin>>kb;


  ifile.close();

  switch(kb){
  	case 1:{	u.login();
	  for(;;)
	  {
   		 cout<<"\n  \n 1:Search  2:list of cars  3.booking 4:Exit\n\t "<<endl;

    	cin>>ch;

    	switch(ch)
    		{
      			case 1: cr.search(); break;
      			case 2: cr.unpack();break;
      			case 3: cr.booking1();break;
      			default: exit(0);
    		}
  		}
	}
  break;
case 2:{
  	admin1 a;
  	a.authenticity();
  	}
  break;

  }
   return 0;
}



