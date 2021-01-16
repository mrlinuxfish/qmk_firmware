#include QMK_KEYBOARD_H

bool i2c_initialized = 0;
i2c_status_t mcp23018_status = 0x20;

void matrix_init_kb(void) {
    // (tied to Vcc for hardware convenience)
    //DDRB  &= ~(1<<4);  // set B(4) as input
    //PORTB &= ~(1<<4);  // set B(4) internal pull-up disabled

    // unused pins - B0, B4, B5, B6, B7, C6, C7, D4, D5, D6, D7, E6, F0, F1, F6, F7
    // set as input with internal pull-up enabled
    DDRB  &= ~(1<<1 | 1<<2 | 1<<3);
    PORTB |=  (1<<1 | 1<<2 | 1<<3);

    PORTD |=  (1<<2 | 1<<3);
    DDRD  &= ~(1<<2 | 1<<3);

    DDRF  &= ~(1<<4 | 1<<5);
    PORTF |=  (1<<4 | 1<<5);

    matrix_init_user();
}
uint8_t init_mcp23018(void) {
    print("starting init");
    mcp23018_status = 0x20;

    // I2C subsystem

    // uint8_t sreg_prev;
    // sreg_prev=SREG;
    // cli();

    if (i2c_initialized == 0) {
        i2c_init();  // on pins D(1,0)
        i2c_initialized = true;
        _delay_ms(1000);
    }
    // i2c_init(); // on pins D(1,0)
    // _delay_ms(1000);

    // set pin direction
    // - unused  : input  : 1
    // - input   : input  : 1
    // - driving : output : 0
    mcp23018_status = i2c_start(I2C_ADDR_WRITE, I2C_TIMEOUT);    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(IODIRA, I2C_TIMEOUT);            if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b11000001, I2C_TIMEOUT);        if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b11111111, I2C_TIMEOUT);        if (mcp23018_status) goto out;
    i2c_stop();

    // set pull-up
    // - unused  : on  : 1
    // - input   : on  : 1
    // - driving : off : 0
    mcp23018_status = i2c_start(I2C_ADDR_WRITE, I2C_TIMEOUT);    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(GPPUA, I2C_TIMEOUT);             if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b11000001, I2C_TIMEOUT);        if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b11111111, I2C_TIMEOUT);        if (mcp23018_status) goto out;

out:
    i2c_stop();
    // SREG=sreg_prev;
    //uprintf("Init %x\n", mcp23018_status);
    return mcp23018_status;
}
