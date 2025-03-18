#ifndef PROFILE_H
#define PROFILE_H

#include <string>
#include <iostream>

struct Profile {
    std::string username;
    int age;
    std::string state;

    bool operator==(const Profile& other) const {
        return username == other.username;
    }

    friend std::ostream& operator<<(std::ostream& os, const Profile& profile) {
        os << "Username: " << profile.username << ", Age: " << profile.age << ", State: " << profile.state;
        return os;
    }
};

#endif // PROFILE_H
