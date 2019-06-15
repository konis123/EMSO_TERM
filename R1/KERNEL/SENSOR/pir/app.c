#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "../../../lib/SENSOR/sensor_lib.h"

#define ALERT_DISTANCE 10


/*pir기다리는 함수*/
int wait_for_pir(){
	
	if(pir_wait()==0){
		return 0;
	}
	else{
		return -1;
	}
}


/*거리 재는 함수*/
int get_ultrasonic(int dev){
	int dist;
	dist = read_ultrasonic_sensor(dev);
	
	return dist;
}


int main(){
	int time = 0;
	int dev;
	dev=open_ultrasonic_sensor();

	
	while(1){
			if(wait_for_pir()==0){
			printf("detected.\n");
				while(time<=10){
					time=(clock()/CLOCKS_PER_SEC);
					printf("distance : %d\n",get_ultrasonic(dev));
					if(get_ultrasonic(dev)<ALERT_DISTANCE){
						printf("%d\n",time);
						break;	
					}
				}
			}
		}	
	
	close_ultrasonic_sensor(dev);

	return 0;	
}
