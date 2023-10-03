### 下载Arduino并配置ESP32环境

#### 一、下载并安装Arduino

- 直接去官网，根据自己的电脑配置自行下载

- https://www.arduino.cc/en/software

- 注意下载==1.8.19版本==而不是2.21版本

  (什么？你下错版本了？那就只能删掉重下了)

#### 二、配置ESP32环境

+ 在文件->首选项中

  + 修改一下项目文件夹的位置，不要放在c盘
  + 设置附加开发板管理器的网址https://dl.espressif.com/dl/package_esp32_index.json
  + 点击确定，关闭窗口

+ 然后进入工具->开发板->开发板管理器中

+ 搜索esp32 下载

  ![image-20231003155153300](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20231003155153300.png)

  + 下载时需要科学上网，最好用手机热点下载
  + 下载时候往往会出错，如果出错，多试几次即可。
  + 建议是最好不要用离线包，真的很不靠谱（）


#### 三、项目测试

OK接下来你就需要来实验室试一下你的环境到底有没有安好

+ 先把板子（ESP32）连接到电脑上
+ 然后在`工具->开发板->esp32` 选择板子对应的型号
+ ![image-20231003155855823](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20231003155855823.png)

+ 在`工具->端口`里选择你连接的端口

+ ![屏幕截图 2023-10-03 160023](C:\Users\Lenovo\Pictures\Screenshots\屏幕截图 2023-10-03 160023.png)

+ 用一个简单的测试代码试一下

  ```
  void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
  }
  void loop(){
    Serial.println("hello world!");
    delay(1000);
  }
  ```

+ 然后点击左上角的一个向右的小箭头，进行上传（第一次编译可能有点慢）

+ 如果输出窗口显示`Hard resetting via RTS pin...`就表示上传成功了