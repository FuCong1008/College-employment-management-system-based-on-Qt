--创建学生就业管理系统数据库---
#CREATE DATABASE SEME2;

SET NAMES utf8mb4;

-- ----------------------------
-- 1.Table structure for city
-- ----------------------------
DROP TABLE IF EXISTS `city`;
CREATE TABLE `city`  (
  `province` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
  `town` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_bin ROW_FORMAT = Compact;

-- ----------------------------
-- Records of city
-- ----------------------------
TRUNCATE TABLE `city`;
INSERT INTO `city` VALUES('请选择','请选择');
INSERT INTO `city` VALUES('北京','北京');
INSERT INTO `city` VALUES('广东','东莞');
INSERT INTO `city` VALUES('广东','广州');
INSERT INTO `city` VALUES('广东','中山');
INSERT INTO `city` VALUES('广东','深圳');
INSERT INTO `city` VALUES('广东','惠州');
INSERT INTO `city` VALUES('广东','江门');
INSERT INTO `city` VALUES('广东','珠海');
INSERT INTO `city` VALUES('广东','汕头');
INSERT INTO `city` VALUES('广东','佛山');
INSERT INTO `city` VALUES('广东','汕尾');
INSERT INTO `city` VALUES('江苏','南京');
INSERT INTO `city` VALUES('江苏','苏州');
INSERT INTO `city` VALUES('江苏','徐州');
INSERT INTO `city` VALUES('江苏','无锡');
INSERT INTO `city` VALUES('江苏','连云港');
INSERT INTO `city` VALUES('江苏','镇江');
INSERT INTO `city` VALUES('上海','上海');
INSERT INTO `city` VALUES('山东','青岛');
INSERT INTO `city` VALUES('山东','烟台');
INSERT INTO `city` VALUES('河南','郑州');
INSERT INTO `city` VALUES('河南','开封');
INSERT INTO `city` VALUES('河北','石家庄');
INSERT INTO `city` VALUES('河北','唐山');
INSERT INTO `city` VALUES('河北','张家口');
INSERT INTO `city` VALUES('河北','衡水');
INSERT INTO `city` VALUES('浙江','杭州');
INSERT INTO `city` VALUES('浙江','温州');
INSERT INTO `city` VALUES('陕西','西安');
INSERT INTO `city` VALUES('陕西','延安');
INSERT INTO `city` VALUES('湖南','长沙');
INSERT INTO `city` VALUES('福建','厦门');
INSERT INTO `city` VALUES('福建','泉州');
INSERT INTO `city` VALUES('四川','成都');
INSERT INTO `city` VALUES('安徽','合肥');
INSERT INTO `city` VALUES('海南','三亚');
INSERT INTO `city` VALUES('海南','海口');
INSERT INTO `city` VALUES('江西','南昌');
INSERT INTO `city` VALUES('江西','九江');
INSERT INTO `city` VALUES('江西','赣州');
INSERT INTO `city` VALUES('江西','上饶');
INSERT INTO `city` VALUES('江西','吉安');
INSERT INTO `city` VALUES('江西','九江');
INSERT INTO `city` VALUES('江西','新余');
INSERT INTO `city` VALUES('江西','宜春');
INSERT INTO `city` VALUES('江西','景德镇');
INSERT INTO `city` VALUES('江西','萍乡');
INSERT INTO `city` VALUES('江西','鹰潭');
INSERT INTO `city` VALUES('湖北','武汉');
INSERT INTO `city` VALUES('山西','太原');
INSERT INTO `city` VALUES('辽宁','大连');
INSERT INTO `city` VALUES('黑龙江','哈尔滨');
INSERT INTO `city` VALUES('吉林','吉林');
INSERT INTO `city` VALUES('吉林','长春');

-- ----------------------------
-- 2.Table structure for major
-- ----------------------------
DROP TABLE IF EXISTS `major`;
CREATE TABLE `major`  (
  `faculty` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
  `stuMajor` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_bin ROW_FORMAT = Compact;

-- ----------------------------
-- Records of major
-- ----------------------------
TRUNCATE TABLE `major`;
INSERT INTO `major` VALUES ('请选择','请选择');
INSERT INTO `major` VALUES ('信息工程系','计算机科学与技术');
INSERT INTO `major` VALUES ('信息工程系','通信工程');
INSERT INTO `major` VALUES ('信息工程系','软件工程');
INSERT INTO `major` VALUES ('信息工程系','网络工程');
INSERT INTO `major` VALUES ('应用工程系','资源勘察工程');
INSERT INTO `major` VALUES ('应用工程系','化学工程与工艺');
INSERT INTO `major` VALUES ('应用工程系','土木工程');
INSERT INTO `major` VALUES ('应用工程系','工程管理');
INSERT INTO `major` VALUES ('应用工程系','测绘工程');
INSERT INTO `major` VALUES ('机械与电子工程系','机械工程');
INSERT INTO `major` VALUES ('机械与电子工程系','自动化');
INSERT INTO `major` VALUES ('机械与电子工程系','电子信息工程');
INSERT INTO `major` VALUES ('人文与艺术系','法学');
INSERT INTO `major` VALUES ('人文与艺术系','汉语国际教育');
INSERT INTO `major` VALUES ('人文与艺术系','英语');
INSERT INTO `major` VALUES ('人文与艺术系','日语');
INSERT INTO `major` VALUES ('人文与艺术系','网络与新媒体');
INSERT INTO `major` VALUES ('人文与艺术系','工程设计');
INSERT INTO `major` VALUES ('人文与艺术系','体育教育');
INSERT INTO `major` VALUES ('经济与管理系','国际经济与贸易');
INSERT INTO `major` VALUES ('经济与管理系','市场营销');
INSERT INTO `major` VALUES ('经济与管理系','会记学');
INSERT INTO `major` VALUES ('经济与管理系','财务管理');


-- ----------------------------
-- 3.Table structure for `user`
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user`  (
  `account` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `pwd` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`identity` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`userName` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	CONSTRAINT user_pk PRIMARY KEY (`account`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_bin ROW_FORMAT = Compact;

-- ----------------------------
-- Records of major
-- ----------------------------
TRUNCATE TABLE `user`;
INSERT INTO `user` VALUES ('admin','123','管理员','admin');
INSERT INTO `user` VALUES ('20183033619','000000','学生','熊文龙');
INSERT INTO `user` VALUES ('20183033621','111111','学生','李峰');
INSERT INTO `user` VALUES ('20183033622','222222','学生','付聪');
INSERT INTO `user` VALUES ('20183033623','333333','学生','陈政宏');
INSERT INTO `user` VALUES ('20183033624','444444','学生','陈流生');
INSERT INTO `user` VALUES ('88888888','555555','老师','朱老师');

-- ----------------------------
-- 4.Table structure for `recordlogin`
-- ----------------------------
DROP TABLE IF EXISTS `recordlogin`;
CREATE TABLE `recordlogin`  (
  `account` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `pwd` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`loginFlag` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	#CONSTRAINT recordlogin_pk PRIMARY KEY (`account`) USING BTREE
	CONSTRAINT user_fk FOREIGN KEY (account) REFERENCES `user`(account)
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_bin ROW_FORMAT = Compact;

-- ----------------------------
-- Records of recordlogin
-- ----------------------------
TRUNCATE TABLE `recordlogin`;
INSERT INTO `recordlogin` VALUES ('admin','123','no');

-- ----------------------------
-- 5.Table structure for `student`
-- ----------------------------
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student`  (
  `stuNumber` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `stuClass` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`stuName` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`stuSex` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`stuMajor` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`stuPhone` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`jobTime` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`companyName` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`jobPost` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	CONSTRAINT student_pk PRIMARY KEY (`stuNumber`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_bin ROW_FORMAT = Compact;

-- ----------------------------
-- Records of student
-- ----------------------------
TRUNCATE TABLE `student`;
INSERT INTO `student` VALUES ('20183033619','1830336','熊文龙','男','软件工程','18296966170','2021/12/05','芷间科技有限公司','嵌入式软件工程师');
INSERT INTO `student` VALUES ('20183033621','1830336','李峰','男','软件工程','13576632877','2022/02/15','三百云信息科技有限公司','java开发工程师');
INSERT INTO `student` VALUES ('20183033622','1830336','付聪','男','软件工程','15270212610','2021/12/20','睿辰欣创科技股份有限公司','初级软件工程师');
INSERT INTO `student` VALUES ('20183033624','1830336','陈流生','男','软件工程','17779484964','2021/12/05','赛克蓝德网络科技有限公司','C++开发');

-- ----------------------------
-- 6.Table structure for `company`
-- ----------------------------
DROP TABLE IF EXISTS `company`;
CREATE TABLE `company`  (
  `companySide` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
  `company` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`contacts` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`stuSex` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`contactsPhone` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`jobPost` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`salary` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`abilityRecquire` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	CONSTRAINT company_pk PRIMARY KEY (`companySide`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_bin ROW_FORMAT = Compact;

-- ----------------------------
-- Records of company
-- ----------------------------
TRUNCATE TABLE `company`;
INSERT INTO `company` VALUES ('江苏南京','芷间科技有限公司','吕超','13265864768','嵌入式软件工程师','11000','熟悉C语言，看的懂原理图');
INSERT INTO `company` VALUES ('江苏南京','三百云信息科技有限公司','张典典','13345567987','java开发工程师','6500','熟练掌握java,MySql数据库');
INSERT INTO `company` VALUES ('江苏南京','睿辰欣创科技股份有限公司','孙银','13352631425','初级软件工程师','8500','熟悉C++,C,Qt,数据库,计算机网络');
INSERT INTO `company` VALUES ('江苏南京','赛克蓝德网络科技有限公司','朱林','15244568754','C++开发','9000','熟悉C++,数据结构，网络通讯');


-- ----------------------------
-- 7.Table structure for `stu_company`
-- ----------------------------
DROP TABLE IF EXISTS `stu_company`;
CREATE TABLE `stu_company`  (
  `stuNumber` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `stuClass` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`stuName` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`stuSex` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`stuMajor` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`stuPhone` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`jobTime` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`companyName` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`companySide` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`contacts` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`contactsPhone` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`jobPost` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`salary` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	`abilityRecquire` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL,
	CONSTRAINT stu_company_fk FOREIGN KEY (stuNumber) REFERENCES `student`(stuNumber)
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_bin ROW_FORMAT = Compact;

-- ----------------------------
-- Records of stu_company
-- ----------------------------
TRUNCATE TABLE `stu_company`;
INSERT INTO `stu_company` VALUES ('20183033619','1830336','熊文龙','男','软件工程','18296966170','2021/12/05','芷间科技有限公司','江苏南京','吕超','13265864768','嵌入式软件工程师','11000','熟悉C语言,看的懂原理图');
INSERT INTO `stu_company` VALUES ('20183033621','1830336','李峰','男','软件工程','13576632877','2022/02/15','三百云信息科技有限公司','江苏南京','张典典','13345567987','java开发工程师','6500','熟练掌握java,MySql数据库');
INSERT INTO `stu_company` VALUES ('20183033622','1830336','付聪','男','软件工程','15270212610','2021/12/20','睿辰欣创科技股份有限公司','江苏南京','孙银','13352631425','初级软件工程师','8500','熟悉C++,C,Qt,数据库,计算机网络');
INSERT INTO `stu_company` VALUES ('20183033624','1830336','陈流生','男','软件工程','17779484964','2021/12/05','赛克蓝德网络科技有限公司','江苏南京','朱林','15244568754','C++开发','9000','熟悉C++,数据结构，网络通讯');
