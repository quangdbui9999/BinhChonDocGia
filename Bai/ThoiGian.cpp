#include "ThoiGian.h"

ThoiGian::ThoiGian(void)
{
}

void ThoiGian::DoiGio(int x)
{
	this->gio = x;
}

void ThoiGian::DoiPhut(int x)
{
	this->phut = x;
}

void ThoiGian::DoiGiay(int x)
{
	this->giay = x;
}

void ThoiGian::NhapThoiGian()
{
	do
	{
		cout<<"Nhap gio: ";
		cin>>this->gio;
	}while(this->gio < 0 || this->gio > 23);
	do
	{
		cout<<"Nhap phut: ";
		cin>>this->phut;
	}while(this->phut < 0 || this->phut > 59);
	do
	{
		cout<<"Nhap giay: ";
		cin>>this->giay;
	}while(this->giay < 0 || this->giay > 59);
}

void ThoiGian::XuatThoiGian()
{
	if(this->gio >= 0 && this->gio <= 9)
		cout<<"0"<<this->gio<<":";
	else
		cout<<this->gio<<":";
	if(this->phut >= 0 && this->phut <= 9)
		cout<<"0"<<this->phut<<":";
	else
		cout<<this->phut<<":";
	if(this->giay >= 0 && this->giay <= 9)
		cout<<"0"<<this->giay;
	else
		cout<<this->giay;
	cout<<"."<<endl;
}

ThoiGian::~ThoiGian(void)
{
}