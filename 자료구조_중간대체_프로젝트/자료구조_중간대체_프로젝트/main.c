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