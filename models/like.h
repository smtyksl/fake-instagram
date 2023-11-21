#ifndef LIKE_H
#define LIKE_H
#include <string>

class Like
{
public:
    Like(int id, int &postId, int userId, long createdAt);
    int id;
    int postId;
    int userId;
    long int createdAt;
    std::string toString() const;
};

#endif // LIKE_H
