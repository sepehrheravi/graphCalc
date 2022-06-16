TEMPLATE = app
CONFIG += console
#CONFIG -= app_bundle

#since we want to use qDebug, we
#will not subtract qt.
#CONFIG -= qt

CONFIG += c++11
#------------------------------------------
##Add these lines for SFML:



#WINDOWS
# put SFML file in the same location as project
#LIBS += -L"..\..\SFML-2.0\lib" #change this
#LIBS += -L"..\..\SFML-2.0\bin" #change this

#MAC
LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
#INCLUDEPATH += "..\..\SFML-2.0\include" #change this
#DEPENDPATH  += "..\..\SFML-2.0\include" #change this

#MAC
INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"

#-----------------------------------------

SOURCES += main.cpp \
    ../../shunting_yard/shunting_yard/function.cpp \
    ../../shunting_yard/shunting_yard/lparen.cpp \
    ../../shunting_yard/shunting_yard/number.cpp \
    ../../shunting_yard/shunting_yard/operator.cpp \
    ../../shunting_yard/shunting_yard/rparen.cpp \
    ../../shunting_yard/shunting_yard/shunting_yard.cpp \
    ../../shunting_yard/shunting_yard/token.cpp \
    ../../shunting_yard/shunting_yard/variable.cpp \
    coord_translator.cpp \
    graph.cpp \
    graph_info.cpp \
    plot.cpp \
    rpn.cpp \
    system.cpp \
    sidebar.cpp \
    animate.cpp \
    tokenize.cpp


HEADERS += \
    ../../!includes/queue/queue.h \
    ../../!includes/stack/stack.h \
    ../../my_vector/my_vector/my_vector.h \
    ../../shunting_yard/shunting_yard/constants.h \
    ../../shunting_yard/shunting_yard/function.h \
    ../../shunting_yard/shunting_yard/lparen.h \
    ../../shunting_yard/shunting_yard/number.h \
    ../../shunting_yard/shunting_yard/operator.h \
    ../../shunting_yard/shunting_yard/rparen.h \
    ../../shunting_yard/shunting_yard/shunting_yard.h \
    ../../shunting_yard/shunting_yard/token.h \
    ../../shunting_yard/shunting_yard/variable.h \
    constants.h \
    coord_translator.h \
    graph.h \
    graph_info.h \
    plot.h \
    rpn.h \
    system.h \
    sidebar.h \
    animate.h \
    tokenize.h \
    z_graph_calc_work_report.h
