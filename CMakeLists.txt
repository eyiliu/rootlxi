cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(rootlxi VERSION 1.0.0 LANGUAGES CXX)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/INSTALL CACHE PATH "Default prefix of install directories" FORCE)
endif()

set(CMAKE_CXX_STANDARD 17)
  
set(CMAKE_THREAD_PREFER_PTHREAD ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


add_subdirectory(source)

# install(TARGETS target_name_list
#   RUNTIME       DESTINATION bin      COMPONENT runtime
#   LIBRARY       DESTINATION lib      COMPONENT runtime
#   ARCHIVE       DESTINATION lib      COMPONENT devel
#   PUBLIC_HEADER DESTINATION include  COMPONENT devel
#   RESOURCE      DESTINATION resource COMPONENT runtime
#   )


install(CODE "MESSAGE(\"project is installed in ${CMAKE_INSTALL_PREFIX} .\")")
