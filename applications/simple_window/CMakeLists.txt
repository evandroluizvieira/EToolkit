add_executable(EToolkitSimpleWindow
    main.cpp
)

target_link_libraries(EToolkitSimpleWindow PRIVATE EToolkit)

target_compile_features(EToolkitSimpleWindow PRIVATE cxx_std_11)

add_custom_command(TARGET EToolkitSimpleWindow POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:EToolkit>
        $<TARGET_FILE_DIR:EToolkitSimpleWindow>
)