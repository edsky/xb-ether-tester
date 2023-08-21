cmake_minimum_required(VERSION 3.11) # Updated for FetchContent

project(xb_ether_tester)

# Set the base directory for all content fetched with FetchContent
set(FETCHCONTENT_BASE_DIR "${CMAKE_BINARY_DIR}/deps")

# Download WpdPack
include(FetchContent)
FetchContent_Declare(
    WpdPack
    URL http://www.winpcap.org/install/bin/WpdPack_4_1_2.zip
)
FetchContent_GetProperties(WpdPack)
if(NOT WpdPack_POPULATED)
    FetchContent_Populate(WpdPack)
    set(WpdPack_SOURCE_DIR "${CMAKE_BINARY_DIR}/_deps/WpdPack-src")
    set(WPCAP_INCLUDE_DIR "${WpdPack_SOURCE_DIR}/Include")
    set(WPCAP_LIBRARY_DIR "${WpdPack_SOURCE_DIR}/Lib")
endif()

message(STATUS "WPCAP_INCLUDE_DIR: ${WPCAP_INCLUDE_DIR}")
message(STATUS "WPCAP_LIBRARY_DIR: ${WPCAP_LIBRARY_DIR}")


# Set the output to be a Win32 window application
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")

# Compiler flags
add_definitions(-DBUILD_TIME='"${CMAKE_BUILD_TIME}"')
add_definitions(-DWIN32_LEAN_AND_MEAN -DHAVE_REMOTE -DWPCAP)

link_directories(${WPCAP_LIBRARY_DIR})

# Source files
set(SOURCE_FILES
    src/main.c
    src/frame_window.c
    src/left_window.c
    src/right_window.c
    src/bottom_window.c
    src/splitters.c
    src/toolbar_statusbar.c
    src/tip_window.c
    src/hex_edit_window.c
    src/packets_rx_tx.c
    src/stats_window.c
    src/stream_edit_dlg.c
    src/net.c
    src/history.c
    src/common.c
    src/gui.c
    src/ver_update.c
    src/debug.c
    src/sample_pkts.c
    src/linux_tm.c
)

# Include directories
include_directories(${WPCAP_INCLUDE_DIR})
include_directories(inc)
include_directories(res)

# Target executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES} res/sample.rc)

# Linking libraries
target_link_libraries(${PROJECT_NAME}
    kernel32
    user32
    gdi32
    comctl32
    ws2_32
    wininet
    iphlpapi
    Winmm
    wpcap
    shell32
)

# # Post build commands to copy files (similar to your Makefile)
# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/profile.ini $<TARGET_FILE_DIR:${PROJECT_NAME}>
#     COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/version_update.ini $<TARGET_FILE_DIR:${PROJECT_NAME}>
# )

# # Installer (for NSIS)
# set(CPACK_GENERATOR "NSIS")
# set(CPACK_PACKAGE_FILE_NAME "xb_ether_tester")
# include(CPack)
