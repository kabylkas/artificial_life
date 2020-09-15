#pragma once

#include "SupportTypes.h"
#include <map>
#include <iostream>
#include <cstdlib> //rand()
#include <assert.h>

template <uint32_t W, uint32_t H, bool ALLOW_SHARE>
class World {
  private:
    const uint32_t width = W;
    const uint32_t height = H;
    std::map<AgentType, std::array<std::array<uint32_t, H>, W>> positions;

  public:
    World();
    inline bool in_place(const AgentType& type, const PosType& pos);
    inline bool someone_there(const PosType& pos);
    uint32_t wrap_x(const int32_t& x);
    uint32_t wrap_y(const int32_t& y);
    PosType place_agent_rand(const AgentType& type);
    void place_agent_to(const AgentType& type, const PosType& pos);
    void remove_agent_from(const AgentType& type, const PosType& pos);
    void clear_positions();

    // gets
    inline const uint32_t& get_width() const;
    inline const uint32_t& get_height() const;

    // debug
    void draw_positions(const AgentType& type) const;
    void draw_positions() const;
};
