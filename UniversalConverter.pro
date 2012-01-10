# Add files and directories to ship with the application 
# by adapting the examples below.
# file1.source = myfile
# dir1.source = mydir
DEPLOYMENTFOLDERS = # file1 dir1

symbian:TARGET.UID3 = 0xE4D8E374

# Smart Installer package's UID
# This UID is from the protected range 
# and therefore the package will fail to install if self-signed
# By default qmake uses the unprotected range value if unprotected UID is defined for the application
# and 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment
# the following lines and add the respective components to the 
# MOBILITY variable. 
# CONFIG += mobility
# MOBILITY +=

SOURCES += main.cpp mainwindow.cpp \
    unitsettings.cpp \
    categories_units/categories_units.cpp \
    tablemodelunits.cpp \
    globalfunctions.cpp \
    categories_units/units.cpp \
    math/calculadora.cpp \
    math/complexdata.cpp \
    math/complexo.cpp \
    math/array_math.cpp \
    categories_dlg.cpp
HEADERS += mainwindow.h \
    unitsettings.h \
    categories_units/categories_units.h \
    tablemodelunits.h \
    globalfunctions.h \
    categories_units/units.h \
    math/calculadora.h \
    math/complexdata.h \
    math/complexo.h \
    math/array_math.h \
    categories_dlg.h
FORMS += mainwindow.ui \
    unitsettings.ui \
    categories_dlg.ui

# Please do not modify the following two lines. Required for deployment.
include(deployment.pri)
qtcAddDeployment()
