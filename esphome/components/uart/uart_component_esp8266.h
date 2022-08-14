#pragma once

#ifdef USE_ESP8266

#include <HardwareSerial.h>
#include <SoftwareSerial.h>
#include <vector>
#include "esphome/core/component.h"
#include "esphome/core/hal.h"
#include "esphome/core/log.h"
#include "uart_component.h"

namespace esphome {
namespace uart {

class ESP8266UartComponent : public UARTComponent, public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
  float get_setup_priority() const override { return setup_priority::BUS; }

  void write_array(const uint8_t *data, size_t len) override;

  bool peek_byte(uint8_t *data) override;
  bool read_array(uint8_t *data, size_t len) override;

  int available() override;
  void flush() override;

  uint32_t get_config();

 protected:
  uint32_t get_sw_config();
  void check_logger_conflict() override;

  HardwareSerial *hw_serial_{nullptr};
  SoftwareSerial *sw_serial_{nullptr};

 private:
  static bool serial0_in_use;  // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
};

}  // namespace uart
}  // namespace esphome

#endif  // USE_ESP8266
