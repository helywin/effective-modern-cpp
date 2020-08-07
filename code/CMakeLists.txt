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

SUBDIR_LIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

foreach (subdir ${SUBDIRS})
    string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${subdir})
    file(GLOB SRCS
            ${subdir}/*.hpp
            ${subdir}/*.cpp
            )
    add_executable(${CURRENT_FOLDER} ${SRCS})
endforeach ()
