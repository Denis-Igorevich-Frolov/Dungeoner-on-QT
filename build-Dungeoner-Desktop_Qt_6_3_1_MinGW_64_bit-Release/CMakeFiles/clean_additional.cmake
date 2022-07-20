# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\Dungeoner_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Dungeoner_autogen.dir\\ParseCache.txt"
  "Dungeoner_autogen"
  )
endif()
