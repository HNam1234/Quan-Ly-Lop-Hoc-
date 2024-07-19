#include "Sinhvien.h"
#include<iostream>
#include <cstring>
using namespace std;

void Sinhvien::in_thong_tin_sinh_vien()
{
	cout<<"--------------------------------\n";
	cout<<"Ma sinh vien :" << College_ID << endl;
	cout<<"Ten sinh vien :" << Name << endl;
	cout<<"Ngay sinh(YYYY-MM-DD) :" << BirthDate << endl;
	cout<<"GPA :"<< Grade <<endl;
}

void Sinhvien::nhap_thong_tin_sinh_vien()  
{
	cout<<"Ma so sinh vien: "; cin>>College_ID;
	cout<<"Nhap ten sinh vien: "; 
	cin.ignore();
	cin.getline(Name,20, '\n');
	cout<<"Nhap Ngay sinh(YYYY-MM-DD): ";cin>>BirthDate;
	cout<<"GPA: "; cin>>Grade;
}
int Sinhvien::getCollege_ID() const 
		{
			return College_ID;
		}
const char* Sinhvien::getName() const 
		{
			return Name;
		}
const char* Sinhvien::getBirthDate() const 
		{
			return BirthDate;
		}
float Sinhvien::getGrade() const 
		{
			return Grade;
		}
size_t Sinhvien::getNameLength() 
		{
        return strlen(Name);
    	}
size_t Sinhvien::getBirthDateLength() 
		{
        return strlen(BirthDate);
    	}


