# Use the local assertion runner. CTest only registers and launches the binary.
# Automatically include every C++ translation unit in this test directory.
file(GLOB ETOOLKIT_TEST_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(etoolkit_tests ${ETOOLKIT_TEST_SOURCES})
target_compile_features(etoolkit_tests PRIVATE cxx_std_11)
target_include_directories(etoolkit_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
target_link_libraries(etoolkit_tests PRIVATE EToolkit)

# Keep the shared library beside the test executable at runtime.
if(ETOOLKIT_BUILD_SHARED_LIBRARY)
    add_custom_command(TARGET etoolkit_tests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:EToolkit>
            $<TARGET_FILE_DIR:etoolkit_tests>
    )
endif()

add_test(NAME etoolkit_tests COMMAND etoolkit_tests)
