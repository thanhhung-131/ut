#include <iostream>
#include <math.h>
#include <conio.h>
#include <fstream>
#define MAX 100
#define exp 0.0001
using namespace std;
//void getCofactor(double a[][MAX], double temp[][MAX], int p, int q, int n)
//{
//    int i = 1, j = 1;
//  
//     Looping for each element of the matrix
//    for (int row = 1; row <= n; row++)
//    {
//        for (int col = 1; col <= n; col++)
//        {
//              Copying into temporary matrix only those element
//              which are not in given row and column
//            if (row != p && col != q)
//            {
//                temp[i][j++] = a[row][col];
//  
//                 Row is filled, so increase row index and
//                 reset col index
//                if (j == n - 1)
//                {
//                    j = 1;
//                    i++;
//                }
//            }
//        }
//    }
//}
//  
///* Recursive function for finding determinant of matrix.
//   n is current dimension of A[][]. */
//int determinant(double a[][MAX], int n)
//{
//    int D = 0; // Initialize result
//  
//      Base case : if matrix contains single element
//    if (n == 1)
//        return a[1][1];
//  
//    double temp[MAX][MAX]; // To store cofactors
//  
//    int sign = 1;  // To store sign multiplier
//  
//      Iterate for each element of first row
//    for (int f = 1; f <= n; f++)
//    {
//         Getting Cofactor of A[0][f]
//        getCofactor(a, temp, 1, f, n);
//        D += sign * a[1][f] * determinant(temp, n - 2);
//  
//         terms are to be added with alternate sign
//        sign = -sign;
//    }
//  
//    return D;
//}
//  
// Function to get adjoint of A[N][N] in adj[N][N].
//void adjoint(double a[][MAX],double adj[][MAX])
//{
//    if (n == 1)
//    {
//        adj[1][1] = 1;
//        return;
//    }
//  
//     temp is used to store cofactors of A[][]
//    int sign = 1;
//	double temp[MAX][MAX];
//  
//    for (int i=1; i<=n; i++)
//    {
//        for (int j=1; j<= n; j++)
//        {
//             Get cofactor of A[i][j]
//            getCofactor(a, temp, i, j, n);
//  
//             sign of adj[j][i] positive if sum of row
//             and column indexes is even.
//            sign = ((i+j)%2==0)? 1: -1;
//  
//             Interchanging rows and columns to get the
//             transpose of the cofactor matrix
//            adj[j][i] = (sign)*(determinant(temp, n-1));
//        }
//    }
//}
//  
// Function to calculate and store inverse, returns false if
// matrix is singular
//bool inverse(double a[MAX][MAX], double inverse[MAX][MAX])
//{
//     Find determinant of A[][]
//    double det = determinant(a, n);
//    if (det == 0)
//    {
//        cout << "Singular matrix, can't find its inverse";
//        return false;
//    }
//  
//     Find adjoint
//    int adj[MAX][MAX];
//    adjoint(a, adj);
//  
//     Find Inverse using formula "inverse(A) = adj(A)/det(A)"
//    for (int i=0; i<N; i++)
//        for (int j=0; j<N; j++)
//            inverse[i][j] = adj[i][j]/float(det);
//  
//    return true;
//}
//void layA(double b[][MAX],double a[][MAX], int &n){
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++){
//			a[i][j] = b[i][j];
//		}
//	}
//}
//void swap(double a[][MAX], int row1, int row2,
//          int col)
//{
//    for (int i = 0; i < col; i++)
//    {
//        int temp = a[row1][i];
//        a[row1][i] = a[row2][i];
//        a[row2][i] = temp;
//    }
//}
//int rankOfMatrix(double a[][MAX],int &n)
//{
//    int rank = n;
// 
//    for (int i = 0; i < rank; i++)
//    {
//         Before we visit current row 'row', we make
//         sure that mat[row][0],....mat[row][row-1]
//         are 0.
// 
//         Diagonal element is not zero
//        if (a[i][i])
//        {
//           for (int j = 1; i <= j;j ++)
//           {
//               if (i != j)
//               {
//                  This makes all entries of current
//                  column as 0 except entry 'mat[row][row]'
//                 double mult = (double)a[j][i] /
//                                       a[i][i];
//                 for (int i = 0; i < rank; i++)
//                   a[j][i] -= mult * a[i][i];
//              }
//           }
//        }
// 
//         Diagonal element is already zero. Two cases
//         arise:
//         1) If there is a row below it with non-zero
//            entry, then swap this row with that row
//            and process that row
//         2) If all elements in current column below
//            mat[r][row] are 0, then remvoe this column
//            by swapping it with last column and
//            reducing number of columns by 1.
//        else
//        {
//            bool reduce = true;
// 
//            /* Find the non-zero element in current
//                column  */
//            for (int k = i + 1; i < n;  i++)
//            {
//                 Swap the row with non-zero element
//                 with this row.
//                if (a[k][i])
//                {
//                    swap(a, i, k, rank);
//                    reduce = false;
//                    break ;
//                }
//            }
// 
//             If we did not find any row with non-zero
//             element in current columnm, then all
//             values in this column are 0.
//            if (reduce)
//            {
//                 Reduce number of columns
//                rank--;
// 
//                 Copy the last column here
//                for (int c = 1; c <= n; c ++)
//                    a[c][i] = a[c][rank];
//            }
// 
//             Process this row again
//            i--;
//        }
// 
//        Uncomment these lines to see intermediate results
//        display(mat, R, C);
//        printf("\n");
//    }
//    return rank;
//}
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
//bool check(double c[][MAX],int &n){ //dang lammmmmmmm
//	double a[MAX][MAX],i[MAX][MAX];
//	layA(c,a,n);
//	int ranka = rankOfMatrix(a,n);
//	inverse(a,i);
//	int ranka_ = rankOfMatrix(i,n);
//	if(ranka != ranka_)
//	{
//	 cout << "phuong trinh vo nghiem";
//	 return false;
//	}
//	if(ranka < ranka_)
//	{
//	 cout << "phuong trinh vo so nghiem";
//	 return true;
//	}
//	
//}
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
					{
						xuatmatran(a,n);
						cout << "phuong trinh co vo so nghiem";
						return ; /* ket thuc chuong trinh */
					}
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
				{   //check(a,n);
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
