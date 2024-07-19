#ifndef GIAOVIEN_H
#define GIAOVIEN_H
#include <iostream>

class Giaovien{
	private:
		int Teacher_ID;
		char Teacher_Name[20];
		char Teacher_BirthDate[11];
		char Major[20];
	public:
		int getTeacher_ID() const ;
		const char* getTeacher_Name() const ;
		const char* getTeacher_BirthDate() const ;
		const char* getMajor() const ;
		size_t getNameLength();
		size_t getBirthDateLength();
		size_t getMajorLength();
		void in_thong_tin_giao_vien();
		void nhap_thong_tin_giao_vien();
};
#endif
