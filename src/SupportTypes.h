#pragma once
#include <cstddef>
#include <cstdint>
#include <utility>

// Defines
#define ALLOW_PLACE_SHARING true

#define SEED           2
#define MEMORY_SIZE    12

#define D_MIN          -5.0
#define D_MAX          5.0

#define NUM_AGENT_TYPE 3
#define NUM_ACTION     4
#define NUM_INPUT      4
#define NUM_DIRECTION  4
#define NUM_OFFSET     15

using PosType = std::pair<uint32_t, uint32_t>;

class AlifeConsts {
  public:
    static inline const size_t NumAgentType = 3;
    static inline const size_t NumAction    = 4;
    static inline const size_t NumInput     = 4;
    static inline const size_t NumDirection = 4;
    static inline const size_t NumOffset    = 15;
};

enum class Direction {
  EAST,
  SOUTH,
  WEST,
  NORTH
};

enum class AgentType {
  HERBIVOR,
  CARNIVOR,
  PLANT
};

enum class ActionType {
  EAT, 
  TURN_LEFT,
  TURN_RIGHT,
  MOVE
};
