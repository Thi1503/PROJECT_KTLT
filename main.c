#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>



struct nhanVien{
    int maSoNV[20];
    char hoDem[50];
    char tenNV[50];
    char gioiTinh[20];
}
typedef struct nhanVien NV;

struct deTai{
    char maDeTai[20];
    char tenDeTai[100];
    int namBatDau[20];
    int namKetThuc[20];
    int kinhPhi[100];
}
typedef struct deTai DT;

struct NVDT {
    int maDeTai[20];
    int maSoNV[20];
    char vaiTro[50];
}
typedef struct NVDT NVDT;







int main(){

}