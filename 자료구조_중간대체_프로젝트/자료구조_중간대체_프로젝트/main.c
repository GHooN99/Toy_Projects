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
/* 매출 회원 상품 데이터 구조체 정의 */
/* ------------------------------ */


typedef struct sales	//매출 구조체 정의
{
	char date[9];		//20200413 8자리 문자열
	int todaySales;		//당일 매출
}sales;

typedef struct member	//회원 구조체 정의
{
	char name[11];		//영어 이름 최대 10자
	char id[12];		//01012345678 전화번호 최대 11자
	int point;			//적립된 포인트
}member;

typedef struct product	//상품 구조체 정의
{
	char name[21];		//상품 이름
	int price;			//상품 가격
	int sellCnt;		//상품 판매 횟수

}product;


/* ------------------------------ */
/* 연결리스트 정의를 위한 노드 설정 */
/* ------------------------------ */


typedef struct salesNode		//매출 노드 구조체 정의
{
	struct salesNode *prev;		//이전 노드의 주소
	sales data;					//매출 데이터
	struct salesNode *next;		//다음 노드의 주소
}salesNode;

typedef struct memberNode		//회원 노드 구조체 정의
{
	struct memberNode *prev;	//이전 노드의 주소
	member data;				//매출 데이터
	struct memberNode *next;	//다음 노드의 주소
}memberNode;

typedef struct productNode		//상품 노드 구조체 정의
{
	struct productNode *prev;	//이전 노드의 주소
	product data;				//상품 데이터
	struct productNode *next;	//다음 노드의 주소
}productNode;


/* ---------------------------------- */
/* 각 데이터에 대한 이중 연결리스트 설정 */
/* ---------------------------------- */


typedef struct salesList		//매출 리스트 정의
{
	salesNode *head;			//머리 노드의 주소
	salesNode *tail;			//꼬리 노드의 주소
	salesNode *crnt;			//현재 선택된 노드의 주소
}salesList;

typedef struct memberList		//회원 리스트 정의
{
	memberNode *head;			//머리 노드의 주소
	memberNode *tail;			//꼬리 노드의 주소
	memberNode *crnt;			//현재 선택된 노드의 주소
}memberList;

typedef struct productList		//상품 리스트 정의
{
	productNode *head;			//머리 노드의 주소
	productNode *tail;			//꼬리 노드의 주소
	productNode *crnt;			//현재 선택된 노드의 주소
}productList;

/* -------------------------------------------------------------------------- */
/* C 언어는 함수 오버로딩을 지원하지 않는다고 한다.
  따라서 각 데이터들의 리스트를 따로 정의하고 대응되는 함수 또한 따로 만들기로 한다 */
/* -------------------------------------------------------------------------- */


  /* ----------------------- */
  /* 연결리스트 관련 함수 목록 */
  /* ----------------------- */


  /* salesList 에 대한 함수 목록 */

salesNode* allocSalesNode();														// 새 노드의 주소를 반환하는 함수  
void setSalesNode(salesNode *n, salesNode *prev, salesNode *next, sales data);		// 노드의 값들을 설정하는 함수
int sizeOfSalesList(const salesList *list);											// 연결 리스트의 크기를 반환하는 함수 
bool isEmptySalesList(const salesList *list);										// 연결 리스트가 비어있는지 확인 하는 함수
void setCurrentSalesNode(salesList *list, Index pos);								// 현재 선택 노드를 특정노드로 가르키게 하는 함수
void initializeSalesList(salesList *list);											// 리스트를 초기화 하는 함수
void printSalesList(const salesList *list);											// 리스트내의 데이터를 출력하는 함수
void addDataToSalesList(salesList *list, Index pos, sales data);					// 리스트의 특정 위치에 데이터를 추가하는 함수
void deleteDataFromSalesList(salesList *list, Index pos);							// 리스트내 특정 위치의 데이터를 삭제하는 함수
sales getDataFromSalesList(salesList *list, Index pos);								// 리스트내 특정 위치의 데이터를 반환하는 함수
void terminateSalesList(salesList *list);											// 리스트에 할당된 공간을 해제하고 종료하는 함수

/* memberList 에 대한 함수 목록 */

memberNode* allocMemberNode();														// 새 노드의 주소를 반환하는 함수  
void setMemberNode(memberNode *n, memberNode *prev, memberNode *next, member data);		// 노드의 값들을 설정하는 함수
int sizeOfMemberList(const memberList *list);											// 연결 리스트의 크기를 반환하는 함수 
bool isEmptyMemberList(const memberList *list);										// 연결 리스트가 비어있는지 확인 하는 함수
void setCurrentMemberNode(memberList *list, Index pos);								// 현재 선택 노드를 특정노드로 가르키게 하는 함수
void initializeMemberList(memberList *list);											// 리스트를 초기화 하는 함수
void printMemberList(const memberList *list);											// 리스트내의 데이터를 출력하는 함수
void addDataToMemberList(memberList *list, Index pos, member data);					// 리스트의 특정 위치에 데이터를 추가하는 함수
void deleteDataFromMemberList(memberList *list, Index pos);							// 리스트내 특정 위치의 데이터를 삭제하는 함수
member getDataFromMemberList(memberList *list, Index pos);								// 리스트내 특정 위치의 데이터를 반환하는 함수
void terminateMemberList(memberList *list);											// 리스트에 할당된 공간을 해제하고 종료하는 함수

/* productList 에 대한 함수 목록 */

productNode* allocProductNode();														// 새 노드의 주소를 반환하는 함수  
void setProductNode(productNode *n, productNode *prev, productNode *next, product data);		// 노드의 값들을 설정하는 함수
int sizeOfProductList(const productList *list);											// 연결 리스트의 크기를 반환하는 함수 
bool isEmptyProductList(const productList *list);										// 연결 리스트가 비어있는지 확인 하는 함수
void setCurrentProductNode(productList *list, Index pos);								// 현재 선택 노드를 특정노드로 가르키게 하는 함수
void initializeProductList(productList *list);											// 리스트를 초기화 하는 함수
void printProductList(const productList *list);											// 리스트내의 데이터를 출력하는 함수
void addDataToProductList(productList *list, Index pos, product data);					// 리스트의 특정 위치에 데이터를 추가하는 함수
void deleteDataFromProductList(productList *list, Index pos);							// 리스트내 특정 위치의 데이터를 삭제하는 함수
product getDataFromProductList(productList *list, Index pos);								// 리스트내 특정 위치의 데이터를 반환하는 함수
void terminateProductList(productList *list);											// 리스트에 할당된 공간을 해제하고 종료하는 함수


/* ------------------------ */
/* 주요 기능에 대한 함수 목록 */
/* ------------------------ */


/* 회원 관리에 대한 함수 목록 */

void printAllMember(memberList *list);		// 회원 조회 함수
void registerMember(memberList *list);		// 회원 가입 함수
void changeMemberName(memberList *list);	// 회원 이름 변경 함수
void changeMemberID(memberList *list);		// 회원 아이디 변경 함수
void deleteMember(memberList *list);		// 회원 삭제 함수
void changePointOfMember(member *list);		// 회원 적립 함수

/* 상품 관리에 대한 함수 목록 */

void addProduct(productList *list);			// 상품 추가 함수
void deleteProduct(productList *list);		// 상품 삭제 함수
void changeProductPrice(productList *list); // 상품 가격 변경 함수
void printAllProduct(productList *list);    // 모든 상품 출력 함수

/* 주문 관리에 대한 함수 목록 */

void orderProduct(productList *prodictlist, salesList *saleslist, memberList *memberlist);	// 상품 주문 함수
void cancelOrder(productList *prodictlist, salesList *saleslist, memberList *memberlist);   // 상품 주문 취소 함수

/* 매출 관리에 대한 함수 목록 */

void printAllSales(salesList *list);		// 총 매출 출력 함수
void printSalesByDates(salesList *list);    // 날짜 별 매출 출력 함수 
void printSalesByProduct(salesList *saleslist, productList *productlist);					// 상품 별 매출 출력 함수


/* -------------------------- */
/* 파일 입출력에 대한 함수 목록 */
/* -------------------------- */


void loadMemberFromFile(memberList *list);	// 회원 목록 불러오기
void saveMemberToFile(memberList *list);	// 회원 목록 저장하기

void loadProductFromFile(memberList *list); // 상품 목록 불러오기
void saveProductToFile(memberList *list);	// 상품 목록 저장하기

void loadSalesFromFile(memberList *list);	// 회원 목록 불러오기
void saveSalesToFile(memberList *list);		// 회원 목록 저장하기


/* --------------------------*/
/* 인터페이스에 대한 함수 목록 */
/* --------------------------*/


void printMainWindow();
void printSelectMenu();
void printMemberManageMenu();
void printProductManageMenu();
void printOrderManageMenu();
void printSalesManageMenu();





/* ------------------ */
/* 기타 필요 함수 목록 */
/* ------------------ */








/* -------- */
/* 메인 함수 */
/* -------- */


int main()
{
	memberList member_list;
	salesList sales_list;
	productList product_list;

	printMainWindow(); // 메인 윈도우 오픈 



	return 0;
}


salesNode* allocSalesNode()														// 새 노드의 주소를 반환하는 함수
{
	return (salesNode*)calloc(1, sizeof(salesNode));							//새로운 노드주소를 할당하여 반환
}
void setSalesNode(salesNode *n, salesNode *prev, salesNode *next, sales data)		// 노드의 값들을 설정하는 함수
{
	n->prev = prev;																	// prev 설정
	n->next = next;																	//next 설정
	n->data = data;																	// data 설정 
}
int sizeOfSalesList(const salesList *list)											// 연결 리스트의 크기를 반환하는 함수 
{
	int cnt = 0;																	// 크기 초기화
	salesNode *ptr = list->head->next;												// ptr 변수에 값이 존재하는 첫 노드 대입
	while (ptr->next != NULL)														// ptr 노드의 다음노드가 NULL 일 때 까지 반복(맨 마지막 꼬리노드)
	{
		cnt++;																		// 크기변수 증가
		ptr = ptr->next;															// ptr 을 다음 노드로
	}
	return cnt;																		// 크기 반환
}
bool isEmptySalesList(const salesList *list)										// 연결 리스트가 비어있는지 확인 하는 함수
{
	if (list->head->next == list->tail) return true;								// 머리노드의 다음노드가 꼬리 노드일때 비어있는 리스트임
	else return false;
}
void setCurrentSalesNode(salesList *list, Index pos)								// 현재 선택 노드를 특정노드로 가르키게 하는 함수
{
	if (isEmpty(list))																// 빈 리스트일때 
	{
		list->crnt = list->tail;													// 꼬리노드로 가리킴
		return;
	}
	salesNode *ptr = list->head;													// 임시 ptr 변수를 머리노드를 가리키게 함 
	for (Index i = 0; i <= pos; ptr = ptr->next, i++)								// ptr이 pos번을 가르키게 한다.
	{
		list->crnt = ptr;															// ptr을 현재 선택 노드로
	}
}
void initializeSalesList(salesList *list)											// 리스트를 초기화 하는 함수
{
	list->head = alllocNode();														// 머리 노드를 할당
	list->tail = alllocNode();														// 꼬리 노드를 할당
	setNode(list->head, NULL, list->tail, 0);										// 머리노드를 초기화
	setNode(list->tail, list->head, NULL, 0);										// 꼬리 노드를 초기화

	list->crnt = list->head;														// 현재 선택 노드 초기화
}
void printSalesList(const salesList *list)											// 리스트내의 데이터를 출력하는 함수
{
	salesNode *ptr = list->head->next;												// ptr을 맨 처음 값 노드로 설정
	if (!isEmpty(list))																// 빈 리스트가 아니면 출력
	{
		while (ptr->next != NULL)													// 리스트 끝까지 탐색
		{
			printf("%c", ptr->data);												// 데이터 출력
			ptr = ptr->next;														// ptr을 다음 노드로		/*TODO 데이터 출력 형식 바꿔야함*/
		}
		printf("\n");   
	}

}
void addDataToSalesList(salesList *list, Index pos, sales data)					// 리스트의 특정 위치에 데이터를 추가하는 함수
{
	if (!isValidPosition(list, pos - 1))										// 올바른 위치에 삽입 여부
	{
		printf("invalid position\n");											// 오류메시지 출력
		return;																	// 함수 비정상 종료
	}

	setCurrentNode(list, pos);													// 현재 선택 노드를 pos위치 노드로 설정

	salesNode *new_node = alllocNode();											// 새로운 노드를 할당
	salesNode *crnt_node = list->crnt->prev;									// 삽입될 위치의 이전 주소 저장

	crnt_node->next = new_node;													// 삽입될 위치의 다음 노드를 새노드에 연결
	list->crnt->prev = new_node;												// 삽입될 위치의 이전 노드를 새노드에 연결

	setNode(new_node, crnt_node, list->crnt, data);								// 새 노드 위치와 데이터 설정 
}
void deleteDataFromSalesList(salesList *list, Index pos)							// 리스트내 특정 위치의 데이터를 삭제하는 함수
{
	if (!isValidPosition(list, pos))												// 올바른 위치에 접근 확인 함수
	{
		printf("invalid position\n");												// 오류메시지 출력
		return;																		// 함수 비정상 종료
	}
	setCurrentNode(list, pos);														// 현재 선택 노드를 pos위치 노드로 설정

	salesNode *A = list->crnt->prev;												// 임시 지정 노드 설정
	salesNode *B = list->crnt->next;												// 임시 지정 노드 설정

	A->next = B;																	// 삭제할 노드 앞뒤를 서로 연결
	B->prev = A;																	// 삭제할 노드 앞뒤를 서로 연결

	free(list->crnt);																// 삭제할 노드 공간 할당 해제

	list->crnt = list->head;														// 현재 선택 노드를 머리노드로 

}
sales getDataFromSalesList(salesList *list, Index pos)								// 리스트내 특정 위치의 데이터를 반환하는 함수
{
	if (!isValidPosition(list, pos))												// 올바른 접근 여부 확인
	{	
		printf("invalid position\n");												// 오류 메시지 출력
		return ;																	// 함수 비정상 종료
	}

	setCurrentNode(list, pos);														// 현재 선택 노드를 pos번째 노드로

	return list->crnt->data;														// 현재 선택 노드 데이터 반환
}
void terminateSalesList(salesList *list)											// 리스트에 할당된 공간을 해제하고 종료하는 함수
{
	while (!isEmpty(list))															// 빈 리스트가 될 때 까지
	{
		deleteData(list, 1);														// 맨 앞 노드를 삭제
	}
	list->crnt = NULL;																// 현재 선택 노드를 NULL 로
	free(list->head);																// 머리 노드 할당 해제
	free(list->tail);																// 꼬리 노드 할당 해제
}

/* memberList 에 대한 함수 목록 */

memberNode* allocMemberNode()														// 새 노드의 주소를 반환하는 함수
{
	return (memberNode*)calloc(1, sizeof(memberNode));							//새로운 노드주소를 할당하여 반환
}
void setMemberNode(memberNode *n, memberNode *prev, memberNode *next, member data)		// 노드의 값들을 설정하는 함수
{
	n->prev = prev;																	// prev 설정
	n->next = next;																	//next 설정
	n->data = data;																	// data 설정 
}
int sizeOfMemberList(const memberList *list)											// 연결 리스트의 크기를 반환하는 함수 
{
	int cnt = 0;																	// 크기 초기화
	memberNode *ptr = list->head->next;												// ptr 변수에 값이 존재하는 첫 노드 대입
	while (ptr->next != NULL)														// ptr 노드의 다음노드가 NULL 일 때 까지 반복(맨 마지막 꼬리노드)
	{
		cnt++;																		// 크기변수 증가
		ptr = ptr->next;															// ptr 을 다음 노드로
	}
	return cnt;																		// 크기 반환
}
bool isEmptyMemberList(const memberList *list)										// 연결 리스트가 비어있는지 확인 하는 함수
{
	if (list->head->next == list->tail) return true;								// 머리노드의 다음노드가 꼬리 노드일때 비어있는 리스트임
	else return false;
}
void setCurrentMemberNode(memberList *list, Index pos)								// 현재 선택 노드를 특정노드로 가르키게 하는 함수
{
	if (isEmpty(list))																// 빈 리스트일때 
	{
		list->crnt = list->tail;													// 꼬리노드로 가리킴
		return;
	}
	memberNode *ptr = list->head;													// 임시 ptr 변수를 머리노드를 가리키게 함 
	for (Index i = 0; i <= pos; ptr = ptr->next, i++)								// ptr이 pos번을 가르키게 한다.
	{
		list->crnt = ptr;															// ptr을 현재 선택 노드로
	}
}
void initializeMemberList(memberList *list)											// 리스트를 초기화 하는 함수
{
	list->head = alllocNode();														// 머리 노드를 할당
	list->tail = alllocNode();														// 꼬리 노드를 할당
	setNode(list->head, NULL, list->tail, 0);										// 머리노드를 초기화
	setNode(list->tail, list->head, NULL, 0);										// 꼬리 노드를 초기화

	list->crnt = list->head;														// 현재 선택 노드 초기화
}
void printMemberList(const memberList *list)											// 리스트내의 데이터를 출력하는 함수
{
	memberNode *ptr = list->head->next;												// ptr을 맨 처음 값 노드로 설정
	if (!isEmpty(list))																// 빈 리스트가 아니면 출력
	{
		while (ptr->next != NULL)													// 리스트 끝까지 탐색
		{
			printf("%c", ptr->data);												// 데이터 출력
			ptr = ptr->next;														// ptr을 다음 노드로		/*TODO 데이터 출력 형식 바꿔야함*/
		}
		printf("\n");
	}

}
void addDataToMemberList(memberList *list, Index pos, member data)					// 리스트의 특정 위치에 데이터를 추가하는 함수
{
	if (!isValidPosition(list, pos - 1))										// 올바른 위치에 삽입 여부
	{
		printf("invalid position\n");											// 오류메시지 출력
		return;																	// 함수 비정상 종료
	}

	setCurrentNode(list, pos);													// 현재 선택 노드를 pos위치 노드로 설정

	memberNode *new_node = alllocNode();											// 새로운 노드를 할당
	memberNode *crnt_node = list->crnt->prev;									// 삽입될 위치의 이전 주소 저장

	crnt_node->next = new_node;													// 삽입될 위치의 다음 노드를 새노드에 연결
	list->crnt->prev = new_node;												// 삽입될 위치의 이전 노드를 새노드에 연결

	setNode(new_node, crnt_node, list->crnt, data);								// 새 노드 위치와 데이터 설정 
}
void deleteDataFromMemberList(memberList *list, Index pos)							// 리스트내 특정 위치의 데이터를 삭제하는 함수
{
	if (!isValidPosition(list, pos))												// 올바른 위치에 접근 확인 함수
	{
		printf("invalid position\n");												// 오류메시지 출력
		return;																		// 함수 비정상 종료
	}
	setCurrentNode(list, pos);														// 현재 선택 노드를 pos위치 노드로 설정

	memberNode *A = list->crnt->prev;												// 임시 지정 노드 설정
	memberNode *B = list->crnt->next;												// 임시 지정 노드 설정

	A->next = B;																	// 삭제할 노드 앞뒤를 서로 연결
	B->prev = A;																	// 삭제할 노드 앞뒤를 서로 연결

	free(list->crnt);																// 삭제할 노드 공간 할당 해제

	list->crnt = list->head;														// 현재 선택 노드를 머리노드로 

}
member getDataFromMemberList(memberList *list, Index pos)								// 리스트내 특정 위치의 데이터를 반환하는 함수
{
	if (!isValidPosition(list, pos))												// 올바른 접근 여부 확인
	{
		printf("invalid position\n");												// 오류 메시지 출력
		return;																	// 함수 비정상 종료
	}

	setCurrentNode(list, pos);														// 현재 선택 노드를 pos번째 노드로

	return list->crnt->data;														// 현재 선택 노드 데이터 반환
}
void terminateMemberList(memberList *list)											// 리스트에 할당된 공간을 해제하고 종료하는 함수
{
	while (!isEmpty(list))															// 빈 리스트가 될 때 까지
	{
		deleteData(list, 1);														// 맨 앞 노드를 삭제
	}
	list->crnt = NULL;																// 현재 선택 노드를 NULL 로
	free(list->head);																// 머리 노드 할당 해제
	free(list->tail);																// 꼬리 노드 할당 해제
}

/* productList 에 대한 함수 목록 */

productNode* allocProductNode()														// 새 노드의 주소를 반환하는 함수
{
	return (productNode*)calloc(1, sizeof(productNode));							//새로운 노드주소를 할당하여 반환
}
void setProductNode(productNode *n, productNode *prev, productNode *next, product data)		// 노드의 값들을 설정하는 함수
{
	n->prev = prev;																	// prev 설정
	n->next = next;																	//next 설정
	n->data = data;																	// data 설정 
}
int sizeOfProductList(const productList *list)											// 연결 리스트의 크기를 반환하는 함수 
{
	int cnt = 0;																	// 크기 초기화
	productNode *ptr = list->head->next;												// ptr 변수에 값이 존재하는 첫 노드 대입
	while (ptr->next != NULL)														// ptr 노드의 다음노드가 NULL 일 때 까지 반복(맨 마지막 꼬리노드)
	{
		cnt++;																		// 크기변수 증가
		ptr = ptr->next;															// ptr 을 다음 노드로
	}
	return cnt;																		// 크기 반환
}
bool isEmptyProductList(const productList *list)										// 연결 리스트가 비어있는지 확인 하는 함수
{
	if (list->head->next == list->tail) return true;								// 머리노드의 다음노드가 꼬리 노드일때 비어있는 리스트임
	else return false;
}
void setCurrentProductNode(productList *list, Index pos)								// 현재 선택 노드를 특정노드로 가르키게 하는 함수
{
	if (isEmpty(list))																// 빈 리스트일때 
	{
		list->crnt = list->tail;													// 꼬리노드로 가리킴
		return;
	}
	productNode *ptr = list->head;													// 임시 ptr 변수를 머리노드를 가리키게 함 
	for (Index i = 0; i <= pos; ptr = ptr->next, i++)								// ptr이 pos번을 가르키게 한다.
	{
		list->crnt = ptr;															// ptr을 현재 선택 노드로
	}
}
void initializeProductList(productList *list)											// 리스트를 초기화 하는 함수
{
	list->head = alllocNode();														// 머리 노드를 할당
	list->tail = alllocNode();														// 꼬리 노드를 할당
	setNode(list->head, NULL, list->tail, 0);										// 머리노드를 초기화
	setNode(list->tail, list->head, NULL, 0);										// 꼬리 노드를 초기화

	list->crnt = list->head;														// 현재 선택 노드 초기화
}
void printProductList(const productList *list)											// 리스트내의 데이터를 출력하는 함수
{
	productNode *ptr = list->head->next;												// ptr을 맨 처음 값 노드로 설정
	if (!isEmpty(list))																// 빈 리스트가 아니면 출력
	{
		while (ptr->next != NULL)													// 리스트 끝까지 탐색
		{
			printf("%c", ptr->data);												// 데이터 출력
			ptr = ptr->next;														// ptr을 다음 노드로		/*TODO 데이터 출력 형식 바꿔야함*/
		}
		printf("\n");
	}

}
void addDataToProductList(productList *list, Index pos, product data)					// 리스트의 특정 위치에 데이터를 추가하는 함수
{
	if (!isValidPosition(list, pos - 1))										// 올바른 위치에 삽입 여부
	{
		printf("invalid position\n");											// 오류메시지 출력
		return;																	// 함수 비정상 종료
	}

	setCurrentNode(list, pos);													// 현재 선택 노드를 pos위치 노드로 설정

	productNode *new_node = alllocNode();											// 새로운 노드를 할당
	productNode *crnt_node = list->crnt->prev;									// 삽입될 위치의 이전 주소 저장

	crnt_node->next = new_node;													// 삽입될 위치의 다음 노드를 새노드에 연결
	list->crnt->prev = new_node;												// 삽입될 위치의 이전 노드를 새노드에 연결

	setNode(new_node, crnt_node, list->crnt, data);								// 새 노드 위치와 데이터 설정 
}
void deleteDataFromProductList(productList *list, Index pos)							// 리스트내 특정 위치의 데이터를 삭제하는 함수
{
	if (!isValidPosition(list, pos))												// 올바른 위치에 접근 확인 함수
	{
		printf("invalid position\n");												// 오류메시지 출력
		return;																		// 함수 비정상 종료
	}
	setCurrentNode(list, pos);														// 현재 선택 노드를 pos위치 노드로 설정

	productNode *A = list->crnt->prev;												// 임시 지정 노드 설정
	productNode *B = list->crnt->next;												// 임시 지정 노드 설정

	A->next = B;																	// 삭제할 노드 앞뒤를 서로 연결
	B->prev = A;																	// 삭제할 노드 앞뒤를 서로 연결

	free(list->crnt);																// 삭제할 노드 공간 할당 해제

	list->crnt = list->head;														// 현재 선택 노드를 머리노드로 

}
product getDataFromProductList(productList *list, Index pos)								// 리스트내 특정 위치의 데이터를 반환하는 함수
{
	if (!isValidPosition(list, pos))												// 올바른 접근 여부 확인
	{
		printf("invalid position\n");												// 오류 메시지 출력
		return;																	// 함수 비정상 종료
	}

	setCurrentNode(list, pos);														// 현재 선택 노드를 pos번째 노드로

	return list->crnt->data;														// 현재 선택 노드 데이터 반환
}
void terminateProductList(productList *list)											// 리스트에 할당된 공간을 해제하고 종료하는 함수
{
	while (!isEmpty(list))															// 빈 리스트가 될 때 까지
	{
		deleteData(list, 1);														// 맨 앞 노드를 삭제
	}
	list->crnt = NULL;																// 현재 선택 노드를 NULL 로
	free(list->head);																// 머리 노드 할당 해제
	free(list->tail);																// 꼬리 노드 할당 해제
}
