#include "Metrics.h"
#include <fstream>
#include <cassert>
#include <algorithm>

void Metrics::SortAndUpdatePlayerData() {
    PlayerData d{ name, time };
    playerData.push_back(d);
}

bool Metrics::Save(const std::string& path) {
    if (!path.empty())
        filePath = path;
    std::ofstream fs;
    fs.open(filePath);
    if (fs.is_open() && fs.good())
    {
        std::sort(playerData.begin(), playerData.end(), [](const PlayerData& a, const PlayerData& b) {
            return a.time > b.time;
        });

        fs << VERSION;
        for (size_t i = 0; i < playerData.size(); ++i)
        {
            std::string sanitized_name = playerData[i].name;
            std::replace(sanitized_name.begin(), sanitized_name.end(), ' ', '_');

            fs << ' ' << sanitized_name << ' ' << playerData[i].time;
        }
        assert(!fs.fail());
        fs.close();
    }
    else
    {
        assert(false);
        return false;
    }
    return true;
}

bool Metrics::Load(const std::string& path)
{
    assert(!path.empty());
    filePath = path;
    std::ifstream fs;
    fs.open(filePath, std::ios::binary);
    if (fs.is_open() && fs.good())
    {
        std::string version;
        fs >> version;
        if (version == VERSION)
        {
            playerData.clear();
            while (!fs.eof()) {
                PlayerData d;
                fs >> d.name;
                assert(!d.name.empty());
                fs >> d.time;
                assert(d.time >= 0);
                playerData.push_back(d);
            }
        }
        assert(!fs.fail());
        fs.close();
        return true;
    }
    else
    {
        // If the file does not exist, create an empty file
        std::ofstream ofs(filePath, std::ios::binary);
        if (ofs.is_open() && ofs.good())
        {
            ofs << VERSION;
            ofs.close();
            return true;
        }
        else
        {
            assert(false);
            return false;
        }
    }
}


bool Metrics::IsScoreInTopFive() {
    if (playerData.size() < 5)
        return true;
    return time < playerData.back().time;
}

void Metrics::Restart() {
    time = 0;
    name = "";
}
