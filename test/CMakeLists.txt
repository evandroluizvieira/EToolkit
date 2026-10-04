 # This test target uses the local assertion runner in TestAssertions.hpp.
 # It does not use GoogleTest, GoogleMock, FetchContent, or another external
 # test framework. CTest only registers and executes the resulting binary.
add_executable(etoolkit_containers_test
    main.cpp
    StaticArrayTest.cpp
    DynamicArrayTest.cpp
    GeometryTest.cpp
)

target_compile_features(etoolkit_containers_test PRIVATE cxx_std_11)
target_include_directories(etoolkit_containers_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
target_link_libraries(etoolkit_containers_test PRIVATE EToolkit)

add_custom_command(TARGET etoolkit_containers_test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:EToolkit>
        $<TARGET_FILE_DIR:etoolkit_containers_test>
)

add_test(NAME etoolkit_containers_test COMMAND etoolkit_containers_test)