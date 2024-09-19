# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Algorithm_analysis_autogen"
  "CMakeFiles/Algorithm_analysis_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Algorithm_analysis_autogen.dir/ParseCache.txt"
  )
endif()
