

set(command "/Applications/CLion.app/Contents/bin/cmake/bin/cmake;-P;/Users/aaron/ClionProjects/CppTest/catch/tmp/catch-gitclone.cmake")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/Users/aaron/ClionProjects/CppTest/catch/src/catch-stamp/catch-download-out.log"
  ERROR_FILE "/Users/aaron/ClionProjects/CppTest/catch/src/catch-stamp/catch-download-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /Users/aaron/ClionProjects/CppTest/catch/src/catch-stamp/catch-download-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "catch download command succeeded.  See also /Users/aaron/ClionProjects/CppTest/catch/src/catch-stamp/catch-download-*.log")
  message(STATUS "${msg}")
endif()
