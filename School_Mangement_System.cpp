 //@uthor MUBASHIR ALI //
//@Develpoing Furm TECHABBOTT//
//***************************************************************
//                   HEADER FILES USED IN PROJECT
//****************************************************************
#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
using namespace std;
//**********************************************************************************************//
//****************************gotoxyFUnction***************************************************//
//**********************************************************************************************//
void gotoxy(int x,int y)
{
COORD c;
c.X=x;
c.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);	
};
//*********************************************************************************************//
//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************
class Staff
{
char CNIC[20];
char id[15];
char E_mail[25];
char name[20];
char Father_Name[20];
int M,Y,D;
char bloodGroup[15];
char Qualification[25];
char Designation[25];
char serves[15];
long double Pay;
char Adress[35];
char ContactNo[20];
public:
	
	Staff()
	{ 

	strcpy(name,"no name");
	strcpy(Father_Name,"no name");
	strcpy(Adress,"No Adress");
	strcpy(E_mail,"0");
	Pay=0.0;
	M=0;
	D=0;
	Y=0;
	CNIC[0]=0;
	strcpy(id,"no id");
	}
void Get_Info();
void show_Info();
int store_Record();
void Search_CNIC(char* );
void Search_Name(char* );
void Delete(char* );
void update_Record(char *);
void Show_All();
void copyright();
char* getname()
{
return name;	
}
char* get_Contact()
{
return ContactNo;	
} 
char* getQualification()
{
	return Qualification;
}
char* get_Cnic()
{
return CNIC;
}	
};



//-----------------------------Staff Class End Here---------------------------------------//
//-----------------------------Funcations Definations------------------------------------//




void Staff::Get_Info()
{	system("cls");
	cout<<"\t\t\t  ---------------------\n";
	cout<<"\t\t\t    STAFF INFORMATION   \n";
	cout<<"\t\t\t  ---------------------";
	cout<<"\n";
	cout<<"\n\tEnter Your Empolyee Number:            " ;   cin.getline(id,19);
	cout<<"\n\tEnter Your National Identity Card No:  " ;	cin.getline(CNIC,19);
	cout<<"\n\tEnter Your Name:                       " ;	cin.getline(name,19);
	cout<<"\n\tEnter Your Father Name:                " ;	cin.getline(Father_Name,19);
	cout<<"\n\tEnter Your Qualifciation:              " ;	cin.getline(Qualification,24);
	cout<<"\n\tEnter Your Date Of Birth:              " ;
	cout<<"\n\tDate:                                  "	;   cin>>D;
	cout<<"\n\tMonth:                                 "	;   cin>>M;
	cout<<"\n\tYear:                                  " ;	cin>>Y;
 	cin.ignore();
	cout<<"\n\tEnter Your Blood Group:                " ;    cin.getline(bloodGroup,14);
	cout<<"\n\tEnter Your Current Designation:        " ; 	cin.getline(Designation,24);
	cout<<"\n\tEnter Your Number of Serves:           " ;    cin.getline(serves,14);
	cout<<"\n\tEnter Your Current Pay:                " ;	cin>>Pay;
	cin.ignore();
	cout<<"\n\tEnter Your Valid Contact No:           " ;	cin.getline(ContactNo,19);
	cout<<"\n\tEnter Your Email:                      " ;	cin.getline(E_mail,24);
	cout<<"\n\tEnter Your Adress:                     " ;	cin.getline(Adress,34);
	cout<<"\n";
	getch();
	
	
		
}
void Staff::show_Info()

{	system("cls");
	system("color 11");
	cout<<"\n";
	Sleep(500);
	int i =0;
	int size=0;
	char Heading[]=" \t\t\t    STAFF INFORMATION\n";
	size=strlen(Heading);
	cout<<"\t\t\t  ---------------------\n";
		for(i=0;i<size;i++)
		{
		Sleep(20);
		cout<<Heading[i];	
		}	
	cout<<"\t\t\t  ---------------------\n";
	cout<<"                "<<"NAME:-                      "<<setw(20)<<name<<endl;
	cout<<"                "<<"FATHER NAME:-               "<<setw(20)<<Father_Name<<endl;
	cout<<"                "<<"NIC:-                       "<<setw(20)<<CNIC<<endl;
	cout<<"                "<<"EMPOLYEE NUMBER:-           "<<setw(20)<<id<<endl;
	cout<<"                "<<"EDUCATION:-                 "<<setw(20)<<Qualification<<endl;
	cout<<"                "<<"DESIGNATION:-               "<<setw(20)<<Designation<<endl;
	cout<<"                "<<"SERVES:-                    "<<setw(15)<<serves<<"YEARS"<<endl;
	cout<<"                "<<"BLOOD GROUP:-               "<<setw(20)<<bloodGroup<<endl;
	cout<<"                "<<"CURRENT PAY:-               "<<setw(15)<<"PKR "<<Pay<<"/-"<<endl;
	cout<<"                "<<"DATE OF BIRTH:-             "<<setw(13)<<D<<"/"<<M<<"/"<<Y<<endl;
	cout<<"                "<<"CONTACT NO :-               "<<setw(20)<<ContactNo<<endl;
	cout<<"                "<<"E-MAIL:-                    "<<setw(20)<<E_mail<<endl;
	cout<<"                "<<"ADDRESS:-                   "<<setw(20)<<Adress<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;

}
int Staff::store_Record()
{
	if(Pay ==0 && CNIC ==0 && name=="no mame" && id =="0")
{
		cout<<"Your Data is Not Initialized"<<endl;
		return (0);
}
else 
{	
ofstream fin;
fin.open("School.dat",ios::app|ios::binary);
fin.write((char*)this,sizeof(*this));
cout<<"\n\n\n\n\n\n\n\n"<<endl;
cout<<"\t\t\t---------------------------------------------"<<endl;
cout<<"\t\t\t"<<" Record Store Successfully into Database"<<endl;
cout<<"\t\t\t---------------------------------------------"<<endl;

return (1);
fin.close();	
}
}
void Staff::Show_All()
{
ifstream fout;
fout.open("School.dat",ios::in|ios::binary);
if(!fout)
{
	cout<<"\t\t\tFile Not Exist"<<endl;
}
while(!fout.eof())
{
	
	fout.read((char*)this,sizeof(*this));
	show_Info();
	getch();
		
}			
fout.read((char*)this,sizeof(*this));	
			//cout<<"\t\t\t\t\t\t\t\t-----------"<<endl;
			//co/ut<<"\t\t\t\t\t\t\t\t TECHABBOTT"<<endl;
			//cout<<"\t\t\t\t\t\t\t\t-----------"<<endl;	
fout.close();	
}
//cout<<"Enter the Name"<<endl;
//cin.getline(k,19);
void Staff::Search_CNIC(char* k)
{
int flag=0;
ifstream fin;
fin.open("School.dat",ios::in|ios::binary);
if(!fin)
{
	cout<<"\t\t\tFile Not Found"<<endl;
}
else 
{
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(!strcmp(get_Cnic(),k))
		{
		show_Info();
		flag=1;
		cout<<"\t\t\t\t\t\t\t\t-----------"<<endl;
		cout<<"\t\t\t\t\t\t\t\t AbbottTech"<<endl;
		cout<<"\t\t\t\t\t\t\t\t-----------"<<endl;

		}
		fin.read((char*) this ,sizeof(*this));
	}
	if(flag==0)
	{	system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t--------------------"<<endl;
		cout<<"\t\t\t\tRecord Doesn't Exist"<<endl;
		cout<<"\t\t\t\t--------------------"<<endl;
	}
	fin.close();
	getch();
}
	
	
}
void Staff::Search_Name(char* N)
{
int flag=0;
ifstream fin;
fin.open("School.dat",ios::in|ios::binary);
if(!fin)
{
cout<<"File Doesn't Exist"<<endl;	
}
else
{	
	while(fin.read((char*) this,sizeof(*this)))
	{
		if(strcmp(getname(),N)==0)
		{
			show_Info();
			getch();
			flag=1;
			cout<<"\t\t\t\t\t\t\t\t-----------"<<endl;
			cout<<"\t\t\t\t\t\t\t\t AbbottTech"<<endl;
			cout<<"\t\t\t\t\t\t\t\t-----------"<<endl;
		}
	}
	//fin.read((char*)this,sizeof(*this));
	if(flag==0)
	{	system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t --------------------"<<endl;
		cout<<"\t\t\t\t Record Doesn't Exist"<<endl;
		cout<<"\t\t\t\t --------------------"<<endl;

	}
	fin.close();
	getch();
}	
	
}
//************************************************DELETE FUNCTION*****************************************************//
void Staff::Delete (char * k)
{
	int flag =0;
	ifstream fin;
	ofstream fout;
	fin.open("School.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t--------------------"<<endl;
		cout<<"\t\t\t\tFile Doesn't Exist"<<endl;
		cout<<"\t\t\t\t--------------------"<<endl;	
	}
	else 
	{
		fout.open("Tempfile.dat",ios::out|ios::binary);
		fin.read((char*) this ,sizeof(*this));
		while(!fin.eof())
		{
			if(strcmp(getname(),k))
			fout.write((char*) this ,sizeof(*this));
			fin.read((char*) this ,sizeof(*this));
			flag =1;			
		}
		fin.close();
		fout.close();
		remove("School.dat");
		rename("Tempfile.dat","School.dat");
		
		if(flag==1)
		{
		system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------------"<<endl;
		cout<<"\t\t\tRecord Delete Successfully"<<endl;
		cout<<"\t\t\t--------------------------"<<endl;
		}
		else
		{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------"<<endl;
		cout<<"\t\t\tRecord Doesn't Exist"<<endl;
		cout<<"\t\t\t--------------------"<<endl;
		}
		getche();
		
	}
	
}
void Staff::update_Record(char *k)
{
int flag =0;
fstream file;
file.open("School.dat",ios::in|ios::out|ios::ate|ios::binary);
if(!file)
{		
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------"<<endl;
		cout<<"\t\t\t File  Doesn't Exist"<<endl;
		cout<<"\t\t\t--------------------"<<endl;
}
file.seekg(0);
file.read((char*) this ,sizeof(*this));
while(!file.eof())
{
	if(!strcmp(k,get_Cnic()))
	{
		Get_Info();
		show_Info();
		file.seekp(file.tellp()-sizeof(*this));
		file.write((char*) this ,sizeof(*this));
		flag++;
		system("cls");
		system("color 47");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t--------------------"<<endl;
		cout<<"\t\t\t\t   Record Updated   "<<endl;
		cout<<"\t\t\t\t--------------------"<<endl;
		
	}
	file.read((char*) this ,sizeof(*this));
	
	
}
if(flag==0)
{		system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------"<<endl;
		cout<<"\t\t\tRecord Doesn't Exist"<<endl;
		cout<<"\t\t\t--------------------"<<endl;
}
file.close();
	
}
//*************************************************************************************************//
//*********************************INTRODUCTION-FUNCTION****************************************************//
//*************************************************************************************************//
void Starting()
{
char Main_Logo[]="\n\n\n\n\n\n\n\n\t\t\t\t-----------------\n\t\t\t\t  \4TECHABBOTT\4\n\t\t\t\t-----------------\n\n\n\n\n\n\t\t\t\t\t------------------------------------\n\t\t\t\t\t   PROVIDING DOOR STEP SOLUTIONS\n\t\t\t\t\t------------------------------------\n";
int size=strlen(Main_Logo);
int i;
for(i=0;i<size;i++)
{
	Sleep(10);
	cout<<Main_Logo[i];
}
	getche();
	system("cls");

}
void EndFunction()
{
		
char Main_Logo[]="\n\n\n\n\n\n\n\n\t\t\t\t-----------------\n\t\t\t\t  \4THANK YOU\4\n\t\t\t\t-----------------\n\n\n\n\n\n\t\t\t\t\t------------------------------------\n\t\t\t\t\t   FOR USING THIS APPLICATION\n\t\t\t\t\t------------------------------------\n";
int size=strlen(Main_Logo);
int i;
for(i=0;i<size;i++)
{
	Sleep(10);
	cout<<Main_Logo[i];
}
	getche();
	system("cls");
	
	
	
	
	
	
	
	
	
	
}
void Instructions()
{
		char CLine[]="\t\4 THIS PROJECT IS COMPLETED  UNDER SUPERVISION  OF TECHABBOTT  FOR\n\n\t\t\tGOVT SCHOOL  NO 3 ABBOTTABAD \4";
	int i=0;
	int size;
	size=strlen(CLine);
	system("color 2");
	cout<<"\t\t\t\t-----------"<<endl;
	cout<<"\t\t\t\t\4TECHABBOTT\4"<<endl;
	cout<<"\t\t\t\t-----------"<<endl;
	cout<<"\n\n\n\n\n\n\n\n";
	Sleep(500);
	for(i=0;i<size;i++)
	{	Sleep(20);
		cout<<CLine[i];
	}
	getch();
	system("cls");
	system("color 2");
	cout<<"\t\t\t\t-----------"<<endl;
	cout<<"\t\t\t\t\4TECHABBOTT\4"<<endl;
	cout<<"\t\t\t\t-----------"<<endl;
	int I=0;
	int siZE;	
	char Inst[]="\tPLEASE FOLLOW THESE INSTRUCTION FOR USING THIS PROJECT \n\n \t1:-Please Make Sure to keep RollNo As Unique Id Of Student\n \t2:-We Proposed You To Use this Formate For Roll Numberng\n \t3:-Roll Formate:-RollNo-Class-Section\n \t4:-EI=8TH,SE=7TH,SI=6TH As Class Code\n \t5:-Sections Code Are Here.......... \n \t6:-Green=G,Yellow=Y;Blue=B,Pink=P\n \t7:-RollNo Example:1-EI-G\n \t8:-Above Statment Means That a Student having\n  \t9:-RollNo 1 From Class 8th And his Section is Greem\n \t10:-Fail Subject Is Treated as Fail And Not Count in Total Marks\n \t11:-Use UpperCase Letters";
	siZE=strlen(Inst);
	for(I=0;I<siZE;I++)
	{
		Sleep(10);
		cout<<Inst[I];
	}
	cout<<"\n";
																							cout<<"\t\t\t\t\t\t\t\t-----------"<<endl;
																							cout<<"\t\t\t\t\t\t\t\t   ADMIN   "<<endl;
																							cout<<"\t\t\t\t\t\t\t\t-----------"<<endl;
	cout<<"----------------------------------------------------------------------------------"<<endl;
	cout<<endl;
	getch();
	system("cls");
}
//********************************************************************************************************//
//*************************************Security***********************************************************//
//********************************************************************************************************//
// ******************************************************************************************//
          //                  Student class                //
 		//                                                 //
// ******************************************************************************************//
 class Student
 {
  	private:
	
	char  RollNo[20];
	char name[30];
	char Father_Name[20];
	char Class [15];
	char Blood_G[15];
	char Gender[15];
	int M,D,Y;
	char Section[15];
	char Campus[20];
	char Remarks[20];
	char contact_No[20];
	char Adress[35];
	
	public:
		Student()
		{
			strcpy(RollNo,"0");
			strcpy(name,"Empty");
			strcpy(Father_Name,"Empty");
			strcpy(Class,"Empty");
			strcpy(Remarks,"Empty");
			strcpy(Section,"Empty");
			strcpy(Gender,"Empty");
			M=0;
			D=0;
			Y=0;
		}
		void Get_Information();
		void Show_Info();
		int store_Stu();
		void Show_all();
		void Find(char *T);
		void Find_Class(char *T);
		void Modify(char *T);
		void remove_info(char *T);
		char* get_name()
		{
			return name;
		}
		char* get_Class()
		{
			return Class;
		}
		char* get_rollno()
		{
			return RollNo;
		}
 };
 //***************************************************************
//                   STUDENT CLASS END HERER
//****************************************************************
//********************************************************************************************************//
//**************************************GLOBAL OBJECTS****************************************************//

Student Std;
Staff Stf;

//********************************************************************************************************//
 void Student::Get_Information()
 {	system("cls");
	cout<<"\t\t\t  ---------------------\n";
	cout<<"\t\t\t    STUDENT INFORMATION   \n";
	cout<<"\t\t\t  ---------------------";
	cout<<"\n";
	cout<<"\tEnter Your RollNo"<<endl;
	cin.getline(RollNo,19);
	cin.ignore();
	cout<<"Enter Your Name"<<endl;
	cin.getline(name,29);
	cin.ignore();
	cout<<"Enter Your Father Name"<<endl;
	cin.getline(Father_Name,19);
	cin.ignore();
	cout<<"Enter Your Current Class"<<endl;
	cin.getline(Class,14);
	cin.ignore();
	cout<<"Enter Your Section"<<endl;
	cin.getline(Section,14);
	cin.ignore();
	cout<<"Enter Your Blood Group"<<endl;
	cin.getline(Blood_G,14);
	cout<<"Enter Your Gender"<<endl;
	cin.getline(Gender,14);
	cout<<"Enter Your Age(M,D,Y)"<<endl;
	cin>>M>>D>>Y;
	cin.ignore();
	cout<<"Principal Remarks "<<endl;
	cin.getline(Remarks,19);
	cout<<"Enter Your Campus Detiles"<<endl;
	cin.getline(Campus,19);
	cout<<"Enter Your Valid Contact Number"<<endl;
	cin.getline(contact_No,19);
	cout<<"Enter Your Address"<<endl;
	cin.getline(Adress,34);
	cout<<"\n\n";
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;

	 
 }
 void Student::Show_Info()
 {
 	
	system("cls");
	system("color 11");
	cout<<"\t\t\t\t---------------------\n";
	cout<<"\t\t\t\t  STAFF INFORMATION   \n";
	cout<<"\t\t\t\t---------------------"<<endl;
	cout<<"\n\n"<<endl;
	cout<<"                "<<"Name:-                             "<<setw(20)<<name<<endl;
	cout<<"                "<<"Father Name:-                      "<<setw(20)<<Father_Name<<endl;
	cout<<"                "<<"RollNo:-                           "<<setw(20)<<RollNo<<endl;
	cout<<"                "<<"Class:-                            "<<setw(18)<<Class<<"th"<<endl;
	cout<<"                "<<"Section:-                          "<<setw(20)<<Section<<endl;
	cout<<"                "<<"Campus:-                           "<<setw(20)<<Campus<<endl;
	cout<<"                "<<"Blood Group:-                      "<<setw(20)<<Blood_G<<endl;
	cout<<"                "<<"Gender:-                           "<<setw(20)<<Gender<<endl;
	cout<<"                "<<"Date Of Birth:-                 "<<setw(16)<<D<<"/"<<M<<"/"<<Y<<endl;
	cout<<"                "<<"Conatact No:-                      "<<setw(20)<<contact_No<<endl;
	cout<<"                "<<"Principal Remarks:-                "<<setw(20)<<Remarks<<endl;
	cout<<"                "<<"Adress:-                           "<<setw(20)<<Adress<<endl;
	cout<<"--------------------------------------------------------------------------------";
	cout<<"--------------------------------------------------------------------------------";
 	
 }
 int Student::store_Stu()
 {
 	if(RollNo ==0 && M ==0)
 	{
 		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------"<<endl;
		cout<<"\t\t\tRecord Not Stored Due To initialization Issues"<<endl;
		cout<<"\t\t\t--------------------"<<endl;
		return 0;
	 
	}
	else
	{
	ofstream fout;
	fout.open("SMS_Student.dat",ios::app|ios::binary);
	fout.write((char*) this ,sizeof(*this));
	getch();
	char set[]="\t\t\t---------------------------------------------\n\t\t\tRecord Store Successfully into Database\n\t\t\t---------------------------------------------\n";
	int size=strlen(set);
	int i;
	for(i=0;i<size;i++)
	{
		Sleep(20);
		cout<<set[i]; 
	}
	return 1;	
	fout.close();	
	}
 	
 	
 	
 }
 void Student::Show_all()
 {
	ifstream fout;
	fout.open("SMS_Student.dat",ios::in|ios::binary);
	if(!fout)
	{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------"<<endl;
		cout<<"\t\t\tFile Doesn't Exist"<<endl;
		cout<<"\t\t\t--------------------"<<endl;
	}
	else
	{
	while(!fout.eof())
	{
		
	fout.read((char*) this ,sizeof(*this));
	Show_Info();
	getch();
	}
	fout.read((char*) this ,sizeof(*this));
	char Logo[]="\t\t\t\t\t\t\t\t-----------\n\t\t\t\t\t\tTECHABBOTT\n\t\t\t\t\t\t\t\t-----------";
		 int size=strlen(Logo);
		 for(int i=0;i<size;i++)
		 {
		 	
		 	Sleep(20);
		 	cout<<Logo[i];
		 	
		 }
	fout.close();
	        }                          //  cout<<"\t\t\t\t\t\t\t\t-----------"<<endl;
			                            //cout<<"\t\t\t\t\t\t\t\t TECHABBOTT"<<endl;
			                        	//cout<<"\t\t\t\t\t\t\t\t-----------"<<endl;	
 }
 void Student::Find(char *T)
 {
 int flag =0;
 ifstream fin;
 fin.open("SMS_Student.dat",ios::in|ios::binary);
 if(!fin)
 {
 		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------"<<endl;
		cout<<"\t\t\tFile Not Exist"<<endl;
		cout<<"\t\t\t--------------------"<<endl;
 
 }	
 	while(fin.read((char*) this ,sizeof(*this)));
 	{
	 
 	if(!strcmp(get_name(),T))
 	{
 		Show_Info();
 				 flag=1;								
	char Logo[]="\t\t\t\t\t\t\t\t----------- \t\t\t\t\t\tTECHABBOTT\n\t\t\t\t\t\t\t\t-----------";
		 int size=strlen(Logo);
		 for(int i=0;i<size;i++)
		 {
		 	
		 	Sleep(20);
		 	cout<<Logo[i];
		 	
		 }
	 
	}	//fin.read((char*) this ,sizeof(*this));
 	if(flag==0)
	{	
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t --------------------"<<endl;
		cout<<"\t\t\t\t Record Doesn't Exist"<<endl;
		cout<<"\t\t\t\t --------------------"<<endl;

	}
	fin.close();
	getch();
 }	
 }
  void Student::Find_Class(char *T)
 {
 int flag =0;
 ifstream fin;
 fin.open("SMS_Student.dat",ios::in|ios::binary);
 if(!fin)
 {
 		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------"<<endl;
		cout<<"\t\t\tFile Not Exist"<<endl;
		cout<<"\t\t\t--------------------"<<endl;
 
 }	
 else
 {
 	fin.read((char*) this ,sizeof(*this));
 	if(!strcmp(get_rollno(),T))
 	{
 		Show_Info();
		 flag=1;
		 char Logo[]="\t\t\t\t\t\t\t\t-----------\n\t\t\t\t\t\tTECHABBOTT\n\t\t\t\t\t\t\t\t-----------";
		 int size=strlen(Logo);
		 for(int i=0;i<size;i++)
		 {
		 	
		 	Sleep(20);
		 	cout<<Logo[i];
		 	
		 }
			                        
			                       								
		 																		
		 					
	 
	}
	fin.read((char*) this ,sizeof(*this));
 	if(flag==0)
	{	
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t --------------------"<<endl;
		cout<<"\t\t\t\t Record Doesn't Exist"<<endl;
		cout<<"\t\t\t\t --------------------"<<endl;

	}
	fin.close();
	getch();
 }	
 }
 void Student::Modify(char *T)
 {
 int flag=0;
 fstream file;
 file.open("SMS_Student.dat",ios::in|ios::out|ios::ate|ios::binary);
 if(!file)	
 {		
 		system("cls");
 		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t-------------------"<<endl;
		cout<<"\t\t\t\t   File Not Exist  "<<endl;
		cout<<"\t\t\t\t-------------------"<<endl;
			
 }
 file.seekg(0);
 file.read((char*) this ,sizeof(*this));
  while(!file.eof())
  {
	if(!strcmp(get_name(),T))
	{
		Get_Information();
		Show_Info();
		file.seekp(file.tellg()-sizeof(*this));
		file.write((char*) this ,sizeof(*this));
		flag++;
		system("cls");
		system("color 47");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t\t  --------------------"<<endl;
		cout<<"\t\t\t\t\t     Record Updated   "<<endl;
		cout<<"\t\t\t\t\t  --------------------"<<endl;
			
	}
	file.read((char*) this ,sizeof(*this));
  }
  if(flag==0)
  {
  		getch();
  		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------"<<endl;
		cout<<"\t\t\tRecord Doesn't Exist"<<endl;
		cout<<"\t\t\t--------------------"<<endl;
  	
  	
  }
  file.close();
 	
  }
void Student::remove_info(char *T)
{
int flag=0;
ifstream fin;
ofstream fout;
fin.open("SMS_Student.dat",ios::in|ios::binary);
if(!fin)
	{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t--------------------"<<endl;
		cout<<"\t\t\t\tFile Doesn't Exist"<<endl;
		cout<<"\t\t\t\t--------------------"<<endl;	
	}
else
{ 
  fout.open("TempFile.dat",ios::out|ios::binary);
  fin.read((char*) this ,sizeof(*this));
  while(!fin.eof())
  {
  	if(strcmp(get_name(),T))
  	fout.write((char*) this ,sizeof(*this));
  	fin.read((char*) this ,sizeof(*this));
  	flag++;	
  }
  fin.close();
  fout.close();
  remove("SMS_Student.dat");
  rename("TempFile.dat" ,"SMS_Student.dat");		
if(flag==1)
		{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------------"<<endl;
		cout<<"\t\t\tRecord Delete Successfully"<<endl;
		cout<<"\t\t\t--------------------------"<<endl;
		}
		else
		{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------"<<endl;
		cout<<"\t\t\tRecord Doesn't Exist"<<endl;
		cout<<"\t\t\t--------------------"<<endl;
		}
		getche();
}	
}
void Student_Menu()
{   system("cls");
	int choice;
	Sleep(500);
	int i =0;
	int size=0;
	char Heading[]="\t\t\t  STUDENT PANEL";
	size=strlen(Heading);
	system("cls");
	{
	}
	cout<<"\t\t\t--------------------"<<endl;
	for(i=0;i<=size;i++)
	{
		Sleep(10);
		cout<<Heading[i];
		
		
	}
	cout<<"\n";
	cout<<"\t\t\t--------------------"<<endl;
	int sIZE;
	int I;
	Sleep(500);
	char H6[]="\n\n\t\t\t1:DISPLAY ALL STUDENTS RECORD	\n\n\t\t\t2:SEARCH  STUDENT RECORD BY NAME \n\n\t\t\t3:SEARCH  STUDENT RECORD BY ROLLNO \n\n\t\t\t4:MODIFY STUDENT RECORD  \n\n\t\t\t5:DELETE STUDENT RECORD  \n\n\t\t\t6:BACK TO MAIN MENU"; 
	sIZE=strlen(H6);
	for(I=0;I<sIZE;I++)
	{
		Sleep(5);
		cout<<H6[I];
	}
	cout<<"\n";
	cout<<"\n\n\t\t\tPLEASE ENTER YOUR CHOICE(1-6)\n"<<endl;
	gotoxy(24,20);
	cin>>choice;
	switch(choice)
	{
		case 1:
		Std.Show_all();
		break;
		case 2:
		{
		char Sname[20];
		cout<<"\t\t\tENTER YOUR NAME:"<<endl;
		gotoxy(24,22);
		cin.ignore();
		cin.getline(Sname,19);
		Std.Find(Sname);	
		break;
		}	
		case 3:
		char Sroll[20];
		cout<<"\t\t\tENTER YOUR ROLLNO:"<<endl;
		gotoxy(24,22);
		cin.ignore();
		cin.getline(Sroll,19);
		Std.Find(Sroll);
		break;
		case 4:
		{
		char Name[20];
		cout<<"\t\t\tENTER  NAME FOR UPDATING"<<endl;
		gotoxy(24,22);
		cin.ignore();
		cin.getline(Name,19);
		Std.Modify(Name);
		break;	
		}
		case 5:
		{
		char NaMe[20];
		cout<<"\t\t\tENTER NAME ROLLNO FOR DELETING"<<endl;
		gotoxy(24,22);
		cin.ignore();
		cin.getline(NaMe,19);
		break;			
		}
		case 6:
		return;	
		default:
			cout<<"INVALID choice"<<endl;	
	}
	Student_Menu();
	
//	cout<<"--------------------------------------------------------------------------------"<<endl;
//	getch();
//	system("cls");
}



void  Staff_Menu()
{
	
	
	int Choice;
	int i =0;
	int size=0;
	char Heading[]="\t\t\t    STAFF PANEL   ";
	size=strlen(Heading);
	system("cls");
	{
	}
	cout<<"\t\t\t--------------------"<<endl;
	for(i=0;i<=size;i++)
	{
		Sleep(10);
		cout<<Heading[i];
		
		
	}
	cout<<"\n";
	cout<<"\t\t\t--------------------"<<endl;
	
	cout<<"\n\t\t\t1:DISPLAY ALL EMPOLYEES RECORD	\n\n\t\t\t2:SEARCH EMPOLYEES RECORD BY NIC\n\n \t\t\t3:SEARCH EMPOLYEES RECORD BY NAME \n\n\t\t\t4:MODIFY EMPOLYEES RECORD  \n\n\t\t\t5:DELETE EMPOLYEE RECORD  \n\n\t\t\t6:BACK TO MAIN MENU \n"<<endl; 
	cout<<"\t\t\tPLEASE ENTER YOUR CHOICE(1-6)\n";
	gotoxy(24,19);
	cin>>Choice;
	switch(Choice)
	{
	case 1:
		system("cls");
		Stf.Show_All();
		break;
	case 2:
		
		{char Nic[20];
	//	system("cls");
		cout<<"\t\t\tENTER YOUR NIC:"<<endl;
		gotoxy(24,21);
		cin.ignore();
		cin.getline(Nic,19);
		Stf.Search_CNIC(Nic);
		break;
		}
	case 3:
		//system("cls");
		{
		char sName[20];
		cout<<"\t\t\tENTER YOUR NAME:"<<endl;
		gotoxy(24,21);
		cin.ignore();
		cin.getline(sName,21);
		Stf.Search_Name(sName);
		//getch();
		break;}
	case 4:
		{
		char Snic[25];
		cout<<"\t\t\tENTER THE NIC FOR UPDATING"<<endl;
		gotoxy(24,21);
		cin.ignore();
		cin.getline(Snic,24);
		Stf.update_Record(Snic);
		break;}
	case 5:
		{
		char DRecord[25];
		cout<<"\t\t\tENTER THE NAME FOR DELETE RECORD"<<endl;
		gotoxy(24,21);
		cin.ignore();
		cin.getline(DRecord,24);
		Stf.Delete(DRecord);
		break;
		}
	case 6:
		return ;
	default:
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------"<<endl;
		cout<<"\t\t\tINVALID CHOICE"<<endl;
		cout<<"\t\t\t--------------------"<<endl;	
	}	
	 Staff_Menu();
}
//***************************************************************************************************************//
//***************************************Student Class End Here*************************************************//
//**************************************************************************************************************//	
int main ()
{
SetConsoleTitle("\t\t\tSCHOOL MANAGEMENT SYSTEM BY MUBASHIR ALI");
system("color 47");
Starting();
system("color 47");
system("cls");
while(1)
{
	
	int i =0;
	int size=0;
	char Heading[]="\t\t\t         MAIN MENU   ";
	size=strlen(Heading);
	system("cls");
	{
	}
	cout<<"\n\n\n\t\t\t   --------------------"<<endl;
	for(i=0;i<=size;i++)
	{
		Sleep(10);
		cout<<Heading[i];
		
		
	}
	cout<<"\n";
	cout<<"\t\t\t   --------------------"<<endl;
	int Choice;
	cout<<"\n\t\t\t   1:CREATE FACULITY RECORED"<<endl;
	cout<<"\n\t\t\t   2:CREATE STUDENT RECORED"<<endl;
	cout<<"\n\t\t\t   3:FACULITY SECTION"<<endl;
	cout<<"\n\t\t\t   4:STUDENT SECTION"<<endl;
	cout<<"\n\t\t\t   5:HOW TO USE     "<<endl;
	cout<<"\n\t\t\t   6:EXIT"<<endl;
	cout<<"\n\t\t\t   ENTER YOUR CHOICE(1-3)"<<endl;
	gotoxy(27,20);
	cin>>Choice;
	switch(Choice)
	{
		case 1:
		 {
		system("cls");
		cin.ignore();
		Stf.Get_Info();
		system("color 2");
		Stf.show_Info();
		Stf.store_Record();
		break;}
		//<--------------------------------------------------->//
	case 2:
			{
		Std.Get_Information();
     	Std.Show_Info();
   		Std.store_Stu();	
		break;
		}
		//<--------------------------------------------------->//
		case 3:
		system("cls");
		Staff_Menu();
		break;
		//<--------------------------------------------------->//
		case 4:
		system("cls");
		Student_Menu();
		break;
		//<--------------------------------------------------->//
		case 5:
		{
		system("cls");
		Instructions();		
		break;
		}
		//<--------------------------------------------------->//
		case 6:
		system("cls");
		EndFunction();
		exit(0);	
		break;
		//<--------------------------------------------------->//
		default:
			cout<<"INVALID CHOICE";	
	}
		
}
system("color CF");
getch();
return 0;		
}
