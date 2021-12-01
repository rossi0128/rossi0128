cmake_minimum_required (VERSION 2.8)
project (cmake_demo)

#set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#aux_source_directory (source SRC_LIST)

set( Service_SRC_LIST
	 ./source/service.c
	 ./source/command.c)
	 
set( Clinet_SRC_LIST
	 ./source/client.c
	 ./source/command.c)
	 
include_directories (include)

add_executable (service.out ${Service_SRC_LIST})
add_executable (client.out ${Clinet_SRC_LIST})