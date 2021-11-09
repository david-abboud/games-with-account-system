QT+=widgets

SOURCES += main.cpp \
    battleship.cpp \
    button.cpp \
    datahandler.cpp \
    error.cpp \
    game1.cpp \
    mainwidget.cpp \
    player.cpp \
    profilepage.cpp \
    signin.cpp \
    signup.cpp

HEADERS += \
    battleship.h \
    button.h \
    datahandler.h \
    error.h \
    game1.h \
    mainwidget.h \
    player.h \
    profilepage.h \
    signin.h \
    signup.h

DISTFILES += \
    data.json \
    qna.json

RESOURCES += \
    Battleship_images.qrc \
    Flags.qrc \
    ProfilePic1.qrc
