#
# ChristmasBakery cmake script
#

option(MIA_USE_APP_CHRISTMASBAKERY "Build ChristmasBakery" ON)


# only build the app if the option is set
if(NOT MIA_USE_APP_CHRISTMASBAKERY)
    return()
endif()

message(STATUS "[Mia App] ChristmasBakery")

# List all source files in this directory
file(GLOB APP_SRCS "${CMAKE_CURRENT_LIST_DIR}/*.c")

mia_app_sources(APP_SRCS)
mia_app_build()
