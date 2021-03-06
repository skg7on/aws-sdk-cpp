project(aws-cpp-sdk-kms)

  file(GLOB AWS_KMS_HEADERS
    "include/aws/kms/*.h"
  )

  file(GLOB AWS_KMS_MODEL_HEADERS
    "include/aws/kms/model/*.h"
  )

  file(GLOB AWS_KMS_SOURCE
    "source/*.cpp"
  )

  file(GLOB AWS_KMS_MODEL_SOURCE
    "source/model/*.cpp"
  )

  file(GLOB KMS_UNIFIED_HEADERS
    ${AWS_KMS_HEADERS}
    ${AWS_KMS_MODEL_HEADERS}
  )

  file(GLOB KMS_UNITY_SRC
    ${AWS_KMS_SOURCE}
    ${AWS_KMS_MODEL_SOURCE}
  )

  if(ENABLE_UNITY_BUILD)
    enable_unity_build("KMS" KMS_UNITY_SRC)
  endif()

  file(GLOB KMS_SRC
    ${KMS_UNIFIED_HEADERS}
    ${KMS_UNITY_SRC}
  )

  if(WIN32)
    #if we are compiling for visual studio, create a sane directory tree.
    if(MSVC)
      source_group("Header Files\\aws\\kms" FILES ${AWS_KMS_HEADERS})
      source_group("Header Files\\aws\\kms\\model" FILES ${AWS_KMS_MODEL_HEADERS})
      source_group("Source Files" FILES ${AWS_KMS_SOURCE})
      source_group("Source Files\\model" FILES ${AWS_KMS_MODEL_SOURCE})
    endif(MSVC)
  endif()

  set(KMS_INCLUDES
    "${CMAKE_CURRENT_SOURCE_DIR}/include/"
    "${CORE_DIR}/include/"
  )

  include_directories(${KMS_INCLUDES})

  if(USE_WINDOWS_DLL_SEMANTICS AND BUILD_SHARED_LIBS)
    add_definitions("-DAWS_KMS_EXPORTS")
  endif()

  add_library(aws-cpp-sdk-kms ${LIBTYPE} ${KMS_SRC})

  target_include_directories(aws-cpp-sdk-kms PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
  
  target_link_libraries(aws-cpp-sdk-kms aws-cpp-sdk-core)

  if(SIMPLE_INSTALL)
      install (TARGETS aws-cpp-sdk-kms
               ARCHIVE DESTINATION ${ARCHIVE_DIRECTORY}
               LIBRARY DESTINATION lib
               RUNTIME DESTINATION bin)
  else()
    if(PLATFORM_CUSTOM)
      install_custom_library(aws-cpp-sdk-kms)
    else()
      install (TARGETS aws-cpp-sdk-kms
               ARCHIVE DESTINATION ${ARCHIVE_DIRECTORY}/${SDK_INSTALL_BINARY_PREFIX}/${PLATFORM_INSTALL_QUALIFIER}/\${CMAKE_INSTALL_CONFIG_NAME}
               LIBRARY DESTINATION lib/${SDK_INSTALL_BINARY_PREFIX}/${PLATFORM_INSTALL_QUALIFIER}/\${CMAKE_INSTALL_CONFIG_NAME}
               RUNTIME DESTINATION bin/${SDK_INSTALL_BINARY_PREFIX}/${PLATFORM_INSTALL_QUALIFIER}/\${CMAKE_INSTALL_CONFIG_NAME})
    endif()
  endif()

  install (FILES ${AWS_KMS_HEADERS} DESTINATION include/aws/kms)
  install (FILES ${AWS_KMS_MODEL_HEADERS} DESTINATION include/aws/kms/model)

  if(PLATFORM_WINDOWS AND MSVC)
    install (FILES nuget/aws-cpp-sdk-kms.autopkg DESTINATION nuget)
  endif()



