#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#define MAX 100

void menu()
{
    printf("\t ______________________________________ \n");
    printf("\t|                MENU                  |\n");
    printf("\t|--------------------------------------|\n");
    printf("\t| 1 - Nhap 2 ma tran                   |\n");
    printf("\t| 2 - Tinh tich 2 ma tran              |\n");
    printf("\t| 3 - In 3 ma tran                     |\n");
    printf("\t| 4 - Ket thuc                         |\n");
    printf("\t|______________________________________|\n");
    printf("\tVui long chon: ");
}

int nhapSo()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if (n<0)
            printf("\t\aSo phai lon hon 0!!! Nhap lai: ");
        else
            return n;
    }
}

void nhapMaTran(int a[][MAX], int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}
void inMaTran(int a[][MAX], int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

}
void tichHaiMaTran(int a[][MAX], int b[][MAX], int t[][MAX], int donga, int cotb,  int cotc){
    for(int i=0; i< donga; i++){
        for(int j=0; j<cotc; j++){
            t[i][j]=0;
            for(int k=0; k<cotb; k++){
                t[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}

void Loading()
{
    printf("\tLoading.");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(400);
}

int main()
{
    int select;
    int m1[MAX][MAX], m2[MAX][MAX], m_mul[MAX][MAX];
    int flag1 = 0;
    int flag2 = 0;
    int r1, n, c2, temp;
    printf("\n");
    Loading();
    system("cls");
    label:
    menu();
    scanf("%d",&select);
    switch(select)
    {
        case 1:
            {
                printf("\tNhap so dong, cot ma tran thu nhat: ");
                r1 = nhapSo();
                n = nhapSo();
                printf("\tNhap ma tran 1: \n");
                nhapMaTran(m1,r1,n);
                printf("\tNhap so dong, cot ma tran thu hai: ");
                do
                {
                    temp = nhapSo();
                    if (temp!=n)
                        printf("\tSo dong phai bang so cot ma tran truoc, nhap lai!!\n");
                }
                while (temp!=n);
                c2 = nhapSo();
                printf("\tNhap ma tran 2: ");
                nhapMaTran(m2,n,c2);
                printf("\tBan da nhap xong 2 ma tran\n");
                flag1 = 1;
                Loading();
                system("cls");
                goto label;
                break;
            }
        case 2:
            {
                if (flag1==0)
                {
                    printf("\t\aChua nhap ma tran!!!\n");
                    Loading();
                    system("cls");
                    goto label;
                }
                tichMaTran(m1,m2,m_mul,r1,n,c2);
                flag2 = 1;
                Loading();
                system("cls");
                goto label;
            }
        case 3:
            {
                if (flag1==0)
                {
                    printf("\t\aChua nhap ma tran!!!\n");
                    Loading();
                    system("cls");
                    goto label;
                }
                if (flag2==0)
                {
                    printf("\t\aChua tinh tich!!!\n");
                    Loading();
                    system("cls");
                    goto label;
                }
                printf("\tBa ma tran la: \n");
                inMaTran(m1,r1,n);
                printf("\n");
                inMaTran(m2,n,c2);
                printf("\n");
                inMaTran(m_mul,r1,c2);
                printf("\n");
                printf("\tBam phim bat ki de chon tiep\n");
                getch();
                system("cls");
                goto label;
            }
        case 4:
            {
                printf("\tBan da chon thoat. Xin chao!\n");
                Sleep(1000);
                exit(0);
            }
        default:
            {
                printf("\t\aNhap sai roi nhap lai di!!!\n");
                Loading();
                goto label;
            }
    }
    return 0;
}
