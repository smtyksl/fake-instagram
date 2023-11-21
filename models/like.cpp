#include "like.h"
#include <sstream>
#include <iostream>

Like::Like(int id, int &postId, int userId, long createdAt)
    : id(id), postId(postId), userId(userId), createdAt(createdAt)
{
}

std::string Like::toString() const
{
    std::stringstream ss;
    std::cout << "adasd";
    ss << "ID: " << id << "\n"
       << "Post ID: " << postId << "\n"
       << "User ID: " << userId << "\n"
       << "Created At: " << createdAt;
    return ss.str();
}
