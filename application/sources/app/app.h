/**
 ******************************************************************************
 * @author: GaoKong
 * @date:   13/08/2016
 ******************************************************************************
 **/

#ifndef __APP_H__
#define __APP_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "ak.h"
#if defined(IF_NETWORK_NRF24_EN)
#include "nrf_nwk_sig.h"
#endif

#include "app_if.h"
#include "app_eeprom.h"
#include "app_data.h"

	/*****************************************************************************/
	/* SYSTEM task define
	 */
	/*****************************************************************************/
	/* define timer */
	/* define signal */
	enum
	{
		SYSTEM_AK_FLASH_UPDATE_REQ = AK_USER_DEFINE_SIG,
	};

/*****************************************************************************/
/* FIRMWARE task define
 */
/*****************************************************************************/
/* define timer */
#define FW_PACKED_TIMEOUT_INTERVAL (5000)
#define FW_UPDATE_REQ_INTERVAL (5000)

	/* define signal */
	enum
	{
		FW_CRENT_APP_FW_INFO_REQ = AK_USER_DEFINE_SIG,
		FW_CRENT_BOOT_FW_INFO_REQ,
		FW_UPDATE_REQ,
		FW_UPDATE_SM_OK,
		FW_TRANSFER_REQ,
		FW_INTERNAL_UPDATE_APP_RES_OK,
		FW_INTERNAL_UPDATE_BOOT_RES_OK,
		FW_SAFE_MODE_RES_OK,
		FW_UPDATE_SM_BUSY,
		FW_PACKED_TIMEOUT,
		FW_CHECKING_REQ
	};

/*********************************************************AC_LIFE_TASK_TIMER_LED_LIFE_INTERVAL********************/
/*  LIFE task define
 */
/*****************************************************************************/
/* define timer */
#define AC_LIFE_TASK_TIMER_LED_LIFE_INTERVAL (1000)

	/* define signal */
	enum
	{
		AC_LIFE_SYSTEM_CHECK = AK_USER_DEFINE_SIG,
	};

	/*****************************************************************************/
	/*  SHELL task define
	 */
	/*****************************************************************************/
	/* define timer */

	/* define signal */
	enum
	{
		AC_SHELL_LOGIN_CMD = AK_USER_DEFINE_SIG,
		AC_SHELL_REMOTE_CMD,
	};

	/*****************************************************************************/
	/*  RF24 task define
	 */
	/*****************************************************************************/
	/* private define */
	/* define timer */
	/* define signal */
	enum
	{
		AC_RF24_IF_INIT_NETWORK = AK_USER_DEFINE_SIG,
		AC_RF24_IF_PURE_MSG_OUT,
		AC_RF24_IF_COMMON_MSG_OUT,
		AC_RF24_IF_PURE_MSG_IN,
		AC_RF24_IF_COMMON_MSG_IN,
	};

	/*****************************************************************************/
	/* IF task define
	 */
	/*****************************************************************************/
	/* define timer */
	/* define signal */
	enum
	{
		AC_IF_PURE_MSG_IN = AK_USER_DEFINE_SIG,
		AC_IF_PURE_MSG_OUT,
		AC_IF_COMMON_MSG_IN,
		AC_IF_COMMON_MSG_OUT,
		AC_IF_DYNAMIC_MSG_IN,
		AC_IF_DYNAMIC_MSG_OUT,
	};

	/*****************************************************************************/
	/* UART_IF task define
	 */
	/*****************************************************************************/
	/* timer signal */
	/* define signal */

	enum
	{
		AC_UART_IF_INIT = AK_USER_DEFINE_SIG,
		AC_UART_IF_PURE_MSG_OUT,
		AC_UART_IF_COMMON_MSG_OUT,
		AC_UART_IF_DYNAMIC_MSG_OUT,
		AC_UART_IF_PURE_MSG_IN,
		AC_UART_IF_COMMON_MSG_IN,
		AC_UART_IF_DYNAMIC_MSG_IN,
	};

	/*	SIGNAL SCREEN GAME ON	*/
	enum 
	{
		SIG_DISPLAY_GAME_ON_SETUP = AK_USER_DEFINE_SIG,
		SIG_DISPLAY_GAME_ON_TICK,

		SIG_DISPLAY_GAME_ON_DOWN_PRESSED,
		SIG_DISPLAY_GAME_ON_UP_PRESSED,
		SIG_DISPLAY_GAME_ON_MODE_PRESSED
	};
	enum
	{
		SIG_DISPLAY_GAME_OVER_DOWN_PRESSED = AK_USER_DEFINE_SIG,
		SIG_DISPLAY_GAME_OVER_MODE_PRESSED,
		SIG_DISPLAY_GAME_OVER_ON_TICK
	};
	/*	SIGNAL WALL	*/
	enum 
	{
		SIG_WALL_SETUP = AK_USER_DEFINE_SIG,
		SIG_WALL_RESET,
		SIG_WALL_UPDATE,
		SIG_WALL_ON_TICK
	};
	/*	SIGNAL PLANE	*/
	enum
	{
		SIG_PLANE_SETUP = AK_USER_DEFINE_SIG,
		SIG_PLANE_DOWN,
		SIG_PLANE_UP,
		SIG_PLANE_CRASH,
		SIG_PLANE_ON_TICK
	};
	/*	SIGNAL MISSLE	*/
	enum
	{
		SIG_MISSLE_PUSH = AK_USER_DEFINE_SIG,
		SIG_MISSLE_MOVE,
		SIG_MISSLE_RESET,
		SIG_MISSLE_CRASH,
		SIG_MISSLE_ON_TICK
	};
	/*	SIGNAL EXPLOSION	*/
	enum
	{
		SIG_EXPLOSION_RESET = AK_USER_DEFINE_SIG,
		SIG_EXPLOSION_PUSH,
		SIG_EXPLOSION_UPDATE,
		SIG_EXPLOSION_ON_TICK
	};
	/*	SIGNAL BOM		*/
	enum
	{
		SIG_BOM_RESET = AK_USER_DEFINE_SIG,
		SIG_BOM_PUSH,
		SIG_BOM_MOVE,
		SIG_BOM_ON_TICK
	};
	/*	SIGNAL MINE		*/
	enum
	{
		SIG_MINE_RESET = AK_USER_DEFINE_SIG,
		SIG_MINE_PUSH,
		SIG_MINE_MOVE,
		SIG_MINE_ON_TICK
	};
/*****************************************************************************/
/*  LIFE task define
 */
/*****************************************************************************/
/* define timer */
#define AC_DISPLAY_INITIAL_INTERVAL (100)
#define AC_DISPLAY_STARTUP_INTERVAL (2000)
#define AC_DISPLAY_LOGO_INTERVAL (10000)
#define AC_DISPLAY_IDLE_INTERVAL (15000)
#define AC_DISPLAY_SHOW_IDLE_BALL_MOVING_UPDATE_INTERAL (150)
#define AC_DISPLAY_SHOW_MERRY_CHRISTMAS_SNOW_MOVING_UPDATE_INTERAL (150)
#define AC_DISPLAY_SHOW_MERRY_CHRISTMAS_SLEEP_INTERVAL (15000)
#define AC_DISPLAY_SHOW_MODBUS_PULL_INTERVAL (1500)
#define AC_DISPLAY_SHOW_MODBUS_PULL_SLEEP_INTERVAL (30000)

/*
	GAME ON TIMER
*/
#define AC_DISPLAY_GAME_ON_INTERVAL (100)

#define AC_WALL_INTERVAL 		(150)
#define AC_EXPLOSION_INTERVAL	(150)
#define AC_BOM_INTERVAL			(150)
#define AC_PLANE_INTERVAL 		(100)
#define AC_MISSLE_INTERVAL		(100)
#define AC_MINE_INTERVAL		(150)

#define AC_MINE_PUSH_INTERNAL	(1500)
#define AC_BOM_PUSH_INTERNAL	(1800)

#define AC_GAME_OVER_INTERNAL	(2000)
	/* define signal */
	enum
	{
		AC_DISPLAY_INITIAL = AK_USER_DEFINE_SIG,
		AC_DISPLAY_BUTON_MODE_RELEASED,
		AC_DISPLAY_BUTON_UP_RELEASED,
		AC_DISPLAY_BUTON_DOWN_RELEASED,

		AC_DISPLAY_BUTON_MODE_LONG_PRESSED,

		AC_DISPLAY_BUTON_MODE_PRESSED,
		AC_DISPLAY_BUTON_UP_PRESSED,
		AC_DISPLAY_BUTON_DOWN_PRESSED,

		AC_DISPLAY_SHOW_LOGO,
		AC_DISPLAY_SHOW_IDLE,
		AC_DISPLAY_SHOW_IDLE_BALL_MOVING_UPDATE,
		AC_DISPLAY_SHOW_FW_UPDATE,
		AC_DISPLAY_SHOW_FW_UPDATE_ERR,
		AC_DISPLAY_SHOW_MERRY_CHRISTMAS_SNOW_MOVING_UPDATE,
		AC_DISPLAY_SHOW_MERRY_CHRISTMAS_SLEEP,
		AC_DISPLAY_SHOW_MODBUS_PULL_UPDATE,
		AC_DISPLAY_SHOW_MODBUS_PULL_SLEEP
	};

	/*****************************************************************************/
	/*  ZIGBEE task define
	 */
	/*****************************************************************************/
	/* define timer */
	/* define signal */
	enum
	{
		AC_ZIGBEE_INIT = AK_USER_DEFINE_SIG,
		AC_ZIGBEE_FORCE_START_COODINATOR,
		AC_ZIGBEE_START_COODINATOR,
		AC_ZIGBEE_PERMIT_JOINING_REQ,
		AC_ZIGBEE_ZCL_CMD_HANDLER
	};

	/*****************************************************************************/
	/* DBG task define
	 */
	/*****************************************************************************/
	/* define timer */
	/* define signal */
	enum
	{
		AC_DBG_TEST_1 = AK_USER_DEFINE_SIG,
	};

/*****************************************************************************/
/*  app function declare
 */
/*****************************************************************************/
#define APP_MAGIC_NUMBER 0xAABBCCDD
#define APP_VER    \
	{              \
		0, 0, 0, 3 \
	}

	typedef struct
	{
		uint32_t magic_number;
		uint8_t version[4];
	} app_info_t;

	extern const app_info_t app_info;

	extern void *app_get_boot_share_data();
	extern int main_app();

#ifdef __cplusplus
}
#endif

#endif //__APP_H__