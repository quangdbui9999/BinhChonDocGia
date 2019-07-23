#include "BinhChon.h"
#include "GetTime.h"
#include "Ngay.h"
#include "ThoiGian.h"

BinhChon::BinhChon(void)
{
}

void BinhChon::NhapThongTinBinhChon()
{
	/*do
	{
		cout<<"Nhap so dien thoai cua nguoi binh chon: ";
		flushall();
		getline(cin, this->sodienthoai);
	}while(this->sodienthoai.length() < 10 || this->sodienthoai.length() > 11);*/
	do
	{
		cout<<"Nhap so bao cua thi sinh ma minh binh chon: ";
		cin>>this->sobaodanh;
	}while(this->sobaodanh < 1);
	do
	{
		cout<<"Nhap con so du doan co bao nhieu nguoi du doan giong ban: ";
		cin>>this->consodudoan;
	}while(this->consodudoan < 1);
}

void BinhChon::XuatThongTinBinhChon()
{
	cout<<"So dien thoai cua nguoi binh chon: "<<this->sodienthoai<<".\n";	
	cout<<"Ngay binh chon: ";
	ngaythangnam.XuatNgay();
	cout<<"Thoi gian binh chon: ";
	giophutgiay.XuatThoiGian();
	cout<<"So bao cua thi sinh ma minh binh chon: "<<this->sobaodanh<<".\n";
	cout<<"Con so du doan co bao nhieu nguoi du doan giong ban: "<<this->consodudoan<<".\n";
}

int BinhChon::LaySoBaoDanh()
{
	return this->sobaodanh;
}

int BinhChon::LaySoDuDoan()
{
	return this->consodudoan;
}

void BinhChon::ThayDoiSoBaoDanh(int sobaodanh1)
{
	this->sobaodanh = sobaodanh1;
}

void BinhChon::ThayDoiLuotChon(int luotchon)
{
	this->consodudoan = luotchon;
}

void BinhChon::ThayDoiNgay(Ngay ngay)
{
	this->ngaythangnam = ngay;
}

void BinhChon::ThayDoiThoiGian(ThoiGian thoigian)
{
	this->giophutgiay = thoigian;
}

BinhChon::~BinhChon(void)
{
}