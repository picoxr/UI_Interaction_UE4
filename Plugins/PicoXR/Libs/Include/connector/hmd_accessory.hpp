#pragma once

#include "../types.h"

namespace pxr
{
    namespace connector
    {

        class HmdAccessory
        {
        public:

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

            void SetAngularAcceleration_(const p_vector3_f& angular_acceleration);
            void GetAngularAcceleration_(PXR_OUT_VALUE p_vector3_f& angular_acceleration) const;

            void SetLinearVelocity_(const p_vector3_f& linear_velocity);
            void GetLinearVelocity_(PXR_OUT_VALUE p_vector3_f& linear_velocity) const;

            void SetLinearAcceleration_(const p_vector3_f& linear_acceleration);
            void GetLinearAcceleration_(PXR_OUT_VALUE p_vector3_f& linear_acceleration) const;

            void SetConnectionStatus_(ConnectionStatus status);
            ConnectionStatus GetConnectionStatus_();

            void SetBatteryPercentage_(p_uint8 percentage);
            p_uint8 GetBatteryPercentage_();

            void SetIsActive_(p_bool is_active);
            p_bool GetIsActive_() const;

            void SetTerminalId_(p_uint32 id);
            p_uint32 GetTerminalId_() const;


            /**
             * \brief 
             * \param ipd Interpupillary distance in millimeter(mm)
             */
            void SetIpd_(p_float ipd);
            p_float GetIpd_();

            void SetTimestamp_(p_int64 ts);
            p_int64 GetTimestamp_() const;

            void SetIndex_(p_uint64 index);
            p_uint64 GetIndex_() const;



            HmdAccessory() = default;
            HmdAccessory(const HmdAccessory& a);
            HmdAccessory& operator=(const HmdAccessory& a);

            template <class Archive>
            void serialize(Archive& ar);

        private:
            p_vector4_f rotation_ = {};
            p_vector3_f position_ = {};
            p_vector3_f velocity_ = {};
            p_vector3_f acceleration_ = {};
            
            p_vector3_f angular_velocity_ = {};
            p_vector3_f angular_acceleration_ = {};
            p_vector3_f linear_velocity_ = {};
            p_vector3_f linear_acceleration_ = {};

            p_bool is_active_ = false;
            p_uint32 terminal_id_ = 0;

            ConnectionStatus connection_status_ = ConnectionStatus::kNotInitialized;
            p_uint8 battery_percentage_ = 0;
            p_float ipd_ = 0;
            p_int64 timestamp_ = 0;

            p_uint64 index_ = 0;
        };


        inline void HmdAccessory::SetRotation_(const p_vector4_f& rotation)
        {
            rotation_ = rotation;
        }

        inline void HmdAccessory::GetRotation_(p_vector4_f& rotation) const
        {
            rotation = rotation_;
        }

        inline void HmdAccessory::SetPosition_(const p_vector3_f& position)
        {

            position_ = position;
        }

        inline void HmdAccessory::GetPosition_(p_vector3_f& position) const
        {

            position = position_;
        }

        inline void HmdAccessory::SetVelocity_(const p_vector3_f& velocity)
        {
            velocity_ = velocity;
        }

        inline void HmdAccessory::GetVelocity_(p_vector3_f& velocity) const
        {
            velocity = velocity_;
        }

        inline void HmdAccessory::SetAcceleration_(const p_vector3_f& acceleration)
        {
            acceleration_ = acceleration;
        }

        inline void HmdAccessory::GetAcceleration_(p_vector3_f& acceleration) const
        {
            acceleration = acceleration_;
        }

        inline void HmdAccessory::SetAngularVelocity_(const p_vector3_f& angular_velocity)
        {
            angular_velocity_ = angular_velocity;
        }

        inline void HmdAccessory::GetAngularVelocity_(PXR_OUT_VALUE p_vector3_f& angular_velocity) const
        {
            angular_velocity = angular_velocity_;
        }

        inline void HmdAccessory::SetAngularAcceleration_(const p_vector3_f& angular_acceleration)
        {
            angular_acceleration_ = angular_acceleration;
        }

        inline void HmdAccessory::GetAngularAcceleration_(PXR_OUT_VALUE p_vector3_f& angular_acceleration) const
        {
            angular_acceleration = angular_acceleration_;
        }

        inline void HmdAccessory::SetLinearVelocity_(const p_vector3_f& linear_velocity)
        {
            linear_velocity_ = linear_velocity;
        }

        inline void HmdAccessory::GetLinearVelocity_(PXR_OUT_VALUE p_vector3_f& linear_velocity) const
        {
            linear_velocity = linear_velocity_;
        }

        inline void HmdAccessory::SetLinearAcceleration_(const p_vector3_f& linear_acceleration)
        {
            linear_acceleration_ = linear_acceleration;
        }

        inline void HmdAccessory::GetLinearAcceleration_(PXR_OUT_VALUE p_vector3_f& linear_acceleration) const
        {
            linear_acceleration = linear_acceleration_;
        }

        inline void HmdAccessory::SetIsActive_(p_bool is_active)
        {
            is_active_ = is_active;
        }

        inline bool HmdAccessory::GetIsActive_() const
        {
            return is_active_;
        }

        inline void HmdAccessory::SetTerminalId_(p_uint32 id)
        {
            terminal_id_ = id;
        }

        inline p_uint32 HmdAccessory::GetTerminalId_() const
        {
            return terminal_id_;
        }

        inline void HmdAccessory::SetIpd_(p_float ipd)
        {
            ipd_ = ipd;
        }

        inline p_float HmdAccessory::GetIpd_()
        {
            return ipd_;
        }

        inline void HmdAccessory::SetTimestamp_(p_int64 ts)
        {
            timestamp_ = ts;
        }

        inline p_int64 HmdAccessory::GetTimestamp_() const
        {
            return timestamp_;
        }

        inline void HmdAccessory::SetIndex_(p_uint64 index)
        {
            index_ = index;
        }

        inline p_uint64 HmdAccessory::GetIndex_() const
        {
            return index_;
        }

        inline void HmdAccessory::SetConnectionStatus_(ConnectionStatus status)
        {
            connection_status_ = status;
        }

        inline HmdAccessory::ConnectionStatus HmdAccessory::GetConnectionStatus_()
        {
            return connection_status_;
        }

        inline void HmdAccessory::SetBatteryPercentage_(p_uint8 percentage)
        {
            battery_percentage_ = percentage;
        }

        inline p_uint8 HmdAccessory::GetBatteryPercentage_()
        {
            return battery_percentage_;
        }

        inline HmdAccessory::HmdAccessory(const HmdAccessory& a)
        {
            is_active_ = a.is_active_;
            rotation_ = a.rotation_;
            position_ = a.position_;
            velocity_ = a.velocity_;
            acceleration_ = a.acceleration_;
            angular_velocity_ = a.angular_velocity_;
            angular_acceleration_ = a.angular_acceleration_;
            linear_velocity_ = a.linear_velocity_;
            linear_acceleration_ = a.linear_acceleration_;
            terminal_id_ = a.terminal_id_;
            connection_status_ = a.connection_status_;
            battery_percentage_ = a.battery_percentage_;
            ipd_ = a.ipd_;
            timestamp_ = a.timestamp_;
            index_ = a.index_;
        }

        inline HmdAccessory& HmdAccessory::operator=(const HmdAccessory& a)
        {
            if (this != &a)
            {
                is_active_ = a.is_active_;
                rotation_ = a.rotation_;
                position_ = a.position_;
                velocity_ = a.velocity_;
                acceleration_ = a.acceleration_;
                angular_velocity_ = a.angular_velocity_;
                angular_acceleration_ = a.angular_acceleration_;
                linear_velocity_ = a.linear_velocity_;
                linear_acceleration_ = a.linear_acceleration_;
                terminal_id_ = a.terminal_id_;
                connection_status_ = a.connection_status_;
                battery_percentage_ = a.battery_percentage_;
                ipd_ = a.ipd_;
                timestamp_ = a.timestamp_;
                index_ = a.index_;
            }
            return *this;
        }


        template <class Archive>
        void HmdAccessory::serialize(Archive& ar)
        {
            ar(is_active_);
            ar(rotation_);
            ar(position_);
            ar(velocity_);
            ar(acceleration_);
            ar(angular_velocity_);
            ar(angular_acceleration_);
            ar(linear_velocity_);
            ar(linear_acceleration_);
            ar(terminal_id_);
            ar(connection_status_);
            ar(battery_percentage_);
            ar(ipd_);
            ar(timestamp_);
            ar(index_);
        }
    }
}
