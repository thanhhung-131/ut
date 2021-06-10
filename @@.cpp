#include <iostream>
#include <math.h>
#include <conio.h>
#include <fstream>
#define MAX 100
#define exp 0.0001
using namespace std;
void readfile(double a[][MAX],int &n,string topicName){
	fstream g;
	g.open((topicName + ".txt").c_str()); /* mo file doc n va ma tran */
	if (g.fail())
	{
		do
		{
			cout << "Failed to open this file!" << endl;
			g.open((topicName + ".txt").c_str());
		} while (!g.fail());
	}
	g >> n; /* nhap n */
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n + 1; j++)
		{
			g >> a[i][j]; /* nhap ma tran */
		}
	if (g == NULL)
		cout << "So lieu khong hop le";
	g.close();
}
void biendoimatran(double a[][MAX], int &n){
	int i,j,k;
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n + 1; j++)
		if (a[i][j] == 0) {
			for (k = 1; k <= n + 1; k++)
		    	a[i][k] += a[i+1][k];
		}
	}
}
void editfile(double a[][MAX], int &n)
{
	int i, j;
	string topicName,fileName;
	cout << "nhap ten file can sua: ";
	cin >> fileName;
	topicName = "notepad \"" + fileName + "\"";
	system(topicName.c_str());
	readfile(a,n,fileName);
}
void openfile(double a[][MAX],int &n) {
	int i,j;	
	string Name;
	cout << "nhap ten file: ";
	cin >> Name;
	readfile(a,n,Name);
}
void xuatmatran(double a[][MAX], int &n) /* xuat ma tran hai chieu */
{
	for (int i = 1; i <= n; i++)
	{
		cout << "\t\t\t\t";
		for (int j = 1; j <= n + 1; j++)
			cout << a[i][j] << "\t";
		cout << "\n\n"
			 << endl;
	}
}
void nhap(double *a, int &n)
{ /* nhap day n phan tu */
	int i;
	for (i = 1; i <= n; i++)
	{
		cout << "\t\tx" << i << "= ";
		cin >> a[i];
	}
}
/* Xuat day n phan tu */
void xuat(double a[], int &n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		cout << "\n\t\tx[" << i << "]= " << a[i] << " ";
	}
}
void swap(double &a, double &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void calculate(double a[][MAX],int &n){
	int	dem = 0;
	int lap,i,j;
	double x[MAX], y[MAX];
	cout << "\n\n Nhap xap xi nghiem ban dau : " << endl;
	nhap(x, n);
	xuatmatran(a,n);
	do
		{
			lap = 0;
			dem++;
			for (i = 1; i <= n; i++)
			{
				double s = 0;
				for (int j = 1; j <= n; j++)
					if (j != i)
					{
						s += a[i][j] * x[j];
						y[i] = (a[i][n + 1] - s);
					}
					if (a[i][i] != 0)
						y[i] = y[i] / a[i][i];
					else
						return ; /* ket thuc chuong trinh */
					if (fabs(x[i] - y[i]) > exp && dem < 30)
						lap = 1;
					}
					for (i = 1; i <= n; i++)
					{
						x[i] = y[i];
					}
					for (i = 1; i <= n; i++)
					{
						printf("\t\t%0.4f\t\t||", x[i]);
					}
					cout << "\n";

		} while (lap);
		if (dem < 30)
		{
			cout << "\n Nghiem cua he phuong trinh : ";
			xuat(y, n);
		}
		else
		cout << " \n He phtrinh ko giai duoc bang phuong phap nay";
}
void index()
{
	system("cls"); // lenh xoa man hinh
	cout << "\t\t\t---------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t   *************************************" << endl;
	cout << "\t\t\t\t\t MENU giai phuong trinh tuyen tinh\n"
		 << endl;
	cout << "\n"
		 << endl;
	cout << "\t\t\t\t\t1 xuat ma tran\n"
		 << endl;

	cout << "\t\t\t\t\t2 giai bang phuong phap gauss siedel\n"
		 << endl;
	cout << "\t\t\t\t\t3 tro ve de nhap file khac\n"
		 << endl;
	cout << "\t\t\t\t\t4 vao file de sua du lieu(khi xong luu va thoat de tiep tuc)\n"
		 << endl;
	cout << "\t\t\t\t\t5 EXIT\n"
		 << endl;
	cout << "\t\t\t\t   *************************************" << endl;
	cout << "\t\t\t---------------------------------------------------------------------" << endl;
	cout << " MOI BAN CHON: ";
}
void presentation(){
	cout << "          ----------------------------------------------------------------------------------------------------" << endl;
	cout << "          |                                     NHOM SINH VIEN THUC HIEN                                     |" << endl;
	cout << "          |                                          HO THANH HUNG                                           |" << endl;
	cout << "          |                                          TRAN ANH HAO                                            |" << endl;
	cout << "          |                                        DE TAI DO AN KY 2                                         |" << endl;
	cout << "          |                  VIET CHUONG TRINH GIAI HE PHUONG TRINH BANG PHUONG PHAP GAUSS SEIDEL            |" << endl;
	cout << "          ----------------------------------------------------------------------------------------------------" << endl;
}
int main()
{
	int n, i, j, lap, dem, chon;
	double a[MAX][MAX];
	char tt,f,g;
	string Name;
	presentation();
	do
	{

		system("pause");
		system("cls");
		openfile(a,n);
		do
		{

			system("pause");
			system("cls");

			index();
			cin >> chon;

			switch (chon)
			{
			case 1:
			{
				cout << "Ma tran " << n << " hang " << n + 1 << " cot" << endl;
				cout << "He so cua phuong trinh: " << endl;
				xuatmatran(a, n);
				break;
				system("pause");
			}
			case 2:
			{
				while (1)
				{
					calculate(a,n);
					cout << "\n\n Ban tiep tuc ko(c/k)?";
					tt = getch();
					if (tt != 'c')
						break;
				}
				break;
			}
				
			case 3:
			{

				break;
			}

			case 4:
			{
				editfile(a,n);
				break;
			}
			case 5:
			{
				cout << "\t\t\tket thuc chuong trinh";
				return 0;
			}
			default:
			{
				cout << "MOI BAN NHAP LAI !" << endl;
				break;
			}
			}
		} while ((chon != 3));
	} while (chon != 5);
}
