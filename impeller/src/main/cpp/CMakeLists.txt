cmake_minimum_required(VERSION 3.22)

project("impeller")

include(FetchContent)

set(IMPELLER_SDK_SHA b7c3af43f90ac9aaf66dbd10b922c25addd9c3db)
set(IMPELLER_PLATFORM android)
set(IMPELLER_ARCH arm64)
set(IMPELLER_DYLIB libimpeller.so)

message(NOTICE "Impeller SDK ${IMPELLER_SDK_SHA} for ${IMPELLER_PLATFORM}-${IMPELLER_ARCH} selected.")

FetchContent_Declare(
        impeller_sdk
        URL https://storage.googleapis.com/flutter_infra_release/flutter/${IMPELLER_SDK_SHA}/${IMPELLER_PLATFORM}-${IMPELLER_ARCH}/impeller_sdk.zip
)
FetchContent_MakeAvailable(impeller_sdk)
add_library(impeller SHARED IMPORTED)

set_target_properties(impeller
        PROPERTIES
        IMPORTED_LOCATION ${impeller_sdk_SOURCE_DIR}/lib/${IMPELLER_DYLIB}
)
target_include_directories(impeller INTERFACE ${impeller_sdk_SOURCE_DIR}/include)
