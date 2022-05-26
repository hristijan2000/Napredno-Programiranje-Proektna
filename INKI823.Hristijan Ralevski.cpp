//Hristijan Ralevski INKI-823

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Profile
{
    int id;
    std::string nickname;
    float level;

    Profile(int id, std::string nickname, float level);
    int compare(Profile profil);
    std::string toString();
};

Profile::Profile(int id, std::string nickname, float level) : id(id), nickname(nickname), level(level) {}

int Profile::compare(Profile profile)
{
    return nickname.compare(profile.nickname);
}

std::string Profile::toString()
{
    return "id: " + std::to_string(this->id) + '\n' + "nickname: " + this->nickname + '\n' + "level: " + std::to_string(this->level);
}

void printProfiles(const std::vector<Profile> &profiles)
{
    // for (auto it = profiles.begin(); it != profiles.end(); it++)
    // {
    //     std::cout << it->toString() << std::endl;
    // }

    for (auto profile : profiles)
    {
        std::cout << profile.toString() << std::endl;
    }
}

int main()
{
    std::vector<Profile> profiles = {Profile(0, "funni", 2)};
    profiles.push_back(Profile(1, "lazy", 4));
    profiles.push_back(Profile(2, "mr.atakomo", 8));
    profiles.push_back(Profile(3, "mr.atakomo e najdobar", 10));


    printProfiles(profiles);

    std::sort(profiles.begin(), profiles.end(), [](Profile profile1, Profile profile2) -> bool
              { return profile1.compare(profile2) > 0; });

    printProfiles(profiles);

    return 0;
}
