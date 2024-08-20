
get_filename_component(LIB_NAME  ${CMAKE_CURRENT_SOURCE_DIR} NAME_WE)
include_directories(include .)
aux_source_directory(src OBJECT_SRC)

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
find_package(ROOT 6 REQUIRED)
include(${ROOT_USE_FILE})


set(LIB_DICT_NAME ROOT${LIB_NAME})
set(LIB_DICT_CXX ${CMAKE_CURRENT_BINARY_DIR}/${LIB_DICT_NAME}.cxx)
set(LIB_DICT_PCM ${CMAKE_CURRENT_BINARY_DIR}/lib${LIB_DICT_NAME}_rdict.pcm)
set(LIB_DICT_MAP ${CMAKE_CURRENT_BINARY_DIR}/lib${LIB_DICT_NAME}.rootmap)

find_library(LXI_LIBRARY NAMES lxi REQUIRED)
find_path(LXI_HEADER_DIR NAMES lxi.h REQUIRED)


root_generate_dictionary(${LIB_DICT_NAME} ${LXI_HEADER_DIR}/lxi.h LINKDEF include/LinkDef.h)
add_library(${LIB_NAME} SHARED ${OBJECT_SRC} ${LIB_DICT_CXX})
target_link_libraries(${LIB_NAME} ${ROOT_LIBRARIES} ${LXI_LIBRARY})

install(
  TARGETS ${LIB_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  )

install(
  FILES ${LIB_DICT_PCM} ${LIB_DICT_MAP} 
  DESTINATION lib
  )
