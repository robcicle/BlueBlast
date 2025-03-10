#pragma once

#include <string>
#include <vector>

struct Metrics {
    const std::string VERSION = "1.0";  // Current game version
    float time;                        // Session time
    std::string name;                  // Current player's name

    // Hold data together so it can be saved as a container
    struct PlayerData {
        std::string name;
        float time = 0;
    };
    std::vector<PlayerData> playerData;  // Last five players' data
    std::string filePath;                // Data storage location

    // Use this whenever a new game is played to reset data such as name and time
    void Restart();
    // Is the new score in the top five
    bool IsScoreInTopFive();
    // Figure out if current score qualifies for the top five,
    // if it does then add it to the data and then resort the playerData vector to correspond to it
    void SortAndUpdatePlayerData();
    // Load in the player data
    bool Load(const std::string& path);
    // Save all of the player data
    bool Save(const std::string& path = "");
};
