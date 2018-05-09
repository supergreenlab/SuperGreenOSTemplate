/*
 * =====================================================================================
 *
 *       Filename:  ble_db.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/09/2018 11:58:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "ble_db.h"

#include "misc/log.h"
#include "core/ble_private.h"
#include "core/ble_utils.h"
#include "time/time.h"

const esp_gatts_attr_db_t gatt_db[HRS_IDX_NB] = {
  // Time Service Declaration
  [IDX_TIME_SVC]    =
  {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&primary_service_uuid, ESP_GATT_PERM_READ,
    ESP_UUID_LEN_16, sizeof(TIME_SERVICE), (uint8_t *)TIME_SERVICE}},

  RW_I_NOTIFIABLE_CHAR(IDX_CHAR_TIME, IDX_CHAR_VAL_TIME, IDX_CHAR_CFG_TIME, TIME_UUID),
  R_I_NOTIFIABLE_CHAR(IDX_CHAR_SIMULATED_TIME, IDX_CHAR_VAL_SIMULATED_TIME, IDX_CHAR_CFG_SIMULATED_TIME, SIMULATED_TIME_UUID),
  RW_I_CHAR(IDX_CHAR_START_DATE_MONTH, IDX_CHAR_VAL_START_DATE_MONTH, START_DATE_MONTH_UUID),
  RW_I_CHAR(IDX_CHAR_START_DATE_DAY, IDX_CHAR_VAL_START_DATE_DAY, START_DATE_DAY_UUID),
  RW_I_CHAR(IDX_CHAR_DURATION_DAYS, IDX_CHAR_VAL_DURATION_DAYS, DURATION_DAYS_UUID),
  RW_I_CHAR(IDX_CHAR_SIMULATION_DURATION_DAYS, IDX_CHAR_VAL_SIMULATION_DURATION_DAYS, SIMULATION_DURATION_DAYS_UUID),
  RW_I_CHAR(IDX_CHAR_STARTED_AT, IDX_CHAR_VAL_STARTED_AT, STARTED_AT_UUID)
};

void on_write(esp_ble_gatts_cb_param_t *param) {
  ESP_LOGI(TAG, "on_write");

  // TIME SERVICE
  if (param->write.handle == handle_table[IDX_CHAR_VAL_TIME]) {
    on_set_time(*(uint32_t *)(&param->write.value[0]));
  } else if (param->write.handle == handle_table[IDX_CHAR_VAL_START_DATE_MONTH]) {
    on_set_start_date_month(*(uint32_t *)(&param->write.value[0]));
  } else if (param->write.handle == handle_table[IDX_CHAR_VAL_START_DATE_DAY]) {
    on_set_start_date_day(*(uint32_t *)(&param->write.value[0]));
  } else if (param->write.handle == handle_table[IDX_CHAR_VAL_DURATION_DAYS]) {
    on_set_duration_days(*(uint32_t *)(&param->write.value[0]));
  } else if (param->write.handle == handle_table[IDX_CHAR_VAL_SIMULATION_DURATION_DAYS]) {
    on_set_duration_days(*(uint32_t *)(&param->write.value[0]));
  } else if (param->write.handle == handle_table[IDX_CHAR_VAL_STARTED_AT]) {
    on_set_started_at(*(uint32_t *)(&param->write.value[0]));
  }
}

void on_read(esp_ble_gatts_cb_param_t *param) {
  ESP_LOGI(TAG, "on_read");
}