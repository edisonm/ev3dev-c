
/*  ev3_dc.h was generated by yup.py (yupp) 0.8b7
    out of ev3_dc.yu-h at 2015-07-24 14:13
 *//**
 *  \file  ev3_dc.h (ev3_dc.yu-h)
 *  \brief  EV3 DC Motors.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#ifndef EV3_DC_H
#define EV3_DC_H

#ifdef  EV3_DC_IMPLEMENT
#define EV3_DC_EXT
#define EV3_DC_EXT_INIT( dec, init ) \
	dec = init
#else
#define EV3_DC_EXT extern
#define EV3_DC_EXT_INIT( dec, init ) \
	extern dec
#endif

#ifndef COMMA
#define COMMA   ,
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  \defgroup ev3_dc DC Motors
 *  \brief Access to EV3 DC Motors.
 *  \see http://www.ev3dev.org/docs/motors/
 *  \see http://www.ev3dev.org/docs/drivers/dc-motor-class/
 *  \{
 */

#define DC_DIR  "/sys/class/dc-motor"  /**< Directory of DC motors. */

/**
 *  \brief Structure of a DC motor descriptor.
 */
typedef struct {
	inx_t type_inx;  /**< DC motor type. */
	uint8_t port;  /**< DC motor EV3 port. */
	uint8_t extport;  /**< DC motor extended port. */

} EV3_DC;

#define DC_DESC__LIMIT_  64  /**< Limit of DC motor descriptors. */

#define DC__NONE_  DC_DESC__LIMIT_  /**< DC motor is not found. */

/**
 *  \brief Vector of DC motor descriptors (filled by \ref ev3_dc_init).
 */
EV3_DC_EXT EV3_DC ev3_dc[ DC_DESC__LIMIT_ ];

/**
 *  \brief Identifiers of DC motor types.
 */
enum {
	DC_TYPE__NONE_ = 0,  /* XXX: memset( 0 ) is used */

	RCX_MOTOR,

	DC_TYPE__COUNT_,  /**< Count of DC motor types. */
	DC_TYPE__UNKNOWN_ = DC_TYPE__COUNT_
};

/**
 *  \brief Identifiers of DC motor commands.
 */
enum {
	DC_COMMAND__NONE_ = 0,

	RCX_MOTOR_RUN_FOREVER, 				
	RCX_MOTOR_RUN_TIMED, 				
	RCX_MOTOR_STOP, 

	DC_COMMAND__COUNT_,  /**< Count of DC motor commands. */
	DC_COMMAND__UNKNOWN_ = DC_COMMAND__COUNT_
};

/**
 *  \brief Identifiers of DC motor stop_commands.
 */
enum {
	DC_STOP_COMMAND__NONE_ = 0,

	RCX_MOTOR_COAST, 				
	RCX_MOTOR_BRAKE, 

	DC_STOP_COMMAND__COUNT_,  /**< Count of DC motor stop_commands. */
	DC_STOP_COMMAND__UNKNOWN_ = DC_STOP_COMMAND__COUNT_
};

/**
 *  \brief Common identifiers of DC motor commands.
 */
enum {
	DC_COMMAND__NULL_ = 0,

	DC_RUN_FOREVER,
	DC_RUN_TIMED,
	DC_STOP,

};

/**
 *  \brief Common identifiers of DC motor stop commands.
 */
enum {
	DC_STOP_COMMAND__NULL_ = 0,

	DC_COAST,
	DC_BRAKE,

};

/**
 *  \brief Common identifiers of DC motor states.
 */
enum {
	DC_STATE__NONE_ = 0,

	DC_RUNNING = 0x1L,
	DC_RAMPING = 0x2L,

};

/**
 *  \brief Write "command" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_DC_EXT size_t set_dc_command( uint8_t sn, char *value );

/**
 *  \brief Read "commands" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_commands( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Read "driver_name" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_driver_name( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Read "duty_cycle" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_duty_cycle( uint8_t sn, int *buf );

/**
 *  \brief Read "duty_cycle_sp" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_duty_cycle_sp( uint8_t sn, int *buf );

/**
 *  \brief Write "duty_cycle_sp" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_DC_EXT size_t set_dc_duty_cycle_sp( uint8_t sn, int value );

/**
 *  \brief Read "polarity" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_polarity( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Write "polarity" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_DC_EXT size_t set_dc_polarity( uint8_t sn, char *value );

/**
 *  \brief Read "port_name" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_port_name( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Read "state" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_state( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Write "stop_command" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_DC_EXT size_t set_dc_stop_command( uint8_t sn, char *value );

/**
 *  \brief Read "stop_commands" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_stop_commands( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Read "ramp_down_sp" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_ramp_down_sp( uint8_t sn, int *buf );

/**
 *  \brief Write "ramp_down_sp" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_DC_EXT size_t set_dc_ramp_down_sp( uint8_t sn, int value );

/**
 *  \brief Read "ramp_up_sp" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_ramp_up_sp( uint8_t sn, int *buf );

/**
 *  \brief Write "ramp_up_sp" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_DC_EXT size_t set_dc_ramp_up_sp( uint8_t sn, int value );

/**
 *  \brief Read "time_sp" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_time_sp( uint8_t sn, int *buf );

/**
 *  \brief Write "time_sp" attribute of the DC motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_DC_EXT size_t set_dc_time_sp( uint8_t sn, int value );

/**
 *  \brief Get name of the specified DC motor type.
 *  \param type_inx Index of the DC motor type.
 *  \return Requested value.
 */
EV3_DC_EXT const char *ev3_dc_type( inx_t type_inx );

/**
 *  \brief Read "driver_name" attribute and get index of the DC motor type.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_DC_EXT inx_t get_dc_type_inx( uint8_t sn );

/**
 *  \brief Read the DC motor attributes that are required for filling the descriptor.
 *  \param sn Sequence number.
 *  \param desc Buffer for the descriptor.
 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_desc( uint8_t sn, EV3_DC *desc );

/**
 *  \brief Get descriptor of the DC motor.
 *  \param sn Sequence number.
 *  \return Pointer to the DC motor descriptor.
 */
EV3_DC_EXT EV3_DC *ev3_dc_desc( uint8_t sn );

/**
 *  \brief Get type from the DC motor descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_DC_EXT inx_t ev3_dc_desc_type_inx( uint8_t sn );

/**
 *  \brief Get EV3 port from the DC motor descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_DC_EXT uint8_t ev3_dc_desc_port( uint8_t sn );

/**
 *  \brief Get extended port from the DC motor descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_DC_EXT uint8_t ev3_dc_desc_extport( uint8_t sn );

/**
 *  \brief Assemble EV3 port name from the DC motor descriptor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \return Requested value.
 */
EV3_DC_EXT char *ev3_dc_port_name( uint8_t sn, char *buf );

/**
 *  \brief Search of a sequence number of the specified DC motor type.
 *  \param type_inx The DC motor type.
 *  \param[out] sn Buffer for the sequence number.
 *  \param from Search initial value.
 *  \return Flag - the DC motor is found.
 */
EV3_DC_EXT bool ev3_search_dc( inx_t type_inx, uint8_t *sn, uint8_t from );

/**
 *  \brief Search of a sequence number the DC motor by plug-in attributes.
 *  \param port EV3 port.
 *  \param extport Extended port.
 *  \param[out] sn Buffer for the sequence number.
 *  \param from Search initial value.
 *  \return Flag - the DC motor is found.
 */
EV3_DC_EXT bool ev3_search_dc_plugged_in( uint8_t port, uint8_t extport, uint8_t *sn, uint8_t from );

/**
 *  \brief Get name of the specified DC motor command.
 *  \param command_inx Index of the DC motor command.
 *  \return Requested value.
 */
EV3_DC_EXT const char *ev3_dc_command( inx_t command_inx );

/**
 *  \brief Write "command" attribute of the DC motor by the index.
 *  \param sn Sequence number.
 *  \param command_inx Index of the DC motor command.
 *  \return Count of written bytes.
 */
EV3_DC_EXT size_t set_dc_command_inx( uint8_t sn, inx_t command_inx );

/**
 *  \brief Get name of the specified DC motor stop_command.
 *  \param stop_command_inx Index of the DC motor stop_command.
 *  \return Requested value.
 */
EV3_DC_EXT const char *ev3_dc_stop_command( inx_t stop_command_inx );

/**
 *  \brief Write "stop_command" attribute of the DC motor by the index.
 *  \param sn Sequence number.
 *  \param stop_command_inx Index of the DC motor stop_command.
 *  \return Count of written bytes.
 */
EV3_DC_EXT size_t set_dc_stop_command_inx( uint8_t sn, inx_t stop_command_inx );

/**
 *  \brief Read "state" attribute of the DC motor and get the flags.
 *  \param sn Sequence number.
 *  \param desc Buffer for the flags.
 *  \return Count of read bytes.
 */
EV3_DC_EXT size_t get_dc_state_flags( uint8_t sn, flags_t *flags );

/**
 *  \brief Detect connected DC motors.
 *  \return The number of found DC motors or -1 in case of an error.
 */
EV3_DC_EXT int ev3_dc_init( void );

/** \} */

#ifdef __cplusplus
}
#endif

#endif

