#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include "Giaovien.h"
#include "Sinhvien.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

char HOST[] = "localhost";
char USER[] = "root";
char PASS[] = "Mypassword1";
//your mysql username, host, password 

int main(int argc, char** argv) {
	MYSQL* obj;
	MYSQL_ROW row;
    MYSQL_RES * res;
	bool ProgramIsOpened = true;
	int answer0,answer,answer1,answer2;
	int Delete_student,Delete_teacher;
	
	char* consult;
	char* sentence,qstate;
	string sentence_aux;	// to add data to the table

//---------------------------
//Connection

	if(!(obj = mysql_init(0)))
	{
		cout<<"ERROR: MySql object could not be created." <<endl;
	}else
	{
		if(!mysql_real_connect(obj,HOST,USER,PASS,"school",3306,NULL,0))
		{
			cout<<"Some ERROR database is wrong or not exist." <<endl;
			cout<<mysql_error(obj)<<endl;
		}else
		{
			cout<<"LOGGED IN"<<endl;
			while(ProgramIsOpened)
			{
				cout<<"Would you like to add the information for: \n";
				cout<<"[1] Teacher\n";
				cout<<"[2] Student\n";
				cout<<"Answer: ";
				cin>>answer0;
				if(answer0 == 2)
				{
					Sinhvien sinhvien;
					sinhvien.nhap_thong_tin_sinh_vien();
					//Setting update
					sentence_aux = "INSERT INTO student(College_ID,Name,BirthDate,Grade) VALUES('%d','%s','%s','%f')";
					sentence = new char[sentence_aux.length()+1];
					strcpy(sentence, sentence_aux.c_str());  // copy string statement into a *char
					
					consult = new char[strlen(sentence) + sizeof(int) + sinhvien.getNameLength() + sinhvien.getBirthDateLength() + sizeof(float)];
					sprintf(consult, sentence, sinhvien.getCollege_ID(), sinhvien.getName(), sinhvien.getBirthDate(), sinhvien.getGrade());
				}
				else if(answer0 == 1)
				{
					Giaovien giaovien;
					giaovien.nhap_thong_tin_giao_vien();
					//Setting update
					sentence_aux = "INSERT INTO teacher(Teacher_ID,Name,BirthDate,Major) VALUES('%d','%s','%s','%s')";
					sentence = new char[sentence_aux.length()+1];
					strcpy(sentence, sentence_aux.c_str());  // copy string statement into a *char
					
					consult = new char[strlen(sentence) + sizeof(int) + giaovien.getNameLength() + giaovien.getBirthDateLength() + giaovien.getMajorLength()];
					sprintf(consult, sentence, giaovien.getTeacher_ID(),giaovien.getTeacher_Name(),giaovien.getTeacher_BirthDate(),giaovien.getMajor());
				}
				//Make attemp
				if(mysql_ping(obj))
				{
					cout<< "ERROR: Imposible to connect."<<endl;
					cout<< mysql_error(obj)<<endl;
				}
				if(mysql_query(obj,consult))
				{
					cout<<"ERROR: " <<mysql_error(obj)<<endl;
					rewind(stdin);
					getchar();
				}
				else
				{
					cout<<"Info added correctly."<<endl;
					
				}
				mysql_store_result(obj);
				cout<<endl<<"Another?"<<endl;
				cout<<"[1] : YES "<<endl;
				cout<<"[0] : NO "<<endl;
				cout<<"Answer: ";
				cin>> answer;
				cin.ignore(100,'\n');
				if(answer == 0 )
				{
					ProgramIsOpened = false;
						cout<<endl;
						cout<<"Would you like to see your table? \n";
						cout<<"[1] : YES"<<endl;
						cout<<"[2] : NO"<<endl;
						cout<<"Answer: ";
						cin>> answer1;
						if(answer1 == 1 && answer0 == 2 )
						{
							qstate = mysql_query(obj, "SELECT * FROM student");
							
							if (!qstate)
					        {
					            res = mysql_store_result(obj);
					
					
					            while (row = mysql_fetch_row (res))
					            {
					            	cout<<"------------------------\n";
					                cout<<" ID : "<< row [0]<<endl;
					                cout <<" Name: "<<row [1]<<endl;
					                cout <<" BirthDate: "<< row [2]<<endl;
					                cout <<" Grade: " <<row [3] <<endl;
					            }
					        }
					    cout<<"Do you want to clear any student? \n";
						cout<<"[0] : YES"<<endl;
						cout<<"[1] : NO"<<endl;
						cout<<"Answer: ";
						cin>> answer2;
						}
						else if(answer1 == 1 && answer0 == 1 )
						{
							qstate = mysql_query(obj, "SELECT * FROM teacher");
							
							if (!qstate)
					        {
					            res = mysql_store_result(obj);
					
					
					            while (row = mysql_fetch_row (res))
					            {
					            	cout<<"------------------------\n";
					                cout<<" Teacher_ID : "<< row [0]<<endl;
					                cout <<" Name: "<<row [1]<<endl;
					                cout <<" BirthDate: "<< row [2]<<endl;
					                cout <<" Major: " <<row [3] <<endl;
					            }
					        }
					    cout<<"Do you want to clear any teacher? \n";
						cout<<"[2] : YES"<<endl;
						cout<<"[1] : NO"<<endl;
						cout<<"Answer: ";
						cin>> answer2;
						}
						while(answer2 == 0 )
						{
							cout<<"Enter student's College_ID: ";
							cin>>Delete_student;
							char query[100];
        					sprintf(query, "DELETE FROM student WHERE College_ID = %d", Delete_student);
							mysql_query(obj, query);
							cout<<"Delete succesfully! Press 0 to delete another one, 1 to exit! \n";
							cin>>answer2;
						}
						while(answer2 == 2 )
						{
							cout<<"Enter teacher's ID: ";
							cin>>Delete_teacher;
							char query[100];
        					sprintf(query, "DELETE FROM teacher WHERE Teacher_ID = %d", Delete_teacher);
							mysql_query(obj, query);
							cout<<"Delete succesfully! Press 2 to delete another one, 1 to exit! \n";
							cin>>answer2;
						}
					
				}
			
			}
		}
	}
	cout<<"BYE";
	return 0;
}
