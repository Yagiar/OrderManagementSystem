#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    int userId;
    std::string username;
    std::string passwordHash;
    std::string email;

public:
    // Конструктор
    User(int id, const std::string& uname, const std::string& pwdHash, const std::string& mail)
        : userId(id), username(uname), passwordHash(pwdHash), email(mail) {}

    // Методы доступа (getters)
    int getUserId() const { return userId; }
    std::string getUsername() const { return username; }
    std::string getPasswordHash() const { return passwordHash; }
    std::string getEmail() const { return email; }

    // Методы для работы с пользователями
    static bool login(const std::string& username, const std::string& password);
    static bool registerUser(const std::string& username, const std::string& password, const std::string& email);
    static User getUserById(int userId);

    // Дополнительные методы
    void updateEmail(const std::string& newEmail);
    void updatePassword(const std::string& newPassword);
};

#endif // USER_H
