#include <stdio.h>
#include <stdlib.h>
#include <string.h>



        // Khai bao cau truc du lieu và bien


// cau truc ngay sinh
struct NgaySinh {
    int ngay;
    int thang;
    int nam;
};
typedef struct NgaySinh NgaySinh;

// cau truc nhan vien
struct NhanVien { 
    int maSoNV;
    char hoDem[50];
    char tenNV[50];
    char gioiTinh[20];
    NgaySinh ngaySinh;
};
typedef struct NhanVien NV;

// cau truc de tai
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

// cau truc nut nhan vien
struct NVNode {
    NV data;
    struct NVNode* next;
};
typedef struct NVNode NVNode;

// cau truc nut de tai
struct DTNode {
	DT data;
	struct DTNode* next;
};
typedef struct DTNode DTNode;

// cau truc nut nhiem vu de tai
struct NVDTNode{
	NVDT data;
	struct NVDTNode* next;
};
typedef struct NVDTNode NVDTNode;

// cau truc danh sach nhan vien
struct NVList {
    NVNode* head;
    NVNode* tail;
};
typedef struct NVList NVList;

// cau truc danh sach de tai
struct DTList{
	DTNode* head;
	DTNode* tail;
};
typedef struct DTList DTList;

// cau truc danh sach nhiem vu de tai
struct NVDTList{
	NVDTNode* head;
	NVDTNode* tail;
};
typedef struct NVDTList NVDTList;


NVList NV_List;
DTList DT_List; 
NVDTList NVDT_List;


		// Khai bao cac ham

void deleteNewline(char x[]);  // xoa ky tu "\n" khi nhap xau ky tu

void menuMain(int choose); // in ra menu chinh
void menu1(int choose); // in ra menu phu

void enterNgaySinh(NgaySinh* ngay_Sinh); // nhap thong tin ngay sinh
void enterNV(NV* newNV); // nhap thong tin nhan vien
void enterDT(DT* newDT); // nhap thong tin de tai
void enterNVDT(NVDT* newNVDT); // nhap thong tin nhiem vu de tai		

NVNode* createNVNode(NV newNVNode); // tao nut nhan vien
DTNode* createDTNode(DT newDTNode); // tao nut de tai
NVDTNode* createNVDTNode(NVDT newNVDTNode); // tao nut nhiem vu de tai

void createNVList(NVList* NV_List); // tao danh sach nhan vien
void createDTList(DTList* DT_List); // tao danh sach de tai
void createNVDTList(NVDTList* NVDT_List); // tao danh sach nhiem vu de tai

int countNV(NVList NV_List); // dem so luong nhan vien trong danh sach
int countDT(DTList DT_List); // dem so luong de tai trong danh sach
int countNVDT(NVDTList NVDT_List); // dem so luong nhiem vu de tai trong danh sach

int checkNV(int maSoNV); // kiem tra khoa chinh trong danh sach nhan vien
int checkDT(char maDT[]); // kiem tra khoa chinh trong danh sach de tai
int checkNVDT(char maDT[], int maSoNV); // kiem tra khoa chinh trong danh sach nhiem vu de tai
int checkDT_NVDT(char maDT[]); // kiem tra rang buoc khoa giua de tai va nhiem vu de tai
int checkNV_NVDT(int maSoNV); // kiem tra rang buoc khoa giua nhan vien va nhiem vu de tai
int checkNVDT_NV(int maSoNV); // kiem tra rang buoc khoa giua nhiem vu de tai va nhan vien
int checkNVDT_DT(char maDT[]); // kiem tra rang buoc khoa giua nhiem vu de tai va de tai

void addHeadNVList(NVList* NV_List, NVNode* node); // them 1 nhan vien vao dau danh sach
void addHeadDTList(DTList* DT_List, DTNode* node); // them 1 de tai vao dau danh sach
void addHeadNVDTList(NVDTList* NVDT_List, NVDTNode* node); // them 1 nhiem vu de tai vao danh sach

void addTailNVList(NVList* NV_List, NVNode* node); // them 1 nhan vien vao cuoi danh sach
void addTailDTList(DTList* DT_List, DTNode* node); // them 1 de tai vao cuoi danh sach
void addTailNVDTList(NVDTList* NVDT_List, NVDTNode* node); // them 1 nhiem vu de tai vao danh sach

void addNVToList(NVList* NV_List); // them nhieu nhan vien vao danh sach
void addDTToList(DTList* DT_List); // them nhieu de tai vao danh sach
void addNVDTToList(NVDTList* NVDT_List); // them nhieu nhiem vu de tai vao danh sach

NVNode* searchNVNodeByMaSoNV(NVList NV_List); // tim nut nhan vien bang ma so nhan vien
DTNode* searchDTNodeByMaDeTai(DTList DT_List); // tim nut de tai bang ma nhan vien
NVDTNode* searchNVDTNodeByMaDeTaiAndMaSoNV(NVDTList NVDT_List); // tim nut nhan vien bang ma so NV va ma DT

int removeNVByMaSoNV(NVList* NV_List); // xoa nhan vien bang ma so nhan vien
int removeDTByMaDT(DTList* DT_List); // xoa de tai bang ma de tai
int removeNVDTByMaDTAndMaSoNV(NVDTList* NVDT_List)// xoa nhiem vu de tai bang ma de tai va ma so nhan vien

int updateNVList(NVList* NV_List); // sua chua danh sach nhan vien
int updateDTList(DTList* DT_List); // sua chua danh sach de tai
int updateNVDTList(NVDTList* NVDT_List); // sua chua danh sach nhiem vu de tai

void printNVNode(NVNode node); // xuat ra thonh tin 1 nut nhan vien
void printDTNode(DTNode node); // xuat ra thong tin 1 nut de tai
void printNVDTNode(NVDTNode node); // xuat ra thong tin 1 nut nhiem vu de tai

void printNVList(NVList NV_List); // xuat ra thong tin danh sach nhan vien
void printDTList(DTList DT_List); // xuat ra thong tin danh sach de tai
void printNVDTList(NVDTList NVDT_List); // xuat ra thong tin nhiem vu de tai

void importFileNV(NVList* NV_List); // lay du lieu tu file "NV.bin"
void importFileDT(DTList* DT_List); // lay du lieu tu file "DT.bin"
void importFileNVDT(NVDTList* NVDT_List); // lay du lieu tu file "NVDT.bin"

void exportFileNV(NVList NV_List); // cap nhat du lieu file "NV.bin"
void exportFileDT(DTList DT_List); // cap nhat du lieu file "DT.bin"
void exportFileNVDT(NVDTList NVDT_List); // cap nhet du lieu file "NVDT.bin"

void requestThree(NVDTList NVDT_List); // yeu cau 3
void sortDeTai(DTList* DT_List); // sap xep de tai theo nam bat dau
void requestFive(); // yeu cau 5
void totalCost(DTList DT_List); // yeu cau 6


		// ham main()

int main(){
	

	importFileNV(&NV_List);
	importFileDT(&DT_List);
	importFileNVDT(&NVDT_List);
	int flag = 0, flag1;
	int run = 1;
	int run1, run2;
	char c, c1, c2;
	
	menuMain(flag);

	while(run){
		c = getch();
		if(c == -32){
			c = getch();
		}
		switch(c){
			case 72: // Up
				flag -= 1;
				system("cls || clear");
				menuMain(flag);
			break;
			
			case 80: // down
				flag += 1;
				system("cls || clear");
				menuMain(flag);
			break;
			
			case 77:
			case 13:
				switch((unsigned int)flag%10){
					case 0:
					case 1:
					case 2:
					case 3:
						system("cls || clear");
						flag1 = 0;
						menu1(flag1);
						run1 = 1;
						
						while(run1 && (unsigned int)flag%10 == 0){
							c1 = getch();
							if (c1 == -32){
								c1 = getch();
							}
							switch(c1){
								case 72:
									flag1 -= 1;
									system("cls || clear");
									menu1(flag1);
								break;
								
								case 80:
									flag1 += 1;
									system("cls || clear");
									menu1(flag1);
								break;
								
								case 77:
								case 13:
									switch((unsigned int)flag1%4){
										case 0:
											printNVList(NV_List);
											c2 = getch();
											if(c2 = 13){
												system("cls || clear");
												menu1(flag1 = 0);
											}
										break;
										
										case 1:
											printDTList(DT_List);
											c2 = getch();
											if(c2 = 13){
												system("cls || clear");
												menu1(flag1 = 0);
											}
										break;
										
										case 2:
											printNVDTList(NVDT_List);
											c2 = getch();
											if(c2 = 13){
												system("cls || clear");
												menu1(flag1 = 0);
											}
										break;
										
										case 3:
											system("cls || clear");
											run1 = 0;
											flag = 0;
											menuMain(flag);
										break;
									}
									
								break;
								case 75:
								case 8:
									run1 = 0;
									system("cls || clear");
									flag = 0;
									menuMain(flag);
								break;
							}
						}
						while(run1 && (unsigned int)flag%10 == 1){
							c1 = getch();
							if (c1 == -32){
								c1 = getch();
							}
							switch(c1){
								case 72:
									flag1 -= 1;
									system("cls || clear");
									menu1(flag1);
								break;
								
								case 80:
									flag1 += 1;
									system("cls || clear");
									menu1(flag1);
								break;
								
								case 77:
								case 13:
									switch((unsigned int)flag1%4){
										case 0:
											addNVToList(&NV_List);
											c2 = getch();
											if(c2 = 13){
												system("cls || clear");
												menu1(flag1 = 0);
											}
										break;
										
										case 1:
											addDTToList(&DT_List);
											c2 = getch();
											if(c2 = 13){
												system("cls || clear");
												menu1(flag1 = 0);
											}
										break;
										
										case 2:
											addNVDTToList(&NVDT_List);
											c2 = getch();
											if(c2 = 13){
												system("cls || clear");
												menu1(flag1 = 0);
											}
										break;
										
										case 3:
											system("cls || clear");
											run1 = 0;
											flag = 0;
											menuMain(flag);
										break;
									}
									
								break;
								case 75:
								case 8:
									run1 = 0;
									system("cls || clear");
									flag = 0;
									menuMain(flag);
								break;
							}
						}
						
						while(run1 && (unsigned int)flag%10 == 2){
							c1 = getch();
							if (c1 == -32){
								c1 = getch();
							}
							switch(c1){
								case 72:
									flag1 -= 1;
									system("cls || clear");
									menu1(flag1);
								break;
								
								case 80:
									flag1 += 1;
									system("cls || clear");
									menu1(flag1);
								break;
								
								case 77:
								case 13:
									switch((unsigned int)flag1%4){
										case 0:
											removeNVByMaSoNV(&NV_List);
											c2 = getch();
											if(c2 = 13){
												system("cls || clear");
												menu1(flag1 = 0);
											}
										break;
										
										case 1:
											removeDTByMaDT(&DT_List);
											c2 = getch();
											if(c2 = 13){
												system("cls || clear");
												menu1(flag1 = 0);
											}
										break;
										
										case 2:
											removeNVDTByMaDTAndMaSoNV(&NVDT_List);
											c2 = getch();
											if(c2 = 13){
												system("cls || clear");
												menu1(flag1 = 0);
											}
										break;
										
										case 3:
											system("cls || clear");
											run1 = 0;
											flag = 0;
											menuMain(flag);
										break;
									}
									
								break;
								case 75:
								case 8:
									run1 = 0;
									system("cls || clear");
									flag = 0;
									menuMain(flag);
								break;
							}
						}

						while(run1 && (unsigned int)flag%10 == 3){
							c1 = getch();
							if (c1 == -32){
								c1 = getch();
							}
							switch(c1){
								case 72:
									flag1 -= 1;
									system("cls || clear");
									menu1(flag1);
								break;

								case 80:
									flag1 += 1;
									system("cls || clear");
									menu1(flag1);
								break;

								case 77:
								case 13:
									switch((unsigned int)flag1%4){
										case 0:
											updateNVList(&NV_List);
											c2 = getch();
											if(c2 = 13){
												system("cls || clear");
												menu1(flag1 = 0);
											}
										break;

										case 1:
										    updateDTList(&DT_List);
											c2 = getch();
											if(c2 = 13){
												system("cls || clear");
												menu1(flag1 = 0);
											}
										break;

										case 2:
											updateNVDTList(&NVDT_List);
											c2 = getch();
											if(c2 = 13){
												system("cls || clear");
												menu1(flag1 = 0);
											}
										break;

										case 3:
											system("cls || clear");
											run1 = 0;
											flag = 0;
											menuMain(flag);
										break;
									}

								break;
								case 75:
								case 8:
									run1 = 0;
									system("cls || clear");
									flag = 0;
									menuMain(flag);
								break;
							}
						}
					break;

					case 4:
					
						requestThree(NVDT_List);
						c2 = getch();
						if(c2 = 13){
							system("cls || clear");
							flag = 0;
							menuMain(flag);
						}
					break;
					
					case 5:
						sortDeTai(&DT_List);
						printDTList(DT_List);
						c2 = getch();
						if(c2 = 13){
							system("cls || clear");
							flag = 0;
							menuMain(flag);
						}
					break;
					
					case 6:
						requestFive();
						c2 = getch();
						if(c2 = 13){
							system("cls || clear");
							flag = 0;
							menuMain(flag);
						}	
					break;
					
					case 7:
						totalCost(DT_List);
						c2 = getch();
						if(c2 = 13){
							system("cls || clear");
							flag = 0;
							menuMain(flag);
						}	
					break;

					case 8:
						// luu du lieu;
						exportFileNV(NV_List);
						exportFileDT(DT_List);
						exportFileNVDT(NVDT_List);
						printf("Cap nhat thanh cong !");
						c2 = getch();
						if(c2 = 13){
							system("cls || clear");
							flag = 0;
							menuMain(flag);
						}				
					break;

					case 9:
						// thoat chuong trinh
						run =0;
					break;
				}	
			break;

			case 75:
			case 27:
			case 8:
				run = 0;
			break;
		}	
	}

}



void menuMain(int choose){
	int i;
	printf("|-------------------------------------MENU----------------------------------------|\n");
	char menuTitle[10][100] = {
		"|  | 1. Hien thi du lieu.                                                         |\n",
		"|  | 2. Bo sung du lieu.                                                          |\n",
		"|  | 3. Xoa du lieu.                                                              |\n",
		"|  | 4. Sua chua du lieu.                                                         |\n",
		"|  | 5. Nhap vao ma nhan vien, hien thi danh sach de tai tham gia va vai tro.     |\n",
		"|  | 6. Hien thi danh sach de tai theo tung nam bat dau.                          |\n",
		"|  | 7. Nhap vao de tai, hien thi chi tiet ve de tai.                             |\n",
		"|  | 8. Tinh tong kinh phi.                                                       |\n",
		"|  | 9. Luu ket qua.                                                              |\n",
		"|  | 10.Ket thuc chuong trinh.                                                    |\n"
	};
	*(menuTitle[(unsigned int)choose%10] + 1) = (char)45;
	*(menuTitle[(unsigned int)choose%10] + 2) = (char)62;
	for(i = 0; i < 10 ; i++){
		printf(menuTitle[i]);
	}
	printf("|---------------------------------------------------------------------------------|\n");
}
























