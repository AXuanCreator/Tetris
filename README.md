# Tetris

> To Do

5/10

~~设立方块~~ 

~~设立方块组~~ `未完成初始随机化`

~~方块组的移动~~ `移动完后前面的方块组不会消失` `方块只有一个移动方向` `方块不能旋转`



5/11

~~方块组随机化~~

~~方块移动后清除原来的~~

~~方块移动~~ ~~`还未实现界限判定，应当在block中实现`~~



5/12

~~补充新图形 : 田~~

~~设立地图范围，用数组和0、1，并修改检测函数~~

~~方块自动下落~~

~~方块下落后地图值改变~~

~~方块新生成~~ 

~~方块的转动~~

~~方块转动后的重新判定~~

~~**方块行判定** (重点，当消除行之后如何让上面的方块往下滑)~~



5/13

~~死亡判定~~

~~倒计时运行修复 (移除此功能)~~

~~预先知道下一个生成的方块形状~~

~~分数系统~~



5/14

~~优化~~



> 需注意的点

* 框的移动范围是 : X->[1~37] Y->[1~24]
* 判定可用数组判定，每当落下，当层+1 `非当前任务`
* 多线程的学习



> 已知问题，优先度高

* ~~方块碰撞判定有问题~~
* ~~方块在即将碰撞时变形会出现问题~~
* ~~条形在靠近有边界变形时会形变~~



> 已知问题，但优先度不高

* ~~倒计时运行时，其他程序不能执行~~（功能移除）

> 已知可优化点

* consoleset.h的私有变量short x short y可以将它们放在Point,更加简洁
