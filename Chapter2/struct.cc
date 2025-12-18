#include <iostream>

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

int main(){
    // C++ old style
    User user1 = {Status::Connected, 42U};
    // C++ 20 style
    User user2 = {.status = Status::Connected, .id = 42U};

    std::cout << user1.id << '\n';

    // C style approach
    std::cout << (std::int32_t)user1.status << '\n';

    // C++ style approach
    std::cout << static_cast<std::int32_t>(user1.status) << '\n';

    return 0;
}
