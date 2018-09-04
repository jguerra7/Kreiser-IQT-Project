

set(command "C:/Program Files/CMake/bin/cmake.exe;-P;C:/Users/Eric/Projects/BasicDeveloper/bd_checkride_v1/CPP/catch/tmp/catch-gitclone.cmake")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "C:/Users/Eric/Projects/BasicDeveloper/bd_checkride_v1/CPP/catch/src/catch-stamp/catch-download-out.log"
  ERROR_FILE "C:/Users/Eric/Projects/BasicDeveloper/bd_checkride_v1/CPP/catch/src/catch-stamp/catch-download-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  C:/Users/Eric/Projects/BasicDeveloper/bd_checkride_v1/CPP/catch/src/catch-stamp/catch-download-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "catch download command succeeded.  See also C:/Users/Eric/Projects/BasicDeveloper/bd_checkride_v1/CPP/catch/src/catch-stamp/catch-download-*.log")
  message(STATUS "${msg}")
endif()
