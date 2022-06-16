TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../!includes/queue/queue_test.cpp \
        ../../!includes/stack/stack_test.cpp \
        function.cpp \
        lparen.cpp \
        main.cpp \
        number.cpp \
        operator.cpp \
        rparen.cpp \
        shunting_yard.cpp \
        test_shuntin_yard.cpp \
        token.cpp \
        variable.cpp

HEADERS += \
    ../../!includes/queue/queue.h \
    ../../!includes/queue/queue_test.h \
    ../../!includes/queue/z_queue_output.h \
    ../../!includes/queue/z_queue_work_report.h \
    ../../!includes/stack/stack.h \
    ../../!includes/stack/stack_test.h \
    ../../!includes/stack/z_stack_output.h \
    ../../!includes/stack/z_stack_work_report.h \
    constants.h \
    function.h \
    lparen.h \
    number.h \
    operator.h \
    rparen.h \
    shunting_yard.h \
    test_shuntin_yard.h \
    token.h \
    variable.h \
    z_shunting_yard_output.h \
    z_shunting_yard_work_report.h
