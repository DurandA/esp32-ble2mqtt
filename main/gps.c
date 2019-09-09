#include "gps.h"
#include "nmea_parser.h"
#include "wifi.h"
#include <esp_log.h>

/* Constants */
static const char *TAG = "GPS";

static nmea_parser_handle_t nmea_hdl;

int gps_start(void (*gps_event_handler))
{
    /* register event handler for NMEA parser library */
    nmea_parser_add_handler(nmea_hdl, gps_event_handler, NULL);

    return 0;
}

int gps_stop(void (*gps_event_handler))
{
	/* unregister event handler */
    nmea_parser_remove_handler(nmea_hdl, gps_event_handler);

	/* deinit NMEA parser library */
    //nmea_parser_deinit(nmea_hdl);
	return 0;
}

int gps_initialize(void)
{
    ESP_LOGI(TAG, "Initializing GPS");
	/* NMEA parser configuration */
    nmea_parser_config_t config = NMEA_PARSER_CONFIG_DEFAULT();
	config.uart.rx_pin = GPS_TX_PIN;
    /* init NMEA parser library */
    nmea_hdl = nmea_parser_init(&config);

    return 0;
}
