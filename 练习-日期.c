//输入某年某月某日，判断这一天是这一年的第几天？
//程序分析：以3月5日为例，应该先把前两个月的加起来，然后再加上5天即本年的第几天，特殊情况，闰年且输入月份大于3时需考虑多加一天。
#include <stdio.h>

int isLeapYear(int year){//一个函数声明和定义。(int year)接受一个 年份 作为输入
	if((year%4==0&&year%100!=0)||(year%400==0)){//判断是否为闰年
		return 1;//是闰年返回1
	}else{
		return 0;//不是返回0
	}
}
int main(){
	int year,month,day;
	int totaldays=0;
	int daysInMonth[]={31,28,31,30,31,30,31,31,30,31,30,31};//数组，储存每个月份的天数。0为1月/1为2月/2为3月...
	
	printf("请输入年份、月份和日期（格式：年 月 日）：");
	scanf("%d %d %d",&year,&month,&day);
	
	if(isLeapYear(year)){//调用函数，将year输入进isleapyear函数，为闰年则为真，执行语句。
		daysInMonth[1]=29;//将闰年的二月改为29天
	}
	
	for(int i=0;i<=month-1;i++){//for循环，根据月份将数组中的天数取出。
		totaldays=totaldays+daysInMonth[i];
	}
	totaldays=totaldays+day;//加上本月第几天的天数
	
	printf("%d年%d月%d日是该年的第%d天\n", year, month, day, totaldays);
	
}
