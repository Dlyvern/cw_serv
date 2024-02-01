# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/cw_serv_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/cw_serv_autogen.dir/ParseCache.txt"
  "cw_serv_autogen"
  )
endif()
