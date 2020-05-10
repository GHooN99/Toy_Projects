from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5 import uic
from PyQt5 import QtGui
from urllib import request
import sys
import os

form_class=uic.loadUiType("login.ui")[0]

## os.system("shutdown -s -t 60")  # 60초 뒤에 강제종료

#test data
sid = "19011011"
sname = "kim"
getPcIndex = "20"
getlocation = "B104"


class LogoutWindow(QMainWindow):
    def __init__(self,parent):
        super(LogoutWindow,self).__init__(parent)
        LogoutUI="logout.ui"
        uic.loadUi(LogoutUI,self)

        self.setFixedSize(655, 521)
        self.setWindowFlag(Qt.WindowCloseButtonHint, False)
        self.timer = QTimer(self)
        self.timer.start(1000)

        self.btnLogout.clicked.connect(self.btn_logout)

        self.timer.timeout.connect(self.printTime)

        self.ShowPC.setText(str(getPcIndex))
        self.ShowPC.setFont(QtGui.QFont("맑은 고딕", 24))

        self.ShowLoc.setText(str(getlocation))
        self.ShowLoc.setFont(QtGui.QFont("맑은 고딕", 24))

        self.LoginID.setText(str(login_id))
        self.LoginID.setFont(QtGui.QFont("맑은 고딕", 24))

        self.LoginTime.setText(str(login_time))
        self.LoginTime.setFont(QtGui.QFont("맑은 고딕", 24))

        self.show()

    def printTime(self):
        curTime = QTime.currentTime()
        strTime = curTime.toString("hh:mm:ss")
        self.ShowTime.setText(str(strTime))

    def btn_logout(self):
        log = os.system("shutdown -s -t 100")  # 강제종료
        print(log)
        print("Logout")
        curTime = QTime.currentTime()
        strTime = curTime.toString("hh:mm:ss")

        print("user : %s" %login_name)
        print("id : %s" % login_id)
        print("logout time : %s" % (strTime))
        print("PC : ", getPcIndex)

        self.close()



class myWindow(QMainWindow,form_class):

    def __init__(self):

        super().__init__()
        self.setFixedSize(655,521)
        self.setWindowFlag(Qt.WindowCloseButtonHint, False)
        self.setupUi(self)
        self.timer=QTimer(self)
        self.timer.start(1000)
        self.btnLogin.clicked.connect(self.btn_login)
        self.timer.timeout.connect(self.printTime)

        self.ShowPC.setText(str(getPcIndex))
        self.ShowPC.setFont(QtGui.QFont("맑은 고딕",24))

        self.ShowLoc.setText(str(getlocation))
        self.ShowLoc.setFont(QtGui.QFont("맑은 고딕",24))

    def printTime(self):
        curTime = QTime.currentTime()
        strTime = curTime.toString("hh:mm:ss")
        self.ShowTime.setText(str(strTime))

    def btn_login(self):
        name = str(self.inputName.text())
        number = str(self.inputNumber.text())
        alert = QMessageBox()

        print("input")      #인풋 값 확인
        print("name : %s , id : %s"%(name,number))

        if name == sname:
            if number == sid:
                self.login(name,number)

            else:
                alert.information(self, "학번 오류!", "없는 학번입니다!")
                print("Failed1")
        else:
            alert.information(self, "이름 오류!", "없는 이름입니다!")
            print("Failed2")


    def timeOut(self):      #현재 시간 출력

        curTime=QTime.currentTime()
        strTime=curTime.toString("hh:mm:ss")
        self.statusBar().showMessage(strTime)

    def login(self,name,number):
        log=os.system("shutdown -a") # 강제종료 취소
        print(log)
        print("Login")

        self.timer.timeout.connect(self.timeOut)        # 시간 저장
        curTime = QTime.currentTime()
        strTime = curTime.toString("hh:mm:ss")

        #데이터 넘겨주기
        global login_id
        global login_time
        global login_name

        login_name = name
        login_id = number
        login_time = strTime

        # 데이터 출력
        print("user : %s" % name)
        print("id : %s" % number)
        print("login time : %s" %(strTime))
        print("PC : ", getPcIndex)

        self.close()            # 로그인 창 닫음
        LogoutWindow(self)          # 로그아웃 창 열기



app = QApplication(sys.argv)
window=myWindow()
window.show()
app.exec_()