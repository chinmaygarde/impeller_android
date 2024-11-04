cmake_minimum_required(VERSION 3.22.1)
set(CMAKE_CXX_STANDARD 17)

project(impeller)

include(FetchContent)

# Import the Impeller SDK.
set(IMPELLER_SDK_SHA b7c3af43f90ac9aaf66dbd10b922c25addd9c3db)
set(IMPELLER_PLATFORM android)
set(IMPELLER_ARCH arm64)
set(IMPELLER_DYLIB libimpeller.so)

message(NOTICE "Impeller SDK ${IMPELLER_SDK_SHA} for ${IMPELLER_PLATFORM}-${IMPELLER_ARCH} selected. Copying ${IMPELLER_DYLIB}.")

FetchContent_Declare(
  impeller_sdk
  URL https://storage.googleapis.com/flutter_infra_release/flutter/${IMPELLER_SDK_SHA}/${IMPELLER_PLATFORM}-${IMPELLER_ARCH}/impeller_sdk.zip
)
FetchContent_MakeAvailable(impeller_sdk)

# Prepare a synthetic library that exports libimpeller.so.
add_library(impeller SHARED IMPORTED GLOBAL)
set_target_properties(impeller
  PROPERTIES
  IMPORTED_LOCATION ${impeller_sdk_SOURCE_DIR}/lib/${IMPELLER_DYLIB}
)
target_include_directories(impeller INTERFACE ${impeller_sdk_SOURCE_DIR}/include)
include_directories(${impeller_sdk_SOURCE_DIR}/include)

# Prepare the glue library.
add_library(impeller_glue SHARED
  impeller_glue.cc
)
target_link_libraries(impeller_glue impeller log android EGL)
