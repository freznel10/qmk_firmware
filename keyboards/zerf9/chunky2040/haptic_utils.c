// Copyright 2021 Christoph Rehmann (crehmann)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "haptic_utils.h"

#ifdef HAPTIC_ENABLE
#include "drivers/haptic/DRV2605L.h"
#endif


void process_layer_pulse(layer_state_t state) {
#ifdef HAPTIC_ENABLE
    switch (get_highest_layer(state)) {
        case 1:
            DRV_pulse(soft_bump);
            break;
        case 2:
            DRV_pulse(sh_dblsharp_tick);
            break;
        case 3:
            DRV_pulse(lg_dblclick_str);
            break;
        case 4:
            DRV_pulse(soft_bump);
            break;
        case 5:
            DRV_pulse(pulsing_sharp);
            break;
    }
#endif
}
