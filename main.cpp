#include <iostream>
#include "crow.h"
#include <sqlite3.h>
#include <controllers/controller.h>
#include <backend.h>
using namespace std;

int main()
{
    crow::SimpleApp app;
    Backend be;


    CROW_ROUTE(app, "/").methods("GET"_method)
    ([&](const crow::request& req) {
        crow::json::wvalue::list array;
        crow::json::wvalue postElement;
        int id =stoi(req.url_params.get("id"));

        for(auto post: be.getPosts(id)) {
            postElement["id"] = std::uint64_t(post.id);
            postElement["description"] = post.description;
            postElement["image"] = post.image;
            postElement["userId"] = std::uint64_t(post.userId);
            postElement["createdAt"] =  std::uint64_t(post.createdAt);
            array.push_back(postElement);
        }
        return array.data()->dump();

    });

    app.port(18080).run();



    return 0;
}

