#pragma warning(disable:4996)			// 보안경고 무시
#include <stdio.h>						// stdio.h 헤더 include
#include <string.h>						// string.h 헤더 include
#include <stdlib.h>						// stdlib.h 헤더 include
#include <Windows.h>					// windows.h 헤더 include (system사용위함)	

#define true 1						//true 를 1로
#define false 0						// false를 0 으로

enum main_menu				//메인메뉴 열거형 정의
{
	EXIT = 0,				// 종료 는 0부터
	MEMBER_MANAGE,			// 회원관리
	PRODUCT_MANAGE,			// 상품관리
	ORDER_MANAGE,			// 주문관리
	SALES_MANAGE			// 매출관리
};
enum member_menu				// 회원관리 메뉴 열거형
{
	EXIT_MEMBER_MENU = 0,		// 종료를 0부터
	PRINT_MEMBER,				// 회원 출력
	CHANGE_NAME,				// 회원 이름변경
	CHANGE_ID,					// 회원 아이디 변경
	DELETE_MEMBER				// 회원 삭제
};
enum product_menu              // 상품관리 메뉴 열거형
{
	EXIT_PRODUCT_MENU = 0,		// 종료를 0으로
	PRINT_PRODUCT,				// 상품 출력
	ADD_PRODUCT,				// 상품 추가
	CHANGE_PRICE,				// 상품 가격 변경
	DELETE_PRODUCT				// 상품 삭제
};
enum sales_menu              // 매출관리 메뉴 열거형
{
	EXIT_SALES_MENU =0,      //종료를 0으로 
	PRINT_ALL,					// 총매출 출력
	PRINT_BY_PRODUCT				// 상품별 매출 출력
};

typedef int bool;     //bool형 자료형 만들기
typedef int Index;    // Index형 자료형 만들기


/* ---------------------------- */
/*  회원 상품 데이터 구조체 정의 */
/* ---------------------------- */


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


/* --------------------------*/
/* 인터페이스에 대한 함수 목록 */
/* --------------------------*/
void keyPressDelay();														// 키 입력 대기 함수
void printInputError();														// 입력 오류 출력 함수
void printMainWindow();														// 메인 화면 출력 함수
void printSelectMenu();														// 메뉴 선택 출력 함수
void MemberManageMenu(memberList *list);									// 회원 관리 메뉴
void ProductManageMenu(productList *list);									// 상품 관리 메뉴
void OrderManageMenu(productList *pro_list, memberList *mem_list);			// 주문 관리 메뉴
void SalesManageMenu(productList *list);									// 매출 관리 메뉴 

/* ------------------------ */
/* 주요 기능에 대한 함수 목록 */
/* ------------------------ */


/* 회원 관리에 대한 함수 목록 */
Index findIndexOfMemberByName(const memberList *list, const char name[]); // 이름으로 회원 검색
Index findIndexOfMemberById(const memberList *list, const char id[]);	//회원 아이디 검색 함수
void printAllMember(memberList *list);		// 회원 조회 함수
void registerMember(memberList *list);		// 회원 가입 함수
void changeMemberName(memberList *list);	// 회원 이름 변경 함수
void changeMemberID(memberList *list);		// 회원 아이디 변경 함수
void deleteMember(memberList *list);		// 회원 삭제 함수
void changePointOfMember(memberList *list,int point);		// 회원 적립 함수

/* 상품 관리에 대한 함수 목록 */
Index findIndexOfProduct(const productList *list, const char name[]);	//이름으로 상품 찾는 함수
void addProduct(productList *list);			// 상품 추가 함수
void deleteProduct(productList *list);		// 상품 삭제 함수
void changeProductPrice(productList *list); // 상품 가격 변경 함수
void printAllProduct(productList *list);    // 모든 상품 출력 함수

/* 주문 관리에 대한 함수 목록 */

void orderProduct(productList *prodictlist,  memberList *memberlist);	// 상품 주문 함수

/* 매출 관리에 대한 함수 목록 */

void printAllSales(productList *list);		// 총 매출 출력 함수 
void printSalesByProduct( productList *list);					// 상품 별 매출 출력 함수


/* -------- */
/* 메인 함수 */
/* -------- */

#define DEBUG_IF

int main()			//메인함수 시작 
{

#ifdef DEBUG_IF

	/* 멤버 사전 데이터 삽입 */
	memberList member_list;			//멤버리스트 선언
	productList product_list;		// 상품 리스트 선언

	member mdata1 = { "Kim","01012345678",1000 };
	member mdata2 = { "Lee","01099999999",2000 };
	member mdata3 = { "Park","01000000000",500 };
	member mdata4 = { "Choi","01011112222",0 };
	member mdata5 = { "Kang","01055556666",200 };
	initializeMemberList(&member_list);				//리스트 초기화
	addDataToMemberList(&member_list, 1, mdata1);   // 데이터 1,2,3,4,5 삽입
	addDataToMemberList(&member_list, 2, mdata2);
	addDataToMemberList(&member_list, 3, mdata3);
	addDataToMemberList(&member_list, 4, mdata4);
	addDataToMemberList(&member_list, 5, mdata5);
	/* 멤버 사전 데이터 삽입 끝 */

	/* 상품 사전 데이터 삽입*/
	product pdata1 = { "Coffee",3500,1 };
	product pdata2 = { "Cake",5000,2 };
	product pdata3 = { "Milk",1000,0 };
	product pdata4 = { "Water",500,4 };
	product pdata5 = { "Juice",1500,3 };
	initializeProductList(&product_list);		//리스트 초기화 
	addDataToProductList(&product_list, 1, pdata1);		//데이터 1,2,3,4,5 삽입
	addDataToProductList(&product_list, 2, pdata2);
	addDataToProductList(&product_list, 3, pdata3);
	addDataToProductList(&product_list, 4, pdata4);
	addDataToProductList(&product_list, 5, pdata5);
	/* 상품 사전 데이터 삽입 끝 */

	enum main_menu menu;			//열거형 정의 

	printMainWindow(); // 메인 윈도우 오픈 

	while (true)		//무한 루프
	{
		printSelectMenu(); // 메뉴 선택 

		scanf("%d",(int*)&menu);   //메뉴 번호 입력
		system("cls");			// 콘솔 화면 초기화

		switch (menu)				//메뉴선택 분기
		{
			case MEMBER_MANAGE:				//1번 회원관리
				MemberManageMenu(&member_list);   // 회원관리 함수 호출 
				break;
			case PRODUCT_MANAGE:                 // 2번 상품관리
				ProductManageMenu(&product_list);   // 상품관리 함수 호출 
				break;
			case ORDER_MANAGE:             // 3번 주문관리
				OrderManageMenu(&product_list, &member_list);     //주문관리 함수 호출 
				break;
			case SALES_MANAGE:                //4번 매출관리
				SalesManageMenu(&product_list);    //매출 관리 함수 호출 
				break;

			case EXIT:                        //0 번 프로그램 종료
				terminateMemberList(&member_list);	// 리스트 종료
				terminateProductList(&product_list); // 리스트 종료
				return 0;  //프로그램 종료

			default:										// 예외처리
				printInputError();							// 오류 메시지 출력
				break;
		}
	}
#endif
}


/* --------- */
/* 함수 정의 */
/* --------- */

/* ----------------------- */
/* 연결리스트 관련 함수 목록 */
/* ----------------------- */


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
	if (isEmptyMemberList(list))																// 빈 리스트일때 
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
	member data = { 0 };
	list->head = allocMemberNode();														// 머리 노드를 할당
	list->tail = allocMemberNode();														// 꼬리 노드를 할당
	setMemberNode(list->head, NULL, list->tail, data);										// 머리노드를 초기화
	setMemberNode(list->tail, list->head, NULL, data);										// 꼬리 노드를 초기화

	list->crnt = list->head;														// 현재 선택 노드 초기화
}
void printMemberList(const memberList *list)											// 리스트내의 데이터를 출력하는 함수
{
	memberNode *ptr = list->head->next;												// ptr을 맨 처음 값 노드로 설정
	if (!isEmptyMemberList(list))																// 빈 리스트가 아니면 출력
	{
		while (ptr->next != NULL)													// 리스트 끝까지 탐색
		{
			printf("%s %s %d\n", ptr->data.name, ptr->data.id, ptr->data.point);												// 데이터 출력
			ptr = ptr->next;														// ptr을 다음 노드로		/*TODO 데이터 출력 형식 바꿔야함*/
		}
		printf("\n");
	}

}
void addDataToMemberList(memberList *list, Index pos, member data)					// 리스트의 특정 위치에 데이터를 추가하는 함수
{
	//if (!isValidPosition(list, pos - 1))										// 올바른 위치에 삽입 여부
	//{
	//	printf("invalid position\n");											// 오류메시지 출력
	//	return;																	// 함수 비정상 종료
	//}

	setCurrentMemberNode(list, pos);													// 현재 선택 노드를 pos위치 노드로 설정

	memberNode *new_node = allocMemberNode();											// 새로운 노드를 할당
	memberNode *crnt_node = list->crnt->prev;									// 삽입될 위치의 이전 주소 저장

	crnt_node->next = new_node;													// 삽입될 위치의 다음 노드를 새노드에 연결
	list->crnt->prev = new_node;												// 삽입될 위치의 이전 노드를 새노드에 연결

	setMemberNode(new_node, crnt_node, list->crnt, data);								// 새 노드 위치와 데이터 설정 
}
void deleteDataFromMemberList(memberList *list, Index pos)							// 리스트내 특정 위치의 데이터를 삭제하는 함수
{
	//if (!isValidPosition(list, pos))												// 올바른 위치에 접근 확인 함수
	//{
	//	printf("invalid position\n");												// 오류메시지 출력
	//	return;																		// 함수 비정상 종료
	//}
	setCurrentMemberNode(list, pos);														// 현재 선택 노드를 pos위치 노드로 설정

	memberNode *A = list->crnt->prev;												// 임시 지정 노드 설정
	memberNode *B = list->crnt->next;												// 임시 지정 노드 설정

	A->next = B;																	// 삭제할 노드 앞뒤를 서로 연결
	B->prev = A;																	// 삭제할 노드 앞뒤를 서로 연결

	free(list->crnt);																// 삭제할 노드 공간 할당 해제

	list->crnt = list->head;														// 현재 선택 노드를 머리노드로 

}
member getDataFromMemberList(memberList *list, Index pos)								// 리스트내 특정 위치의 데이터를 반환하는 함수
{
	//if (!isValidPosition(list, pos))												// 올바른 접근 여부 확인
	//{	
	//	printf("invalid position\n");												// 오류 메시지 출력
	//	return ;																	// 함수 비정상 종료
	//}

	setCurrentMemberNode(list, pos);														// 현재 선택 노드를 pos번째 노드로

	return list->crnt->data;														// 현재 선택 노드 데이터 반환
}
void terminateMemberList(memberList *list)											// 리스트에 할당된 공간을 해제하고 종료하는 함수
{
	while (!isEmptyMemberList(list))															// 빈 리스트가 될 때 까지
	{
		deleteDataFromMemberList(list, 1);														// 맨 앞 노드를 삭제
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
	if (isEmptyProductList(list))																// 빈 리스트일때 
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
	product data = { 0 };
	list->head = allocProductNode();														// 머리 노드를 할당
	list->tail = allocProductNode();														// 꼬리 노드를 할당
	setProductNode(list->head, NULL, list->tail, data);										// 머리노드를 초기화
	setProductNode(list->tail, list->head, NULL, data);										// 꼬리 노드를 초기화

	list->crnt = list->head;														// 현재 선택 노드 초기화
}
void printProductList(const productList *list)											// 리스트내의 데이터를 출력하는 함수
{
	productNode *ptr = list->head->next;												// ptr을 맨 처음 값 노드로 설정
	if (!isEmptyProductList(list))																// 빈 리스트가 아니면 출력
	{
		while (ptr->next != NULL)													// 리스트 끝까지 탐색
		{
			printf("%s %d %d\n", ptr->data.name,ptr->data.price,ptr->data.sellCnt);												// 데이터 출력
			ptr = ptr->next;														// ptr을 다음 노드로		/*TODO 데이터 출력 형식 바꿔야함*/
		}
		printf("\n");
	}

}
void addDataToProductList(productList *list, Index pos, product data)					// 리스트의 특정 위치에 데이터를 추가하는 함수
{
	//if (!isValidPosition(list, pos - 1))										// 올바른 위치에 삽입 여부
	//{
	//	printf("invalid position\n");											// 오류메시지 출력
	//	return;																	// 함수 비정상 종료
	//}

	setCurrentProductNode(list, pos);													// 현재 선택 노드를 pos위치 노드로 설정

	productNode *new_node = allocProductNode();											// 새로운 노드를 할당
	productNode *crnt_node = list->crnt->prev;									// 삽입될 위치의 이전 주소 저장

	crnt_node->next = new_node;													// 삽입될 위치의 다음 노드를 새노드에 연결
	list->crnt->prev = new_node;												// 삽입될 위치의 이전 노드를 새노드에 연결

	setProductNode(new_node, crnt_node, list->crnt, data);								// 새 노드 위치와 데이터 설정 
}
void deleteDataFromProductList(productList *list, Index pos)							// 리스트내 특정 위치의 데이터를 삭제하는 함수
{
	//if (!isValidPosition(list, pos))												// 올바른 위치에 접근 확인 함수
	//{
	//	printf("invalid position\n");												// 오류메시지 출력
	//	return;																		// 함수 비정상 종료
	//}
	setCurrentProductNode(list, pos);														// 현재 선택 노드를 pos위치 노드로 설정

	productNode *A = list->crnt->prev;												// 임시 지정 노드 설정
	productNode *B = list->crnt->next;												// 임시 지정 노드 설정

	A->next = B;																	// 삭제할 노드 앞뒤를 서로 연결
	B->prev = A;																	// 삭제할 노드 앞뒤를 서로 연결

	free(list->crnt);																// 삭제할 노드 공간 할당 해제

	list->crnt = list->head;														// 현재 선택 노드를 머리노드로 

}
product getDataFromProductList(productList *list, Index pos)								// 리스트내 특정 위치의 데이터를 반환하는 함수
{
	//if (!isValidPosition(list, pos))												// 올바른 접근 여부 확인
	//{	
	//	printf("invalid position\n");												// 오류 메시지 출력
	//	return ;																	// 함수 비정상 종료
	//}

	setCurrentProductNode(list, pos);														// 현재 선택 노드를 pos번째 노드로

	return list->crnt->data;														// 현재 선택 노드 데이터 반환
}
void terminateProductList(productList *list)											// 리스트에 할당된 공간을 해제하고 종료하는 함수
{
	while (!isEmptyProductList(list))															// 빈 리스트가 될 때 까지
	{
		deleteDataFromProductList(list, 1);														// 맨 앞 노드를 삭제
	}
	list->crnt = NULL;																// 현재 선택 노드를 NULL 로
	free(list->head);																// 머리 노드 할당 해제
	free(list->tail);																// 꼬리 노드 할당 해제
}


/* --------------------------*/
/* 인터페이스에 대한 함수 목록 */
/* --------------------------*/

void keyPressDelay()			//키 입력 대기 함수
{
	system("pause");			// 아무키나 입력 대기
	system("cls");				// 콘솔창 초기화
}
void printInputError()			//에러 메시지 출력 함수
{
	printf("잘못된 입력입니다.\n");			// 에러 메시지 출력 
	keyPressDelay();						// 키 입력 대기
}
void printMainWindow()										//메인 화면 출력 함수
{
	printf("___________________**************___________________\n");   // 메인 화면 출력 
	printf("___________________카페관리 시스템___________________\n");
	printf("___________________**************___________________\n");
	printf("\n");
	keyPressDelay();			//키 입력 대기
}
void printSelectMenu()			//메뉴 선택 함수
{
	printf("(1)회원관리 (2)상품관리 (3)주문관리 (4)매출관리 (0)종료\n");    //메뉴 출력 
	printf("메뉴를 선택해주세요 : ");
}
void MemberManageMenu(memberList *list)             //회원 관리 함수
{
	enum member_menu menu;           //열거형 메뉴 선언

	while (true)           //무한루프
	{
		printf("(1)회원조회 (2)회원이름변경 (3)회원아이디변경 (4)회원삭제 (0)처음으로\n");    // 메뉴 출력 
		printf("메뉴를 선택해주세요 : ");
		scanf("%d", (int*)&menu);         // 메뉴 입력 
		system("cls");            // 콘솔창 초기화
		switch (menu)     // 메뉴 선택
		{
			case PRINT_MEMBER:          //1번 회원 출력 
				printAllMember(list);    //회원 출력 함수 호출
				break;
			case CHANGE_NAME:		//2번 회원 이름 변경
				changeMemberName(list);   // 회원 이름 변경 함수 호출
				break;
			case CHANGE_ID:				//3번 회원 아이디 변경 
				changeMemberID(list);     //회원 아이디 변경 함수 호출
				break;
			case DELETE_MEMBER:         //4번 회원 삭제 
				deleteMember(list);     //회원 삭제 함수 호출 
				break;
			case EXIT_MEMBER_MENU:       // 0번 메뉴 종료
				system("cls");           // 콘솔 초기화
				return;                //함수 종료
			default:							//예외
				printInputError();       // 입력 오류 출력 
				break;
		}
	}
}
void ProductManageMenu(productList *list)      // 상품 관리 메뉴 함수
{
	enum product_menu menu;        // 상품 메뉴 열거형 선언
	while (true)  // 무한루프
	{
		printf("(1)상품조회 (2)상품추가 (3)상품가격변경 (4)상품삭제 (0)처음으로\n");    //메뉴 출력
		printf("메뉴를 선택해주세요 : ");
		scanf("%d", (int*)&menu);   //메뉴 입력
		system("cls");   //콘솔 초기화

		switch (menu)   //메뉴 선택
		{
			case PRINT_PRODUCT:			//1번 상품 출력
				printAllProduct(list);  //상품출력함수 호출
				break;
			case ADD_PRODUCT:		//2번 상품 추가
				addProduct(list);		//상품 추가 함수 호출
				break;
			case CHANGE_PRICE:			//3번 상품 가격 변경
				changeProductPrice(list);	//상품 가격 변경 함수 호출
				break;
			case DELETE_PRODUCT:		//4번 상품 삭제 
				deleteProduct(list);  //상품 삭제함수 호출
				break;
			case EXIT_PRODUCT_MENU:		//0번 종료
				system("cls");        //콘솔창 초기화
				return;             // 함수종료
			default:			//예외
				printInputError();     // 오류메시지 출력   
				break;
		}
	}
}
void OrderManageMenu(productList *pro_list,memberList *mem_list)        //주문관리 함수 
{
	orderProduct(pro_list, mem_list);       // 주문관리 함수 호출 
}
void SalesManageMenu(productList *list)         //매출 관리 함수
{
	enum sales_menu menu;        // 매출관리 열거형 선언

	while (true)	//무한루프
	{
		printf("(1)총 매출 (2)상품별 매출 조회 (0)처음으로\n");        // 메뉴선택창 출력 
		printf("메뉴를 선택해주세요 : ");
		scanf("%d", (int*)&menu);       // 메뉴 입력
		system("cls");   //콘솔 초기화
		switch (menu)   //메뉴 선택
		{
			case PRINT_ALL:         //1번 총매출 출력 
				printAllSales(list);  // 총매출 출력 함수 호출
				break;
			case PRINT_BY_PRODUCT:       //2번 상품별 매출 출력
				printSalesByProduct(list);      // 상품별 매출 함수 출력 
				break;
 			case EXIT_SALES_MENU:			// 0번 종료
				system("cls");            //콘솔창 초기화
				return;				// 함수종료
			default:				//예외
				printInputError();			//입력 오류메시지 출력 
				break;
		}
	}
}

/* ------------------------ */
/* 주요 기능에 대한 함수 목록 */
/* ------------------------ */


/* 회원 관리에 대한 함수 목록 */

Index findIndexOfMemberByName(const memberList *list,const char name[])	//회원 이름 검색 함수
{
	memberNode *ptr = list->head->next;												// ptr을 맨 처음 값 노드로 설정
	Index i=1;																	// i는 1부터
	if (!isEmptyMemberList(list))																// 빈 리스트가 아니면 실행
	{
		while (ptr->next != NULL)													// 리스트 끝까지 탐색
		{
			if (strcmp(name, ptr->data.name) == 0)										// 찾는 이름이면
			{
				return i;															// 현재 인덱스 반환
			}
			ptr = ptr->next;														// ptr을 다음 노드로		/*TODO 데이터 출력 형식 바꿔야함*/
			i++;
		}
	}
	return -1;			// 찾지 못하였을때
}
Index findIndexOfMemberById(const memberList *list, const char id[])	//회원 아이디 검색 함수
{
	memberNode *ptr = list->head->next;												// ptr을 맨 처음 값 노드로 설정
	Index i = 1;																	// i는 1부터
	if (!isEmptyMemberList(list))																// 빈 리스트가 아니면 실행
	{
		while (ptr->next != NULL)													// 리스트 끝까지 탐색
		{
			if (strcmp(id, ptr->data.id) == 0)										// 찾는 아이디이면
			{
				return i;															// 현재 인덱스 반환
			}
			ptr = ptr->next;														// ptr을 다음 노드로		/*TODO 데이터 출력 형식 바꿔야함*/
			i++;
		}
	}
	return -1;			// 찾지 못하였을때
}
void printAllMember(memberList *list)		// 회원 조회 함수
{
	printMemberList(list);       // 회원출력
	keyPressDelay();       // 키입력 대기
}
void registerMember(memberList *list)		// 회원 가입 함수
{
	char new_name[11];					// 새로운 이름 변수
	char new_id[12];					// 새로운 전화번호 변수
	int new_point=0;					// 새로운 포인트 변수 

	printf("회원가입\n");				//TODO 가입 인터페이스 만들기

	printf("이름을 입력해주세요. (영문10자 이내) :");				// 이름 입력 안내
	scanf("%s", new_name);										// 이름 입력
	printf("전화번호를 입력해주세요. (ex.01012345678) :");		// 전화번호 입력 안내
	scanf("%s", new_id);										// 전화번호 입력

	member new_member = { "tmp","tmp",new_point };				// 새로운  회원 구조체 생성
	strcpy(new_member.name, new_name);							// 이름을 대입
	strcpy(new_member.id, new_id);								// 전화번호를 대입


	addDataToMemberList(list, 1, new_member);					// 새로운 회원을 리스트에 맨 앞에 추가
	
	printf("가입 완료 !!\n");									// 가입 완료 메시지

	keyPressDelay();            // 키입력 대기
}
void changeMemberName(memberList *list)	// 회원 이름 변경 함수
{
	char find_name[11];
	char new_name[11];

	Index find_name_idx;

	printf("찾는 이름을 입력해주세요. (영문10자 이내) :");				// 이름 입력 안내
	scanf("%s", find_name);										// 이름 입력

	find_name_idx = findIndexOfMemberByName(list, find_name);
	
	if (find_name_idx == -1)										// 이름이 없을때 처리
	{
		printf("이름을 찾지 못하였습니다.\n");						// 오류 메시지 출력											
		keyPressDelay();
		return;
	}

	setCurrentMemberNode(list, find_name_idx);

	printf("이름을 찾았습니다!\n");
	printf("회원 정보\n%s %s %d\n", list->crnt->data.name, list->crnt->data.id, list->crnt->data.point);		// 찾은 회원 정보출력

	printf("바꿀 이름을 입력해주세요. (영문10자 이내) :");				// 이름 입력 안내
	scanf("%s", new_name);											// 새 이름 입력 

	strcpy(list->crnt->data.name, new_name);					// 새이름을 기존이름에 덮어쓰기

	printf("변경 완료 !!\n");									// 완료 메시지 출력 

	keyPressDelay();

}
void changeMemberID(memberList *list)	// 회원 아이디 변경 함수
{
	char find_id[12];
	char new_id[12];

	Index find_id_idx;

	printf("찾는 아이디을 입력해주세요. (ex.01012345678) :");				// 이름 입력 안내
	scanf("%s", find_id);										// 이름 입력

	find_id_idx = findIndexOfMemberById(list, find_id);

	if (find_id_idx == -1)										// 이름이 없을때 처리
	{
		printf("아이디을 찾지 못하였습니다.\n");						// 오류 메시지 출력
		keyPressDelay();
		return;														// 함수 비정상 종료
	}

	setCurrentMemberNode(list, find_id_idx);

	printf("아이디을 찾았습니다!\n");
	printf("회원 정보\n%s %s %d\n", list->crnt->data.name, list->crnt->data.id, list->crnt->data.point);		// 찾은 회원 정보출력

	printf("바꿀 아이디을 입력해주세요. (ex.01012345678) :");				// 이름 입력 안내
	scanf("%s", new_id);											// 새 이름 입력 

	strcpy(list->crnt->data.id, new_id);					// 새이름을 기존이름에 덮어쓰기

	printf("변경 완료 !!\n");									// 완료 메시지 출력 

	keyPressDelay();
}
void deleteMember(memberList *list)		// 회원 삭제 함수
{
	char find_name[11];
	char del_mem;

	Index find_name_idx;

	printf("삭제할 회원의 이름을 입력해주세요. (영문10자 이내) :");				// 이름 입력 안내
	scanf("%s", find_name);										// 이름 입력

	find_name_idx = findIndexOfMemberByName(list, find_name);

	if (find_name_idx == -1)										// 이름이 없을때 처리
	{
		printf("이름을 찾지 못하였습니다.\n");						// 오류 메시지 출력

		keyPressDelay();
		return;														// 함수 비정상 종료
	}

	setCurrentMemberNode(list, find_name_idx);

	printf("아이디을 찾았습니다!\n");
	printf("회원 정보\n%s %s %d\n", list->crnt->data.name, list->crnt->data.id, list->crnt->data.point);		// 찾은 회원 정보출력
	printf("삭제하시겠습니까? [Y:N] :");
	getchar();
	scanf("%c", &del_mem);

	if (del_mem == 'N' || del_mem == 'n')
	{
		printf("삭제를 취소하셨습니다.\n");
		keyPressDelay();
		return;
	}

	deleteDataFromMemberList(list, find_name_idx);

	printf("삭제 완료!!\n");

	keyPressDelay();
}
void changePointOfMember(memberList *list,int point)		// 회원 적립 함수
{
	Index find_name_idx;			// 인덳스 , 이름 변수 선언
	char find_name[11],regi;

	printf("회원 이름을 입력해주세요. (영문10자 이내) :");				// 이름 입력 안내
	scanf("%s", find_name);										// 이름 입력

	find_name_idx = findIndexOfMemberByName(list, find_name);      // 이름 찾아서 인덱스 반환

	if (find_name_idx == -1)										// 이름이 없을때 처리
	{
		printf("이름을 찾지 못하였습니다.\n");						// 오류 메시지 출력
		printf("회원 가입을 하시겠습니까?[Y:N] :");
		getchar();
		scanf("%c", &regi);              // 입력 

		if (regi == 'N' || regi == 'n')       // n 입력시
		{
			printf("회원 가입을 취소하셨습니다.\n");   // 가입취소
			keyPressDelay();					//키입력대기
			return;								//함수종료
		}
		registerMember(list);          //회원 가입 함수 호출 
		return;						//함수 종료
	}


	setCurrentMemberNode(list, find_name_idx);      //현재 선택노드를 찾은 인덱스로 

	printf("이름을 찾았습니다!\n");										//이름 찾기 성공 메시지 출력 
	printf("%d 포인트가 적립되었습니다.\n\n", point);									// 포인트 적립
	list->crnt->data.point += point;
	printf("회원 정보\n%s %s %d\n\n", list->crnt->data.name, list->crnt->data.id, list->crnt->data.point);   //적립 회원 정보출력
	keyPressDelay();    // 키입력 대기
}

/* 상품 관리에 대한 함수 목록 */

Index findIndexOfProduct(const productList *list, const char name[])	//이름으로 상품 찾는 함수
{
	productNode *ptr = list->head->next;												// ptr을 맨 처음 값 노드로 설정
	Index i = 1;																	// i는 1부터
	if (!isEmptyProductList(list))																// 빈 리스트가 아니면 실행
	{
		while (ptr->next != NULL)													// 리스트 끝까지 탐색
		{
			if (strcmp(name, ptr->data.name) == 0)										// 찾는 이름이면
			{
				return i;															// 현재 인덱스 반환
			}
			ptr = ptr->next;														// ptr을 다음 노드로		/*TODO 데이터 출력 형식 바꿔야함*/
			i++;
		}
	}
	return -1;			// 찾지 못하였을때
}
void addProduct(productList *list)			// 상품 추가 함수
{
	char product_name[21] = { "\0" };
	int product_price = 0;

	printf("상품추가\n");				// 상품 추가 메뉴 출력 

	printf("추가할 상품의 이름을 입력해주세요. (영문자 20자이내) :");       // 상품추가 안내 메시지
	scanf("%s", product_name);								//추가할 상품이름 입력
	printf("추가할 상품의 가격을 입력해주세요.(원) :");
	scanf("%d", &product_price);											// 추가할 상품 가격 입력 

	product new_product = { "tmp",product_price,0 };               // 새로운 상품 정보 초기화
	strcpy(new_product.name, product_name);                  // 새로운 상품 정보에 새로운 상품이름 대입
	
	addDataToProductList(list, 1, new_product);            //리스트에 데이터 추가
	printf("추가 완료 !!\n");											// 추가 완료 메시지
	keyPressDelay();												// 키 입력 대기
}
void deleteProduct(productList *list)		// 상품 삭제 함수
{
	char product_name[21] = { "\0" };			// 상품 이름 변수
	char del_product;							
	Index find_product_idx;

	printf("상품 삭제\n");				//상품 삭제 메시지

	printf("삭제 상품의 이름을 입력해주세요. (영문자 20자이내) :");
	scanf("%s", product_name);			//삭제할 상품이름 입력
	find_product_idx = findIndexOfProduct(list, product_name);			// 삭제할 상품 이름 인덱스 찾기

	if (find_product_idx == -1)			//찾지못하면
	{
		printf("상품을 찾지 못하였습니다.\n");   //에러메시지 출력
		keyPressDelay();		// 키입력 대기
		return;				//함수 종료
	}
	setCurrentProductNode(list, find_product_idx);				// 현재 노드를 찾은 인덱스로 변경 
	printf("상품을 찾았습니다!\n");					// 상품 찾기 성공 메시지 출력 
	printf("상품 정보\n%s %d %d\n", list->crnt->data.name, list->crnt->data.price, list->crnt->data.sellCnt);		// 찾은 상품 정보출력
	

	printf("삭제하시겠습니까? [Y:N] :");        // 상품 삭제 여부 
	getchar();
	scanf("%c", &del_product);          // 입력 

	if (del_product == 'N' || del_product == 'n')   //n 일시 삭제 취소 
	{
		printf("삭제를 취소하셨습니다.\n");
		keyPressDelay();
		return;
	}
	// 이외에는 상품 삭제 
	deleteDataFromProductList(list, find_product_idx);   // 리스트에서 상품 삭제

	printf("삭제 완료 !!\n");  //상품 삭제 메시지 출력 
	keyPressDelay();	// 키입력대기

}
void changeProductPrice(productList *list) // 상품 가격 변경 함수
{
	char product_name[21] = { "\0" };		// 이름 초기화
	int new_price = 0;								// 새로운 가격
	char change_product;
	Index find_product_idx;

	printf("상품 가격 변경\n");				//상품 가격 변경 메뉴 출력 

	printf("가격을 변경할 상품의 이름을 입력해주세요. (영문자 20자이내) :");
	scanf("%s", product_name);											//이름 입력 
	find_product_idx = findIndexOfProduct(list, product_name);      // 이름 찾아서 인덱스 반환 

	if (find_product_idx == -1)				// 찾지못하면 
	{
		printf("상품을 찾지 못하였습니다.\n");   //출력 
		keyPressDelay(); //키 입력 대기
		return; //함수 종료
	}

	setCurrentProductNode(list, find_product_idx);						// 현재 선택노드를 찾은 인덱스로
	printf("상품을 찾았습니다!\n");   //상품 정보 출력 
	printf("상품 정보\n%s %d %d\n", list->crnt->data.name, list->crnt->data.price, list->crnt->data.sellCnt);		// 찾은 상품 정보출력
	printf("변경 하시겠습니까? [Y:N] :");   // 변경 여부 
	getchar();
	scanf("%c", &change_product);   //입력 

	if (change_product == 'N' || change_product == 'n')   //n 이면 변경 취소
	{
		printf("변경을 취소하셨습니다.\n");   //변경취소 메시지
		keyPressDelay();		//키입력대기
		return;			//함수종료
	}

	printf("새로운 가격을 입력해주세요.(원) :");        // 새로운 가격입력
	scanf("%d", &new_price);

	list->crnt->data.price = new_price;         // 새로운 가격 업데이트

	printf("변경 완료 !!\n");           // 변경완료 메시지

	keyPressDelay();			//키 입력대기 
}
void printAllProduct(productList *list)    // 모든 상품 출력 함수
{
	printProductList(list);       // 상품 출력 함수 호출
	keyPressDelay(); // 키 입력 대기
}

/* 주문 관리에 대한 함수 목록 */

void orderProduct(productList *pro_list, memberList *mem_list)	// 상품 주문 함수
{
	Index idx;       // 인덱스 
	int k;     // 상품 갯수
	char order, checkpoint;      // n 입력 확인 
	while (true)				// 무한루프
	{
		printProductList(pro_list);         // 상품 리스트 출력 
		printf("무엇을 주문하시겠습니까? (0)처음으로\n");   // 주문 메뉴 출력 
		printf("(위에서부터 1번) 메뉴를 선택해주세요 : ");
		scanf("%d", &idx);           // 메뉴 입력
		system("cls");            // 콘솔창 초기화
		if (idx == 0)        // 0번은 종료 
			return;
		if (idx > sizeOfProductList(pro_list))        //예외처리 
		{
			printInputError();						// 에러메시지 출력 
			continue;					// 계속 
		}

		setCurrentProductNode(pro_list, idx);				//현재 선택 노드를 입력한 인덱스로
		product buy_product;											// 새로운 데이터 
		buy_product = getDataFromProductList(pro_list, idx);      //상품 데이터를 받아온다.

		printf("상품정보\n");           //상품정보 출력 
		printf("%s %d원\n", buy_product.name, buy_product.price);

		printf("몇개를 주문하시겠습니까? :");       // 주문 개수
		scanf("%d", &k);							//주문 개수입력
		system("cls");			// 콘솔창 초기화
		// 정보 출력 
		printf("%s %d개를 주문 하셨습니다. 가격은 %d 입니다.\n", buy_product.name, k, k*buy_product.price);
		printf("주문하시겠습니까? [Y:N] :");   //주문 여부
		getchar();
		scanf("%c", &order);

		if (order == 'N' || order == 'n')   //N입력시 주문취소
		{
			printf("주문을 취소하셨습니다.\n");  //메시지 출력
			keyPressDelay();   //키입력대기
			continue;    //함수 맨처음으로 
		}

		pro_list->crnt->data.sellCnt += k;     //판매 카운트 증가
		printf("주문 완료!!\n");        // 주문완료 메시지출력 

		printf("적립 포인트는 %d포인트 입니다.", (int)(k*buy_product.price*0.05));      //포인트적립
		printf("적립하시겠습니까? [Y:N] :");   //포인트 적립 여부
		getchar();
		scanf("%c", &checkpoint);      // 포인트 적립 여부 입력
		system("cls");   //콘솔 초기화
		if (checkpoint == 'N' || checkpoint == 'n') //n이면 적립취소
		{
			printf("적립을 취소하셨습니다.\n");     // 적립취소 메시지
			keyPressDelay();   // 키 입력 대기
			continue;   // 함수 처음으로 
		}

		changePointOfMember(mem_list, (int)(k*buy_product.price*0.05));  // 포인트 변경 함수 호출 
	}
}

/* 매출 관리에 대한 함수 목록 */

void printAllSales(productList *list)		// 총 매출 출력 함수
{
	int all_sales = 0;		//총매출 변수 초기화
	productNode *ptr = list->head->next;												// ptr을 맨 처음 값 노드로 설정
	if (!isEmptyProductList(list))																// 빈 리스트가 아니면 출력
	{
		while (ptr->next != NULL)													// 리스트 끝까지 탐색
		{
			all_sales += (ptr->data.price)*(ptr->data.sellCnt);
			ptr = ptr->next;														// ptr을 다음 노드로		/*TODO 데이터 출력 형식 바꿔야함*/
		}
	}
	printf("총 매출은 %d 원 입니다.\n",all_sales);		// 매출 출력 
	keyPressDelay();		// 키입력 대기
}
void printSalesByProduct(productList *list)					// 상품 별 매출 출력 함수
{
	productNode *ptr = list->head->next;												// ptr을 맨 처음 값 노드로 설정
	if (!isEmptyProductList(list))																// 빈 리스트가 아니면 출력
	{
		while (ptr->next != NULL)													// 리스트 끝까지 탐색
		{
			printf("상품 이름 : %s 매출 : %d원\n", ptr->data.name, (ptr->data.price) *(ptr->data.sellCnt));												// 데이터 출력
			ptr = ptr->next;														// ptr을 다음 노드로		/*TODO 데이터 출력 형식 바꿔야함*/
		}
		printf("\n");
	}
	keyPressDelay();		// 키 입력 대기
}
