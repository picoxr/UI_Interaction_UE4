#pragma once

#include "../types.h"

namespace pxr
{
    namespace connector
    {

        class ControllerAccessory
        {
        public:

            enum class Type
            {
                kUnknown,
                kLeft,
                kRight
            };

            enum class ButtonStatus
            {
                kNone = 0x0000,
                kXAClick = 0x0001,
                kXATouch = 0x0002,
                kYBClick = 0x0004,
                kYBTouch = 0x0008,
                kJoystickClick = 0x0010,
                kJoystickTouch = 0x0020,
                kTriggerClick = 0x0040,
                kTriggerTouch = 0x0080,
                kGripClick = 0x0100,
                kGripTouch = 0x0200,
                kSystemButtonClick = 0x0400,
                kMenuButtonClick = 0x0800,
                kBlankTouch = 0x1000
            };

            enum class ConnectionStatus
            {
                kNotInitialized = 0,
                kDisconnected = 1,
                kConnected = 2,
                kConnecting = 3,
                kError = 4
            };


            void SetRotation_(const p_vector4_f& rotation);
            void GetRotation_(PXR_OUT_VALUE p_vector4_f& rotation) const;

            void SetPosition_(const p_vector3_f& position);
            void GetPosition_(PXR_OUT_VALUE p_vector3_f& position) const;

            void SetVelocity_(const p_vector3_f& velocity);
            void GetVelocity_(PXR_OUT_VALUE p_vector3_f& velocity) const;

            void SetAcceleration_(const p_vector3_f& acceleration);
            void GetAcceleration_(PXR_OUT_VALUE p_vector3_f& acceleration) const;

            void SetAngularVelocity_(const p_vector3_f& angular_velocity);
            void GetAngularVelocity_(PXR_OUT_VALUE p_vector3_f& angular_velocity) const;

            /**
             * \brief The combination of controller button, see the enum class ButtonStatus for all button status.
             * \param status 
             */
            void SetButtonStatus_(p_uint16 status);
            p_uint16 GetButtonStatus_();


            /**
             * \brief
             * \param pos Range from 0~255, so the centre pos is {128, 128}
             */
            void SetJoystickPosition_(p_vector2_f pos);
            p_vector2_f GetJoystickPosition_();


            void SetTriggerValue_(p_float value);
            p_float GetTriggerValue_();


            void SetGripValue_(p_float value);
            p_float GetGripValue_();

            void SetConnectionStatus_(ConnectionStatus status);
            ConnectionStatus GetConnectionStatus_();

            void SetBatteryPercentage_(p_uint8 percentage);
            p_uint8 GetBatteryPercentage_();

            void SetTimestamp_(p_int64 ts);
            p_int64 GetTimestamp_() const;

            void SetIsActive_(p_bool is_active);
            p_bool GetIsActive_() const;

            void SetTerminalId_(p_uint32 id);
            p_uint32 GetTerminalId_() const;

            void SetType_(Type type);
            Type GetType_() const;

            void SetIndex_(p_uint64 index);
            p_uint64 GetIndex_() const;

            ControllerAccessory() = default;
            ControllerAccessory(const ControllerAccessory& a);
            ControllerAccessory& operator=(const ControllerAccessory& a);

            template <class Archive>
            void serialize(Archive& ar);

        private:
            p_vector4_f rotation_ = {};
            p_vector3_f position_ = {};
            p_vector3_f velocity_ = {};
            p_vector3_f acceleration_ = {};
            p_vector3_f angular_velocity_ = {};

            p_bool is_active_ = false;
            p_uint32 terminal_id_ = 0;
            Type type_ = Type::kUnknown;
            p_uint32 button_state_ = 0;
            p_vector2_f joystick_position_ = { 0, 0 };
            p_float trigger_value_ = 0;
            p_float grip_value_ = 0;
            ConnectionStatus connection_status_ = ConnectionStatus::kNotInitialized;
            p_uint8 battery_percentage_ = 0;
            p_int64 timestamp_ = 0;
            p_uint64 index_ = 0;

        };


        inline void ControllerAccessory::SetRotation_(const p_vector4_f& rotation)
        {
            rotation_ = rotation;
        }

        inline void ControllerAccessory::GetRotation_(p_vector4_f& rotation) const
        {
            rotation = rotation_;
        }

        inline void ControllerAccessory::SetPosition_(const p_vector3_f& position)
        {

            position_ = position;
        }

        inline void ControllerAccessory::GetPosition_(p_vector3_f& position) const
        {

            position = position_;
        }

        inline void ControllerAccessory::SetVelocity_(const p_vector3_f& velocity)
        {
            velocity_ = velocity;
        }

        inline void ControllerAccessory::GetVelocity_(p_vector3_f& velocity) const
        {
            velocity = velocity_;
        }

        inline void ControllerAccessory::SetAcceleration_(const p_vector3_f& acceleration)
        {
            acceleration_ = acceleration;
        }

        inline void ControllerAccessory::GetAcceleration_(p_vector3_f& acceleration) const
        {
            acceleration = acceleration_;
        }

        inline void ControllerAccessory::SetAngularVelocity_(const p_vector3_f& angular_velocity)
        {
            angular_velocity_ = angular_velocity;
        }

        inline void ControllerAccessory::GetAngularVelocity_(p_vector3_f& angular_velocity) const
        {
            angular_velocity = angular_velocity_;
        }

        inline void ControllerAccessory::SetIsActive_(bool is_active)
        {
            is_active_ = is_active;
        }

        inline bool ControllerAccessory::GetIsActive_() const
        {
            return is_active_;
        }

        inline void ControllerAccessory::SetTerminalId_(p_uint32 id)
        {
            terminal_id_ = id;
        }

        inline p_uint32 ControllerAccessory::GetTerminalId_() const
        {
            return terminal_id_;
        }

        inline void ControllerAccessory::SetType_(Type type)
        {
            type_ = type;
        }

        inline ControllerAccessory::Type ControllerAccessory::GetType_() const
        {
            return type_;
        }

        inline void ControllerAccessory::SetIndex_(p_uint64 index)
        {
            index_ = index;
        }

        inline p_uint64 ControllerAccessory::GetIndex_() const
        {
            return index_;
        }

        inline void ControllerAccessory::SetButtonStatus_(p_uint16 status)
        {
            button_state_ = status;
        }

        inline p_uint16 ControllerAccessory::GetButtonStatus_()
        {
            return button_state_;
        }


        inline void ControllerAccessory::SetJoystickPosition_(p_vector2_f pos)
        {
            joystick_position_ = pos;
        }

        inline p_vector2_f ControllerAccessory::GetJoystickPosition_()
        {
            return joystick_position_;
        }

        inline void ControllerAccessory::SetTriggerValue_(p_float value)
        {
            trigger_value_ = value;
        }

        inline p_float ControllerAccessory::GetTriggerValue_()
        {
            return trigger_value_;
        }

        inline void ControllerAccessory::SetGripValue_(p_float value)
        {
            grip_value_ = value;
        }

        inline p_float ControllerAccessory::GetGripValue_()
        {
            return grip_value_;
        }

        inline void ControllerAccessory::SetConnectionStatus_(ConnectionStatus status)
        {
            connection_status_ = status;
        }

        inline ControllerAccessory::ConnectionStatus ControllerAccessory::GetConnectionStatus_()
        {
            return connection_status_;
        }

        inline void ControllerAccessory::SetBatteryPercentage_(p_uint8 percentage)
        {
            battery_percentage_ = percentage;
        }

        inline p_uint8 ControllerAccessory::GetBatteryPercentage_()
        {
            return battery_percentage_;
        }

        inline void ControllerAccessory::SetTimestamp_(p_int64 ts)
        {
            timestamp_ = ts;
        }

        inline p_int64 ControllerAccessory::GetTimestamp_() const
        {
            return timestamp_;
        }

        inline ControllerAccessory::ControllerAccessory(const ControllerAccessory& a)
        {
            is_active_ = a.is_active_;
            rotation_ = a.rotation_;
            position_ = a.position_;
            velocity_ = a.velocity_;
            acceleration_ = a.acceleration_;
            angular_velocity_ = a.angular_velocity_;
            terminal_id_ = a.terminal_id_;
            type_ = a.type_;
            button_state_ = a.button_state_;
            joystick_position_ = a.joystick_position_;
            trigger_value_ = a.trigger_value_;
            grip_value_ = a.grip_value_;
            connection_status_ = a.connection_status_;
            battery_percentage_ = a.battery_percentage_;
            timestamp_ = a.timestamp_;
            index_ = a.index_;
        }

        inline ControllerAccessory& ControllerAccessory::operator=(const ControllerAccessory& a)
        {
            if (this != &a)
            {
                is_active_ = a.is_active_;
                rotation_ = a.rotation_;
                position_ = a.position_;
                velocity_ = a.velocity_;
                acceleration_ = a.acceleration_;
                angular_velocity_ = a.angular_velocity_;
                terminal_id_ = a.terminal_id_;
                type_ = a.type_;
                button_state_ = a.button_state_;
                joystick_position_ = a.joystick_position_;
                trigger_value_ = a.trigger_value_;
                grip_value_ = a.grip_value_;
                connection_status_ = a.connection_status_;
                battery_percentage_ = a.battery_percentage_;
                timestamp_ = a.timestamp_;
                index_ = a.index_;

            }
            return *this;
        }


        template <class Archive>
        void ControllerAccessory::serialize(Archive& ar)
        {
            ar(is_active_);
            ar(rotation_);
            ar(position_);
            ar(velocity_);
            ar(acceleration_);
            ar(angular_velocity_);
            ar(terminal_id_);
            ar(type_);
            ar(button_state_);
            ar(joystick_position_);
            ar(trigger_value_);
            ar(grip_value_);
            ar(connection_status_);
            ar(battery_percentage_);
            ar(timestamp_);
            ar(index_);
        }
    }
}
