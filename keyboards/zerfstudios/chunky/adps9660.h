#pragma once

#include <stdint.h>

void adps9660_id(uint8_t *id);

void adps9660_init(void);

void adps9660_proximity(uint8_t *data);

void adps9660_sleep(void);

void adps9660_wake(void);
