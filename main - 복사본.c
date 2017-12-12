#include "Altino.h"
int main()
{
    SensorData sens;
    int ir0, ir1, ir2;
    int bright;

    Open(szPort);

    while(1)
    {
        sens = Sensor(10);
        ir0 = sens.IRSensor[0];
        ir1 = sens.IRSensor[1];
        ir2 = sens.IRSensor[2];
        ir3 = sens.IRSensor[3];
        ir4 = sens.IRSensor[4];
        bright = sens.CDSSensor;

        if (ir0 > 10 && ir1 > 10 && ir2 > 10)
        {
            Go(0,0);
            if (ir3 > 10 && ir4 > 10)
            {
                Go(-350,-350);
                Steering(2);
                delay(3000);
            }
            else if (ir3 > 10 || ir2 > 10)
            {
                Go(-350,-350);
                Steering(3);
                delay(3000);
            }
            else if (ir4 > 10 || ir0 > 10)
            {
                Go(-350,-350);
                Steering(1);
                delay(3000);
            }
        }
        else if (ir0 > 10 && ir)
        {
            Go(-350,-350)
            Steering(1);
            delay(3000);

        }
        else
        {
            Go(400,400);
            Steering(2);
        }
    }
    // ¡÷ºÆ
    return 0;


}
