from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5 import uic
import pybithumb
import sys


form_class=uic.loadUiType("window.ui")[0]


class myWindow(QMainWindow,form_class):

    def __init__(self):

        super().__init__()

        self.setupUi(self)
        self.timer=QTimer(self)
        self.timer.start(1000)

        self.coin = ""

        self.comboBox.addItems(pybithumb.get_tickers())
        self.comboBox.currentIndexChanged.connect(self.changeCoin)

        self.pastPrice = pybithumb.get_current_price(self.coin)

        self.btnStart.clicked.connect(self.btn_start)
        self.btnStop.clicked.connect(self.btn_stop)


    def changeCoin(self):

        self.coin=self.comboBox.currentText()

    def btn_start(self):

        self.timer.timeout.connect(self.timeOut)

    def btn_stop(self):

        self.timer.timeout.disconnect(self.timeOut)
        self.lineEdit.setText(" ")
        self.priceUp.setText(" ")
        self.priceDown.setText(" ")

    def timeOut(self):

        curTime=QTime.currentTime()
        strTime=curTime.toString("hh:mm:ss")
        self.statusBar().showMessage(strTime)

        self.showCoin()



    def showCoin(self):

        currentPrice = pybithumb.get_current_price(self.coin)

        print(currentPrice)

        if currentPrice > self.pastPrice:
            print("상승")
            self.priceUp.setText("상승")
            self.priceDown.setText(" ")

        elif currentPrice < self.pastPrice:
            print("하락")
            self.priceDown.setText("하락")
            self.priceUp.setText(" ")

        self.pastPrice = currentPrice
        self.lineEdit.setText(str(currentPrice) + "원")


app = QApplication(sys.argv)
window=myWindow()
window.show()
app.exec_()