#include <iostream>

namespace DB {
    enum class Status {
        Unknown,
        Connected,
        Disconnected,
    };

    enum class UserPermissions {
        Unknown,
        User,
        Admin,
    };

    struct User
    {
        Status status;
        std::uint64_t id;
    };
}

int main(){
    // C++ old style
    DB::User user1 = {DB::Status::Connected, 42U};
    // C++ 20 style
    DB::User user2 = {.status = DB::Status::Connected, .id = 42U};

    std::cout << user1.id << '\n';

    // C style approach
    std::cout << (std::int32_t)user1.status << '\n';

    // C++ style approach
    std::cout << static_cast<std::int32_t>(user1.status) << '\n';

    return 0;
}
