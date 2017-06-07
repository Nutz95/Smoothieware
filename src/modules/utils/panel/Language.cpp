/*
      This file is part of Smoothie (http://smoothieware.org/). The motion control part is heavily based on Grbl (https://github.com/simen/grbl).
      Smoothie is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
      Smoothie is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
      You should have received a copy of the GNU General Public License along with Smoothie. If not, see <http://www.gnu.org/licenses/>.
*/

#include "libs/Kernel.h"
#include "Panel.h"

#include "libs/nuts_bolts.h"
#include "libs/utils.h"
#include "checksumm.h"
#include "ConfigValue.h"
#include "Config.h"
#include "Language.h"

#define language_checksum                      CHECKSUM("language")
#define selected_language_checksum             CHECKSUM("selected_language")

#define printing_message_checksum  CHECKSUM("printing")
#define ready_message_checksum     CHECKSUM("ready")
#define back_message_checksum      CHECKSUM("back")
#define status_message_checksum    CHECKSUM("status")
#define z_probe_message_checksum   CHECKSUM("z_probe")
#define home_all_axis_message_checksum     CHECKSUM("home_all_axis")
#define set_home_message_checksum   CHECKSUM("set_home")
#define set_z0_message_checksum     CHECKSUM("set_z0")
#define motors_off_message_checksum CHECKSUM("motors_off")
#define preheat_message_checksum    CHECKSUM("preheat")
#define cool_down_message_checksum  CHECKSUM("cool_down")
#define extruder_message_checksum   CHECKSUM("extruder")
#define set_temperature_message_checksum       CHECKSUM("set_temperature")
#define default_acceleration_message_checksum  CHECKSUM("default_acceleration")
#define xstep_message_checksum        CHECKSUM("xstep")
#define ystep_message_checksum        CHECKSUM("ystep")
#define zstep_message_checksum        CHECKSUM("zstep")
#define z_home_ofs_message_checksum   CHECKSUM("z_home_ofs")
#define contrast_message_checksum     CHECKSUM("contrast")
#define watch_message_checksum        CHECKSUM("watch")
#define clear_halt_message_checksum   CHECKSUM("clear_halt")
#define abort_message_checksum        CHECKSUM("abort")
#define play_message_checksum         CHECKSUM("play")
#define jog_message_checksum          CHECKSUM("jog")
#define preprare_message_checksum     CHECKSUM("preprare")
#define custom_message_checksum       CHECKSUM("custom")
#define configure_message_checksum    CHECKSUM("configure")
#define probe_message_checksum        CHECKSUM("probe")
#define move10mm_message_checksum     CHECKSUM("move10mm")
#define move1mm_message_checksum      CHECKSUM("move1mm")
#define move0_1mm_message_checksum    CHECKSUM("move0_1mm")
#define move0_01mm_message_checksum   CHECKSUM("move0_01mm")
#define extrude_5mm_message_checksum  CHECKSUM("extrude_5mm")
#define retract_5mm_message_checksum  CHECKSUM("retract_5mm")
#define settings_message_checksum     CHECKSUM("settings")
#define estepmm_message_checksum      CHECKSUM("estepmm")
#define filament_diameter_message_checksum     CHECKSUM("filament_diameter")
#define flow_rate_message_checksum     CHECKSUM("flow_rate")
#define accel_message_checksum        CHECKSUM("accel")
#define retract_len_message_checksum  CHECKSUM("retract_len")

Language::Language()
{
    this->current_language          = THEKERNEL->config->value(language_checksum, selected_language_checksum)->by_default("english")->as_string();
    this->current_language_checksum = get_checksum(current_language);
	
	ready_msg      = get_string(ready_message_checksum, "Smoothie ready").c_str();
	printing_msg   = get_string(printing_message_checksum, "Printing").c_str();
	back_msg       = get_string(back_message_checksum, "Back").c_str();
	watch_msg           = get_string(watch_message_checksum, "Watch").c_str();
	clear_halt_msg      = get_string(clear_halt_message_checksum, "Cleart Halt").c_str();
	abort_msg           = get_string(abort_message_checksum, "Abort").c_str();
	play_msg            = get_string(play_message_checksum, "Play").c_str();
	jog_msg             = get_string(jog_message_checksum, "Jog").c_str();
	prepare_msg         = get_string(preprare_message_checksum, "Prepare").c_str();
	custom_msg          = get_string(custom_message_checksum, "Custom").c_str();
	configure_msg       = get_string(configure_message_checksum, "Configure").c_str();
	probe_msg           = get_string(probe_message_checksum, "Probe").c_str();
	status_msg     = get_string(status_message_checksum, "Status").c_str();
	z_probe_msg    = get_string(z_probe_message_checksum, "Z Probe").c_str();
	home_all_axis_msg   = get_string(home_all_axis_message_checksum, "Home All Axes").c_str();
	set_home_msg        = get_string(set_home_message_checksum, "Set Home").c_str();
	set_z0_msg          = get_string(set_z0_message_checksum, "Set Z0").c_str();
	motors_off_msg      = get_string(motors_off_message_checksum, "Motors Off").c_str();
	preheat_msg         = get_string(preheat_message_checksum, "Pre heat").c_str();
	cool_down_msg       = get_string(cool_down_message_checksum, "Cool Down").c_str();
	extruder_msg        = get_string(extruder_message_checksum, "Extruder").c_str();
	set_temperature_msg = get_string(set_temperature_message_checksum, "Set Temperature").c_str();
	default_acceleration_msg  = get_string(default_acceleration_message_checksum, "Default Acceleration").c_str();
	xstep_msg           = get_string(xstep_message_checksum, "X Steps/mm").c_str();
	ystep_msg           = get_string(ystep_message_checksum, "Y Steps/mm").c_str();
	zstep_msg           = get_string(zstep_message_checksum, "Z Steps/mm").c_str();
	estep_msg           = get_string(estepmm_message_checksum, "E Steps/mm").c_str();
	z_home_ofs_msg      = get_string(z_home_ofs_message_checksum, "Z Home Offset").c_str();
	contrast_msg        = get_string(contrast_message_checksum, "Contrast").c_str();
	move10mm_msg        = get_string(move10mm_message_checksum, "Move 10.0mm").c_str();
	move1mm_msg         = get_string(move1mm_message_checksum, "Move  1.0mm").c_str();
	move0_1mm_msg       = get_string(move0_1mm_message_checksum, "Move  0.1mm").c_str();
	move0_01mm_msg      = get_string(move0_01mm_message_checksum, "Move  0.01mm").c_str();
	extrude_5mm_msg     = get_string(extrude_5mm_message_checksum, "Extrude 5mm").c_str();
	retract_5mm_msg     = get_string(retract_5mm_message_checksum, "Retract 5mm").c_str();
	settings_msg        = get_string(settings_message_checksum, "Settings").c_str();
	filament_diameter_msg  = get_string(filament_diameter_message_checksum, "Filament Diameter").c_str();
	flow_rate_msg          = get_string(flow_rate_message_checksum, "Flow Rate").c_str();
	accel_msg              = get_string(accel_message_checksum, "Acceleration").c_str();
	retract_len_msg        = get_string(retract_5mm_message_checksum, "Retract Length").c_str();
	
}

Language::~Language()
{
}

std::string Language::get_current_language()
{
    return this->current_language;
}
std::string Language::get_string(uint16_t string_checksum,const std::string& default_value)
{
    return THEKERNEL->config->value(language_checksum, this->current_language_checksum, string_checksum)->by_default(default_value)->as_string();
}
