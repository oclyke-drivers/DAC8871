/*
Copyright 2019 Owen Lyke

Permission is hereby granted, free of charge, to any person obtaining a copy of this 
software and associated documentation files (the "Software"), to deal in the Software 
without restriction, including without limitation the rights to use, copy, modify, 
merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit 
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be 
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef _DAC8871_PLATFORM_ESP32_H_
#define _DAC8871_PLATFORM_ESP32_H_

#include "dac8871.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"

typedef struct _dac8871_if_esp32_arg_t {
  spi_device_handle_t     spi;
  spi_host_device_t       host;
  uint32_t                spi_q_size;
  uint32_t                clk_freq;
  int                     clk_pin;
  int                     mosi_pin;
  int                     cs_pin;
  int                     ldac_pin;
  int                     rst_pin;
} dac8871_if_esp32_arg_t;

extern dac8871_if_t dac8871_if_esp32;

#endif // _DAC8871_PLATFORM_ESP32_H_

// This header file provides an ESP32 implementation of the DAX interface
// Example Usage:
/*



*/
