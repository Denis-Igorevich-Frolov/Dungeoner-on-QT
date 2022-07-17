cmake_minimum_required(VERSION 3.5)

project(Dungeoner VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        dungeoner.cpp
        dungeoner.h
        dungeoner.ui
        CustomWidget/PrimarySkillSignature/primaryskillsignature.h
        CustomWidget/PrimarySkillSignature/primaryskillsignature.cpp
        CustomWidget/PrimarySkillSignature/primaryskillsignature.ui
        Resources/Textures.qrc
        CustomWidget/PrimarySkillSignature/stylemaster.h
        CustomWidget/PrimarySkillSignature/stylemaster.cpp
        Resources/Fonts.qrc
        Windows/CharacterWindow/characterwindow.h
        Windows/CharacterWindow/characterwindow.cpp
        Windows/CharacterWindow/characterwindow.ui
        CustomWidget/LabelWithTooltip/labelwithtooltip.h
        CustomWidget/LabelWithTooltip/labelwithtooltip.cpp
        CustomWidget/LabelWithTooltip/labelwithtooltip.ui
        CustomWidget/LabelWithTooltip/stylemaster.h
        CustomWidget/LabelWithTooltip/stylemaster.cpp
        Windows/CharacterWindow/stylemaster.h
        Windows/CharacterWindow/stylemaster.cpp
        Resources/Sounds.qrc
        MediaPlayer/mediaplayer.h MediaPlayer/mediaplayer.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Dungeoner
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Dungeoner APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Dungeoner SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Dungeoner
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Dungeoner PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Dungeoner PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Dungeoner)
endif()

find_package(Qt6 REQUIRED COMPONENTS Multimedia)
target_link_libraries(Dungeoner PRIVATE Qt${QT_VERSION_MAJOR}::Multimedia)
