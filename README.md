# Algorithm-homework
  保存这个学期（2022-2023）《算法设计与分析》这门课程的代码    
  第一次将代码上传到github，有很多不熟练的地方，下面把过程和一些tips写一下（防止下一次又忘了）   
  以第四周的代码为例：  
  右键选择Git Bash Here
  ![image](https://github.com/howareyouandyou/Algorithm-homework/assets/99010752/26e7c63e-9e8c-4574-b08c-fd4b66d401fa)

  出现界面，输入命令： 
  ```
  git add .    
  git commit -m "week4"  #这里是备注  
 ```
  ![image](https://github.com/howareyouandyou/Algorithm-homework/assets/99010752/5b429067-b1d1-4343-b03b-4250f6cd92a7)  
  
  最后输入：
  `git push -u origin main`  
  连接成功：  
  ![image](https://github.com/howareyouandyou/Algorithm-homework/assets/99010752/25609268-cd4a-4ce2-a380-d37125fb56cf)  
  
  注意！连接超时的话要关闭梯子  
  
  经常遇到push失败的问题：  
  ![image](https://github.com/howareyouandyou/Algorithm-homework/assets/99010752/e3dce707-cb39-4a69-b256-392c2c8ee940)  
  
  采用了这篇文章的方法：https://zhuanlan.zhihu.com/p/422024766  
  push前先将远程repository修改pull下来，然后再推送  
  ```
  git pull origin main   
  git push -u origin main
  ```
  
  修改备注：  
  https://www.cnblogs.com/hapday/p/13327856.html  
  https://blog.csdn.net/weixin_44867717/article/details/111350746

