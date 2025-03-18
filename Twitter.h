#pragma once
#include <iostream>
#include "Array.h"  // Include the Array class template

template <typename T>
class Twitter {
private:
    T followedUser;    // Variable to store the followed user
    Array<T> followers; // Array to store the list of followers
    const size_t maxFollowers = 5;  // Set maximum of followers to 5

public:
    Twitter(T user) : followedUser(user), followers(2) {}  // Initialize with an array of size 2

    void addFollower(T follower) {
        if (followers.length() >= maxFollowers) {
            std::cout << "Follower list is full!" << std::endl;
            return;
        }

        if (followers.length() == followers.capacity()) {
            followers.changeSize(followers.capacity() * 2);  // Double the size if full
        }
        followers[followers.length()] = follower;  // Add the follower
    }

    void removeFollower(T follower) {
        for (int i = 0; i < followers.length(); ++i) {
            if (followers[i] == follower) {
                for (int j = i; j < followers.length() - 1; ++j) {
                    followers[j] = followers[j + 1];  // Shift elements to the left
                }
                followers.changeSize(followers.length() - 1);  // Reduce size by 1

                // Halve the size if less than 25% of the capacity is used
                if (followers.length() < followers.capacity() / 4) {
                    followers.changeSize(followers.capacity() / 2);
                }
                return;
            }
        }
        std::cout << "Follower not found!" << std::endl;
    }

    void printFollowers() const {
        std::cout << "Followers of " << followedUser << ":" << std::endl;
        for (int i = 0; i < followers.length(); ++i) {
            std::cout << followers[i] << std::endl;
        }
    }
};
