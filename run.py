#!/usr/bin/env python
# -*- coding: utf-8 -*-

from PyQt5.QtCore import QTimer, QThread, QCoreApplication
from PyQt5.QtGui import QIcon

import code
import time
import sys
import os
import sys

import pyyourclass

class Application(QCoreApplication):
    def __init__(self, arg):
        super().__init__(arg)

        # Instanciate your C++ Qt Application as follow:
        self.yourapp = pyyourclass.YourClass(666)

    def init(self):
        self.yourapp.init()


class Console(QThread):
    def run(self):
        code.interact(local=globals())
        app.quit();


if __name__ == '__main__':

    console = Console()
    app = Application(sys.argv)

    # Access one of your function as follow:
    pyyourclass.aFunction()

    # Manipulate your object as follow:
    print(app.yourapp.getMember())

    # Call a static method of YourClass class.
    pyyourclass.YourClass.setSleep(1);

    # Create console and keep your python prompt.
    console.start()

    yourStruct1 = app.yourapp.getYourStruct();
    yourStruct1.printMember()

    # Qt main loop.
    app.exec_()
    console.wait()

    print("pyyourclass bye !")
    app = 0
