package config

modules wifi: _CORE_MODULE

modules wifi fields status: _INT8 & _BLE & _HTTP & {
  _default_var: "DISCONNECTED"
  ble uuid: "{0x17,0xfe,0xc3,0xc1,0x6b,0xe1,0x15,0x54,0xa5,0x74,0x55,0x9c,0x81,0x69,0xa3,0x5c}"
}

modules wifi fields ssid: _STRING & _NVS & _BLE_RW & _HTTP_RW & {
  ble uuid: "{0x17,0xfe,0xc3,0xc1,0x6b,0xe1,0x15,0x54,0xa5,0x74,0x55,0x9c,0x81,0x69,0xa3,0x6c}"
  ble notify: false
  nosend: true
  nvs key: "WSSID"
  write_cb: true
}

modules wifi fields password: _STRING & _NVS & _BLE_RW & _HTTP_RW & {
  ble uuid: "{0x17,0xfe,0xc3,0xc1,0x6b,0xe1,0x15,0x54,0xa5,0x74,0x55,0x9c,0x81,0x69,0xa3,0x7c}"
  ble no_sync: true
  nosend: true
  nvs key: "WPASS"
  write_cb: true
}

modules wifi fields ap_ssid: _STRING & _NVS & _HTTP_RW & {
  nvs key: "WAPSSID"
  _default_var: "DEFAULT_AP_SSID"
}

modules wifi fields ap_password: _STRING & _NVS & _HTTP_RW & {
  nvs key: "WAPPASS"
  _default_var: "DEFAULT_AP_PASSWORD"
}

modules wifi fields mdns_domain: _STRING & _NVS & _HTTP_RW & {
  name: "mdns_domain"
  nvs key: "MDNSD"
  default: string | *"supergreendriver"
  write_cb: true
}

modules wifi fields ip: _STRING & _BLE & _HTTP & {
  ble uuid: "{0x17,0xfe,0xc3,0xc1,0x6b,0xe1,0x15,0x54,0xa5,0x74,0x55,0x9c,0x81,0x69,0xa3,0x8c}"
}