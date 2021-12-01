cmake_minimum_required (VERSION 2.8)
project (tipc_demo)

#set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#aux_source_directory (source SRC_LIST)

set( Service_SRC_LIST
	 ./source/server_tipc.c)
	 
set( Clinet_SRC_LIST
	 ./source/client_tipc.c)
	 
include_directories (include)

add_executable (server_tipc.out ${Service_SRC_LIST})
add_executable (client_tipc.out ${Clinet_SRC_LIST})
