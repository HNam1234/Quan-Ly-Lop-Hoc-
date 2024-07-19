#include "Giaovien.h"
#include<iostream>
#include <cstring>
using namespace std;

void Giaovien::in_thong_tin_giao_vien()
{
	cout<<"--------------------------------\n";
	cout<<"Ma so giao vien :" << Teacher_ID << endl;
	cout<<"Ten giao vien :" << Teacher_Name << endl;
	cout<<"Ngay sinh(YYYY-MM-DD) :" << Teacher_BirthDate << endl;
	cout<<"Chuyen nganh :"<< Major <<endl;
}

void Giaovien::nhap_thong_tin_giao_vien()  
{
	cout<<"Ma so giao vien: "; cin>>Teacher_ID;
	cout<<"Nhap ten giao vien: "; 
	cin.ignore();
	cin.getline(Teacher_Name,20, '\n');
	cout<<"Nhap Ngay sinh(YYYY-MM-DD): ";cin>>Teacher_BirthDate;
	cout<<"Major: "; cin>>Major;
}
int Giaovien::getTeacher_ID() const 
		{
			return Teacher_ID;
		}
const char* Giaovien::getTeacher_Name() const 
		{
			return Teacher_Name;
		}
const char* Giaovien::getTeacher_BirthDate() const 
		{
			return Teacher_BirthDate;
		}
const char* Giaovien::getMajor() const 
		{
			return Major;
		}
size_t Giaovien::getNameLength() 
		{
        return strlen(Teacher_Name);
    	}
size_t Giaovien::getBirthDateLength() 
		{
        return strlen(Teacher_BirthDate);
    	}
size_t Giaovien::getMajorLength() 
		{
        return strlen(Major);
    	}

