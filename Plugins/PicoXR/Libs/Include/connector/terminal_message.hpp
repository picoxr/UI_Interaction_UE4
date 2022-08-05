#pragma once

#include <map>
#include <vector>

#include "../types.h"

namespace pxr
{
    namespace connector
    {
        class TerminalMessage
        {

        public:

            enum class Type
            {
                kInvalid,
                kConnectTo,
                kControllerVibration,
                kSubmitEyeLayer,
                kModifyConfig,
                kSubmitAnIFrame,
                kStatisticsData
            };

            struct Parameter
            {
                enum class Type
                {
                    kInvalid,
                    kInt8,
                    kUInt8,
                    kInt16,
                    kUInt16,
                    kInt32,
                    kUInt32,
                    kInt64,
                    kUInt64,
                    kFloat,
                    kDouble,
                    kString
                };

                std::string describe;
                std::string parameter;
                Type type;
                template <class Archive>
                void serialize(Archive& ar);
            };


            Type GetType_() const;
            void SetType_(Type t);

            p_uint32 GetDestinationTerminalId() const;
            void SetDestinationTerminalId(p_uint32 id);

            void GetParameters(PXR_OUT_VALUE std::vector<Parameter>& out) const;
            void SetParameters(const std::vector<Parameter>& in);

            TerminalMessage() = default;
            ~TerminalMessage() = default;
            TerminalMessage(const TerminalMessage& tm);
            TerminalMessage& operator=(const TerminalMessage& tm);

            template <class Archive>
            void serialize(Archive& ar);
        private:
            Type type_ = Type::kInvalid;
            p_uint32 dst_terminal_id_ = 0;
            std::vector<Parameter> parameters_;
        };

        inline TerminalMessage::Type TerminalMessage::GetType_() const
        {
            return type_;
        }

        inline void TerminalMessage::SetType_(Type t)
        {
            type_ = t;
        }

        inline p_uint32 TerminalMessage::GetDestinationTerminalId() const
        {
            return dst_terminal_id_;
        }

        inline void TerminalMessage::SetDestinationTerminalId(p_uint32 id)
        {
            dst_terminal_id_ = id;
        }

        inline void TerminalMessage::GetParameters(std::vector<Parameter>& out) const
        {
            out = parameters_;
        }

        inline void TerminalMessage::SetParameters(const std::vector<Parameter>& in)
        {
            parameters_ = in;
        }

        inline TerminalMessage::TerminalMessage(const TerminalMessage& tm)
        {
            type_ = tm.type_;
            parameters_ = tm.parameters_;
            dst_terminal_id_ = tm.dst_terminal_id_;
        }

        inline TerminalMessage& TerminalMessage::operator=(const TerminalMessage& tm)
        {
            if (this != &tm)
            {
                type_ = tm.type_;
                parameters_ = tm.parameters_;
                dst_terminal_id_ = tm.dst_terminal_id_;
            }
            return *this;
        }

        template <class Archive>
        void TerminalMessage::serialize(Archive& ar)
        {
            ar(type_);
            ar(parameters_);
            ar(dst_terminal_id_);
        }

        template <class Archive>
        void TerminalMessage::Parameter::serialize(Archive& ar)
        {
            ar(describe);
            ar(parameter);
            ar(type);
        }
    }
}
