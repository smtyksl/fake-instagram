#include "user.h"
#include <sstream>

User::User(int id, const std::string& userName, const std::string &email, const std::string& fullName, const std::string& profilePicture, const std::string& bio, long int createdAt)
    : id(id)
    , userName(userName)
    , fullName(fullName)
    , profilePicture(profilePicture)
    , bio(bio)
    , createdAt(createdAt)
    , email(email)
{
}

std::string User::User::toString() const
{
    std::stringstream ss;
    ss << "ID: " << std::to_string(id) << "\n"
       << "Username: " << userName << "\n"
       << "FullName: " << fullName << "\n"
       << "ProfilePicture: " << profilePicture << "\n"
       << "Bio: " << bio << "\n"
       << "CreatedAt: " << createdAt;
    return ss.str();
}
