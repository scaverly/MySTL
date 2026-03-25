#pragma once
#include <iostream>

class MyString {
public:
	// Конструкторы
	MyString();
	MyString(const char* str);
	MyString(size_t n, char c);
	MyString(char c);
	MyString(const MyString& s, size_t start, size_t len);
	// Конструктор копирования
	MyString(const MyString& other);
	// Деструктор
	~MyString();
	// Операторы
	MyString& operator =(const MyString& other);
	MyString operator +(const MyString& other);
	MyString& operator +=(const MyString& other);
	MyString& operator +=(char c);
	bool operator !=(const MyString& other);
	bool operator ==(const MyString& other);
	char& operator[](size_t index);				// Для записи
	char operator[](size_t index) const;		// Для чтения
	// операторы <<, >>
	friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
	friend std::istream& operator>>(std::istream& is, MyString& obj);
	// Методы
	size_t strlen(const char* str);
	char& at(size_t index);              // Для изменения
	char at(size_t index) const;         // Для чтения
	bool empty() const;
	char& front();						 // Для изменения
	char front() const;					 // Для чтения
	char& back();						 // Для Изменения
	char back() const;					 // Для чтения
	size_t length() const;
	size_t size() const;
	size_t capacity() const;
	void reserve(size_t n);
	void shrink_to_fit();
	void clear();
	void push_back(char c);
	void pop_back();
	void append(const MyString& other);
	void append(char c);
	void insert(size_t pos, const MyString& other);
	void erase(size_t pos, size_t len);
private:
	// Переменные
	char* str;
	size_t _length;
	size_t _capacity; // Размер	выделенного буфера
};