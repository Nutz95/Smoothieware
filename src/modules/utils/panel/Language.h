/*
      This file is part of Smoothie (http://smoothieware.org/). The motion control part is heavily based on Grbl (https://github.com/simen/grbl).
      Smoothie is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
      Smoothie is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
      You should have received a copy of the GNU General Public License along with Smoothie. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "Module.h"
#include <functional>

#include <string>

class Language {
    public:
        Language();
        virtual ~Language();
		std::string current_language;
		uint16_t current_language_checksum;
		
		std::string get_string(uint16_t string_checksum, const std::string& default_value);
		std::string get_string2(uint16_t string_checksum, const std::string& default_value);
		std::string get_current_language();
		
		const char* ready_msg;
		const char* printing_msg;
		const char* back_msg;
		const char* status_msg;
		const char* z_probe_msg;
		const char* home_all_axis_msg;
		const char* set_home_msg;
		const char* set_z0_msg;
		const char* motors_off_msg;
		const char* preheat_msg;
		const char* cool_down_msg;
		const char* extruder_msg;
		const char* set_temperature_msg;
		const char* default_acceleration_msg;
		const char* xstep_msg;
		const char* ystep_msg;
		const char* zstep_msg;
		const char* estep_msg;
		const char* z_home_ofs_msg;
		const char* contrast_msg;
		const char* watch_msg;
		const char* clear_halt_msg;
		const char* abort_msg;
		const char* play_msg;
		const char* jog_msg;
		const char* prepare_msg;
		const char* custom_msg;
		const char* configure_msg;
		const char* probe_msg;
		const char* move10mm_msg;
		const char* move1mm_msg;
		const char* move0_1mm_msg;
		const char* move0_01mm_msg;
		const char* extrude_5mm_msg;
		const char* retract_5mm_msg;
		const char* settings_msg;
		const char* filament_diameter_msg;
		const char* flow_rate_msg;
		const char* accel_msg;
		const char* retract_len_msg;
	private:
};

#endif
