#include <iss_sensors.h>
#include <iss_sensor_if.h>
#include <iss_sensor_priv.h>
#include <app_remote_service.h>
#include <app_ipc.h>

#include "dev_helpers.h"

#define define_dev_printk_level(func, kern_level)		\
void func(const struct device *dev, const char *fmt, ...)	\
{								\
	int length;						\
	char buff[256];						\
	va_list va;						\
	va_start(va, fmt);					\
	length = vsnprintf(buff, sizeof(buff), fmt, va);	\
	va_end(va);						\
								\
	appLogPrintf("%s: %s", dev->name ? dev->name : "NULL", buff); \
								\
	(void)length;						\
}								\

define_dev_printk_level(dev_emerg, KERN_EMERG);
define_dev_printk_level(dev_alert, KERN_ALERT);
define_dev_printk_level(dev_crit, KERN_CRIT);
define_dev_printk_level(dev_err, KERN_ERR);
define_dev_printk_level(dev_warn, KERN_WARNING);
define_dev_printk_level(dev_notice, KERN_NOTICE);
define_dev_printk_level(dev_info, KERN_INFO);
define_dev_printk_level(dev_dbg, KERN_DEBUG);

void usleep_range(unsigned long min, unsigned long max)
{
	/* ????!!!! */
	appLogWaitMsecs((max + 999) / 1000);
}

void mdelay(unsigned long delay)
{
	/* ????!!!! */
	appLogWaitMsecs(delay);
}
