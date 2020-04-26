#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

#define true 1
#define false 0

enum main_menu
{
	EXIT = 0,
	MEMBER_MANAGE,
	PRODUCT_MANAGE,
	ORDER_MANAGE,
	SALES_MANAGE
};
enum member_menu
{
	EXIT_MEMBER_MENU = 0,
	PRINT_MEMBER,
	CHANGE_NAME,
	CHANGE_ID,
	DELETE_MEMBER
};
enum product_menu
{
	EXIT_PRODUCT_MENU = 0,
	PRINT_PRODUCT,
	ADD_PRODUCT,
	CHANGE_PRICE,
	DELETE_PRODUCT
};
enum sales_menu
{
	EXIT_SALES_MENU =0,
	PRINT_ALL,
	PRINT_BY_PRODUCT
};

typedef int bool;
typedef int Index;


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
void keyPressDelay();
void printInputError();
void printMainWindow();
void printSelectMenu();
void MemberManageMenu(memberList *list);
void ProductManageMenu(productList *list);
void OrderManageMenu(productList *pro_list, memberList *mem_list);
void SalesManageMenu(productList *list);

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

int main()
{

#ifdef DEBUG_IF

	/* ��� ���� ������ ���� */
	memberList member_list;
	productList product_list;

	member mdata1 = { "Kim","01012345678",1000 };
	member mdata2 = { "Lee","01099999999",2000 };

	initializeMemberList(&member_list);
	addDataToMemberList(&member_list, 1, mdata1);
	addDataToMemberList(&member_list, 2, mdata2);

	/* ��� ���� ������ ���� �� */
	/* ��ǰ ���� ������ ����*/

	product pdata1 = { "Coffee",4000,0 };
	product pdata2 = { "Cake",2000,2 };

	initializeProductList(&product_list);
	addDataToProductList(&product_list, 1, pdata1);
	addDataToProductList(&product_list, 2, pdata2);
	
	enum main_menu menu;

	printMainWindow(); // ���� ������ ���� 

	while (true)
	{
		printSelectMenu(); // �޴� ���� 

		scanf("%d",(int*)&menu);
		system("cls");

		switch (menu)
		{
			case MEMBER_MANAGE:
				MemberManageMenu(&member_list);
				break;
			case PRODUCT_MANAGE:
				ProductManageMenu(&product_list);
				break;
			case ORDER_MANAGE:
				OrderManageMenu(&product_list, &member_list);
				break;
			case SALES_MANAGE:
				SalesManageMenu(&product_list);
				break;

			case EXIT:
				terminateMemberList(&member_list);
				terminateProductList(&product_list);
				return 0;

			default:
				printInputError();
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

void keyPressDelay()
{
	system("pause");
	system("cls");
}
void printInputError()
{
	printf("�߸��� �Է��Դϴ�.\n");
	keyPressDelay();
}
void printMainWindow()
{
	printf("___________________**************___________________\n");
	printf("___________________ī����� �ý���___________________\n");
	printf("___________________**************___________________\n");
	keyPressDelay();
}
void printSelectMenu()
{
	printf("(1)ȸ������ (2)��ǰ���� (3)�ֹ����� (4)������� (0)����\n");
	printf("�޴��� �������ּ��� : ");
}
void MemberManageMenu(memberList *list)
{
	enum member_menu menu;

	while (true)
	{
		printf("(1)ȸ����ȸ (2)ȸ���̸����� (3)ȸ�����̵𺯰� (4)ȸ������ (0)ó������\n");
		printf("�޴��� �������ּ��� : ");
		scanf("%d", (int*)&menu);
		system("cls");
		switch (menu)
		{
			case PRINT_MEMBER:
				printAllMember(list);
				break;
			case CHANGE_NAME:
				changeMemberName(list);
				break;
			case CHANGE_ID:
				changeMemberID(list);
				break;
			case DELETE_MEMBER:
				deleteMember(list);
				break;
			case EXIT_MEMBER_MENU:
				system("cls");
				return;
			default:
				printInputError();
				break;
		}
	}
}
void ProductManageMenu(productList *list)
{
	enum product_menu menu;
	while (true)
	{
		printf("(1)��ǰ��ȸ (2)��ǰ�߰� (3)��ǰ���ݺ��� (4)��ǰ���� (0)ó������\n");
		printf("�޴��� �������ּ��� : ");
		scanf("%d", (int*)&menu);
		system("cls");

		switch (menu)
		{
			case PRINT_PRODUCT:
				printAllProduct(list);
				break;
			case ADD_PRODUCT:
				addProduct(list);
				break;
			case CHANGE_PRICE:
				changeProductPrice(list);
				break;
			case DELETE_PRODUCT:
				deleteProduct(list);
				break;
			case EXIT_PRODUCT_MENU:
				system("cls");
				return;
			default:
				printInputError();
				break;
		}
	}
}
void OrderManageMenu(productList *pro_list,memberList *mem_list)
{
	orderProduct(pro_list, mem_list);
}
void SalesManageMenu(productList *list)
{
	enum sales_menu menu;

	while (true)
	{
		printf("(1)�� ���� (2)��ǰ�� ���� ��ȸ (0)ó������\n");
		scanf("%d", (int*)&menu);
		system("cls");
		switch (menu)
		{
			case PRINT_ALL:
				printAllSales(list);
				break;
			case PRINT_BY_PRODUCT:
				printSalesByProduct(list);
				break;
			case EXIT_SALES_MENU:
				system("cls");
				return;
			default:
				printInputError();
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
	printMemberList(list);
	keyPressDelay();
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

	keyPressDelay();
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

		keyPressDelay();
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
	Index find_name_idx;
	char find_name[11],regi;

	printf("ȸ�� �̸��� �Է����ּ���. (����10�� �̳�) :");				// �̸� �Է� �ȳ�
	scanf("%s", find_name);										// �̸� �Է�

	find_name_idx = findIndexOfMemberByName(list, find_name);

	if (find_name_idx == -1)										// �̸��� ������ ó��
	{
		printf("�̸��� ã�� ���Ͽ����ϴ�.\n");						// ���� �޽��� ���
		printf("ȸ�� ������ �Ͻðڽ��ϱ�?[Y:N] :");
		getchar();
		scanf("%c", &regi);

		if (regi == 'N' || regi == 'n')
		{
			printf("ȸ�� ������ ����ϼ̽��ϴ�.\n");
			keyPressDelay();
			return;
		}
		registerMember(list);
		return;
	}


	setCurrentMemberNode(list, find_name_idx);

	printf("�̸��� ã�ҽ��ϴ�!\n");
	printf("%d ����Ʈ�� �����Ǿ����ϴ�.\n", point);
	list->crnt->data.point += point;
	printf("ȸ�� ����\n%s %s %d\n", list->crnt->data.name, list->crnt->data.id, list->crnt->data.point);
	keyPressDelay();
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

	printf("��ǰ�߰�\n");				//TODO ���� �������̽� �����

	printf("�߰��� ��ǰ�� �̸��� �Է����ּ���. (������ 20���̳�) :");
	scanf("%s", product_name);
	printf("�߰��� ��ǰ�� ������ �Է����ּ���.(��) :");
	scanf("%d", &product_price);

	product new_product = { "tmp",product_price,0 };
	strcpy(new_product.name, product_name);
	
	addDataToProductList(list, 1, new_product);
	printf("�߰� �Ϸ� !!\n");
	keyPressDelay();
}
void deleteProduct(productList *list)		// ��ǰ ���� �Լ�
{
	char product_name[21] = { "\0" };
	int product_price = 0;
	char del_product;
	Index find_product_idx;

	printf("��ǰ ����\n");				//TODO ���� �������̽� �����

	printf("���� ��ǰ�� �̸��� �Է����ּ���. (������ 20���̳�) :");
	scanf("%s", product_name);
	find_product_idx = findIndexOfProduct(list, product_name);

	if (find_product_idx == -1)
	{
		printf("��ǰ�� ã�� ���Ͽ����ϴ�.\n");
		keyPressDelay();
		return;
	}
	setCurrentProductNode(list, find_product_idx);
	printf("��ǰ�� ã�ҽ��ϴ�!\n");
	printf("��ǰ ����\n%s %d %d\n", list->crnt->data.name, list->crnt->data.price, list->crnt->data.sellCnt);		// ã�� ��ǰ �������
	

	printf("�����Ͻðڽ��ϱ�? [Y:N] :");
	getchar();
	scanf("%c", &del_product);

	if (del_product == 'N' || del_product == 'n')
	{
		printf("������ ����ϼ̽��ϴ�.\n");
		keyPressDelay();
		return;
	}

	deleteDataFromProductList(list, find_product_idx);

	printf("���� �Ϸ� !!\n");
	keyPressDelay();

}
void changeProductPrice(productList *list) // ��ǰ ���� ���� �Լ�
{
	char product_name[21] = { "\0" };
	int new_price = 0;
	char change_product;
	Index find_product_idx;

	printf("��ǰ ���� ����\n");				//TODO ���� �������̽� �����

	printf("������ ������ ��ǰ�� �̸��� �Է����ּ���. (������ 20���̳�) :");
	scanf("%s", product_name);
	find_product_idx = findIndexOfProduct(list, product_name);

	if (find_product_idx == -1)
	{
		printf("��ǰ�� ã�� ���Ͽ����ϴ�.\n");
		keyPressDelay();
		return;
	}

	setCurrentProductNode(list, find_product_idx);
	printf("��ǰ�� ã�ҽ��ϴ�!\n");
	printf("��ǰ ����\n%s %d %d\n", list->crnt->data.name, list->crnt->data.price, list->crnt->data.sellCnt);		// ã�� ��ǰ �������
	printf("���� �Ͻðڽ��ϱ�? [Y:N] :");
	getchar();
	scanf("%c", &change_product);

	if (change_product == 'N' || change_product == 'n')
	{
		printf("������ ����ϼ̽��ϴ�.\n");
		keyPressDelay();
		return;
	}

	printf("���ο� ������ �Է����ּ���.(��) :");
	scanf("%d", &new_price);

	list->crnt->data.price = new_price;

	printf("���� �Ϸ� !!\n");

	keyPressDelay();
}
void printAllProduct(productList *list)    // ��� ��ǰ ��� �Լ�
{
	printProductList(list);
	keyPressDelay();
}

/* �ֹ� ������ ���� �Լ� ��� */

void orderProduct(productList *pro_list, memberList *mem_list)	// ��ǰ �ֹ� �Լ�
{
	Index idx;
	int k;
	char order, checkpoint;
	while (true)
	{
		printProductList(pro_list);
		printf("������ �ֹ��Ͻðڽ��ϱ�? (0)ó������\n");
		printf("(���������� 1��) �޴��� �������ּ��� : ");
		scanf("%d", &idx);
		system("cls");
		if (idx == 0)
			return;
		if (idx > sizeOfProductList(pro_list))
		{
			printf("�߸��� �Է��Դϴ�.\n");
			keyPressDelay();
			continue;
		}

		setCurrentProductNode(pro_list, idx);
		product buy_product;
		buy_product = getDataFromProductList(pro_list, idx);

		printf("��ǰ����\n");
		printf("%s %d��\n", buy_product.name, buy_product.price);

		printf("��� �ֹ��Ͻðڽ��ϱ�? :");
		scanf("%d", &k);
		system("cls");

		printf("%s %d���� �ֹ� �ϼ̽��ϴ�. ������ %d �Դϴ�.\n", buy_product.name, k, k*buy_product.price);
		printf("�ֹ��Ͻðڽ��ϱ�? [Y:N] :");
		getchar();
		scanf("%c", &order);

		if (order == 'N' || order == 'n')
		{
			printf("�ֹ��� ����ϼ̽��ϴ�.\n");
			keyPressDelay();
			continue;
		}

		pro_list->crnt->data.sellCnt += k;
		printf("�ֹ� �Ϸ�!!\n");

		printf("���� ����Ʈ�� %d����Ʈ �Դϴ�.", (int)(k*buy_product.price*0.05));
		printf("�����Ͻðڽ��ϱ�? [Y:N] :");
		getchar();
		scanf("%c", &checkpoint);
		system("cls");
		if (checkpoint == 'N' || checkpoint == 'n')
		{
			printf("������ ����ϼ̽��ϴ�.\n");
			keyPressDelay();
			continue;
		}

		changePointOfMember(mem_list, (int)(k*buy_product.price*0.05));
	}


}

/* ���� ������ ���� �Լ� ��� */

void printAllSales(productList *list)		// �� ���� ��� �Լ�
{
	int all_sales = 0;
	productNode *ptr = list->head->next;												// ptr�� �� ó�� �� ���� ����
	if (!isEmptyProductList(list))																// �� ����Ʈ�� �ƴϸ� ���
	{
		while (ptr->next != NULL)													// ����Ʈ ������ Ž��
		{
			all_sales += (ptr->data.price)*(ptr->data.sellCnt);
			ptr = ptr->next;														// ptr�� ���� ����		/*TODO ������ ��� ���� �ٲ����*/
		}
	}
	printf("�� ������ %d �� �Դϴ�.\n",all_sales);
	keyPressDelay();
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
	keyPressDelay();
}
