#ifndef _QUAN_LY_BINH_CHON_H_
#define _QUAN_LY_BINH_CHON_H_

#include <iostream>
#include <vector>
#include <math.h>
#include <conio.h>
#include "BinhChon.h"
using std::vector;
using namespace std;

class QuanLyBinhChon
{
private:
	vector<BinhChon> a;
public:
	QuanLyBinhChon(void);
	void NhapQuanLyBinhChon();
	void XuatQuanLyBinhChon();
	int TanSuatBinhChon(int phantu);
	int TanSuatBinhChonNhieuNhat();
	int KiemTraTrung(vector<BinhChon> b,int k);
	void LietKeThiSinhBinhChonNhieuNhat(vector<BinhChon> &b);
	BinhChon NguoiDuDoanDung(int sobaodanh, int dudoan);
	void ChonBinhChon(vector<BinhChon> b);
	void XuatDS(vector<BinhChon> z);
	~QuanLyBinhChon(void);
};
#endif