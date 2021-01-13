#pragma once
#pragma once
#ifndef BOOKS_H_
#define BOOKS_H_
class Books
{
public:
	char name[20];
	int num;
	char type[10];
	Books();
	void add_books();
	void modify_books();
	void check_info();
	void ststistic();
	friend istream& operator>>(istream& is, Books& books);
};
#endif // !BOOKS_H_
