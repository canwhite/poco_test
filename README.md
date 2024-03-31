# poco_test
using of poco 


## env 
1) openSSL
```
brew install openssl
```

2) build Poco
```
$ git clone -b master https://github.com/pocoproject/poco.git
$ cd poco
$ mkdir cmake-build
$ cd cmake-build
$ cmake ..
$ cmake --build . --config Release
$ make install 
```
on Mac , it's necessary to tell CMake where to find the OpenSSL headers and libraries by setting the OPENSSL_ROOT_DIR
```
cmake .. -DOPENSSL_ROOT_DIR=/usr/local/opt/openssl
```

3)using of cmake
```
find_package(Poco REQUIRED 
    Foundation 
    Util 
    Net
)

include_directories(${Poco_INCLUDE_DIRS})

add_definitions(${Poco_DEFINITIONS})

add_executable(${APP_NAME} ${SOURCE_FILES})

target_link_libraries(${APP_NAME} Poco::Foundation Poco::Util Poco::Net)


```

4) c++ standard

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


