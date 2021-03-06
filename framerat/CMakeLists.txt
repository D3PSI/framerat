file(GLOB_RECURSE BASE_SRC "*.c" "*.cpp" "../external/glad/src/glad.c")

IF(MACOSX_COMPILATION)
    add_library(framerat STATIC ${BASE_SRC})
    target_link_libraries(framerat ${Vulkan_LIBRARIES} ${GLFW3_LIBRARY} ${ASSIMP_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
    add_custom_command(TARGET framerat PRE_BUILD COMMAND rm -rfv ${FRAMERAT_HEADER_DIRECTORY}/* && cp -r ${CMAKE_SOURCE_DIR}/framerat ${FRAMERAT_HEADER_DIRECTORY})
ELSE()
    IF(WIN32)
        add_library(framerat STATIC ${BASE_SRC})
        target_link_libraries(framerat ${Vulkan_LIBRARIES} ${GLFW3_LIBRARY} ${GLM_LIBRARIES} ${ASSIMP_LIBRARIES} ${WINLIBS})
        file(COPY ${CMAKE_SOURCE_DIR}/framerat DESTINATION ${FRAMERAT_HEADER_DIRECTORY}\\)      # TODO
    ELSE(WIN32)
        add_library(framerat STATIC ${BASE_SRC})
        target_link_libraries(framerat stdc++fs dl ${Vulkan_LIBRARIES} ${GLFW3_LIBRARY} ${GLM_LIBRARIES} ${ASSIMP_LIBRARIES} ${XCB_LIBRARIES} ${WAYLAND_CLIENT_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
        add_custom_command(TARGET framerat PRE_BUILD COMMAND rm -rfv ${FRAMERAT_HEADER_DIRECTORY}/* && cp -r ${CMAKE_SOURCE_DIR}/framerat ${FRAMERAT_HEADER_DIRECTORY} && rm -rfv ${FRAMERAT_HEADER_DIRECTORY}/**/*.cpp)
    ENDIF(WIN32)
ENDIF()
