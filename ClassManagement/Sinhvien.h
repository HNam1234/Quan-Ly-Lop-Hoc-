#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <iostream>

class Sinhvien{
	public:
		int College_ID;
		char Name[20];
		char BirthDate[11];
		float Grade;
	public:
		int getCollege_ID() const ;
		const char* getName() const ;
		const char* getBirthDate() const ;
		float getGrade() const ;
		size_t getNameLength();
		size_t getBirthDateLength();
		void in_thong_tin_sinh_vien();
		void nhap_thong_tin_sinh_vien();
};
#endif
