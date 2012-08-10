// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Proto/Server/DownstreamMessage.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* DownstreamMessageProto_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  DownstreamMessageProto_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* DownstreamMessageProto_Type_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_Proto_2fServer_2fDownstreamMessage_2eproto() {
  protobuf_AddDesc_Proto_2fServer_2fDownstreamMessage_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Proto/Server/DownstreamMessage.proto");
  GOOGLE_CHECK(file != NULL);
  DownstreamMessageProto_descriptor_ = file->message_type(0);
  static const int DownstreamMessageProto_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DownstreamMessageProto, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DownstreamMessageProto, data_),
  };
  DownstreamMessageProto_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      DownstreamMessageProto_descriptor_,
      DownstreamMessageProto::default_instance_,
      DownstreamMessageProto_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DownstreamMessageProto, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DownstreamMessageProto, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(DownstreamMessageProto));
  DownstreamMessageProto_Type_descriptor_ = DownstreamMessageProto_descriptor_->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Proto_2fServer_2fDownstreamMessage_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    DownstreamMessageProto_descriptor_, &DownstreamMessageProto::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Proto_2fServer_2fDownstreamMessage_2eproto() {
  delete DownstreamMessageProto::default_instance_;
  delete DownstreamMessageProto_reflection_;
}

void protobuf_AddDesc_Proto_2fServer_2fDownstreamMessage_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n$Proto/Server/DownstreamMessage.proto\"l"
    "\n\026DownstreamMessageProto\022*\n\004type\030\001 \002(\0162\034"
    ".DownstreamMessageProto.Type\022\014\n\004data\030\002 \001"
    "(\014\"\030\n\004Type\022\020\n\014AUTHENTICATE\020\001B1\n\026fr.kissy"
    ".hellion.protoB\024DownstreamMessageDto\210\001\000", 199);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Proto/Server/DownstreamMessage.proto", &protobuf_RegisterTypes);
  DownstreamMessageProto::default_instance_ = new DownstreamMessageProto();
  DownstreamMessageProto::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Proto_2fServer_2fDownstreamMessage_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Proto_2fServer_2fDownstreamMessage_2eproto {
  StaticDescriptorInitializer_Proto_2fServer_2fDownstreamMessage_2eproto() {
    protobuf_AddDesc_Proto_2fServer_2fDownstreamMessage_2eproto();
  }
} static_descriptor_initializer_Proto_2fServer_2fDownstreamMessage_2eproto_;


// ===================================================================

const ::google::protobuf::EnumDescriptor* DownstreamMessageProto_Type_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return DownstreamMessageProto_Type_descriptor_;
}
bool DownstreamMessageProto_Type_IsValid(int value) {
  switch(value) {
    case 1:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const DownstreamMessageProto_Type DownstreamMessageProto::AUTHENTICATE;
const DownstreamMessageProto_Type DownstreamMessageProto::Type_MIN;
const DownstreamMessageProto_Type DownstreamMessageProto::Type_MAX;
const int DownstreamMessageProto::Type_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int DownstreamMessageProto::kTypeFieldNumber;
const int DownstreamMessageProto::kDataFieldNumber;
#endif  // !_MSC_VER

DownstreamMessageProto::DownstreamMessageProto()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void DownstreamMessageProto::InitAsDefaultInstance() {
}

DownstreamMessageProto::DownstreamMessageProto(const DownstreamMessageProto& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void DownstreamMessageProto::SharedCtor() {
  _cached_size_ = 0;
  type_ = 1;
  data_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

DownstreamMessageProto::~DownstreamMessageProto() {
  SharedDtor();
}

void DownstreamMessageProto::SharedDtor() {
  if (data_ != &::google::protobuf::internal::kEmptyString) {
    delete data_;
  }
  if (this != default_instance_) {
  }
}

void DownstreamMessageProto::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* DownstreamMessageProto::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return DownstreamMessageProto_descriptor_;
}

const DownstreamMessageProto& DownstreamMessageProto::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Proto_2fServer_2fDownstreamMessage_2eproto();  return *default_instance_;
}

DownstreamMessageProto* DownstreamMessageProto::default_instance_ = NULL;

DownstreamMessageProto* DownstreamMessageProto::New() const {
  return new DownstreamMessageProto;
}

void DownstreamMessageProto::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    type_ = 1;
    if (has_data()) {
      if (data_ != &::google::protobuf::internal::kEmptyString) {
        data_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool DownstreamMessageProto::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .DownstreamMessageProto.Type type = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::DownstreamMessageProto_Type_IsValid(value)) {
            set_type(static_cast< ::DownstreamMessageProto_Type >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_data;
        break;
      }
      
      // optional bytes data = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_data:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_data()));
        } else {
          goto handle_uninterpreted;
        }
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

void DownstreamMessageProto::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required .DownstreamMessageProto.Type type = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->type(), output);
  }
  
  // optional bytes data = 2;
  if (has_data()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      2, this->data(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* DownstreamMessageProto::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required .DownstreamMessageProto.Type type = 1;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->type(), target);
  }
  
  // optional bytes data = 2;
  if (has_data()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->data(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int DownstreamMessageProto::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .DownstreamMessageProto.Type type = 1;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
    }
    
    // optional bytes data = 2;
    if (has_data()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->data());
    }
    
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

void DownstreamMessageProto::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const DownstreamMessageProto* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const DownstreamMessageProto*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void DownstreamMessageProto::MergeFrom(const DownstreamMessageProto& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_data()) {
      set_data(from.data());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void DownstreamMessageProto::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DownstreamMessageProto::CopyFrom(const DownstreamMessageProto& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DownstreamMessageProto::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  
  return true;
}

void DownstreamMessageProto::Swap(DownstreamMessageProto* other) {
  if (other != this) {
    std::swap(type_, other->type_);
    std::swap(data_, other->data_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata DownstreamMessageProto::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = DownstreamMessageProto_descriptor_;
  metadata.reflection = DownstreamMessageProto_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
