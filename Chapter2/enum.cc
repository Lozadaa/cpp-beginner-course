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

int main(){
    Status s1 = Status::Unknown;
    UserPermissions s2 = UserPermissions::Unknown;

    switch (s1)
    {
    case Status::Unknown:
        std::cout << "Unknown\n";
        break;
    case Status::Connected:
        std::cout << "Connected\n";
    case Status::Disconnected:
        std::cout << "Disconnected\n";
    default:
        std::cout << "No case";
        break;
    }

    return 0;
}
