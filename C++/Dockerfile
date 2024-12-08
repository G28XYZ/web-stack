# Используем последний образ Alpine Linux как базовый для создания контейнера
FROM alpine:latest

# Обновляем пакеты и устанавливаем необходимые зависимости
RUN \
    # Обновляем список пакетов
    apk update \                
    # Обновляем все установленные пакеты
    && apk upgrade \            
    # Устанавливаем необходимые пакеты без использования кэша
    && apk add --no-cache \     
    # Библиотека стандартных C++-классов
    libstdc++ \                 
    # Разработческая версия библиотеки Boost
    boost-dev \                 
    # Разработческая версия OpenSSL
    openssl-dev \               
    # Разработческая версия библиотеки zlib
    zlib-dev \                  
    # Компилятор GCC
    gcc \                       
    # Компилятор G++
    g++ \                       
    # Утилита для работы с URL
    curl \                      
    # Текстовый редактор vim
    vim \                       
    # Bash shell
    bash \                      
    # Утилита для сборки проектов
    cmake \                     
    # Утилита для сборки программ
    make \                      
    # Интерпретатор Python 3
    python3 \                   
    # Утилита pip для Python 3
    py3-pip \                   
    # Заголовочные файлы ядра Linux
    linux-headers \             
    # Очищаем кэш пакетов, чтобы уменьшить размер контейнера
    && rm -rf /var/cache/apk/*  

# Устанавливаем Conan — менеджер пакетов для C++ через pip для Python 3
RUN pip3 install conan --break-system-packages

# Устанавливаем рабочую директорию в контейнере на /app
WORKDIR /app

# Копируем все файлы из текущей директории на хосте в рабочую директорию контейнера
COPY . .

# Автоматически определяем профиль для Conan, перезаписывая существующий
RUN conan profile detect --force

# Устанавливаем зависимости проекта с помощью Conan, в папку build, собирая отсутствующие пакеты
RUN conan install . --output-folder=build --build=missing

# Собираем проект с использованием CMake и Conan
# Конфигурируем проект с использованием CMake и Conan
RUN cmake -B build -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
# Собираем проект
RUN cmake --build build

# Открываем порт 8080, на котором будет работать сервер
EXPOSE 8080

# Указываем команду для запуска сервера при старте контейнера
CMD ["./build/server"]
