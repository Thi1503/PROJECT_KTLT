#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Khai bao cau truc du lieu va bien

// cau truc ngay sinh
struct NgaySinh
{
	int ngay;
	int thang;
	int nam;
};
typedef struct NgaySinh NgaySinh;

// cau truc nhan vien
struct NhanVien
{
	int maSoNV;
	char hoDem[50];
	char tenNV[50];
	char gioiTinh[20];
	NgaySinh ngaySinh;
};
typedef struct NhanVien NV;

// cau truc de tai
struct DeTai
{
	char maDT[50];
	char tenDT[100];
	int namBatDau;
	int namKetThuc;
	long int kinhPhi;
};
typedef struct DeTai DT;

// cau truc nhiem vu de tai
struct NhiemVuDeTai
{
	char maDT[50];
	int maSoNV;
	char vaiTro[50];
};
typedef struct NhiemVuDeTai NVDT;

// cau truc nut nhan vien
struct NVNode
{
	NV data;
	struct NVNode *next;
};
typedef struct NVNode NVNode;

// cau truc nut de tai
struct DTNode
{
	DT data;
	struct DTNode *next;
};
typedef struct DTNode DTNode;

// cau truc nut nhiem vu de tai
struct NVDTNode
{
	NVDT data;
	struct NVDTNode *next;
};
typedef struct NVDTNode NVDTNode;

// cau truc danh sach nhan vien
struct NVList
{
	NVNode *head;
	NVNode *tail;
};
typedef struct NVList NVList;

// cau truc danh sach de tai
struct DTList
{
	DTNode *head;
	DTNode *tail;
};
typedef struct DTList DTList;

// cau truc danh sach nhiem vu de tai
struct NVDTList
{
	NVDTNode *head;
	NVDTNode *tail;
};
typedef struct NVDTList NVDTList;

NVList NV_List;
DTList DT_List;
NVDTList NVDT_List;

FILE *file;
// Khai bao cac ham

void deleteNewline(char x[]); // xoa ky tu "\n" khi nhap xau ky tu

void menuMain(int choose); // in ra menu chinh
void menu1(int choose);	   // in ra menu phu

void enterNgaySinh(NgaySinh *ngay_Sinh); // nhap thong tin ngay sinh
void enterNV(NV *newNV);				 // nhap thong tin nhan vien
void enterDT(DT *newDT);				 // nhap thong tin de tai
void enterNVDT(NVDT *newNVDT);			 // nhap thong tin nhiem vu de tai

NVNode *createNVNode(NV newNVNode);			// tao nut nhan vien
DTNode *createDTNode(DT newDTNode);			// tao nut de tai
NVDTNode *createNVDTNode(NVDT newNVDTNode); // tao nut nhiem vu de tai

void createNVList(NVList *NV_List);		  // tao danh sach nhan vien
void createDTList(DTList *DT_List);		  // tao danh sach de tai
void createNVDTList(NVDTList *NVDT_List); // tao danh sach nhiem vu de tai

int countNV(NVList NV_List);	   // dem so luong nhan vien trong danh sach
int countDT(DTList DT_List);	   // dem so luong de tai trong danh sach
int countNVDT(NVDTList NVDT_List); // dem so luong nhiem vu de tai trong danh sach

int checkNV(int maSoNV);				// kiem tra khoa chinh trong danh sach nhan vien
int checkDT(char maDT[]);				// kiem tra khoa chinh trong danh sach de tai
int checkNVDT(char maDT[], int maSoNV); // kiem tra khoa chinh trong danh sach nhiem vu de tai
int checkDT_NVDT(char maDT[]);			// kiem tra rang buoc khoa giua de tai va nhiem vu de tai
int checkNV_NVDT(int maSoNV);			// kiem tra rang buoc khoa giua nhan vien va nhiem vu de tai
int checkNVDT_NV(int maSoNV);			// kiem tra rang buoc khoa giua nhiem vu de tai va nhan vien
int checkNVDT_DT(char maDT[]);			// kiem tra rang buoc khoa giua nhiem vu de tai va de tai

void addHeadNVList(NVList *NV_List, NVNode *node);		   // them 1 nhan vien vao dau danh sach
void addHeadDTList(DTList *DT_List, DTNode *node);		   // them 1 de tai vao dau danh sach
void addHeadNVDTList(NVDTList *NVDT_List, NVDTNode *node); // them 1 nhiem vu de tai vao danh sach

void addTailNVList(NVList *NV_List, NVNode *node);		   // them 1 nhan vien vao cuoi danh sach
void addTailDTList(DTList *DT_List, DTNode *node);		   // them 1 de tai vao cuoi danh sach
void addTailNVDTList(NVDTList *NVDT_List, NVDTNode *node); // them 1 nhiem vu de tai vao danh sach

void addNVToList(NVList *NV_List);		 // them nhieu nhan vien vao danh sach
void addDTToList(DTList *DT_List);		 // them nhieu de tai vao danh sach
void addNVDTToList(NVDTList *NVDT_List); // them nhieu nhiem vu de tai vao danh sach

NVNode *searchNVNodeByMaSoNV(NVList NV_List);					// tim nut nhan vien bang ma so nhan vien
DTNode *searchDTNodeByMaDeTai(DTList DT_List);					// tim nut de tai bang ma nhan vien
NVDTNode *searchNVDTNodeByMaDeTaiAndMaSoNV(NVDTList NVDT_List); // tim nut nhan vien bang ma so NV va ma DT

void removeNVByMaSoNV(NVList *NV_List);				 // xoa nhan vien bang ma so nhan vien
void removeDTByMaDT(DTList *DT_List);				 // xoa de tai bang ma de tai
void removeNVDTByMaDTAndMaSoNV(NVDTList *NVDT_List); // xoa nhiem vu de tai bang ma de tai va ma so nhan vien

void updateNVList(NVList *NV_List);		  // sua chua danh sach nhan vien
void updateDTList(DTList *DT_List);		  // sua chua danh sach de tai
void updateNVDTList(NVDTList *NVDT_List); // sua chua danh sach nhiem vu de tai

void printNVNode(NVNode node);	   // xuat ra thonh tin 1 nut nhan vien
void printDTNode(DTNode node);	   // xuat ra thong tin 1 nut de tai
void printNVDTNode(NVDTNode node); // xuat ra thong tin 1 nut nhiem vu de tai

void printNVList(NVList NV_List);		// xuat ra thong tin danh sach nhan vien
void printDTList(DTList DT_List);		// xuat ra thong tin danh sach de tai
void printNVDTList(NVDTList NVDT_List); // xuat ra thong tin nhiem vu de tai

void importFileNV(NVList *NV_List);		  // lay du lieu tu file "NV.bin"
void importFileDT(DTList *DT_List);		  // lay du lieu tu file "DT.bin"
void importFileNVDT(NVDTList *NVDT_List); // lay du lieu tu file "NVDT.bin"

void exportFileNV(NVList NV_List);		 // cap nhat du lieu file "NV.bin"
void exportFileDT(DTList DT_List);		 // cap nhat du lieu file "DT.bin"
void exportFileNVDT(NVDTList NVDT_List); // cap nhet du lieu file "NVDT.bin"

void requestThree(NVDTList NVDT_List); // yeu cau 3
void sortDeTai(DTList *DT_List);	   // sap xep de tai theo nam bat dau
void requestFive();					   // yeu cau 5
void totalCost(DTList DT_List);		   // yeu cau 6

// ham main()

int main()
{
	int flag = 0, flag1;
	int run = 1;
	int run1, run2;
	char c, c1, c2;

	file = fopen("output.txt", "w");

	if (file == NULL)
	{
		printf("Khong the mo file.\n");
		return 1;
	}
	fprintf(file, "Bat dau chay chuong trinh!\n");

	importFileNV(&NV_List);
	importFileDT(&DT_List);
	importFileNVDT(&NVDT_List);

	menuMain(flag);

	while (run)
	{
		c = getch();
		if (c == -32)
		{
			c = getch();
		}
		switch (c)
		{
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
			switch ((unsigned int)flag % 10)
			{
			case 0:
			case 1:
			case 2:
			case 3:
				system("cls || clear");
				flag1 = 0;
				menu1(flag1);
				run1 = 1;

				while (run1 && (unsigned int)flag % 10 == 0)
				{
					c1 = getch();
					if (c1 == -32)
					{
						c1 = getch();
					}
					switch (c1)
					{
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
						switch ((unsigned int)flag1 % 4)
						{
						case 0:
							fprintf(file, "Yeu cau 1 : Hien thi du lieu danh sach \"Nhan vien\"\n");
							printNVList(NV_List);
							c2 = getch();
							if (c2 = 13)
							{
								system("cls || clear");
								menu1(flag1 = 0);
							}
							break;

						case 1:
							fprintf(file, "Yeu cau 1 : Hien thi du lieu danh sach \"De tai\"\n");
							printDTList(DT_List);
							c2 = getch();
							if (c2 = 13)
							{
								system("cls || clear");
								menu1(flag1 = 0);
							}
							break;

						case 2:
							fprintf(file, "Yeu cau 1 : Hien thi du lieu danh sach \"Nhiem vu de tai\"\n");
							printNVDTList(NVDT_List);
							c2 = getch();
							if (c2 = 13)
							{
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
				while (run1 && (unsigned int)flag % 10 == 1)
				{
					c1 = getch();
					if (c1 == -32)
					{
						c1 = getch();
					}
					switch (c1)
					{
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
						switch ((unsigned int)flag1 % 4)
						{
						case 0:
							fprintf(file, "Yeu cau 2 : Bo sung du lieu danh sach \"Nhan vien\"\n");
							addNVToList(&NV_List);
							c2 = getch();
							if (c2 = 13)
							{
								system("cls || clear");
								menu1(flag1 = 0);
							}
							break;

						case 1:
							fprintf(file, "Yeu cau 2 : Bo sung du lieu danh sach \"De tai\"\n");
							addDTToList(&DT_List);
							c2 = getch();
							if (c2 = 13)
							{
								system("cls || clear");
								menu1(flag1 = 0);
							}
							break;

						case 2:
							fprintf(file, "Yeu cau 2 : Bo sung du lieu danh sach \"Nhiem vu de tai\"\n");
							addNVDTToList(&NVDT_List);
							c2 = getch();
							if (c2 = 13)
							{
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

				while (run1 && (unsigned int)flag % 10 == 2)
				{
					c1 = getch();
					if (c1 == -32)
					{
						c1 = getch();
					}
					switch (c1)
					{
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
						switch ((unsigned int)flag1 % 4)
						{
						case 0:
							fprintf(file, "Yeu cau 2 : Xoa du lieu danh sach \"Nhan vien\"\n");
							removeNVByMaSoNV(&NV_List);
							c2 = getch();
							if (c2 = 13)
							{
								system("cls || clear");
								menu1(flag1 = 0);
							}
							break;

						case 1:
							fprintf(file, "Yeu cau 2 : Xoa du lieu danh sach \"De tai\"\n");
							removeDTByMaDT(&DT_List);
							c2 = getch();
							if (c2 = 13)
							{
								system("cls || clear");
								menu1(flag1 = 0);
							}
							break;

						case 2:
							fprintf(file, "Yeu cau 2 : Xoa du lieu danh sach \"Nhiem vu de tai\"\n");
							removeNVDTByMaDTAndMaSoNV(&NVDT_List);
							c2 = getch();
							if (c2 = 13)
							{
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

				while (run1 && (unsigned int)flag % 10 == 3)
				{
					c1 = getch();
					if (c1 == -32)
					{
						c1 = getch();
					}
					switch (c1)
					{
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
						switch ((unsigned int)flag1 % 4)
						{
						case 0:
							fprintf(file, "Yeu cau 2 : Sua chua du lieu danh sach \"Nhan vien\"\n");
							updateNVList(&NV_List);
							c2 = getch();
							if (c2 = 13)
							{
								system("cls || clear");
								menu1(flag1 = 0);
							}
							break;

						case 1:
							fprintf(file, "Yeu cau 2 : Sua chua du lieu danh sach \"De tai\"\n");
							updateDTList(&DT_List);
							c2 = getch();
							if (c2 = 13)
							{
								system("cls || clear");
								menu1(flag1 = 0);
							}
							break;

						case 2:
							fprintf(file, "Yeu cau 2 : Sua chua du lieu danh sach \"Nhiem vu de tai\"\n");
							updateNVDTList(&NVDT_List);
							c2 = getch();
							if (c2 = 13)
							{
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
				fprintf(file, "Yeu cau 3 : Nhap ma nhan vien. Cho biet danh sach de tai nhan vien tham gia va vai tro.\n");
				requestThree(NVDT_List);
				c2 = getch();
				if (c2 = 13)
				{
					system("cls || clear");
					flag = 0;
					menuMain(flag);
				}
				break;

			case 5:
				fprintf(file, "Yeu cau 4 : Hien thi danh sach \"De tai\" theo tung nam bat dau.\n");
				sortDeTai(&DT_List);
				printDTList(DT_List);
				c2 = getch();
				if (c2 = 13)
				{
					system("cls || clear");
					flag = 0;
					menuMain(flag);
				}
				break;

			case 6:
				fprintf(file, "Yeu cau 5: Nhap vao ma de tai. Hien thi thong tin chi tiet ve de tai, ten chu nhiem, ten thu ky, danh sach nhan vien tham gia\n");
				requestFive();
				c2 = getch();
				if (c2 = 13)
				{
					system("cls || clear");
					flag = 0;
					menuMain(flag);
				}
				break;

			case 7:
				fprintf(file, "Yeu cau 6 : Nhap vao nam. Tinh tong kinh phi cua nhung de tai bat dau vao nam do.\n");
				totalCost(DT_List);
				c2 = getch();
				if (c2 = 13)
				{
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
				printf("Cap nhat du lieu vao file thanh cong !");

				c2 = getch();
				if (c2 = 13)
				{
					system("cls || clear");
					flag = 0;
					menuMain(flag);
				}
				break;

			case 9:
				// thoat chuong trinh
				fprintf(file, "Ket thuc chuong trinh !\n");
				run = 0;
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
	fclose(file);
}

void deleteNewline(char *str)
{
	size_t len = strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
}

void menuMain(int choose)
{
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
		"|  | 10.Ket thuc chuong trinh.                                                    |\n"};
	*(menuTitle[(unsigned int)choose % 10] + 1) = (char)45;
	*(menuTitle[(unsigned int)choose % 10] + 2) = (char)62;
	for (i = 0; i < 10; i++)
	{
		printf(menuTitle[i]);
	}
	printf("|---------------------------------------------------------------------------------|\n");

	// ghi vao file text
	fprintf(file,"\n");
	fprintf(file, "|-------------------------------------MENU----------------------------------------|\n");
	for (i = 0; i < 10; i++)
	{
		fprintf(file, "%s", menuTitle[i]);
	}
	fprintf(file, "|---------------------------------------------------------------------------------|\n");
	
}

void menu1(int choose)
{
	int i;
	printf("\n");
	printf("|-----------Hien thi du lieu--------------|\n");
	char menuTitle[4][50] = {
		"|  | 1. Nhan vien.                        |\n",
		"|  | 2. De tai.                           |\n",
		"|  | 3. Nhien vu de tai.                  |\n",
		"|  | 4. Quay lai.                         |\n"};
	*(menuTitle[(unsigned int)choose % 4] + 1) = (char)45;
	*(menuTitle[(unsigned int)choose % 4] + 2) = (char)62;
	for (i = 0; i < 4; i++)
	{
		printf(menuTitle[i]);
	}
	printf("|-----------------------------------------|\n");

	// ghi vao file text
	fprintf(file,"\n");
	fprintf(file, "|-----------Hien thi du lieu--------------|\n");
	for (i = 0; i < 4; i++)
	{
		fprintf(file, "%s", menuTitle[i]);
	}
	fprintf(file, "|-----------------------------------------|\n");
}

void enterNgaySinh(NgaySinh *ngay_Sinh)
{
	char ngaySinh[30];
	printf("Ngay sinh (dd/mm/yyyy): ");
	fgets(ngaySinh, sizeof(ngaySinh), stdin);
	deleteNewline(ngaySinh);
	int result = sscanf(ngaySinh, "%d/%d/%d", &ngay_Sinh->ngay, &ngay_Sinh->thang, &ngay_Sinh->nam);
}

void enterNV(NV *newNV)
{
	printf("\nMa so nhan vien: ");
	scanf("%d", &newNV->maSoNV);
	printf("Ho ten dem: ");
	getchar();
	fgets(newNV->hoDem, sizeof(newNV->hoDem), stdin);
	deleteNewline(newNV->hoDem);
	printf("Ten nhan vien: ");
	fgets(newNV->tenNV, sizeof(newNV->tenNV), stdin);
	deleteNewline(newNV->tenNV);
	printf("Gioi tinh (Nam/Nu): ");
	fgets(newNV->gioiTinh, sizeof(newNV->gioiTinh), stdin);
	deleteNewline(newNV->gioiTinh);
	enterNgaySinh(&newNV->ngaySinh);

	// ghi vao file text
	fprintf(file, "\nMa so nhan vien: %d\n", newNV->maSoNV);
	fprintf(file, "Ho ten dem: %s\n", newNV->hoDem);
	fprintf(file, "Ten nhan vien: %s\n", newNV->tenNV);
	fprintf(file, "Gioi tinh (Nam/Nu): %s\n", newNV->gioiTinh);
	fprintf(file, "Ngay sinh (dd/mm/yyyy): %02d/02%d/%d \n", newNV->ngaySinh.ngay, newNV->ngaySinh.thang, newNV->ngaySinh.nam);
}

void enterDT(DT *newDT)
{
	printf("\nMa de tai: ");
	fgets(newDT->maDT, sizeof(newDT->maDT), stdin);
	deleteNewline(newDT->maDT);
	printf("Ten De Tai: ");
	fgets(newDT->tenDT, sizeof(newDT->tenDT), stdin);
	deleteNewline(newDT->tenDT);
	printf("Nam bat dau: ");
	scanf("%d", &newDT->namBatDau);
	printf("Nam ket thuc: ");
	scanf("%d", &newDT->namKetThuc);
	printf("Kinh phi de tai (VND): ");
	scanf("%ld", &newDT->kinhPhi);

	// ghi vao file text
	fprintf(file, "\nMa de tai: %s\n", newDT->maDT);
	fprintf(file, "Ten De Tai: %s\n", newDT->tenDT);
	fprintf(file, "Nam bat dau: %d\n", newDT->namBatDau);
	fprintf(file, "Nam ket thuc: %d\n", newDT->namKetThuc);
	fprintf(file, "Kinh phi de tai (VND): %d\n", newDT->kinhPhi);
}

void enterNVDT(NVDT *newNVDT)
{
	printf("\nMa de tai: ");
	fgets(newNVDT->maDT, sizeof(newNVDT->maDT), stdin);
	deleteNewline(newNVDT->maDT);
	printf("Ma so nhan vien: ");
	scanf("%d", &newNVDT->maSoNV);
	getchar();
	printf("Vai tro: ");
	fgets(newNVDT->vaiTro, sizeof(newNVDT->vaiTro), stdin);
	deleteNewline(newNVDT->vaiTro);

	// ghi vao file text
	fprintf(file, "\nMa de tai: %s\n", newNVDT->maDT);
	fprintf(file, "Ma so nhan vien: %d\n", newNVDT->maSoNV);
	fprintf(file, "Vai tro: %s\n", newNVDT->vaiTro);
}

NVNode *createNVNode(NV newNV)
{
	NVNode *newNVNode = (NVNode *)malloc(sizeof(NVNode));
	newNVNode->data = newNV;
	newNVNode->next = NULL;
	return newNVNode;
}

DTNode *createDTNode(DT newDT)
{
	DTNode *newDTNode = (DTNode *)malloc(sizeof(DTNode));
	newDTNode->data = newDT;
	newDTNode->next = NULL;
	return newDTNode;
}

NVDTNode *createNVDTNode(NVDT newNVDT)
{
	NVDTNode *newNVDTNode = (NVDTNode *)malloc(sizeof(NVDTNode));
	newNVDTNode->data = newNVDT;
	newNVDTNode->next = NULL;
	return newNVDTNode;
}

void createNVList(NVList *NV_List)
{
	NV_List->head = NULL;
	NV_List->tail = NULL;
}

void createDTList(DTList *DT_List)
{
	DT_List->head = NULL;
	DT_List->tail = NULL;
}

void createNVDTList(NVDTList *NVDT_List)
{
	NVDT_List->head = NULL;
	NVDT_List->tail = NULL;
}

int countNV(NVList NV_List)
{
	int count = 0;
	if (NV_List.head != NULL)
	{
		NVNode *node = NV_List.head;
		while (node != NULL)
		{
			count++;
			node = node->next;
		}
	}
	return count;
}

int countDT(DTList DT_List)
{
	int count = 0;
	if (DT_List.head != NULL)
	{
		DTNode *node = DT_List.head;
		while (node != NULL)
		{
			count++;
			node = node->next;
		}
	}
	return count;
}

int countNVDT(NVDTList NVDT_List)
{
	int count = 0;
	if (NVDT_List.head != NULL)
	{
		NVDTNode *node = NVDT_List.head;
		while (node != NULL)
		{
			count++;
			node = node->next;
		}
	}
	return count;
}

int checkNV(int maSoNV)
{
	NVNode *node = NV_List.head;
	while (node != NULL)
	{
		if (node->data.maSoNV == maSoNV)
		{
			return 1;
		}
		node = node->next;
	}
	return 0;
}

int checkDT(char maDT[])
{
	DTNode *node = DT_List.head;
	while (node != NULL)
	{
		if (strcmp(node->data.maDT, maDT) == 0)
		{
			return 1;
		}
		node = node->next;
	}
	return 0;
}

int checkNVDT(char maDT[], int maSoNV)
{
	NVDTNode *node = NVDT_List.head;
	while (node != NULL)
	{
		if (strcmp(node->data.maDT, maDT) == 0 && maSoNV == node->data.maSoNV)
		{
			return 1;
		}
		node = node->next;
	}
	return 0;
}

int checkDT_NVDT(char maDT[])
{
	NVDTNode *node = NVDT_List.head;
	while (node != NULL)
	{
		if (strcmp(node->data.maDT, maDT) == 0)
		{
			return 1;
		}
		node = node->next;
	}
	return 0;
}

int checkNV_NVDT(int maSoNV)
{
	NVDTNode *node = NVDT_List.head;
	while (node != NULL)
	{
		if (maSoNV == node->data.maSoNV)
		{
			return 1;
		}
		node = node->next;
	}
	return 0;
}

int checkNVDT_NV(int maSoNV)
{
	NVNode *node = NV_List.head;
	while (node != NULL)
	{
		if (maSoNV == node->data.maSoNV)
		{
			return 1;
		}
		node = node->next;
	}
	return 0;
}

int checkNVDT_DT(char maDT[])
{
	DTNode *node = DT_List.head;
	while (node != NULL)
	{
		if (strcmp(node->data.maDT, maDT) == 0)
		{
			return 1;
		}
		node = node->next;
	}
	return 0;
}

void addHeadNVList(NVList *NV_List, NVNode *node)
{
	if (NV_List->head == NULL)
	{
		NV_List->head = node;
		NV_List->tail = node;
	}
	else
	{
		node->next = NV_List->head;
		NV_List->head = node;
	}
}

void addHeadDTList(DTList *DT_List, DTNode *node)
{
	if (DT_List->head == NULL)
	{
		DT_List->head = node;
		DT_List->tail = node;
	}
	else
	{
		node->next = DT_List->head;
		DT_List->head = node;
	}
}

void addHeadNVDTList(NVDTList *NVDT_List, NVDTNode *node)
{
	if (NVDT_List->head == NULL)
	{
		NVDT_List->head = node;
		NVDT_List->tail = node;
	}
	else
	{
		node->next = NVDT_List->head;
		NVDT_List->head = node;
	}
}

void addTailNVList(NVList *NV_List, NVNode *node)
{
	if (NV_List->head == NULL)
	{
		NV_List->head = node;
		NV_List->tail = node;
	}
	else
	{
		NV_List->tail->next = node;
		NV_List->tail = node;
	}
}

void addTailDTList(DTList *DT_List, DTNode *node)
{
	if (DT_List->head == NULL)
	{
		DT_List->head = node;
		DT_List->tail = node;
	}
	else
	{
		DT_List->tail->next = node;
		DT_List->tail = node;
	}
}

void addTailNVDTList(NVDTList *NVDT_List, NVDTNode *node)
{
	if (NVDT_List->head == NULL)
	{
		NVDT_List->head = node;
		NVDT_List->tail = node;
	}
	else
	{
		NVDT_List->tail->next = node;
		NVDT_List->tail = node;
	}
}

void addNVToList(NVList *NV_List)
{
	int i;
	int size;
	printf("\nNhap vao so luong nhan vien: ");
	scanf("%d", &size);
	fprintf(file, "\nNhap vao so luong nhan vien: %d\n", size);
	NV *newNV = (NV *)malloc(size * sizeof(NV));
	for (i = 0; i < size; i++)
	{
		printf("\nNhan vien thu %d", i + 1);
		fprintf(file, "\nNhan vien thu %d", i + 1);
		do
		{
			enterNV(&newNV[i]);
			if (checkNV(newNV[i].maSoNV))
			{
				printf("\nMa so nhan vien da co trong danh sach !");
				printf("\nVui long nhap lai !");
				printf("\nNhan vien thu %d", i + 1);

				fprintf(file, "\nMa so nhan vien da co trong danh sach !\n");
				fprintf(file, "Vui long nhap lai !\n");
				fprintf(file, "\nNhan vien thu %d", i + 1);
			}
		} while (checkNV(newNV[i].maSoNV));

		NVNode *node = createNVNode(newNV[i]);
		addTailNVList(NV_List, node);
	}
	printf("\nBo sung thanh cong !");
	fprintf(file, "\nBo sung thanh cong !\n");
	free(newNV);
}

void addDTToList(DTList *DT_List)
{
	int i;
	int size;
	printf("\nNhap vao so luong de tai: ");
	scanf("%d", &size);
	fprintf(file, "\nNhap vao so luong de tai: %d\n", size);
	getchar();
	DT *newDT = (DT *)malloc(size * sizeof(DT));
	for (i = 0; i < size; i++)
	{
		printf("\nDe tai thu %d", i + 1);
		fprintf(file, "\nDe tai thu %d", i + 1);
		do
		{
			enterDT(&newDT[i]);
			getchar();
			if (checkDT(newDT[i].maDT))
			{
				printf("\nMa de tai da co trong danh sach");
				printf("\nVui long nhap lai !");
				printf("\nDe tai thu %d", i + 1);

				fprintf(file, "\nMa de tai da co trong danh sach !\n");
				fprintf(file, "Vui long nhap lai !\n");
				fprintf(file, "\nDe tai thu %d", i + 1);
			}
		} while (checkDT(newDT[i].maDT));

		DTNode *node = createDTNode(newDT[i]);
		addTailDTList(DT_List, node);
	}
	printf("\nBo sung thanh cong !");
	fprintf(file, "\nBo sung thanh cong !\n");
	free(newDT);
}

void addNVDTToList(NVDTList *NVDT_List)
{
	int i;
	int size;
	printf("\nNhap vao so luong nhiem vu de tai: ");
	scanf("%d", &size);
	fprintf(file, "\nNhap vao so luong nhiem vu de tai: %d\n", size);
	getchar();
	NVDT *newNVDT = (NVDT *)malloc(size * sizeof(NVDT));

	for (i = 0; i < size; i++)
	{
		printf("\nNhiem vu de tai thu %d", i + 1);
		fprintf(file, "\nNhiem vu de tai thu %d", i + 1);
		do
		{
			enterNVDT(&newNVDT[i]);
			if (checkNVDT(newNVDT[i].maDT, newNVDT[i].maSoNV))
			{
				printf("\nNhiem vu de tai da co trong danh sach !");
				printf("\nVui long nhap lai !");
				printf("\nNhiem vu de tai thu %d", i + 1);

				fprintf(file, "\nNhiem vu de tai da co trong danh sach !");
				fprintf(file, "\nVui long nhap lai !");
				fprintf(file, "\nNhiem vu de tai thu %d", i + 1);
			}
			else if (!checkNVDT_NV(newNVDT[i].maSoNV) && !checkNVDT_DT(newNVDT[i].maDT))
			{
				printf("\nMa so nhan vien va Ma de tai khong co trong danh sach !");
				printf("\nVui long nhap lai !");
				printf("\nNhiem vu de tai thu %d", i + 1);

				fprintf(file, "\nMa so nhan vien va Ma de tai khong co trong danh sach !");
				fprintf(file, "\nVui long nhap lai !");
				fprintf(file, "\nNhiem vu de tai thu %d", i + 1);
			}
			else if (!checkNVDT_NV(newNVDT[i].maSoNV))
			{
				printf("\nMa so nhan vien khong co trong danh sach \"Nhan vien\" !");
				printf("\nVui long nhap lai !");
				printf("\nNhiem vu de tai thu %d", i + 1);

				fprintf(file, "\nMa so nhan vien khong co trong danh sach \"Nhan vien\" !");
				fprintf(file, "\nVui long nhap lai !");
				fprintf(file, "\nNhiem vu de tai thu %d", i + 1);
			}
			else if (!checkNVDT_DT(newNVDT[i].maDT))
			{
				printf("\nMa de tai khong co trong danh sach \"De tai\" !");
				printf("\nVui long nhap lai !");
				printf("\nNhiem vu de tai thu %d", i + 1);

				fprintf(file, "\nMa de tai khong co trong danh sach \"De tai\" !");
				fprintf(file, "\nVui long nhap lai !");
				fprintf(file, "\nNhiem vu de tai thu %d", i + 1);
			}
		} while (checkNVDT(newNVDT[i].maDT, newNVDT[i].maSoNV) || (!checkNVDT_NV(newNVDT[i].maSoNV)) || (!checkNVDT_DT(newNVDT[i].maDT)) || (!checkNVDT_NV(newNVDT[i].maSoNV) && !checkNVDT_DT(newNVDT[i].maDT)));

		NVDTNode *node = createNVDTNode(newNVDT[i]);
		addTailNVDTList(NVDT_List, node);
	}
	printf("\nBo sung thanh cong !");
	fprintf(file, "\nBo sung thanh cong !\n");
	free(newNVDT);
}

NVNode *searchNVNodeByMaSoNV(NVList NV_List)
{
	int maSoNV;
	NVNode *node = NV_List.head;
	printf("\nNhap vao ma so nhan vien: ");
	scanf("%d", &maSoNV);
	fprintf(file, "\nNhap vao ma so nhan vien: %d\n", maSoNV);

	while (node != NULL)
	{
		if (node->data.maSoNV == maSoNV)
		{
			fprintf(file, "Tim thay nhan vien trong danh sach!\n");
			return node;
		}
		node = node->next;
	}
	printf("\nNhan vien khong co trong danh sach!");
	fprintf(file, "Nhan vien khong co trong danh sach!\n");
	return NULL;
}

DTNode *searchDTNodeByMaDeTai(DTList DT_List)
{
	char maDT[50];
	DTNode *node = DT_List.head;

	printf("\nNhap vao ma de tai: ");
	fgets(maDT, sizeof(maDT), stdin);
	deleteNewline(maDT);
	fprintf(file, "\nNhap vao ma de tai: %s\n", maDT);
	while (node != NULL)
	{
		if (strcmp(node->data.maDT, maDT) == 0)
		{
			fprintf(file, "Tim thay de tai trong danh sach!\n");
			return node;
		}
		node = node->next;
	}
	printf("\nDe tai khong co trong danh sach!");
	fprintf(file, "De tai khong co trong danh sach!\n");
	return NULL;
}

NVDTNode *searchNVDTNodeByMaDeTaiAndMaSoNV(NVDTList NVDT_List)
{
	char maDT[50];
	int maSoNV;
	printf("\nNhap vao ma de tai: ");
	fgets(maDT, sizeof(maDT), stdin);
	deleteNewline(maDT);
	fprintf(file, "\nNhap vao ma de tai: %s\n", maDT);
	printf("Nhap vao ma so nhan vien: ");
	scanf("%d", &maSoNV);
	fprintf(file, "\nNhap vao ma so nhan vien: %d\n", maSoNV);
	while (getchar() != '\n')
		;
	NVDTNode *node = NVDT_List.head;
	while (node != NULL)
	{
		if (strcmp(node->data.maDT, maDT) == 0 && node->data.maSoNV == maSoNV)
		{
			fprintf(file, "Tim thay nhiem vu de tai trong danh sach!\n");
			return node;
		}
		node = node->next;
	}

	printf("\nNhiem vu de tai khong co trong danh sach!");
	fprintf(file, "Nhiem vu de tai khong co trong danh sach!\n");
	return NULL;
}

void removeNVByMaSoNV(NVList *NV_List)
{
	NVNode *nodeToDelete = searchNVNodeByMaSoNV(*NV_List);
	if (nodeToDelete != NULL)
	{
		// Ensure that the employee is in the NV_List
		int maSoNV = nodeToDelete->data.maSoNV;
		if (checkNV_NVDT(maSoNV))
		{
			printf("\nKhong the xoa vi nhan vien co nhiem vu de tai lien quan!");
			fprintf(file, "Khong the xoa vi nhan vien co nhiem vu de tai lien quan!\n");
		}
		else
		{
			if (nodeToDelete == NV_List->head)
			{
				NV_List->head = nodeToDelete->next;
			}
			else
			{
				NVNode *prevNode = NV_List->head;
				while (prevNode != NULL && prevNode->next != nodeToDelete)
				{
					prevNode = prevNode->next;
				}
				if (prevNode != NULL)
				{
					prevNode->next = nodeToDelete->next;
				}
			}
			free(nodeToDelete);
			printf("\nXoa thanh cong !");
			fprintf(file, "Xoa thanh cong !\n");
		}
	}
	else
	{
		printf("\nKhong the xoa vi nhan vien khong co trong danh sach !");
		fprintf(file, "Khong the xoa vi nhan vien khong co trong danh sach !\n");
	}
}

void removeDTByMaDT(DTList *DT_List)
{
	DTNode *nodeToDelete = searchDTNodeByMaDeTai(*DT_List);
	if (nodeToDelete != NULL)
	{
		// Check if there are any associated NVDT entries for the given DT
		if (checkDT_NVDT(nodeToDelete->data.maDT))
		{
			printf("\nKhong the xoa vi de tai co nhiem vu de tai lien quan!");
			fprintf(file, "Khong the xoa vi de tai co nhiem vu de tai lien quan!\n");
		}
		else
		{
			if (nodeToDelete == DT_List->head)
			{
				DT_List->head = nodeToDelete->next;
			}
			else
			{
				DTNode *prevNode = DT_List->head;
				while (prevNode != NULL && prevNode->next != nodeToDelete)
				{
					prevNode = prevNode->next;
				}
				if (prevNode != NULL)
				{
					prevNode->next = nodeToDelete->next;
				}
			}
			printf("\nXoa thanh cong !");
			fprintf(file, "Xoa thanh cong !\n");
			free(nodeToDelete);
		}
	}
	else
	{
		printf("\nKhong the xoa vi de tai khong co trong danh sach!");
		fprintf(file, "Khong the xoa vi de tai khong co trong danh sach!\n");
	}
}

void removeNVDTByMaDTAndMaSoNV(NVDTList *NVDT_List)
{
	NVDTNode *nodeToDelete = searchNVDTNodeByMaDeTaiAndMaSoNV(*NVDT_List);
	if (nodeToDelete != NULL)
	{
		if (nodeToDelete == NVDT_List->head)
		{
			NVDT_List->head = nodeToDelete->next;
		}
		else
		{
			NVDTNode *prevNode = NVDT_List->head;
			while (prevNode != NULL && prevNode->next != nodeToDelete)
			{
				prevNode = prevNode->next;
			}
			if (prevNode != NULL)
			{
				prevNode->next = nodeToDelete->next;
			}
		}
		printf("\nXoa thanh cong !");
		fprintf(file, "Xoa thanh cong !\n");
		free(nodeToDelete);
	}

	else
	{
		printf("\nKhong the xoa vi nhiem vu de tai khong co trong danh sach!");
		fprintf(file, "Khong the xoa vi nhiem vu de tai khong co trong danh sach!\n");
	}
}

void updateNVList(NVList *NV_List)
{
	NVNode *nodeUpdate = searchNVNodeByMaSoNV(*NV_List);
	if (nodeUpdate != NULL)
	{
		printf("\nNhap vao cac chinh sua cua nhan vien co ma so: %d", nodeUpdate->data.maSoNV);
		fprintf(file, "Nhap vao cac chinh sua cua nhan vien co ma so: %d\n", nodeUpdate->data.maSoNV);
		printf("\nHo ten dem: ");
		getchar();
		fgets(nodeUpdate->data.hoDem, sizeof(nodeUpdate->data.hoDem), stdin);
		deleteNewline(nodeUpdate->data.hoDem);
		fprintf(file, "Ho ten dem: %s\n", nodeUpdate->data.hoDem);
		printf("Ten nhan vien: ");
		fgets(nodeUpdate->data.tenNV, sizeof(nodeUpdate->data.tenNV), stdin);
		deleteNewline(nodeUpdate->data.tenNV);
		fprintf(file, "Ten nhan vien: %s\n", nodeUpdate->data.tenNV);
		printf("Gioi tinh (Nam/Nu): ");
		fgets(nodeUpdate->data.gioiTinh, sizeof(nodeUpdate->data.gioiTinh), stdin);
		deleteNewline(nodeUpdate->data.gioiTinh);
		fprintf(file, "Gioi tinh (Nam/Nu): %s\n", nodeUpdate->data.gioiTinh);
		enterNgaySinh(&nodeUpdate->data.ngaySinh);
		fprintf(file, "Ngay sinh (dd/mm/yyyy): %02d/02%d/%d \n", nodeUpdate->data.ngaySinh.ngay, nodeUpdate->data.ngaySinh.thang, nodeUpdate->data.ngaySinh.nam);
		printf("\nCap nhat thanh cong !");
	}
	else
	{
		printf("\nCap nhat that bai !");
		fprintf(file, "Cap nhat that bai !\n");
	}
}

void updateDTList(DTList *DT_List)
{
	DTNode *nodeUpdate = searchDTNodeByMaDeTai(*DT_List);
	if (nodeUpdate != NULL)
	{
		printf("\nNhap vao cac chinh sua cua de tai co ma la: %s", nodeUpdate->data.maDT);
		fprintf(file, "Nhap vao cac chinh sua cua de tai co ma la: %s\n", nodeUpdate->data.maDT);
		printf("\nTen De Tai: ");
		fgets(nodeUpdate->data.tenDT, sizeof(nodeUpdate->data.tenDT), stdin);
		deleteNewline(nodeUpdate->data.tenDT);
		fprintf(file, "Ten De Tai: %s\n", nodeUpdate->data.tenDT);
		printf("Nam bat dau: ");
		scanf("%d", &nodeUpdate->data.namBatDau);
		fprintf(file, "Nam bat dau: %d\n", nodeUpdate->data.namBatDau);
		printf("Nam ket thuc: ");
		scanf("%d", &nodeUpdate->data.namKetThuc);
		fprintf(file, "Nam ket thuc: %d\n", nodeUpdate->data.namKetThuc);
		printf("Kinh phi de tai: ");
		scanf("%ld", &nodeUpdate->data.kinhPhi);
		fprintf(file, "Kinh phi de tai: %d\n", nodeUpdate->data.kinhPhi);
		printf("\nCap nhat thanh cong !");
		fprintf(file, "Cap nhat thanh cong !\n");
	}
	else
	{
		printf("\nCap nhat that bai !");
		fprintf(file, "Cap nhat that bai !\n");
	}
}

void updateNVDTList(NVDTList *NVDT_List)
{
	NVDTNode *nodeUpdate = searchNVDTNodeByMaDeTaiAndMaSoNV(*NVDT_List);

	if (nodeUpdate != NULL)
	{
		printf("\nNhap vao cac chinh sua cua nhiem vu de tai co ma de tai %s va ma so nhan vien %d", nodeUpdate->data.maDT, nodeUpdate->data.maSoNV);
		fprintf(file, "Nhap vao cac chinh sua cua nhiem vu de tai co ma de tai %s va ma so nhan vien %d\n", nodeUpdate->data.maDT, nodeUpdate->data.maSoNV);
		printf("\nVai tro: ");

		getchar();
		fgets(nodeUpdate->data.vaiTro, sizeof(nodeUpdate->data.vaiTro), stdin);
		deleteNewline(nodeUpdate->data.vaiTro);
		fprintf(file, "Vai tro: %s\n", nodeUpdate->data.vaiTro);
		printf("\nCap nhat thanh cong !");
		fprintf(file, "Cap nhat thanh cong !\n");
	}
	else
	{
		printf("\nCap nhat that bai !");
		fprintf(file, "Cap nhat that bai !\n");
	}
}

void printNVNode(NVNode node)
{
	printf("\n |%20s \t |%30s \t |%30s \t |%20s \t |\t%26s |", "Ma so nhan vien", "Ho ten dem", "Ten nhan vien", "Gioi tinh", "Ngay sinh");
	fprintf(file, "\n |%20s \t |%30s \t |%30s \t |%20s \t |\t%26s |", "Ma so nhan vien", "Ho ten dem", "Ten nhan vien", "Gioi tinh", "Ngay sinh");
	printf("\n |%20d \t |%30s \t |%30s \t |%20s \t |\t%20d/%d/%d|", node.data.maSoNV, node.data.hoDem,
		   node.data.tenNV, node.data.gioiTinh, node.data.ngaySinh.ngay, node.data.ngaySinh.thang, node.data.ngaySinh.nam);
	fprintf(file, "\n |%20d \t |%30s \t |%30s \t |%20s \t |\t%20d/%d/%d|\n", node.data.maSoNV, node.data.hoDem,
			node.data.tenNV, node.data.gioiTinh, node.data.ngaySinh.ngay, node.data.ngaySinh.thang, node.data.ngaySinh.nam);
}

void printDTNode(DTNode node)
{
	printf("\n |%20s \t |%50s \t |%20s \t |%20s \t |%30s |", "Ma de tai", "Ten de tai", "Nam bat dau", "Nam ket thuc", "Kinh phi de tai");
	fprintf(file, "\n |%20s \t |%50s \t |%20s \t |%20s \t |%30s |", "Ma de tai", "Ten de tai", "Nam bat dau", "Nam ket thuc", "Kinh phi de tai");
	printf("\n |%20s \t |%50s \t |%20d \t |%20d \t |%30ld |", node.data.maDT, node.data.tenDT, node.data.namBatDau, node.data.namKetThuc, node.data.kinhPhi);
	fprintf(file, "\n |%20s \t |%50s \t |%20d \t |%20d \t |%30ld |\n", node.data.maDT, node.data.tenDT, node.data.namBatDau, node.data.namKetThuc, node.data.kinhPhi);
}

void printNVDTNode(NVDTNode node)
{
	printf("\n |%20s \t |%30s  \t|%30s|", "Ma de tai", "Ma so nhan vien", "Vai tro");
	fprintf(file, "\n |%20s \t |%30s  \t|%30s|", "Ma de tai", "Ma so nhan vien", "Vai tro");
	printf("\n |%20s \t |%30d  \t|%30s|", node.data.maDT, node.data.maSoNV, node.data.vaiTro);
	fprintf(file, "\n |%20s \t |%30d  \t|%30s|\n", node.data.maDT, node.data.maSoNV, node.data.vaiTro);
}

void printNVList(NVList NV_List)
{
	if (NV_List.head != NULL)
	{
		NVNode *node = NV_List.head;
		printf("\n |%20s \t |%30s \t |%30s \t |%20s \t |\t %26s \t|", "Ma so nhan vien", "Ho ten dem", "Ten nhan vien", "Gioi tinh", "Ngay sinh");
		fprintf(file, "\n |%20s \t |%30s \t |%30s \t |%20s \t |\t %26s \t|", "Ma so nhan vien", "Ho ten dem", "Ten nhan vien", "Gioi tinh", "Ngay sinh");
		while (node != NULL)
		{
			printf("\n |%20d \t |%30s \t |%30s \t |%20s \t |\t%20d/%02d/%d\t|", node->data.maSoNV, node->data.hoDem,
				   node->data.tenNV, node->data.gioiTinh, node->data.ngaySinh.ngay, node->data.ngaySinh.thang, node->data.ngaySinh.nam);
			fprintf(file, "\n |%20d \t |%30s \t |%30s \t |%20s \t |\t%20d/%02d/%d\t|", node->data.maSoNV, node->data.hoDem,
					node->data.tenNV, node->data.gioiTinh, node->data.ngaySinh.ngay, node->data.ngaySinh.thang, node->data.ngaySinh.nam);
			node = node->next;
		}
		fprintf(file, "\n");
	}
	else
	{
		printf("\nDanh sach nhan vien trong !");
		fprintf(file, "Danh sach nhan vien trong !\n");
	}
}

void printDTList(DTList DT_List)
{
	if (DT_List.head != NULL)
	{
		DTNode *node = DT_List.head;
		printf("\n |%20s \t |%50s \t |%20s \t |%20s \t |%30s |", "Ma de tai", "Ten de tai", "Nam bat dau", "Nam ket thuc", "Kinh phi de tai");
		fprintf(file, "\n |%20s \t |%50s \t |%20s \t |%20s \t |%30s |", "Ma de tai", "Ten de tai", "Nam bat dau", "Nam ket thuc", "Kinh phi de tai");
		while (node != NULL)
		{
			printf("\n |%20s \t |%50s \t |%20d \t |%20d \t |%30ld |", node->data.maDT, node->data.tenDT, node->data.namBatDau, node->data.namKetThuc, node->data.kinhPhi);
			fprintf(file, "\n |%20s \t |%50s \t |%20d \t |%20d \t |%30ld |", node->data.maDT, node->data.tenDT, node->data.namBatDau, node->data.namKetThuc, node->data.kinhPhi);
			node = node->next;
		}
		fprintf(file, "\n");
	}
	else
	{
		printf("Danh sach de tai trong !");
		fprintf(file, "Danh sach de tai trong !\n");
	}
}

void printNVDTList(NVDTList NVDT_List)
{
	if (NVDT_List.head != NULL)
	{
		NVDTNode *node = NVDT_List.head;
		printf("\n|%20s \t |%20s  \t|%20s|", "Ma de tai", "Ma so nhan vien", "Vai tro");
		fprintf(file, "\n|%20s \t |%20s  \t|%20s|", "Ma de tai", "Ma so nhan vien", "Vai tro");
		while (node != NULL)
		{
			printf("\n|%20s \t |%20d  \t|%20s|", node->data.maDT, node->data.maSoNV, node->data.vaiTro);
			fprintf(file, "\n|%20s \t |%20d  \t|%20s|", node->data.maDT, node->data.maSoNV, node->data.vaiTro);
			node = node->next;
		}
		fprintf(file, "\n");
	}
	else
	{
		printf("Danh sach nhiem vu de tai trong !");
		fprintf(file, "Danh sach nhiem vu de tai trong !\n");
	}
}

void importFileNV(NVList *NV_List)
{
	long i;
	FILE *f;
	f = fopen("NV.bin", "rb");
	if (f == NULL)
	{
		printf("Khong the mo file de doc!");
		fprintf(file, "Yeu cau 1 : Nhap du lieu cho file \"NV.bin\" that bai !\n");
		return;
	}
	fseek(f, 0, SEEK_END);
	long f_size = ftell(f);
	fseek(f, 0, SEEK_SET);
	NV *newNV = (NV *)malloc(f_size);
	NVNode *node;
	fread(newNV, sizeof(NV), f_size / sizeof(NV), f);
	fclose(f);
	for (i = 0; i < f_size / sizeof(NV); i++)
	{
		node = createNVNode(newNV[i]);
		addTailNVList(NV_List, node);
	}
	fprintf(file, "Yeu cau 1 : Nhap du lieu cho file \"NV.bin\" thanh cong !\n");

	free(newNV);
}

void importFileDT(DTList *DT_List)
{
	long i;
	FILE *f;
	f = fopen("DT.bin", "rb");
	if (f == NULL)
	{
		printf("Khong the mo file de doc!");
		fprintf(file, "Yeu cau 1 : Nhap du lieu cho file \"DT.bin\" that bai !\n");
		return;
	}
	fseek(f, 0, SEEK_END);
	long f_size = ftell(f);
	fseek(f, 0, SEEK_SET);
	DT *newDT = (DT *)malloc(f_size);
	DTNode *node;
	fread(newDT, sizeof(DT), f_size / sizeof(DT), f);
	fclose(f);
	for (i = 0; i < f_size / sizeof(DT); i++)
	{
		node = createDTNode(newDT[i]);
		addTailDTList(DT_List, node);
	}
	fprintf(file, "Yeu cau 1 : Nhap du lieu cho file \"DT.bin\" thanh cong !\n");
	free(newDT);
}

void importFileNVDT(NVDTList *NVDT_List)
{
	long i;
	FILE *f;
	f = fopen("NVDT.bin", "rb");
	if (f == NULL)
	{
		printf("Khong the mo file de doc!");
		fprintf(file, "Yeu cau 1 : Nhap du lieu cho file \"NVDT.bin\" that bai !\n");
		return;
	}
	fseek(f, 0, SEEK_END);
	long f_size = ftell(f);
	fseek(f, 0, SEEK_SET);
	NVDT *newNVDT = (NVDT *)malloc(f_size);
	NVDTNode *node;
	fread(newNVDT, sizeof(NVDT), f_size / sizeof(NVDT), f);
	fclose(f);
	for (i = 0; i < f_size / sizeof(NVDT); i++)
	{
		node = createNVDTNode(newNVDT[i]);
		addTailNVDTList(NVDT_List, node);
	}
	fprintf(file, "Yeu cau 1 : Nhap du lieu cho file \"NVDT.bin\" thanh cong !\n");
	free(newNVDT);
}

void exportFileNV(NVList NV_List)
{
	NVNode *node = NV_List.head;
	FILE *f;
	f = fopen("NV.bin", "wb");
	if (f == NULL)
	{
		printf("Khong the mo file de ghi!");
		fprintf(file, "Cap nhat du lieu vao file \"NV.bin\" that bai !\n");
		return;
	}
	while (node != NULL)
	{
		fwrite(&node->data, sizeof(NV), 1, f);
		node = node->next;
	}
	fprintf(file, "Cap nhat du lieu vao file \"NV.bin\" thanh cong !\n");
	fclose(f);
}

void exportFileDT(DTList DT_List)
{
	DTNode *node = DT_List.head;
	FILE *f;
	f = fopen("DT.bin", "wb");
	if (f == NULL)
	{
		printf("Khong the mo file de ghi!");
		fprintf(file, "Cap nhat du lieu vao file \"DT.bin\" that bai !\n");
		return;
	}
	while (node != NULL)
	{
		fwrite(&node->data, sizeof(DT), 1, f);
		node = node->next;
	}
	fprintf(file, "Cap nhat du lieu vao file \"DT.bin\" thanh cong !\n");
	fclose(f);
}

void exportFileNVDT(NVDTList NVDT_List)
{
	NVDTNode *node = NVDT_List.head;
	FILE *f;
	f = fopen("NVDT.bin", "wb");
	if (f == NULL)
	{
		printf("Khong the mo file de ghi!");
		fprintf(file, "Cap nhat du lieu vao file \"NVDT.bin\" that bai !\n");
		return;
	}
	while (node != NULL)
	{
		fwrite(&node->data, sizeof(NVDT), 1, f);
		node = node->next;
	}
	fprintf(file, "Cap nhat du lieu vao file \"NVDT.bin\" thanh cong !\n");
	fclose(f);
}

void requestThree(NVDTList NVDT_List)
{
	NVDTNode *node = NVDT_List.head;
	int count = 0;
	int maSoNV;
	printf("\nNhap vao ma so nhan vien: ");
	scanf("%d", &maSoNV);
	fprintf(file, "\nNhap vao ma so nhan vien: %d", maSoNV);
	printf("\nDanh sach de tai nhan vien %d tham gia cung nhiem vu la: ", maSoNV);
	fprintf(file, "\nDanh sach de tai nhan vien %d tham gia cung nhiem vu la: ", maSoNV);
	printf("\n|%20s  \t|%20s|", "Ma de tai", "Vai tro");
	fprintf(file, "\n|%20s  \t|%20s|", "Ma de tai", "Vai tro");
	while (node != NULL)
	{
		if (node->data.maSoNV == maSoNV)
		{

			printf("\n|%20s  \t|%20s|", node->data.maDT, node->data.vaiTro);
			fprintf(file, "\n|%20s  \t|%20s|", node->data.maDT, node->data.vaiTro);
			count++;
		}
		node = node->next;
	}
	fprintf(file, "\n");
	if (count < 1)
	{
		printf("\nNhan vien khong tham gia de tai n�o hoac khong co trong danh sach \"Nhan vien\"!");
		fprintf(file, "\nNhan vien khong tham gia de tai n�o hoac khong co trong danh sach \"Nhan vien\"!\n");
	}
}

void sortDeTai(DTList *DT_List)
{
	DTNode *node1 = DT_List->head;
	DTNode *node2;
	DT temp;
	for (node1; node1 != NULL; node1 = node1->next)
	{
		for (node2 = node1->next; node2 != NULL; node2 = node2->next)
		{
			if (node1->data.namBatDau > node2->data.namBatDau)
			{
				temp = node1->data;
				node1->data = node2->data;
				node2->data = temp;
			}
		}
	}
}

void requestFive()
{
	DTNode *deTai = searchDTNodeByMaDeTai(DT_List);
	NVDTNode *temp = NVDT_List.head;
	NVNode *node = NV_List.head;
	int i = 0;
	int maThuKy, maChuNhiem;
	int size = countNV(NV_List);
	int *maThanhVien = (int *)malloc(size * sizeof(int));
	char tenChuNhiem[100] = "";
	char tenThuKy[100] = "";
	char tenThanhVien[100][100] = {""};
	if (deTai != NULL)
	{
		printDTNode(*deTai);

		while (temp != NULL)
		{
			if (strcmp(temp->data.maDT, deTai->data.maDT) == 0)
			{
				if (strcmp(temp->data.vaiTro, "Chu nhiem") == 0)
				{
					maChuNhiem = temp->data.maSoNV;
				}
				else if (strcmp(temp->data.vaiTro, "Thu ky") == 0)
				{
					maThuKy = temp->data.maSoNV;
				}
				else
				{
					maThanhVien[i] = temp->data.maSoNV;
					i++;
				}
			}
			temp = temp->next;
		}

		while (node != NULL)
		{
			if (node->data.maSoNV == maChuNhiem)
			{
				strcat(tenChuNhiem, node->data.hoDem);
				strcat(tenChuNhiem, " ");
				strcat(tenChuNhiem, node->data.tenNV);
				printf("\n\nTen chu nhiem : %s", tenChuNhiem);
				fprintf(file, "\n\nTen chu nhiem : %s", tenChuNhiem);
			}
			if (node->data.maSoNV == maThuKy)
			{
				strcat(tenThuKy, node->data.hoDem);
				strcat(tenThuKy, " ");
				strcat(tenThuKy, node->data.tenNV);
				printf("\n\nTen thu ky : %s", tenThuKy);
				fprintf(file, "\n\nTen thu ky : %s", tenThuKy);
			}
			node = node->next;
		}

		node = NV_List.head;
		printf("\n\nDanh sach ten nhan vien: \n");
		fprintf(file, "\n\nDanh sach ten nhan vien: \n");
		printf("|%10s\t|%30s\t|\n", "STT", "Ten nhan vien");
		fprintf(file, "|%10s\t|%30s\t|\n", "STT", "Ten nhan vien");

		for (i = 0; i < size; i++)
		{
			node = NV_List.head;
			while (node != NULL)
			{
				if (node->data.maSoNV == maThanhVien[i])
				{
					strcpy(tenThanhVien[i], "");
					strcat(tenThanhVien[i], node->data.hoDem);
					strcat(tenThanhVien[i], " ");
					strcat(tenThanhVien[i], node->data.tenNV);
					printf("|%10d\t|%30s\t|\n", i + 1, tenThanhVien[i]);
					fprintf(file, "|%10d\t|%30s\t|\n", i + 1, tenThanhVien[i]);
				}
				node = node->next;
			}
		}

		free(maThanhVien);
	}
	else
	{
		printf("Thao tac that bai !");
		fprintf(file, "Thao tac that bai !\n");
	}
}

void totalCost(DTList DT_List)
{
	DTNode *node = DT_List.head;
	long int sum = 0;
	int namBatDau;
	printf("\nNhap vao nam bat dau: ");
	scanf("%d", &namBatDau);
	fprintf(file, "\nNhap vao nam bat dau: %d", namBatDau);
	if (node != NULL)
	{
		while (node != NULL)
		{
			if (node->data.namBatDau == namBatDau)
			{
				sum = sum + node->data.kinhPhi;
			}
			node = node->next;
		}
		printf("\nTong kinh phi cua nam %d la: %ld VND", namBatDau, sum);
		fprintf(file, "\nTong kinh phi cua nam %d la: %ld VND\n", namBatDau, sum);
	}

	else
	{
		printf("\nDanh sach \"De tai\" trong !");
		fprintf(file, "\nDanh sach \"De tai\" trong !\n");
	}
}
