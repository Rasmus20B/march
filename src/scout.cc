#include "scout.h"


namespace march {
MissionReport scout(std::vector<int>& s) {
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_real_distribution<float> distr(0, 1);

  std::cout << "Sending " << s.size() << " soldiers for the scouting mission\n";

  float res = distr(generator);
  std::cout << "chance = " << res << std::endl;
  if(res < 0.20) {
    auto gen = std::mt19937(std::random_device{}());
    std::uniform_int_distribution<size_t> supply_chance(1, 40);
    auto supplies = supply_chance(gen);
    return MissionReport { s, s, supplies, 1 };
  } else if(res < 0.90) {
    std::uniform_int_distribution<int> r(1, s.size() - 1);
    auto gen = std::mt19937(std::random_device{}());
    std::vector<int> dead;
    size_t back = r(gen);
    std::cout << back << "\n";
    for(size_t i = 0; i <= back; i++) {
      std::ranges::sample(s, std::back_inserter(dead), i, gen);
    }
    std::sort(dead.begin(), dead.end());
    const auto [first, last] = std::ranges::unique(dead.begin(), dead.end());
    dead.erase(first, last);
    std::cout << "dead : ";
    for(auto i : dead) {
      std::cout << i << ", ";
    }
    std::cout << "\n";

    std::uniform_int_distribution<size_t> supply_chance(1, 40);
    auto supplies = supply_chance(gen);
    return MissionReport { s, dead, supplies, 2 };
  } else {
    std::vector<int> l{};
    return MissionReport { s, s , 0, 3 };
  }
}

}
