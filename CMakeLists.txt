file(GLOB SRC_FILES
  *.cpp
  *.h
  *.ui
  *.qrc
)


add_library(AuxiliarCustomWidgets STATIC
    ${SRC_FILES}
)

target_link_libraries(AuxiliarCustomWidgets
    PUBLIC
    Qt::Core
    Qt::Widgets
    QLogger
)
target_include_directories(AuxiliarCustomWidgets PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
