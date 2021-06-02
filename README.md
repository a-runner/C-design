# C-design

### 上传的是本人当初的C++课程设计的代码，绝对保证真实性，均由本人独立完成。
主要功能的实现放在了doxc文件中。

#### 缺点：
* 由于由本人独立编写，虽然几乎全部实现了功能，但是逻辑结构可能不是很流畅，不是很方便别人阅读。
* 由于完成的时间较短，难免存在一些纰漏和未检验的bug。

### 大致包括以下功能

* 复数计数器

  **项目说明**
    该项目是要求设计一个小型实用复数计算器，可以完成复数的加减操作。
    
  **设计提示** 
  1. 对复数计算器程序总体功能作出设计，每种功能都用菜单选项列出，用户可根据需要选择相应菜单 项，从而执行不同子程序完成相应功能。对每个子程序分别进行   功能设计。 
  2. 将复数形式的数据定义成一个复数类 CComplex，重载上述运算符象一般数据运算一样方便。 
  3. 实际应用中，重载输入运算符应能识别 a+bi，a，bi，−a，− bi，+ i，− i，i 等形式多样的复数。重载 输入函数应考虑各种输入形式。 
  4. 设计一个复数运算的测试函数，其功能是让计算机随机出 10 道运算题，用户给出答案，同时计算机 实时判断对错并打分。 
  5. 使用文件保存程序运行的结果和操作

* 学校图书管理系统
  ==项目说明==
    该项目要求设计一个图书管理系统，支持系统用户的图书借阅、图书管理、用户管理等功能。图书借阅主要包括图书借阅、图书归还、借阅信息查看等功能。图书管   理主要包括图书的增加、删除、修改、查看、统计等功能。用户管理主要包括用户注册、登录、修改密码、修改个人信息、设置用户类型等功能。
  **设计要求**
  1. 显示菜单项，支持用户输入菜单项编号循环选择并执行各功能。
  2. 系统中用户分为：读者、图书管理员、系统管理员。系统管理员可以对读者、图书管理员等系统用户进行增加、删除、权限管理；图书管理员可以对书目进行增加、   修改、查询、统计等管理；读者可以实现对图书的借阅、归还。
  3. 根据不同类型用户，登录系统显示不同的用户功能菜单，实现不同的操作处理，如学生与教师所借
  阅书的数量和天数均不相同。
  4. 借阅图书时，对已到所能借阅图书的最大数量给予提示；归还图书时，图书已超期需要缴纳罚款。
  5. 实现将馆藏图书信息、借阅记录等保存到磁盘，形成日志文件。
* 网上超市购物管理
  ==项目说明==
    每人独立设计能够完成小型超市购物管理功能的程序。
  **设计要求**
  1. 商品基本信息
      * 商品代码，商品名称，商品价格，商品库存。
      * 设计约定：可以假定超市有 N 种商品，在系统启动时将这些商品信息加载到商品库中。
  2. 顾客信息
      * 普通顾客属性：ID（顾客代码）（随机生成或流水号）
      * 普通会员：ID（会员代码），会员姓名，会员电话，会员积分。
      * 高级会员：ID（会员代号），会员姓名，会员电话，会员积分，副卡 ID。 
  3. 购物管理
      * 为每一个普通顾客生成临时顾客代码。
      * 普通会员购买商品时，可享受 9.8 折，普通顾客在单次购物满 1000 元，添加个人基本信息后，可成为普通会员。
      * 高级会员购买商品时，可享受 9.5 折，普通顾客在单次购物满 2000 元，添加个人基本信息后，或普通会员单次购物满 1000 元可成为高级会员。普通会员和   高级会员可查询 1 年内的购物详单，会员购物积分按照 1 元 1 分计。
      * 每次购物后，输出购物清单。包括顾客代号（会员代码）、商品的名称、代号、单价、折扣、数量、价格以及合计价格、购买时间。
  4. 店铺管理
      * 实现商品信息的添加、修改、删除、查询的功。可查询库存少于一定数量的商品。
      * 实现会员资料的查询、修改、删除；实现会员整理功能，对于 1 年内无购物会员，进行自动删除。
      * 可以按照时间区间统计，包括：销售总额；分类统计商品的销售情况；统计对会员的让利情况。

* 饮料自动售货机
  ==项目说明==
    该项目模拟饮料自动售货机的销售过程。顾客先投币，系统显示投币金额。接下来顾客选择要购买的 饮料，如果投币金额足够并且所购饮料存在，则提示用户取走饮   料，同时找零。如果投币金额不足，显示 提示信息。如果所购饮料已经售完，显示售完信息。
   **项目要求**
   1. 只接受 10 元、5 元、2 元、1 元和 0.5 元的纸币和硬币。 
   2. 顾客一次只能投入上述一种金额的纸币或硬币，当用户重复投入时货币金额累加。 
   3. 销售饮料包括 5 种：可口可乐（2 元）、百事可乐（2 元）、橙汁（3 元）、咖啡（5 元），纯净水（1.5 元）。 
   4. 系统通过必要的提示信息，提示用户完成相应的操作。 
   5. 若顾客购买的饮料已经售完，则进行提示并询问用户是否购买其它饮料。 
   6. 完成一次售卖后，系统自动结算找零。
   
* 灰度直方图统计
  ==项目说明==
    该项目要求统计灰度图像的直方图。
  **项目要求**
  1. 以二进制方式读取一幅 bmp、jpeg 或 png 格式图像的数据，并判断其是否为灰度图像，如果不是，则将其转换为灰度图像数据。
  2. 提示输入一个灰度值区间数（在 1~256 之间的整数）。然后遍历整幅图像，根据区间数，统计每个区间内灰度值的总个数，并将所有统计结果归一化后乘以 100。   3. 画出图像的直方图：用行表示灰度值所在区间，在列上用“*”表示直方图数据，“*”的个数即为对应区间内的像素值统计结果，数据为 0 的不显示。
 设计提示
  1. 定义图像类，成员变量包含图像的分辨率、像素值、直方图。
  2. 定义直方图类，成员函数包含直方图的计算与绘制。
