#ifndef GPS_H
#define GPS_H

#include "nmea_parser.h"

#define GPS_TX_PIN (33)
#define TIME_ZONE (+2)   //Bern Time
#define YEAR_BASE (2000) //date in GPS starts from 2000

int gps_start(void (*gps_event_handler));
int gps_stop(void (*gps_event_handler));
int gps_initialize(void);

#endif
