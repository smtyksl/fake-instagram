#ifndef USER_H
#define USER_H

#include <string>
class User
{
public:
    User();
    User(int id, const std::string &userName, const std::string &email, const std::string &fullName, const std::string &profilePicture, const std::string &bio, long int  createdAt);
    int id;
    std::string userName;
    std::string fullName;
    std::string email;
    std::string profilePicture;
    std::string bio;
    long int createdAt;
    std::string toString() const;
};

#endif // USER_H
