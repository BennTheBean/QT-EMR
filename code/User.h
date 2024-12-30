#ifndef USER_H
#define USER_H

#include <QString>

class User {
public:
    User(const QString& username, const QString& password);
    virtual ~User() = default;  // Ensure virtual destructor for polymorphic usage

    virtual QString getRole() const = 0;  // Mark pure virtual

    const QString& getUsername() const;  // Mark const
    const QString& getPassword() const;  // Mark const
    bool login(const QString& inputUsername, const QString& inputPassword) const;

protected:
    const QString username;  // Should remain constant after initialization
    const QString password;  // Should remain constant after initialization
};

class Doctor : public User {
public:
    Doctor(const QString& uname, const QString& pwd);
    QString getRole() const override;
};

class Admin : public User {
public:
    Admin(const QString& uname, const QString& pwd);
    QString getRole() const override;
};

class Receptionist : public User {
public:
    Receptionist(const QString& uname, const QString& pwd);
    QString getRole() const override;
};

#endif // USER_H
