
cmake_minimum_required(VERSION 3.31)
project(MyDemo VERSION 0.1.0)

add_library(DemoLib INTERFACE)

include(GNUInstallDirs)

target_include_directories(
	DemoLib 
	INTERFACE 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
) 

# 依赖
find_package(OpenSSL REQUIRED)
if(NOT OPENSSL_FOUND)
    message(SEND_ERROR  "OpenSSL not found") 
endif()

target_link_libraries(DemoLib INTERFACE OpenSSL::SSL OpenSSL::Crypto OpenSSL::applink)
if(WIN32)
    target_link_libraries(DemoLib INTERFACE wsock32 ws2_32 crypt32)
endif()

# 测试
enable_testing()
add_subdirectory(test EXCLUDE_FROM_ALL)

# 生成配置文件
include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_NAME}ConfigVersion.cmake"
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY SameMajorVersion)

configure_package_config_file(
	"${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
	"${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
	INSTALL_DESTINATION
	${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)


# 导出目标 
install(TARGETS DemoLib EXPORT ${PROJECT_NAME}_Targets)

install(EXPORT ${PROJECT_NAME}_Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

# 安装复制文件
install(FILES "${PROJECT_SOURCE_DIR}/include/httplib.h" TYPE INCLUDE)

install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
	"${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)








