#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<process.h>

class student
{
char name[30],bgrp[5],sec,dob[10],stream[10],moname[15],faname[15];
char gra,sex;
int tot;
int enrollno,cla,pmar,cmar,mmar,csmar,engmar,rank;
float per;
long int phno;
public:
void sreadrecord();
void newrecord();
void modify();
void del();
void displayall();
void display();
void studentmenu();
void inputmark();
void marksheet();
void allotstream();
void helpmenu();
void credits();
}s;

class teacher
{
int enrollno;
char name[30],qual[30],sex,exp[10],dept[30],bgrp[7],dob[10];
int phno,age;
public:
void treadrecord();
void newrecord();
void modify();
void del();
void display();
void displayall();
void teachermenu();
}t;


struct administrator
{
char user_name[10];
char password[10];
}admin;

void intropage();
void mainmenu();
int verifypassword();

void intropage()
{
clrscr();
int y;
cout<<"\n\n\n\n\n\n";
cout<<"           *=============== SCHOOL MANAGEMENT SYSTEM ===============*\n\n";
y=verifypassword();
if(y==0)
mainmenu();
else
cout<<"\n\nACCESS DENIED! INVALID USERNAME/PASSSWORD";
}




void mainmenu()
{
clrscr();
int ch;
cout<<"==============================MAIN MENU============================"<<endl;
cout<<"\n\n\n1.Student management\n2.teacher management\n3.Help\n4.Credits\n5.Exit program\n\n\n";
cout<<"\n\n\==================================================================="<<endl;
cout<<"PLEASE ENTER YOUR CHOICE"<<endl;
cin>>ch;
switch(ch)
{
     case 1:
	  s.studentmenu();
	  break;
     case 2:
	  t.teachermenu();
	  break;
     case 3:
	  s.helpmenu();
	  break;
     case 4:
	  s.credits();
	  break;
     case 5:
	  exit(0);
	  break;
     default:
	  cout<<"Invalid choice.Please enter again."<<endl;
	  break;
}
}



int verifypassword()
{
char u_name[10];
char u_pwd[10],temp[2];
int x=1;
cout<<"\n\n                     enter username:";
cin>>u_name;
cout<<endl;
cout<<"                     enter password:";
{
int i=0;
while(1)
{
u_pwd[i]=getch();
if(u_pwd[i]==13)
break;
cout<<"*";
i++;
}
u_pwd[i]='\0';
}
cout<<"\n\n***************************************************************"<<endl;
x=strcmp("cv",u_name);
if(x==0)
{
x=strcmp("csc",u_pwd);
}
cin.getline(temp,2);
return(x);
}


void student::studentmenu()
{
int ch;
clrscr();
cout<<"============================STUDENT MAIN MENU==========================\n\n\n"<<endl;
cout<<"1.Enter new student record\n2.Modify existing student record\n3.Delete student record\n4.Display all records\n5.Display desired student record\n6.Display mark sheet\n7.Stream Predictor\n8.Back to main\n\n\n";
cout<<"=======================================================================\n\n\n"<<endl;
cout<<"Please enter you choice:"<<endl;
cin>>ch;
switch(ch)
{
      case 1:
	   s.newrecord();
	   break;
      case 2:
	   s.modify();
	   break;
      case 3:
	   s.del();
	   break;
      case 4:
	   s.displayall();
	   break;
      case 5:
	   s.display();
	   break;
      case 6:
	   s.marksheet();
	   break;

      case 7:
	   s.allotstream();
	   break;
      case 8:
	   mainmenu();
	   break;
      default:
	   cout<<"invalid choice.please enter another choice\n\n";
	   s.studentmenu();
	   break;
      }

}


void student::newrecord()
{
   clrscr();
   char ch;
   char a;
   cout<<"=====================STUDENT DATA ENTRY========================="<<endl;
   fstream x("student.dat",ios::out|ios::binary);
   do
   {
   s.sreadrecord();
   x.write((char*)&s,sizeof(s));
   cout<<"Any more records (y/n)\n\n";
   cin>>ch;
   }
   while(ch=='y'||ch=='Y');
   x.close();
   s.studentmenu();
}


void student::sreadrecord()
{
cout<<endl;
cout<<"Enrollno:";
cin>>s.enrollno;
cout<<"\nName:";
gets(s.name);
cout<<"\nDOB:";
gets(s.dob);
cout<<"\nClass:";
cin>>s.cla;
cout<<"\nSection:";
cin>>s.sec;
cout<<"\nEnter sex:";
cin>>s.sex;
cout<<"\nEnter Blood Group:";
cin>>s.bgrp;
cout<<"\nMother's name:";
gets(s.moname);
cout<<"\nFather's name:";
gets(s.faname);
cout<<"\nEnter phone number:";
cin>>s.phno;
cout<<"\nEnter marks:";
cout<<endl;
cout<<"\Enter the physics marks:";
cin>>s.pmar;
cout<<"\nEnter the chemistry mark:";
cin>>s.cmar;
cout<<"\nEnter the math mark:";
cin>>s.mmar;
cout<<"\nenter the english marks:";
cin>>s.engmar;
cout<<"\nenter the computer science marks:";
cin>>s.csmar;
}


void student::modify()
{
clrscr();
char a;
int c,i=0,r=0;
fstream x("student.dat",ios::in|ios::out|ios::binary);
if(!x)
cout<<"\nFile does not exist"<<endl;
else
{
cout<<"******************* MODIFYING RECORD *******************"<<endl;
cout<<"\n\nEnter the student enrollno to be modified:\n";
cin>>c;
while(x.read((char*)&s,sizeof(s)))
{
r++;
if(s.enrollno==c)
{
i++;
cout<<"\n\nEnter the new values:\n";
sreadrecord();
x.seekp((r-1)*sizeof(s),ios::beg);
x.write((char*)&s,sizeof(s));
}
}
}
x.close();
if(i==0)
cout<<"\RECORD DOES NOT EXIST";
else
cout<<"\nSUCESS!RECORD IS UPDATED";
cout<<endl;
cout<<"Enter *m* to go back to student mainmenu"<<endl;
cin>>a;
if(a=='m')
s.studentmenu();
else
{
do
{
cout<<"INVALID INPUT! Enter *m* to go back to mainmenu"<<endl;
cin>>a;
}
while(a!='m');
s.studentmenu();
}
}


void student::del()
{
clrscr();
char a;
int eno,flag=0;
fstream x,y;
cout<<"********************* RECORD DELETION **************************"<<endl;
x.open("student.dat",ios::in|ios::binary);
y.open("temp.dat",ios::out|ios::binary);
cout<<"Enter the student enrollno to be deleted";
cin>>eno;
while(!x.eof())
{
x.read((char*)&s,sizeof(s));
if(s.enrollno==eno)
flag=1;
else
y.write((char*)&s,sizeof(s));
}
x.close();
y.close();
remove("student.dat");
rename("temp.dat","student.dat");
if(flag==0)
cout<<"SORRY,ENROLLNO NOT FOUND!";
else
cout<<"SUCCESS!RECORD HAS BEEN DELETED";
cout<<endl;
cout<<"Enter *m* to go back to mainmenu"<<endl;
cin>>a;
if(a=='m')
s.studentmenu();
else
{
do
{
cout<<"INVALID INPUT!Enter *m* to back to mainmenu";
cin>>a;
}
while(a!='m');
s.studentmenu();
}
}


void student::displayall()
{
char a;
clrscr();
cout<<"********************** STUDENT RECORDS ***************************"<<endl;
fstream x("student.dat",ios::in|ios::binary);
if(!x)
 cout<<"\nFile does not exist"<<endl;
 else
 {
 cout<<"E.NO\tNAME\t\tSEX\tDOB\t\t\tCLASS\tSEC\n\n";
 while(x.read((char*)&s,sizeof(s)))
 cout<<s.enrollno<<"\t"<<s.name<<"\t\t"<<s.sex<<"\t"<<s.dob<<"\t\t"<<s.cla<<"\t"<<s.sec<<endl;
 }
 cout<<"*******************************************************************"<<endl;
 x.close();
 cout<<"Enter *m* to go back to student mainmenu"<<endl;
 cin>>a;
 if(a=='m')
 s.studentmenu();
 else
 {
 do
 {
 cout<<"INVALID INPUT!Enter *m* to go back to studentmenu"<<endl;
 cin>>a;
 }
 while(a!='m');
 s.studentmenu();
 }
 }

void student::display()
{
clrscr();
int flag=0;
int a;
char r;
cout<<"Enter enrollno of the student record to de diplayed"<<endl;
cin>>a;
cout<<"*********************** STUDENTS DETAILS *************************"<<endl;
fstream x("student.dat",ios::in|ios::binary);
while(x.read((char*)&s,sizeof(s)))
{
if(a==s.enrollno)
{
cout<<"\n              E.NO              :"<<s.enrollno;
cout<<"\n              NAME              :"<<s.name;
cout<<"\n              MOTHER'S NAME     :"<<s.moname;
cout<<"\n              FATHER'S NAME     :"<<s.faname;
cout<<"\n              CLASS             :"<<s.cla;
cout<<"\n              SECTION           :"<<s.sec;
cout<<"\n              SEX               :"<<s.sex;
cout<<"\n              BLOOD GROUP       :"<<s.bgrp;
cout<<"\n              PHNO              :"<<s.phno<<"\n\n";
cout<<"*****************************************************************"<<endl;
flag=1;
}
}
if(flag==0)
cout<<"\nSORRY! NO RECORD FOUND";
x.close();
cout<<"\n\nEnter *m* to go back to mainmenu";
cin>>r;
if(r=='m')
s.studentmenu();
else
{
do
{
cout<<"INVALID INPUT! Enter *m* to go back to mainmenu"<<endl;
cin>>r;
}
while(r!='m');
s.studentmenu();
}
}

void student::marksheet()
{
clrscr();
int e;
char a;
int flag=0;
fstream x("student.dat",ios::in|ios::binary);
if(!x)
cout<<"\nSORRY! FILE DOES NOT EXIST"<<endl;
else
{
cout<<"enter enrollno of the marksheet to be displayed:"<<endl;
cin>>e;
while (x.read((char*)&s,sizeof(s)))
{
if(s.enrollno==e)
{
cout<<"*********************** MARK SHEET *********************"<<endl;
cout<<"\n         Name             :"<<s.name;
cout<<"\n         Physics          :"<<s.pmar;
cout<<"\n         Chemistry        :"<<s.cmar;
cout<<"\n         Math             :"<<s.mmar;
cout<<"\n         Computer Science :"<<s.csmar;
cout<<"\n         English          :"<<s.engmar;
cout<<"\n         Total            :"<<s.pmar+s.cmar+s.mmar+s.csmar+s.engmar;
cout<<"\n\n*********************************************************"<<endl;
flag++;
}
}
}
if(flag==0)
cout<<"Enroll no does not exist!"<<endl;
cout<<"\nEnter *m* to go back to student mainmenu"<<endl;
cin>>a;
if(a=='m')
s.studentmenu();
else
{
do
{
cout<<"\n\nINVALID INPUT! Enter *m* to go to student mainmenu"<<endl;
cin>>a;
}
while(a!='m');
s.studentmenu();
}
}



void student::allotstream()
{
clrscr();
int ch;
char a;
cout<<"*********************** STREAM PREDICTOR ***********************"<<endl;
cout<<"1.Science stream\n2.Commerce stream\n3.Humanities\n";
cout<<"****************************************************************"<<endl;
cout<<"\nEnter the stream you want";
cin>>ch;
cout<<"\nEnter your class 10 percentage";
cin>>per;
switch(ch)
{
case 1:
{
if(per>=90)
cout<<"\n\nCONGRATS!!! You are eligible for the stream";
else
cout<<"\n\nSORRY!!! You are not eligible";
}
break;
case 2:
{
if(per>=80)
cout<<"\n\nCONGRATS!!! You are eligible for the stream";
else
cout<<"\n\nSORRY!!! You are not eligible";
}
break;
case 3:
{
if(per>=70)
cout<<"\n\nCONGRATS!!! You are eligible for the stream";
else
cout<<"\n\nSORRY!!! You are not eligible";
}
break;
default:
cout<<"invalid choice";
}
cout<<"\n\nEnter *m* to go back to student mainmenu"<<endl;
cin>>a;
if(a=='m')
s.studentmenu();
else
{
do
{
cout<<"INVALID INPUT! Enter *m* to go back to student main menu"<<endl;
cin>>a;
}
while(a!='m');
s.studentmenu();
}
}


void teacher::teachermenu()
{
clrscr();
int ch;
cout<<"=======================TEACHER MAIN MENU======================"<<endl;
cout<<"\n\n";
cout<<"1.New teacher record\n2.Edit existing teacher record\n3.Delete teacher record\n4.Display desired teacher record\n5.Display all records\n6.Back to main menu\n\n";
cout<<"=============================================================="<<endl;
cout<<"\nPlease enter your choice:"<<endl;
cin>>ch;
switch(ch)
{
   case 1:
	t.newrecord();
	break;
   case 2:
	t.modify();
	break;
   case 3:
	 t.del();
	 break;
   case 4:
	t.display();
	break;
   case 5:
	t.displayall();
	break;
   case 6:
	mainmenu();
	break;
   default:
	cout<<"SORRY!Invalid choice.Try again"<<endl;
	t.teachermenu();
	break;
   }

}


void teacher::newrecord()
{
clrscr();
char ch;
char a;
cout<<"******************* ENTER TEACHER DATA *******************"<<endl;
fstream x("teacher.dat",ios::out|ios::binary);
do
{
treadrecord();
x.write((char*)&t,sizeof(t));
cout<<"Any more records?(y/n)\n";
cin>>ch;
}
while(ch=='y'||ch=='Y');
x.close();
t.teachermenu();
}


void teacher::treadrecord()
{
cout<<endl;
cout<<"\nEnrollno:";
cin>>t.enrollno;
cout<<"\nName:";
gets(t.name);
cout<<"\nAge:";
cin>>t.age;
cout<<"\nD.O.B:";
gets(t.dob);
cout<<"\nSex(M/F):";
cin>>t.sex;
cout<<"\nBlood grp:";
gets(t.bgrp);
cout<<"\nQualification:";
gets(t.qual);
cout<<"\nExperience:";
cin>>t.exp;
cout<<"\nDepartment:";
gets(t.dept);
cout<<"\nPhone no:";
cin>>t.phno;
}


void teacher::modify()
{
clrscr();
int c,i=0,r=0;
char a;
fstream x("teacher.dat",ios::in|ios::out|ios::binary);
if(!x)
cout<<"\nFile does not exist"<<endl;
else
{
cout<<"***************** TEACHER DATA MODIFICATION *****************"<<endl;
cout<<"\n\nEnter the teacher enrollno to be modified:";
cin>>c;
while(x.read((char*)&t,sizeof(t)))
{
r++;
if(t.enrollno==c)
{
i++;
cout<<"\n\nEnter the new values:\n";
treadrecord();
x.seekp((r-1)*sizeof(t),ios::beg);
x.write((char*)&t,sizeof(t));
}
}
}
x.close();
if(i==0)
 cout<<"\nSORRY!RECORD DOES NOT EXIST";
else
 cout<<"\nSUCCESS!RECORD IS UPDATED";
cout<<endl;
cout<<"Enter *m* to go back to teacher mainmenu"<<endl;
cin>>a;
if(a=='m')
t.teachermenu();
else
{
do
{
cout<<"INVALID INPUT! Enter *m* to go back to teacher mainmenu"<<endl;
cin>>a;
}
while(a!='m');
t.teachermenu();
}
}


void teacher::del()
{
clrscr();
char a;
int eno,flag=0;
fstream x,y;
x.open("teacher.dat",ios::in|ios::binary);
y.open("tempo.dat",ios::out|ios::binary);
cout<<"************************ DATA DELETION ***********************"<<endl;
cout<<"\nEnter the teacher enrollno to be deleted";
cin>>eno;
while(!x.eof())
{
x.read((char*)&t,sizeof(t));
if(t.enrollno==eno)
flag=1;
else
y.write((char*)&t,sizeof(t));
}
x.close();
y.close();
remove("teacher.dat");
rename("tempo.dat","teacher.dat");
if (flag==0)
cout<<"SORRY! RECORD NOT FOUND";
else
cout<<"SUCCESS!RECORD IS DELETED";
cout<<endl;
cout<<"Enter *m* to go back to teacher mainmenu"<<endl;
cin>>a;
if(a=='m')
t.teachermenu();
else
{
do
{
cout<<"INVALID CHOICE! Enter *m* to go back to teacher mainmenu"<<endl;
cin>>a;
}
while(a!='m');
t.teachermenu();
}
}

void teacher::displayall()
{
clrscr();
char a;
fstream x("teacher.dat",ios::in|ios::binary);
if(!x)
cout<<"\n File does not exist"<<endl;
else
{
cout<<"************************** TEACHER RECORDS **************************** "<<endl;
cout<<"E.NO"<<"\t"<<"NAME"<<"\t\t"<<"AGE"<<"\t\t"<<"SEX"<<"\t"<<"DEPT"<<"\t\t"<<endl;
while(x.read((char*)&t,sizeof(t)))
cout<<t.enrollno<<"\t"<<t.name<<"\t\t"<<t.age<<"\t\t"<<t.sex<<"\t"<<t.dept<<"\t\t"<<endl;
}
cout<<"************************************************************************"<<endl;
x.close();
cout<<"\n\nEnter *m* to go back to mainmenu"<<endl;
cin>>a;
if(a=='m')
t.teachermenu();
else
{
do
{
cout<<"INAVLID INPUT! ENTER *m* to go back to mainmenu"<<endl;
cin>>a;
}
while(a!='m');
t.teachermenu();
}
}

void teacher::display()
{
clrscr();
int a;
char r;
int flag=0;
cout<<"Enter the enrollno of the teacher record to be displayed"<<endl;
cin>>a;
fstream x("teacher.dat",ios::in|ios::binary);
while(x.read((char*)&t,sizeof(t)))
{
if(a==t.enrollno)
{
cout<<"************************* TEACHER DETAILS ************************"<<endl;
cout<<"\n          E.NO          :"<<t.enrollno;
cout<<"\n          NAME          :"<<t.name;
cout<<"\n          DOB           :"<<t.dob;
cout<<"\n          SEX           :"<<t.sex;
cout<<"\n          AGE           :"<<t.age;
cout<<"\n          BLOOD GROUP   :"<<t.bgrp;
cout<<"\n          DEPARTMENT    :"<<t.dept;
cout<<"\n          EXPERIENCE    :"<<t.exp;
cout<<"\n          QUALIFICATION :"<<t.qual;
cout<<"\n          PHONE NO      :"<<t.phno;
flag=1;
}
}
if(flag==0)
cout<<"SORRY!RECORD NOT FOUND"<<endl;
x.close();
cout<<"\n\nEnter *m* to go back to mainmenu"<<endl;
cin>>r;
if(r=='m')
t.teachermenu();
else
{
do
{
cout<<"INALID INPUT! Enter *m* to go back to mainmenu";
cin>>r;
}
while(a!='m');
t.teachermenu();
}
}

void student::helpmenu()
{
clrscr();
char a;
cout<<"\n\n\n";
cout<<"*************** This Software is designed for aiding schools in ***************"<<endl;
cout<<"*************** keepingand maintaining records and files of the ***************"<<endl;
cout<<"*************** students and teachers of the respective school. ***************"<<endl;
cout<<"*************** This software is interactive and menu driven    ***************"<<endl;
cout<<endl;
cout<<endl;
cout<<"           To toggle between menus,Enter *m* and press the Enter Key                       "<<endl;
cout<<"enter *m* to go back to mainmenu"<<endl;
cin>>a;
if(a=='m')
mainmenu();
else
{
do
{
cout<<"Invalid Input! Enter *m* to go back to main menu"<<endl;
cin>>a;
}
while(a!='m');
mainmenu();
}
}

void student::credits()
{
	clrscr();
	cout<<"This program was coded by Shreya Kannan in the year 2017 in TURBO C++";
	cout<<"\n\nEnter *m* to go back to mainmenu"<<endl;
cin>>r;
if(r=='m')
mainmenu();
else
{
do
{
cout<<"INALID INPUT! Enter *m* to go back to mainmenu";
cin>>r;
}
while(a!='m');
mainmenu();
}
}


void main()
{
clrscr();
student s;
teacher t;
intropage();
getch();
}

