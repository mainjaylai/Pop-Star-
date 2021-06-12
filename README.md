
## 引言

### 1.1

#### 1.1.2数据管理技术的发展

1. 人工管理阶段
2. 文件系统阶段
3. 数据库系统阶段

### 1.2 数据库管理的组成和特点
#### 1.2.1组成
1. 计算机硬件系统
2. 数据库集合
3. 数据库管理系统(DBMS)
4. 相关的软件系统
5. 数据库管理员以及其他人员
#### 1.2.2特点
1. 数据`冗余度`小,数据`共享性高`
2. 具有较高的数据`独立性`
3. 数据`结构化`
4. 具有统一的数据`控制功能`
	* 数据安全性控制
	* 数据完整性控制
	* 数据并发控制
	* 数据恢复
### 1.4基本数据模型
#### 1.4.1
1. 层次模型
		利用树型结构
2. 网状模型
		利用网状结构
3. 关系模型
		利用二维表

![屏幕快照 2021-06-12 下午4 09 21](https://user-images.githubusercontent.com/73374331/121770075-d215a200-cb99-11eb-90ba-f347a2fe9458.png)
## 第二章——关系模型介绍

### 2.1 关系数据库的结构

* 元组:行
* 关系:表
* 属性:列
* 域: 列的所有取值的集合 (通常叫做**属性的域) 

### 2.3 码

* 超码: 一个或者多个属性的集合(里面有无关紧要的属性)

* 候选码:每个属性都有用,决定其他属性的属性集合

* 主码:是被数据库设计者选中,只是用来区分而已(关系的一个候选码可以作为主码)

* 外码和参照关系
###  2.6 关系运算

|     符号      | 使用实例 |
| :-----------: | :------: |
| $\alpha_{条件}(表名)$ 选择|   $\alpha_{salary>=5000}(instructor)$       |
|     $\Pi_{属性名}(表名)$ 投影      |$\Pi_{ID,salary}(instructor)$          |
|   自然连接    |          |
|   $\times$笛卡尔积    |    [表名]$\times$[表名]      |
|      $U$并       |      表名$U$表名(要求两个表的属性完全相同)      |



## 第三章——SQL

### 3.2基本数据类型

* char(n) 用户指定长度

* varchar(n) 指定最大长度

* int

* smallint

* numeric(p,d) 定点数(p个数字,d是小数点右边数字个数)

* float

### 3.2.2基本模式定义

* 创建

```mysql
create table(
  primary key (course_id,sex_id),
  foreign key (dept_name) references tabke_name(dept_name)
);
```

* 删除元组
```mysql
delete from table_name where ; 

```

* 删除表
```mysql
drop table table_name
```

* 添加列

```mysql
ALTER TABLE 【表名】 ADD 【列名】 【类型】
```

* 删除列

```mysql
ALTER TABLE 【表名】 DROP 【列名】
```
* 重命名列

```mysql
ALTER TABLE 【表名】 CHANGE 【列名】【新名】
```
* 修改表字段

```mysql
alter table 表名称 change 字段名称 字段名称 字段类型 [是否允许非空];
alter table 表名称 modify 字段名称 字段类型 [是否允许非空];
```
* 修改表名

```mysql
ALTER TABLE tbl_name rename new_tbl_name;
```

### 3.3 SQL查询基本结构

* `all` :不去重
* `distinc` :去重	

### 3.3.3 自然连接

* `natural join`

### 3.5 集合运算

|   运算    | 名称 |
| :-------: | :--: |
|   union   | 并集 |
| intersect | 交集 |
|  expect   | 减去 |

### 3.6集合的比较

* `all`

* `some`
* `exists`

### 3.8 重复元组

* `unique` :是否存在重复元组,没有就是true
* `with as`用法

```mysql
with [表名](属性名字,属性名字) as (
      # 查询的结果
)
```

* `update` 用法	

```mysql
update [表名] set [列名]=[值]
where 条件
```

* `case` 用法

```mysql
case 
	when pred1 then result1
	when pred2 then result2
	else result0
end
```

## 第四章 —— 中级SQL

### 4.2 视图

* `view` 的使用

```mysql
create view [名字] as select
#条件
;
```

### 4.3 事务

* `原子性`  :事务所有操作要么全部正确反映,要么完全不反映
* `一致性`  :隔离事务之时,保持其一致
* `隔离性`  :顺序执行
* `持久性`  :对数据库的改变是永久的

### 4.4 完整性约束

* `not null`
* `unique` :放在属性后面
* `check`  :放在属性后面,括号里面加入条件

### 4.5 SQL中的数据类型

* `date`  : '2001-04-25'
* `time` : '09:30:00'
* `timestamp` :'2001-04-25 09:30:00'

### 4.5.3 创建索引

```mysql
create index Student_index on student(ID);
```

### 4.6 授权

* 权限授予与收回

```mysql
grant [权限列表‘select,delete,*,...(update 后面可加([属性名]))’]
on [表名或者视图]
to [角色]
```
```mysql
revoke [权限列表‘select,delete,*,...’]
on [表名或者视图]
from [角色]
```

* 角色

```mysql
create role [角色名]
```

* 授权角色

```mysql
grant [角色名] to [角色名]
```

* 权限转移

```mysql
grant [权限列表] on [表名] to [角色名] with grant option #表示允许该角色将权限授权给其他角色
```

## 第五章——高级SQL

### 5.2函数与过程

* 函数

```mysql
 create function 函数名([<参数1><类型1>[,<参数2><类型2>...]]) 
    returns 数据类型 
    begin
      sql语句;
      return 值;
    end
```

* 存储过程

```mysql
 create procedure 名称(in [<参数1><类型1>[,<参数2><类型2>...], out [<参数1><类型1>[,<参数2><类型2>...]]) 
    begin
      sql语句;
    end
```

### 5.2.2 支持过程语言构造

* `while` and `repeat`

```mysql
while 布尔表达式 do 
			语句序列	;
end while

repeat 语句序列;
until	布尔表达式
end repeat
```
* `if` 
```mysql
if 布尔表达式  
then		语句序列	;
elseif 	语句序列	;
else 	语句序列	;
end if
```

### 5.3触发器

* 语法
```mysql
CREATE TRIGGER trigger_name
trigger_time(after,before)
([update,delete,insert] of [表名]) trigger_event ON tbl_name
(referencing new row as nrow,old row as orow )
FOR EACH ROW
trigger_stmt
```

## 第七章——数据库设计与E-R模型

### 7.1.2设计选择

我们主要避免一下两个问题

* `冗余` : 出现重复信息
* `不完整` :对关系处理的不完整

### 7.2实体-联系模型

#### 7.2.1

* `实体`
* `实体集`

#### 7.2.2

* `联系` :是指多个实体间的相互联系
* `联系集` 

#### 7.2.3

* 简单和复合属性:简单属性不能被划分,复合属性还能被划分(比如name可以设计成为firstname和lastname)
* 单值属性和多值属性:多值属性(不同的老师可以有不同数量的电话号码)
* 派生属性:可以由其他属性计算而来

### 7.5 实体-联系图

#### 7.5.1 基本结构

* 矩形:实体集的名字和所有属性的名字
* 菱形:代表联系集
* 未分割的矩形:代表联系的属性
* 线段:实体集-联系集
* 虚线:联系集-联系集属性
* 双线:实体在联系集的参与度
* 双菱形:连接到弱实体集(没有足够属性已形成主码)的标志性联系集

