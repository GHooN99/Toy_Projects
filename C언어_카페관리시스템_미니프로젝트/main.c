#pragma warning(disable:4996)			// ���Ȱ�� ����
#include <stdio.h>						// stdio.h ��� include
#include <string.h>						// string.h ��� include
#include <stdlib.h>						// stdlib.h ��� include
#include <Windows.h>					// windows.h ��� include (system�������)	

#define true 1						//true �� 1��
#define false 0						// false�� 0 ����

enum main_menu				//���θ޴� ������ ����
{
	EXIT = 0,				// ���� �� 0����
	MEMBER_MANAGE,			// ȸ������
	PRODUCT_MANAGE,			// ��ǰ����
	ORDER_MANAGE,			// �ֹ�����
	SALES_MANAGE			// �������
};
enum member_menu				// ȸ������ �޴� ������
{
	EXIT_MEMBER_MENU = 0,		// ���Ḧ 0����
	PRINT_MEMBER,				// ȸ�� ���
	CHANGE_NAME,				// ȸ�� �̸�����
	CHANGE_ID,					// ȸ�� ���̵� ����
	DELETE_MEMBER				// ȸ�� ����
};
enum product_menu              // ��ǰ���� �޴� ������
{
	EXIT_PRODUCT_MENU = 0,		// ���Ḧ 0����
	PRINT_PRODUCT,				// ��ǰ ���
	ADD_PRODUCT,				// ��ǰ �߰�
	CHANGE_PRICE,				// ��ǰ ���� ����
	DELETE_PRODUCT				// ��ǰ ����
};
enum sales_menu              // ������� �޴� ������
{
	EXIT_SALES_MENU =0,      //���Ḧ 0���� 
	PRINT_ALL,					// �Ѹ��� ���
	PRINT_BY_PRODUCT				// ��ǰ�� ���� ���
};

typedef int bool;     //bool�� �ڷ��� �����
typedef int Index;    // Index�� �ڷ��� �����


/* ---------------------------- */
/*  ȸ�� ��ǰ ������ ����ü ���� */
/* ---------------------------- */


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
void keyPressDelay();														// Ű �Է� ��� �Լ�
void printInputError();														// �Է� ���� ��� �Լ�
void printMainWindow();														// ���� ȭ�� ��� �Լ�
void printSelectMenu();														// �޴� ���� ��� �Լ�
void MemberManageMenu(memberList *list);									// ȸ�� ���� �޴�
void ProductManageMenu(productList *list);									// ��ǰ ���� �޴�
void OrderManageMenu(productList *pro_list, memberList *mem_list);			// �ֹ� ���� �޴�
void SalesManageMenu(productList *list);									// ���� ���� �޴� 

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
void changePointOfMember(memberList *list,int point);		// ȸ�� ���� �Լ�

/* ��ǰ ������ ���� �Լ� ��� */
Index findIndexOfProduct(const productList *list, const char name[]);	//�̸����� ��ǰ ã�� �Լ�
void addProduct(productList *list);			// ��ǰ �߰� �Լ�
void deleteProduct(productList *list);		// ��ǰ ���� �Լ�
void changeProductPrice(productList *list); // ��ǰ ���� ���� �Լ�
void printAllProduct(productList *list);    // ��� ��ǰ ��� �Լ�

/* �ֹ� ������ ���� �Լ� ��� */

void orderProduct(productList *prodictlist,  memberList *memberlist);	// ��ǰ �ֹ� �Լ�

/* ���� ������ ���� �Լ� ��� */

void printAllSales(productList *list);		// �� ���� ��� �Լ� 
void printSalesByProduct( productList *list);					// ��ǰ �� ���� ��� �Լ�


/* -------- */
/* ���� �Լ� */
/* -------- */

#define DEBUG_IF

int main()			//�����Լ� ���� 
{

#ifdef DEBUG_IF

	/* ��� ���� ������ ���� */
	memberList member_list;			//�������Ʈ ����
	productList product_list;		// ��ǰ ����Ʈ ����

	member mdata1 = { "Kim","01012345678",1000 };
	member mdata2 = { "Lee","01099999999",2000 };
	member mdata3 = { "Park","01000000000",500 };
	member mdata4 = { "Choi","01011112222",0 };
	member mdata5 = { "Kang","01055556666",200 };
	initializeMemberList(&member_list);				//����Ʈ �ʱ�ȭ
	addDataToMemberList(&member_list, 1, mdata1);   // ������ 1,2,3,4,5 ����
	addDataToMemberList(&member_list, 2, mdata2);
	addDataToMemberList(&member_list, 3, mdata3);
	addDataToMemberList(&member_list, 4, mdata4);
	addDataToMemberList(&member_list, 5, mdata5);
	/* ��� ���� ������ ���� �� */

	/* ��ǰ ���� ������ ����*/
	product pdata1 = { "Coffee",3500,1 };
	product pdata2 = { "Cake",5000,2 };
	product pdata3 = { "Milk",1000,0 };
	product pdata4 = { "Water",500,4 };
	product pdata5 = { "Juice",1500,3 };
	initializeProductList(&product_list);		//����Ʈ �ʱ�ȭ 
	addDataToProductList(&product_list, 1, pdata1);		//������ 1,2,3,4,5 ����
	addDataToProductList(&product_list, 2, pdata2);
	addDataToProductList(&product_list, 3, pdata3);
	addDataToProductList(&product_list, 4, pdata4);
	addDataToProductList(&product_list, 5, pdata5);
	/* ��ǰ ���� ������ ���� �� */

	enum main_menu menu;			//������ ���� 

	printMainWindow(); // ���� ������ ���� 

	while (true)		//���� ����
	{
		printSelectMenu(); // �޴� ���� 

		scanf("%d",(int*)&menu);   //�޴� ��ȣ �Է�
		system("cls");			// �ܼ� ȭ�� �ʱ�ȭ

		switch (menu)				//�޴����� �б�
		{
			case MEMBER_MANAGE:				//1�� ȸ������
				MemberManageMenu(&member_list);   // ȸ������ �Լ� ȣ�� 
				break;
			case PRODUCT_MANAGE:                 // 2�� ��ǰ����
				ProductManageMenu(&product_list);   // ��ǰ���� �Լ� ȣ�� 
				break;
			case ORDER_MANAGE:             // 3�� �ֹ�����
				OrderManageMenu(&product_list, &member_list);     //�ֹ����� �Լ� ȣ�� 
				break;
			case SALES_MANAGE:                //4�� �������
				SalesManageMenu(&product_list);    //���� ���� �Լ� ȣ�� 
				break;

			case EXIT:                        //0 �� ���α׷� ����
				terminateMemberList(&member_list);	// ����Ʈ ����
				terminateProductList(&product_list); // ����Ʈ ����
				return 0;  //���α׷� ����

			default:										// ����ó��
				printInputError();							// ���� �޽��� ���
				break;
		}
	}
#endif
}


/* --------- */
/* �Լ� ���� */
/* --------- */

/* ----------------------- */
/* ���Ḯ��Ʈ ���� �Լ� ��� */
/* ----------------------- */


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

void keyPressDelay()			//Ű �Է� ��� �Լ�
{
	system("pause");			// �ƹ�Ű�� �Է� ���
	system("cls");				// �ܼ�â �ʱ�ȭ
}
void printInputError()			//���� �޽��� ��� �Լ�
{
	printf("�߸��� �Է��Դϴ�.\n");			// ���� �޽��� ��� 
	keyPressDelay();						// Ű �Է� ���
}
void printMainWindow()										//���� ȭ�� ��� �Լ�
{
	printf("___________________**************___________________\n");   // ���� ȭ�� ��� 
	printf("___________________ī����� �ý���___________________\n");
	printf("___________________**************___________________\n");
	printf("\n");
	keyPressDelay();			//Ű �Է� ���
}
void printSelectMenu()			//�޴� ���� �Լ�
{
	printf("(1)ȸ������ (2)��ǰ���� (3)�ֹ����� (4)������� (0)����\n");    //�޴� ��� 
	printf("�޴��� �������ּ��� : ");
}
void MemberManageMenu(memberList *list)             //ȸ�� ���� �Լ�
{
	enum member_menu menu;           //������ �޴� ����

	while (true)           //���ѷ���
	{
		printf("(1)ȸ����ȸ (2)ȸ���̸����� (3)ȸ�����̵𺯰� (4)ȸ������ (0)ó������\n");    // �޴� ��� 
		printf("�޴��� �������ּ��� : ");
		scanf("%d", (int*)&menu);         // �޴� �Է� 
		system("cls");            // �ܼ�â �ʱ�ȭ
		switch (menu)     // �޴� ����
		{
			case PRINT_MEMBER:          //1�� ȸ�� ��� 
				printAllMember(list);    //ȸ�� ��� �Լ� ȣ��
				break;
			case CHANGE_NAME:		//2�� ȸ�� �̸� ����
				changeMemberName(list);   // ȸ�� �̸� ���� �Լ� ȣ��
				break;
			case CHANGE_ID:				//3�� ȸ�� ���̵� ���� 
				changeMemberID(list);     //ȸ�� ���̵� ���� �Լ� ȣ��
				break;
			case DELETE_MEMBER:         //4�� ȸ�� ���� 
				deleteMember(list);     //ȸ�� ���� �Լ� ȣ�� 
				break;
			case EXIT_MEMBER_MENU:       // 0�� �޴� ����
				system("cls");           // �ܼ� �ʱ�ȭ
				return;                //�Լ� ����
			default:							//����
				printInputError();       // �Է� ���� ��� 
				break;
		}
	}
}
void ProductManageMenu(productList *list)      // ��ǰ ���� �޴� �Լ�
{
	enum product_menu menu;        // ��ǰ �޴� ������ ����
	while (true)  // ���ѷ���
	{
		printf("(1)��ǰ��ȸ (2)��ǰ�߰� (3)��ǰ���ݺ��� (4)��ǰ���� (0)ó������\n");    //�޴� ���
		printf("�޴��� �������ּ��� : ");
		scanf("%d", (int*)&menu);   //�޴� �Է�
		system("cls");   //�ܼ� �ʱ�ȭ

		switch (menu)   //�޴� ����
		{
			case PRINT_PRODUCT:			//1�� ��ǰ ���
				printAllProduct(list);  //��ǰ����Լ� ȣ��
				break;
			case ADD_PRODUCT:		//2�� ��ǰ �߰�
				addProduct(list);		//��ǰ �߰� �Լ� ȣ��
				break;
			case CHANGE_PRICE:			//3�� ��ǰ ���� ����
				changeProductPrice(list);	//��ǰ ���� ���� �Լ� ȣ��
				break;
			case DELETE_PRODUCT:		//4�� ��ǰ ���� 
				deleteProduct(list);  //��ǰ �����Լ� ȣ��
				break;
			case EXIT_PRODUCT_MENU:		//0�� ����
				system("cls");        //�ܼ�â �ʱ�ȭ
				return;             // �Լ�����
			default:			//����
				printInputError();     // �����޽��� ���   
				break;
		}
	}
}
void OrderManageMenu(productList *pro_list,memberList *mem_list)        //�ֹ����� �Լ� 
{
	orderProduct(pro_list, mem_list);       // �ֹ����� �Լ� ȣ�� 
}
void SalesManageMenu(productList *list)         //���� ���� �Լ�
{
	enum sales_menu menu;        // ������� ������ ����

	while (true)	//���ѷ���
	{
		printf("(1)�� ���� (2)��ǰ�� ���� ��ȸ (0)ó������\n");        // �޴�����â ��� 
		printf("�޴��� �������ּ��� : ");
		scanf("%d", (int*)&menu);       // �޴� �Է�
		system("cls");   //�ܼ� �ʱ�ȭ
		switch (menu)   //�޴� ����
		{
			case PRINT_ALL:         //1�� �Ѹ��� ��� 
				printAllSales(list);  // �Ѹ��� ��� �Լ� ȣ��
				break;
			case PRINT_BY_PRODUCT:       //2�� ��ǰ�� ���� ���
				printSalesByProduct(list);      // ��ǰ�� ���� �Լ� ��� 
				break;
 			case EXIT_SALES_MENU:			// 0�� ����
				system("cls");            //�ܼ�â �ʱ�ȭ
				return;				// �Լ�����
			default:				//����
				printInputError();			//�Է� �����޽��� ��� 
				break;
		}
	}
}

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
	printMemberList(list);       // ȸ�����
	keyPressDelay();       // Ű�Է� ���
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

	keyPressDelay();            // Ű�Է� ���
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
		keyPressDelay();
		return;
	}

	setCurrentMemberNode(list, find_name_idx);

	printf("�̸��� ã�ҽ��ϴ�!\n");
	printf("ȸ�� ����\n%s %s %d\n", list->crnt->data.name, list->crnt->data.id, list->crnt->data.point);		// ã�� ȸ�� �������

	printf("�ٲ� �̸��� �Է����ּ���. (����10�� �̳�) :");				// �̸� �Է� �ȳ�
	scanf("%s", new_name);											// �� �̸� �Է� 

	strcpy(list->crnt->data.name, new_name);					// ���̸��� �����̸��� �����

	printf("���� �Ϸ� !!\n");									// �Ϸ� �޽��� ��� 

	keyPressDelay();

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
		keyPressDelay();
		return;														// �Լ� ������ ����
	}

	setCurrentMemberNode(list, find_id_idx);

	printf("���̵��� ã�ҽ��ϴ�!\n");
	printf("ȸ�� ����\n%s %s %d\n", list->crnt->data.name, list->crnt->data.id, list->crnt->data.point);		// ã�� ȸ�� �������

	printf("�ٲ� ���̵��� �Է����ּ���. (ex.01012345678) :");				// �̸� �Է� �ȳ�
	scanf("%s", new_id);											// �� �̸� �Է� 

	strcpy(list->crnt->data.id, new_id);					// ���̸��� �����̸��� �����

	printf("���� �Ϸ� !!\n");									// �Ϸ� �޽��� ��� 

	keyPressDelay();
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

		keyPressDelay();
		return;														// �Լ� ������ ����
	}

	setCurrentMemberNode(list, find_name_idx);

	printf("���̵��� ã�ҽ��ϴ�!\n");
	printf("ȸ�� ����\n%s %s %d\n", list->crnt->data.name, list->crnt->data.id, list->crnt->data.point);		// ã�� ȸ�� �������
	printf("�����Ͻðڽ��ϱ�? [Y:N] :");
	getchar();
	scanf("%c", &del_mem);

	if (del_mem == 'N' || del_mem == 'n')
	{
		printf("������ ����ϼ̽��ϴ�.\n");
		keyPressDelay();
		return;
	}

	deleteDataFromMemberList(list, find_name_idx);

	printf("���� �Ϸ�!!\n");

	keyPressDelay();
}
void changePointOfMember(memberList *list,int point)		// ȸ�� ���� �Լ�
{
	Index find_name_idx;			// �ΉH�� , �̸� ���� ����
	char find_name[11],regi;

	printf("ȸ�� �̸��� �Է����ּ���. (����10�� �̳�) :");				// �̸� �Է� �ȳ�
	scanf("%s", find_name);										// �̸� �Է�

	find_name_idx = findIndexOfMemberByName(list, find_name);      // �̸� ã�Ƽ� �ε��� ��ȯ

	if (find_name_idx == -1)										// �̸��� ������ ó��
	{
		printf("�̸��� ã�� ���Ͽ����ϴ�.\n");						// ���� �޽��� ���
		printf("ȸ�� ������ �Ͻðڽ��ϱ�?[Y:N] :");
		getchar();
		scanf("%c", &regi);              // �Է� 

		if (regi == 'N' || regi == 'n')       // n �Է½�
		{
			printf("ȸ�� ������ ����ϼ̽��ϴ�.\n");   // �������
			keyPressDelay();					//Ű�Է´��
			return;								//�Լ�����
		}
		registerMember(list);          //ȸ�� ���� �Լ� ȣ�� 
		return;						//�Լ� ����
	}


	setCurrentMemberNode(list, find_name_idx);      //���� ���ó�带 ã�� �ε����� 

	printf("�̸��� ã�ҽ��ϴ�!\n");										//�̸� ã�� ���� �޽��� ��� 
	printf("%d ����Ʈ�� �����Ǿ����ϴ�.\n\n", point);									// ����Ʈ ����
	list->crnt->data.point += point;
	printf("ȸ�� ����\n%s %s %d\n\n", list->crnt->data.name, list->crnt->data.id, list->crnt->data.point);   //���� ȸ�� �������
	keyPressDelay();    // Ű�Է� ���
}

/* ��ǰ ������ ���� �Լ� ��� */

Index findIndexOfProduct(const productList *list, const char name[])	//�̸����� ��ǰ ã�� �Լ�
{
	productNode *ptr = list->head->next;												// ptr�� �� ó�� �� ���� ����
	Index i = 1;																	// i�� 1����
	if (!isEmptyProductList(list))																// �� ����Ʈ�� �ƴϸ� ����
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
void addProduct(productList *list)			// ��ǰ �߰� �Լ�
{
	char product_name[21] = { "\0" };
	int product_price = 0;

	printf("��ǰ�߰�\n");				// ��ǰ �߰� �޴� ��� 

	printf("�߰��� ��ǰ�� �̸��� �Է����ּ���. (������ 20���̳�) :");       // ��ǰ�߰� �ȳ� �޽���
	scanf("%s", product_name);								//�߰��� ��ǰ�̸� �Է�
	printf("�߰��� ��ǰ�� ������ �Է����ּ���.(��) :");
	scanf("%d", &product_price);											// �߰��� ��ǰ ���� �Է� 

	product new_product = { "tmp",product_price,0 };               // ���ο� ��ǰ ���� �ʱ�ȭ
	strcpy(new_product.name, product_name);                  // ���ο� ��ǰ ������ ���ο� ��ǰ�̸� ����
	
	addDataToProductList(list, 1, new_product);            //����Ʈ�� ������ �߰�
	printf("�߰� �Ϸ� !!\n");											// �߰� �Ϸ� �޽���
	keyPressDelay();												// Ű �Է� ���
}
void deleteProduct(productList *list)		// ��ǰ ���� �Լ�
{
	char product_name[21] = { "\0" };			// ��ǰ �̸� ����
	char del_product;							
	Index find_product_idx;

	printf("��ǰ ����\n");				//��ǰ ���� �޽���

	printf("���� ��ǰ�� �̸��� �Է����ּ���. (������ 20���̳�) :");
	scanf("%s", product_name);			//������ ��ǰ�̸� �Է�
	find_product_idx = findIndexOfProduct(list, product_name);			// ������ ��ǰ �̸� �ε��� ã��

	if (find_product_idx == -1)			//ã�����ϸ�
	{
		printf("��ǰ�� ã�� ���Ͽ����ϴ�.\n");   //�����޽��� ���
		keyPressDelay();		// Ű�Է� ���
		return;				//�Լ� ����
	}
	setCurrentProductNode(list, find_product_idx);				// ���� ��带 ã�� �ε����� ���� 
	printf("��ǰ�� ã�ҽ��ϴ�!\n");					// ��ǰ ã�� ���� �޽��� ��� 
	printf("��ǰ ����\n%s %d %d\n", list->crnt->data.name, list->crnt->data.price, list->crnt->data.sellCnt);		// ã�� ��ǰ �������
	

	printf("�����Ͻðڽ��ϱ�? [Y:N] :");        // ��ǰ ���� ���� 
	getchar();
	scanf("%c", &del_product);          // �Է� 

	if (del_product == 'N' || del_product == 'n')   //n �Ͻ� ���� ��� 
	{
		printf("������ ����ϼ̽��ϴ�.\n");
		keyPressDelay();
		return;
	}
	// �̿ܿ��� ��ǰ ���� 
	deleteDataFromProductList(list, find_product_idx);   // ����Ʈ���� ��ǰ ����

	printf("���� �Ϸ� !!\n");  //��ǰ ���� �޽��� ��� 
	keyPressDelay();	// Ű�Է´��

}
void changeProductPrice(productList *list) // ��ǰ ���� ���� �Լ�
{
	char product_name[21] = { "\0" };		// �̸� �ʱ�ȭ
	int new_price = 0;								// ���ο� ����
	char change_product;
	Index find_product_idx;

	printf("��ǰ ���� ����\n");				//��ǰ ���� ���� �޴� ��� 

	printf("������ ������ ��ǰ�� �̸��� �Է����ּ���. (������ 20���̳�) :");
	scanf("%s", product_name);											//�̸� �Է� 
	find_product_idx = findIndexOfProduct(list, product_name);      // �̸� ã�Ƽ� �ε��� ��ȯ 

	if (find_product_idx == -1)				// ã�����ϸ� 
	{
		printf("��ǰ�� ã�� ���Ͽ����ϴ�.\n");   //��� 
		keyPressDelay(); //Ű �Է� ���
		return; //�Լ� ����
	}

	setCurrentProductNode(list, find_product_idx);						// ���� ���ó�带 ã�� �ε�����
	printf("��ǰ�� ã�ҽ��ϴ�!\n");   //��ǰ ���� ��� 
	printf("��ǰ ����\n%s %d %d\n", list->crnt->data.name, list->crnt->data.price, list->crnt->data.sellCnt);		// ã�� ��ǰ �������
	printf("���� �Ͻðڽ��ϱ�? [Y:N] :");   // ���� ���� 
	getchar();
	scanf("%c", &change_product);   //�Է� 

	if (change_product == 'N' || change_product == 'n')   //n �̸� ���� ���
	{
		printf("������ ����ϼ̽��ϴ�.\n");   //������� �޽���
		keyPressDelay();		//Ű�Է´��
		return;			//�Լ�����
	}

	printf("���ο� ������ �Է����ּ���.(��) :");        // ���ο� �����Է�
	scanf("%d", &new_price);

	list->crnt->data.price = new_price;         // ���ο� ���� ������Ʈ

	printf("���� �Ϸ� !!\n");           // ����Ϸ� �޽���

	keyPressDelay();			//Ű �Է´�� 
}
void printAllProduct(productList *list)    // ��� ��ǰ ��� �Լ�
{
	printProductList(list);       // ��ǰ ��� �Լ� ȣ��
	keyPressDelay(); // Ű �Է� ���
}

/* �ֹ� ������ ���� �Լ� ��� */

void orderProduct(productList *pro_list, memberList *mem_list)	// ��ǰ �ֹ� �Լ�
{
	Index idx;       // �ε��� 
	int k;     // ��ǰ ����
	char order, checkpoint;      // n �Է� Ȯ�� 
	while (true)				// ���ѷ���
	{
		printProductList(pro_list);         // ��ǰ ����Ʈ ��� 
		printf("������ �ֹ��Ͻðڽ��ϱ�? (0)ó������\n");   // �ֹ� �޴� ��� 
		printf("(���������� 1��) �޴��� �������ּ��� : ");
		scanf("%d", &idx);           // �޴� �Է�
		system("cls");            // �ܼ�â �ʱ�ȭ
		if (idx == 0)        // 0���� ���� 
			return;
		if (idx > sizeOfProductList(pro_list))        //����ó�� 
		{
			printInputError();						// �����޽��� ��� 
			continue;					// ��� 
		}

		setCurrentProductNode(pro_list, idx);				//���� ���� ��带 �Է��� �ε�����
		product buy_product;											// ���ο� ������ 
		buy_product = getDataFromProductList(pro_list, idx);      //��ǰ �����͸� �޾ƿ´�.

		printf("��ǰ����\n");           //��ǰ���� ��� 
		printf("%s %d��\n", buy_product.name, buy_product.price);

		printf("��� �ֹ��Ͻðڽ��ϱ�? :");       // �ֹ� ����
		scanf("%d", &k);							//�ֹ� �����Է�
		system("cls");			// �ܼ�â �ʱ�ȭ
		// ���� ��� 
		printf("%s %d���� �ֹ� �ϼ̽��ϴ�. ������ %d �Դϴ�.\n", buy_product.name, k, k*buy_product.price);
		printf("�ֹ��Ͻðڽ��ϱ�? [Y:N] :");   //�ֹ� ����
		getchar();
		scanf("%c", &order);

		if (order == 'N' || order == 'n')   //N�Է½� �ֹ����
		{
			printf("�ֹ��� ����ϼ̽��ϴ�.\n");  //�޽��� ���
			keyPressDelay();   //Ű�Է´��
			continue;    //�Լ� ��ó������ 
		}

		pro_list->crnt->data.sellCnt += k;     //�Ǹ� ī��Ʈ ����
		printf("�ֹ� �Ϸ�!!\n");        // �ֹ��Ϸ� �޽������ 

		printf("���� ����Ʈ�� %d����Ʈ �Դϴ�.", (int)(k*buy_product.price*0.05));      //����Ʈ����
		printf("�����Ͻðڽ��ϱ�? [Y:N] :");   //����Ʈ ���� ����
		getchar();
		scanf("%c", &checkpoint);      // ����Ʈ ���� ���� �Է�
		system("cls");   //�ܼ� �ʱ�ȭ
		if (checkpoint == 'N' || checkpoint == 'n') //n�̸� �������
		{
			printf("������ ����ϼ̽��ϴ�.\n");     // ������� �޽���
			keyPressDelay();   // Ű �Է� ���
			continue;   // �Լ� ó������ 
		}

		changePointOfMember(mem_list, (int)(k*buy_product.price*0.05));  // ����Ʈ ���� �Լ� ȣ�� 
	}
}

/* ���� ������ ���� �Լ� ��� */

void printAllSales(productList *list)		// �� ���� ��� �Լ�
{
	int all_sales = 0;		//�Ѹ��� ���� �ʱ�ȭ
	productNode *ptr = list->head->next;												// ptr�� �� ó�� �� ���� ����
	if (!isEmptyProductList(list))																// �� ����Ʈ�� �ƴϸ� ���
	{
		while (ptr->next != NULL)													// ����Ʈ ������ Ž��
		{
			all_sales += (ptr->data.price)*(ptr->data.sellCnt);
			ptr = ptr->next;														// ptr�� ���� ����		/*TODO ������ ��� ���� �ٲ����*/
		}
	}
	printf("�� ������ %d �� �Դϴ�.\n",all_sales);		// ���� ��� 
	keyPressDelay();		// Ű�Է� ���
}
void printSalesByProduct(productList *list)					// ��ǰ �� ���� ��� �Լ�
{
	productNode *ptr = list->head->next;												// ptr�� �� ó�� �� ���� ����
	if (!isEmptyProductList(list))																// �� ����Ʈ�� �ƴϸ� ���
	{
		while (ptr->next != NULL)													// ����Ʈ ������ Ž��
		{
			printf("��ǰ �̸� : %s ���� : %d��\n", ptr->data.name, (ptr->data.price) *(ptr->data.sellCnt));												// ������ ���
			ptr = ptr->next;														// ptr�� ���� ����		/*TODO ������ ��� ���� �ٲ����*/
		}
		printf("\n");
	}
	keyPressDelay();		// Ű �Է� ���
}
