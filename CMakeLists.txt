file(GLOB SRC_FILES
  *.cpp
  *.h
  *.ui
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

set_target_properties(aux_widgets PROPERTIES
    AUTORCC ON
)

target_link_libraries(AuxiliarCustomWidgets
    PUBLIC
    Qt::Core
    Qt::Widgets
    PRIVATE
    QLogger
)
target_include_directories(AuxiliarCustomWidgets PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
