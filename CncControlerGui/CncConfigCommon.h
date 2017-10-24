#ifndef CNC_CONFIG_COMMON_H
#define CNC_CONFIG_COMMON_H

	#define Attribute_READONLY						"READONLY"
	
	#define CncConfig_MAX_SPEED_XY 					"Cnc.Config/MAX_SPEED_XY"
	#define CncConfig_MAX_SPEED_Z 					"Cnc.Config/MAX_SPEED_Z"
	#define CncConfig_DEF_SPEED_MODE_XY				"Cnc.Config/DEF_SPEED_MODE_XY"
	#define CncConfig_DEF_SPEED_MODE_Z				"Cnc.Config/DEF_SPEED_MODE_Z"
	#define CncConfig_DEF_RAPID_SPEED_XY 			"Cnc.Config/DEF_RAPID_SPEED_XY"
	#define CncConfig_DEF_RAPID_SPEED_Z 			"Cnc.Config/DEF_RAPID_SPEED_Z"
	#define CncConfig_DEF_WORK_SPEED_XY 			"Cnc.Config/DEF_WORK_SPEED_XY"
	#define CncConfig_DEF_WORK_SPEED_Z 				"Cnc.Config/DEF_WORK_SPEED_Z"
	#define CncConfig_DEF_RAPID_SPEED_XY			"Cnc.Config/DEF_RAPID_SPEED_XY"
	#define CncConfig_DEF_RAPID_SPEED_Z 			"Cnc.Config/DEF_RAPID_SPEED_Z"
	#define CncConfig_DEF_WORK_SPEED_XY 			"Cnc.Config/DEF_WORK_SPEED_XY"
	#define CncConfig_DEF_WORK_SPEED_Z 				"Cnc.Config/DEF_WORK_SPEED_Z"
	#define CncConfig_MAX_DIMENSION_X 				"Cnc.Config/MAX_DIMENSION_X"
	#define CncConfig_MAX_DIMENSION_Y 				"Cnc.Config/MAX_DIMENSION_Y"
	#define CncConfig_MAX_DIMENSION_Z 				"Cnc.Config/MAX_DIMENSION_Z"
	#define CncConfig_STEPS_X 						"Cnc.Config/STEPS_X"
	#define CncConfig_STEPS_Y 						"Cnc.Config/STEPS_Y"
	#define CncConfig_STEPS_Z 						"Cnc.Config/STEPS_Z"
	#define CncConfig_PITCH_X 						"Cnc.Config/PITCH_X"
	#define CncConfig_PITCH_Y 						"Cnc.Config/PITCH_Y"
	#define CncConfig_PITCH_Z 						"Cnc.Config/PITCH_Z"
	#define CncConfig_MULTIPLIER_X 					"Cnc.Config/MULTIPLIER_X"
	#define CncConfig_MULTIPLIER_Y 					"Cnc.Config/MULTIPLIER_Y"
	#define CncConfig_MULTIPLIER_Z 					"Cnc.Config/MULTIPLIER_Z"
	#define CncConfig_PULS_WIDTH_OFFSET_X 			"Cnc.Config/PULS_WIDTH_OFFSET_X"
	#define CncConfig_PULS_WIDTH_OFFSET_Y 			"Cnc.Config/PULS_WIDTH_OFFSET_Y"
	#define CncConfig_PULS_WIDTH_OFFSET_Z 			"Cnc.Config/PULS_WIDTH_OFFSET_Z"

	#define CncRuntime_DISPLAY_FACT_X 				"#/CncRuntime/DISPLAY_FACT_X"
	#define CncRuntime_DISPLAY_FACT_Y 				"#/CncRuntime/DISPLAY_FACT_Y"
	#define CncRuntime_DISPLAY_FACT_Z 				"#/CncRuntime/DISPLAY_FACT_Z"
	#define CncRuntime_DISPLAY_FACT_3D_X 			"#/CncRuntime/DISPLAY_FACT_3D_X"
	#define CncRuntime_DISPLAY_FACT_3D_Y 			"#/CncRuntime/DISPLAY_FACT_3D_Y"
	#define CncRuntime_DISPLAY_FACT_3D_Z 			"#/CncRuntime/DISPLAY_FACT_3D_Z"
	#define CncRuntime_CALCULATION_FACT_X 			"#/CncRuntime/CALCULATION_FACT_X"
	#define CncRuntime_CALCULATION_FACT_Y 			"#/CncRuntime/CALCULATION_FACT_Y"
	#define CncRuntime_CALCULATION_FACT_Z 			"#/CncRuntime/CALCULATION_FACT_Z"
	
	#define CncRuntime_Z_MAX_DURATIONS				"#/CncRuntime/Z_MAX_DURATIONS"
	#define CncRuntime_Z_WORKPIECE_OFFSET			"#/CncRuntime/Z_WORKPIECE_OFFSET"
	#define CncRuntime_Z_MAX_DURATION_THICKNESS		"#/CncRuntime/Z_MAX_DURATION_THICKNESS"
	#define CncRuntime_Z_CALCULATED_DURATIONS		"#/CncRuntime/Z_CALCULATED_DURATIONS"
	#define CncRuntime_Z_CURRENT_Z_DISTANCE			"#/CncRuntime/Z_CURRENT_Z_DISTANCE"
	#define CncRuntime_Z_WORKPIECE_INCLUDED			"#/CncRuntime/Z_WORKPIECE_INCLUDED"
	#define CncRuntime_Z_DURATION_THICKNESS			"#/CncRuntime/Z_DURATION_THICKNESS"
	
	#define CncApplication_DEF_DISPLAY_UNIT 		"CncApplication/DEF_DISPLAY_UNIT"
	#define CncApplication_AUTO_CONNECT 			"CncApplication/AUTO_CONNECT"
	#define CncApplication_AUTO_PROCESS 			"CncApplication/AUTO_PROCESS"
	#define CncApplication_SHOW_TEST_MENU 			"CncApplication/SHOW_TEST_MENU"
	#define CncApplication_USE_SETTER_LIST 			"CncApplication/USE_SETTER_LIST"
	#define CncApplication_CLEAR_SETTER_LIST 		"CncApplication/CLEAR_SETTER_LIST"
	#define CncApplication_CONFIRMATION_MODE		"CncApplication/CONFIRMATION_MODE"
	#define CncApplication_Com_DEFALT_PORT 			"CncApplication.Port/DEFAULT_PORT"
	#define CncApplication_Tpl_DEFALT_DIRECTORY		"CncApplication.Template/DEFAULT_DIRECTORY"
	#define CncApplication_Tpl_DEFALT_FILE 			"CncApplication.Template/DEFAULT_FILE"
	#define CncApplication_Tool_SVG_FILE_VIEWER 	"CncApplication.Tools/SVG_FILE_VIEWER"
	#define CncApplication_Tool_GCODE_FILE_VIEWER 	"CncApplication.Tools/GCODE_FILE_VIEWER"
	#define CncApplication_Tool_XML_FILE_VIEWER 	"CncApplication.Tools/XML_FILE_VIEWER"
	#define CncApplication_Tool_EXTERNAL_EDITOR 	"CncApplication.Tools/EXTERNAL_EDITOR"
	#define CncApplication_Tool_PY_CAM 				"CncApplication.Tools/PY_CAM"
	
	#define CncSvg_Parser_REVERSE_Y_AXIS			"CncSvg.Parser/REVERSE_Y_AXIS"
	#define CncSvg_Emu_COPY_FACTOR					"CncSvg.Emu/COPY_FACTOR"
	#define CncSvg_Emu_RSLT_WITH_ORIG_PATH			"CncSvg.Emu/RESULT_WITH_ORIG_PATH"
	#define CncSvg_Emu_RSLT_ONLY_WITH_FIRST_CROSS	"CncSvg.Emu/RESULT_ONLY_WITH_FIRST_CROSSING"
	
	#define CncWork_Tool_TYPE						"CncWork.Tool/TYPE"
	#define CncWork_Tool_DIAMETER					"CncWork.Tool/DIAMETER"
	#define CncWork_Wpt_THICKNESS					"CncWork.Workpiece/THICKNESS"
	#define CncWork_Wpt_MAX_THICKNESS_CROSS			"CncWork.Workpiece/MAX_THICKNESS_PER_CROSSING"
	#define CncWork_Ctl_REPLY_THRESHOLD				"CncWork.Controller/REPLAY_THRESHOLD"

#endif