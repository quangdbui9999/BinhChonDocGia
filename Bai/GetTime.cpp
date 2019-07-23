#include "GetTime.h"

void TimeAnalys(char *a, ThoiGian &b) // phân tích thời gian
{
	char tam[5];
	int j = 0, i = 0, dem = 0;
	for(i = 0; i <= strlen(a); i++)
	{
		if(a[i] != 0 && a[i] != ':')
		{
			tam[j] = a[i];
			j++;
		}
		else
		{
			tam[j] = 0;
			if(dem == 0)
			{
				b.DoiGio(atoi(tam));
			}
			else if(dem == 1)
			{
				b.DoiPhut(atoi(tam));
			}
			else if(dem == 2)
			{
				b.DoiGiay(atoi(tam));
			}
			dem++;
			j = 0;
		}
	}
}

void XuLyThoiGian(Ngay &a, ThoiGian &b)
{
	time_t thoigian; //khai báo kiểu dữ liệu thời gian
	struct tm* thongtinthoigian; // khai báo dữ liệu có cấu trúc
	time(&thoigian);
	thongtinthoigian = localtime(&thoigian);
	char *time = asctime(thongtinthoigian); // Wed Nov 12 11:40:47 2014
	// theo thứ tự: thứ tháng ngày giờ:phút:giây năm
	char tam[26];
	int i = 0, j = 0, x = 0, dem = 0;
	for(i = 0; i <= strlen(time); i++)
	{
		if(time[i] != ' ' && time[i] != 0)
		{
			tam[j] = time[i];
			j++;
		}
		else
		{
			tam[j] = 0; // kí tự kết thúc 1 chuỗi '\0'
			if(dem == 1)
			{
				if(strcmp(tam, "Jan") == 0)
					x = 1;
				else if (strcmp(tam, "Feb") == 0)
					x = 2;
				else if (strcmp(tam, "Mar") == 0)
					x = 3;
				else if (strcmp(tam, "Apr") == 0)
					x = 4;
				else if (strcmp(tam, "May") == 0)
					x = 5;
				else if (strcmp(tam, "Jun") == 0)
					x = 6;
				else if (strcmp(tam, "Jul") == 0)
					x = 7;
				else if (strcmp(tam, "Aug") == 0)
					x = 8;
				else if (strcmp(tam, "Sep") == 0)
					x = 9;
				else if (strcmp(tam, "Oct") == 0)
					x = 10;
				else if (strcmp(tam, "Nov") == 0)
					x = 11;
				else if (strcmp(tam, "Dec") == 0)
					x = 12;
				a.DoiThang(x);
			}
			if(dem == 2)
			{
				a.DoiNgay(atoi(tam));
			}
			if(dem == 3)
			{
				TimeAnalys(tam, b);
			}
			if(dem == 4)
			{
				a.DoiNam(atoi(tam));
			}
			dem++;
			j = 0;
		}
	}
}