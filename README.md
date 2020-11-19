# ESP32-CAM-LCD-Display
Using ESP32 to display OV2640 on ILI9341 LCD

![RunOk](https://raw.githubusercontent.com/hxy513696765/ESP32-CAM-LCD-Display/main/doc/RunOK.jpg)

----

### ESP-CAM开发版原理图
![ESP32-CAM开发版](https://github.com/hxy513696765/ESP32-CAM-LCD-Display/blob/main/doc/ESP32-CAM-AI-Thinker-schematic-diagram.png)
### ESP-CAM引脚定义图
![ESP32-CAM引脚图](https://raw.githubusercontent.com/hxy513696765/ESP32-CAM-LCD-Display/main/doc/ESP32-CAM-pinout.png)

----

### 编译和下载：
#### USB转串口连接到开发版的接线图
![ESP32-CAM下载连接图](https://raw.githubusercontent.com/hxy513696765/ESP32-CAM-LCD-Display/main/doc/UART%20to%20ESP32-CAM.jpeg)

#### 更新ESP32-CAM固件的方法
![ESP-CAM更新固件的方法](https://raw.githubusercontent.com/hxy513696765/ESP32-CAM-LCD-Display/main/doc/Download.png)

#### 具体步骤：
- Step 1: GPIO-0连接到GND

- Step 2: 按一下Rest按钮

- Step 3: make -j4 编译成功

- Step 4: 使用USB转串口连接开发版到电脑然后执行make flash命令就可以直接下载（PS:也可以使用官方的flash_download_tools下载工具进行下载）

- Step 5: 断开GPIO-0和GND的连接

- Step 6: 按一下Rest按钮开发版就可以正常工作了

----

### ESP-CAM和ILI9341 LCD的引脚连接方式

|  Index  | ESP32-CAM Pin | ILI9341 LCD Pin |
| :-----: | :---------: | :---------: |
|    1    |  3.3V(POW)  |     VCC     |
|    2    |     GND     |     GND     |
|    3    |   GPIO12    |     CS      |
|    4    |   GPIO13    |    RESET    |
|    5    |   GPIO15    |    DC/RS    |
|    6    |   GPIO14    |  SDI/MOSI   |
|    7    |    GPIO2    |     SCK     |
|    8    | 3.3V(P_OUT) |     LED     |
|    9    |    GPIO4    |  SDO/MISO   |

----
### ESP32-CAM和ILI9341 LCD的相关文档:
[ESP32使用手册](https://github.com/hxy513696765/ESP32-CAM-LCD-Display/blob/main/doc/esp32_technical_reference_manual_cn.pdf)


[ESP32-CAM原理图文件](https://github.com/hxy513696765/ESP32-CAM-LCD-Display/blob/main/doc/ESP32_CAM_V1.6.pdf)


[OV2640 Datasheet](https://github.com/hxy513696765/ESP32-CAM-LCD-Display/blob/main/doc/OV2640_datasheet_1.8_.pdf)


[2.2寸LCD模块底板原理图](https://github.com/hxy513696765/ESP32-CAM-LCD-Display/blob/main/doc/QDtech_2.2%E5%AF%B8%E5%A4%A9%E9%A9%AC%E6%A8%A1%E5%9D%97%E5%BA%95%E6%9D%BF%E5%8E%9F%E7%90%86%E5%9B%BERev1.2.pdf)


[ILI9341 Datasheet](https://github.com/hxy513696765/ESP32-CAM-LCD-Display/blob/main/doc/ILI9341%20Datasheet.pdf)


[2.2寸LCD模块模块结构尺寸图](https://github.com/hxy513696765/ESP32-CAM-LCD-Display/blob/main/doc/2.2%E5%AF%B8%E4%B8%B2%E5%8F%A3QVGA%E6%A8%A1%E5%9D%97%E7%BB%93%E6%9E%84%E5%B0%BA%E5%AF%B8.pdf)


[液晶屏规格书](https://github.com/hxy513696765/ESP32-CAM-LCD-Display/blob/main/doc/%E6%B6%B2%E6%99%B6%E5%B1%8F%E8%A7%84%E6%A0%BC%E4%B9%A6.pdf)

----

### Tips:
- 1、ESP32-CAM 因为LCD和ESP32-CAM开发板使用同一组的供电需要的电流比较大建议使用手机充电器的充电头。
- 2、ESP32-CAM 开发板上的AMS1117感觉有点不是正品,使用过程中OV2604出来的数据噪声比较大图像画面出现大面积花屏，更换正品的LM1117之后图像画面没有出现大面积花屏问题。

----

### 其它
- ESP32 KIT开发版引脚定义
![ESP32KIT](https://raw.githubusercontent.com/hxy513696765/ESP32-CAM-LCD-Display/main/doc/kit.png)

- 此项目基于[esp32-camera](https://github.com/espressif/esp32-camera)基础上修改完成。
