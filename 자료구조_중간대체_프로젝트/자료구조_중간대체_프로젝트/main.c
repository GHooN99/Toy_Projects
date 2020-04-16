#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>


#define true 1
#define false 0

typedef int bool;
typedef int Index;


/* ------------------------------ */
/* ���� ȸ�� ��ǰ ������ ����ü ���� */
/* ------------------------------ */


typedef struct sales	//���� ����ü ����
{
	char date[9];		//20200413 8�ڸ� ���ڿ�
	int todaySales;		//���� ����
}sales;

typedef struct member	//ȸ�� ����ü ����
{
	char name[11];		//���� �̸� �ִ� 10��
	char id[12];		//01012345678 ��ȭ��ȣ �ִ� 11��
	int point;			//������ ����Ʈ
}member;

typedef struct product	//��ǰ ����ü ����
{
	char name[21];		//��ǰ �̸�
	int price;			//��ǰ ����
	int sellCnt;		//��ǰ �Ǹ� Ƚ��

}product;


/* ------------------------------ */
/* ���Ḯ��Ʈ ���Ǹ� ���� ��� ���� */
/* ------------------------------ */


typedef struct salesNode		//���� ��� ����ü ����
{
	struct salesNode *prev;		//���� ����� �ּ�
	sales data;					//���� ������
	struct salesNode *next;		//���� ����� �ּ�
}salesNode;

typedef struct memberNode		//ȸ�� ��� ����ü ����
{
	struct memberNode *prev;	//���� ����� �ּ�
	member data;				//���� ������
	struct memberNode *next;	//���� ����� �ּ�
}memberNode;

typedef struct productNode		//��ǰ ��� ����ü ����
{
	struct productNode *prev;	//���� ����� �ּ�
	product data;				//��ǰ ������
	struct productNode *next;	//���� ����� �ּ�
}productNode;


/* ---------------------------------- */
/* �� �����Ϳ� ���� ���� ���Ḯ��Ʈ ���� */
/* ---------------------------------- */


typedef struct salesList		//���� ����Ʈ ����
{
	salesNode *head;			//�Ӹ� ����� �ּ�
	salesNode *tail;			//���� ����� �ּ�
	salesNode *crnt;			//���� ���õ� ����� �ּ�
}salesList;

typedef struct memberList		//ȸ�� ����Ʈ ����
{
	memberNode *head;			//�Ӹ� ����� �ּ�
	memberNode *tail;			//���� ����� �ּ�
	memberNode *crnt;			//���� ���õ� ����� �ּ�
}memberList;

typedef struct productList		//��ǰ ����Ʈ ����
{
	productNode *head;			//�Ӹ� ����� �ּ�
	productNode *tail;			//���� ����� �ּ�
	productNode *crnt;			//���� ���õ� ����� �ּ�
}productList;

/* -------------------------------------------------------------------------- */
/* C ���� �Լ� �����ε��� �������� �ʴ´ٰ� �Ѵ�.
  ���� �� �����͵��� ����Ʈ�� ���� �����ϰ� �����Ǵ� �Լ� ���� ���� ������ �Ѵ� */
/* -------------------------------------------------------------------------- */


  /* ----------------------- */
  /* ���Ḯ��Ʈ ���� �Լ� ��� */
  /* ----------------------- */


  /* salesList �� ���� �Լ� ��� */

salesNode* allocSalesNode();														// �� ����� �ּҸ� ��ȯ�ϴ� �Լ�  
void setSalesNode(salesNode *n, salesNode *prev, salesNode *next, sales data);		// ����� ������ �����ϴ� �Լ�
int sizeOfSalesList(const salesList *list);											// ���� ����Ʈ�� ũ�⸦ ��ȯ�ϴ� �Լ� 
bool isEmptySalesList(const salesList *list);										// ���� ����Ʈ�� ����ִ��� Ȯ�� �ϴ� �Լ�
void setCurrentSalesNode(salesList *list, Index pos);								// ���� ���� ��带 Ư������ ����Ű�� �ϴ� �Լ�
void initializeSalesList(salesList *list);											// ����Ʈ�� �ʱ�ȭ �ϴ� �Լ�
void printSalesList(const salesList *list);											// ����Ʈ���� �����͸� ����ϴ� �Լ�
void addDataToSalesList(salesList *list, Index pos, sales data);					// ����Ʈ�� Ư�� ��ġ�� �����͸� �߰��ϴ� �Լ�
void deleteDataFromSalesList(salesList *list, Index pos);							// ����Ʈ�� Ư�� ��ġ�� �����͸� �����ϴ� �Լ�
sales getDataFromSalesList(salesList *list, Index pos);								// ����Ʈ�� Ư�� ��ġ�� �����͸� ��ȯ�ϴ� �Լ�
void terminateSalesList(salesList *list);											// ����Ʈ�� �Ҵ�� ������ �����ϰ� �����ϴ� �Լ�

/* memberList �� ���� �Լ� ��� */

memberNode* allocMemberNode();														// �� ����� �ּҸ� ��ȯ�ϴ� �Լ�  
void setMemberNode(memberNode *n, memberNode *prev, memberNode *next, member data);		// ����� ������ �����ϴ� �Լ�
int sizeOfMemberList(const memberList *list);											// ���� ����Ʈ�� ũ�⸦ ��ȯ�ϴ� �Լ� 
bool isEmptyMemberList(const memberList *list);										// ���� ����Ʈ�� ����ִ��� Ȯ�� �ϴ� �Լ�
void setCurrentMemberNode(memberList *list, Index pos);								// ���� ���� ��带 Ư������ ����Ű�� �ϴ� �Լ�
void initializeMemberList(memberList *list);											// ����Ʈ�� �ʱ�ȭ �ϴ� �Լ�
void printMemberList(const memberList *list);											// ����Ʈ���� �����͸� ����ϴ� �Լ�
void addDataToMemberList(memberList *list, Index pos, member data);					// ����Ʈ�� Ư�� ��ġ�� �����͸� �߰��ϴ� �Լ�
void deleteDataFromMemberList(memberList *list, Index pos);							// ����Ʈ�� Ư�� ��ġ�� �����͸� �����ϴ� �Լ�
member getDataFromMemberList(memberList *list, Index pos);								// ����Ʈ�� Ư�� ��ġ�� �����͸� ��ȯ�ϴ� �Լ�
void terminateMemberList(memberList *list);											// ����Ʈ�� �Ҵ�� ������ �����ϰ� �����ϴ� �Լ�

/* productList �� ���� �Լ� ��� */

productNode* allocProductNode();														// �� ����� �ּҸ� ��ȯ�ϴ� �Լ�  
void setProductNode(productNode *n, productNode *prev, productNode *next, product data);		// ����� ������ �����ϴ� �Լ�
int sizeOfProductList(const productList *list);											// ���� ����Ʈ�� ũ�⸦ ��ȯ�ϴ� �Լ� 
bool isEmptyProductList(const productList *list);										// ���� ����Ʈ�� ����ִ��� Ȯ�� �ϴ� �Լ�
void setCurrentProductNode(productList *list, Index pos);								// ���� ���� ��带 Ư������ ����Ű�� �ϴ� �Լ�
void initializeProductList(productList *list);											// ����Ʈ�� �ʱ�ȭ �ϴ� �Լ�
void printProductList(const productList *list);											// ����Ʈ���� �����͸� ����ϴ� �Լ�
void addDataToProductList(productList *list, Index pos, product data);					// ����Ʈ�� Ư�� ��ġ�� �����͸� �߰��ϴ� �Լ�
void deleteDataFromProductList(productList *list, Index pos);							// ����Ʈ�� Ư�� ��ġ�� �����͸� �����ϴ� �Լ�
product getDataFromProductList(productList *list, Index pos);								// ����Ʈ�� Ư�� ��ġ�� �����͸� ��ȯ�ϴ� �Լ�
void terminateProductList(productList *list);											// ����Ʈ�� �Ҵ�� ������ �����ϰ� �����ϴ� �Լ�


/* ------------------------ */
/* �ֿ� ��ɿ� ���� �Լ� ��� */
/* ------------------------ */


/* ȸ�� ������ ���� �Լ� ��� */

void printAllMember(memberList *list);		// ȸ�� ��ȸ �Լ�
void registerMember(memberList *list);		// ȸ�� ���� �Լ�
void changeMemberName(memberList *list);	// ȸ�� �̸� ���� �Լ�
void changeMemberID(memberList *list);		// ȸ�� ���̵� ���� �Լ�
void deleteMember(memberList *list);		// ȸ�� ���� �Լ�
void changePointOfMember(member *list);		// ȸ�� ���� �Լ�

/* ��ǰ ������ ���� �Լ� ��� */

void addProduct(productList *list);			// ��ǰ �߰� �Լ�
void deleteProduct(productList *list);		// ��ǰ ���� �Լ�
void changeProductPrice(productList *list); // ��ǰ ���� ���� �Լ�
void printAllProduct(productList *list);    // ��� ��ǰ ��� �Լ�

/* �ֹ� ������ ���� �Լ� ��� */

void orderProduct(productList *prodictlist, salesList *saleslist, memberList *memberlist);	// ��ǰ �ֹ� �Լ�
void cancelOrder(productList *prodictlist, salesList *saleslist, memberList *memberlist);   // ��ǰ �ֹ� ��� �Լ�

/* ���� ������ ���� �Լ� ��� */

void printAllSales(salesList *list);		// �� ���� ��� �Լ�
void printSalesByDates(salesList *list);    // ��¥ �� ���� ��� �Լ� 
void printSalesByProduct(salesList *saleslist, productList *productlist);					// ��ǰ �� ���� ��� �Լ�


/* -------------------------- */
/* ���� ����¿� ���� �Լ� ��� */
/* -------------------------- */


void loadMemberFromFile(memberList *list);	// ȸ�� ��� �ҷ�����
void saveMemberToFile(memberList *list);	// ȸ�� ��� �����ϱ�

void loadProductFromFile(memberList *list); // ��ǰ ��� �ҷ�����
void saveProductToFile(memberList *list);	// ��ǰ ��� �����ϱ�

void loadSalesFromFile(memberList *list);	// ȸ�� ��� �ҷ�����
void saveSalesToFile(memberList *list);		// ȸ�� ��� �����ϱ�


/* --------------------------*/
/* �������̽��� ���� �Լ� ��� */
/* --------------------------*/


void printMainWindow();
void printSelectMenu();
void printMemberManageMenu();
void printProductManageMenu();
void printOrderManageMenu();
void printSalesManageMenu();





/* ------------------ */
/* ��Ÿ �ʿ� �Լ� ��� */
/* ------------------ */








/* -------- */
/* ���� �Լ� */
/* -------- */


int main()
{
	memberList member_list;
	salesList sales_list;
	productList product_list;

	printMainWindow(); // ���� ������ ���� 



	return 0;
}