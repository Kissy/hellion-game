// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Proto/Common/System.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* SystemProto_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SystemProto_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* SystemProto_Type_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_Proto_2fCommon_2fSystem_2eproto() {
  protobuf_AddDesc_Proto_2fCommon_2fSystem_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Proto/Common/System.proto");
  GOOGLE_CHECK(file != NULL);
  SystemProto_descriptor_ = file->message_type(0);
  static const int SystemProto_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SystemProto, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SystemProto, properties_),
  };
  SystemProto_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SystemProto_descriptor_,
      SystemProto::default_instance_,
      SystemProto_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SystemProto, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SystemProto, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SystemProto));
  SystemProto_Type_descriptor_ = SystemProto_descriptor_->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Proto_2fCommon_2fSystem_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SystemProto_descriptor_, &SystemProto::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Proto_2fCommon_2fSystem_2eproto() {
  delete SystemProto::default_instance_;
  delete SystemProto_reflection_;
}

void protobuf_AddDesc_Proto_2fCommon_2fSystem_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::protobuf_AddDesc_Proto_2fCommon_2fProperty_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\031Proto/Common/System.proto\032\033Proto/Commo"
    "n/Property.proto\"\334\001\n\013SystemProto\022\037\n\004type"
    "\030\001 \002(\0162\021.SystemProto.Type\022\"\n\nproperties\030"
    "\002 \003(\0132\016.PropertyProto\"\207\001\n\004Type\022\010\n\004None\020\000"
    "\022\013\n\007Generic\020\001\022\006\n\002AI\020\002\022\r\n\tAnimation\020\003\022\t\n\005"
    "Audio\020\004\022\014\n\010Geometry\020\005\022\013\n\007Graphic\020\006\022\007\n\003Gu"
    "i\020\007\022\t\n\005Input\020\010\022\013\n\007Network\020\t\022\n\n\006Physic\020\nB"
    "9\n)fr.kissy.hellion.definition.encoder.p"
    "rotoB\tSystemDto\210\001\000", 338);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Proto/Common/System.proto", &protobuf_RegisterTypes);
  SystemProto::default_instance_ = new SystemProto();
  SystemProto::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Proto_2fCommon_2fSystem_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Proto_2fCommon_2fSystem_2eproto {
  StaticDescriptorInitializer_Proto_2fCommon_2fSystem_2eproto() {
    protobuf_AddDesc_Proto_2fCommon_2fSystem_2eproto();
  }
} static_descriptor_initializer_Proto_2fCommon_2fSystem_2eproto_;


// ===================================================================

const ::google::protobuf::EnumDescriptor* SystemProto_Type_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SystemProto_Type_descriptor_;
}
bool SystemProto_Type_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const SystemProto_Type SystemProto::None;
const SystemProto_Type SystemProto::Generic;
const SystemProto_Type SystemProto::AI;
const SystemProto_Type SystemProto::Animation;
const SystemProto_Type SystemProto::Audio;
const SystemProto_Type SystemProto::Geometry;
const SystemProto_Type SystemProto::Graphic;
const SystemProto_Type SystemProto::Gui;
const SystemProto_Type SystemProto::Input;
const SystemProto_Type SystemProto::Network;
const SystemProto_Type SystemProto::Physic;
const SystemProto_Type SystemProto::Type_MIN;
const SystemProto_Type SystemProto::Type_MAX;
const int SystemProto::Type_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int SystemProto::kTypeFieldNumber;
const int SystemProto::kPropertiesFieldNumber;
#endif  // !_MSC_VER

SystemProto::SystemProto()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void SystemProto::InitAsDefaultInstance() {
}

SystemProto::SystemProto(const SystemProto& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void SystemProto::SharedCtor() {
  _cached_size_ = 0;
  type_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SystemProto::~SystemProto() {
  SharedDtor();
}

void SystemProto::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SystemProto::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SystemProto::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SystemProto_descriptor_;
}

const SystemProto& SystemProto::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Proto_2fCommon_2fSystem_2eproto();  return *default_instance_;
}

SystemProto* SystemProto::default_instance_ = NULL;

SystemProto* SystemProto::New() const {
  return new SystemProto;
}

void SystemProto::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    type_ = 0;
  }
  properties_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SystemProto::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .SystemProto.Type type = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::SystemProto_Type_IsValid(value)) {
            set_type(static_cast< ::SystemProto_Type >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_properties;
        break;
      }
      
      // repeated .PropertyProto properties = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_properties:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_properties()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_properties;
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void SystemProto::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required .SystemProto.Type type = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->type(), output);
  }
  
  // repeated .PropertyProto properties = 2;
  for (int i = 0; i < this->properties_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->properties(i), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* SystemProto::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required .SystemProto.Type type = 1;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->type(), target);
  }
  
  // repeated .PropertyProto properties = 2;
  for (int i = 0; i < this->properties_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->properties(i), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int SystemProto::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .SystemProto.Type type = 1;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
    }
    
  }
  // repeated .PropertyProto properties = 2;
  total_size += 1 * this->properties_size();
  for (int i = 0; i < this->properties_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->properties(i));
  }
  
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SystemProto::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SystemProto* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SystemProto*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SystemProto::MergeFrom(const SystemProto& from) {
  GOOGLE_CHECK_NE(&from, this);
  properties_.MergeFrom(from.properties_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_type()) {
      set_type(from.type());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SystemProto::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SystemProto::CopyFrom(const SystemProto& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SystemProto::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  
  for (int i = 0; i < properties_size(); i++) {
    if (!this->properties(i).IsInitialized()) return false;
  }
  return true;
}

void SystemProto::Swap(SystemProto* other) {
  if (other != this) {
    std::swap(type_, other->type_);
    properties_.Swap(&other->properties_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SystemProto::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SystemProto_descriptor_;
  metadata.reflection = SystemProto_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
