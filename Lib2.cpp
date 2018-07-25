///***************************************************************
///                   HEADER FILE USED IN PROJECT
///****************************************************************

#include<fstream>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<cstring>
#include<iomanip>
#include<stdlib.h>
#include<windows.h>

char password[30] ="123" ;

///Creating custom gotoxy function

 COORD coord={0,0};

 void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }


///***************************************************************
///                   CLASS USED IN PROJECT
///****************************************************************

using namespace std ;


class book
{
	char bno[20];
	char bname[50];
	char aname[20];
	//char bookid[20];
	int noc;
	int m_noc;
  public:
	void create_book(char bn[20])
	{
		strcpy(bno ,bn);
		cout<<"\nEnter The Name of The Book :";
		gets(bname);
		cout<<"\nEnter The Author's Name :";
		gets(aname);
		cout<<"\n\nEnter number of copies : ";
		cin>>noc ;
		m_noc=noc;
		cout<<"\n\n\nBook Created..";
	}

	void show_book()
	{
		cout<<"\nBook no. : "<<bno;
		cout<<"\nBook Name : ";
		puts(bname);
		cout<<"Author Name : ";
		puts(aname);
		cout<<"Number of copies left :";
		cout<<noc ;
	}

	void modify_book()
	{
		cout<<"\nBook no. : "<<bno;cin.get();
		cout<<"\nModify Book Name : ";
		gets(bname);
		cout<<"\nModify Author's Name of Book : ";
		gets(aname);
	}

	char *retbname()
	{
	    return bname;
	}

	char *retbauth()
	{
	    return aname;
	}

	void inc_copies(int x)
	{
	    m_noc+=x;
	}

	int max_noc()
	{
	    return m_noc;
	}

	char* retbno()
	{
		return bno;
	}

	int ret_noc()
	{
	    return noc;
	}

	void dec_copies(int x)
	{
	    m_noc-=x;
	    noc-=x;
	}

	void set_noc(int n)
	{
	    noc = n ;
	}

	void report()
	{cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<setw(30)<<m_noc<<endl;}


};         ///class ends here




class student
{
	char admno[20];
	char name[20];
	char stbno1[20];
	char stbno2[20];
	char stbno3[20];
	long long ph;
	char branch[20];
	int token;
public:

    int fine;///this is the variable for the fine.


	void create_student(char admn[20])
	{

		strcpy(admno ,admn);
		//cin.get() ;
		cout<<"\nEnter The Name of The Student :";
		gets(name) ;
		cout <<"\nEnter the branch of the student (1.coe 2.it 3.ice) :";
		int x;
		cin >> x;
		while(x<1 || x>3)
        {
            cout << "Wrong entry!";
            cout <<"\nEnter the branch of the student (1.coe 2.it 3.ice) :";
            cin >> x;
        }
        if(x==1) strcpy(branch,"COE");
        else if(x==2) strcpy(branch,"IT");
        else if(x==3) strcpy(branch,"ICE");
		cout <<"\nEnter the phone no. of the student :";
		cin >> ph;
		while(ph<1000000000 || ph>9999999999)
        {
            cout << "Invalid phone no!";
            cout <<"\nEnter the phone no. of the student :";
            cin >> ph;
        }
		///
		//cin.get() ;
		token=0;
		stbno1[0]='/0';
		stbno2[0]='/0';
		stbno3[0]='/0';

		fine =0 ;///for fine

		cout<<"\n\nStudent Record Created..";
	}

	void show_student()
	{
		cout<<"\nRoll no. : "<<admno;
		cout<<"\nStudent Name : ";
		puts(name);
		cout << "Phone no. : " << ph;
		cout << "\nBranch : ";
		puts(branch);
		cout<<"No of Book issued : "<<token;
		int x=token;
		if(x>=1) cout <<"\nBook No 1 :"<<stbno1;
		if(x>=2) cout <<"\nBook No 2 :"<<stbno2;
		if(x>=3) cout <<"\nBook No 3 :"<<stbno3;

		if(fine!=0)
        {
            cout<<"\nFINE TO BE PAID :"<<fine ;
        }
	}

	void modify_student()
	{
		cin.get();
		cout<<"\nRoll no. : "<<admno;
		cout<<"\nBranch : "<<branch;
		cout<<"\nModify Student Name : ";
		gets(name);
		cout << "\nModify Phone no. : ";
		cin >> ph;
		cin >> ph;
		while(ph<1000000000 || ph>9999999999)
        {
            cout << "Invalid phone no!";
            cout <<"\nEnter the phone no. of the student :";
            cin >> ph;
        }
	}

	char* retname()
	{
		return name;
	}

	char* retbranch()
	{
		return branch;
	}

	long long retph()
	{
	    return ph;
	}

	char* retadmno()
	{
		return admno;
	}

	char* retstbno1()
	{
	    return stbno1;
	}
	char* retstbno2()
	{
	    return stbno2;
	}
	char* retstbno3()
	{
	    return stbno3;
	}

	int rettoken()
	{
		return token;
	}

	void addtoken()
	{token++;}

	void dec_token()
	{token--;}

	void getstbno(char *t)
	{
		if(token==0) for(int i=0; i<=strlen(t); i++) stbno1[i]=t[i];
		else if(token==1) for(int i=0; i<=strlen(t); i++) stbno2[i]=t[i];
		else for(int i=0; i<=strlen(t); i++) stbno3[i]=t[i];
	}

	void del_book(int x)
	{
        if(x==1)
        {
            if(stbno3[0]!='\0')
            {
                for(int i=0; i<=strlen(stbno3); i++) stbno1[i]=stbno3[i];
                stbno3[0]='\0';
            }
            else if(stbno2[0]!='\0')
            {
                for(int i=0; i<=strlen(stbno2); i++) stbno1[i]=stbno2[i];
                stbno2[0]='\0';
            }
            else stbno1[0]='\0';
        }
        else if(x==2)
        {
            if(stbno3[0]!='\0')
            {
                for(int i=0; i<=strlen(stbno3); i++) stbno2[i]=stbno3[i];
                stbno3[0]='\0';
            }
            else stbno2[0]='\0';
        }
        else stbno3[0]='\0';
	}

	void report()
	{cout<<"\t"<<admno<<setw(30)<<name<<setw(20)<<branch<<setw(20)<<ph<<setw(20)<<token<<endl;}

};         ///class ends here




///***************************************************************
///    	global declaration for stream object, object
///****************************************************************

fstream fp,fp1;
book bk;
student st;


///***************************************************************
///    	function to write in file
///****************************************************************

void write_book()
{
	char ch;

	do
	{
		system("cls") ;
		cout<<"\nNEW BOOK ENTRY...\n";
		cout<<"\nEnter The book no. :";
		char bn[20];
		cin>>bn;cin.get() ;

		ifstream ifile("book.dat" ,ios::in|ios::binary) ;

		while(ifile.read((char*)&bk ,sizeof(book)))
        {
            if(strcmp(bk.retbno(),bn)==0)
            {
                cout<<"THIS REORD ALREADY EXISTS!!!\n";
                ifile.close();
                return ;
            }

        }
		ifile.close();
		bk.create_book(bn);
		fp.open("book.dat",ios::out|ios::app|ios::binary);
		fp.write((char*)&bk,sizeof(book));
		cout<<"\n\nDo you want to add more record..(y/n?) ";
		cin>>ch;
		fp.close();
	}while(ch=='y'||ch=='Y');

}

void write_student()
{
	char ch;

	do
	{
		ifstream ifile("student.dat", ios::binary|ios::in);
		system("cls") ;
		cin.get();
		char admn[20] ;
	 	cout<<"\nNEW STUDENT ENTRY...\n";
		cout<<"\nEnter The roll no. : ";
		gets(admn) ;

		while(ifile.read((char*)&st ,sizeof(student)))
        {

            if(strcmp(st.retadmno() ,admn)==0)
            {
                cout<<"THIS RECORD EXISTS!!!\n";
                ifile.close();
                return ;
            }
        }

        ifile.close() ;

		st.create_student(admn);
		fp.open("student.dat" ,ios::out|ios::app|ios::binary);
		fp.write((char*)&st,sizeof(student));
		cout<<"\n\ndo you want to add more record..(y/n?) ";
		cin>>ch;
		fp.close();
	}while(ch=='y'||ch=='Y');

}


///***************************************************************
///    	function to read specific record from file
///****************************************************************


void display_spb(char n[])
{
	cout<<"\nBOOK DETAILS\n";
	int flag=0;
	fp.open("book.dat",ios::in|ios::binary);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmp(bk.retbno(),n)==0)
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

void dis_bk() ///search book by the name
{
    char bn[50],ba[50];
    cout << "Enter book name : ";
    gets(bn);
    cout << "Enter book author : ";
    gets(ba);
    cout<<"\nBOOK DETAILS\n";
	int flag=0;
	fp.open("book.dat",ios::in|ios::binary);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmp(bk.retbname(),bn)==0 || strcmp(bk.retbauth(),ba)==0)
		{
			cout << "Book name : " << bk.retbname() << "\nAuthor name : " << bk.retbauth() << endl << endl;
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
	fp.open("student.dat",ios::in|ios::binary);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if((strcmp(st.retadmno(),n)==0))
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

void dis_stu() ///search student by the name
{
    char sn[50],sb[50];
    cout << "Enter student's name : ";
    gets(sn);
    cout <<"\nEnter the branch of the student (1.coe 2.it 3.ice) :";
    int x;
    cin >> x;
    while(x<1 || x>3)
    {
        cout << "Wrong entry!";
        cout <<"\nEnter the branch of the student (1.coe 2.it 3.ice) :";
        cin >> x;
    }
    if(x==1) strcpy(sb,"COE");
    else if(x==2) strcpy(sb,"IT");
    else if(x==3) strcpy(sb,"ICE");
    cout<<"\nSTUDENT DETAILS\n";
	int flag=0;
    fp.open("student.dat",ios::in|ios::binary);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if((strcmp(st.retname(),sn)==0)||(strcmp(st.retbranch(),sb)==0))
		{
			cout << "Student name : " << st.retname() << "\nBranch : " << st.retbranch() << "\nPhone no : " << st.retph() << endl << endl;
			flag=1;
		}
	}

	fp.close();
	if(flag==0)
    		cout<<"\n\nStudent does not exist";
 	getch();
}


///***************************************************************
///    	function to modify record of file
///****************************************************************


/*void modify_book()
{
	char n[20];
	int found=0;
	system("cls") ;
	cout<<"\n\n\tMODIFY BOOK REOCORD.... ";
	cout<<"\n\n\tEnter The book no. of The book : ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out|ios::binary);
	while(fp.read((char*)&bk,sizeof(book)) && found==0)
	{
		if(strcmp(bk.retbno(),n)==0)
		{
		    if(bk.ret_noc()<bk.max_noc())
            {
                cout << "\nSome Books are issued ";
                fp.close();
                getch();
                return;
            }
			bk.show_book();
			cout<<"\nEnter The New Details of book"<<endl;
			bk.modify_book();
			int pos=-1*sizeof(bk);
		    	fp.seekp(pos,ios::cur);
		    	fp.write((char*)&bk,sizeof(book));
		    	cout<<"\n\n\t Record Updated";
		    	found=1;
		}
	}

    	fp.close();
    	if(found==0)
    		cout<<"\n\n Record Not Found ";
    	getch();
}*/


void modify_student()
{
	char n[20];///
	int found=0;
	system("cls") ;
	cout<<"\n\n\tMODIFY STUDENT RECORD... ";
	cout<<"\n\n\tEnter The roll no. of The student";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out|ios::binary);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	{
		if(strcmp(st.retadmno(),n)==0)
		{
			st.show_student();
			cout<<"\nEnter The New Details of student"<<endl;
			st.modify_student();
			int pos=-1*sizeof(st);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&st,sizeof(student));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}

	fp.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
}

///***************************************************************
///    	function to delete record of file
///****************************************************************


void delete_student()
{
	char n[20];
	int flag=0;
	system("cls") ;
    	cout<<"\n\n\n\tDELETE STUDENT...";
    	cout<<"\n\nEnter The roll no. of the Student You Want To Delete : ";
    	cin>>n;
    	fp.open("student.dat",ios::out|ios::in|ios::binary);
        while(fp.read((char*)&st,sizeof(student)))
	    {
		  if(strcmp(st.retadmno(),n)==0)
          {
              if(st.rettoken()>0)
              { cout<<"Please deposit the issued book(s)"<<endl ;cin.get();
                fp.close();
                return ;
              }
              if(st.fine!=0)
              {
                  cout<<"Please pay the fine first."<<endl; cin.get();
                  fp.close();
                  return ;
              }
          }

	   }

    	fstream fp2;
    	fp2.open("Temp.dat",ios::out|ios::binary);
    	fp.seekg(0,ios::beg);
    	while(fp.read((char*)&st,sizeof(student)))
	{
		if(strcmp(st.retadmno(),n)!=0)
	     		fp2.write((char*)&st,sizeof(student));
		else
	   		flag=1;
	}

	fp2.close();
    	fp.close();
    	remove("student.dat");
    	rename("Temp.dat","student.dat");
    	if(flag==1)
     		cout<<"\n\n\tRecord Deleted ..";
    	else
     		cout<<"\n\nRecord not found";
    	getch();
}


void delete_book()
{
	char n[20];
	system("cls") ;
	cout<<"\n\n\n\tDELETE BOOK ...";
	cout<<"\n\nEnter The Book no. of the Book You Want To Delete : ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out|ios::binary);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	bool f=0,found=0;
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmp(bk.retbno(),n)!=0)
		{
			fp2.write((char*)&bk,sizeof(book));
		}
		else
        {
            found=1;
            if(bk.ret_noc()!=0)
            {
                int x;
                cout << "\n\nThere are " << bk.ret_noc() << " out of " << bk.max_noc() << " copies in library.\n" ;
                cout << "Enter number of copies to be deleted : ";
                cin >> x;
                while(x>bk.ret_noc())
                {
                    cout << "Wrong input\n\n";
                    cout << "Enter number of copies to be deleted : ";
                    cin >> x;
                }
                if(x>0)f=1;
                bk.dec_copies(x);
                if(bk.max_noc()!=0)fp2.write((char*)&bk,sizeof(book));
            }
            else
            {
                cout <<"No copies of this books are available in the library. So, it cannot be deleted";
                fp2.write((char*)&bk,sizeof(book));
            }
        }
	}

	fp2.close();
    fp.close();
    remove("book.dat");
    rename("Temp.dat","book.dat");
    if(f==1)cout<<"\n\n\tDeletion Successful ..";
    if(found==0) cout << "\n\n\tBook not found ..";
    getch();
}



///***************************************************************
///    	function to display all students list
///****************************************************************

void display_alls()
{
	system("cls") ;
     	fp.open("student.dat",ios::in|ios::binary);
     	if(!fp)
     	{
       		cout<<"ERROR!!! FILE COULD NOT BE OPENED";
       		getch();
       		return;
     	}

	cout<<"\n\n\t\tSTUDENT LIST\n\n";
	cout<<"=========================================================================================================\n";
	cout<<"\tRoll No."<<setw(20)<<"Name"<<setw(20)<<"Branch"<<setw(20)<<"Phone no."<<setw(20)<<"Book Issued\n";
	cout<<"=========================================================================================================\n";

	while(fp.read((char*)&st,sizeof(student)))
	{
		st.report();
	}

	fp.close();
	getch();
}


///***************************************************************
///    	function to display Books list
///****************************************************************

void display_allb()
{
	system("cls") ;
	fp.open("book.dat",ios::in|ios::binary);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPENED ";
       		getch();
       		return;
     	}

	cout<<"\n\n\t\tBOOK LIST\n\n";
	cout<<"=====================================================================================================\n";
	cout<<"Book Number"<<setw(30)<<"Book Name"<<setw(30)<<"Author"<<setw(30)<<"Max No. of copies\n";
	cout<<"=====================================================================================================\n";

	while(fp.read((char*)&bk,sizeof(book)))
	{
		bk.report();
	}
     	fp.close();
     	getch();
}



///***************************************************************
///    	function to issue book
///****************************************************************

void book_issue()
{
	char sn[20],bn[20];
	int found=0,flag=0;
	system("cls") ;
	cout<<"\n\nBOOK ISSUE ...";
	cout<<"\n\n\tEnter The student's roll no. : ";
	cin>>sn;
	fp.open("student.dat",ios::in|ios::out|ios::binary);
    	fp1.open("book.dat",ios::in|ios::out|ios::binary);
    	while(fp.read((char*)&st,sizeof(student)) && found==0)
       	{
		if(strcmp(st.retadmno(),sn)==0)
		{
			found=1;
			if(st.rettoken()<3 && st.rettoken()>=0)
			{
		      		cout<<"\n\n\tEnter the book no. : ";
				cin>>bn;
				while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
				{
			   		if(strcmp(bk.retbno(),bn)==0)
					{

						if(bk.ret_noc()==0)
                        {
                            cout<<"NO BOOKS LEFT!!!\n";
                            getch();
                            fp.close();
                            fp1.close() ;
                            return ;
                        }

                        bk.set_noc(bk.ret_noc()-1) ;
                        bk.show_book();
                        //cout<<"No of copies ="<<bk.ret_noc()<<endl ;
						flag=1;
						st.getstbno(bk.retbno());
						st.addtoken();
       						int pos=-1*sizeof(st);
						fp.seekp(pos,ios::cur);
						fp.write((char*)&st,sizeof(student));
						cout<<"\n\n\t Book issued successfully\n\nPlease Note: Write current date ";
						cout<<"in backside of book and submit within 15 days fine Rs. 1 for each day ";
						cout<<"after 15 days \nperiod";

                        pos=-1*sizeof(bk);
					    fp1.seekp(pos ,ios::cur);

					    fp1.write((char*)&bk ,sizeof(book)) ;

					    break;


					}
                }
		  		if(flag==0)
		    			cout<<"Book no. does not exist";
		        else
                         break ;
			}
	    		else{
		  		cout<<"Maximum books issued ";
	    		}
		}
	}
      	if(found==0)
		cout<<"Student record not exist...";
	getch();
  	fp.close();
  	fp1.close();
}

///***************************************************************
///    	function to deposit book
///****************************************************************

void book_deposit()
{
    char sn[20],bn[20];
    int found=0,day,fine;
    system("cls") ;
    cout<<"\n\nBOOK DEPOSIT ...";
    cout<<"\n\n\tEnter The student's roll no. : ";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out|ios::binary);
    fp1.open("book.dat",ios::in|ios::out|ios::binary);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
	    if(strcmp(st.retadmno(),sn)==0)
	    {
		    found=1;
		    if(st.rettoken()>=1)
		    {
		        cout<<"\n\n\tEnter the book no. : ";
                cin>>bn;
                bool f=0;
                while(fp1.read((char*)&bk,sizeof(book)))
                {
                    if(strcmp(bk.retbno(),bn)==0)
                    {
                        cout << bn;
                        f=1;
                        break;
                    }
                }
                if(f==0)
                {
                    cout << "\n\nBook doesn't exist";
                    fp1.close();
                    break;
                }
                fp1.close();
                if(strcmp(bn,st.retstbno1())==0 || strcmp(bn,st.retstbno2())==0 || strcmp(bn,st.retstbno3())==0)
                {
                    fp1.open("book.dat",ios::in|ios::out|ios::binary);
                    while(fp1.read((char*)&bk,sizeof(book)))
                    {
                        if(strcmp(bk.retbno(),bn)==0)
                        {
                            if(strcmp(bk.retbno(),st.retstbno1())==0) st.del_book(1);
                            else if(strcmp(bk.retbno(),st.retstbno2())==0) st.del_book(2);
                            else st.del_book(3);
                            bk.set_noc(bk.ret_noc()+1);
                            bk.show_book();
                            int pos=-1*sizeof(bk);
                            fp1.seekp(pos ,ios::cur);
                            fp1.write((char*)&bk ,sizeof(bk));
                            fp1.close();
                            break;
                        }
                    }
                    cout<<"\n\nBook deposited in no. of days : ";
                    cin>>day;
                    if(day>15)
                    {
                       fine=(day-15)*1;
                       cout<<"\n\nFine has to deposited Rs. : "<<fine;
                       st.fine += fine;
                       cout<<"do you want to pay fine now (y/n)";
                       char ch;
                       cin>>ch ;
                       if(ch=='y'||ch=='Y')
                       {
                           cout<<"fine paid(including previous fine if any) = "<<st.fine ;
                           cout<<"\n....the current fine =0"<<endl;
                       }
                    }
                    st.dec_token();
                    int pos=-1*sizeof(st);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&st,sizeof(student));
                    cout<<"\n\n\t Book deposited successfully";
                    break ;
                }
                else
                {
                    cout << "This book is not issued to this student";
                    break;
                }
            }
            else
            {
                cout<<"No book is issued..please check!!";
                break;
            }
		}
    }
    if(found==0)
    cout<<"Student record not exist...";
	getch();
    fp.close();
}

void inc_noc()  ///to increase the number of copies of the book
{
    char n[20];
	int found=0;
	system("cls") ;
	cout<<"\n\n\tADD NUMBER OF COPIES OF A BOOK.... ";
	cout<<"\n\n\tEnter The book no. of The book : ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out|ios::binary);
	while(fp.read((char*)&bk,sizeof(book)) && found==0)
	{
		if(strcmp(bk.retbno(),n)==0)
		{
		    found=1;
		    bk.show_book();
		    int x;
            cout << "\nEnter increase in number of copies : " ;
            cin >> x;
			bk.inc_copies(x);
			bk.set_noc(bk.ret_noc()+x);
			int pos=-1*sizeof(bk);
		    	fp.seekp(pos,ios::cur);
		    	fp.write((char*)&bk,sizeof(book));
		    	cout<<"\n\n\t Record Updated";
		    	found=1;
		}
	}

    	fp.close();
    	if(found==0)
    		cout<<"\n\n Record Not Found ";
    	getch();
}

void pay_fine()
{
    ///to be done .
    char n[20] ;
    int found=0;
    system("cls") ;
	cout<<"\n\n\tPAYING FINE... ";
	cout<<"\n\n\tEnter The roll no. of The student";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out|ios::binary);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	{
		if(strcmp(st.retadmno(),n)==0)
		{
			st.show_student();
			cout<<"\nYour current fine = "<<st.fine<<endl;
            cout<<"Do you want to pay he fine(y/n)\n";
            char ans;
            cin>>ans;

            if(ans=='y'||ans=='Y')
            {
                cout<<"How much fine do you want to pay :";
                int fn;
                cin>>fn;
                if(fn<=st.fine)
                    st.fine -=fn;
                else
                    cout<<"Please add valid fine\n";
            }

			int pos=-1*sizeof(st);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&st,sizeof(student));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}

	fp.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();

}


///***************************************************************
///    	INTRODUCTION FUNCTION
///****************************************************************

void intro()
{

    system("cls") ;
	system("color 4E");
	//system("size 5") ;
	cout<<"\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t         LIBRARY";
	cout<<" MANAGEMENT";
	cout<<" SYSTEM\n";
	cout<<"\t\t\t\t         _________________________\n";
	getch();
	system("color F2") ;
}



///***************************************************************
///    	ADMINISTRATOR MENU FUNCTION
///****************************************************************
void admin() ;
void student_menu();
void book_menu();
void admin_menu()
{
	system("cls") ;
	cout<<"To enter this menu please enter password : ";
	char pass[30];
	cin>>pass;


	if(strcmp(pass ,password))
    {
        cout<<"THE PASSWORD IS INCORRECT!!!";
        cin.get() ;
        return ;
    }
    else
    {
        cout<<"\nPlease press any key to continue";
        system("cls");
    }

    char ch ;
    do
	{
		system("cls") ;
		gotoxy(40 , 5) ;
		cout<<"\t______________";
		gotoxy(40 , 6) ;
		cout<<"\t  ADMIN MENU";
		gotoxy(40 , 7) ;
		cout<<"\t______________";
		gotoxy(40 , 9) ;
		cout<<"\t01. Student Menu";
		gotoxy(40 , 10) ;
		cout<<"\t02. Book Menu";
        gotoxy(40 ,11) ;
        cout<<"\t03. Return to Main menu  ";
        gotoxy(40 ,12) ;
        cout<<"\tPLease enter your choice (1-3)  ";
	  	cin>>ch;
	  	switch(ch)
	  	{
			case '1':system("cls") ;
				 student_menu();
			   	 break;
		  	case '2':system("cls");
		  	    book_menu();
			    	 break;
			case '3':return ;

		  	default :cout<<"\a";
		}
    	}while(ch!='3');

    return ;
}

void student_menu()
{

    system("cls");
	int ch2;
	gotoxy(40,5);
	cout<<"   ___________________________";
	gotoxy(40,6);
	cout<<"         STUDENT MENU\n";
	gotoxy(40,7);
	cout<<"   ____________________________";
	gotoxy(40,9);
	cout<<"   1.Create New Student";
	gotoxy(40,10);
	cout<<"   2.Display all Students";
	gotoxy(40,11);
	cout<<"   3.Display student (by rollno) ";
	gotoxy(40,12);
	cout<<"   4.Display student (by name) ";
	gotoxy(40,13);
	cout<<"   5.Modify Student";
	gotoxy(40,14);
	cout<<"   6.Delete Student";
	gotoxy(40,15);
	cout<<"   7.Return to Admin Menu";
	gotoxy(40,16);
	cout<<"   Please Enter Your Choice (1-7) : ";
	cin>>ch2;
	switch(ch2)
	{
    		case 1: system("cls") ;
	    		write_student();break;
    		case 2: display_alls();break;
    		case 3:
	       		char num[20];
	       		system("cls") ;
	       		cout<<"\n\n\tPlease Enter The roll No. : ";
	       		cin>>num;
	       		display_sps(num);
	       		break;
            case 4: system("cls");cin.get();
                    dis_stu() ;
                    break ;
      		case 5: modify_student();break;
      		case 6: delete_student();break;

     		case 7: return;
      		default:cout<<"\a";
   	}
   	cin.get() ;
   	student_menu() ;

}

void book_menu()
{
   int ch2 ;
   system("cls") ;
   gotoxy(40,5);
	cout<<"   ___________________________";
	gotoxy(40,6);
	cout<<"           BOOK MENU\n";
	gotoxy(40,7);
	cout<<"   ____________________________";
	gotoxy(40,9);
	cout<<"   1.Create Book ";///7
	gotoxy(40,10);
	cout<<"   2.Display all Books ";
	gotoxy(40,11);
	cout<<"   3.Display Specific Books (by book number) ";
	gotoxy(40,12);
	cout<<"   4.Display Specific Books (by name)";
	gotoxy(40,13);
	cout<<"   5.Increase No. of Copies ";
	gotoxy(40,14);
	cout<<"   6.Delete Book";
	gotoxy(40,15);
	cout<<"   7.Pay fine";
	gotoxy(40,16);
	cout<<"   8.Return to Admin Menu";
	gotoxy(40,17);
	cout<<"   Please Enter Your Choice (1-8) : ";
	cin>>ch2;
	switch(ch2)
	{
		case 1: system("cls") ;
			write_book();break;
		case 2: display_allb();break;
		case 3 :{
	       		char num[20];
	       		system("cls") ;
	       		cout<<"\n\n\tPlease Enter The book No. : ";
	       		cin>>num;
	       		display_spb(num);
	       		break;
			}
        case 4 :  system("cls");cin.get();
                   dis_bk() ;
                   break ;
      		case 5: inc_noc();break;
      		case 6: delete_book();break;

      		case 7 :system("cls") ;
                pay_fine();break ;

     		case 8: return;
      		default:cout<<"\a";
   	}
   	cin.get() ;

   	book_menu() ;
}


///**************************************************************
///    THE PASSWORD FUNCTION
///**************************************************************

void pass_menu()
{
    cout<<"Please enter the current password  : " ;
    char pass[30] ;
    cin.get();
    gets(pass) ;

    if(strcmp(pass ,password))
    {
        cout<<"INCORRECT PASSWORD!!!";
        return ;
    }
    else
    {
         cout<<"please enter new password : ";
         gets(password) ;

    }


}

///***************************************************************
///    	THE MAIN FUNCTION OF PROGRAM
///****************************************************************


int main()
{
	char ch;
	intro();
	do
	{
		system("cls") ;
		gotoxy(40 , 5) ;
		cout<<"\t______________";
		gotoxy(40 , 6) ;
		cout<<"\t  MAIN MENU";
		gotoxy(40 , 7) ;
		cout<<"\t______________";
		gotoxy(40 , 9) ;
		cout<<"\t01. Book Issue Menu";
		gotoxy(40 , 10) ;
		cout<<"\t02. Book Deposit Menu";
		gotoxy(40 , 11) ;
	  	cout<<"\t03. Administrator Menu";
	  	gotoxy(40 , 12) ;
	  	cout<<"\t04. Change the password";
	  	gotoxy(40 ,13) ;
	  	cout<<"\t05. Exit";
	  	gotoxy(40 , 14) ;
	  	cout<<"\tPlease Select Your Option (1-5) ";
	  	cin>>ch;
	  	switch(ch)
	  	{
			case '1':system("cls") ;
				 book_issue();
			   	 break;
		  	case '2':book_deposit();
			    	 break;
		  	case '3':admin_menu();
				 break;
            case '4' :
                   pass_menu();
                   break ;
		  	case '5':return 0;
		  	       //system("shutdown.exe -h");
		  	       exit(1);
		  	       break;
		  	default :cout<<"\a";
		}
    	}while(ch!='5');

    	return 0;
}

///***************************************************************
///    			END OF PROJECT
///***************************************************************



