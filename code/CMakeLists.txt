#macro SUBDIR_LIST from https://stackoverflow.com/questions/7787823/cmake-how-to-get-the-name-of-all-subdirectories-of-a-directory
macro(SUBDIR_LIST result curdir)
    file(GLOB children RELATIVE ${curdir} ${curdir}/*)
    set(dirlist "")
    foreach (child ${children})
        if (IS_DIRECTORY ${curdir}/${child})
            list(APPEND dirlist ${child})
        endif ()
    endforeach ()
    set(${result} ${dirlist})
endmacro()

SUBDIR_LIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

foreach (subdir ${SUBDIRS})
    add_subdirectory(${subdir})
endforeach ()
