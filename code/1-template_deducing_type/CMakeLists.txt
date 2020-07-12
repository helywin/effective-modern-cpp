file(GLOB SRCS
        ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        )
add_executable(template_type_deducing ${SRCS})
target_include_directories(template_type_deducing PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(template_type_deducing ${Boost_LIBRARIES})
