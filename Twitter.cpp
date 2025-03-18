#include <iostream>
#include "Twitter.h"
#include "Profile.h"  // Include the Profile struct definition

int main() {
    // Create Twitter<string> object
    Twitter<std::string> twitterStr("MainUser");
    twitterStr.addFollower("Follower1");
    twitterStr.addFollower("Follower2");
    twitterStr.printFollowers();

    twitterStr.removeFollower("Follower1");

    // Create Twitter<Profile> object
    Profile userProfile = {"MainProfileUser", 25, "Michigan"};
    Twitter<Profile> twitterProfile(userProfile);

    Profile follower1 = {"Follower1", 21, "California"};
    Profile follower2 = {"Follower2", 23, "New York"};

    twitterProfile.addFollower(follower1);
    twitterProfile.addFollower(follower2);
    twitterProfile.printFollowers();

    twitterProfile.removeFollower(follower1);

    return 0;
}
