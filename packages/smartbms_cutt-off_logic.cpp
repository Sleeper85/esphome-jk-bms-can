      // +-----------------------------------------------+
      // | Cut-off Charging Logic                        |
      // +-----------------------------------------------+
      
      // Warning : information from JK BMS is not available immediately after boot
      
      // JK-BMS Alarm !
      if (id(bms1_errors_bitmask).state > 1) id(${smart_bms_id}_charge_status) = "Alarm";
      // JK-BMS Alarm ended
      else if ((id(${smart_bms_id}_charge_status) == "Alarm") & (id(bms1_errors_bitmask).state < 2)) {
        if (id(${smart_bms_id}_eoc) == true) id(${smart_bms_id}_charge_status) = "EOC";
        else id(${smart_bms_id}_charge_status) = "Wait";
      }
      // Float
      else if ((id(${smart_bms_id}_charge_status) == "EOC") & (id(${smart_bms_id}_switch_float).state)) id(${smart_bms_id}_charge_status) = "Float";
      // No Float => EOC
      else if ((id(${smart_bms_id}_charge_status) == "Float") & (!id(${smart_bms_id}_switch_float).state)) id(${smart_bms_id}_charge_status) = "EOC";
      // No Force Bulk => Wait
      else if ((id(${smart_bms_id}_charge_status) == "Force Bulk") & (!id(${smart_bms_id}_switch_force_bulk).state)) id(${smart_bms_id}_charge_status) = "Wait";
      // No Balancing => Wait
      else if ((id(${smart_bms_id}_charge_status) == "Balancing") & (!id(bms1_switch_balancing).state)) id(${smart_bms_id}_charge_status) = "Wait";
      
      // +-----------------------------------------------+
      // | Charge ON : BMS and CAN charging switch is ON |
      // +-----------------------------------------------+
      else if ((id(${smart_bms_id}_switch_charging).state) & (id(${smart_bms_id}_switch_charging).state)) {
      
        // Variables
        float cell_bulk_v = (id(${smart_bms_id}_bulk_voltage).state / id(${smart_bms_id}_cell_count).state);
        float cell_rebulk_v = (id(${smart_bms_id}_rebulk_voltage).state / id(${smart_bms_id}_cell_count).state);
        float cell_absorption_offset_v = (id(${smart_bms_id}_absorption_offset).state / id(${smart_bms_id}_cell_count).state);
        static int eoc_counter = 0;
        
        // Force Bulk Logic
        if (id(${smart_bms_id}_switch_force_bulk).state) {
          // Stop Force Bulk when cells equalizing (charging ends when cells are equalized)
          if (id(${smart_bms_id}_equalizing).state) {
            id(${smart_bms_id}_charge_status) = "Balancing";
            id(${smart_bms_id}_switch_force_bulk).turn_off();
          }
          // Force Bulk
          else id(${smart_bms_id}_charge_status) = "Force Bulk";
        }
        
        // Rebulk Logic (eg: Max Cell V. <= 3.3V)
        else if (id(${smart_bms_id}_max_cell_voltage).state <= cell_rebulk_v) id(${smart_bms_id}_charge_status) = "Bulk";
        
        // Charging Logic
        else if ((id(${smart_bms_id}_charge_status) == "Wait") | (id(${smart_bms_id}_charge_status) == "Bulk") | (id(${smart_bms_id}_charge_status) == "Force Bulk") | (id(${smart_bms_id}_charge_status) == "Balancing") | (id(${smart_bms_id}_charge_status) == "Absorption")) {
        
          // Charging
          if (id(${smart_bms_id}_current).state >= 0) {
            
            float cv_min = ${smart_bms_cutoff_cvmin};
            float cv_max = ${smart_bms_cutoff_cvmax};
            float cutoff_current = (id(${smart_bms_id}_battery_capacity).state * 0.05 * (cell_bulk_v - cv_min) / (cv_max - cv_min));
            float cutoff_voltage = (cv_min + (cv_max - cv_min)/(0.05 + cell_absorption_offset_v) * (id(${smart_bms_id}_current).state / id(${smart_bms_id}_battery_capacity).state));
            
            ESP_LOGI("main", "Cut-Off Current : %f", cutoff_current);
            ESP_LOGI("main", "Cut-Off Voltage : %f", cutoff_voltage);
          
            // Stop Charging
            if ((id(${smart_bms_id}_current).state <= cutoff_current) & (id(${smart_bms_id}_max_cell_voltage).state >= cutoff_voltage)) {
            
              // End Of Charge
              if (!id(${smart_bms_id}_equalizing).state) {
                eoc_counter += 1;
                ESP_LOGI("main", "EOC Cycle Count : %i", eoc_counter);
                if (eoc_counter > ${smart_bms_eoc_cycle_threshold}) {
                  eoc_counter = 0;
                  id(${smart_bms_id}_charge_status) = "EOC";
                }
              }
            
            }
            // Start Charging
            else {
              eoc_counter = 0;
              // Balancing : the BMS is equalizing the cells
              if (id(${smart_bms_id}_equalizing).state) id(${smart_bms_id}_charge_status) = "Balancing";
              // Absorption : Max Cell V. >= Cell Absorption V.
              else if (id(${smart_bms_id}_max_cell_voltage).state >= (cell_bulk_v - cell_absorption_offset_v)) id(${smart_bms_id}_charge_status) = "Absorption";
              // Bulk
              else id(${smart_bms_id}_charge_status) = "Bulk";
          
            }
          }
          // Discharging (!= "EOC" | != "Float")
          else if (id(${smart_bms_id}_max_cell_voltage).state < (cell_bulk_v - cell_absorption_offset_v)) id(${smart_bms_id}_charge_status) = "Bulk";
        }
      }
      // Charge OFF
      else id(${smart_bms_id}_charge_status) = "Wait";
      
      ESP_LOGI("main", "Charge Status : %s", id(${smart_bms_id}_charge_status).c_str());
      return id(${smart_bms_id}_charge_status);