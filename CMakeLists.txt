include_directories(.)

aux_source_directory(mozart++ SRCS)
aux_source_directory(src SRCS_IMPL)

add_library(mpp_core STATIC
        ${SRCS}
        ${SRCS_IMPL}
        )

set_target_properties(mpp_core PROPERTIES LINKER_LANGUAGE CXX)


## test and benchmark targets here
file(GLOB_RECURSE CPP_SRC_LIST tests/test-*.cpp)
foreach(v ${CPP_SRC_LIST})
    string(REGEX MATCH "tests/.*" relative_path ${v})
    string(REGEX REPLACE "tests/" "" target_name ${relative_path})
    string(REGEX REPLACE ".cpp" "" target_name ${target_name})

    add_executable(mpp_core-${target_name} ${v})
    target_link_libraries(mpp_core-${target_name} mpp_core)
    add_test(mpp_core-${target_name} mpp_core-${target_name})
endforeach()
