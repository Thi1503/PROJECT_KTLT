#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai bao ham va cau truc

// Cau truc cua ngay sinh
int size;
struct NgaySinh {
    int ngay;
    int thang;
    int nam;
};
typedef struct NgaySinh NgaySinh;

// Cau truc cua nhan vien
struct NhanVien {
    int maSoNV;
    char hoDem[50];
    char tenNV[50];
    char gioiTinh[20];
    NgaySinh ngaySinh;
};
typedef struct NhanVien NV;

// cau truc De tai
struct DeTai{
	char maDT[50];
	char tenDT[100];
	int namBatDau;
	int namKetThuc;
	long int kinhPhi;
}; 
typedef struct DeTai DT;

// Cau truc 1 node nhan vien trong danh sach lien ket
struct NVNode {
    NV data;
    struct NVNode* next;
};
typedef struct NVNode NVNode;

// cau truc 1 node de tai trong danh sach lien ket
struct DTNode {
	DT data;
	struct DTNode* next;
};
typedef struct DTNode DTNode;

// Cau truc cua danh sach lien ket nhan vien
struct NVList {
    NVNode* head;
    NVNode* tail;
};
typedef struct NVList NVList;

// cau truc cua danh sach lien ket de tai
struct DTList{
	DTNode* head;
	DTNode* tail;
};
typedef struct DTList DTList;













// Khai bao cac ham cua nhan vien
void deleteNewline(char x[]);             // xoa xuong dong 
int countNV(NVList NV_List);               // dem so node
void createNVList(NVList* NV_List);        // tao danh sach lien ket nhan vien
NVNode* createNVNode(NV newNVNode);        // tao node nhan vien
void enterNgaySinh(NgaySinh* ngay_Sinh);   // nhap vap ngay sinh
void enterNV(NV* newNV);                   // nhap vao thong tin nhan vien
void addHeadNVList(NVList* NV_List, NVNode* node); // them 1 node vao dau danh sach
void addTailNVList(NVList* NV_List, NVNode* node);         //them 1 node vao cuoi danh sach  
void addAtPositionNVList(NVList* NV_List, NVNode* new_node, int position); 
int removeHeadNVList(NVList* NV_List);  //xoa nhan vien dau danh sach
int removeTailNVList(NVList* NV_List);
int removeAtPositionNVList(NVList* NV_List, int position);
int updateNVList(NVList *NV_List);
void printNVList(NVList NV_List);     //in ra danh sach nhan vien
void exportFileNV(NVList NV_List);    // xuat ra file NV.bin
void importFileNV(NVList* NV_List);   // doc thong tin file NV.bin

// khai bao ham cua de tai
int countDT(DTList DT_List);
void createDTList(DTList* DT_List);
DTNode* createDTNode(DT newDTNode);
void enterDT(DT* newDT); 
void addHeadDTList(DTList* DT_List, DTNode* node);






int main() {
//	int position;
//    NV newNV1, newNV2;
//    NVNode *newNVNode1, *newNVNode2;
    NVList NV_List;
    DTList DT_List;
    DT newDT;
//    createNVList(&NV_List);
//	importFileNV(&NV_List);
//    printf("Nhap vao thong tin nhan vien");
//    enterNV(&newNV1);
//    printf("\nNhap vao vi tri: ");
//    scanf("%d",&position);
//    newNVNode1 = createNVNode(newNV1);
//    addAtPositionList(&NV_List, newNVNode1,position);

//    enterNV(&newNV2);
//    newNVNode2 = createNVNode(newNV2);
//    addTailNVList(&NV_List, newNVNode2);
    importFileNV(&NV_List);
    removeHeadNVList(&NV_List);
    printNVList(NV_List);
    enterDT(&newDT);
//	exportFileNV(NV_List);
//	printNVList(NV_List);
    return 0;
}

// xoa xuong dong
void deleteNewline(char x[]) {
    size_t len = strlen(x);
    if (x[len - 1] == '\n') {
        x[len - 1] = '\0';
    }
}

// dem so nhan vien trong danh sach
int countNV(NVList NV_List) {
    int count = 0;
    if (NV_List.head != NULL) {
        NVNode* node = NV_List.head;
        while (node != NULL) {
            count++;
            node = node->next;
        }
    }
    return count;
}

// tao danh sach nhan vien
void createNVList(NVList* NV_List) {
    NV_List->head = NULL;
    NV_List->tail = NULL;
}

// tao 1 node nhan vien
NVNode* createNVNode(NV newNV) {
    NVNode* newNVNode = (NVNode*)malloc(sizeof(NVNode));
    newNVNode->data = newNV;
    newNVNode->next = NULL;
    return newNVNode;
}

// nhap vao ngay sinh 
void enterNgaySinh(NgaySinh* ngay_Sinh) {
    printf("\nNgay sinh: ");
    scanf("%d", &ngay_Sinh->ngay);
    printf("Thang sinh: ");
    scanf("%d", &ngay_Sinh->thang);
    printf("Nam sinh: ");
    scanf("%d", &ngay_Sinh->nam);
}

// nhap vao thong tin nhan vien
void enterNV(NV* newNV) {
    printf("\nMa so nhan vien: ");
    scanf("%d", &newNV->maSoNV);
    printf("Ho ten dem: ");
    getchar();
    fgets(newNV->hoDem, sizeof(newNV->hoDem), stdin);
    deleteNewline(newNV->hoDem);
    printf("Ten nhan vien: ");
    fgets(newNV->tenNV, sizeof(newNV->tenNV), stdin);
    deleteNewline(newNV->tenNV);
    printf("Gioi tinh: ");
    fgets(newNV->gioiTinh, sizeof(newNV->gioiTinh), stdin);
    deleteNewline(newNV->gioiTinh);
    enterNgaySinh(&newNV->ngaySinh);
}

// them 1 node vao dau danh sach
void addHeadNVList(NVList* NV_List, NVNode* node) {
    if (NV_List->head == NULL) {
        NV_List->head = node;
        NV_List->tail = node;
    } else {
        node->next = NV_List->head;
        NV_List->head = node;
    }
}

// them 1 node vao cuoi danh sach
void addTailNVList(NVList* NV_List, NVNode* node) {
    if (NV_List->head == NULL) {
        NV_List->head = node;
        NV_List->tail = node;
    } else {
        NV_List->tail->next = node;
        NV_List->tail = node;
    }
}

void addAtPositionList(NVList* NV_List, NVNode* new_node, int position) {
    if (position <= 0) {
        addHeadNVList(NV_List, new_node);
    } else if (position >= countNV(*NV_List)) {
        addTailNVList(NV_List, new_node);
    } else {
        NVNode* node = NV_List->head;
        int count = 0;
        while (count < position - 1) {
            node = node->next;
            count++;
        }
        new_node->next = node->next;
        node->next = new_node;
    }
}

int removeHeadNVList(NVList* NV_List){
	if (NV_List->head != NULL){
		NVNode* node = NV_List->head;
		NV_List->head = node->next;
		free(node);
		if(NV_List == NULL){
			NV_List->tail = NULL;
		}
		return 1;
	}
	return 0;
}


int removeTailNVList(NVList* NV_List) {
    if (NV_List->head == NULL) {
    } else if (NV_List->head == NV_List->tail) {
        free(NV_List->head);
        NV_List->head = NULL;
        NV_List->tail = NULL;
        return 1;
    } else {
        NVNode* prev_node = NULL;
        NVNode* current_node = NV_List->head;
        while (current_node->next != NULL) {
            prev_node = current_node;
            current_node = current_node->next;
        }
        free(current_node);
        prev_node->next = NULL;
        NV_List->tail = prev_node;
        return 1;
    }
}


int removeAtPositionNVList(NVList* NV_List, int position) {
    if (position <= 0) {
        return removeHeadNVList(NV_List);
    } else if (position >= countNV(*NV_List)) {
        return removeTailNVList(NV_List);
    } else {
        NVNode* prev_node = NULL;
        NVNode* current_node = NV_List->head;
        int count = 0;
        while (count < position) {
            prev_node = current_node;
            current_node = current_node->next;
            count++;
        }
        prev_node->next = current_node->next;
        free(current_node);
        return 1;
    }
}



int updateNVList(NVList* NV_List) {
	int maSoNV;
	printf("\nNhap vao ma so nhan vien: ");
	scanf("%d", &maSoNV);
    NVNode* node = NV_List->head;
    while (node != NULL) {
        if (node->data.maSoNV == maSoNV) {
            // T�m th?y nh�n vi�n c?n c?p nh?t
            printf("Nhap thong tin moi cho nhan vien (Ma so nhan vien: %d):\n", maSoNV);
            enterNV(&node->data);
            return 1;
        }
        node = node->next;
    }
    // Kh�ng t�m th?y nh�n vi�n
    return 0;
}


// in ra danh sach nhan vien
void printNVList(NVList NV_List) {
    if (NV_List.head != NULL) {
        NVNode* node = NV_List.head;
        printf("\n |%20s \t |%30s \t |%30s \t |%20s \t |\t%s |", "Ma so nhan vien", "Ho ten dem", "Ten nhan vien", "Gioi tinh", "Ngay sinh");
        while (node != NULL) {
            printf("\n |%20d \t |%30s \t |%30s \t |%20s \t |\t%02d/%02d/%d|", node->data.maSoNV, node->data.hoDem,
                node->data.tenNV, node->data.gioiTinh, node->data.ngaySinh.ngay, node->data.ngaySinh.thang, node->data.ngaySinh.nam);
            node = node->next;
        }
    }
}

// xuat vao file NV.bin
void exportFileNV(NVList NV_List) {
    FILE* f;
    f = fopen("NV.bin", "wb");
    if (f == NULL) {
        printf("Khong the mo file de ghi!");
        return;
    }
    int count = countNV(NV_List);
    fwrite(&count, sizeof(count), 1, f);
    NVNode* node = NV_List.head;
    while (node != NULL) {
        fwrite(&node->data, sizeof(NV), 1, f);
        node = node->next;
    }
    fclose(f);
}

// doc du lieu tu file NV.bin
void importFileNV(NVList* NV_List) {
	int i;
    FILE* f;
    f = fopen("NV.bin", "rb");
    if (f == NULL) {
        printf("Khong the mo file de doc!");
        return;
    }
    int count;
    fread(&count, sizeof(count), 1, f);
    for (i = 0; i < count; i++) {
        NV newNV;
        fread(&newNV, sizeof(NV), 1, f);
        NVNode* newNVNode = createNVNode(newNV);
        addTailNVList(NV_List, newNVNode);
    }
    fclose(f);
}





int countDT(DTList DT_List) {
    int count = 0;
    if (DT_List.head != NULL) {
        DTNode* node = DT_List.head;
        while (node != NULL) {
            count++;
            node = node->next;
        }
    }
    return count;
}


void createDTList(DTList* DT_List) {
    DT_List->head = NULL;
    DT_List->tail = NULL;
}


DTNode* createDTNode(DT newDT) {
    DTNode* newDTNode = (DTNode*)malloc(sizeof(DTNode));
    newDTNode->data = newDT;
    newDTNode->next = NULL;
    return newDTNode;
}


void enterDT(DT* newDT) {
    printf("\nMa de tai: ");
    fgets(newDT->maDT, sizeof(newDT->maDT),stdin);
    deleteNewline(newDT->tenDT);
    printf("\nTen De Tai: ");
    fgets(newDT->tenDT, sizeof(newDT->tenDT), stdin);
    deleteNewline(newDT->tenDT);
    printf("\nNam bat dau: ");
    scanf("%d",&newDT->namBatDau);
    printf("\nNam ket thuc: ");
    scanf("%d", &newDT->namKetThuc);
    printf("\nKinh phi de tai: ");
    scanf("%ld", &newDT->kinhPhi);
}






































