#include "show.h"

uint8_t string_buffer1[20];
uint8_t string_buffer2[20];
uint8_t seconds = 0;
uint8_t minutes = 0;

void show_task(void *pvParameters)
{
   u32 lastWakeTime = getSysTickCnt();
	
	 OLED_Refresh_Gram();
	 OLED_ShowString(0,0,"Low Cheng Feng");
   while(1)
    {	

			vTaskDelayUntil(&lastWakeTime, F2T(RATE_50_HZ));
			
			oled_show();    
    }
}  

void oled_show(void)
{  
     //To DO
	 
		OLED_Refresh_Gram();
		OLED_Display_On();

		seconds++;
	  if (seconds%60 == 0){
			minutes++;
		}
		sprintf(string_buffer2 , "%d", minutes);
		OLED_ShowString(10,20,"Minutes:");
		OLED_ShowString(90,20,string_buffer2);
		sprintf(string_buffer1 , "%d", seconds%60);
		OLED_ShowString(10,40,"Second:");
		OLED_ShowString(90,40,string_buffer1);
		OLED_Refresh_Gram();
		vTaskDelay(1000);
		
	
	 //call some function in oled to display something
	 
	 OLED_Refresh_Gram(); //refresh the OLED RAM

	  		
	}

