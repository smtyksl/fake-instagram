#include "post.h"
#include <sstream>

Post::Post(int id, const std::string& description, int userId, const std::string& image, long int createdAt)
    : id(id), description(description), userId(userId), image(image), createdAt(createdAt)
{
}

std::string Post::toString() const
{
    std::stringstream ss;
    ss << "ID: " << id << "\n"
       << "Description: " << description << "\n"
       << "User ID: " << userId << "\n"
       << "Image: " << image << "\n"
       << "Created At: " << createdAt;
    return ss.str();
}
