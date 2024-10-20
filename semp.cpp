#include<iostream>
#include<fstream>
using namespace std;
int a=0;
class department;
class university{
	private:
		string uni_name;
		int uni_id;
		friend class department;
		friend void display(university obj1,department obj2);
};
university u1;
class department:public university{
	private:
		string dept_name;
		int dept_id;
		friend void display(university obj1,department obj2);
	public:
		void input(university obj)
		{
			cout<<"\nenter university name : ";
			cin>>obj.uni_name;
			cout<<"enter university id : ";
			cin>>obj.uni_id;
			cout<<"enter department name : ";
			cin>>dept_name;
			cout<<"enter department id : ";
			cin>>dept_id;
			u1=obj;
		}
};
department d1;
void display(university obj1,department obj2)
{
	cout<<"\nuniversity name : "<<obj1.uni_name;
	cout<<"\nuniversity id : "<<obj1.uni_id;
	cout<<"\ndepartment name  :"<<obj2.dept_name;
	cout<<"\ndepartment id : "<<obj2.dept_id;
}
class student:public department{
	    private:
	    		string dept_name;
		        int dept_id;
		        string s_name;
		        string f_name;
		        int f_mobilenumber;
		        string gender;
		        string location;
		        int semester;
		        int s_roll_no;
		        int sr_no;
		        float gpa;
		        float cgpa;
		public:
			   void menu();
		       void student_menu();
		       void institute_menu();
		       void create_data();
		       void update_data();
		       void display_data();
		       void search_data();
		       void delete_data();
		       void hit_scholarship();
		       void top();
			   
};
void student::menu()
{
	int choice1=0;
	while(choice1!=3)
	{
		cout<<"\n\n\t\t\t\t*****MAIN MENU*****";
		cout<<"\npress 1 for student menu ";
		cout<<"\t\tpress 2 for institute menu";
		cout<<"\t\tpress 3 to exit\n";
		cin>>choice1;
		switch(choice1)
		{
			case 1:
				student_menu();
				break;
			case 2:
				institute_menu();
				break;
			case 3:
				cout<<"\n\n\t\t\t\tTHANK YOU";
				break;
			default:
				cout<<"\n\n\t\t\t\tINVALID OPTION";
		}
	}
}
void student::student_menu()
{
	int choice=0;
	while(choice!=8)
	{
	cout<<"\n\n\t\t\t\t*****MENU*****";
	cout<<"\n\npress 1 to enter new students data ";
	cout<<"\t\tpress 2 to update existing student data ";
	cout<<"\npress 3 to display all data ";
	cout<<"\t\t\tpress 4 to search for a specific student ";
	cout<<"\npress 5 to delete students data ";
	cout<<"\t\tpress 6 to search for hit employee scholarship eligibles";
	cout<<"\npress 7 to search for students ";
	cout<<"\t\t\tpress 8 to exit";
	cout<<"\nhaving gpa more than or equal to 3.5\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			create_data();
			break;
		case 2:
			update_data();
			break;
		case 3:
			display_data();
			break;
		case 4:
			search_data();
			break;
		case 5:
			delete_data();
			break;
		case 6:
			hit_scholarship();
			break;
		case 7:
			top();
			break;
	}
}
}
void student::institute_menu()
{
	int choice2=0;
	while(choice2!=3)
	{
		cout<<"\n\n\t\t\t\t*****INSTITUTE MENU*****";
		cout<<"\n\npress 1 to enter institute detail\t\tpress 2 to display institute detail\t\tpress 3 to exit\n";
		cin>>choice2;
		switch(choice2)
		{
			case 1:
				d1.input(u1);
				break;
			case 2:
				display(u1,d1);
				break;
			case 3:
				break;
			default:
				cout<<"\n\n\t\t\t\tINVALID OPTION!";
		}
	}
}
void student::create_data()
{
	int z=0;
    string t_f_name;
	int t_f_mobilenumber;
	string t_gender;
	string t_location;
	int t_semester;
	float t_gpa;
	float t_cgpa;
	int t_roll;
	string t_name;
	int t_sr=1;
	ifstream infile;
	ofstream outfile;
	cout<<"\n\n\t\t\t\t*****STUDENT DATA ENTRY PANEL*****";
	cout<<"\nenter student name : ";
	cin>>t_name;
	cout<<"enter student roll no : ";
	cin>>t_roll;
	cout<<"enter gender : ";
	cin>>t_gender;
	cout<<"enter location : ";
	cin>>t_location;
	cout<<"enter father's name : ";
	cin>>t_f_name;
	cout<<"enter father's mobile number : ";
	cin>>t_f_mobilenumber;
	cout<<"enter semester : ";
	cin>>t_semester;
	cout<<"enter gpa : ";
	cin>>gpa;
	cout<<"enter cgpa : ";
	cin>>t_cgpa;
	infile.open("khan.txt",ios::in);
	outfile.open("khan.txt",ios::out|ios::app);
	if(!infile)
	{
	sr_no=1;
	outfile<<t_sr<<" "<<t_name<<" "<<t_roll<<" "<<t_gender<<" "<<t_location<<" "<<t_f_name<<" "<<t_f_mobilenumber
	<<" "<<t_semester<<" "<<gpa<<" "<<t_cgpa<<endl;
	t_sr++;
	cout<<"\n\n\t\t\t\tFIRST STUDENT DATA REGISTERED!";
    }
    else
    {
    	float t_gpa;
    	while(infile>>sr_no>>s_name>>s_roll_no>>gender>>location>>f_name>>f_mobilenumber>>semester>>t_gpa>>cgpa)
    	{
    		if(t_roll==s_roll_no)
    		{
    			z++;
			}
		}
		if(z!=0)
		{
		  cout<<"\n\n\t\t\t\tUSER ALREADY EXIST!";
	    } 
		else
		{
	    outfile<<t_sr<<" "<<t_name<<" "<<t_roll<<" "<<t_gender<<" "<<t_location<<" "<<t_f_name<<" "<<t_f_mobilenumber
	    <<" "<<t_semester<<" "<<gpa<<" "<<t_cgpa<<endl;
	    t_sr++;
	    cout<<"\n\n\t\t\t\tSTUDENT DATA REGISTERED!";
	    }
	}
	infile.close();
	outfile.close();

	
}
void student::update_data()
{
	int a=0;
	ifstream infile;
	ofstream outfile;
	string t_f_name;
	int t_f_mobilenumber;
	string t_gender;
	string t_location;
	int t_semester;
	float t_gpa;
	float t_cgpa;
	int t_roll;
	string t_name;
	int t_sr=1;
	infile.open("khan.txt",ios::in);
	if(!infile)
	{
		cout<<"\n\n\t\t\t\tFILE OPENING ERROR!";
	}
	else
	{
		cout<<"\n\n\t\t\t\t*****STUDENT MODIFICATION PANEL*****";
	    cout<<"\nenter the roll no of student to update data : ";
	    cin>>t_roll;
	    cout<<"\nenter the name to be updated : ";
	    cin>>t_name;
	    cout<<"enter the fathers correct name : ";
	    cin>>t_f_name;
	    cout<<"enter fathers correct mobile number : ";
	    cin>>t_f_mobilenumber;
	    cout<<"enter updated semester : ";
	    cin>>t_semester;
	    cout<<"enter updated gpa : ";
	    cin>>t_gpa;
	    cout<<"enter updated cgpa : ";
	    cin>>t_cgpa;
	    cout<<"enter updated location : ";
	    cin>>t_location;
	    outfile.open("khan1.txt",ios::out);
	    while(infile>>sr_no>>s_name>>s_roll_no>>gender>>location>>f_name>>f_mobilenumber>>semester>>gpa>>cgpa)
	    {
	    	if(t_roll==s_roll_no)
	    	{
	    		outfile<<t_sr<<" "<<t_name<<" "<<s_roll_no<<" "<<gender<<" "<<t_location<<" "<<t_f_name<<" "<<t_f_mobilenumber
				<<" "<<t_semester<<" "<<t_gpa<<" "<<t_cgpa<<endl;
	    		a++;
	    		t_sr++;
			}
			else
			{
				outfile<<t_sr<<" "<<s_name<<" "<<s_roll_no<<" "<<gender<<" "<<location<<" "<<f_name<<" "<<f_mobilenumber
				<<" "<<semester<<" "<<gpa<<" "<<cgpa<<endl;
				t_sr++;
			}
		}
		outfile.close();
		infile.close();
	
		if(a!=0)
		{
			remove("khan.txt");
		    rename("khan1.txt","khan.txt");
			cout<<"\n\n\t\t\t\tSTUDENT DETAIL UPDATED";
		}
		else
		{
			remove("khan.txt");
		    rename("khan1.txt","khan.txt");
			cout<<"\n\n\t\t\t\tSTUDENT NOT FOUND";
		}
	}
}
void student::display_data()
{
	int a=1;
	cout<<"\n\n\t\t\t\t*****DISPLAY DATA PANEL*****";
	ifstream infile;
	infile.open("khan.txt",ios::in);
	if(!infile)
	{
		cout<<"\n\n\t\t\t\tFILE DO NOT EXIST";
	}
	else
	{
		while(infile>>sr_no>>s_name>>s_roll_no>>gender>>location>>f_name>>f_mobilenumber>>semester>>gpa>>cgpa)
		{
			cout<<"\n\n\t\t\t\tStudent "<<a;
			cout<<"\n\nsr no : "<<sr_no<<"\nname : "<<s_name<<"\nroll no : "<<s_roll_no<<"\ngender : "<<gender<<"\nlocation : "<<location;
			cout<<"\nfather's name : "<<f_name<<"\nfather's mobile no : "<<f_mobilenumber<<"\nsemester : "<<semester;
			cout<<"\ngpa : "<<gpa<<"\ncgpa : "<<cgpa;
			a++;
		}
	}
	infile.close();
}
void student::search_data()
{
	ifstream infile;
	int t_roll;
	int z=0;
	infile.open("khan.txt",ios::in);
	if(!infile)
	{
		cout<<"\n\n\t\t\t\tFILE DO NOT EXIST";
	}
	else
	{
		cout<<"\n\n\t\t\t\t*****SEARCH DATA PANEL*****";
		cout<<"\n\nenter roll no of student to find data ";
		cin>>t_roll;
		while(infile>>sr_no>>s_name>>s_roll_no>>gender>>location>>f_name>>f_mobilenumber>>semester>>gpa>>cgpa)
		{
			if(t_roll==s_roll_no)
			{
					cout<<"\nNAME : "<<s_name;
	                cout<<"\nROLL NO : "<<s_roll_no;
	                cout<<"\nGENDER : "<<gender;
	                cout<<"\nLOCATION : "<<location;
	                cout<<"\nFATHER'S NAME : "<<f_name;
	                cout<<"\nFATHER'S MOBILE NUMBER : "<<f_mobilenumber;
	                cout<<"\nGPA : "<<gpa;
	                cout<<"\nCGPA : "<<cgpa;
				    z++;
			}
			if(z==0)
			{
				cout<<"\n\n\t\t\t\tSTUDENT DATA DOES NOT EXIST";
			}
		}
	}
}
void student::delete_data()
{
	int t_sr=1;
	int t_roll;
	ifstream infile;
	ofstream outfile1;
	int z=0;
	cout<<"\n\n\t\t\t\t*****DELETE DATA PANEL*****";
	infile.open("khan.txt",ios::in);
	if(!infile)
	{
		cout<<"\n\n\t\t\t\tFILE DO NOT EXIST";
	}
	else
	{
		cout<<"\n\nenter the roll no to delete data : ";
		cin>>t_roll;
		outfile1.open("khan1.txt",ios::out);
		while(infile>>sr_no>>s_name>>s_roll_no>>gender>>location>>f_name>>f_mobilenumber>>semester>>gpa>>cgpa)
		{
			if(t_roll==s_roll_no)
			{
				cout<<"\n\n\t\t\t\tSTUDENT DATA SUCESSFULY DELETED";
				z++;
			}
			else
			{
				outfile1<<t_sr<<" "<<s_name<<" "<<s_roll_no<<" "<<gender<<" "<<location<<" "<<f_name<<" "<<f_mobilenumber
				<<" "<<semester<<" "<<gpa<<" "<<cgpa<<endl;
				t_sr++;
			}
		}
		if(z==0)
		{
			cout<<"\n\n\t\t\t\tSTUDENT DATA NOT FOUND";
		}
		infile.close();
		outfile1.close();
		remove("khan.txt");
		rename("khan1.txt","khan.txt");
	}
}
void student::hit_scholarship()
{
	ifstream infile;
	ofstream outfile;
	int a=0;
	infile.open("khan.txt",ios::in);
	cout<<"\n\n\t\t\t\t*****HIT SCHOLARSHIP PANEL*****";
	if(!infile)
	{
		cout<<"\n\n\t\t\t\tFILE DO NOT EXIST";
	}
	else
	{
		while(infile>>sr_no>>s_name>>s_roll_no>>gender>>location>>f_name>>f_mobilenumber>>semester>>gpa>>cgpa)
		{
			if(gpa>=3.0)
			{
				cout<<"\nSR NO : "<<sr_no<<"\tNAME : "<<s_name<<"\tROLL NO : "<<s_roll_no<<"\tgpa : "<<gpa<<"\tcgpa: "<<cgpa;
				a++;
			}
		}
		if(a==0)
		{
			cout<<"\n\n\t\t\t\tNO STUDENT ELIGIBLE FOR SCHOLARSHIP";
		}
		infile.close();
		outfile.close();
		
	}
}
void student::top()
{
	int a=0;
	ifstream infile;
	cout<<"\n\n\t\t\t\t*****3.5 +*****";
	infile.open("khan.txt",ios::in);
	if(!infile)
	{
		cout<<"\n\n\t\t\t\tFILE DO NOT EXIST";
	}
	else
	{
		while(infile>>sr_no>>s_name>>s_roll_no>>gender>>location>>f_name>>f_mobilenumber>>semester>>gpa>>cgpa)
		{
			if(gpa>=3.5)
			{
				cout<<"\nSR NO : "<<sr_no<<"\tNAME : "<<s_name<<"\tROLL NO : "<<s_roll_no<<"\tgpa : "<<gpa<<"\tcgpa : "<<cgpa;
				a++;
			}
		}
		if(a==0)
		{
			cout<<"\n\n\t\t\t\tNO STUDENT HAVE GPA 3.5+";
		}
		infile.close();
		}
	}
int main()
{
	student s1;
	s1.menu();
	return 0;
}
