#ifndef _BINH_CHON_H_
#define _BINH_CHON_H_
#include <iostream>
#include <string>
#include "GetTime.h"
#include "Ngay.h"
#include "ThoiGian.h"
using namespace std;
class BinhChon
{
private:
	string sodienthoai;
	Ngay ngaythangnam;
	ThoiGian giophutgiay;
	int sobaodanh;
	int consodudoan;
public:
	BinhChon(void);
	void NhapThongTinBinhChon();
	void XuatThongTinBinhChon();
	int LaySoBaoDanh();
	int LaySoDuDoan();
	void ThayDoiSoBaoDanh(int sobaodanh1);
	void ThayDoiLuotChon(int luotchon);
	void ThayDoiNgay(Ngay ngay);
	void ThayDoiThoiGian(ThoiGian thoigian);
	~BinhChon(void);
};
#endif