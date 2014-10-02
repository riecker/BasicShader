set(CMAKE_AUTOMOC ON)
project(ProjectS)

FIND_PACKAGE(Qt4 COMPONENTS QtCore QtGui QtOpenGL REQUIRED)
INCLUDE(${QT_USE_FILE})

qt4_wrap_ui(./mainwindow.ui)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR} .)

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

cmake_minimum_required(VERSION 2.8)

aux_source_directory(. SRC_LIST)
ADD_EXECUTABLE(${PROJECT_NAME} ${SRC_LIST} ${PROJECTS_UIS_HDRS} )

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${QT_LIBRARIES})

#old stinky stuff !!!
#SET(QT_USE_QTOPENGL TRUE)
#SET(LIBRARIES ${LIBRARIES} ${QT_LIBRARIES})
#qt4_wrap_cpp(MOC_SOURCES ${MOC_HEADERS})
#qt4_wrap_ui(PROJECTS_UIS_HDRS ${PROJECTS_UIS} )
#qt4_wrap_cpp(HEADERS_MOC ${HEADERS})
#qt4_wrap_ui(FORMS_HEADERS ${FORMS})
#qt4_add_resources(RESOURCES_RCC ${RESOURCES})
