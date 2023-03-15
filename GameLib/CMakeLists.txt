cmake_minimum_required(VERSION 3.23)
project(GameLib)

set(SOURCE_FILES pch.h MainFrame.cpp MainFrame.h ids.h Game.cpp Game.h GameView.cpp GameView.h PlayingArea.cpp PlayingArea.h Item.cpp Item.h LevelThree.cpp LevelThree.h Level.cpp Level.h Bug.cpp Bug.h NullBug.cpp NullBug.h RedundancyBug.cpp RedundancyBug.h GarbageBug.cpp GarbageBug.h Feature.cpp Feature.h Program.cpp Program.h ScoreBoard.cpp ScoreBoard.h ItemVisitor.cpp ItemVisitor.h)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})