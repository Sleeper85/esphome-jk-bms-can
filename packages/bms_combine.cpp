          // Combine Datas
          if (id(${bms_id}_combine).state) {

            // Combine one time
            if (id(${bms_id}_combined) == false) {
              // bms_counter
              id(${smart_bms_id}_bms_counter) += 1;
              // cell_count
              id(${smart_bms_id}_cell_count) = id(${bms_id}_cell_count).state;
              // max_charge_current TOTAL
              id(${smart_bms_id}_total_max_charge_current) += id(${bms_id}_max_charge_current).state;
              // max_discharge_current TOTAL
              id(${smart_bms_id}_total_max_discharge_current) += id(${bms_id}_max_discharge_current).state;
              // battery_capacity TOTAL
              id(${smart_bms_id}_total_battery_capacity) += id(${bms_id}_battery_capacity).state;
              // Combined
              id(${bms_id}_combined) = true;
            }

            // Combine continuously
            if (id(${smart_bms_id}_combined_bms_counter) < id(${smart_bms_id}_bms_counter)) {
              // min_cell_voltage MIN
              if (id(${bms_id}_min_cell_voltage).state < id(${smart_bms_id}_min_min_cell_voltage)) id(${smart_bms_id}_min_min_cell_voltage) = id(${bms_id}_min_cell_voltage).state;
              // max_cell_voltage MAX
              if (id(${bms_id}_max_cell_voltage).state > id(${smart_bms_id}_max_max_cell_voltage)) id(${smart_bms_id}_max_max_cell_voltage) = id(${bms_id}_max_cell_voltage).state;
              // cell_ovp MIN
              if (id(${bms_id}_cell_ovp).state < id(${smart_bms_id}_min_cell_ovp)) id(${smart_bms_id}_min_cell_ovp) = id(${bms_id}_cell_ovp).state;
              // cell_ovpr MIN
              if (id(${bms_id}_cell_ovpr).state < id(${smart_bms_id}_min_cell_ovpr)) id(${smart_bms_id}_min_cell_ovpr) = id(${bms_id}_cell_ovpr).state;
              // cell_uvpr MAX
              if (id(${bms_id}_cell_uvpr).state > id(${smart_bms_id}_max_cell_uvpr)) id(${smart_bms_id}_max_cell_uvpr) = id(${bms_id}_cell_uvpr).state;
              // temperature_sensor_1 MAX
              if (id(${bms_id}_temperature_sensor_1).state > id(${smart_bms_id}_max_temperature_sensor_1)) id(${smart_bms_id}_max_temperature_sensor_1) = id(${bms_id}_temperature_sensor_1).state;
              // temperature_sensor_2 MAX
              if (id(${bms_id}_temperature_sensor_2).state > id(${smart_bms_id}_max_temperature_sensor_2)) id(${smart_bms_id}_max_temperature_sensor_2) = id(${bms_id}_temperature_sensor_2).state;
              // total_voltage TOTAL
              id(${smart_bms_id}_total_total_voltage) += id(${bms_id}_total_voltage).state;
              // current TOTAL
              id(${smart_bms_id}_total_current) += id(${bms_id}_current).state;
              // power TOTAL
              id(${smart_bms_id}_total_power) += id(${bms_id}_power).state;
              // soc TOTAL
              id(${smart_bms_id}_total_soc) += id(${bms_id}_state_of_charge).state;
              // capacity_remaining_ah SUM
              id(${smart_bms_id}_total_capacity_remaining_ah) += id(${bms_id}_capacity_remaining_ah).state;
              // charging_cycles MEAN
              id(${smart_bms_id}_total_charging_cycles) += id(${bms_id}_charging_cycles).state;
              // BMS combined counter
              id(${smart_bms_id}_combined_bms_counter) += 1;
            }

            // Equalizing
            if ((id(${bms_id}_combined_equalizing) == false) & (id(${bms_id}_equalizing).state == true)) {
              id(${smart_bms_id}_equalizing_counter) += 1;
              id(${bms_id}_combined_equalizing) = true;
            }
            else if ((id(${bms_id}_combined_equalizing) == true) & (id(${bms_id}_equalizing).state == false)) {
              id(${smart_bms_id}_equalizing_counter) -= 1;
              id(${bms_id}_combined_equalizing) = false;
            }

          }
          // Uncombine Datas
          else if (id(${bms_id}_combined)){

            // BMS counter
            id(${smart_bms_id}_bms_counter) -= 1;
            // max_charge_current TOTAL
            id(${smart_bms_id}_total_max_charge_current) -= id(${bms_id}_max_charge_current).state;
            // max_discharge_current TOTAL
            id(${smart_bms_id}_total_max_discharge_current) -= id(${bms_id}_max_discharge_current).state;
            // battery_capacity TOTAL
            id(${smart_bms_id}_total_battery_capacity) -= id(${bms_id}_battery_capacity).state;

            // Equalizing
            if (id(${bms_id}_combined_equalizing) == true) {
              id(${smart_bms_id}_equalizing_counter) -= 1;
              id(${bms_id}_combined_equalizing) = false;
            }

            id(${bms_id}_combined) = false;

          }
