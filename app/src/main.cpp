#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

//#define SLEEP_TIME_MS 1000 //This variable is replaced by the kconfig.

/* The devicetree node identifier for the "led0" alias. */
#define LED_NODE DT_ALIAS(led0)
//#define LED_NODE DT_NODELABEL(red_led_0) //changing the node label to red_led_0 with the help of  devicetree but in this board there is only one user led "led0".

//#define LED_NODE DT_PATH(leds, ;led_1)  PATH : /leds/led_1  //changing the node label to blue_led_1 with the help of devicetree but in this board there is only one user led "led0".

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);

int main(void)
{
    bool led_state = true;

    if (!gpio_is_ready_dt(&led)) return 0;

    if (gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE) < 0) return 0;

    LOG_INF("Hello Guys, This project is developed by Gopi");

    while (1) {
        if (gpio_pin_toggle_dt(&led) < 0) return 0;

        led_state = !led_state;
        LOG_INF("LED state: %s", led_state ? "ON" : "OFF");
        //k_msleep(SLEEP_TIME_MS); //kconfig variable is added.
        k_msleep(CONFIG_LED_BLINK_SLEEP_TIME_MS);
    }
    return 0;
}
