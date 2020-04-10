#include <Servo.h> //서보 라이브러리를 불러옵니다.

Servo myservo;  // 서보를 제어할 서보 오브젝트를 만듭니다.

int pos = 0;     // 서보 위치를 저장할 변수를 선언합니다.

void setup()
{
  Serial.begin(9600); // 시리얼 통신 시작 
  myservo.attach(9);  // 핀 9의 서보를 서보 오브젝트에 연결합니다.
}


void loop()
{
  while (Serial.available())  
  {
    int n = Serial.read();   // 파이썬에서 신호를 가져옴 

    if (n == 1)   
    {
      myservo.write(0);
      delay(30);
    }
    else if (n == 2)
    {
      myservo.write(65);
      delay(30);
    }
    else if(n==3)
    {
      myservo.write(110);
      delay(30);
    }
    else
    {
      delay(300);
    }

   
    delay(200);
  }
}
