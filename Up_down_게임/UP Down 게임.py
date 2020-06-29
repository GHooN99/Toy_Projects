
inf_loop=1                          #무한 루프 변수 =1
6
while inf_loop!=0:             #무한 루프 변수가 0 이 아닐때 게임 계속진행
    
    import random              #랜덤 모듈
    import math                  #수학 모듈
    

    print("UP Down 게임")
    print("0보다 큰 양수로 범위를 지정 해주세요(범위길이는 2보다 크게)\n")

    range_start=int(input("범위 시작 : "))
    range_end=int(input("범위 끝 : "))
    range_len= range_end-range_start                #범위 길이 변수
    swap=0           #스왑 변수 초기화
    
    if range_len<=2:
        continue
    
    if range_start>range_end:      #범위 시작이 끝보다 클때 강제스왑
        swap=range_start
        range_start=range_end
        range_end=swap

    answer=random.randint(range_start,range_end)      #범위 내의 랜덤 숫자 생성
    
    print("%d에서 %d사이의 숫자가 생성되었습니다."%(range_start,range_end))

    

    
    q=0                #입력 변수 초기화
    count=0          # 기회 변수 초기화
    
   
    count=math.log(range_len)//math.log(2)        #범위 길이를 2 로 '기회 '번나눴을때 1이 되는 최소 기회  ??
    count_0=count                                               #기회 상수 선언 
    print("기회는 %d 번"%count)
    



    
    while count>0:     #기회가 0이상일때 반복 
    
        count-=1              # 기회 차감 
    
        q=int(input("답을 입력해 주세요 : "))
    
        if range_start>q or q>range_end:  # 범위 밖 수 처리 
            print("범위 밖의 수입니다.\n")
            print("남은 기회 : %d번\n"%count)                     
            continue         # 밑부분 if 문  무시 
        
        if q==answer:
            break       #정답일시 탈출 

        elif q>answer:
            print("Down!")
            print("남은 기회 : %d번\n"%count)
        
        elif q<answer:
            print("UP!")
            print("남은 기회 : %d번\n"%count)


            

    if q!=answer:    # 정답이 아닐시 실패 
        print("실패")
        print("정답은 %d 였습니다."%answer)
        
        
    else:           
        print("정답입니다.")
        print("시도 횟수 : %d"%(count_0-count))  #시도 횟수=(처음기회-누적기회)





    continue_value=' '                  #계속하기 변수 초기화 
    while continue_value!='Y' or continue_value!='N':           #Y,N 이외의 값 일때 반복 
        continue_value=input('계속 하시겠습니까? (Y : N)\n: ')
        
        if continue_value=='Y':                 #Y일때 무한 루프 변수 1로 만든후 반복 탈출 
            inf_loop=1
            break
        
        elif continue_value=='N':               #N일때 무한 루프 변수 0로 만든후(무한루프 종료) 반복 탈출
            inf_loop=0
            break
        
        else:
             print("Y 또는 N을 입력해 주세요\n")     #Y,N 이외값 처리 




print("Game Over")              #다 끝나면 출력 













