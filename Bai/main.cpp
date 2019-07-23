#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <time.h>
#include "ThoiGian.h"
#include "Ngay.h"
#include "GetTime.h"
#include "BinhChon.h"
#include "QuanLyBinhChon.h"
using std::vector;
using namespace std;

void main()
{
	cout<<"CHUONG TRINH BINH CHON GIONG HAT VIET NHI 2014.\n";
	QuanLyBinhChon a;
	a.NhapQuanLyBinhChon();
	a.XuatQuanLyBinhChon();
	cout<<"Thi sinh duoc binh chon nhieu nhat: \n";

	vector<BinhChon> b;
	a.LietKeThiSinhBinhChonNhieuNhat(b);
	cout<<"\n\n";
	a.ChonBinhChon(b);
	cout<<"\nKET THUC CHUONG TRINH.\n";

	getch();
}

// vector<int> A(10, 2); // 10 phan tu cua vector A duoc khoi tao bang 2

/* khoi tao cho 1 bector se la ban sao cua 1 hoac 1 phan vector khac 
vector<int> A(10, 2);
vector<int> B(A);
vector<int> C(A.begin(), A.begin() + 5); // vector copy 5 phan tu cua vector A
*/
/*
void main()
{
	vector<int> v(3); //vector kieu so nguyen, giong khai bao mang int[3]
	v[0] = 5;
	v[1] = 3;
	v[2] = 8;
	for(int i = 0; i <v.size(); i++)
		cout<<v[i]<<endl;

	int iWordNum;
	vector<string> arrWords;
	cout<<"Enter number of words = ";
	cin>>iWordNum;
	arrWords.resize(iWordNum);
	for(int i = 0; i < arrWords.size(); i++)
	{
		cout<<"Enter word "<<i<<" : ";
		cin>>arrWords[i];
	}
	cout<<"Alter enter data...\n";
	for(int i = 0; i < arrWords.size(); i++)
		cout<<arrWords[i]<<endl;

	int i;
	vector<int> v;
	for(i = 0; i < 5; i++) // lap 5 lan, moi lan dua them 1 so vao vector
		v.push_back(i); // nhu vay, vector co the duoc su dung nhu Stack
	cout<<endl<<"Mang ban dau: "<<endl;
	for(i = 0; i < v.size(); i++) // ghi noi dung cua mang ra man hinh
		cout<<v[i]<<endl;


	getchar();
}



int ChanCuoi(int a[] , int n)
{
        for(int i=n-1; i>=0; i--)
        {
                if(a[i]%2==0)
                {
                   return a[i];
                }
        }
        return -1;
}

void xoa(int a[],int n)
{
	int i,j;
    int nb=0;
    int b[100];
    for(i=0;i<n;i++)
    {   for(j=0;j<=i;j++)
            if(a[i]==a[j])
                break;
        if(i==j)
            b[nb++]=a[i];        
		cout<<b[i]<<"\t";
    }
 
    for(i=0;i<nb;i++)
        printf("%d ",b[i]);
}

void NhapMang(int a[kichthuocmang], int &n)
{
	int i = 0;
	do
	{
		cout<<"Nhap so luong phan tu cua mang: ";
		cin>>n;
	}while(n<0 || n > 100);
	for(i = 0; i < n; i++)
	{
		cout<<"Nhap phan tu thu a["<<i<<"]: ";
		cin>>a[i];
	}
}

void XuatMang(int a[kichthuocmang], int n)
{
	int i = 0;
	cout<<"[";
	for(i = 0; i < n; i++)
	{
		if(i < (n - 1))
			cout<<a[i]<<"\t";
		if(i == (n - 1))
			cout<<a[i]<<"]";
	}
	cout<<endl;
}

int TimKiem(int A[], int n, int x){
   for(int i = 0; i<n ; i++)
   if(x==A[i])
      return 1;
   return 0;
}

int SoNguyenTo(int n) {
	int i = 0;
    if(n<2)
        return 0;
    else
    {
		for(i = 2; i <= sqrt(n); i++)
        {
			if(n%i==0)
                return 0;
		}
        return 1;
    }
	
}

void LietKeSoNguyenTo(int a[kichthuocmang], int n)
{
	int i = 0, songuyento = 0;
	for(i = 0; i < n; i ++)
	{
		songuyento = SoNguyenTo(a[i]);
		if(songuyento == 1)
			cout<<"["<<a[i]<<"]\t";
	}
	cout<<endl;
}

void main()
{
	int chan = 0;
	int a[kichthuocmang], b[kichthuocmang], n = 0, i = 0, k = 0;
	NhapMang(a, n);
	XuatMang(a, n);
	LietKeSoNguyenTo(a, n);
	int x = 0, pt = 0;
	cout<<"Nhap gia tri x = :";
	cin>>x;
	pt = TimKiem(a, n, x);
	if(pt == 0)
	{
		cout<<"Gia tri "<<x<<" chua co trong mang.\n";
		cout<<"Nhap vi tri can chen, k = ";
		cin>>k;
		if((n + 1) <= kichthuocmang)
		{
			if(k > n || k < 0)
			{
				cout<<"Vi tri k khong nam trong khoang tu [1, "<<n<<".\n";
			}
			else
			{
				for (i=n; i>k-1; i--)
					a[i]=a[i-1];
				a[k]=x;
				n++;
				XuatMang(a, n);
			}
		}
		else
		{
			cout<<"Mang da day du phan tu nen khong the chen them phan tu.\n";
		}
	}
	else
	{
		cout<<"Gia tri "<<x<<" da co trong mang.\n";
	}
	
	chan = ChanCuoi(a, n);
	cout<<"So chan cuoi cung trong mang: "<<chan<<".\n";

	/*
	printf("\n Nhap so x=");
    scanf("%d", &x);
    printf("\n Nhap so k trong [1,%d]=", n);
    scanf("%d", &k);

	if((n + 1) <= max)
	{
		if(k > n || k < 0)
		{
			printf("Vi tri k khong nam trong khoang tu [1, %d].\n", n);
		}
		else
		{
			for (i=n; i>k-1; i--)
				a[i]=a[i-1];
			a[k]=x;
			n++;
			printf("Mang vua chen la: \n");
			for (i=0; i<n; i++)
				printf("%d ", a[i]);
		}
	}
	else
	{
		printf("Mang da day du phan tu nen khong the chen them phan tu.\n");
	}
	

	//for(k=i=0;i<n;i++)
    //      if(a[i] %2!=0){
    //              a[k]=a[i];k++;
    //    }
	//XuatMang(a, k);
}

*/

/*#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
    int a[100],b[100],c[200];
    int k,i,j,m,n,tam,nc;
 
    printf("Nhap so phan tu cua mang ma ban muon nhap : ");
    scanf("%d",&m);
    for(j=0;j<m;j++)
    {
        printf("Nhap phan tu a[%d] cua mang: ",j+1);
        scanf("%d",&a[j]);
    }
 
    do
    {
        printf("nhap so phan tu ngau nhien trong khoang [0,100]= ");
        scanf("%d",&n);
        if((n<0)||(n>100))
            printf("Ban phai nhap n trong khoang [0,100]");
    }
    while((n<0)||(n>100));
	
	srand(time(0));

    for(i=0;i<n;i++)
    {
        tam = rand() % 100;
        b[i]=tam;
    }
 
    printf("Mang cac so do nguoi dung nhap la : ");
    for(j=0;j<m;j++)
        printf("\t%d",a[j]);
   
    printf("\nMang %d so ngau nhien trong khoang [0,100] la : ",n);
    for(i=0;i<n;i++)
        printf("\t%d",b[i]);
 
    k=0;
    for(j=0;j<m;j++)  // sai ở đây, code cũ là "i < m"
    {
        c[k]=a[j];
        k++;
    }

	for(i=0;i<n;i++)
    {  
        c[k]=b[i];
        k++;
    }
 
    printf("\nmang gom phan tu cua 2 mang tren la : \n");
    for(k=0;k<(m+n);k++)
        printf("\t%d",c[k]);
   
    getch();
}

#include <conio.h>
#include <stdio.h>
#define max 5
void main()
{
	printf("So phan tu toi da trong mang: %d", max);
    int a[max];
    int i, n, k, x;
    printf("N=");
    scanf("%d", &n);
    for (i=0; i<n; i++){
        printf("m[%d]=", i+1);
        scanf("%d", &a[i]);
    }
    printf("Mang vua nhap la: \n");
    for (i=0; i<n; i++)
        printf("%d ", a[i]);
    
    printf("\n Nhap so k trong [1,%d]=", n);
	scanf("%d", &k);

	if(n >= 1)
	{
		if(k > n || k < 0)
		{
			printf("Vi tri xoa khong ton tai.\n");
		}
		else
		{
			for(i = k; i < n - 1; i++){
				a[i] = a[i + 1];
			}
			n--;
			printf("Mang vua xoa la: \n");
			for (i=0; i<n; i++)
				printf("%d ", a[i]);
		}
	}
	else
	{
		printf("Mang khong co phan tu de xoa.\n");
	}


	if(n >= 1)
	{
		for(i = 0; i < n - 1; i++){
			a[i] = a[i + 1];
		}
		n--;
		printf("Mang vua xoa dau la: \n");
		for (i=0; i<n; i++)
			printf("%d ", a[i]);
	}
	else
	{
		printf("Mang khong co phan tu de xoa.\n");
	}

	if(n >= 1)
	{
		for(i = n; i < n - 1; i++){
			a[i] = a[i + 1];
		}
		n--;
		printf("Mang vua xoa cuoi la: \n");
		for (i=0; i<n; i++)
			printf("%d ", a[i]);
	}
	else
	{
		printf("Mang khong co phan tu de xoa.\n");
	}

	

	printf("\n Nhap so x=");
    scanf("%d", &x);
    printf("\n Nhap so k trong [1,%d]=", n);
    scanf("%d", &k);

	if((n + 1) <= max)
	{
		if(k > n || k < 0)
		{
			printf("Vi tri k khong nam trong khoang tu [1, %d].\n", n);
		}
		else
		{
			for (i=n; i>k-1; i--)
				a[i]=a[i-1];
			a[k]=x;
			n++;
			printf("Mang vua chen la: \n");
			for (i=0; i<n; i++)
				printf("%d ", a[i]);
		}
	}
	else
	{
		printf("Mang da day du phan tu nen khong the chen them phan tu.\n");
	}


	if((n + 1) <= max)
	{
		printf("\n Nhap so x=");
		scanf("%d", &x);
		for (i=n; i>0; i--)
			a[i]=a[i-1];
		a[0]=x;
		n++;
		printf("Mang vua chen dau la: \n");
		for (i=0; i<n; i++)
			printf("%d ", a[i]);
	}
	else
	{
		printf("Mang da day du phan tu nen khong the chen them phan tu.\n");
	}

	if((n + 1) <= max)
	{
		printf("\n Nhap so x=");
		scanf("%d", &x);
		for (i=n; i>n-1; i--)
			a[i]=a[i-1];
		a[n]=x;
		n++;
		printf("Mang vua chen cuoi la: \n");
		for (i=0; i<n; i++)
			printf("%d ", a[i]);
	}
	else
	{
		printf("Mang da day du phan tu nen khong the chen them phan tu.\n");
	}
	getch();

}



#include "stdio.h" 
#include "math.h" 
void nhapmang(int &n, int M[]) 
{ 
     
    printf("Nhap so phan tu cua mang "); 
    scanf("%d",&n); 
    for(int i=0; i<n;i++) 
    { 
        printf("Nhap phan tu thu %d ",i); 
        scanf("%d",&M[i]); 
    }
} 

void tach(int n, int M[], int &a, int A[], int &b, int B[]) 
{ 
    a=0;b=0; 
    for(int i=0;i<n;i++) 
    { 
        if(M[i]%2==0) 
            A[a++]=M[i]; 
        if(M[i]%2!=0) 
            B[b++]=M[i]; 
    } 


} 


void xuatmang (int n, int M[]) 
{ 
    for(int i=0;i<n;i++) 
        printf("%d ",M[i]); 
} 
void xuatmang1 (int a, int A[]) 
{ 
    for(int i=0;i<a;i++) 
        printf("%d ",A[i]); 
} 
void xuatmang2 (int b, int B[]) 
{ 
    for(int i=0;i<b;i++) 
        printf("%d ",B[i]); 
} 
void main() 
{ 
    int n, M[100], a, A[100], b, B[100]; 
    nhapmang(n,M); 
    xuatmang(n,M); 
    printf("\n"); 
    tach(n,M,a,A,b,B); 
    xuatmang1(a,A); 
    printf("\n"); 
    xuatmang2(b,B); 
    printf("\n"); 
}


#include<iostream>
#include<iomanip>
using namespace std;

int M[50][50];

void NhapMaTran(int A[50][50], int n, int m){
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				cout<<"\n A["<<i<<","<<j<<"]= ";
				cin>>A[i][j];
			}
}
void InMaTran(int B[50][50], int n,int m){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				cout<<setw(3)<<B[i][j]; 
				cout<<"\n";
		
		}
}
void ChuyenVi(int F[50][50], int n,int m){
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++)
			cout<<setw(3)<<F[i][j]; 
			cout<<"\n";
	}
}
void main(){
		int r,c;
		cout<<"\n So dong = "; cin>>r;
		cout<<"\n So cot = "; cin>>c;
		NhapMaTran(M,r,c);
		cout<<"\n Ma tran vua nhap: \n";
		InMaTran(M,r,c);
		cout<<"Ma tran chuyen vi: \n";
		ChuyenVi(M,r,c);		
}


#include <iostream>
#include <string>
using namespace std;

void Sort(int n, string str[])
{
	int i = 0, j = 0;
	string s;
	for(i = 0; i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(str[i] > str[j])
			{
				s = str[i];
				str[i] = str[j];
				str[j] = s;
			}
		}
	}
}

void main()
{
	string s1("012");
	string s2("345");
	string s = s1 + s2;
	cout<<"Result: "<<s<<".\n";

	int n = 5;
	string country[] = {"Viet Nam", "Lao", "Campuchia", "Thai Lan", "Trung Quoc"};
	string so[] = {"7", "35", "86", "12", "65"};
	Sort(n, country);
	Sort(n, so);
	cout<<"Alter sorting:\n";
	for(int i = 0; i < n; i++)
	{
		cout<<"\t"<<country[i]<<endl;
	}
	for(int i = 0; i < n; i++)
	{
		cout<<"\t"<<so[i]<<endl;
	}
}









#include<stdio.h>
#include<conio.h>
 
void main()
{
    int i,j,k,n, sign = 1;
    double det = 1; double temp;
    double a[10][10],b[10][10];
// Nhap cap cua ma tran:
    printf("\nCap cua ma tran vuon, n = "); scanf("%d",&n);
 
// Nhap ma tran a:
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            {
                printf("a[%d][%d] = ", i, j);
                scanf("%lf",&a[i][j]);
            }
 
// Tinh dinh thuc cua a
    for (i = 0; i < n-1; i++)
        {
            if (a[i][i] == 0) // Nếu gặp phần tử trên đường chéo chính bằng 0 thì tìm hàng khác để đổi
                {
                    k = i+1;
                    while (k < n && a[k][i] == 0) k++;
                    if (k==n) { printf("\ndet(a) = 0"); break;} // Không timg thấy, tức det(a) = 0
                    for (j = i; j < n; j++)// Đổi hàng i với hàng k
                        {
                            temp = a[i][j];
                            a[i][j] = a[k][j];
                            a[k][j] = temp;
                        }
                    sign = -sign; // Định thức đổi dấu đó
                }
            for (j = i+1; j < n; j++)// Biển đổi để các phần tử cùng cột ở hàng dưới bằng 0 đó
                {
                    temp = -a[j][i]/a[i][i];
                    for (k = i+1; k < n; k++)   a[j][k] += temp*a[i][k]; // Nhân hàng i với (-a[j][i]/a[i][i]) rồi cộng vào hàng j
                }
            det *= a[i][i]; // Tính dần det(a)
        }
 
    det *= a[n-1][n-1]; // Nhân với phần tử cuối chéo chính nữa là xong
    printf("\ndet(a) = %lf\n",det);
 
//Tinh ma tran nguoc
if (det != 0)
{
    for (i = 0; i < n; i++) // Tạo ra b là ma trận đơn vị đó
        for (j = 0; j < n; j++)
        if (i==j) b[i][j] = 1; else b[i][j] = 0;
 
    for (i = 0; i < n; i++) // Xử lý từ hàng đầu đến hàng cuối
        {
            if (a[i][i] == 0) // Nếu gặp phần tử trên đường chéo chính bằng 0 thì đổi hàng
                {
                    k = i+1;
                    while (k < n && a[k][i] == 0) k++;
                    for (j = 0; j < n; j++) // Đổi hàng đó của a đó, cả với ma trận b nữa
                        {
                            temp = a[i][j];
                            a[i][j] = a[k][j];
                            a[k][j] = temp;
                            temp = b[i][j];
                            b[i][j] = b[k][j];
                            b[k][j] = temp;
                        }
                }
 
            temp = a[i][i];
            for (j = i; j < n; j++) a[i][j] /= temp;
            for (j = 0; j < n; j++) b[i][j] /= temp;
 
            for (j = i+1; j < n; j++)
                {
                    temp = -a[j][i];
                    for (k = i; k < n; k++) a[j][k] += temp*a[i][k];
                    for (k = 0; k < n; k++) b[j][k] += temp*b[i][k];
                }
        }// Kết thúc quá trình Gauss
 
    for (i = n-1; i > 0; i--) // Bắt đầu quá trình Jordan
        for (j = i-1; j >=0; j--)
            {
                temp = -a[j][i];
                for (k = n-1; k >= i; k--)  a[j][k] += temp*a[i][k];
                for (k = 0; k < n; k++) b[j][k] += temp*b[i][k];
            }
 
    for (i = 0; i < n; i++)// In ra ma trận b, bây giờ là ma trận nghich đảo của a
        {
            for (j = 0; j < n; j++) printf("%8.3lf\t", b[i][j]);
            printf("\n");
        }
}
else printf("\nKhong co ma tran nghich dao\n");
    getch();
}











//#include<stdio.h> 
//#include<conio.h> 
//void Nhap(int a[],int N) 
//{ 
//     for(int i=0;i<N;i++) 
//     { 
//             printf("a[%d]: ",i); 
//             scanf("%d",&a[i]); 
//     } 
// } 
// void In(int a[],int N) 
// { 
//      for(int i=0;i<N;i++) 
//         printf(" %d ",a[i]); 
//      printf("\n"); 
//  } 
//  void sapxep(int a[],int N) 
//  { 
//       int i,j,t; 
//       for(i=0;i<N-1;i++) 
//          for(j=i+1;j<N;j++) 
//            if(a[i]>a[j]) 
//            { 
//               t=a[i]; 
//               a[i]=a[j]; 
//               a[j]=t; 
//            } 
//   } 
//  void xoatrung(int a[],int N) 
//  { 
//       int i,j,k; 
//       for(i=0;i<N-1;i++)
//          for(j=i+1;j<N;j++)
//            while(a[i]==a[j]) //đổi if thành while
//            {
//               
//                for(k=j;k<N;k++)
//                a[k]=a[k+1];
//                N-- ; //chuyển N-- xuống đây
//            } 
//            In(a,N); 
//            printf("Mang sap xep sau khi loai bo phan tu trung: "); 
//            sapxep(a,N); 
//            In(a,N); 
//   } 
//   int main() 
//   { 
//       int a[20],N; 
//       printf("Nhap vao so luong phan tu N: "); 
//       scanf("%d",&N); 
//       Nhap(a,N); 
//       printf("Mang vua nhap: ");In(a,N); 
//       printf("Mang sau khi xoa trung: "); 
//       xoatrung(a,N); 
//       getch(); 
//   } 

*/