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


/* --------------------------*/
/* �������̽��� ���� �Լ� ��� */
/* --------------------------*/


void printMainWindow();
void printSelectMenu();
void printMemberManageMenu();
void printProductManageMenu();
void printOrderManageMenu();
void printSalesManageMenu();

/* ------------------------ */
/* �ֿ� ��ɿ� ���� �Լ� ��� */
/* ------------------------ */


/* ȸ�� ������ ���� �Լ� ��� */
Index findIndexOfMemberByName(const memberList *list, const char name[]); // �̸����� ȸ�� �˻�
Index findIndexOfMemberById(const memberList *list, const char id[]);	//ȸ�� ���̵� �˻� �Լ�
void printAllMember(memberList *list);		// ȸ�� ��ȸ �Լ�
void registerMember(memberList *list);		// ȸ�� ���� �Լ�
void changeMemberName(memberList *list);	// ȸ�� �̸� ���� �Լ�
void changeMemberID(memberList *list);		// ȸ�� ���̵� ���� �Լ�
void deleteMember(memberList *list);		// ȸ�� ���� �Լ�
void changePointOfMember(member *list,int point);		// ȸ�� ���� �Լ�

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








/* ------------------ */
/* ��Ÿ �ʿ� �Լ� ��� */
/* ------------------ */








/* -------- */
/* ���� �Լ� */
/* -------- */

#define DEBUG

int main()
{
	
#ifdef DEBUG

	memberList member_list;
	salesList sales_list;
	productList product_list;

	member mdata1 = { "Kim","01012345678",1000 };
	member mdata2 = { "Lee","01099999999",2000 };

	product pdata1 = { "Coffee",4000,0 };
	product pdata2 = { "Cake",2000,2 };

	sales sdata1 = { "20200419",15000 };
	sales sdata2 = { "20200420",40000 };

	/*DEBUG_MEMBER_LIST*/
	initializeMemberList(&member_list);
	addDataToMemberList(&member_list, 1, mdata1);
	addDataToMemberList(&member_list, 2, mdata2);
	printMemberList(&member_list);
	deleteDataFromMemberList(&member_list, 1);
	registerMember(&member_list);
	printMemberList(&member_list);
	changeMemberName(&member_list);
	printMemberList(&member_list);
	changeMemberID(&member_list);
	printMemberList(&member_list);
	deleteMember(&member_list);
	printMemberList(&member_list);
	terminateMemberList(&member_list);

	/*DEBUG_PRODUCT_LIST*/


	initializeProductList(&product_list);
	addDataToProductList(&product_list, 1, pdata1);
	addDataToProductList(&product_list, 2, pdata2);
	printProductList(&product_list);
	deleteDataFromProductList(&product_list, 1);
	printProductList(&product_list);

	terminateProductList(&product_list);

	/*DEBUG_MEMBER_LIST*/
	initializeSalesList(&sales_list);
	addDataToSalesList(&sales_list, 1, sdata1);
	addDataToSalesList(&sales_list, 2, sdata2);
	printSalesList(&sales_list);
	deleteDataFromSalesList(&sales_list, 1);
	printSalesList(&sales_list);

	terminateSalesList(&sales_list);

	return 0;


#endif // DEBUG

	//printMainWindow(); // ���� ������ ���� 



	return 0;
}


/* --------- */
/* �Լ� ���� */
/* --------- */


/* ----------------------- */
/* ���Ḯ��Ʈ ���� �Լ� ��� */
/* ----------------------- */


/* salesList �� ���� �Լ� ��� */

salesNode* allocSalesNode()														// �� ����� �ּҸ� ��ȯ�ϴ� �Լ�
{
	return (salesNode*)calloc(1, sizeof(salesNode));							//���ο� ����ּҸ� �Ҵ��Ͽ� ��ȯ
}
void setSalesNode(salesNode *n, salesNode *prev, salesNode *next, sales data)		// ����� ������ �����ϴ� �Լ�
{
	n->prev = prev;																	// prev ����
	n->next = next;																	//next ����
	n->data = data;																	// data ���� 
}
int sizeOfSalesList(const salesList *list)											// ���� ����Ʈ�� ũ�⸦ ��ȯ�ϴ� �Լ� 
{
	int cnt = 0;																	// ũ�� �ʱ�ȭ
	salesNode *ptr = list->head->next;												// ptr ������ ���� �����ϴ� ù ��� ����
	while (ptr->next != NULL)														// ptr ����� ������尡 NULL �� �� ���� �ݺ�(�� ������ �������)
	{
		cnt++;																		// ũ�⺯�� ����
		ptr = ptr->next;															// ptr �� ���� ����
	}
	return cnt;																		// ũ�� ��ȯ
}
bool isEmptySalesList(const salesList *list)										// ���� ����Ʈ�� ����ִ��� Ȯ�� �ϴ� �Լ�
{
	if (list->head->next == list->tail) return true;								// �Ӹ������ ������尡 ���� ����϶� ����ִ� ����Ʈ��
	else return false;
}
void setCurrentSalesNode(salesList *list, Index pos)								// ���� ���� ��带 Ư������ ����Ű�� �ϴ� �Լ�
{
	if (isEmptySalesList(list))																// �� ����Ʈ�϶� 
	{
		list->crnt = list->tail;													// �������� ����Ŵ
		return;
	}
	salesNode *ptr = list->head;													// �ӽ� ptr ������ �Ӹ���带 ����Ű�� �� 
	for (Index i = 0; i <= pos; ptr = ptr->next, i++)								// ptr�� pos���� ����Ű�� �Ѵ�.
	{
		list->crnt = ptr;															// ptr�� ���� ���� ����
	}
}
void initializeSalesList(salesList *list)											// ����Ʈ�� �ʱ�ȭ �ϴ� �Լ�
{
	sales data = {0};
	list->head = allocSalesNode();														// �Ӹ� ��带 �Ҵ�
	list->tail = allocSalesNode();														// ���� ��带 �Ҵ�
	setSalesNode(list->head, NULL, list->tail, data);										// �Ӹ���带 �ʱ�ȭ
	setSalesNode(list->tail, list->head, NULL, data);										// ���� ��带 �ʱ�ȭ

	list->crnt = list->head;														// ���� ���� ��� �ʱ�ȭ
}
void printSalesList(const salesList *list)											// ����Ʈ���� �����͸� ����ϴ� �Լ�
{
	salesNode *ptr = list->head->next;												// ptr�� �� ó�� �� ���� ����
	if (!isEmptySalesList(list))																// �� ����Ʈ�� �ƴϸ� ���
	{
		while (ptr->next != NULL)													// ����Ʈ ������ Ž��
		{
			printf("%s %d\n", ptr->data.date,ptr->data.todaySales);												// ������ ���
			ptr = ptr->next;														// ptr�� ���� ����		/*TODO ������ ��� ���� �ٲ����*/
		}
		printf("\n");   
	}

}
void addDataToSalesList(salesList *list, Index pos, sales data)					// ����Ʈ�� Ư�� ��ġ�� �����͸� �߰��ϴ� �Լ�
{
	//if (!isValidPosition(list, pos - 1))										// �ùٸ� ��ġ�� ���� ����
	//{
	//	printf("invalid position\n");											// �����޽��� ���
	//	return;																	// �Լ� ������ ����
	//}

	setCurrentSalesNode(list, pos);													// ���� ���� ��带 pos��ġ ���� ����

	salesNode *new_node = allocSalesNode();											// ���ο� ��带 �Ҵ�
	salesNode *crnt_node = list->crnt->prev;									// ���Ե� ��ġ�� ���� �ּ� ����

	crnt_node->next = new_node;													// ���Ե� ��ġ�� ���� ��带 ����忡 ����
	list->crnt->prev = new_node;												// ���Ե� ��ġ�� ���� ��带 ����忡 ����

	setSalesNode(new_node, crnt_node, list->crnt, data);								// �� ��� ��ġ�� ������ ���� 
}
void deleteDataFromSalesList(salesList *list, Index pos)							// ����Ʈ�� Ư�� ��ġ�� �����͸� �����ϴ� �Լ�
{
	//if (!isValidPosition(list, pos))												// �ùٸ� ��ġ�� ���� Ȯ�� �Լ�
	//{
	//	printf("invalid position\n");												// �����޽��� ���
	//	return;																		// �Լ� ������ ����
	//}
	setCurrentSalesNode(list, pos);														// ���� ���� ��带 pos��ġ ���� ����

	salesNode *A = list->crnt->prev;												// �ӽ� ���� ��� ����
	salesNode *B = list->crnt->next;												// �ӽ� ���� ��� ����

	A->next = B;																	// ������ ��� �յڸ� ���� ����
	B->prev = A;																	// ������ ��� �յڸ� ���� ����

	free(list->crnt);																// ������ ��� ���� �Ҵ� ����

	list->crnt = list->head;														// ���� ���� ��带 �Ӹ����� 

}
sales getDataFromSalesList(salesList *list, Index pos)								// ����Ʈ�� Ư�� ��ġ�� �����͸� ��ȯ�ϴ� �Լ�
{
	//if (!isValidPosition(list, pos))												// �ùٸ� ���� ���� Ȯ��
	//{	
	//	printf("invalid position\n");												// ���� �޽��� ���
	//	return ;																	// �Լ� ������ ����
	//}

	setCurrentSalesNode(list, pos);														// ���� ���� ��带 pos��° ����

	return list->crnt->data;														// ���� ���� ��� ������ ��ȯ
}
void terminateSalesList(salesList *list)											// ����Ʈ�� �Ҵ�� ������ �����ϰ� �����ϴ� �Լ�
{
	while (!isEmptySalesList(list))															// �� ����Ʈ�� �� �� ����
	{
		deleteDataFromSalesList(list, 1);														// �� �� ��带 ����
	}
	list->crnt = NULL;																// ���� ���� ��带 NULL ��
	free(list->head);																// �Ӹ� ��� �Ҵ� ����
	free(list->tail);																// ���� ��� �Ҵ� ����
}

/* memberList �� ���� �Լ� ��� */

memberNode* allocMemberNode()														// �� ����� �ּҸ� ��ȯ�ϴ� �Լ�
{
	return (memberNode*)calloc(1, sizeof(memberNode));							//���ο� ����ּҸ� �Ҵ��Ͽ� ��ȯ
}
void setMemberNode(memberNode *n, memberNode *prev, memberNode *next, member data)		// ����� ������ �����ϴ� �Լ�
{
	n->prev = prev;																	// prev ����
	n->next = next;																	//next ����
	n->data = data;																	// data ���� 
}
int sizeOfMemberList(const memberList *list)											// ���� ����Ʈ�� ũ�⸦ ��ȯ�ϴ� �Լ� 
{
	int cnt = 0;																	// ũ�� �ʱ�ȭ
	memberNode *ptr = list->head->next;												// ptr ������ ���� �����ϴ� ù ��� ����
	while (ptr->next != NULL)														// ptr ����� ������尡 NULL �� �� ���� �ݺ�(�� ������ �������)
	{
		cnt++;																		// ũ�⺯�� ����
		ptr = ptr->next;															// ptr �� ���� ����
	}
	return cnt;																		// ũ�� ��ȯ
}
bool isEmptyMemberList(const memberList *list)										// ���� ����Ʈ�� ����ִ��� Ȯ�� �ϴ� �Լ�
{
	if (list->head->next == list->tail) return true;								// �Ӹ������ ������尡 ���� ����϶� ����ִ� ����Ʈ��
	else return false;
}
void setCurrentMemberNode(memberList *list, Index pos)								// ���� ���� ��带 Ư������ ����Ű�� �ϴ� �Լ�
{
	if (isEmptyMemberList(list))																// �� ����Ʈ�϶� 
	{
		list->crnt = list->tail;													// �������� ����Ŵ
		return;
	}
	memberNode *ptr = list->head;													// �ӽ� ptr ������ �Ӹ���带 ����Ű�� �� 
	for (Index i = 0; i <= pos; ptr = ptr->next, i++)								// ptr�� pos���� ����Ű�� �Ѵ�.
	{
		list->crnt = ptr;															// ptr�� ���� ���� ����
	}
}
void initializeMemberList(memberList *list)											// ����Ʈ�� �ʱ�ȭ �ϴ� �Լ�
{
	member data = { 0 };
	list->head = allocMemberNode();														// �Ӹ� ��带 �Ҵ�
	list->tail = allocMemberNode();														// ���� ��带 �Ҵ�
	setMemberNode(list->head, NULL, list->tail, data);										// �Ӹ���带 �ʱ�ȭ
	setMemberNode(list->tail, list->head, NULL, data);										// ���� ��带 �ʱ�ȭ

	list->crnt = list->head;														// ���� ���� ��� �ʱ�ȭ
}
void printMemberList(const memberList *list)											// ����Ʈ���� �����͸� ����ϴ� �Լ�
{
	memberNode *ptr = list->head->next;												// ptr�� �� ó�� �� ���� ����
	if (!isEmptyMemberList(list))																// �� ����Ʈ�� �ƴϸ� ���
	{
		while (ptr->next != NULL)													// ����Ʈ ������ Ž��
		{
			printf("%s %s %d\n", ptr->data.name, ptr->data.id, ptr->data.point);												// ������ ���
			ptr = ptr->next;														// ptr�� ���� ����		/*TODO ������ ��� ���� �ٲ����*/
		}
		printf("\n");
	}

}
void addDataToMemberList(memberList *list, Index pos, member data)					// ����Ʈ�� Ư�� ��ġ�� �����͸� �߰��ϴ� �Լ�
{
	//if (!isValidPosition(list, pos - 1))										// �ùٸ� ��ġ�� ���� ����
	//{
	//	printf("invalid position\n");											// �����޽��� ���
	//	return;																	// �Լ� ������ ����
	//}

	setCurrentMemberNode(list, pos);													// ���� ���� ��带 pos��ġ ���� ����

	memberNode *new_node = allocMemberNode();											// ���ο� ��带 �Ҵ�
	memberNode *crnt_node = list->crnt->prev;									// ���Ե� ��ġ�� ���� �ּ� ����

	crnt_node->next = new_node;													// ���Ե� ��ġ�� ���� ��带 ����忡 ����
	list->crnt->prev = new_node;												// ���Ե� ��ġ�� ���� ��带 ����忡 ����

	setMemberNode(new_node, crnt_node, list->crnt, data);								// �� ��� ��ġ�� ������ ���� 
}
void deleteDataFromMemberList(memberList *list, Index pos)							// ����Ʈ�� Ư�� ��ġ�� �����͸� �����ϴ� �Լ�
{
	//if (!isValidPosition(list, pos))												// �ùٸ� ��ġ�� ���� Ȯ�� �Լ�
	//{
	//	printf("invalid position\n");												// �����޽��� ���
	//	return;																		// �Լ� ������ ����
	//}
	setCurrentMemberNode(list, pos);														// ���� ���� ��带 pos��ġ ���� ����

	memberNode *A = list->crnt->prev;												// �ӽ� ���� ��� ����
	memberNode *B = list->crnt->next;												// �ӽ� ���� ��� ����

	A->next = B;																	// ������ ��� �յڸ� ���� ����
	B->prev = A;																	// ������ ��� �յڸ� ���� ����

	free(list->crnt);																// ������ ��� ���� �Ҵ� ����

	list->crnt = list->head;														// ���� ���� ��带 �Ӹ����� 

}
member getDataFromMemberList(memberList *list, Index pos)								// ����Ʈ�� Ư�� ��ġ�� �����͸� ��ȯ�ϴ� �Լ�
{
	//if (!isValidPosition(list, pos))												// �ùٸ� ���� ���� Ȯ��
	//{	
	//	printf("invalid position\n");												// ���� �޽��� ���
	//	return ;																	// �Լ� ������ ����
	//}

	setCurrentMemberNode(list, pos);														// ���� ���� ��带 pos��° ����

	return list->crnt->data;														// ���� ���� ��� ������ ��ȯ
}
void terminateMemberList(memberList *list)											// ����Ʈ�� �Ҵ�� ������ �����ϰ� �����ϴ� �Լ�
{
	while (!isEmptyMemberList(list))															// �� ����Ʈ�� �� �� ����
	{
		deleteDataFromMemberList(list, 1);														// �� �� ��带 ����
	}
	list->crnt = NULL;																// ���� ���� ��带 NULL ��
	free(list->head);																// �Ӹ� ��� �Ҵ� ����
	free(list->tail);																// ���� ��� �Ҵ� ����
}




/* productList �� ���� �Լ� ��� */


productNode* allocProductNode()														// �� ����� �ּҸ� ��ȯ�ϴ� �Լ�
{
	return (productNode*)calloc(1, sizeof(productNode));							//���ο� ����ּҸ� �Ҵ��Ͽ� ��ȯ
}
void setProductNode(productNode *n, productNode *prev, productNode *next, product data)		// ����� ������ �����ϴ� �Լ�
{
	n->prev = prev;																	// prev ����
	n->next = next;																	//next ����
	n->data = data;																	// data ���� 
}
int sizeOfProductList(const productList *list)											// ���� ����Ʈ�� ũ�⸦ ��ȯ�ϴ� �Լ� 
{
	int cnt = 0;																	// ũ�� �ʱ�ȭ
	productNode *ptr = list->head->next;												// ptr ������ ���� �����ϴ� ù ��� ����
	while (ptr->next != NULL)														// ptr ����� ������尡 NULL �� �� ���� �ݺ�(�� ������ �������)
	{
		cnt++;																		// ũ�⺯�� ����
		ptr = ptr->next;															// ptr �� ���� ����
	}
	return cnt;																		// ũ�� ��ȯ
}
bool isEmptyProductList(const productList *list)										// ���� ����Ʈ�� ����ִ��� Ȯ�� �ϴ� �Լ�
{
	if (list->head->next == list->tail) return true;								// �Ӹ������ ������尡 ���� ����϶� ����ִ� ����Ʈ��
	else return false;
}
void setCurrentProductNode(productList *list, Index pos)								// ���� ���� ��带 Ư������ ����Ű�� �ϴ� �Լ�
{
	if (isEmptyProductList(list))																// �� ����Ʈ�϶� 
	{
		list->crnt = list->tail;													// �������� ����Ŵ
		return;
	}
	productNode *ptr = list->head;													// �ӽ� ptr ������ �Ӹ���带 ����Ű�� �� 
	for (Index i = 0; i <= pos; ptr = ptr->next, i++)								// ptr�� pos���� ����Ű�� �Ѵ�.
	{
		list->crnt = ptr;															// ptr�� ���� ���� ����
	}
}
void initializeProductList(productList *list)											// ����Ʈ�� �ʱ�ȭ �ϴ� �Լ�
{
	product data = { 0 };
	list->head = allocProductNode();														// �Ӹ� ��带 �Ҵ�
	list->tail = allocProductNode();														// ���� ��带 �Ҵ�
	setProductNode(list->head, NULL, list->tail, data);										// �Ӹ���带 �ʱ�ȭ
	setProductNode(list->tail, list->head, NULL, data);										// ���� ��带 �ʱ�ȭ

	list->crnt = list->head;														// ���� ���� ��� �ʱ�ȭ
}
void printProductList(const productList *list)											// ����Ʈ���� �����͸� ����ϴ� �Լ�
{
	productNode *ptr = list->head->next;												// ptr�� �� ó�� �� ���� ����
	if (!isEmptyProductList(list))																// �� ����Ʈ�� �ƴϸ� ���
	{
		while (ptr->next != NULL)													// ����Ʈ ������ Ž��
		{
			printf("%s %d %d\n", ptr->data.name,ptr->data.price,ptr->data.sellCnt);												// ������ ���
			ptr = ptr->next;														// ptr�� ���� ����		/*TODO ������ ��� ���� �ٲ����*/
		}
		printf("\n");
	}

}
void addDataToProductList(productList *list, Index pos, product data)					// ����Ʈ�� Ư�� ��ġ�� �����͸� �߰��ϴ� �Լ�
{
	//if (!isValidPosition(list, pos - 1))										// �ùٸ� ��ġ�� ���� ����
	//{
	//	printf("invalid position\n");											// �����޽��� ���
	//	return;																	// �Լ� ������ ����
	//}

	setCurrentProductNode(list, pos);													// ���� ���� ��带 pos��ġ ���� ����

	productNode *new_node = allocProductNode();											// ���ο� ��带 �Ҵ�
	productNode *crnt_node = list->crnt->prev;									// ���Ե� ��ġ�� ���� �ּ� ����

	crnt_node->next = new_node;													// ���Ե� ��ġ�� ���� ��带 ����忡 ����
	list->crnt->prev = new_node;												// ���Ե� ��ġ�� ���� ��带 ����忡 ����

	setProductNode(new_node, crnt_node, list->crnt, data);								// �� ��� ��ġ�� ������ ���� 
}
void deleteDataFromProductList(productList *list, Index pos)							// ����Ʈ�� Ư�� ��ġ�� �����͸� �����ϴ� �Լ�
{
	//if (!isValidPosition(list, pos))												// �ùٸ� ��ġ�� ���� Ȯ�� �Լ�
	//{
	//	printf("invalid position\n");												// �����޽��� ���
	//	return;																		// �Լ� ������ ����
	//}
	setCurrentProductNode(list, pos);														// ���� ���� ��带 pos��ġ ���� ����

	productNode *A = list->crnt->prev;												// �ӽ� ���� ��� ����
	productNode *B = list->crnt->next;												// �ӽ� ���� ��� ����

	A->next = B;																	// ������ ��� �յڸ� ���� ����
	B->prev = A;																	// ������ ��� �յڸ� ���� ����

	free(list->crnt);																// ������ ��� ���� �Ҵ� ����

	list->crnt = list->head;														// ���� ���� ��带 �Ӹ����� 

}
product getDataFromProductList(productList *list, Index pos)								// ����Ʈ�� Ư�� ��ġ�� �����͸� ��ȯ�ϴ� �Լ�
{
	//if (!isValidPosition(list, pos))												// �ùٸ� ���� ���� Ȯ��
	//{	
	//	printf("invalid position\n");												// ���� �޽��� ���
	//	return ;																	// �Լ� ������ ����
	//}

	setCurrentProductNode(list, pos);														// ���� ���� ��带 pos��° ����

	return list->crnt->data;														// ���� ���� ��� ������ ��ȯ
}
void terminateProductList(productList *list)											// ����Ʈ�� �Ҵ�� ������ �����ϰ� �����ϴ� �Լ�
{
	while (!isEmptyProductList(list))															// �� ����Ʈ�� �� �� ����
	{
		deleteDataFromProductList(list, 1);														// �� �� ��带 ����
	}
	list->crnt = NULL;																// ���� ���� ��带 NULL ��
	free(list->head);																// �Ӹ� ��� �Ҵ� ����
	free(list->tail);																// ���� ��� �Ҵ� ����
}


/* --------------------------*/
/* �������̽��� ���� �Լ� ��� */
/* --------------------------*/


void printMainWindow();

void printSelectMenu();

void printMemberManageMenu();

void printProductManageMenu();

void printOrderManageMenu();

void printSalesManageMenu();

/* ------------------------ */
/* �ֿ� ��ɿ� ���� �Լ� ��� */
/* ------------------------ */


/* ȸ�� ������ ���� �Լ� ��� */

Index findIndexOfMemberByName(const memberList *list,const char name[])	//ȸ�� �̸� �˻� �Լ�
{
	memberNode *ptr = list->head->next;												// ptr�� �� ó�� �� ���� ����
	Index i=1;																	// i�� 1����
	if (!isEmptyMemberList(list))																// �� ����Ʈ�� �ƴϸ� ����
	{
		while (ptr->next != NULL)													// ����Ʈ ������ Ž��
		{
			if (strcmp(name, ptr->data.name) == 0)										// ã�� �̸��̸�
			{
				return i;															// ���� �ε��� ��ȯ
			}
			ptr = ptr->next;														// ptr�� ���� ����		/*TODO ������ ��� ���� �ٲ����*/
			i++;
		}
	}
	return -1;			// ã�� ���Ͽ�����
}
Index findIndexOfMemberById(const memberList *list, const char id[])	//ȸ�� ���̵� �˻� �Լ�
{
	memberNode *ptr = list->head->next;												// ptr�� �� ó�� �� ���� ����
	Index i = 1;																	// i�� 1����
	if (!isEmptyMemberList(list))																// �� ����Ʈ�� �ƴϸ� ����
	{
		while (ptr->next != NULL)													// ����Ʈ ������ Ž��
		{
			if (strcmp(id, ptr->data.id) == 0)										// ã�� ���̵��̸�
			{
				return i;															// ���� �ε��� ��ȯ
			}
			ptr = ptr->next;														// ptr�� ���� ����		/*TODO ������ ��� ���� �ٲ����*/
			i++;
		}
	}
	return -1;			// ã�� ���Ͽ�����
}
void printAllMember(memberList *list)		// ȸ�� ��ȸ �Լ�
{

	printMemberList(list);
}
void registerMember(memberList *list)		// ȸ�� ���� �Լ�
{
	char new_name[11];					// ���ο� �̸� ����
	char new_id[12];					// ���ο� ��ȭ��ȣ ����
	int new_point=0;					// ���ο� ����Ʈ ���� 

	printf("ȸ������\n");				//TODO ���� �������̽� �����

	printf("�̸��� �Է����ּ���. (����10�� �̳�) :");				// �̸� �Է� �ȳ�
	scanf("%s", new_name);										// �̸� �Է�
	printf("��ȭ��ȣ�� �Է����ּ���. (ex.01012345678) :");		// ��ȭ��ȣ �Է� �ȳ�
	scanf("%s", new_id);										// ��ȭ��ȣ �Է�

	member new_member = { "tmp","tmp",new_point };				// ���ο�  ȸ�� ����ü ����
	strcpy(new_member.name, new_name);							// �̸��� ����
	strcpy(new_member.id, new_id);								// ��ȭ��ȣ�� ����


	addDataToMemberList(list, 1, new_member);					// ���ο� ȸ���� ����Ʈ�� �� �տ� �߰�
	
	printf("���� �Ϸ� !!\n");									// ���� �Ϸ� �޽���
}
void changeMemberName(memberList *list)	// ȸ�� �̸� ���� �Լ�
{
	char find_name[11];
	char new_name[11];

	Index find_name_idx;

	printf("ã�� �̸��� �Է����ּ���. (����10�� �̳�) :");				// �̸� �Է� �ȳ�
	scanf("%s", find_name);										// �̸� �Է�

	find_name_idx = findIndexOfMemberByName(list, find_name);
	
	if (find_name_idx == -1)										// �̸��� ������ ó��
	{
		printf("�̸��� ã�� ���Ͽ����ϴ�.\n");						// ���� �޽��� ���
		return;														// �Լ� ������ ����
	}

	setCurrentMemberNode(list, find_name_idx);

	printf("�̸��� ã�ҽ��ϴ�!\n");
	printf("ȸ�� ����\n%s %s %d\n", list->crnt->data.name, list->crnt->data.id, list->crnt->data.point);		// ã�� ȸ�� �������

	printf("�ٲ� �̸��� �Է����ּ���. (����10�� �̳�) :");				// �̸� �Է� �ȳ�
	scanf("%s", new_name);											// �� �̸� �Է� 

	strcpy(list->crnt->data.name, new_name);					// ���̸��� �����̸��� �����

	printf("���� �Ϸ� !!\n");									// �Ϸ� �޽��� ��� 

}
void changeMemberID(memberList *list)	// ȸ�� ���̵� ���� �Լ�
{
	char find_id[12];
	char new_id[12];

	Index find_id_idx;

	printf("ã�� ���̵��� �Է����ּ���. (ex.01012345678) :");				// �̸� �Է� �ȳ�
	scanf("%s", find_id);										// �̸� �Է�

	find_id_idx = findIndexOfMemberById(list, find_id);

	if (find_id_idx == -1)										// �̸��� ������ ó��
	{
		printf("���̵��� ã�� ���Ͽ����ϴ�.\n");						// ���� �޽��� ���
		return;														// �Լ� ������ ����
	}

	setCurrentMemberNode(list, find_id_idx);

	printf("���̵��� ã�ҽ��ϴ�!\n");
	printf("ȸ�� ����\n%s %s %d\n", list->crnt->data.name, list->crnt->data.id, list->crnt->data.point);		// ã�� ȸ�� �������

	printf("�ٲ� ���̵��� �Է����ּ���. (ex.01012345678) :");				// �̸� �Է� �ȳ�
	scanf("%s", new_id);											// �� �̸� �Է� 

	strcpy(list->crnt->data.id, new_id);					// ���̸��� �����̸��� �����

	printf("���� �Ϸ� !!\n");									// �Ϸ� �޽��� ��� 
}
void deleteMember(memberList *list)		// ȸ�� ���� �Լ�
{
	char find_name[11];
	char del_mem;

	Index find_name_idx;

	printf("������ ȸ���� �̸��� �Է����ּ���. (����10�� �̳�) :");				// �̸� �Է� �ȳ�
	scanf("%s", find_name);										// �̸� �Է�

	find_name_idx = findIndexOfMemberByName(list, find_name);

	if (find_name_idx == -1)										// �̸��� ������ ó��
	{
		printf("�̸��� ã�� ���Ͽ����ϴ�.\n");						// ���� �޽��� ���
		return;														// �Լ� ������ ����
	}

	printf("�����Ͻðڽ��ϱ�? [Y:N] :");
	getchar();
	scanf("%c", &del_mem);

	if (del_mem == 'N' || del_mem == 'n')
	{
		printf("������ ����ϼ̽��ϴ�.\n");
		return;
	}

	deleteDataFromMemberList(list, find_name_idx);

	printf("���� �Ϸ�!!\n");
}
void changePointOfMember(member *list,int point)		// ȸ�� ���� �Լ�
{

}
