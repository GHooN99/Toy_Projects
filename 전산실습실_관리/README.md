## 전산실습실_관리_프로그램

#### python 으로 간단한 gui 만들기,로그인 로그아웃 창 구현 맛보기

- 학생 정보의 데이터를 주고 받는 일은 구현을 하지 않음
- Pyqt5에서 두번쨰 창으로 넘어가는 (로그인 후) 부분이 구현이 쉽지 않았다.
- 로그인 데이터는 테스트 데이터를 이용하였다.
- 실습실 관리 프로그램인지라 로그인을 하지 않으면 컴퓨터가 자동종료(shutdown 명령어를 이용)되게 만들었다..
- 위치와 PC 번호도 데이터를 받아와 위치마다 다르게 띄울수 있게 만들어 놓았다.

### UI

![1](https://user-images.githubusercontent.com/53388557/85982690-3b4fe400-ba21-11ea-8405-9c6e8554c06f.JPG)


### 로그인 에러 1

- 학번과 이름이 둘다 틀릴때

![2](https://user-images.githubusercontent.com/53388557/85982805-676b6500-ba21-11ea-89f7-e8df604345c6.JPG)


### 로그인 에러 2

- 이름은 맞으나 학번이 틀릴때

![3](https://user-images.githubusercontent.com/53388557/85982831-72be9080-ba21-11ea-9ded-df867a8b50a4.JPG)


### 로그인 성공(로그아웃 창)

![4](https://user-images.githubusercontent.com/53388557/85982885-8964e780-ba21-11ea-94ca-9c6c79388154.JPG)

