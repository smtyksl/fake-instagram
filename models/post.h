#ifndef POST_H
#define POST_H
#include <string>

class Post
{
public:
    Post(int id, const std::string &description, int userId, const std::string &image, long createdAt);
    int id;
    std::string description;
    int userId;
    std::string image;
    long int createdAt;
    std::string toString() const;
};

#endif // POST_H
