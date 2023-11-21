#ifndef FOLLOW_H
#define FOLLOW_H
#include <string>

class Follow
{
public:
    Follow(int followerId, int followingId, long createdAt);
    int followerId;
    int followingId;
    long int createdAt;

    std::string toSstring() const;
};

#endif // FOLLOW_H
