function(add_app_test test_name test_source)
    add_executable(${test_name} ${test_source})
    target_link_libraries(${test_name}
        PRIVATE
            app_components
            gtest
            gtest_main
    )
    add_test(NAME ${test_name} COMMAND ${test_name})
endfunction()

# UNIT Tests
add_app_test(matrix_tests unit/core/MatrixTests.cpp)
add_app_test(vector_tests unit/core/Vector3DTests.cpp)
add_app_test(quaternion_tests unit/core/QuaternionTests.cpp)
