#ifndef BACKEND_H
#define BACKEND_H

#include <map>
#include <vector>

#include "controllers/controller.h"



class Backend
{
public:
    Backend();
    User getUser(int id);
    std::vector<Post> getPosts(int id);
    std::vector<int> getFollowingUser(int id);
    std::vector<Post> mergePosts(std::vector<Post> incomingPost, int id);
private:
    std::map<int, User> userCache;
    std::map<int, std::vector<Post>> userPostCache;
    Controller* controller;
    std::map<int,std::vector<int>> followingList;
    std::vector<User> userList;
};

#endif // BACKEND_H
