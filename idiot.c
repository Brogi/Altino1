#include "Altino.h"

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

       printf("%d\n", ir4);
    }
}

int main()
{
    Open(szPort);

    dongidea();

    return 0;
}
