/*
 *
 *
 */
#ifndef _APP_EDT_SERVER_COMMON
#define _APP_EDT_SERVER_COMMON

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <TI/tivx.h>
#include <app_init.h>

#define APP_DEBUG
#define APP_USE_FILEIO

#ifdef APP_DEBUG
#define APP_PRINTF(f_, ...) printf((f_), ##__VA_ARGS__)
#else
#define APP_PRINTF(f_, ...)
#endif

#endif
