cmake_minimum_required(VERSION 3.15)
project(test3)


set(CMAKE_CXX_STANDARD 14)

# Указывает CMake запускать MOC когда это необходимо
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
#set_property(SOURCE cmake-build-debug/widget.cpp PROPERTY SKIP_AUTOMOC ON)
# По скольку MOC файлы генерируются в дирекотрии bin, необходимо
# указать CMake включать эти файлы (из этой директории)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Поиск модуля Widgets, которые включает в себя QtGui, QtCore
#find_package(Qt5Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core Gui Widgets Test Concurrent Qml Quick QuickWidgets REQUIRED)

# Qt5Widgets_INCLUDES включает QtCore и QtGui include пути
include_directories(${Qt5Widgets_INCLUDES} ${QtQml_INCLUDE_DIRS})

# Добавляет -DQT_WIDGETS_LIB при использовании QtWidgets в Qt 5.
add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS} ${Qt5Quick_DEFINITIONS})

# Добавление флагов компиляции для Qt проекта
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

set(APP_SRC main.cpp widget.cpp widget.h)

qt5_add_resources(QT_RESOURCES resources/qml.qrc)

# Если в проекте есть UI формы, то необходимо испоользовать эту директиву и перечислить пути к файлам UI форм.
qt5_wrap_ui(UIS_HDRS views/main.ui)
# Указывает какие модули использовать в проекте
#qt5_use_modules(QtCLionTest1 Widgets)

add_executable(test3 ${APP_SRC} ${UIS_HDRS} ${QT_RESOURCES})

target_link_libraries(test3 ${Qt5Widgets_LIBRARIES} Qt5::Test Qt5::Concurrent Qt5::Qml Qt5::Quick Qt5::QuickWidgets)
#target_link_libraries(test3 ${Qt5Widgets_LIBRARIES} Qt5::Qml Qt5::Quick)
