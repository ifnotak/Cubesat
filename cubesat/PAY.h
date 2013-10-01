#pragma once
#include<iostream>
#include <string>
#define STRING_SIZE 1000
using namespace std;

class PAY
{
public:
	PAY(void);
	~PAY(void);
	int _DeletePhotos(string);
	int _TakePhoto(string, string, string, string, string);
	int _TakePhoto_2(string, string, string, string);
	int _Rename(string, string, string);
	int _DeletePhotos(string);
};

