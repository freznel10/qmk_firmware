

const pointing_device_driver_t sk8707_driver_default = {.init = ps2_mouse_init, .get_report = pimoroni_trackball_get_raw_report, .set_cpi = NULL, .get_cpi = NULL};
// const pointing_device_ps2_config_t psk8707_config_default = {.address = PIMORONI_TRACKBALL_ADDRESS, .timeout = PIMORONI_TRACKBALL_TIMEOUT };
