set(LIB_NAMES Physika_Core )

foreach(LIB_NAME IN ITEMS ${LIB_NAMES})
    set(LIB_SRC_DIR "${PROJECT_SOURCE_DIR}/Physika_Src/${LIB_NAME}")

    file(                                                                           #利用glob命令读取所有源文件list
            GLOB_RECURSE LIB_SRC
            LIST_DIRECTORIES false
            CONFIGURE_DEPENDS
            "${LIB_SRC_DIR}/*.c*"
            "${LIB_SRC_DIR}/*.h*"
            )

    list(FILTER LIB_SRC EXCLUDE REGEX .*deprecated/.*)                              #排除deprecated 目录下面的所有文件

    if(LIB_NAME STREQUAL "Physika_Core")                                            #特殊处理 把stackWalker tinyxml2 lodepng3个源文件编如core模块
        #list(APPEND LIB_SRC "${PROJECT_SOURCE_DIR}/Extern/StackWalker/StackWalker.cpp")#StackWalker is only available on windows. By czn
        list(APPEND LIB_SRC "${PROJECT_SOURCE_DIR}/Extern/tinyxml/tinyxml2.cpp")
        list(APPEND LIB_SRC "${PROJECT_SOURCE_DIR}/Extern/LodePNG/lodepng.cpp")
    endif()


    add_library(${LIB_NAME} STATIC ${LIB_SRC})                                      #添加编译目标 静态链接库

    foreach(SRC IN ITEMS ${LIB_SRC})                                                #为VS工程添加filter 方便查看文件结构目录
        get_filename_component(SRC_PATH "${SRC}" PATH)
        file(RELATIVE_PATH SRC_PATH_REL "${LIB_SRC_DIR}" "${SRC_PATH}")
        string(REPLACE "/" "\\" GROUP_PATH "${SRC_PATH_REL}")
        source_group("${GROUP_PATH}" FILES "${SRC}")
    endforeach()

    #target_compile_options(${LIB_NAME} PRIVATE -Xcompiler "/wd 4819")               #禁止编译时报告文件编码不是unicode的warning，由于cuda头文件都不是unicode。使编译报错更清晰
    file(RELATIVE_PATH PROJECT_PATH_REL "${PROJECT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")                 #判断当前project在根目录下的相对路径
    set_target_properties(${LIB_NAME} PROPERTIES FOLDER "${PROJECT_PATH_REL}")      #为project设定folder目录
    set_target_properties(${LIB_NAME} PROPERTIES CUDA_RESOLVE_DEVICE_SYMBOLS ON)    #cmake 会自动延迟cuda dlink操作直到静态库被编译成动态库或者exe，
    #但这样影响了后面其他工程对PhysLeo.lib的引用，现在还有些原因未明，暂时在编译成库之前开启dlink
endforeach()

add_subdirectory(Physika_Cloud)
