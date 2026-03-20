#pragma once
#include <iostream>

class MyString {
public:
	// Конструкторы
	MyString();
	MyString(const char* str);
	// Конструктор копирования
	MyString(const MyString& other);
	// Деструктор
	~MyString();
	// Операторы
	MyString& operator =(const MyString& other);
	MyString operator +(const MyString& other);
	MyString& operator +=(const MyString& other);
	// Методы
	int strlen(const char* str);
	void Print();
	// Переменные
	char* str;
private:
	int length;
};