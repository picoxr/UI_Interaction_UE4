#pragma once

#include "../types.h"
#include "hmd_accessory.hpp"
#include "controller_accessory.hpp"

namespace pxr
{
    namespace connector
    {
        class TerminalAccessory
        {

        public:
            void SetHmdAccessory_(const HmdAccessory& hmd);
            void GetHmdAccessory_(PXR_OUT_VALUE HmdAccessory& hmd) const;
            HmdAccessory* GetHmdAccessoryPtr();

            void SetControllerAccessory_(ControllerAccessory::Type type, const ControllerAccessory& accessory);
            void GetControllerAccessory_(ControllerAccessory::Type type, PXR_OUT_VALUE ControllerAccessory& accessory_out) const;
            ControllerAccessory* GetControllerAccessoryPtr(ControllerAccessory::Type type);

            void SetTerminalId_(p_uint32 id);
            p_uint32 GetTerminalId_() const;

            void SetIsActive_(p_bool active);
            p_bool GetIsActive_() const;

            TerminalAccessory() = default;
            ~TerminalAccessory() = default;
            TerminalAccessory(const TerminalAccessory& ta);
            TerminalAccessory& operator=(const TerminalAccessory& ta);

            template <class Archive>
            void serialize(Archive& ar);

        private:


        private:
            p_bool is_active_ = false;
            p_uint32 terminal_id_ = 0;
            HmdAccessory hmd_info_;
            ControllerAccessory left_controller_info_;
            ControllerAccessory right_controller_info_;
        };

        inline void TerminalAccessory::SetHmdAccessory_(const HmdAccessory& hmd)
        {
            hmd_info_ = hmd;
        }

        inline void TerminalAccessory::GetHmdAccessory_(PXR_OUT_VALUE HmdAccessory& hmd) const
        {
            hmd = hmd_info_;
        }

        inline HmdAccessory* TerminalAccessory::GetHmdAccessoryPtr()
        {
            return &(this->hmd_info_);
        }

        inline void TerminalAccessory::SetControllerAccessory_(ControllerAccessory::Type type
            , const ControllerAccessory& accessory)
        {
            switch (type)
            {
            case ControllerAccessory::Type::kLeft:
                left_controller_info_ = accessory;
                break;
            case ControllerAccessory::Type::kRight:
                right_controller_info_ = accessory;
                break;
            default:;
            }
        }

        inline void TerminalAccessory::GetControllerAccessory_(ControllerAccessory::Type type
            , PXR_OUT_VALUE ControllerAccessory& accessory_out) const
        {
            switch (type)
            {
            case ControllerAccessory::Type::kLeft:
                accessory_out = left_controller_info_;
                break;
            case ControllerAccessory::Type::kRight:
                accessory_out = right_controller_info_;
                break;
            default:
                accessory_out = ControllerAccessory();
            }
        }

        inline ControllerAccessory* TerminalAccessory::GetControllerAccessoryPtr(ControllerAccessory::Type type)
        {
            ControllerAccessory* r = p_nullptr;
            switch (type)
            {
            case ControllerAccessory::Type::kLeft:
                r = &(this->left_controller_info_);
                break;
            case ControllerAccessory::Type::kRight:
                r = &(this->right_controller_info_);
                break;
            default:
                r = p_nullptr;
            }

            return r;
        }

        inline void TerminalAccessory::SetTerminalId_(p_uint32 id)
        {
            terminal_id_ = id;
        }

        inline p_uint32 TerminalAccessory::GetTerminalId_() const
        {
            return terminal_id_;
        }

        inline void TerminalAccessory::SetIsActive_(bool active)
        {
            is_active_ = active;
        }

        inline p_bool TerminalAccessory::GetIsActive_() const
        {
            return is_active_;
        }

        inline TerminalAccessory::TerminalAccessory(const TerminalAccessory& ta)
        {
            is_active_ = ta.is_active_;
            hmd_info_ = ta.hmd_info_;
            left_controller_info_ = ta.left_controller_info_;
            right_controller_info_ = ta.right_controller_info_;
            terminal_id_ = ta.terminal_id_;
        }

        inline TerminalAccessory& TerminalAccessory::operator=(const TerminalAccessory& ta)
        {
            if (this != &ta)
            {
                is_active_ = ta.is_active_;
                hmd_info_ = ta.hmd_info_;
                left_controller_info_ = ta.left_controller_info_;
                right_controller_info_ = ta.right_controller_info_;
                terminal_id_ = ta.terminal_id_;
            }
            return *this;
        }

        template <class Archive>
        void TerminalAccessory::serialize(Archive& ar)
        {
            ar(is_active_);
            ar(hmd_info_);
            ar(left_controller_info_);
            ar(right_controller_info_);
            ar(terminal_id_);
        }


    }
}
