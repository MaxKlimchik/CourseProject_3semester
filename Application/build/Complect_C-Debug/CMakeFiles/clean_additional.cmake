# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SpellCheckService_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SpellCheckService_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\spellcheck_lib_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\spellcheck_lib_autogen.dir\\ParseCache.txt"
  "SpellCheckService_autogen"
  "spellcheck_lib_autogen"
  )
endif()
