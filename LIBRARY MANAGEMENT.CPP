#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<iostream>	
using namespace std;
class book
{
	char bno[6];
	char bname[50];
	char aname[20];
    public:
	        void create_book()
        	{
	            cout<<"\nNEW BOOK ENTRY...\n";
		        cout<<"\nEnter The book no.";
		        cin>>bno;
		        cout<<"\n\nEnter The Name of The Book : ";
		        cin.ignore();
	        	gets(bname);
	        	cout<<"\n\nEnter The Author's Name : ";    
		        cin.ignore();
		        gets(aname);
		        cout<<"\n\n\nBook Created..";
        	}
	void show_book()
	{
		cout<<"\nBook no. : "<<bno;
		cout<<"\nBook Name : ";
		puts(bname);
		cout<<"Author Name : ";
		puts(aname);
	}
	void modify_book()
	{
		cout<<"\nBook no. : "<<bno;
		cout<<"\nModify Book Name : ";
		gets(bname);
		cout<<"\nModify Author's Name of Book : ";
		cin.ignore();
		gets(aname);
	}
	char* retbno()
	{
		return bno;
	}
  	void report()
	{   
    	cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;
	}
};         
class student
{
	char admno[6];
	char name[20];
	char stbno[6];
	int token;
    public:
        	void create_student()
        	{
	            system("cls");
	 	        cout<<"\nNEW STUDENT ENTRY...\n";
		        cout<<"\nEnter The admission no. : ";
		        cin.ignore();
		        cin>>admno;
	        	cout<<"\n\nEnter The Name of The Student :  ";
	        	cin.ignore();
		        gets(name);
		        token=0;
		        stbno[0]='\0';
		        cout<<"\n\nStudent Record Created...";
	        }
        	void show_student()
        	{
        		cout<<"\nAdmission no. : "<<admno;
	        	cout<<"\nStudent Name : ";
	        	puts(name);
	        	cout<<"\nNo. of Book issued : "<<token;
		        if(token==1)
		    	cout<<"\nBook No. : "<<stbno;
         	}
            void modify_student()
        	{
	        	cout<<"\nAdmission no. : "<<admno;
	        	cout<<"\nModify Student Name : ";
	        	cin.ignore();
	        	gets(name);
        	}
	        char* retadmno()
	        {
	        	return admno;
         	}
	char* retstbno()
	{
		return stbno;
	}
	int rettoken()
	{
		return token;
	}
	void addtoken()
	{
	    token=1;
	}
	void resettoken()
	{
	    token=0;
	}
	void getstbno(char t[])
	{
		strcpy(stbno,t);
	}
	void report()
	{
	    cout<<admno<<setw(30)<<name<<setw(30)<<token<<endl;
	}
};
class admin
{
	public:
		fstream file;
	    string name,check;
	    char detail[60];
         void add_admin()
        {
        	char temp,temp1;
	        char confirmpass[20];
            string username;
	        char password[20];
               system("cls");
            file.open("file.txt",ios::out|ios::app);
            cout<<"\nBefore creating account,read this : \n";
        	cout<<"\n\t\t*Username and Password should only contain digits(1-9) or alphabets(aA-zZ)\n\n";
         	cout<<"\tEnter the username to be registered : ";
            cin.ignore();
        	cin>>username; 
        	cout<<"\n\n\tCreate new password : ";
	        for(int i=0;;)
            {
                temp=getch();
		        putchar('*');
                if((temp>='a'&& temp<='z')||(temp>='A'&& temp<='Z')||(temp>='0'&& temp<='9'))
                {
                    password[i]=temp;
                    ++i;
                }
                if(temp=='\b'&&i>=1)
                {
                    cout<<"\b \b";
                    --i;
                }
                if(temp== '\r')
                {
                    password[i]='\0';
                    goto y;
                }
            }
y:          cout<<"\nPlease confirm your password by re-entering here : ";
            for(int j=0;;)
            {
                    temp1=getch();
	             	putch('*');
                    if((temp1>='a'&& temp1<='z')||(temp1>='A'&& temp1<='Z')||(temp1>='0'&& temp1<='9'))
                    {
                         confirmpass[j]=temp1;
                         ++j;
                    }
                    if(temp1=='\b'&&j>=1)
                    {
                         cout<<"\b \b";
                         --j;
                    }
                    if(temp1=='\r')
                    {
                         confirmpass[j]='\0';
                         break;
                    }
            }
            if(strcmpi(password,confirmpass)==0)
            {
                 	goto x;
	     	}
         	else if(strcmpi(password,confirmpass)==1) 
         	{
	            	cout<<"\n\nERROR\n\n";
	            	goto y;
	        } 
x:          strcat(detail,(char*&)username);
			file<<" ";
            file<<strcat(detail,password);
            file.close();
            cout<<"\n\n\tADMIN SUCCESSFULLY REGISTERED\n";
            getch();
        }

void admin_login()
{
	string word,filename;
	string passw;
	int flag;
	char pass[20];
	char temp2;
    char uname[20];
    char checkdetails[20];
z:	cout<<"\t\t\tLOGIN REQURED\n";
	cout<<"\n\n\tPLEASE ENTER THE FOLLOWING FIELDS\n";
	cout<<"\n\n\tUSERNAME : ";
    cin.ignore();
	getch();
	gets(uname);
	puts(uname);getch();
	cout<<"\n\n\tPASSWORD : ";
	for(int i=0;;)
	{
	     temp2=getch();
		 if((isalpha(temp2)!=0)||isdigit(temp2)!=0)
		 {
		 	
		 putch('*');
		 if((temp2>='a'&& temp2<='z')||(temp2>='A'&& temp2<='Z')||(temp2>='0'&& temp2<='9'))
        {
            pass[i]=temp2;
            ++i;
        }
    	}
        if((temp2=='\b')&&(i>=1))
        {
            cout<<"\b \b";
            --i;
        }
        if(temp2=='\r')
        {
            pass[i]='\0';
            break;
        }	
	}
	puts(pass);
	strcat(checkdetails,uname);
    strcat(checkdetails,pass);
	file.open("file.txt",ios::in);
	while(file>>word)
	{
		check=word;
		if(word==checkdetails)
		{
			file.close();
			 return;
	    }
	 }
	cout<<" invalid.try again\n\n";getch();
	file.close();
	goto z;
}
}s;
fstream fp,fp1;
book bk;
student st;
void write_book()
{
	char ch;
	fp.open("book.txt",ios::out|ios::app);
	do
	{
		 system("cls");
		bk.create_book();
		fp.write((char*)&bk,sizeof(book));
		cout<<"\n\nDo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
void write_student()
{
	char ch;
	fp.open("student.txt",ios::out|ios::app);
	do
	{
		st.create_student();
		fp.write((char*)&st,sizeof(student));
		cout<<"\n\ndo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
void display_spb(char n[])
{
	cout<<"\nBOOK DETAILS\n";
	int flag=0;
	fp.open("book.txt",ios::in);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.show_book();
		 	flag=1;
		}
	}
	fp.close();
	if(flag==0)
		cout<<"\n\nBook does not exist";
	getch();
}
void display_sps(char n[])
{
	cout<<"\nSTUDENT DETAILS\n";
	int flag=0;
	fp.open("student.txt",ios::in);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if((strcmpi(st.retadmno(),n)==0))
		{
			st.show_student();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
    		cout<<"\n\nStudent does not exist";
 	getch();
}
void modify_book()
{
	char n[6];
	int found=0;
	 system("cls");
	cout<<"\n\n\tMODIFY BOOK REOCORD.... ";
	cout<<"\n\n\tEnter The book no. of The book";
	cin>>n;
	fp.open("book.txt",ios::in|ios::out);
	while(fp.read((char*)&bk,sizeof(book)) && found==0)
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.show_book();
			cout<<"\nEnter The New Details of book"<<endl;
			bk.modify_book();
			int pos=-1*sizeof(bk);
		    	fp.seekp(pos,ios::cur);
		    	fp.write((char*)&bk,sizeof(book));
		    	cout<<"\n\n\t Record Uptxted";
		    	found=1;
		}
	}
    	fp.close();
   	if(found==0)
    		cout<<"\n\n Record Not Found ";
    	getch();
}
void modify_student()
{
	char n[6];
	int found=0;
	 system("cls");
	cout<<"\n\n\tMODIFY STUDENT RECORD... ";
	cout<<"\n\n\tEnter The admission no. of The student";
	cin>>n;
	fp.open("student.txt",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	{
		if(strcmpi(st.retadmno(),n)==0)
		{
			st.show_student();
			cout<<"\nEnter The New Details of student"<<endl;
			st.modify_student();
			int pos=-1*sizeof(st);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&st,sizeof(student));
			cout<<"\n\n\t Record Uptxted";
			found=1;
		}
	}
	fp.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
}
void delete_student()
{
	char n[6];
	int flag=0;	
	 system("cls");
    	cout<<"\n\n\n\tDELETE STUDENT...";
    	cout<<"\n\nEnter The admission no. of the Student You Want To Delete : ";
    	cin>>n;
    	fp.open("student.txt",ios::in|ios::out);
    	fstream fp2;
    	fp2.open("Temp.txt",ios::out);
    	fp.seekg(0,ios::beg);
    	while(fp.read((char*)&st,sizeof(student)))
	{
		if(strcmpi(st.retadmno(),n)!=0)
	     		fp2.write((char*)&st,sizeof(student));
		else
	   		flag=1;
	}
		fp2.close();
    	fp.close();
    	remove("student.txt");
    	rename("Temp.txt","student.txt");
    	if(flag==1)
     		cout<<"\n\n\tRecord Deleted ..";
    	else
     		cout<<"\n\nRecord not found";
    	getch();
}
void delete_book()
{
	char n[6];
	 system("cls");
	cout<<"\n\n\n\tDELETE BOOK ...";
	cout<<"\n\nEnter The Book no. of the Book You Want To Delete : ";
	cin>>n;
	fp.open("book.txt",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.txt",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),n)!=0)  
		{
			fp2.write((char*)&bk,sizeof(book));
		}
	}
	fp2.close();
    	fp.close();
    	remove("book.txt");
    	rename("Temp.txt","book.txt");
    	cout<<"\n\n\tRecord Deleted ..";
    	getch();
}
void display_alls()
{
	 system("cls");
     	fp.open("student.txt",ios::in);
     	if(!fp)
     	{
       		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
       		getch();
       		return;
     	}
	cout<<"\n\n\t\tSTUDENT LIST\n\n";
	cout<<"==================================================================\n";
	cout<<"\tAdmission No."<<setw(30)<<"Name"<<setw(30)<<"Book Issued\n";
	cout<<"==================================================================\n";
	while(fp.read((char*)&st,sizeof(student)))
	{
		st.report();
	}
    fp.close();
	getch();
}
void display_allb()
{
	 system("cls");
	fp.open("book.txt",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
       		getch();
       		return;
     	}
	cout<<"\n\n\t\tBook LIST\n\n";
	cout<<"=========================================================================\n";
	cout<<"Book Number"<<setw(30)<<"Book Name"<<setw(30)<<"Author\n";
	cout<<"=========================================================================\n";
	while(fp.read((char*)&bk,sizeof(bk)))
	{
		bk.report();
	}
     	fp.close();
     	getch();
}
void book_issue()
{
	char sn[6],bn[6];
	int found=0,flag=0;
    system("cls");
	cout<<"\n\t\t... BOOK ISSUE MENU ...";
	cout<<"\n\nEnter The student's admission no.";
	cin>>sn;
	fp.open("student.txt",ios::in|ios::out);
    fp1.open("book.txt",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
		if(strcmpi(st.retadmno(),sn)==0)
		{
			found=1;
			if(st.rettoken()==0)
			{
		      	cout<<"\n\n\tEnter the book no. ";
				cin>>bn;
				while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
				{
			   		if(strcmpi(bk.retbno(),bn)==0)
					{
						bk.show_book();
						flag=1;
						st.addtoken();
						st.getstbno(bk.retbno());
       						int pos=-1*sizeof(st);
						fp.seekp(pos,ios::cur);
						fp.write((char*)&st,sizeof(student));
						cout<<"\n\n\t Book issued successfully\n\nPlease Note: Write the current date in backside of your book and submit within 15 days fine Rs. 1 for each day 							after 15 days period";
					}
		    		}
		  		if(flag==0)
		    			cout<<"Book no does not exist";
			}
	    		else
		  		cout<<"You have not returned the last book ";
		}
	}
      	if(found==0)
		cout<<"Student record not exist...";
	getch();
  	fp.close();
  	fp1.close();
}
void book_deposit()
{
    char sn[6],bn[6];
    int found=0,flag=0,day,fine;
     system("cls");
    cout<<"\n\nBOOK DEPOSIT ...";
    cout<<"\n\n\tEnter The student’s admission no.";
    cin>>sn;
    fp.open("student.txt",ios::in|ios::out);
    fp1.open("book.txt",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
       {
	    if(strcmpi(st.retadmno(),sn)==0)
	    {
		    found=1;
		    if(st.rettoken()==1)
		    {
			while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
			{
			   if(strcmpi(bk.retbno(),st.retstbno())==0)
			{
				bk.show_book();
				flag=1;
				cout<<"\n\nBook deposited in no. of days";
				cin>>day;
				if(day>15)
				{
				   fine=(day-15)*1;
				   cout<<"\n\nFine has to deposited Rs. "<<fine;
				}
					st.resettoken();
					int pos=-1*sizeof(st);
					fp.seekp(pos,ios::cur);
					fp.write((char*)&st,sizeof(student));
					cout<<"\n\n\t Book deposited successfully";
			}
		    }
		  if(flag==0)
		    cout<<"Book no does not exist";
		      }
		 else
			cout<<"No book is issued..please check!!";
		}
	   }
      if(found==0)
	cout<<"Student record not exist...";
	getch();
  fp.close();
  fp1.close();
  }
void intro()
{
	system("cls");
	cout<<"\t\tLIBRARY";
	cout<<"\tMANAGEMENT ";
	cout<<"SYSTEM";
	cout<<"\n\n\tMADE BY : CHINMAY JOSHI";
	cout<<"\n\n\tSCHOOL : SNJA HSS";
	getch();
}
void admin_menu()
{
	system("cls");
	int ch2;
	cout<<"\n\n\n\tADMINISTRATOR MENU";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORD";
	cout<<"\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
	cout<<"\n\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\n\t6.CREATE BOOK ";
	cout<<"\n\n\t7.DISPLAY ALL BOOKS ";
	cout<<"\n\n\t8.DISPLAY SPECIFIC BOOK ";
	cout<<"\n\n\t9.MODIFY BOOK ";
	cout<<"\n\n\t10.DELETE BOOK ";
	cout<<"\n\n\t11.REGISTER NEW ADMINISTRATOR";
	cout<<"\n\n\t12.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-12) ";
	cin>>ch2;
	switch(ch2)
	{
    		case 1:   system("cls");
	    	            write_student();break;
    		case 2:   display_alls();break;
    		case 3:   char num[6];
	       		        system("cls");
	       	    	    cout<<"\n\n\tPlease Enter The Admission No. ";
	       		        cin>>num;
	       	            display_sps(num);
	       		        break;	       		
      		case 4:   modify_student();
			            break;
      		case 5:   delete_student();
		            break;
	    	case 6:   system("cls");
		            	write_book();
				    	break;
	    	case 7:  display_allb();
			           break;
	    	case 8:	 {
	    		        	char num[6];
	       		            system("cls");
	       	    	        cout<<"\n\n\tPlease Enter The book No. ";
	       	    	        cin>>num;
	       	    	        display_spb(num);
	       	    	        break;
	       	             }		
			case 9:   modify_book();
			            break;
      		case 10:  delete_book();
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. BOOK ISSUE";
		cout<<"\n\n\t02. BOOK DEPOSIT";
	  	cout<<"\n\n\t03. ADMINISTRATOR MENU";
	  	cout<<"\n\n\t04. EXIT";
	  	cout<<"\n\n\tPlease Select Your Option (1-4) : ";
	  	ch=getch();
	  	switch(ch)
	  	{
			            break;
     		case 11: s.add_admin();break;
     		case 12:  return;
      		default  :  cout<<"\a"; 
   	}
   admin_menu();
}
int main()
{
	char ch;
	intro();
	do
	{
		system("cls");
			case '1': system("cls");
				      book_issue();
			   	      break;
		  	case '2': book_deposit();
			    	  break;
		  	case '3': s.admin_login(); 
			          admin_menu();
		  	         break;
		  	case '4': exit(0);
		  	default : cout<<"\a";
		}
    }while(ch!='4');
}
