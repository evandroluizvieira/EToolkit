# Each immediate subdirectory containing C++ sources defines one application.
# Add an application by creating a folder here with its .cpp and .hpp files.
file(GLOB ETOOLKIT_APPLICATION_DIRECTORIES CONFIGURE_DEPENDS
	"${CMAKE_CURRENT_SOURCE_DIR}/*"
)

foreach(application_directory ${ETOOLKIT_APPLICATION_DIRECTORIES})
	if(IS_DIRECTORY "${application_directory}")
		get_filename_component(application_name "${application_directory}" NAME)
		file(GLOB_RECURSE application_sources CONFIGURE_DEPENDS
			"${application_directory}/*.cpp"
		)

		if(application_sources)
			set(application_target "EToolkit_${application_name}")
			add_executable(${application_target} ${application_sources})
			target_compile_features(${application_target} PRIVATE cxx_std_11)
			target_include_directories(${application_target} PRIVATE
				"${application_directory}"
				"${CMAKE_CURRENT_SOURCE_DIR}/../include"
			)
			target_link_libraries(${application_target} PRIVATE EToolkit)
			set_target_properties(${application_target} PROPERTIES
				RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/applications/${application_name}"
			)
			if(ETOOLKIT_BUILD_SHARED_LIBRARY)
				add_custom_command(TARGET ${application_target} POST_BUILD
					COMMAND ${CMAKE_COMMAND} -E copy_if_different
						$<TARGET_FILE:EToolkit>
						$<TARGET_FILE_DIR:${application_target}>
				)
			endif()
		endif()
	endif()
endforeach()
