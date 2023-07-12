#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//Khai báo biến và cấu trúc 

// Cấu trúc nhân viên 
struct NgaySinh {
    int ngay;
    int thang;
    int nam;
}; typedef struct NgaySinh NgaySinh;

struct NhanVien{
    int maSoNV;
    char hoDem[50];
    char tenNV[50];
    char gioiTinh[20];
    NgaySinh ngaySinh;
}; typedef struct NhanVien NV;

struct NVNode{
    NV nhanVien;
    struct NVNode* next;
}; typedef struct NVNode NVNode;

struct NVList{
    NVNode *head;
    NVNode *tail;
}; typedef struct NVList NVList;








// khai báo hàm
void createNVList(NVList *NV_List); // tạo danh sách nhân viên
NVNode* createNVNode(NV newNVNode); // tạo một node nhân viên mới





int main(){
    printf("ok");
}


// hàm tạo danh sách nhân viên
void createNVList(NVList *NV_List){
    NVList NV_Lish;
    NV_Lish.head = NULL;
    NV_Lish.tail = NULL;
}
// tạo một node nhân viên mới
NVNode* createNVNode(NV newNV){
    NVNode* newNVNode = (NVNode*)malloc(sizeof(NVNode));
    newNVNode->nhanVien.maSoNV = newNV.maSoNV;
    newNVNode->nhanVien.hoDem[50] = newNV.hoDem[50];
    newNVNode->nhanVien.tenNV[50] = newNV.tenNV[50];
    newNVNode->nhanVien.gioiTinh[20] = newNV.gioiTinh[20];
    newNVNode->nhanVien.ngaySinh.ngay = newNV.ngaySinh.ngay;
    newNVNode->nhanVien.ngaySinh.thang = newNV.ngaySinh.thang;
    newNVNode->nhanVien.ngaySinh.nam = newNV.ngaySinh.nam;
    newNVNode->next=NULL;
}