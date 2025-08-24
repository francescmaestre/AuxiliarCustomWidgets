file(GLOB SRC_FILES
    include/*.h
    src/*.cpp
    *.qrc
)

qt_add_resources(
    RESOURCES
    resources.qrc
)

add_library(AuxiliarCustomWidgets STATIC
    ${SRC_FILES}
    ${RESOURCES}
)

target_include_directories(AuxiliarCustomWidgets PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(AuxiliarCustomWidgets
    PUBLIC
    Qt::Core
    Qt::Widgets
    PRIVATE
    QLogger
)
