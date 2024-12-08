cmake_minimum_required(VERSION 3.15)  # Устанавливаем минимальную версию CMake, необходимую для сборки проекта (3.15)

project(cppcrow-server CXX)  # Определяем имя проекта ("cppcrow-server") и указываем, что проект будет на языке C++

find_package(Crow REQUIRED)  # Находим и подключаем библиотеку Crow, указываем, что она обязательна для сборки (REQUIRED)

add_executable(server src/main.cpp)  # Создаем исполнимый файл "server" из исходного файла src/main.cpp

target_link_libraries(server Crow::Crow)  # Линкуем библиотеку Crow с исполнимым файлом "server"