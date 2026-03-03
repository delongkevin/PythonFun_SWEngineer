# # Git executable is extracted from parameters.
execute_process(COMMAND bash -c "bash ${CMAKE_CURRENT_SOURCE_DIR}/cmake/version_gen.sh" WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# # Input and output files are extracted from parameters.