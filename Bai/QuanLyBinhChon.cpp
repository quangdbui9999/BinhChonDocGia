#include "QuanLyBinhChon.h"

QuanLyBinhChon::QuanLyBinhChon(void)
{
}

void QuanLyBinhChon::NhapQuanLyBinhChon()
{
	int n = 0, i = 0;
	cout<<"Nhap vao so luong nguoi tham gia binh chon: ";
	cin>>n;
	Ngay ngay;
	ThoiGian thoigian;
	for(i = 0; i < n; i++)
	{
		BinhChon binhchon;
		cout<<"Nhap vao thong tin nguoi thu "<<i + 1<<" binh chon: \n";
		binhchon.NhapThongTinBinhChon();
		XuLyThoiGian(ngay, thoigian); // hàm xử lý lấy thời gian của hệ thống
		binhchon.ThayDoiNgay(ngay); // đưa ngày hiện tại vào thông tin người bình chọn
		binhchon.ThayDoiThoiGian(thoigian); // đưa thời gian hiện tại vào
		a.push_back(binhchon);
		cout<<endl;
	}
}

void QuanLyBinhChon::XuatQuanLyBinhChon()
{
	int i = 0;
	cout<<"So luong nguoi tham gia binh chon: "<<a.size()<<".\n";
	for(i = 0; i < a.size(); i++)
	{
		cout<<"Thong tin nguoi thu "<<i + 1<<" binh chon: \n";
		a[i].XuatThongTinBinhChon();
		cout<<endl;
	}
}

int QuanLyBinhChon::TanSuatBinhChon(int phantu)
{
	int i = 0, dem = 0;
	for(i = 0; i < a.size(); i++)
	{
		if(a[i].LaySoBaoDanh() == phantu)
			dem++;
	}
	return dem;
}

int QuanLyBinhChon::TanSuatBinhChonNhieuNhat()
{
	int i = 0, max = 0, tam = 0;
	max = TanSuatBinhChon(a[0].LaySoBaoDanh());
	for(i = 1; i < a.size(); i++)
	{
		tam = TanSuatBinhChon(a[i].LaySoBaoDanh());
		if(max < tam)
			max = tam;
	}
	return max;
}

int QuanLyBinhChon::KiemTraTrung(vector<BinhChon> b, int k)
{
	int i = 0;
	for(i = 0; i < b.size(); i++)
	{
		if(b[i].LaySoBaoDanh() == k)
			return 1;
	}
	return 0;
}

void QuanLyBinhChon::LietKeThiSinhBinhChonNhieuNhat(vector<BinhChon> &b)
{
	int i = 0;
	int max = TanSuatBinhChonNhieuNhat();
	BinhChon tam;
	cout<<"\n-- Danh sach thi sinh duoc binh chon nhieu nhat: --\n";
	for(i = 0; i < a.size(); i++)
	{
		if(max == TanSuatBinhChon(a[i].LaySoBaoDanh()))
		{
			// lấy số báo danh của người được bình chọn nhiều nhất
			tam.ThayDoiSoBaoDanh(a[i].LaySoBaoDanh());
			// lấy số lượt chọn của thí sinh được bình chọn
			tam.ThayDoiLuotChon(max);
			if(this->KiemTraTrung(b, tam.LaySoBaoDanh()) == 0)
			{/* kiểm tra xem thí sinh được bình chọn nhiều nhất có
			bị trùng không:
			 - Nếu có, không thêm
			 - Nếu không có, thêm*/
				cout<<"Thi sinh co ma so: "<<a[i].LaySoBaoDanh()<<".\n";
				b.push_back(tam);
			}
		}
	}
}

BinhChon QuanLyBinhChon::NguoiDuDoanDung(int sobaodanh, int dudoan)
/* dùng mã số của thí sinh được bình chọn nhiều nhất và số người dự đoán 
để tím ra số người dự đoán đúng nhất*/
{
	int min = abs(a[0].LaySoDuDoan() - dudoan);
	int vitri = 0, i = 0, tam = 0;
	for(i = 0; i < a.size(); i++)
	{
		tam = abs(a[i].LaySoDuDoan() - dudoan);
		if((a[i].LaySoBaoDanh() == sobaodanh) && (min > tam))
		{//lưu lại vị trí của người có số dự đoán gần nhất
		// có thể nhỏ hơn hoặc lớn hơn tổng số dự đoán
			min = tam;
			vitri = i;
		}
	}
	return a[vitri]; // trả về thông tin của người dự đoán đúng nhất
}

void QuanLyBinhChon::ChonBinhChon(vector<BinhChon> b)
{
	//int sobinhchon = TanSuatBinhChonNhieuNhat();
	int j = 0, chon;
	int min = abs(b[0].LaySoDuDoan() - a[0].LaySoDuDoan());
	chon = 0;
	for (int i = 0; i < b.size(); i++)
	{
		cout << "Nguoi binh chon dung nhat cho thi sinh co MS: " << b[i].LaySoBaoDanh() << " voi tong so binh chon la: "
			<< b[i].LaySoDuDoan() << " nguoi: \n";
		for (int j = 1; j < a.size(); j++)
		{
			if (b[i].LaySoBaoDanh() == a[j].LaySoBaoDanh() && min > abs(b[i].LaySoDuDoan() - a[j].LaySoDuDoan()))
			{
				min = abs(b[i].LaySoDuDoan() - a[j].LaySoDuDoan());
				chon = j;
			}
		}
		a[chon].XuatThongTinBinhChon();
	}
}

QuanLyBinhChon::~QuanLyBinhChon(void)
{
}