#include <iostream>
#include <string>
#include <windows.h>
#include<vector>

using namespace std;
class Message
{
protected:
    string sender;
    string date;
    string content;
public:
    Message(string a, string b, string c)
    {
	   
	   sender=a;
	   date=b;
	   content=c;
    };
    Message()
    {
	   cout<<"Enter name of the sender :";
	   cin.ignore();
	   getline(cin,sender);
	   cout<<"Enter date of the message :";
	   //cin.ignore();
	   getline(cin,date);
	   cout<<"Enter the content of the message :";
	   //cin.ignore();
	   getline (cin, content);

    };
    virtual void output()
    {
	   cout<<"Message from "<<sender<<" on date: "<<date<<" with content : "<<content;
	   	   cout<<"\n_______________________________________________________________________________ \n";
    }
    virtual string searchspecial()
    {
	   return "";
    }
    string getsender()
    { return sender;
    }
    string getdate()
    { return date;
    }
    virtual string getsource()
    {
	   return "Message";
    }
    
};
class Computer : public Message
{
protected:
    string ip;
public:
    virtual string getip()
    { return ip;
    }
    virtual string getsource()
    {
	   return "Computer";
    }
    Computer(string a)
    {
	   ip=a;
    };
    Computer()
    {
	   cout<<"Enter ip of the computer from which was sent the message :";
	   //cin.ignore();
	   getline(cin,ip);;
    };
    virtual string searchspecial()
    {
	   return "";
    }
    Computer(string a, string b, string c, string d):Message(a,b,c)
    {
	   
	   ip=d;
    };
    virtual void output()
    {
	   cout<<"Message through a computer from "<<sender<<" with ip :" <<ip<<" on date: "<<date<<" with content : "<<content;
	   	   cout<<"\n_______________________________________________________________________________ \n";
    }
};
class Mail : public Computer
{
protected:
    string email;
public:
    virtual string getsource()
    {
	   return "Mail";
    }
    virtual string getemail()
    { return email;
    }
    Mail(string a)
    {
	   email=a;
    };
    virtual string searchspecial()
    {
	   return email;
    }
    Mail()
    {
	   cout<<"Enter the email of the sender :";
	   //cin.ignore();
	   getline(cin,email);
    };
     Mail(string a, string b, string c, string d, string e): Computer(a,b,c,d)
    {
	   email=e;
    };
    void output()
    {
	   cout<<"Message through e-mail from "<<sender<<" with ip :" <<ip<<" and e-mail : "<<email<< " on date: "<<date<<" with content : "<<content;
	   	   cout<<"\n_______________________________________________________________________________ \n";
    }
};
class Facebook : public Computer
{
protected:
    string nickname;
public:
    virtual string getsource()
    {
	   return "Facebook";
    }
    virtual string searchspecial()
    {
	   return nickname;
    }

    Facebook(string a)
    {
	   nickname=a;
    };
    Facebook()
    {
	   cout<<"Enter the nickname of the sender :";
	   //cin.ignore();
	   getline(cin,nickname);
    };
     Facebook(string a, string b, string c, string d, string e): Computer(a,b,c,d)
    {
	  
	   nickname=e;
    };
    void output()
    {
	   cout<<"Message through Facebook from "<<sender<<" with ip :"<<ip<< " and nickname : "<<nickname<< " on date: "<<date<<" with content : "<<content;
	   	   cout<<"\n_______________________________________________________________________________ \n";
    }
};
class Phone: public Message
{
protected:
    string brand;
public:
    virtual string getsource()
    {
	   return "Phone";
    }
    virtual string searchspecial()
    {
	   return "";
    }
    virtual string getbrand()
    { return brand;
    }
    Phone(string a)
    {
	   brand=a;
    };
    Phone()
    {
	   cout<<"Enter the brand of the phone from which was sent the message :";
	   //cin.ignore();
	   getline(cin,brand);
    };
     Phone(string a, string b, string c, string d) :Message(a,b,c)
    {
	   brand=d;
    };
    virtual void output()
    {
	   cout<<"Message through phone from "<<sender<<" with phone : "<<brand <<" on date: "<<date<<" with content : "<<content;
	   cout<<"\n_______________________________________________________________________________ \n";

    }
};
class SMS: public Phone
{
protected:
    string number;
public:
    virtual string getsource()
    {
	   return "SMS";
    }
    virtual string getnumber()
    { return number;
    }
    virtual string searchspecial()
    {
	   return number;
    }
    SMS(string a)
    {
	   number=a;
    };
    SMS()
    {
	   cout<<"Enter the mobile number of the sender :";
	   //cin.ignore();
	   getline(cin,number);
    };
    SMS(string a, string b, string c, string d, string e): Phone(a,b,c,d)
    {
	   number=e;
    };
    void output()
    {
	   cout<<"Message through SMS from "<<sender<<" with number : "<<number<<" with phone : "<<brand <<" on date: "<<date<<" with content : "<<content;
	   cout<<"\n_______________________________________________________________________________ \n";
    }
};
int main()

{	
     cout<<"L";
	Sleep(500);
	cout<<"O";
	Sleep(500);
	cout<<"A";
	Sleep(500);
	cout<<"D";
	Sleep(500);
	cout<<"I";
	Sleep(500);
	cout<<"N";
	Sleep(500);
	cout<<"G \n";
	Sleep(500);

    vector<Message*> warehouse;
	Message* temp;


	temp=new Computer("Hristo","12.12.12","Hello","100.18.192.1") ;
	warehouse.push_back(temp);
	temp=new Computer("Hristo","13.12.12","How  are you?","100.18.192.1");
	warehouse.push_back(temp);
	temp=new Computer("Martin","12.12.12","Are you free tonight","100.18.192.2");
	warehouse.push_back(temp);
	temp=new Computer("Martin","13.12.12","Are you going to Piano Bar","100.18.192.2");
	warehouse.push_back(temp);
	temp=new Facebook("Hristo","14.12.12","Good bye","100.18.192.1","freaknenov");
	warehouse.push_back(temp);
	temp=new Facebook("Martin","14.12.12","Watch this!","100.18.192.2","martoss");
	warehouse.push_back(temp);
	temp=new Facebook("Martin","15.12.12","Are you hungry?","100.18.192.2","martoss");
	warehouse.push_back(temp);
	temp=new Facebook("Hristo","16.12.12","Hell No","100.18.192.1","freaknenov");
	warehouse.push_back(temp);
	temp=new Mail("Hristo","16.12.12","Send me the photos","100.18.192.1","hnn100@aubg.bg");
	warehouse.push_back(temp);
	temp=new Mail("Hristo","17.12.12","See you in Underground","100.18.192.1","hnn100@aubg.bg");
	warehouse.push_back(temp);
	temp=new Mail("Martin","18.12.12","Can you get me one coke?","100.18.192.2","maa100@aubg.bg");
	warehouse.push_back(temp);
	temp=new Mail("Martin","19.12.12","Do you have the COS240 homework?","100.18.192.2","maa100@aubg.bg");
	warehouse.push_back(temp);
	temp=new Phone("Hristo","17.12.12","Call me back","Privileg");
	warehouse.push_back(temp);
	temp=new Phone("Hristo","18.12.12","Text me!","Privileg");
	warehouse.push_back(temp);
	temp=new Phone("Martin","19.12.12","Nope, Chuck Testa","Nokia");
	warehouse.push_back(temp);
	temp=new Phone("Martin","17.12.12","Megusta","Nokia");
	warehouse.push_back(temp);
	temp=new SMS("Hristo","18.12.12",":)","Privileg","0896232333");
	warehouse.push_back(temp);
	temp=new SMS("Hristo","19.12.12","Y U No Call me?","Privileg","0896232333");
	warehouse.push_back(temp);
	temp=new SMS("Martin","18.12.12","trololololo","Nokia","0896123456");
	warehouse.push_back(temp);
	temp=new SMS("Martin","25.12.12","Happy Christmas","Nokia","0896123456");
	warehouse.push_back(temp);



	int secondchoice;
	string select,b;

	string choice="a",prod="a";
	while(choice!="3"){
	cout<<"Enter type of activity: 1 for input \n"<<
	      "			2 for output \n "<<
		 "			3 for exiting the program\n";
	
	cin>>choice;

	if(choice=="1"){
				cout<<"What would you like to enter:	1 for Message from computer"<<
		 		 "							2 for Facebook message"<<
				 "								3 for Mail"<<
				 "					   				4 for Message from Phone"<<
				 "							5 for SMS \n"<<
				 "If you dont want to enter anything enter 'exit' \n";
				cin>>b;
				if(b!="exit"&&choice!="1"&&choice!="2"&&choice!="3"&&choice!="4"&&choice!="5") cout<<"Unrecognizes input. Try again \n";
				else 	{
					   if(b=="1")temp=new Computer();
					   if(b=="2")temp=new Facebook();
					   if(b=="3")temp=new Mail();
					   if(b=="4")temp=new Phone();
					   if(b=="5")temp=new SMS();
						  }
				warehouse.push_back(temp);
				}
	if( choice=="2"){  
				    cout<<"Enter type of search : 1 for search by Date \n"<<
						"		       2 for search by sender \n"<<
						"		       3 for search by source \n"<<
						"		       4 for search by number for SMS \n"<<
						"		       5 for search by nickname for Faceook \n"<<
						"		       6 for search by email for Mail \n";
				    cin>>secondchoice;
				    if(secondchoice==1){cout<<"Enter date ( for example '10.10.11') :";
								    cin.ignore();
								    getline(cin,select);
								    for(int i=0;i<warehouse.size();i++)
								    {   if(warehouse[i]->getdate()==select)
									   {
									   warehouse[i]->output();
									   cout<<endl;}
								    }cout<<endl;}
				    if(secondchoice==2){cout<<"Enter name of the sender :";
								    cin.ignore();
								    getline(cin,select);
								    for(int i=0;i<warehouse.size();i++)
								    {   if(warehouse[i]->getsender()==select)
									   {
									   warehouse[i]->output();
									   cout<<endl;}
								    }cout<<endl;}
				    if(secondchoice==3){cout<<"Enter type of source ( for example Mail, Facebook, Computer, SMS, Phone) :";
								    cin.ignore();
								    getline(cin,select);
								    for(int i=0;i<warehouse.size();i++)
								    {   if(warehouse[i]->getsource()==select)
									   {
									   warehouse[i]->output();
									   cout<<endl;}
								    }cout<<endl;}
				    if(secondchoice==4){cout<<"Enter number :";
								    cin.ignore();
								    getline(cin,select);
								    for(int i=0;i<warehouse.size();i++)
								    {   if(warehouse[i]->searchspecial()==select)
									   {
									   warehouse[i]->output();
									   cout<<endl;}
								    }cout<<endl;
				    }
				    if(secondchoice==5){cout<<"Enter nickname :";
								    cin.ignore();
								    getline(cin,select);
								    for(int i=0;i<warehouse.size();i++)
								    {   if(warehouse[i]->searchspecial()==select)
									   {
									   warehouse[i]->output();
									   cout<<endl;}
								    }cout<<endl;
				    }
				    if(secondchoice==6){cout<<"Enter email:";
								    cin.ignore();
								    getline(cin,select);
								    for(int i=0;i<warehouse.size();i++)
								    {   if(warehouse[i]->searchspecial()==select)
									   {
									   warehouse[i]->output();
									   cout<<endl;}
								    }cout<<endl;
				    }
				    if(secondchoice!=1&&secondchoice!=2&secondchoice!=3)cout<<"Wrong input. Restarting the program ! \n";

	
	}
	}
	system("PAUSE");
	return 0;
}