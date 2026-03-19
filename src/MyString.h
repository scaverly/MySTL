#pragma once
#include <iostream>

class MyString {
public:
	// Конструкторы
	MyString();
	MyString(const char* str);
	// Деструктор
	~MyString();
	// Операторы
	MyString& operator =(const MyString& other);
	MyString operator +(const MyString& other);
	// Методы
	int strlen(const char* str);
	void Print();
private:
	// Переменные
	char* str;
	int length;
};