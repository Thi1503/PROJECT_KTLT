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

// cau truc nhiem vu de tai
struct NhiemVuDeTai{
	char maDT[50];
	int maSoNV;
	char vaiTro[50];
};
typedef struct NhiemVuDeTai NVDT;

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

// cau truc 1 node nhiem vu de tai trong danh sach lien ket
struct NVDTNode{
	NVDT data;
	struct NVDTNode* next;
};
typedef struct NVDTNode NVDTNode;

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

// cau truc danh sach lien ket nhiem vu de tai
struct NVDTList{
	NVDTNode* head;
	NVDTNode* tail;
};
typedef struct NVDTList NVDTList;




NVList NV_List;
DTList DT_List;
NVDTList NVDT_List;


int checkNV_NVDT(int maSoNV);
void removeNVByMaSoNV(NVList* NV_List);

 void removeDTByMaDT(DTList* DT_List);
 int checkDT_NVDT(char maDT[]);

void removeNVDTByMaDTAndMaSoNV(NVDTList* NVDT_List);



// Khai bao cac ham cua nhan vien
void deleteNewline(char x[]);             // xoa xuong dong 
int countNV(NVList NV_List);               // dem so node
void createNVList(NVList* NV_List);        // tao danh sach lien ket nhan vien
NVNode* createNVNode(NV newNVNode);        // tao node nhan vien
void enterNgaySinh(NgaySinh* ngay_Sinh);
int checkNV(int maSoNV);   
void enterNV(NV* newNV);                   // nhap vao thong tin nhan vien
void addHeadNVList(NVList* NV_List, NVNode* node); // them 1 node vao dau danh sach
void addTailNVList(NVList* NV_List, NVNode* node);         //them 1 node vao cuoi danh sach  
void addAtPositionNVList(NVList* NV_List, NVNode* newNode, int position); 
void addNVToList(NVList* NV_List);  // th�m nhieu sinh vien vao danh sach
int removeHeadNVList(NVList* NV_List);  //xoa nhan vien dau danh sach
int removeTailNVList(NVList* NV_List);
int removeAtPositionNVList(NVList* NV_List, int position);
NVNode* getNVNode(NVList* NV_List, int position);
NVNode* searchNVNodeByMaSoNV(NVList NV_List);
int updateNVList(NVList *NV_List);
void printNVList(NVList NV_List);     //in ra danh sach nhan vien
void printNVNode(NVNode node);
void writeToTailNVFile(NV newNV);
void exportFileNV(NVList NV_List);    // xuat ra file NV.bin
void importFileNV(NVList* NV_List);   // doc thong tin file NV.bin

// khai bao ham cua de tai
int countDT(DTList DT_List);
void createDTList(DTList* DT_List);
DTNode* createDTNode(DT newDTNode);
int checkDT(char maDT[]); 
void enterDT(DT* newDT); 
void addHeadDTList(DTList* DT_List, DTNode* node);
void addTailDTList(DTList* DT_List, DTNode* node);
void addAtPositionDTList(DTList* DT_List, DTNode* newNode, int position);
void addDTToList(DTList* DT_List);
int removeHeadDTList(DTList* DT_List);
int removeTailDTList(DTList* DT_List);
int removeAtPositionDTList(DTList* DT_List, int position);
DTNode* getDTNode(DTList* DT_List, int position);
DTNode* searchDTNodeByMaDeTai(DTList DT_List);
int updateDTList(DTList *DT_List);
void printDTList(DTList DT_List);
void printDTNode(DTNode node);
void writeToTailDTFile(DT newDT);
void exportFileDT(DTList DT_List);
void importFileDT(DTList* DT_List); 

// khai bao ham cua nhiem vu de tai
int countNVDT(NVDTList NVDT_List);
void createNVDTList(NVDTList* NVDT_List);
NVDTNode* createNVDTNode(NVDT newNVDTNode);
int checkNVDT(char maDT[], int maSoNV); 
void enterNVDT(NVDT* newNVDT); 
void addHeadNVDTList(NVDTList* NVDT_List, NVDTNode* node);
void addTailNVDTList(NVDTList* NVDT_List, NVDTNode* node);
void addAtPositionNVDTList(NVDTList* NVDT_List, NVDTNode* newNode, int position);
void addNVDTToList(NVDTList* NVDT_List);
int removeHeadNVDTList(NVDTList* NVDT_List);
int removeTailNVDTList(NVDTList* NVDT_List);
int removeAtPositionNVDTList(NVDTList* NVDT_List, int position);
NVDTNode* getNVDTNode(NVDTList* NVDT_List, int position);
NVDTNode* searchNVDTNodeByMaDeTaiAndMaSoNV(NVDTList NVDT_List);
int updateNVDTList(NVDTList *NVDT_List);
void printNVDTList(NVDTList NVDT_List);
void printNVDTNode(NVDTNode node);
void writeToTailNVDTFile(NVDT newNVDT);
void exportFileNVDT(NVDTList NVDT_List);
void importFileNVDT(NVDTList* NVDT_List); 


static int menuPoint1 = 0;
static int menuPoint2 = 0;
static int menuPointNV = 0;
int main() {
	addNVDTToList(&NVDT_List);
//	importFileNVDT(&NVDT_List); 
//	printNVDTList(NVDT_List);
//	removeNVDTByMaDTAndMaSoNV(&NVDT_List);
//	printNVDTList(NVDT_List);
	
	
	
//	menuLevelOne(menuPoint1);
//	int programRun =1;
//	int runNV=1;
//	while(programRun){
//		char c = getch();
//		if (c == -32){
//			c = getch();
//		}
//	switch(c){
//		case 0:
//			
//		case 72: //up
//			menuPoint1 = menuPoint1 - 1;
//			system("cls||clear");
//			menuLevelOne(menuPoint1);
//		break;
//		
//		case 80: //down
//			menuPoint1 = menuPoint1 + 1;
//			system("cls||clear");
//			menuLevelOne(menuPoint1);
//		break;
//		
//		case 13: // enter
//			switch ((unsigned int) menuPoint1 % 3){
//				case 0:
//					system("cls||clear");
////					menuNV(menuPointNV);
//					menuNV_LV1(menuPointNV);
//					break;
//					
//				case 1:
//					printf("De tai\n");
//					break;
//				
//				case 3:
//					printf("Nhiem vu de tai\n");
//					break;
//			}
//		break;
//		case 27:
//		case 8:
//			programRun = 0;
//			printf("Ket thuc chuong trinh\n");
//			break;
//	}
//	
//	}
//	return 0;
}


void menuLevelOne(int choose){
	int i;
	char menuOne[3][100] ={
		"|  | 1. Nhan vien\n",
		"|  | 2. De tai\n",
		"|  | 3. Nhiem vu de tai\n"
	};
	
	printf("Menu lua chon: \n");
	
	*(menuOne[(unsigned int)choose%3]+1) = (char)45;
	*(menuOne[(unsigned int)choose%3]+2) = (char)62;
	for(i= 0; i<3;i++){
		printf(menuOne[i]);
	}
}

void menuNV(int choose){
	int i;
	char menuNV[3][100] ={
		"|  | 1. Bo sung du lieu\n",
		"|  | 2. Xoa du lieu\n",
		"|  | 3. Cap nhat du lieu\n"
	};
	printf("Chon thao tac xu ly voi bang \"Nhan vien\" "": \n");
	
	*(menuNV[(unsigned int)choose%3]+1) = (char)45;
	*(menuNV[(unsigned int)choose%3]+2) = (char)62;
	for(i= 0; i<3;i++){
		printf(menuNV[i]);
	}
}

void menuNV_LV1(int choose){
	menuNV(choose);
	int runNV =1;
	while(runNV){
		char cNV = getch();
		if (cNV == -32){
			cNV = getch();
		}
		switch(cNV){
			case 72:
				choose = choose -1;
				system("cls||clear");
				menuNV(choose);
			break;
								
			case 80:
				choose = choose +1;
				system("cls||clear");
				menuNV(choose);
			break;
							
			case 75:
			case 27:
			case 8:
			break;
		}
	}
}




















// xoa xuong dong
void deleteNewline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
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


int checkNV(int maSoNV) {
    NVNode* node = NV_List.head;
    while (node != NULL) {
        if (node->data.maSoNV == maSoNV) {
            return 1;
        }
        node = node->next;
    }
    return 0; 
}



// nhap vao thong tin nhan vien
void enterNV(NV* newNV) {
    printf("\nMa so nhan vien: ");
    scanf("%d", &newNV->maSoNV);
    while(checkNV(newNV->maSoNV)==1){
    	printf("\nMa so nhan vien da ton tai trond danh sach !");
    	printf("\nVui long nhap lai ma so nhan vien khac !");
    	printf("\nMa so nhan vien: ");
        scanf("%d", &newNV->maSoNV);
	}
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

void addAtPositionNVList(NVList* NV_List, NVNode* newNode, int position) {
    if (position <= 0) {
        addHeadNVList(NV_List, newNode);
    } else if (position >= countNV(*NV_List)) {
        addTailNVList(NV_List, newNode);
    } else {
        NVNode* node = NV_List->head;
        int count = 0;
        while (count < position - 1) {
            node = node->next;
            count++;
        }
        newNode->next = node->next;
        node->next = newNode;
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
    	return 0;
    } else if (NV_List->head == NV_List->tail) {
        free(NV_List->head);
        NV_List->head = NULL;
        NV_List->tail = NULL;
        return 1;
    } else {
        NVNode* prevNode = NULL;
        NVNode* currentNode = NV_List->head;
        while (currentNode->next != NULL) {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        free(currentNode);
        prevNode->next = NULL;
        NV_List->tail = prevNode;
        return 1;
    }
}


int removeAtPositionNVList(NVList* NV_List, int position) {
    if (position <= 0) {
        return removeHeadNVList(NV_List);
    } else if (position >= countNV(*NV_List)) {
        return removeTailNVList(NV_List);
    } else {
        NVNode* prevNode = NULL;
        NVNode* currentNode = NV_List->head;
        int count = 0;
        while (count < position) {
            prevNode = currentNode;
            currentNode = currentNode->next;
            count++;
        }
        prevNode->next = currentNode->next;
        free(currentNode);
        return 1;
    }
}


int checkNV_NVDT(int maSoNV) {
    NVDTNode* node = NVDT_List.head;
    while (node != NULL) {
        if (maSoNV == node->data.maSoNV) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}


void removeNVByMaSoNV(NVList* NV_List){
    NVNode* nodeToDelete = searchNVNodeByMaSoNV(*NV_List);
    if (nodeToDelete != NULL) {
        if(!checkNV_NVDT(nodeToDelete->data.maSoNV)){
        	if (nodeToDelete == NV_List->head) {
            	NV_List->head = nodeToDelete->next;
        	} 
			else {
            	NVNode* prevNode = NV_List->head;
            	while (prevNode != NULL && prevNode->next != nodeToDelete) {
                	prevNode = prevNode->next;
        		}
            	if (prevNode != NULL) {
               		prevNode->next = nodeToDelete->next;
            	}
        	}
		}
		else{
			printf("\Khong the xoa vi nhan vien co trong danh sach \"Nhan vien de tai\"");
		}
	}

    
    free(nodeToDelete);
}



NVNode* getNVNode(NVList* NV_List, int position){
	NVNode* node = NV_List->head;
	int i = 0;
	while(node!= NULL && i != position){
		node = node->next;
		i++;
	}
	if (i == position && node != NULL){
		return node;
	}
	return NULL;
}


NVNode* searchNVNodeByMaSoNV(NVList NV_List){
	int maSoNV;
	NVNode* node = NV_List.head;
	printf("\nNhap vao ma so nhan vien: ");
	scanf("%d", &maSoNV);
	while (node != NULL && node->data.maSoNV != maSoNV){
		node = node->next;
	}
	if(node != NULL){
		return node;
	}
	else{
		printf("\nNhan vien khong co trong danh sach!");
		return NULL;
	}
	
}

int updateNVList(NVList* NV_List) {
	int maSoNV;
	NVNode* node = NV_List->head;
	printf("\nNhap vao ma so nhan vien: ");
	scanf("%d", &maSoNV);
    while (node != NULL) {
        if (node->data.maSoNV == maSoNV) {
            printf("Nhap thong tin moi cho nhan vien (Ma so nhan vien: %d):\n", maSoNV);
            enterNV(&node->data);
            return 1;
        }
        node = node->next;
    }
    return 0;
}


// in ra danh sach nhan vien
void printNVList(NVList NV_List) {
    if (NV_List.head != NULL) {
        NVNode* node = NV_List.head;
        printf("\n |%20s \t |%30s \t |%30s \t |%20s \t |\t%26s |", "Ma so nhan vien", "Ho ten dem", "Ten nhan vien", "Gioi tinh", "Ngay sinh");
        while (node != NULL) {
            printf("\n |%20d \t |%30s \t |%30s \t |%20s \t |\t%20d/%d/%d|", node->data.maSoNV, node->data.hoDem,
                node->data.tenNV, node->data.gioiTinh, node->data.ngaySinh.ngay, node->data.ngaySinh.thang, node->data.ngaySinh.nam);
            node = node->next;
        }
    }
    else{
    	printf("\nDanh sach nhan vien trong !");
	}
}

void printNVNode(NVNode node){
	printf("\n |%20s \t |%30s \t |%30s \t |%20s \t |\t%26s |", "Ma so nhan vien", "Ho ten dem", "Ten nhan vien", "Gioi tinh", "Ngay sinh");
	printf("\n |%20d \t |%30s \t |%30s \t |%20s \t |\t%20d/%d/%d|", node.data.maSoNV, node.data.hoDem,
	node.data.tenNV, node.data.gioiTinh, node.data.ngaySinh.ngay, node.data.ngaySinh.thang, node.data.ngaySinh.nam);
}


void addNVToList(NVList* NV_List) {
    int i;
    int size;
    printf("\nNhap vao so luong nhan vien: ");
    scanf("%d", &size);
    NV *newNV = (NV*)malloc(size * sizeof(NV));
    for (i = 0; i < size; i++) {
        printf("\nNhan vien thu %d", i + 1);
        enterNV(&newNV[i]);
        writeToTailNVFile(newNV[i]);
        NVNode *node = createNVNode(newNV[i]);
        addTailNVList(NV_List, node);
    }
    free(newNV);
}



void writeToTailNVFile(NV newNV){
	FILE* f;
	f = fopen("NV.bin", "ab");
    if (f == NULL) {
        printf("Khong the mo file de ghi!");
        return;
    }
    fwrite(&newNV, sizeof(NV),1 ,f);
    fclose(f);
}

// xuat vao file NV.bin
void exportFileNV(NVList NV_List) {
	NVNode* node = NV_List.head;
    FILE* f;
    f = fopen("NV.bin", "wb");
    if (f == NULL) {
        printf("Khong the mo file de ghi!");
        return;
    }
    while (node != NULL) {
        fwrite(&node->data, sizeof(NV), 1, f);
        node = node->next;
    }
    fclose(f);
}

void importFileNV(NVList* NV_List) {
    long i;
    FILE* f;
    f = fopen("NV.bin", "rb");
    if (f == NULL) {
        printf("Khong the mo file de doc!");
        return;
    }
    fseek(f, 0, SEEK_END);
    long f_size = ftell(f);
    fseek(f, 0, SEEK_SET);
    NV *newNV = (NV*)malloc(f_size);
    NVNode* node;
    fread(newNV, sizeof(NV), f_size / sizeof(NV), f);
    fclose(f);
    for (i = 0; i < f_size / sizeof(NV); i++) {
        node = createNVNode(newNV[i]);
        addTailNVList(NV_List, node);
    }
    free(newNV);
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

int checkDT(char maDT[]) {
    DTNode* node = DT_List.head;
    while (node != NULL) {
        if (strcmp(node->data.maDT, maDT) == 0) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

// Function to enter a new research topic into the list
void enterDT(DT* newDT) {
    printf("\nMa de tai: ");
    fgets(newDT->maDT, sizeof(newDT->maDT), stdin);
    deleteNewline(newDT->maDT);
    while (checkDT(newDT->maDT) == 1) {
        printf("\nMa de tai da ton tai trong danh sach !");
        printf("\nVui long nhap lai ma de tai !");
        printf("\nMa de tai: ");
        fgets(newDT->maDT, sizeof(newDT->maDT), stdin);
        deleteNewline(newDT->maDT);
    }
    printf("\nTen De Tai: ");
    fgets(newDT->tenDT, sizeof(newDT->tenDT), stdin);
    deleteNewline(newDT->tenDT);
    printf("\nNam bat dau: ");
    scanf("%d", &newDT->namBatDau);
    printf("\nNam ket thuc: ");
    scanf("%d", &newDT->namKetThuc);
    printf("\nKinh phi de tai: ");
    scanf("%ld", &newDT->kinhPhi);
}
void addHeadDTList(DTList* DT_List, DTNode* node){
	if(DT_List->head == NULL){
		DT_List->head = node;
		DT_List->tail = node;
	}
	else{
		node->next = DT_List->head;
		DT_List->head = node;
	}
}


void addTailDTList(DTList* DT_List, DTNode* node){
	if(DT_List->head == NULL){
		DT_List->head = node;
		DT_List->tail = node;
	}
	else{
		DT_List->tail->next = node;
		DT_List->tail = node;
	}
}


void addAtPositionDTList(DTList* DT_List, DTNode* newNode, int position) {
    if (position <= 0) {
        addHeadDTList(DT_List, newNode);
    } else if (position >= countDT(*DT_List)) {
        addTailDTList(DT_List, newNode);
    } else {
        DTNode* node = DT_List->head;
        int count = 0;
        while (count < position - 1) {
            node = node->next;
            count++;
        }
        newNode->next = node->next;
        node->next = newNode;
    }
}


int removeHeadDTList(DTList* DT_List){
	if (DT_List->head != NULL){
		DTNode* node = DT_List->head;
		DT_List->head = node->next;
		free(node);
		if(DT_List->head == NULL){
			DT_List->tail = NULL;
		}
		return 1;
	}
	return 0;
}



int removeTailDTList(DTList* DT_List){
	if (DT_List->head == NULL){
		return 0;
	}
	else if (DT_List->head == DT_List->tail){
		free(DT_List->head);
		DT_List->head = NULL;
		DT_List->tail = NULL;
	}
	else{
		DTNode* prevNode = NULL;
		DTNode* currentNode = DT_List->head;
		while(currentNode->next != NULL){
			prevNode = currentNode;
			currentNode = currentNode->next;
		}
		free(currentNode);
		prevNode->next = NULL;
		DT_List->tail = prevNode;
	}
}
 

 int removeAtPositionDTList(DTList* DT_List, int position){
 	if (position<=0){
 		return removeHeadDTList(DT_List);
	 }
	 else if (position >= countDT(*DT_List)){
	 	return removeTailDTList(DT_List);
	 }
	 else{
	 	DTNode* prevNode = NULL;
	 	DTNode* currentNode = DT_List->head;
	 	int count = 0;
	 	while(count < position){
	 		prevNode = currentNode;
	 		currentNode = currentNode->next;
	 		count++;
		 }
		prevNode->next = currentNode->next;
		free(currentNode);
	 }
 }
 

 int checkDT_NVDT(char maDT[]) {
    NVDTNode* node = NVDT_List.head;
    while (node != NULL) {
        if (strcmp(node->data.maDT, maDT) == 0) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void removeDTByMaDT(DTList* DT_List){
    DTNode* nodeToDelete = searchDTNodeByMaDeTai(*DT_List);
    if (nodeToDelete != NULL) {
        if(!checkDT_NVDT(nodeToDelete->data.maDT)){
        	if (nodeToDelete == DT_List->head) {
            	DT_List->head = nodeToDelete->next;
        	} 
			else {
            	DTNode* prevNode = DT_List->head;
            	while (prevNode != NULL && prevNode->next != nodeToDelete) {
                	prevNode = prevNode->next;
        		}
            	if (prevNode != NULL) {
               		prevNode->next = nodeToDelete->next;
            	}
        	}
		}
		else{
			printf("\Khong the xoa vi de tai co trong danh sach \"Nhan vien de tai\"");
		}
	}

    
    free(nodeToDelete);
}


 
 
 
 
 
 
 
 
 
 DTNode* getDTNode(DTList* DT_List, int position){
	DTNode* node = DT_List->head;
	int i = 0;
	while(node!= NULL && i != position){
		node = node->next;
		i++;
	}
	if (i == position && node != NULL){
		return node;
	}
	return NULL;
}




DTNode* searchDTNodeByMaDeTai(DTList DT_List) {
    char maDT[50];
    DTNode* node = DT_List.head;
    
    printf("\nNhap vao ma de tai muon tim kiem: ");
    fgets(maDT, sizeof(maDT), stdin);
    deleteNewline(maDT);

    while (node != NULL) {
        if (strcmp(node->data.maDT, maDT) == 0) {
            return node; 
        }
        node = node->next;
    }

    printf("\nDe tai khong co trong danh sach!");
    return NULL;
}


int updateDTList(DTList* DT_List){
	char maDT[50];
	DTNode* node = DT_List->head;
	printf("\nNhap vao ma de tai: ");
	fgets(maDT, sizeof(maDT),stdin);
	deleteNewline(maDT);
	while(node != NULL){
		if (strcmp(node->data.maDT, maDT) == 0){
			printf("\nNhap vao thong tin moi cho de tai (Ma de tai: %s):", maDT);
			enterDT(&node->data);
			return 1;
		}
		node = node->next;
	}
	return 0;
}



void printDTList(DTList DT_List){
	if (DT_List.head != NULL){
		DTNode* node = DT_List.head;
		printf("\n |%20s \t |%50s \t |%20s \t |%20s \t |%30s |", "Ma de tai", "Ten de tai", "Nam bat dau", "Nam ket thuc","Kinh phi de tai");
		while(node != NULL){
			printf("\n |%20s \t |%50s \t |%20d \t |%20d \t |%30ld |", node->data.maDT, node->data.tenDT, node->data.namBatDau, node->data.namKetThuc, node->data.kinhPhi );
			node = node->next;
		}
	}
	else{
		printf("Danh sach de tai trong !");
	}
}

void printDTNode(DTNode node){
	printf("\n |%20s \t |%50s \t |%20s \t |%20s \t |%30s |", "Ma de tai", "Ten de tai", "Nam bat dau", "Nam ket thuc","Kinh phi de tai");
	printf("\n |%20s \t |%50s \t |%20d \t |%20d \t |%30ld |", node.data.maDT, node.data.tenDT, node.data.namBatDau, node.data.namKetThuc, node.data.kinhPhi );
}

void addDTToList(DTList* DT_List) {
    int i;
    int size;
    printf("\nNhap vao so luong de tai: ");
    scanf("%d", &size);
    DT *newDT = (DT*)malloc(size * sizeof(DT));
    for (i = 0; i < size; i++) {
        printf("\nDe tai thu %d", i + 1);
//        getchar();
        enterDT(&newDT[i]);
        writeToTailDTFile(newDT[i]);
        DTNode *node = createDTNode(newDT[i]);
        addTailDTList(DT_List, node);
    }
    free(newDT);
}



void writeToTailDTFile(DT newDT){
	FILE* f;
	f = fopen("DT.bin", "ab");
    if (f == NULL) {
        printf("Khong the mo file de ghi!");
        return;
    }
    fwrite(&newDT, sizeof(DT),1 ,f);
    fclose(f);
}

// xuat vao file NV.bin
void exportFileDT(DTList DT_List) {
	DTNode* node = DT_List.head;
    FILE* f;
    f = fopen("DT.bin", "wb");
    if (f == NULL) {
        printf("Khong the mo file de ghi!");
        return;
    }
    while (node != NULL) {
        fwrite(&node->data, sizeof(DT), 1, f);
        node = node->next;
    }
    fclose(f);
}

void importFileDT(DTList* DT_List) {
    long i;
    FILE* f;
    f = fopen("DT.bin", "rb");
    if (f == NULL) {
        printf("Khong the mo file de doc!");
        return;
    }
    fseek(f, 0, SEEK_END);
    long f_size = ftell(f);
    fseek(f, 0, SEEK_SET);
    DT *newDT = (DT*)malloc(f_size);
    DTNode* node;
    fread(newDT, sizeof(DT), f_size / sizeof(DT), f);
    fclose(f);
    for (i = 0; i < f_size / sizeof(DT); i++) {
        node = createDTNode(newDT[i]);
        addTailDTList(DT_List, node);
    }
    free(newDT);
}



int countNVDT(NVDTList NVDT_List) {
    int count = 0;
    if (NVDT_List.head != NULL) {
        NVDTNode* node = NVDT_List.head;
        while (node != NULL) {
            count++;
            node = node->next;
        }
    }
    return count;
}


void createNVDTList(NVDTList* NVDT_List) {
    NVDT_List->head = NULL;
    NVDT_List->tail = NULL;
}


NVDTNode* createNVDTNode(NVDT newNVDT) {
    NVDTNode* newNVDTNode = (NVDTNode*)malloc(sizeof(NVDTNode));
    newNVDTNode->data = newNVDT;
    newNVDTNode->next = NULL;
    return newNVDTNode;
}

int checkNVDT(char maDT[],int maSoNV) {
    NVDTNode* node = NVDT_List.head;
    while (node != NULL) {
        if (strcmp(node->data.maDT, maDT) == 0 && maSoNV==node->data.maSoNV) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}



void enterNVDT(NVDT* newNVDT) {
    printf("\nMa de tai: ");
    fgets(newNVDT->maDT, sizeof(newNVDT->maDT),stdin);
    deleteNewline(newNVDT->maDT);
   	printf("\nMa so nhan vien: ");
   	scanf("%d", &newNVDT->maSoNV);
   	getchar();
   	while(checkNVDT(newNVDT->maDT, newNVDT->maSoNV)==1){
   		printf("\nNhien vu de tai da ton tai trong danh sach !");
   		printf("\nVui long nhap lai !");
   		printf("\nMa de tai: ");
        fgets(newNVDT->maDT, sizeof(newNVDT->maDT),stdin);
        deleteNewline(newNVDT->maDT);
   	    printf("\nMa so nhan vien: ");
   	    scanf("%d", &newNVDT->maSoNV);
   	    getchar();
   	}
   	printf("\nVai tro: ");
   	fgets(newNVDT->vaiTro, sizeof(newNVDT->vaiTro), stdin);
}

void addHeadNVDTList(NVDTList* NVDT_List, NVDTNode* node){
	if(NVDT_List->head == NULL){
		NVDT_List->head = node;
		NVDT_List->tail = node;
	}
	else{
		node->next = NVDT_List->head;
		NVDT_List->head = node;
	}
}


void addTailNVDTList(NVDTList* NVDT_List, NVDTNode* node){
	if(NVDT_List->head == NULL){
		NVDT_List->head = node;
		NVDT_List->tail = node;
	}
	else{
		NVDT_List->tail->next = node;
		NVDT_List->tail = node;
	}
}


void addAtPositionNVDTList(NVDTList* NVDT_List, NVDTNode* newNode, int position) {
    if (position <= 0) {
        addHeadNVDTList(NVDT_List, newNode);
    } else if (position >= countNVDT(*NVDT_List)) {
        addTailNVDTList(NVDT_List, newNode);
    } else {
        NVDTNode* node = NVDT_List->head;
        int count = 0;
        while (count < position - 1) {
            node = node->next;
            count++;
        }
        newNode->next = node->next;
        node->next = newNode;
    }
}

int removeHeadNVDTList(NVDTList* NVDT_List){
	if (NVDT_List->head != NULL){
		NVDTNode* node = NVDT_List->head;
		NVDT_List->head = node->next;
		free(node);
		if(NVDT_List->head == NULL){
			NVDT_List->tail = NULL;
		}
		return 1;
	}
	return 0;
}



int removeTailNVDTList(NVDTList* NVDT_List){
	if (NVDT_List->head == NULL){
		return 0;
	}
	else if (NVDT_List->head == NVDT_List->tail){
		free(NVDT_List->head);
		NVDT_List->head = NULL;
		NVDT_List->tail = NULL;
	}
	else{
		NVDTNode* prevNode = NULL;
		NVDTNode* currentNode = NVDT_List->head;
		while(currentNode->next != NULL){
			prevNode = currentNode;
			currentNode = currentNode->next;
		}
		free(currentNode);
		prevNode->next = NULL;
		NVDT_List->tail = prevNode;
	}
}
 

 int removeAtPositionNVDTList(NVDTList* NVDT_List, int position){
 	if (position<=0){
 		return removeHeadNVDTList(NVDT_List);
	 }
	 else if (position >= countNVDT(*NVDT_List)){
	 	return removeTailNVDTList(NVDT_List);
	 }
	 else{
	 	NVDTNode* prevNode = NULL;
	 	NVDTNode* currentNode = NVDT_List->head;
	 	int count = 0;
	 	while(count < position){
	 		prevNode = currentNode;
	 		currentNode = currentNode->next;
	 		count++;
		 }
		prevNode->next = currentNode->next;
		free(currentNode);
	 }
 }
 
 
 
 
 void removeNVDTByMaDTAndMaSoNV(NVDTList* NVDT_List){
    NVDTNode* nodeToDelete = searchNVDTNodeByMaDeTaiAndMaSoNV(*NVDT_List);
    printNVDTNode(*nodeToDelete);
    if (nodeToDelete != NULL) {
        	if (nodeToDelete == NVDT_List->head) {
            	NVDT_List->head = nodeToDelete->next;
        	} 
			else {
            	NVDTNode* prevNode = NVDT_List->head;
            	while (prevNode != NULL && prevNode->next != nodeToDelete) {
                	prevNode = prevNode->next;
        		}
            	if (prevNode != NULL) {
               		prevNode->next = nodeToDelete->next;
            	}
			}
	}

    
    free(nodeToDelete);
}
 
 
 
 
NVDTNode* getNVDTNode(NVDTList* NVDT_List, int position){
	NVDTNode* node = NVDT_List->head;
	int i = 0;
	while(node!= NULL && i != position){
		node = node->next;
		i++;
	}
	if (i == position && node != NULL){
		return node;
	}
	return NULL;
}

NVDTNode* searchNVDTNodeByMaDeTaiAndMaSoNV(NVDTList NVDT_List) {
    char maDT[50];
    int maSoNV;

    printf("\nNhap vao ma de tai: ");
    fgets(maDT, sizeof(maDT), stdin);
    deleteNewline(maDT);

    printf("\nNhap vao ma so nhan vien: ");
    scanf("%d", &maSoNV);
    
    while (getchar() != '\n');

    NVDTNode* node = NVDT_List.head;
    while (node != NULL) {
        if (strcmp(node->data.maDT, maDT) == 0 && node->data.maSoNV == maSoNV) {
          
            printNVDTNode(*node);
            return node;
        }
        node = node->next;
    }

 
    printf("\nKhong tim thay nhan vien voi de tai va ma so nhan vien nay trong danh sach!");
    return NULL;
}

 
int updateNVDTList(NVDTList* NVDT_List){
	char maDT[50];
	int maSoNV;
	NVDTNode* node = NVDT_List->head;
	printf("\nNhap vao ma de tai: ");
	fgets(maDT, sizeof(maDT),stdin);
	deleteNewline(maDT);
	printf("\nNhap vao ma so nhan vien: ");
	scanf("%d", &maSoNV);
	while(node != NULL){
		if ((strcmp(node->data.maDT, maDT) == 0 )&& (maSoNV == node->data.maSoNV)){
			printf("\nNhap vao thong tin moi cho nhiem vu de tai (ma de tai %s, ma so nhan vien %d)", maDT, maSoNV);
			enterNVDT(&node->data);
			return 1;
		}
		node = node->next;
	}
	return 0;
}

void printNVDTList(NVDTList NVDT_List){
	if (NVDT_List.head != NULL){
		NVDTNode* node = NVDT_List.head;
		printf("\n |%20s \t |%30s  \t|%30s|", "Ma de tai", "Ma so nhan vien", "Vai tro");
		while(node != NULL){
			printf("\n |%20s \t |%30d  \t|%30s|", node->data.maDT, node->data.maSoNV, node->data.vaiTro);
			node = node->next;
		}
	}
	else{
		printf("Danh sach nhiem vu de tai trong !");
	}
}

void printNVDTNode(NVDTNode node){
	printf("\n |%20s \t |%30s  \t|%30s|", "Ma de tai", "Ma so nhan vien", "Vai tro");
	printf("\n |%20s \t |%30d  \t|%30s|", node.data.maDT, node.data.maSoNV, node.data.vaiTro);
}


void addNVDTToList(NVDTList* NVDT_List) {
    int i;
    int size;
    printf("\nNhap vao so luong nhiem vu de tai: ");
    scanf("%d", &size);
    getchar();
    NVDT *newNVDT = (NVDT*)malloc(size * sizeof(NVDT));
    for (i = 0; i < size; i++) {
        printf("\nNhiem vu de tai thu %d", i + 1);
//        getchar();
        enterNVDT(&newNVDT[i]);
        writeToTailNVDTFile(newNVDT[i]);
        NVDTNode *node = createNVDTNode(newNVDT[i]);
        addTailNVDTList(NVDT_List, node);
    }
    free(newNVDT);
}



void writeToTailNVDTFile(NVDT newNVDT){
	FILE* f;
	f = fopen("NVDT.bin", "ab");
    if (f == NULL) {
        printf("Khong the mo file de ghi!");
        return;
    }
    fwrite(&newNVDT, sizeof(NVDT),1 ,f);
    fclose(f);
}

// xuat vao file NV.bin
void exportFileNVDT(NVDTList NVDT_List) {
	NVDTNode* node = NVDT_List.head;
    FILE* f;
    f = fopen("NVDT.bin", "wb");
    if (f == NULL) {
        printf("Khong the mo file de ghi!");
        return;
    }
    while (node != NULL) {
        fwrite(&node->data, sizeof(NVDT), 1, f);
        node = node->next;
    }
    fclose(f);
}

void importFileNVDT(NVDTList* NVDT_List) {
    long i;
    FILE* f;
    f = fopen("NVDT.bin", "rb");
    if (f == NULL) {
        printf("Khong the mo file de doc!");
        return;
    }
    fseek(f, 0, SEEK_END);
    long f_size = ftell(f);
    fseek(f, 0, SEEK_SET);
    NVDT *newNVDT = (NVDT*)malloc(f_size);
    NVDTNode* node;
    fread(newNVDT, sizeof(NVDT), f_size / sizeof(NVDT), f);
    fclose(f);
    for (i = 0; i < f_size / sizeof(NVDT); i++) {
        node = createNVDTNode(newNVDT[i]);
        addTailNVDTList(NVDT_List, node);
    }
    free(newNVDT);
}









