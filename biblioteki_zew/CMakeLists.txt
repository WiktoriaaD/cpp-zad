cmake_minimum_required(VERSION 3.10)
project(PrzykladPkgConfig)

# W systemie musi być zainstalowana paczka pkgconf (polecenie pkg-config w terminalu)
find_package(PkgConfig REQUIRED)

# Pierwszy argument (GTK) to prefiks zmiennych, które zostaną utworzone
# Ostatni argument to nazwa biblioteki (np. gtk+-3.0, sqlite, itp)
pkg_check_modules(CURL REQUIRED libcurl)

# Zmienna ${GTK_INCLUDE_DIRS} zawiera ścieżki do nagłówków biblioteki
# W ten sposób będą one widoczne dla kompilatora w dyrektywach preprocesora #include <...>
# Odpowiednik polecenia w terminalu: pkg-config --cflags gtk+-3.0
include_directories(${CURL_INCLUDE_DIRS})

# Zmienna ${GTK_LIBRARY_DIRS} zawiera ścieżki do skompilowanych bibliotek (dla linkera)
link_directories(${CURL_LIBRARY_DIRS})

# Zmienna ${GTK_CFLAGS_OTHER} ewentualne dodatkowe zawiera flagi dla kompilatora
add_definitions(${CURL_CFLAGS_OTHER})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")

set(SOURCE_FILES
    main.cpp)
    
add_executable(przyklad_pkg_config ${SOURCE_FILES})

# Zmienna ${GTK_LIBRARIES} zawiera parametry z nazwami bibliotek do linkera (np. -lm)
# Odpowiednik polecenia w terminalu: pkg-config --libs gtk+-3.0
target_link_libraries(przyklad_pkg_config ${CURL_LIBRARIES})