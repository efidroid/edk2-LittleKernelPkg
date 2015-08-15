#ifndef __LITTLEKERNELAPI_PLATFORM_H__
#define __LITTLEKERNELAPI_PLATFORM_H__

enum lkapi_handler_return {
	LKAPI_INT_NO_RESCHEDULE = 0,
	LKAPI_INT_RESCHEDULE,
};
typedef enum lkapi_handler_return (*lkapi_int_handler)(void *arg);

typedef void (*lkapi_timer_callback_t)(void);

typedef struct {
	void (*platform_early_init)(void);

	int (*serial_poll_char)(void);
	void (*serial_write_char)(char c);
	char (*serial_read_char)(void);

	int (*timer_register_handler)(lkapi_timer_callback_t handler);
	void (*timer_set_period)(UINT64 period);
	void (*timer_delay_microseconds)(unsigned int microseconds);
	void (*timer_delay_nanoseconds)(unsigned int nanoseconds);

	int (*int_mask)(unsigned int vector);
	int (*int_unmask)(unsigned int vector);
	void (*int_register_handler)(unsigned int vector, lkapi_int_handler func, void *arg);
} lkapi_t;

#endif
