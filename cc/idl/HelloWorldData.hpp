/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to CXX Translator
  File name: /home/allen/ws/cyclonedds-cxx/install/share/CycloneDDS-CXX/examples/helloworld/HelloWorldData.idl
  Source: /home/allen/ws/cyclonedds-cxx/install/share/CycloneDDS-CXX/examples/helloworld/HelloWorldData.hpp
  Cyclone DDS: v0.11.0

*****************************************************************/
#ifndef DDSCXX__HOME_ALLEN_WS_CYCLONEDDS_CXX_INSTALL_SHARE_CYCLONEDDS_CXX_EXAMPLES_HELLOWORLD_HELLOWORLDDATA_HPP_A2B6A459CE84C1C6F91FECA6D0EE0587
#define DDSCXX__HOME_ALLEN_WS_CYCLONEDDS_CXX_INSTALL_SHARE_CYCLONEDDS_CXX_EXAMPLES_HELLOWORLD_HELLOWORLDDATA_HPP_A2B6A459CE84C1C6F91FECA6D0EE0587

#include <utility>
#include <ostream>
#include <cstdint>
#include <string>

namespace HelloWorldData
{
class Msg
{
private:
 int32_t userID_ = 0;
 std::string message_;

public:
  Msg() = default;

  explicit Msg(
    int32_t userID,
    const std::string& message) :
    userID_(userID),
    message_(message) { }

  int32_t userID() const { return this->userID_; }
  int32_t& userID() { return this->userID_; }
  void userID(int32_t _val_) { this->userID_ = _val_; }
  const std::string& message() const { return this->message_; }
  std::string& message() { return this->message_; }
  void message(const std::string& _val_) { this->message_ = _val_; }
  void message(std::string&& _val_) { this->message_ = std::move(_val_); }

  bool operator==(const Msg& _other) const
  {
    (void) _other;
    return userID_ == _other.userID_ &&
      message_ == _other.message_;
  }

  bool operator!=(const Msg& _other) const
  {
    return !(*this == _other);
  }

};

std::ostream& operator<<(std::ostream& os, Msg const& rhs);

} //namespace HelloWorldData

#include "dds/topic/TopicTraits.hpp"
#include "org/eclipse/cyclonedds/topic/datatopic.hpp"

namespace org {
namespace eclipse {
namespace cyclonedds {
namespace topic {

template <> constexpr const char* TopicTraits<::HelloWorldData::Msg>::getTypeName()
{
  return "HelloWorldData::Msg";
}

template <> constexpr bool TopicTraits<::HelloWorldData::Msg>::isSelfContained()
{
  return false;
}

#ifdef DDSCXX_HAS_TYPELIB
template<> constexpr unsigned int TopicTraits<::HelloWorldData::Msg>::type_map_blob_sz() { return 246; }
template<> constexpr unsigned int TopicTraits<::HelloWorldData::Msg>::type_info_blob_sz() { return 100; }
template<> inline const uint8_t * TopicTraits<::HelloWorldData::Msg>::type_map_blob() {
  alignas(4) static const uint8_t blob[] = {
 0x4c,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0xf1,  0x6e,  0x42,  0x14,  0x9e,  0xb1,  0x41,  0xa0, 
 0xd7,  0x25,  0x94,  0xc6,  0x50,  0xd7,  0x3c,  0x00,  0x34,  0x00,  0x00,  0x00,  0xf1,  0x51,  0x01,  0x00, 
 0x01,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x24,  0x00,  0x00,  0x00,  0x02,  0x00,  0x00,  0x00, 
 0x0b,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x31,  0x00,  0x04,  0x58,  0x5c,  0x95,  0x70,  0x00, 
 0x0c,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x70,  0x00,  0x78,  0xe7,  0x31,  0x02, 
 0x7a,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0xf2,  0xb1,  0xa3,  0xb1,  0xfb,  0x8b,  0x1a,  0x60, 
 0x51,  0x60,  0x14,  0x29,  0x7c,  0x3b,  0x8a,  0x00,  0x62,  0x00,  0x00,  0x00,  0xf2,  0x51,  0x01,  0x00, 
 0x1c,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x14,  0x00,  0x00,  0x00,  0x48,  0x65,  0x6c,  0x6c, 
 0x6f,  0x57,  0x6f,  0x72,  0x6c,  0x64,  0x44,  0x61,  0x74,  0x61,  0x3a,  0x3a,  0x4d,  0x73,  0x67,  0x00, 
 0x3a,  0x00,  0x00,  0x00,  0x02,  0x00,  0x00,  0x00,  0x15,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 
 0x31,  0x00,  0x04,  0x00,  0x07,  0x00,  0x00,  0x00,  0x75,  0x73,  0x65,  0x72,  0x49,  0x44,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x16,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x70,  0x00, 
 0x08,  0x00,  0x00,  0x00,  0x6d,  0x65,  0x73,  0x73,  0x61,  0x67,  0x65,  0x00,  0x00,  0x00,  0x00,  0x00, 
 0x22,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0xf2,  0xb1,  0xa3,  0xb1,  0xfb,  0x8b,  0x1a,  0x60, 
 0x51,  0x60,  0x14,  0x29,  0x7c,  0x3b,  0x8a,  0xf1,  0x6e,  0x42,  0x14,  0x9e,  0xb1,  0x41,  0xa0,  0xd7, 
 0x25,  0x94,  0xc6,  0x50,  0xd7,  0x3c, };
  return blob;
}
template<> inline const uint8_t * TopicTraits<::HelloWorldData::Msg>::type_info_blob() {
  alignas(4) static const uint8_t blob[] = {
 0x60,  0x00,  0x00,  0x00,  0x01,  0x10,  0x00,  0x40,  0x28,  0x00,  0x00,  0x00,  0x24,  0x00,  0x00,  0x00, 
 0x14,  0x00,  0x00,  0x00,  0xf1,  0x6e,  0x42,  0x14,  0x9e,  0xb1,  0x41,  0xa0,  0xd7,  0x25,  0x94,  0xc6, 
 0x50,  0xd7,  0x3c,  0x00,  0x38,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x04,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x02,  0x10,  0x00,  0x40,  0x28,  0x00,  0x00,  0x00,  0x24,  0x00,  0x00,  0x00, 
 0x14,  0x00,  0x00,  0x00,  0xf2,  0xb1,  0xa3,  0xb1,  0xfb,  0x8b,  0x1a,  0x60,  0x51,  0x60,  0x14,  0x29, 
 0x7c,  0x3b,  0x8a,  0x00,  0x66,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x04,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00, };
  return blob;
}
#endif //DDSCXX_HAS_TYPELIB

} //namespace topic
} //namespace cyclonedds
} //namespace eclipse
} //namespace org

namespace dds {
namespace topic {

template <>
struct topic_type_name<::HelloWorldData::Msg>
{
    static std::string value()
    {
      return org::eclipse::cyclonedds::topic::TopicTraits<::HelloWorldData::Msg>::getTypeName();
    }
};

}
}

REGISTER_TOPIC_TYPE(::HelloWorldData::Msg)

namespace org{
namespace eclipse{
namespace cyclonedds{
namespace core{
namespace cdr{

template<>
const propvec &get_type_props<::HelloWorldData::Msg>();

namespace {
  static const volatile propvec &properties___HelloWorldData__Msg = get_type_props<::HelloWorldData::Msg>();
}

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool write(T& streamer, const ::HelloWorldData::Msg& instance, const entity_properties_t *props) {
  (void)instance;
  member_id_set member_ids;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!write(streamer, instance.userID()))
        return false;
      if (!streamer.finish_member(*prop, member_ids))
        return false;
      break;
      case 1:
      if (!streamer.start_member(*prop))
        return false;
      if (!write_string(streamer, instance.message(), 0))
        return false;
      if (!streamer.finish_member(*prop, member_ids))
        return false;
      break;
    }
    prop = streamer.next_entity(prop);
  }
  return streamer.finish_struct(*props, member_ids);
}

template<typename S, std::enable_if_t<std::is_base_of<cdr_stream, S>::value, bool> = true >
bool write(S& str, const ::HelloWorldData::Msg& instance, key_mode key) {
  const auto &props = get_type_props<::HelloWorldData::Msg>();
  str.set_mode(cdr_stream::stream_mode::write, key);
  return write(str, instance, props.data()); 
}

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool read(T& streamer, ::HelloWorldData::Msg& instance, const entity_properties_t *props) {
  (void)instance;
  member_id_set member_ids;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!read(streamer, instance.userID()))
        return false;
      if (!streamer.finish_member(*prop, member_ids))
        return false;
      break;
      case 1:
      if (!streamer.start_member(*prop))
        return false;
      if (!read_string(streamer, instance.message(), 0))
        return false;
      if (!streamer.finish_member(*prop, member_ids))
        return false;
      break;
    }
    prop = streamer.next_entity(prop);
  }
  return streamer.finish_struct(*props, member_ids);
}

template<typename S, std::enable_if_t<std::is_base_of<cdr_stream, S>::value, bool> = true >
bool read(S& str, ::HelloWorldData::Msg& instance, key_mode key) {
  const auto &props = get_type_props<::HelloWorldData::Msg>();
  str.set_mode(cdr_stream::stream_mode::read, key);
  return read(str, instance, props.data()); 
}

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool move(T& streamer, const ::HelloWorldData::Msg& instance, const entity_properties_t *props) {
  (void)instance;
  member_id_set member_ids;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!move(streamer, instance.userID()))
        return false;
      if (!streamer.finish_member(*prop, member_ids))
        return false;
      break;
      case 1:
      if (!streamer.start_member(*prop))
        return false;
      if (!move_string(streamer, instance.message(), 0))
        return false;
      if (!streamer.finish_member(*prop, member_ids))
        return false;
      break;
    }
    prop = streamer.next_entity(prop);
  }
  return streamer.finish_struct(*props, member_ids);
}

template<typename S, std::enable_if_t<std::is_base_of<cdr_stream, S>::value, bool> = true >
bool move(S& str, const ::HelloWorldData::Msg& instance, key_mode key) {
  const auto &props = get_type_props<::HelloWorldData::Msg>();
  str.set_mode(cdr_stream::stream_mode::move, key);
  return move(str, instance, props.data()); 
}

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool max(T& streamer, const ::HelloWorldData::Msg& instance, const entity_properties_t *props) {
  (void)instance;
  member_id_set member_ids;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!max(streamer, instance.userID()))
        return false;
      if (!streamer.finish_member(*prop, member_ids))
        return false;
      break;
      case 1:
      if (!streamer.start_member(*prop))
        return false;
      if (!max_string(streamer, instance.message(), 0))
        return false;
      if (!streamer.finish_member(*prop, member_ids))
        return false;
      break;
    }
    prop = streamer.next_entity(prop);
  }
  return streamer.finish_struct(*props, member_ids);
}

template<typename S, std::enable_if_t<std::is_base_of<cdr_stream, S>::value, bool> = true >
bool max(S& str, const ::HelloWorldData::Msg& instance, key_mode key) {
  const auto &props = get_type_props<::HelloWorldData::Msg>();
  str.set_mode(cdr_stream::stream_mode::max, key);
  return max(str, instance, props.data()); 
}

} //namespace cdr
} //namespace core
} //namespace cyclonedds
} //namespace eclipse
} //namespace org

#endif // DDSCXX__HOME_ALLEN_WS_CYCLONEDDS_CXX_INSTALL_SHARE_CYCLONEDDS_CXX_EXAMPLES_HELLOWORLD_HELLOWORLDDATA_HPP_A2B6A459CE84C1C6F91FECA6D0EE0587
