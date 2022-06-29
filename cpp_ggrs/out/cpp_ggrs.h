#pragma once
#include "rust/cxx.h"

namespace GGRS {
  struct GGRSSessionInfo;
  struct GGRSPlayer;
  enum class GGRSPlayerType : ::std::uint8_t;
  enum class GGRSSessionType : ::std::uint8_t;
}

namespace GGRS {
#ifndef CXXBRIDGE1_STRUCT_GGRS$GGRSSessionInfo
#define CXXBRIDGE1_STRUCT_GGRS$GGRSSessionInfo
struct GGRSSessionInfo final {
  ::GGRS::GGRSSessionType session_type;
  ::std::uint32_t num_players;
  ::std::uint32_t fps;
  ::std::uint32_t input_delay;
  ::std::uint32_t max_prediction_frames;
  ::std::uint32_t max_frames_behind;
  ::std::uint32_t catchup_speed;
  ::std::uint32_t check_distance;
  ::std::uint16_t local_port;
  ::rust::String host;
  bool sparse_saving;
  ::rust::Vec<::GGRS::GGRSPlayer> players;

  using IsRelocatable = ::std::true_type;
};
#endif // CXXBRIDGE1_STRUCT_GGRS$GGRSSessionInfo

#ifndef CXXBRIDGE1_STRUCT_GGRS$GGRSPlayer
#define CXXBRIDGE1_STRUCT_GGRS$GGRSPlayer
struct GGRSPlayer final {
  ::std::uint32_t player_handle;
  ::GGRS::GGRSPlayerType player_type;
  ::rust::String socket_addr;

  using IsRelocatable = ::std::true_type;
};
#endif // CXXBRIDGE1_STRUCT_GGRS$GGRSPlayer

#ifndef CXXBRIDGE1_ENUM_GGRS$GGRSPlayerType
#define CXXBRIDGE1_ENUM_GGRS$GGRSPlayerType
enum class GGRSPlayerType : ::std::uint8_t {
  Local = 0,
  Remote = 1,
  Spectator = 2,
};
#endif // CXXBRIDGE1_ENUM_GGRS$GGRSPlayerType

#ifndef CXXBRIDGE1_ENUM_GGRS$GGRSSessionType
#define CXXBRIDGE1_ENUM_GGRS$GGRSSessionType
enum class GGRSSessionType : ::std::uint8_t {
  NotSet = 0,
  Peer2Peer = 1,
  Spectator = 2,
  Synctest = 3,
};
#endif // CXXBRIDGE1_ENUM_GGRS$GGRSSessionType

bool setup_ggrs_info(::GGRS::GGRSSessionInfo &info) noexcept;

bool add_player(::GGRS::GGRSSessionInfo &info, ::GGRS::GGRSPlayer player) noexcept;

bool setup_p2p_session(::GGRS::GGRSSessionInfo &info, ::std::uint16_t local_port, ::std::uint32_t fps, ::std::uint32_t input_delay, ::std::uint32_t max_prediction_frames) noexcept;

bool setup_spectator_session(::GGRS::GGRSSessionInfo &info, ::std::uint16_t local_port, ::rust::String host, ::std::uint32_t max_frames_behind, ::std::uint32_t catchup_speed) noexcept;

bool setup_synctest_session(::GGRS::GGRSSessionInfo &info, ::std::uint32_t check_distance, ::std::uint32_t input_delay) noexcept;

bool set_num_players(::GGRS::GGRSSessionInfo &info, ::std::uint32_t num) noexcept;

bool set_sparse_saving(::GGRS::GGRSSessionInfo &info, bool enable) noexcept;

::std::int32_t test_lib(::std::int32_t num) noexcept;
} // namespace GGRS
