#
# MiaApp template cmake script
#

option(MIA_USE_APP_MIAAPP "Build MiaApp" ON)


# only build the app if the option is set
if(NOT MIA_USE_APP_MIAAPP)
    return()
endif()

message(STATUS "[Mia App] MiaApp")

# List all source files in this directory
file(GLOB APP_SRCS "${CMAKE_CURRENT_LIST_DIR}/*.c")

mia_app_sources(APP_SRCS)
mia_app_build()
