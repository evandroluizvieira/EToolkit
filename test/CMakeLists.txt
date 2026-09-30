 # This test target uses the local assertion runner in TestAssertions.hpp.
 # It does not use GoogleTest, GoogleMock, FetchContent, or another external
 # test framework. CTest only registers and executes the resulting binary.
add_executable(etoolkit_containers_test
    main.cpp
    StaticArrayTest.cpp
    DynamicArrayTest.cpp
    ../source/exceptions/EException.cpp
    ../source/exceptions/EExceptionPrivate.cpp
    ../source/exceptions/EOutOfBoundsException.cpp
    ../source/exceptions/EMemoryAllocationException.cpp
    ../source/string/EString.cpp
    ../source/string/EStringPrivate.cpp
    ../source/string/ECString.cpp
)

target_compile_features(etoolkit_containers_test PRIVATE cxx_std_11)
target_compile_definitions(etoolkit_containers_test PRIVATE ETOOLKIT_EXPORT)
target_include_directories(etoolkit_containers_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

add_test(NAME etoolkit_containers_test COMMAND etoolkit_containers_test)