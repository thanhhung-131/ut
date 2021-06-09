#include <iostream>
#include <math.h>
#include <conio.h>
#include <fstream>
#define MAX 100
#define exp 0.001
using namespace std;
void mofile(fstream f)
{
	int i, j, n;
	string Name;
	cout << "nhap ten file can sua: ";
	cin >> Name;
	Name = "notepad \"" + Name + "\"";
	system(Name.c_str());
	f.open((Name + ".txt").c_str()); /* mo file doc n va ma tran */
	if (f.fail())
	{
		do
		{
			cout << "Failed to open this file!" << endl;
			cout << " \t\t\tnhap lai ten file: ";
			cin >> Name;
			f.open((Name + ".txt").c_str());
		} while (f.fail());
	}

	f >> n; /* nhap n */
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n + 1; j++)
		{
			g >> a[i][j]; /* nhap ma tran */
		}
	if (f == NULL)
		cout << "So lieu khong hop le";
	f.close();
}

void xuatmatran(int a[][MAX], int n) /* xuat ma tran hai chieu */
{
	for (int i = 1; i <= n; i++)
	{
		cout << "\t\t\t\t";
		for (int j = 1; j <= n + 1; j++)
			std::cout << a[i][j] << "\t";
		cout << "\n\n"
			 << endl;
	}
}
void nhap(double *a, int n)
{ /* nhap day n phan tu */
	int i;
	for (i = 1; i <= n; i++)
	{
		cout << "\t\tx" << i << "= ";
		cin >> a[i];
	}
}
/* Xuat day n phan tu */
void xuat(double a[], int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		cout << "\n\t\tx[" << i << "]= " << a[i] << " ";
	}
}
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
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

int main()
{
	int n, i, j, lap, dem, chon;
	double x[MAX], y[100];
	int a[MAX][MAX];
	char tt;
	string topicName, Name;
	fstream f, g;
	cout << "          ----------------------------------------------------------------------------------------------------" << endl;
	cout << "          |                                     NHOM SINH VIEN THUC HIEN                                     |" << endl;
	cout << "          |                                          HO THANH HUNG                                           |" << endl;
	cout << "          |                                          TRAN ANH HAO                                            |" << endl;
	cout << "          |                                        DE TAI DO AN KY 2                                         |" << endl;
	cout << "          |                  VIET CHUONG TRINH GIAI HE PHUONG TRINH BANG PHUONG PHAP GAUSS SEIDEL            |" << endl;
	cout << "          ----------------------------------------------------------------------------------------------------" << endl;

	do
	{

		system("pause");
		system("cls");
		mofile(f);
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
					cout << "\n\n Nhap xap xi nghiem ban dau : " << endl;
					nhap(x, n);
					for (i = 1; i <= n; i++)
					{
						if (a[i][i] == 0)
							for (int j = 1; j <= n + 1; j++)
							{
								if (i < n)
									swap(a[i + 1][j], a[i][j]);
								else
									swap(a[1][j], a[i][j]);
							}
					}

					dem = 0;

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
								return 0; /* ket thuc chuong trinh */
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

					cout << "\n\n Ban tiep tuc ko(c/k)?";
					tt = getch();
					if (tt != 'c')
						break;
				}
				break;
			}
				system("pause");
			case 3:
			{

				break;
			}

			case 4:
			{

				cout << "nhap ten file can sua: ";
				cin >> Name;
				Name = "notepad \"" + Name + "\"";
				system(Name.c_str());
				mofile(g);

				break;
			}
				system("pause");
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
				system("pause");
			}
		} while ((chon != 3));
	} while (chon != 5);
}
