 # This test target uses the local assertion runner in TestAssertions.hpp.
 # It does not use GoogleTest, GoogleMock, FetchContent, or another external
 # test framework. CTest only registers and executes the resulting binary.
add_executable(etoolkit_tests
    main.cpp
    StaticArrayTest.cpp
    DynamicArrayTest.cpp
    GeometryTest.cpp
)

add_executable(etoolkit_public_api_compatibility
    EColorTest.cpp
)

target_compile_features(etoolkit_tests PRIVATE cxx_std_11)
target_include_directories(etoolkit_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
target_link_libraries(etoolkit_tests PRIVATE EToolkit)
target_compile_features(etoolkit_public_api_compatibility PRIVATE cxx_std_11)
target_include_directories(etoolkit_public_api_compatibility PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
target_link_libraries(etoolkit_public_api_compatibility PRIVATE EToolkit)

add_custom_command(TARGET etoolkit_tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:EToolkit>
        $<TARGET_FILE_DIR:etoolkit_tests>
)

add_custom_command(TARGET etoolkit_public_api_compatibility POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:EToolkit>
        $<TARGET_FILE_DIR:etoolkit_public_api_compatibility>
)

add_test(NAME etoolkit_tests COMMAND etoolkit_tests)
add_test(NAME etoolkit_public_api_compatibility COMMAND etoolkit_public_api_compatibility)