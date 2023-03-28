#include "mbed.h"

PwmOut PWM1(D6);
AnalogIn Ain(A0);
AnalogIn Ain2(A2);
Thread thread1;
Thread thread2;

void PWM_generator() {
    while (1)
  {
    PWM1.period_ms(5);
    PWM1.pulsewidth_us(double(Ain)*3.3*5000);
    //printf("%f\n\r", PWM1.read());
    ThisThread::sleep_for(50ms);
  }
}

void sensing() {
    while (1)
  {
    printf("%f\n", Ain2.read());
    ThisThread::sleep_for(1ms);
  }
}

int main()
{
  thread1.start(PWM_generator);
  thread2.start(sensing);
}