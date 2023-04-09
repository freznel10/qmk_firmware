#pragma once

#include "pointing_device.h"
#include <stdint.h>
#include <stdbool.h>
#include "debug.h"
#include "report.h"
#include "ps2.h"


const pointing_device_driver_t     ps2_trackpoint_driver_ps2_default;
const pointing_device_ps2_config_t ps2_trackpoint_config_ps2_default;
report_mouse_t ps2_trackpoint_get_report (const void *config);
