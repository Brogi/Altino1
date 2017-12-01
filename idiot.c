#include "Altino.h"

void print_IR_value(int ir)
{
    printf("%d\n", ir);
}

void dongidea()
{
    SensorData sens;
    int ir0, ir1, ir2, ir3, ir4, ir5;

     while(1)
    {
        sens = Sensor(10);
        ir0 = sens.IRSensor[0];
        ir1 = sens.IRSensor[1];
        ir2 = sens.IRSensor[2];
        ir3 = sens.IRSensor[3];
        ir4 = sens.IRSensor[4];
        ir5 = sens.IRSensor[5];

        if (ir4 > 100)
        {
            Steering(2);
        }
        else if (ir4 <= 100 && ir4 > 20)
        {
            Steering(1);
        }
        else
        {
            Steering(0);
        }
    }
}

int main()
{
    Open(szPort);

    Go(400, 400);
    dongidea();

    return 0;
}
