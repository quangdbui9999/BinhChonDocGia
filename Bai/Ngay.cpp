#include "Ngay.h"
#include "ThoiGian.h"

Ngay::Ngay(void)
{
	this->ngay = 1;
	this->thang = 1;
	this->nam = 1;
}

Ngay::Ngay(int year)
{
	this->ngay = 1;
	this->thang = 1;
	this->nam = year;
}

Ngay::Ngay(int year, int month)
{
	this->ngay = 1;
	this->thang = month;
	this->nam = year;
}

Ngay::Ngay(int year, int month, int day)
{
	this->ngay = day;
	this->thang = month;
	this->nam = year;
}

Ngay::Ngay(const Ngay &date)
{
	this->ngay = date.ngay;
	this->thang = date.thang;
	this->nam = date.nam;
}

Ngay& Ngay::operator=(const Ngay &date)
{
	if(this == &date)
		return *this;
	this->ngay = date.ngay;
	this->thang = date.thang;
	this->nam = date.nam;
	return *this;
}

void Ngay::DoiNgay(int x)
{
	this->ngay = x;
}

void Ngay::DoiThang(int x)
{
	this->thang = x;
}

void Ngay::DoiNam(int x)
{
	this->nam = x;
}

int Ngay::KiemTraNam()
{
	int year = this->nam;
	if((year % 4 ==0 && year % 100 != 0) || year % 400 == 0)
	{
		return 1;
	}
	return 0;
}

int Ngay::KiemTraNgay()
{
	int kiemtra = this->KiemTraNam();
	int day, month, year;
	day = this->ngay;
	month = this->thang;
	year = this->nam;
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 ||  month == 12)
	{
		if(day >= 1 && day <= 31)
			return 1;
		else
			return 0;
	}
	else
	{
		if(month == 4 || month == 6 || month == 9 || month == 11)
		{
			if(day >= 1 && day <= 30)
				return 1;
			else 
				return 0;
		}
		else
		{
			if((kiemtra == 1 && (day >= 1 && day <= 29)) || (kiemtra == 0 && (day >= 1 && day <= 28)))
				return 1;
			else
				return 0;
		}
	}
}

int Ngay::KiemTraThang()
{
	int kiemtra = this->KiemTraNam();
	int ngaycuoi = 0;
	Ngay a;
	a.thang = this->thang;
	switch(a.thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		{
			ngaycuoi = 31;
			return ngaycuoi;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		{
			ngaycuoi = 30;
			return ngaycuoi;
		}
		break;
	case 2:
		{
			if(kiemtra == 1)
			{
				ngaycuoi = 29;
				return ngaycuoi;
			}
			else
			{
				ngaycuoi = 28;
				return ngaycuoi;
			}
		}
		break;
	}
}

void Ngay::NhapNgay()
{
	Ngay kiemtra;
	do
	{
		do
		{
			cout<<"Nhap ngay: ";
			cin>>this->ngay;
		}while(this->ngay < 1 || this->ngay > 31);
		do
		{
			cout<<"Nhap thang: ";
			cin>>this->thang;
		}while(this->thang < 1 || this->thang > 12);
		do
		{
			cout<<"Nhap nam: ";
			cin>>this->nam;
		}while(this->nam < 1945 || this->nam > 2014);
		kiemtra.ngay = this->ngay;
		kiemtra.thang = this->thang;
		kiemtra.nam = this->nam;
	}while(kiemtra.KiemTraNgay() == 0);
}

void Ngay::XuatNgay()
{
	if(this->ngay >= 1 && this->ngay <= 9)
		cout<<"0"<<this->ngay<<"/";
	else
		cout<<this->ngay<<"/";
	if(this->thang >= 1 && this->thang <= 9)
		cout<<"0"<<this->thang<<"/";
	else
		cout<<this->thang<<"/";
	if(this->nam >= 1 && this->nam <= 9)
		cout<<"000"<<this->nam<<".";
	else if(this->nam >= 10 && this->nam <= 99)
		cout<<"00"<<this->nam<<".";
	else if(this->nam >= 100 && this->nam <= 999)
		cout<<"0"<<this->nam<<".";
	else
		cout<<this->nam<<".";
	cout<<endl;
}

Ngay::~Ngay(void)
{
}