#include "World.h"

template <uint32_t W, uint32_t H, bool ALLOW_SHARE>
World<W, H, ALLOW_SHARE>::World() {
}

template <uint32_t W, uint32_t H, bool ALLOW_SHARE>
inline bool World<W, H, ALLOW_SHARE>::in_place(const AgentType& type, const PosType& pos) {
  auto [x, y] = pos;
  return positions[type][y][x] > 0;
}

template <uint32_t W, uint32_t H, bool ALLOW_SHARE>
inline bool World<W, H, ALLOW_SHARE>::someone_there(const PosType& pos) {
  auto [x, y] = pos;
  return positions[AgentType::CARNIVOR][y][x] ||
          positions[AgentType::HERBIVOR][y][x] ||
          positions[AgentType::PLANT][y][x];
}

template <uint32_t W, uint32_t H, bool ALLOW_SHARE>
uint32_t World<W, H, ALLOW_SHARE>::wrap_x(const int32_t& x) {
  if (x < 0) {
    return (this->width + x);
  } else {
    return (x % this->width);
  }
}

template <uint32_t W, uint32_t H, bool ALLOW_SHARE>
uint32_t World<W, H, ALLOW_SHARE>::wrap_y(const int32_t& y) {
  if (y < 0) {
    return (this->height + y);
  } else {
    return (y % this->height);
  }
}

template <uint32_t W, uint32_t H, bool ALLOW_SHARE>
PosType World<W, H, ALLOW_SHARE>::place_agent_rand(const AgentType& type) {
  // find empty spot on the plabe
  PosType pos;
  if (ALLOW_SHARE) {
    pos = std::make_pair(rand() % this->width, rand() % this->height);
  } else {
    do {
      pos = std::make_pair(rand() % this->width, rand() % this->height);
    } while (this->someone_there(pos));
  }

  // place an agent to the spot
  auto [x, y] = pos;
  positions[type][y][x]++;

  // return values
  return pos;
}

template <uint32_t W, uint32_t H, bool ALLOW_SHARE>
void World<W, H, ALLOW_SHARE>::place_agent_to(const AgentType& type, const PosType& pos) {
  auto [x, y] = pos;

  if (ALLOW_SHARE) {
    positions[type][y][x]++;
  } else {
    if (this->someone_there(pos)) {
      std::cerr << "Place is taken" << '\n';
    } else {
      positions[type][y][x]++;
    }
  }
}

template <uint32_t W, uint32_t H, bool ALLOW_SHARE>
void World<W, H, ALLOW_SHARE>::remove_agent_from(const AgentType& type, const PosType& pos) {
  auto [x, y] = pos;
  assert(this->positions[type][y][x] > 0);
  if (this->positions[type][y][x] > 0) {
    this->positions[type][y][x]--;
  }
}

template <uint32_t W, uint32_t H, bool ALLOW_SHARE>
void World<W, H, ALLOW_SHARE>::clear_positions() {
  for (uint32_t type = 0; type < NUM_AGENT_TYPE; type++) {
    for (uint32_t i = 0; i < this->height; i++) {
      for (uint32_t j = 0; j < this->width; j++) {
        positions[(AgentType)type][i][j] = 0;
      }
    }
  }
}

// gets
template <uint32_t W, uint32_t H, bool ALLOW_SHARE>
inline const uint32_t& World<W, H, ALLOW_SHARE>::get_width() const {
  return this->width;
}

template <uint32_t W, uint32_t H, bool ALLOW_SHARE>
inline const uint32_t& World<W, H, ALLOW_SHARE>::get_height() const {
  return this->height;
}

// debug
template <uint32_t W, uint32_t H, bool ALLOW_SHARE>
void World<W, H, ALLOW_SHARE>::draw_positions(const AgentType& type) const {
  char type_char;
  switch (type) {
    case AgentType::CARNIVOR:
      type_char = 'C';
      break;
    case AgentType::HERBIVOR:
      type_char = 'H';
      break;
    case AgentType::PLANT:
      type_char = 'P';
      break;
    default:
      break;
  };

  for (uint32_t i = 0; i < this->height; i++) {
    for (uint32_t j = 0; j < this->width; j++) {
      char to_print;
      if (positions.at(type)[i][j] > 0) {
        to_print = type_char;
      } else {
        to_print = '.';
      }
      std::cout << to_print << " ";
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

template <uint32_t W, uint32_t H, bool ALLOW_SHARE>
void World<W, H, ALLOW_SHARE>::draw_positions() const {
  uint8_t c_type_char = 'C';
  uint8_t h_type_char = 'H';
  uint8_t p_type_char = 'P';

  for (uint32_t i = 0; i < this->width; i++) {
    std::cout << i % 10 << " ";
  }
  std::cout << std::endl;

  for (uint32_t i = 0; i < this->height; i++) {
    for (uint32_t j = 0; j < this->width; j++) {
      char to_print;
      if (positions.at(AgentType::CARNIVOR)[i][j] > 0) {
        to_print = c_type_char;
      } else if (positions.at(AgentType::HERBIVOR)[i][j] > 0){
        to_print = h_type_char;;
      } else if (positions.at(AgentType::PLANT)[i][j] > 0) {
        to_print = p_type_char;
      } else {
        to_print = '.';
      }

      std::cout << to_print << " ";
    }
    std::cout << i << std::endl;
  }
  std::cout << std::endl;
}

template class World<10u, 10u, false>;
