/**
 * @file
 * Implement USB protocol for stm32f4 series
 * 
 * @author Alexey Zhelonkin
 * @date 2022
 * @license FreeBSD
 */

#ifndef ZHELE_USB_H
#define ZHELE_USB_H

#include <stm32f4xx.h>

#include "../common/usb/device.h"

namespace Zhele::Usb
{
    enum class ClockSource
    {
        Pll,
        PllDividedOneAndHalf
    };
    
    USB_DEVICE_TEMPLATE_ARGS
    template<auto clockSource>
    void USB_DEVICE_TEMPLATE_QUALIFIER::SelectClockSource()
    {
        static_assert(std::is_same_v<decltype(clockSource), Zhele::Usb::ClockSource>, "Clock source argument must be ClockSource enum value.");
    }
}

#endif //! ZHELE_USB_H