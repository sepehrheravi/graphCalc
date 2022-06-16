TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        my_vector.cpp

HEADERS += \
    ../../!includes/add_entry/add_entry.h \
    ../../!includes/oned/oned.h \
    my_vector.h \
    z_my_vector_output.h \
    z_my_vector_work_report.h
