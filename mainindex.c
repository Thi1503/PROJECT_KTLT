#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//Khai báo biến và cấu trúc 

//Các cấu trúc của nhân viên 
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
void enterNV(NV *newNV); // hàm nhập vào thông tin nhân viên
void enterNgaySinh(NgaySinh* ngay_Sinh);// hàm nhập ngày sinh nhân viên
void addHeadNVList(NVList* NV_List, NVNode* node);// hàm thêm phần tử vào đầu danh sách nhân viên
void addTailNVList(NVList* NV_List, NVNode* node);//hàm thêm phần tử vào cuối danh sách nhân viên
void addMiddleNVListAfterQ(NVList* NV_List, NVNode* p, Node* q);// hàm thêm phần tử vào sau phần tử q 


int main(){
    NV newNV;
    NVList NV_List;
    createNVList(&NV_List);
    printf("ok");
    printf("\nNhap vao thong tinh nhan vien");
    printf("\n%10s \t %20s \t %20s \t %10s %s","Ma so nhan vien","Ho ten dem","Ten nhan vien","Gioi tinh", "Ngay sinh");
    printf("\n-----------------------------------------------------------------------------------------------------------------------------------");
    enterNV(&newNV);
    printf("\n%d/%d/%d",newNV.ngaySinh.ngay,newNV.ngaySinh.thang,newNV.ngaySinh.nam);
}


// hàm tạo danh sách nhân viên
void createNVList(NVList *NV_List){
    NV_List->head = NULL;
    NV_List->tail = NULL;
}

// hàm thêm phần tử vào đầu danh sách nhân viên
void addHeadNVList(NVList* NV_List, NVNode* node){
    if(NV_List->head == NULL){
        NV_List->head = node;
        NV_List->tail = node;
    }
    else{
        node->next = NV_List->head;
         NV_List->head = node;
    }
}

//hàm thêm phần tử vào cuối danh sách nhân viên
void addTailNVList(NVList* NV_List, NVNode* node){
     if(NV_List->head == NULL){
        NV_List->head = node;
        NV_List->tail = node;
    }
    else{
        NV_List->tail->next = node;
        NV_List->tail = node;
    }
}

// hàm thêm phần tử vào sau phần tử q 
void addMiddleNVListAfterQ(NVList* NV_List, NVNode* p, Node* q){
    if(q!=NULL){
        p->next =q ->next;
        q->next = p;
        if(NV_List->tail==q){
            NV_List->tail = p;
        }
    }
    else{
        addHeadNVList(NV_List,p);
    }
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

//hàm nhập vào thông tin nhân viên
void enterNV(NV *newNV){
    NgaySinh ngay_Sinh;
    printf("\nMa so nhan vien: ");
    scanf("%d", &newNV->maSoNV);
    printf("\nHo ten dem: ");
    fflush(stdin);
    fgets(newNV->hoDem, sizeof(newNV->hoDem), stdin);
    printf("\nTen nhan vien:");
    fflush(stdin);
    fgets(newNV->tenNV, sizeof(newNV->tenNV), stdin);
    printf("\nGioi tinh: ");
    fflush(stdin);
    fgets(newNV->gioiTinh, sizeof(newNV->gioiTinh), stdin);
    enterNgaySinh(&ngay_Sinh);
    newNV->ngaySinh.ngay = ngay_Sinh.ngay;
    newNV->ngaySinh.thang = ngay_Sinh.thang;
    newNV->ngaySinh.nam = ngay_Sinh.nam;
}

// hàm nhập vào ngày sinh nhân viên
void enterNgaySinh(NgaySinh* ngay_Sinh){
    printf("\nNgay sinh:");
    scanf("%d",&ngay_Sinh->ngay);
    printf("\nThang sinh:");
    scanf("%d",&ngay_Sinh->thang);
    printf("\nNam sinh:");
    scanf("%d",&ngay_Sinh->nam);
}
