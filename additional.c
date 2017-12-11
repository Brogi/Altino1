#include <stdio.h>
#include <stdlib.h>


void Auto(int ir1, int ir2, int ir3) {

	if (ir1>180 && ir2>180 && ir3>180) {
		Led(0xC00C);
		Go(-300, -300);
		Steering(1);
	}
	else if (ir1>180 && ir2>180) {
		Led(0x8080);
		Go(-300, -300);
		Steering(1);
	}
	else if (ir1>180) {
		Led(0xC024);
		Go(-300, -300);
		Steering(1);
	}
	else if (ir2>180 && ir3>180) {
		Led(0x4004);
		Go(-300, -300);
		Steering(3);
	}
	else if (ir3>180) {
		Led(0xC00C);
		Go(-300, -300);
		Steering(3);
	}
	else {
		Go(300, 300);
		Steering(2);
	}
}