# aweme-algorithm
抖音协议中的加解密算法实现<br>
前两年的工作中涉及到抖音协议的分析部分，分析了两个跟加密有关的接口，项目结束了，现拿出来与大家分享<br>
因为项目结束，最新版本是否有改动不清楚了，当时测试可用的抖音版本：IOS 1.7.8-3.8.0<br>
<br>
1.设备信息生成方案：<br>
设备信息中有几个重点:<br>
(1) carrier、display_name字段：这个字段不是utf-8编码，是GBK编码，要做编码转换<br>
(2) Idfa、VendorID字段：标准UUID算法生成即可<br>
(3) Openudid：这个地方有点头疼，根据所有公开资料，包括抖音自己的代码逆向，都可以看出来实际上是随机生成的，但是随机的没法通过服务器校验，最后使用了真Openudid替换掉中间16字节的方法，服务器通过率在60%左右<br>
<br>
<br>
2./service/2/device_register/接口加密算法：<br>
device_register接口中post包体是加密的，算法实际上是AES，但是不知道为何标准AES实现跑出来的结果不对，不过没关系，直接从IDA伪代码里扒出来即可，中间有5处要修复xray的寄存器解析错误。
<br>
<br>
3.MAS、AS、TS算法：<br>
这部分最头疼，花了很多时间一直想脱机跑，首先伪代码难以修复，因为有两个问题没法解决，1.ios的native API调用（例如线程锁） 2.类的上下文没法初始化，然后Unicorn模拟汇编代码也是一样的问题，没法解决native API调用，最后采用了Hook抖音app的encryptDataWithTimeStamp:parameters函数，然后在Hook代码中阻塞线程，跑个webserver，让抖音app自己初始化类并且准备上下文，然后webserver负责处理加解密，并且返回MAS AS TS<br>
<br>
源码结构简单说明：<br>
1.API是所有加解密的接口，负责给其他需要抖音加解密的业务提供加解密服务，用golang+C混编实现，device_reg的加解密是C写的库文件，通过调用桥调用so，下个部分会说明。<br>
2.aweme-aes是device_reg的加解密实现，纯C代码，编译出来是so库，供上面上面的API调用。<br>
3.ios_aweme_lib的功能是golang->抖音app2lib的桥接，调用流程是API ->ios_aweme_lib ->抖音lib，因为早期的方案是把抖音app2lib，然后通过golang写的webserver（交叉编译到ios）调用这个桥接库，然后调用抖音app，实现encryptDataWithTimeStamp，后来直接采用阻塞app跑webserver的方案后废弃了。<br>
4.ios_webserver，这是Hook抖音app并阻塞encryptDataWithTimeStamp然后跑webserver的实现，框架是monkeydev，框架代码没上传，github上有搜monkeydev就行。<br>
<br>
授权协议：只允许研究、学习目的的分享、使用、修改，不允许任何商业用途。转载请注明出处，感谢。<br>