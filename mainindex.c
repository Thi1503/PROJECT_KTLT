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
    NVNode *tail ;
}; typedef struct NVList NVList;





// khai báo hàm
void deleteNewline(char x[]); // hàm xóa xuống dòng
int countNV(NVList NV_List); // hàm đếm số lượng node trong danh sách nhân viên
void createNVList(NVList *NV_List); // tạo danh sách nhân viên
NVNode* createNVNode(NV newNVNode); // tạo một node nhân viên mới
void importFileNV(NVList *NV_List,int n); // hàm nhập từ file NV.bin
void exportFileNV(NVList NV_List, int n); // hàm xuất dữ liệu ra file NV.bin
void enterNgaySinh(NgaySinh* ngay_Sinh);// hàm nhập ngày sinh nhân viên
void enterNV(NV *newNV); // hàm nhập vào thông tin nhân viên
void enterNgaySinh(NgaySinh* ngay_Sinh);// hàm nhập ngày sinh nhân viên
void addHeadNVList(NVList* NV_List, NVNode* node);
void addTailNVList(NVList* NV_List, NVNode* node);//hàm thêm phần tử vào cuối danh sách nhân viên
void addMiddleNVListAfterQ(NVList* NV_List, NVNode* p, NVNode* q);// hàm thêm phần tử vào sau phần tử q 

int main(){
    // NV newNV1,newNV2;
    // NVNode* newNVNode1;
    // NVNode* newNVNode2;
    // int len;
    // NVList NV_List;
    // createNVList(&NV_List);
    // printf("ok");
    // printf("\nNhap vao thong tinh nhan vien");
    // printf("\n%10s \t %20s \t %20s \t %10s %s","Ma so nhan vien","Ho ten dem","Ten nhan vien","Gioi tinh", "Ngay sinh");
    // printf("\n-----------------------------------------------------------------------------------------------------------------------------------");
    // enterNV(&newNV1);
    // newNVNode1 = createNVNode(newNV1);
    // addHeadNVList(&NV_List,&(*newNVNode1));
    // //printf("\n%d/%d/%d",newNV.ngaySinh.ngay,newNV.ngaySinh.thang,newNV.ngaySinh.nam);
    // enterNV(&newNV2);
    // newNVNode2 = createNVNode(newNV2);
    // addHeadNVList(&NV_List,&(*newNVNode2));
    // len = countNV(NV_List);
    // printf("\n%d",len);
    // exportFileNV(NV_List, len);
    // importFileNV(&NV_List,len);
     char fileName[100];
    printf("\nNhap vao duong dan hoac ten file:");
    fflush(stdin);
    fgets(fileName, sizeof(fileName), stdin);
    deleteNewline(fileName);

    FILE *f;
    f = fopen(fileName, "wb");
 
}

//hàm xóa xuống dòng
void deleteNewline(char x[]){
    size_t len = strlen(x);
    if(x[len-1]=='\n'){
        x[len-1]=='\0';
    }
}

//hàm đếm số lượng node trong danh sách nhân viên
int countNV(NVList NV_List){
    int count=0;
    if (NV_List.head != NULL){
        NVNode* node = NV_List.head;
        while(node != NULL){
            count++;
            node = node->next;
        }
    }
    return count;
}

// hàm tạo danh sách nhân viên
void createNVList(NVList *NV_List){
    NV_List->head = NULL;
    NV_List->tail = NULL;
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
    return newNVNode;
}

// hàm nhập dữ liệu từ file
void importFileNV(NVList *NV_List,int n){
    char fileName[100];
    NV newNV;
    NVNode* node;
    printf("\nNhap vao duong dan hoac ten file: ");
    fflush(stdin);
    fgets(fileName, sizeof(fileName), stdin);
    deleteNewline(fileName);

    FILE *f;
    f = fopen(fileName, "rb");
    if(f==NULL){
        printf("\nKhong the tim thay file!");
        printf("\nVui long nhap lai duong dan hoac ten file:");
        importFileNV(&NV_List, n);
    }
    fread(&n, sizeof(n),1,f);
    for(int i=0; i<n;i++){
        fread(&newNV, sizeof(NV), 1, f);
        node = createNVNode(newNV);
        if(NV_List->head == NULL){
            addHeadNVList(&(*NV_List), &(*node));
        }
        else{
            addTailNVList(&(*NV_List), &(*node));
        }
    }
    fclose(f);
}

// hàm xuất dữ liệu ra file 
void exportFileNV(NVList NV_List, int n){
    char fileName[100];
    printf("\nNhap vao duong dan hoac ten file:");
    fflush(stdin);
    fgets(fileName, sizeof(fileName), stdin);
    deleteNewline(fileName);

    FILE *f;
    f = fopen(fileName, "wb");
    // if(f!=NULL){
    //     printf("\nKhong tim thay duong dan hoac ten file!");
    //     printf("\nVui long nhap lai duong dan hoac ten file!");
    //     exportFileNV(NV_List,n);
    // }
    // fwrite(&n, sizeof(n),1,f);
    // for(int i; i<=0; i++){
    //     fwrite(&(NV_List.head), sizeof(NVNode),1,f);
    //     NV_List.head = NV_List.head->next;
    // }
    // fclose(f);
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



//hàm nhập vào thông tin nhân viên
void enterNV(NV *newNV){
    NgaySinh ngay_Sinh;
    printf("\nMa so nhan vien: ");
    scanf("%d", &newNV->maSoNV);
    printf("\nHo ten dem: ");
    fflush(stdin);
    fgets(newNV->hoDem, sizeof(newNV->hoDem), stdin);
    deleteNewline(newNV->hoDem);
    printf("\nTen nhan vien:");
    fflush(stdin);
    fgets(newNV->tenNV, sizeof(newNV->tenNV), stdin);
    deleteNewline(newNV->tenNV);
    printf("\nGioi tinh: ");
    fflush(stdin);
    fgets(newNV->gioiTinh, sizeof(newNV->gioiTinh), stdin);
    deleteNewline(newNV->gioiTinh);
    enterNgaySinh(&ngay_Sinh);
    newNV->ngaySinh.ngay = ngay_Sinh.ngay;
    newNV->ngaySinh.thang = ngay_Sinh.thang;
    newNV->ngaySinh.nam = ngay_Sinh.nam;
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
void addMiddleNVListAfterQ(NVList* NV_List, NVNode* p, NVNode* q){
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



