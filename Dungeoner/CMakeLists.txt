cmake_minimum_required(VERSION 3.5)

project(Dungeoner VERSION 0.1 LANGUAGES CXX)

enable_testing(true)

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
        CustomWidgets/PrimarySkillSignature/primaryskillsignature.h
        CustomWidgets/PrimarySkillSignature/primaryskillsignature.cpp
        CustomWidgets/PrimarySkillSignature/primaryskillsignature.ui
        Resources/Textures.qrc
        CustomWidgets/PrimarySkillSignature/PSS_stylemaster.h
        CustomWidgets/PrimarySkillSignature/PSS_stylemaster.cpp
        Resources/Fonts.qrc
        Windows/CharacterWindow/characterwindow.h
        Windows/CharacterWindow/characterwindow.cpp
        Windows/CharacterWindow/characterwindow.ui
        CustomWidgets/LabelWithTooltip/labelwithtooltip.h
        CustomWidgets/LabelWithTooltip/labelwithtooltip.cpp
        CustomWidgets/LabelWithTooltip/labelwithtooltip.ui
        CustomWidgets/LabelWithTooltip/LWT_stylemaster.h
        CustomWidgets/LabelWithTooltip/LWT_stylemaster.cpp
        Windows/CharacterWindow/CW_stylemaster.h
        Windows/CharacterWindow/CW_stylemaster.cpp
        Resources/Sounds.qrc
        MediaPlayer/mediaplayer.h
        MediaPlayer/mediaplayer.cpp
        Global/global.h
        Global/global.cpp
        CustomWidgets/WindowBorder_1/windowborder_1.h
        CustomWidgets/WindowBorder_1/windowborder_1.cpp
        CustomWidgets/WindowBorder_1/windowborder_1.ui
        CustomWidgets/WindowBorder_1/WB1_stylemaster.h
        CustomWidgets/WindowBorder_1/WB1_stylemaster.cpp
        CustomWidgets/SecondarySkill/secondaryskill.h
        CustomWidgets/SecondarySkill/secondaryskill.cpp
        CustomWidgets/SecondarySkill/secondaryskill.ui
        CustomWidgets/SecondarySkill/SS_stylemaster.h
        CustomWidgets/SecondarySkill/SS_stylemaster.cpp
        System/TooltipDisplayEvents/tooltipdisplayevents.h
        System/TooltipDisplayEvents/tooltipdisplayevents.cpp
        CustomWidgets/ProgressBar_1/progressbar_1.h
        CustomWidgets/ProgressBar_1/progressbar_1.cpp
        CustomWidgets/ProgressBar_1/progressbar_1.ui
        CustomWidgets/ProgressBar_1/PB1_stylemaster.h
        CustomWidgets/ProgressBar_1/PB1_stylemaster.cpp
        System/OutlineEffect/outlineeffect.h
        System/OutlineEffect/outlineeffect.cpp
        CustomWidgets/SecondarySkillProgressBar/secondaryskillprogressbar.h
        CustomWidgets/SecondarySkillProgressBar/secondaryskillprogressbar.cpp
        CustomWidgets/SecondarySkillProgressBar/secondaryskillprogressbar.ui
        CustomWidgets/SecondarySkillProgressBar/SSPB_stylemaster.h
        CustomWidgets/SecondarySkillProgressBar/SSPB_stylemaster.cpp
        CustomWidgets/ProgressBar_2/progressbar_2.h
        CustomWidgets/ProgressBar_2/progressbar_2.cpp
        CustomWidgets/ProgressBar_2/progressbar_2.ui
        CustomWidgets/ProgressBar_2/PB2_stylemaster.h
        CustomWidgets/ProgressBar_2/PB2_stylemaster.cpp
        Person/MagicDefense/chunk.h
        Person/MagicDefense/chunk.cpp
        CustomWidgets/MagicDefenseProgressBar/magicdefenseprogressbar.h
        CustomWidgets/MagicDefenseProgressBar/magicdefenseprogressbar.cpp
        CustomWidgets/MagicDefenseProgressBar/magicdefenseprogressbar.ui
        CustomWidgets/MagicDefenseProgressBar/MDP_stylemaster.h
        CustomWidgets/MagicDefenseProgressBar/MDP_stylemaster.cpp
        CustomWidgets/Tooltip/tooltip.h
        CustomWidgets/Tooltip/tooltip.cpp
        CustomWidgets/Tooltip/tooltip.ui
        CustomWidgets/Tooltip/T_stylemaster.h
        CustomWidgets/Tooltip/T_stylemaster.cpp
        CustomWidgets/WindowBorder_2/windowborder_2.h
        CustomWidgets/WindowBorder_2/windowborder_2.cpp
        CustomWidgets/WindowBorder_2/windowborder_2.ui
        CustomWidgets/WindowBorder_2/WB2_stylemaster.h
        CustomWidgets/WindowBorder_2/WB2_stylemaster.cpp
        Person/Stat/bonus.h
        Person/Stat/bonus.cpp
        Person/Stat/stat.h
        Person/Stat/stat.cpp
        Person/person.h
        Person/person.cpp
        Person/MagicDefense/magicdefense.h
        Person/MagicDefense/magicdefense.cpp
        Person/MagicDefense/magicdefensebonus.h
        Person/MagicDefense/magicdefensebonus.cpp
        CustomWidgets/InventoryCell/inventorycell.h
        CustomWidgets/InventoryCell/inventorycell.cpp
        CustomWidgets/InventoryCell/inventorycell.ui
        Resources/Gifs.qrc
        CustomWidgets/InventoryCell/IC_stylemaster.h
        CustomWidgets/InventoryCell/IC_stylemaster.cpp
        CustomWidgets/Item/item.h
        CustomWidgets/Item/item.cpp
        CustomWidgets/Item/item.ui
        CustomWidgets/Item/I_stylemaster.h
        CustomWidgets/Item/I_stylemaster.cpp
        System/UnitTests/SecondarySkillsTest/secondarySkillsTest.h
        System/UnitTests/SecondarySkillsTest/secondarySkillsTest.cpp
        Person/SecondaryStat/secondarystat.h
        Person/SecondaryStat/secondarystat.cpp
        CustomWidgets/FPS_Counter/fps_counter.h
        CustomWidgets/FPS_Counter/fps_counter.cpp
        CustomWidgets/FPS_Counter/fps_counter.ui
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

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)
target_link_libraries(Dungeoner PRIVATE Qt${QT_VERSION_MAJOR}::Test)

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Multimedia)
target_link_libraries(Dungeoner PRIVATE Qt${QT_VERSION_MAJOR}::Multimedia)

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)
target_link_libraries(Dungeoner PRIVATE Qt${QT_VERSION_MAJOR}::Sql)
