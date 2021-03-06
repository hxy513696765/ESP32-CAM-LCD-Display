/* ESPRESSIF MIT License
 * 
 * Copyright (c) 2018 <ESPRESSIF SYSTEMS (SHANGHAI) PTE LTD>
 * 
 * Permission is hereby granted for use on all ESPRESSIF SYSTEMS products, in which case,
 * it is free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "app_camera.h"
#include "app_wifi.h"
#include "app_httpd.h"
#include "app_mdns.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

#include "nvs_flash.h"
#include "protocol_examples_common.h"

#include "esp_spiffs.h"
#include "spi_lcd.h"

static void test_lcd_task(void *pvParameters){
			
	uint8_t color = 0;
	while(1){

   /*
	    //vTaskDelay(10 / portTICK_PERIOD_MS);
	    //printf("No 1 test_lcd_task..0x%02x,0x%02x\r\n",data[1],data[0]);
	    //ili9341_display_frame(0, 0, 320, 240, data);
	    displayBmpPicture("/weatherlog/MM.bmp");
	    ili9341_display_frame(0, 0, 320, 240, displayBuffer);	    
	    //ili9341_display_frame(0, 0, 32, 32, data);
	    //printf("No 2 test_lcd_task..0x%02x,0x%02x\r\n",data[1],data[0]);
	    //color = color + 0x01;
	    //memset(displayBuffer,color, 320*240); 
	    
	    vTaskDelay(2000 / portTICK_PERIOD_MS);

	    
	    displayBmpPicture("/weatherlog/LM.bmp");
	    ili9341_display_frame(0, 0, 320, 240, displayBuffer);
	    vTaskDelay(2000 / portTICK_PERIOD_MS);
	    
	    displayBmpPicture("/weatherlog/CY.bmp");
	    ili9341_display_frame(0, 0, 320, 240, displayBuffer);
	    vTaskDelay(2000 / portTICK_PERIOD_MS);
	    
	    displayBmpPicture("/weatherlog/CAT.bmp");
	    ili9341_display_frame(0, 0, 320, 240, displayBuffer);
	    vTaskDelay(2000 / portTICK_PERIOD_MS);
	    
	    displayBmpPicture("/weatherlog/GL.bmp");
	    ili9341_display_frame(0, 0, 320, 240, displayBuffer);
	    vTaskDelay(2000 / portTICK_PERIOD_MS);
	    
	    displayBmpPicture("/weatherlog/HD.bmp");
	    ili9341_display_frame(0, 0, 320, 240, displayBuffer);
	    vTaskDelay(2000 / portTICK_PERIOD_MS);
	    
	    //displayBmpPicture("/weatherlog/YL.bmp");	    
	    displayBmpPicture("/weatherlog/NO1.bmp");
	    ili9341_display_frame(0, 0, 320, 240, displayBuffer);
	    vTaskDelay(2000 / portTICK_PERIOD_MS);
	    
	    displayBmpPicture("/weatherlog/CD.bmp");
	    ili9341_display_frame(0, 0, 320, 240, displayBuffer);
	    vTaskDelay(2000 / portTICK_PERIOD_MS);
	    
	    displayBmpPicture("/weatherlog/DQ.bmp");
	    ili9341_display_frame(0, 0, 320, 240, displayBuffer);
	    vTaskDelay(2000 / portTICK_PERIOD_MS);
	*/    
	    //displayBmpPicture("/weatherlog/MM.bmp");
	    ili9341_display_frame(0, 0, 320, 240, displayBuffer);
	    vTaskDelay(2000 / portTICK_PERIOD_MS);

		uint16_t temp_row,temp_col;
		for(temp_row = 0;temp_row < 240;temp_row = temp_row + 80){
			for(temp_col = 0;temp_col < 320;temp_col = temp_col + 80){
				reFreashLcdBuffer("/weatherlog/NO1.bmp",160 - temp_row,temp_col,80,80,0,0);
			    //lcdDisplay("/weatherlog/NO1.bmp",temp_row,temp_col,80,80);
			    ili9341_display_frame(0, 0, 320, 240, displayBuffer);
			    //vTaskDelay(5 / portTICK_PERIOD_MS);
			    printf("row:%d col:%d\r\n",temp_row,temp_col);
			}
		}
		printf("test_lcd_task..\r\n");
	    //printf("No 3 test_lcd_task..0x%02x,0x%02x\r\n",data[1],data[0]);
	}
}

void app_main()
{    
/*
    esp_vfs_spiffs_conf_t conf = {
      .base_path = "/weatherlog",
      .partition_label = NULL,
      .max_files = 2,
      .format_if_mount_failed = false
    };

    // Use settings defined above to initialize and mount SPIFFS filesystem.
    // Note: esp_vfs_spiffs_register is an all-in-one convenience function.
    esp_err_t ret = esp_vfs_spiffs_register(&conf);

*/


    ESP_ERROR_CHECK( nvs_flash_init() );
    
    ili9341_init();
    
    printf("\r\n------------------\r\nDate:%s\r\nTime:%s\r\n------------------\r\n",__DATE__,__TIME__);
    
    
    //xTaskCreatePinnedToCore(&test_lcd_task, "test_lcd_task", 2048, NULL, 2, NULL, 1);
    
    
    app_wifi_main();
    app_camera_main();
    app_httpd_main();
    app_mdns_main();
    /**/
}
