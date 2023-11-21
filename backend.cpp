#include "backend.h"


Backend::Backend()
    : controller(nullptr)
{
    controller = new Controller;
}

User Backend::getUser(int id)
{
    if(userCache.contains(id))
        return userCache[id];

    for(auto user: controller->getUsers())
        if(user.id== id)
        {
            userCache[id]=user;
            return user;
        }
    return User(-1,"","","","","",-1); // user db de yok!!
}

std::vector<Post> Backend::getPosts(int id)
{
    //    //burada takip edilen userların postları olmalı
    bool userExist;
    for(auto user: controller->getUsers())
        if(user.id == id) {
            userExist = true;
            break;
        }
    if(!userExist)
        return std::vector<Post>(); // hata durumu sistemde hiç user yoksa!!

    if(followingList.contains(id))
    {
        for(auto followingID: followingList[id])
            mergePosts(userPostCache[id] = controller->getposts(followingID),id);
    }

    std::reverse(userPostCache[id].begin(), userPostCache[id].end()); // desc sıralama
    return  userPostCache.contains(id) == true ? userPostCache[id] : std::vector<Post>(); // hata durumu sistemde hiç takip edilen user yoksa!!
}

std::vector<int> Backend::getFollowingUser(int id)
{
    std::vector<int> follomingListLocale;
    if(followingList.contains(id))
        return followingList[id];

    for(auto following: controller->getFollow(id))
        follomingListLocale.push_back(following);

    return follomingListLocale;
}

std::vector<Post> Backend::mergePosts(std::vector<Post> incomingPost, int id)
{
    std::vector<Post> newList;
    if(userPostCache.empty()) {
        userPostCache[id] = incomingPost;
        return incomingPost;
    }

    int userPostCacheSize = userPostCache[id].size();
    for(int i=0; i< incomingPost.size(); i++){
        // 2. vektörün elemanı 1. vektörün son değerinden büyükse
        if(incomingPost.at(i).createdAt > userPostCache[id].at(incomingPost.size()-1).createdAt) {
            userPostCache[id].push_back(incomingPost.at(i));
            userPostCacheSize++;
        } else if(incomingPost.at(i).createdAt == userPostCache[id].at(incomingPost.size()-1).createdAt) { // eşitlik durumunda id si küçük olan öne ekleniyor
                if( userPostCache[id].at(incomingPost.size()-1).id < incomingPost.at(i).id)
                    userPostCache[id].insert(userPostCache[id].begin()+ incomingPost.size()-1, incomingPost.at(i) );
                if( userPostCache[id].at(incomingPost.size()-1).id >= incomingPost.at(i).id)
                    userPostCache[id].insert(userPostCache[id].begin()+ incomingPost.size()-2, incomingPost.at(i) );
                userPostCacheSize++;
                break;
             }

        else {
            // 2. vektörün elemanını 1. vektörde uygun yere ekle
            for(int j=0; j <userPostCacheSize; j++) {
                userPostCache[id].insert(userPostCache[id].begin()+ j,incomingPost.at(i) );
                userPostCacheSize++;
                break;
            }
        }
    }
    return newList;
}
