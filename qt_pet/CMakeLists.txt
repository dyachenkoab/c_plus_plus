cmake_minimum_required(VERSION 3.15)
project(qt_task_protorype)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD 11)

# Указывает CMake запускать MOC когда это необходимо
set(CMAKE_AUTOMOC ON)

# По скольку MOC файлы генерируются в дирекотрии bin, необходимо
# указать CMake включать эти файлы (из этой директории)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Поиск модуля Widgets, которые включает в себя QtGui, QtCore
find_package(Qt5Widgets REQUIRED)

# Qt5Widgets_INCLUDES включает QtCore и QtGui include пути
include_directories(${Qt5Widgets_INCLUDES})

# Добавляет -DQT_WIDGETS_LIB при использовании QtWidgets в Qt 5.
add_definitions(${Qt5Widgets_DEFINITIONS})

# Добавление флагов компиляции для Qt проекта
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

set(APP_SRC main.cpp task_m.h task_m.cpp)

# Если в проекте есть UI формы, то необходимо испоользовать эту директиву и перечислить пути к файлам UI форм.
qt5_wrap_ui(UIS_HDRS views/main.ui)

# Указывает какие модули использовать в проекте
#qt5_use_modules(QtCLionTest1 Widgets)

add_executable(qt_task_protorype ${APP_SRC} ${UIS_HDRS})

target_link_libraries(qt_task_protorype ${Qt5Widgets_LIBRARIES})