#include <iostream>
#include <math.h>
#include <conio.h>
#include <fstream>
#define MAX 100
#define exp 0.001
using namespace std;
void nhapmatran(int a[][MAX], int n) /* nhap ma tran hai chieu */
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n + 1; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
}

void xuatmatran(int a[][MAX], int n) /* xuat ma tran hai chieu */
{
	for (int i = 1; i <= n; i++)
	{	cout<<'\t\t\t\t';
		for (int j = 1; j <= n + 1; j++)
			std::cout << a[i][j] << '\t';
		cout <<'\n\n' <<endl;
	}
}
void nhap(double *a, int n)
{ /* nhap day n phan tu */
	int i;
	for (i = 1; i <= n; i++)
		{
			cout <<'\t\t' << "x" <<i<<"= ";
		cin >> a[i];
		}
}
/* Xuat day n phan tu */
void xuat(double a[], int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		cout <<'\n\t\t'<<"x["<<i<<"]= "<< a[i] << " ";
	}
}

int main()
{
	int n, i, j, lap, dem,chon;
	double x[MAX], y[100];
	int a[MAX][MAX];
	char tt;
	string topicName;
	do
	{
	system("cls"); // lenh xoa man hinh 
    cout << "          ----------------------------------------------------------------------------------------------------" << endl;
    cout << "          |                                     NHOM SINH VIEN THUC HIEN                                     |"<< endl;
    cout << "          |                                          HO THANH HUNG                                           |"<< endl;
    cout << "          |                                          TRAN ANH HAO                                            |"<< endl;
    cout << "          |                                        DE TAI DO AN KY 2                                         |"<< endl;
    cout << "          |                  VIET CHUONG TRINH GIAI HE PHUONG TRINH BANG PHUONG PHAP GAUSS SEIDEL            |"<< endl;
    cout << "          ----------------------------------------------------------------------------------------------------" << endl;
    fstream f;
	f.open("C:\\Users\\DELL\\OneDrive\\Documents\\nhapnvamatran.txt", ios::in); /* mo file doc n va ma tran */
	if (f.fail()) {
		cout << "Failed to open this file!" << endl;
		return 0;
		}
	f >> n; /* nhap n */
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n + 1; j++)
		{
			f >> a[i][j]; /* nhap ma tran */
		}
	if (f == NULL)
		cout << "So lieu khong hop le";
	f.close();
	cout << '\n\n'<< endl;
	cout << '\t\t\t' << "---------------------------------------------------------------------"<< endl;
	cout << '\t\t\t\t'<<"   *********************************************"<< endl;
	cout << '\t\t\t\t\t' <<" MENU giai phuong trinh tuyen tinh "<<'\n' << endl;
	cout << '\n'<< endl;
	cout << '\t\t\t\t\t'<< "1. Xuat ma tran"<< '\n' << endl;
	cout << '\t\t\t\t\t' << "2. Vao file de sua so lieu"<<'\n' << endl;
	cout << '\t\t\t\t\t' << "3. Giai bang phuong phap gauss siedel"<< '\n' << endl;
	cout << '\t\t\t\t\t' << "4. EXIT"<<'\n' << endl;
	cout << '\t\t\t\t' <<"   *********************************************"<< endl;
	cout << '\t\t\t' <<"---------------------------------------------------------------------"<< endl;
	cout <<" MOI BAN CHON: ";
	cin >> chon;
	switch(chon)
	{
		case 1:
			{
				cout << "Ma tran " << n << " hang " << n + 1 << " cot" << endl;
				cout << "He so cua phuong trinh: " << endl;
				xuatmatran(a, n);
				system("pause");
				break;
				
			}
		case 3:
			{
				while (1)
				{
					cout << '\n\n' <<" Nhap xap xi nghiem ban dau : " << endl;
					nhap(x, n);
					for(i=1;i<=n;i++)
					{
						if(a[i][i]==0) cout<< '\t\t\t' << "MATH ERROR !!"; break;
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
							{	x[i] = y[i];}
					
						for(i=1;i<=n;i++)
						 {cout << '\t\t' << setprecision(4) << x[i] << "    ||";}
							  cout<<'\n';
							
							
					} while (lap);
					if (dem < 30)
					{
						cout << '\n' <<" Nghiem cua he phuong trinh : ";
						xuat(y, n);
					}
					else
						cout << " "<< '\n' <<" He phtrinh ko giai duoc bang phuong phap nay";
					cout << '\n\n'<<" Ban tiep tuc ko(c/k)?";
					tt = getch();
					if (tt != 'c')
						break;
					system("pause");
				}
			}
			case 4:
				{
					cout <<" ket thuc chuong trinh"<< endl;
					break;
					
				}
			case 2: 
				{
					cout<<"khi sua xong can luu va thoat file de tiep tuc...	";
    				getline(cin, topicName);

    				topicName = "C:\\Users\\DELL\\OneDrive\\Documents\\nhapnvamatran.txt \"" + topicName + "\"";

    				system(topicName.c_str());
    				
    				break;
    				system("pause");
				}
	}
    } while(chon!=4);
	

}
