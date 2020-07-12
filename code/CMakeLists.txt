#macro SUBDIR_LIST from https://stackoverflow.com/questions/7787823/cmake-how-to-get-the-name-of-all-subdirectories-of-a-directory
macro(SUBDIR_LIST result CURRENT_FOLDER)
    file(GLOB children RELATIVE ${CURRENT_FOLDER} ${CURRENT_FOLDER}/*)
    set(dirlist "")
    foreach (child ${children})
        if (IS_DIRECTORY ${CURRENT_FOLDER}/${child})
            list(APPEND dirlist ${child})
        endif ()
    endforeach ()
    set(${result} ${dirlist})
endmacro()

macro(SUB_PROJECT)
    string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
    project(${CURRENT_FOLDER})
    file(GLOB SRCS
            ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
            )
    add_executable(${PROJECT_NAME} ${SRCS})
endmacro()

SUBDIR_LIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

foreach (subdir ${SUBDIRS})
    add_subdirectory(${subdir})
endforeach ()
