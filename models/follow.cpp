#include "follow.h"
#include <sstream>

Follow::Follow(int followerId, int followingId, long int createdAt)
    : followerId(followerId), followingId(followingId), createdAt(createdAt)
{
}
std::string Follow::toSstring() const
{
    std::stringstream ss;
    ss << "Follower ID: " << followerId << "\n"
       << "Following ID: " << followingId << "\n"
       << "Created At: " << createdAt;
    return ss.str();
}
