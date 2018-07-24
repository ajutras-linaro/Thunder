#ifndef _ITVCONTROL_H
#define _ITVCONTROL_H

#include "Module.h"

#define LINEARBROADCASTPLAYER_PROCESS_NODE_ID "/tmp/LinearBroadcastPlayerProcess0"

namespace WPEFramework {
namespace Exchange {

    struct IStream : virtual public Core::IUnknown {
        enum { ID = 0x00000015 };

        enum Stat {
            TBD = 0
        };

        enum StreamType {
            None
        };

        enum DRMType {
            PlayReady,
            Widevine
        };

        struct IControl : virtual public Core::IUnknown {
            enum { ID = 0x00000017 };

            struct IGeometry : virtual public Core::IUnknown {
                enum { ID = 0x00000018 };

                virtual ~IGeometry() {}

                virtual uint32_t X() const = 0;;
                virtual uint32_t Y() const = 0;
                virtual uint32_t Z() const = 0;
                virtual uint32_t Width() const = 0;
                virtual uint32_t Height() const = 0;
            };

            struct ICallback : virtual public Core::IUnknown {
                enum { ID = 0x00000019 };

                virtual ~ICallback() {}

                virtual void TimeUpdate(uint64_t position) = 0;
            };

            virtual ~IControl() {};

            virtual void Speed(const uint32_t request) = 0;
            virtual uint32_t Speed() const = 0;
            virtual void Position(const uint64_t absoluteTime) = 0;
            virtual uint64_t Position() const = 0;
            virtual void TimeRange(uint64_t& begin, uint64_t& end) const = 0;
            virtual IGeometry* Geometry() const = 0;
            //virtual void Geometry(const IGeometry& settings) = 0;
            virtual void Callback(IControl::ICallback* callback) = 0;
        };

        struct ICallback : virtual public Core::IUnknown  {
            enum { ID = 0x00000016 };

            virtual ~ICallback() {}

            virtual void DRM(uint32_t state) = 0;
            virtual void StateChange(Stat state) = 0;
        };

        virtual ~IStream() {}

        virtual StreamType Type() const = 0;
        virtual DRMType DRM() const = 0;
        virtual IControl* Control() = 0;
        virtual void Callback(IStream::ICallback* callback) = 0;
        virtual Stat State() const = 0;
        virtual uint32_t Load(std::string configuration) = 0;
    };   
}
}
#endif //_ITVCONTROL_H
