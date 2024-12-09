#include "crow.h" // Подключаем библиотеку Crow для создания веб-сервера

int main() {
    crow::SimpleApp app; // Создаем экземпляр приложения Crow

    // Определяем маршрут для корневого URL "/"
    CROW_ROUTE(app, "/")([]() {
        return "Hello Docker World !"; // Возвращаем текстовый ответ
    });

    // Определяем маршрут для URL "/api"
    CROW_ROUTE(app, "/api")([]() {
        crow::json::wvalue response; // Создаем JSON-объект для ответа
        response["status"] = "success"; // Устанавливаем поле "status"
        response["message"] = "Welcome to crowcpp API !"; // Устанавливаем поле "message"
        return response; // Возвращаем JSON-ответ
    });

    // Настраиваем порт, включаем многопоточность и запускаем сервер
    app.port(8080) // Сервер будет слушать порт 8080
       .multithreaded() // Включаем многопоточность
       .run(); // Запускаем сервер
}