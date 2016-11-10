# C语言程序设计
***
# 4.4 printf()和scanf()
***
## 1.printf() 的修饰符
   


1.对int    

        #include <stdio.h>
        #define PAGES 959
        int main(void)
        {
	       printf("*%d*\n",PAGES);
	       printf("*%2d*\n",PAGES);
	       printf("*%10d*\n",PAGES);
	       printf("*%-10d*\n",PAGES);

	       return 0;
        }
     

2.对string  


        #include <stdio.h>
        #define BULRB "Authentic imitation"
        int main(void)
        {
	       printf("[%2s]\n",BULRB);
	       printf("[%24s]\n",BULRB);
	       printf("[%24.5s]\n",BULRB);
	       printf("[%-24.5s]\n",BULRB);

	       return 0;
        }  


  + .5告诉print只打印5个字符  
  + -标记使文本左对齐输出  


## 2.printf()的返回值  

        #include <stdio.h>

        int main(void)
        {
	       int bph2o = 212;
	       int rv;
	       rv = printf("%d Fis water's boiling point.\n",bph2o);
	       printf("The printf() function printed %d characters.\n",rv);

	       return 0;
        }

  + 程序用 rv = printf(···) 的形式把printf() 的返回值赋给rv，因此该语句执行了两个任务：打印信息和给变量赋值
  + 该计算包括空格和\n

## 3.打印较长字符串   
1.


    printf("Here is one way to print a")  
    printf("long string\n");

2.
        

        printf("Here is another way to print a \
    long string.\n);
3.

    printf("Here's the newest way tio print a"
             "long string\n");
+ 方法2的下一行代码必须从最左边开始

## 4.scanf()的修饰符 

    #include <stdio.h>  
    int main(void)
    {
	   int n;

	   printf("Please enter three integers:\n");
	   scanf("%*d %*d %d",&n);
	   printf("The last integers is %d\n", n );

	   return 0;
    }

  + scanf()中,把*放在%和转换字符间会使scanf()跳过相应输出项
##5.空白  
+ 空白包括**空格、制表符、换行符**

#*编程练习*
##*1.*  
    
    #include <stdio.h>
        int main(void)
    {
	   char fname[40],lname[40];
	   printf("Please enter your your name!\n");
	   scanf("%s", fname);
	   scanf("%s", lname);
	   printf("Oh! Your name is %s %s\n", fname,lname);

	   return 0;
    }
##*2.*


    #include <stdio.h>
    int main(void)  
    {  
       char name[40];
	
	   printf("Please enter your your name!\n");
	   scanf("%s", name);
	
	   printf("Oh! Your name is \"%20s\" \n", name);
	   printf("Oh! Your name is \"%-20s\" \n", name);
	   printf("Oh! Your name is \"%s   \" \n",  name);



	   return 0;
    }

##*3.*  

    #include <stdio.h>
    int main(void)
    {
        int float i;
        scanf("%f", &i);
        printf("%f\n%e\n", i, i);
        return 0;
    }

##*4.*
    #include <stdio.h>
    int main(void)
    {
        char name[20];
        float height;
        printf("Hi! Can you tell me your name?\n");
        scanf("%s", name);
        printf("Hi, %s, can you tell me your height?\n", name);
        scanf("%f", &height);
        printf("Oh, %s, you are %.2f feet tall.\n", name, height);
        return 0;
    }
##*5.*  
    #include <stdio.h>
    int main(void)
    {
	   float speed, size;
	   printf("Plaese enter download speed (MB/s) and file size:\n");
	   scanf("%f%f", &speed, &size);
	   printf("At %.2f megabits per second, a file of %.2f megabytes\n",
		  speed, size * 8);
	   printf("download in %.2f seconds\n",
		  size * 8 / speed );
        return 0;
    }
##*6.*
    #include <stdio.h>
    #include <string.h>
    int main(void)
    {
	   int numf, numl;
	   char fname[10], lname[10];

	   printf("Enter your first name:\n");
	   scanf("%s", fname);
	   printf("Enter your last name:\n");
	   scanf("%s", lname);
	   printf("%s %s\n", fname, lname);
	   printf("%*d %*d%\n", strlen(fname), strlen(fname), 
		  strlen(lname),strlen(lname));
        return 0;
    }
##*7.*
    #include <stdio.h>
    #include <float.h>
    int main(void)
    {
       double i = 1.0 / 3.0;
	   float j = 1.0 / 3.0;

	   printf("%.6e\n%.6f\n", i, j);
	   printf("%.12e\n%.12f\n", i, j);
	   printf("%.16e\n%.16f\n", i, j);
	   printf("%d\n%d\n",
	 	 	   FLT_DIG, DBL_DIG);
        return 0;
    }


***
#5. 运算符、表达式和语句
##1. pow()  
* pow(a,b)返回a的b次幂  

##2.几个术语
* **左值**用于标识特定数据对象的名称或表达式
* **右值**指的是能赋值给可修改左值的量，且本身不是左值
* 用于储存值的数据储存区域统称为**数据对象**
##3.指数增长  
  + 国王的麦子  

        #include <stdio.h>
        #define SQUARES 64
        int main(void)
        {
	       const double crop = 2e16;
	       double current, total;
	       int count = 1;
	
	
	   

           printf("square		grains		total		");
	       printf("fraction of\n");
	       printf("		added		grains		");
	       printf("world total\n");
	       total = current = 1.0;
	       printf("%-14d%-16.2e%-18.2e%-12.2e\n", count,
			     current, total, total/crop);
	       while (count < SQUARES)
	       {
		      count += 1;
	          current *= 2.0;
		      total += current;
		      printf("%-14d%-16.2e%-18.2e%-12.2e\n", count,
		      	   current, total, total/crop);
	       }
	       return 0;
          }  
##4. 除法的截断
+ **截断**是整数除法中，结果小数部分被完整丢弃的情况  

##5. sizeof运算符和size_t类型  

        //使用sizeof运算符
        #include <stdio.h>
        int main (void)
        {
            int n = 0;
            size_t intsize  
            
            intsize = sizeof (int);
            printf("n = %d,n has %zd bytes; all ints have %zd bytes.\n,
            n, sizeof n, intsize);

            return 0;
        } 


+ sizeof返回size_t类型的值，这是一个无符号整数类型，不是新类型
##6.求模运算符  
    //把秒转成分和秒
    #include <stdio.h>
    #define SEC_PER_MIN 60
    int main(void)
    {
        int sec, min, left;
    
        printf("Convert seconds to minutes and seconds!\n");
        printf("Enter the number of seconds ( <= 0 to quit ):\n");
        scanf("%d", &sec);
    
        while (sec > 0)
        {
        min = sec / SEC_PER_MIN;
        left = sec % SEC_PER_MIN;
        printf("%d second is %d minutes, %d seconds.\n"
                , sec, min, left);
        printf("Enter the number of seconds ( <= 0 to quit ):\n");
        scanf("%d", &sec);
        }
        printf("Done!\n");

        return 0;
    }
    
##7.递增运算符
+ 递增和递减运算符只能影响一个变量

##8.表达式和语句  
+ **表达式**由运算符和运算对象组成
+ 每个表达式都有一个值
+ **语句**是一条完整的计算机指令，是C程序的基本构建块  

###**副作用和序列**
+ **副作用**是对数据对象或文件的修改,比如调用printf()时，显示的内容是副作用，printf()的返回值是字符的个数
+ **序列点**是程序执行的点，在这个点上，所有副作用都在进入下一步之前发生。分号标记了一个序列点，一个完整表达式的结束也是一个序列点        
##9.带参函数

    #include <stdio.h>
	void pound(int n);
	int main(void)
	{
		int times = 5;
		char ch = '!';
		float f = 6.0f;
		

		pound(times);
		pound(ch);
		pound(f);
		
		return 0;
	}
	void pound(int n)
	{
		while (n-- > 0)
			printf("#");
			printf("\n");
	}
 

+ 如果函数不接受任何参数，函数头的圆括号中应该写上void
+ 声明函数就创建了被称为**形式参数**的变量，该例中的形式参数为变量n，像pound(10)这样调用函数会把10赋给n
+ 函数调用传递的值为**实际参数**
+ **原型**是函数的声明，描述函数的返回值和参数，pound()的原型说明了两点：
  + 该函数没有返回值(函数名前有void）
  + 该函数有一个int型的参数

#*编程练习*
##*1.*

	#include <stdio.h>
	#define M_PER_H 60
	int main(void)
	{
		int hour, minute, left;
		
		printf("请输入一个分钟数（小于等于0退出）:\n");
		scanf("%d", &minute);
	
		
		while (minute > 0)
		{
			
			hour = minute / M_PER_H;
			left = minute % M_PER_H;

			printf("%d分钟等于%d小时%d分钟\n",
					 minute, hour, left);

			printf("请输入一个分钟数(小于等于0退出:\n");
			scanf("%d", &minute);

		}
	return 0;
	}
##*2.*
	#include <stdio.h>
	int main(void)
	{
		int i, j =11;
		
		printf("请输入一个整数\n");
		scanf("%d", &i);
		printf("以下是这个数以及比这个数大十以内的整数:\n");
		
		while (j-- > 0)
		{
			
			printf("%d\n", i++);
		}
	return 0;
	}
##*3.*
    #include <stdio.h>
    #define D_PER_W 7
    int main(void)
    {
        int day, week, left;

        printf("请输入一个天数（小于等于0退出）:\n");
        scanf("%d", &day);


        while (day > 0)
        {

            week = day / D_PER_W;
            left = day % D_PER_W;

            printf("%d天等于%d周%d天\n",
                    day, week, left);

            printf("请输入一个天数(小于等于0退出:\n");
            scanf("%d", &day);

        }
    return 0;
    }
##*4.*
    #include <stdio.h>
    int main(void)
    {
        float height,inches;

        printf("请以厘米为单位输入你的身高（小于等于0退出）:\n");
        scanf("%f", &height);


        while (height > 0)
        {

            inches = height * 0.39;
        

            printf("%.2f cm = %.2f inches\n",
                    height, inches);

            printf("请以厘米输入一个你的身高(小于等于0退出:\n");
            scanf("%f", &height);
    
    }
    return 0;
    }
##*5.*
    #include <stdio.h>
    int main(void)
    {
        int day, res = 0;
	   printf("请输入天数:\n");
	   scanf("%d", &day);

	   while (day > 0)
		  {res += day;
		  day--;}
	   printf("赚了%d元\n", res);
    
    return 0;
    }

##*6.*
    #include <stdio.h>
    int main(void)
    {
        int day;
	   printf("请输入数:\n");
	   scanf("%d", &day);

	   printf("它的平方是%d\n", day * day);
		
    
    return 0;
    }
##*7.*
    #include <stdio.h>
    void cube(double i);
    int main (void)
    {
	   float i;
	   printf("输入一个数：\n");
	   scanf("%e", &i);

	   cube(i);	
    
    return 0;
    }
    void cube(double i)
    {
	   printf("%.2e的立方是%.2e\n",
		  i, i * i * i);
    } 
##*8.*
    #include <stdio.h>
    int main(void)
    {
	   int i, j;


	   printf("这是一个求模运算。\n");
	   printf("请输入除数(输入非正数退出)：\n");
	   scanf("%d", &i);
	   if (i <= 0)
		  printf("结束！\n");
	   else
	   {
            printf("请输入被除数(输入非正数退出)：\n");
	        scanf("%d", &j);
		    if (j <= 0)
			 printf("结束！\n");
		    else


		{while (i > 0 && j > 0)
		{printf("%d / %d = %d\n", j, i, j % i);
		
		
		printf("这是一个求模运算。\n");
	   printf("请输入除数(输入非正数退出)：\n");
	   scanf("%d", &i);
	   if (i <= 0)
		  break;
	   else
	   {printf("请输入被除数(输入非正数退出)：\n");
	   scanf("%d", &j);
		  if (j <= 0)
			 break;}
	
	
	
	
	   printf("结束！\n");
		  }
	   printf("结束！\n");

	   return 0;
    }
    }}
##*9.*
    #include <stdio.h>
    void Temperatures(double n);
    int main(void)
    {
	   float tem;

	   printf("请输入一个华氏温度（输入q或其他非数字退出）：\n");
	

	   while (scanf("%e", &tem) == 1)
		  {
			 Temperatures(tem);
			 printf("请输入一个华氏温度（输入q或其他非数字退出）：\n");
	   }
	   printf("结束！\n");
	   return 0;
    }
    void Temperatures(double n)
    {
   
		  printf("%.2e℉ = %.2eC = %.2eK\n",
			 n, 5.0 / 9.0 * (n - 32.0),
			 n + 273.16);
    }
***
#6.C控制语句：循环
##1.scanf() 的返回值
+ scanf()返回读取数据的数量
##2.C中的真值
+ C中所有非零值都视为真
+ 表达式为真，求值得1,；表达式为假，求值为0
+ 可以给布尔类型赋值 
        
         _Bool i;i = 1;

##3.优先级和关系运算符
+ 关系运算符的优先级比算术运算符低
+ 关系运算符间有两种优先级
 + 高优先级组： <<=  >>=
 + 低优先级组： == !=  
+ 关系运算符的结合律是从左到右

##4.while语句
+ 注解  
 + while语句创建了一个循环，重复执行直到测试表达式为假
 + while语句是一种入口条件循环，也即是，在执行多次循环之前已经决定是否执行循环
+ 示例
 + while (expression)  
    statment  
+ 整数求和  
        
        #include <stdio.h>
		void Temperatures(double n);
		int main(void)
		{
			long num, sum = 0;
			int status;

			printf("Please enter an integer to be sumed \
		(print q to quit):");
			status = scanf("%ld", &num);
			while (status == 1)
			{
				sum += num;
				printf("Please enter next integer (q to quit):");
				status = scanf("%ld", &num);
			}
			printf("Those integers sum to %ld.\n", sum);

			return 0;
		}

  
##5.for语句
+ 注解
 + 过程
       + 先求解表达式1 
       + 求解表达式2，若其值为真，进入第三步；若为假，执行第五步
       + 求解表达式3
       + 转到第二步
       + 循环结束
 + for语句使用三个表达式控制循环过程，分别用分号隔开
 + 第一个表达式不一定是给变量赋值，也可以使用printf，但第一个表达式只执行一次
+ 实例
 + for(initialize; test; updata)  
   stament
+ 求通项为(1/2^(n-1))的数列的和
		
        #include <stdio.h>
		int main(void)
		{
			int t_ct ;
			double time, power_of_2;
			int limit;

			printf("Enter the number of terms you want:");
			scanf("%d", &limit);
			for(time = 0, power_of_2 = 1, t_ct = 1; t_ct <= limit;
				t_ct++, power_of_2 *= 2.0)
			{
				time += 1.0 / power_of_2;
				printf("time = %f when terms = %d\n", time, t_ct);
			}
			return 0;
		}
##6.逗号表达式
* 它保证被分隔的表达式从左向右求值  
* 整个逗号表达式的值是逗号右边的值
##7.出口条件循环：do while
+ 注解
 + do while语句创建一个循环，在expression为假或0之前重复执行循环体中的内容
 + do while是一种出口条件循环，即在执行完循环体后才根据测试结果决定是否再次执行循环
+ 示例
 + do  
  statement  
while (expression);
##8.数组
+ **数组**是按顺序储存的一系列类型相同的值
+ 整个数组有一个数组名，通过整数下标访问数组中单独的项或元素
		

        #include <stdio.h>//用循环处理数组
		#define SIZE 10
		#define PAR 72
		int main(void)
		{
			int index, score[SIZE];
			int sum = 0;
			float average;


			printf("Enter %d golf scores:\n", SIZE);
			for (index = 0; index < SIZE; index++)
				scanf("%d", &score[index]);

			printf("The scores read in are as follows:\n");
			for (index = 0; index < SIZE; index++)
				printf("%5d", score[index]);
					printf("\n");

			for (index = 0; index < SIZE; index++)
				sum += score[index];
			average = 1.0 * sum / SIZE;
			printf("Sum of scores = %d, average = %.2f\n", sum, average);
			

			return 0;
		}
+ 用define创建明示常量，可以在定义数组和设置循环边界时使用该明示常量
+ 重复显示刚输入的数据是个好习惯

#*编程练习*
##*1.*
	#include <stdio.h>
	int main(void)
	{
		char ch[26];
		int i = 97, j = 0;

		for (;i <= 122; i++, j++)
			{
				ch[j] = i;
				printf("%.5c\n", ch[j]);
			}
		return 0;
	}
##*2.*
	#include <stdio.h>
	int main(void)
	{
		int row = 0, num = 0;
		for(; row < 5; row++)
			{
				for (num = 0; num <= row; num++)
					printf("$");
				printf("\n");
			}
		return 0;
	}
##*3.*
	#include <stdio.h>
	int main(void)
	{
		int row = 0, num = 70;
		for(; row <= 5; row++)
			{
				for (num = 70; num >= 70 - row ; num--)
					printf("%c", num);
				printf("\n");
			}
		return 0;
	}
##*4.*
	#include <stdio.h>
	int main(void)
	{
		int row = 0, num = 65, x = 0;
		for(; row <= 5; row++)
			{	
				for (; num <= 65 + x ; num++)
						
					printf("%c", num);
				printf("\n");
				x += row + 2n;
			}
		return 0;
	}

##*5.*
	#include <stdio.h>
	int main(void)
	{
		int row = 0 , num = 65;
		char i;
		printf("Enter a letter:\n");
		scanf("%c", &i);
		for(; row <= i - 65; row++)
			{	
				for (num = 1; num <= i - 65 - row ; num++)
					printf(" ");
				for (num = 65; num <= 64 + row ; num++)
					printf("%c", num);
				for (; num >= 65; num--)
					printf("%c", num);
					printf("\n");
				
			}
		return 0;
	}
##*6.*
	#include <stdio.h>
	int main(void)
	{
		int max, min, row;
		printf("Enter a number as upper limit:\n");
		scanf("%d", &max);
		printf("Enter a number as floor:\n");
		scanf("%d", &min);


		printf("----------------\n");
		printf("一次  二次  三次\n");
		printf("----------------\n");

		for (row = 0; row <= max - min; row++)
		{
			printf("%-7d%-7d%-7d\n", row + min, 
				(row + min) * (row + min),
				(row + min) * (row + min) * (row + min));
			printf("----------------\n");
			}
		return 0;
	}
##*7.*
	#include <stdio.h>
	#include <string.h>
	int main(void)
	{
		int len;
		char word[20];
		printf("Enter a word:\n");
		scanf("%s", word);

		len = strlen(word);
		for (; len >= 0; len--)
			printf("%c", word[len-1]);
		printf("\n");
		return 0;
	}
##*8.*
	#include <stdio.h>
	int main(void)
	{
		float a, b;
		printf("Enter some couples of floats:\n");
		while (scanf("%f%f", &a, &b) == 2)
		{
			printf("%.2f - %.2f = %.2f, %.2f * %.2f = %.2f\n",
				a, b, a - b, a, b, a * b);
			printf("Next couple\n");
		}
		printf("Done!\n");
		return 0;
	}
##*9.*
	#include <stdio.h>
	void f(float a, float b);
	int main(void)
	{
		float a, b;
		printf("Enter some couples of floats:\n");
		while (scanf("%f%f", &a, &b) == 2)
			f(a, b);
		printf("Done!\n");
		return 0;
	}
	void f(float a, float b)
	{
		printf("%.2f - %.2f = %.2f, %.2f * %.2f = %.2f\n",
				a, b, a - b, a, b, a * b);
	}
##*10.*
	#include <stdio.h>
	int main(void)
	{
		int max, min, num, sum;
		printf("Enter lower and upper integer limits(max < min to quit):\n");
		scanf("%d%d", &min, &max);
		num = min;


		while (max >= min)
		{
			for (num = min, sum = 0; num <= max; num++)
				sum += num * num;
			printf("The sum of squares from %d to %d is %d\n",
					 min * min, max * max, sum);
			printf("Enter next set of limits(max < min to quit):\n");
			scanf("%d%d", &min, &max);
			}
		printf("Done!\n");
		return 0;
	}
##*11.*
	#include <stdio.h>
	int main(void)
	{
		int num[8];
		int index;

		printf("Enter a digit:\n");
		
		for (index = 0; index < 8; index++)
			scanf("%d", &num[index]);
		
		for (index = 7; index >= 0; index--)
			printf("%d", num[index]);
		printf("\n");
		return 0;
	}
##*12.*
	#include <stdio.h>
	int main(void)
	{
	    int t_ct ;
	    double sum, deno;
	    int limit;

	    printf("Enter the number of number:");
	    scanf("%d", &limit);
	    for(sum = 1, deno = 2, t_ct = 1; t_ct < limit;
	        t_ct++, deno += 1.0)
	    {
	        sum += 1.0 / deno;
	        printf("sum = %f when terms = %d\n", sum, t_ct);
	    }
	    return 0;
	}

***
	#include <stdio.h>
	int main(void)
	{
	    int t_ct, flag;
	    double sum, deno;
	    int limit;

	    printf("Enter the number of number:");
	    scanf("%d", &limit);
	    for(sum = 1, flag = -1, deno = 2, t_ct = 1; t_ct < limit;
	        t_ct++, deno += 1.0, flag *= -1)
	    {
	        sum += 1.0 * flag / deno;
	        printf("sum = %f when terms = %d\n", sum, t_ct);
	    }
	    return 0;
	}
##*13.*
	#include <stdio.h>
	#include <math.h>
	int main(void)
	{
		int num[8], i;
		for (i = 0; i < 8; i++)
			num[i] = pow(2,i);
		
		i = 0;

		do
			printf("%d\n", num[i]);
		while(i++ < 8);
		printf("\n");
	    return 0;
	}
##*14.*
	#include<stdio.h>
	int main(void)
	{
		double num1[8], num2[8];
		int i = 0;
		

        do
		{
			printf("Enter a number:\n");
			scanf("%e", &num1[i]);
		} 
		while(++i < 8);
				
		for (num1[0] = num2[0], i = 1; i < 8; i++)
		      num2[i] = num1[i] + num2[i - 1];

		for (i = 0; i < 8; i++)
			printf("%5f", num2[i]);
		printf("\n");
		for (i = 0; i < 8; i++)
			printf("%5f", num1[i]);

		printf("\n");
	    return 0;
	}
##*15.*
	#include <stdio.h>
	#include <string.h>
	int main(void)
	{
	    char ch[255];
	    int index, len;

	    printf("Enter a string:\n");

	    for (index = 0; index < 255; index++)
		{
			scanf("%c", &ch[index]);
			if (ch[index] == '\n')
				break;
		}
		len = strlen(ch);

	    for (index = len; index >= 0; index--)
	        printf("%c", ch[index]);
	    printf("\n");
	    return 0;
	}
##*16.*
	#include <stdio.h>
	#define INTEREST_1 0.1
	#define INTEREST_2 0.05
	int main(void)
	{
		float sum1 = 100, sum2 = 100;
		int year = 0;

		
		for (; sum1 >= sum2; year++)
		{
			sum1 += 100 * INTEREST_1;
			sum2 += sum2 * INTEREST_2;
			}
			
		printf("It takes %d years to Deirdre to catch Daphne.\n \
	Deirdre has %f dollars\nDaphne has %f dollars\n", year, sum1, sum2);
			
	    return 0;
	}
***
#7. C控制语句：分支和跳转
##1. getchar()和putchar()
+ getchar() 不带参数，它从输入队列中返回下一个字符，例如  
   `ch = getchar()`  
  `scanf("%c", &ch)`   
  效果相同
+ putchar() 打印它的参数，例如  
  `putchar(ch)`  
  `printf("%c", &ch)`  
  效果相同  
+ `while ((ch = getchar()) != '\n'`可以用于输入一行后运行程序 

##2. ctype.h系列的字符函数
+ ctype.h头文件中有字符测试函数和字符映射函数
##3.逻辑运算符
+ ！运算符的等级比乘法运算符还高，与递增运算符优先级相同，只比圆括号低；&&运算符等级比||高，但两者都比关系运算符低，比赋值运算符高
+ C保证逻辑表达式的求值顺序是从左向右
+ &&和||都是序列点，所以程序在从一个运算对象执行到下一个对象之前，所有副作用都会生效
##4.条件运算符
+ 条件表达式是if else的一种便捷形式
+ expression! ? expression2 : expression3
  如果expression为真，表达式值等于expression2，否则等于expression3
##5.continue
+ 
#*编程练习*
##*1.*
	#include <stdio.h>
	#include <ctype.h>
	#include <stdbool.h>
	#define STOP '#'
	int main(void)
	{
		char c;
		char prev;
		long n_chars = 0L;
		int n_space = 0;
		int n_lines = 0;


		printf("Enter text to be analysed :\n");
		prev = '\n';


		while ((c = getchar()) != STOP)
		{ 
				if (c == ' ')
					n_space++;
				if (c == '\n')
					n_lines++;
				if (isgraph(c))
					n_chars++;
		}

		
				printf("%ld characters, %d space, %d lines.\n",
					n_chars, n_space, n_lines);
				return 0;
	}
##*2.*
	#include <stdio.h>
	#include <ctype.h>
	#include <stdbool.h>
	#define STOP ‘#’
	int main(void)

		int i = 0;


		printf("Enter text to be analysed :\n");


		while ((c = getchar()) != STOP)
		{ 
			i++;
			if (i % 8 != 0)	
			{
				printf("%4d", c);
				printf("%4c", c);
			}
			printf("\n");
		}

				return 0;
	}
##*3.*
	#include <stdio.h>
	#define STOP 0
	int main(void)
	{

		int c, prev, i = 0, j = 0, sum1 = 0, sum2 = 0;


		printf("Enter integers to be analysed :\n");

		
		while (c = getchar() - 48)
		 {
			if (c % 2 != 0)	
			{	i++;
				sum1 += c;
			}
			if (c % 2 == 0)
			{

				prev = c;
				if (prev == STOP)
					break;
				else
				{
					j++;
					sum2 += c;
				}
			}
		printf("%d", sum2);
			}
		printf("There are %d odds and %d even, the average of odds is %d, the average of even is %d.\n"
						, i, j, sum1 / i, sum2 / j);
		

				return 0;
	}

##*4.*
	#include <stdio.h>
	#define m '!'
	#define STOP '#'
	int main(void)
	{
		int i = 0;
		char c;
		
		while((c = getchar()) != STOP)

		{
			if (c == '!')
			{
				i++;
				putchar(m);
				putchar(m);

			}
			if (c == '.')
			{
				i++;
				putchar(m);
			}
			else
				putchar(c);
			}
		printf("\n");
		printf("We changed %d %s.\n", i, i == 1 ? "time" : "times");

				return 0;
	}


##*6.*
    #include <stdio.h>
    #define STOP '#'
        int main(void)
        {
        	char prev = 0, c;
        	int times = 0;
        
        	while ((c = getchar())!= STOP)
        		{
        			if (c == 'e')
        				prev = c;
        			if (c == 'i')
        			{
        				if (prev == 'e')
        					times++;
        			}
        		}
        	printf("ei has appeared %d times\n", times);
        
        			return 0;
        }

##*7.*
	#include <stdio.h>
	int main(void)
	{
		int hours;
		float sum, tax, income;

		printf("Enter your work times one week in hour:\n");
		scanf("%d", &hours);

		if (hours <= 40)
			sum = 1000 * hours;
		else
			sum = 40000 + (hours - 40) * 1500;

		tax = 75 + (sum - 450) * .25;
		income = sum - tax;

		printf("Your gross income is %.2f, your tax is %.2f\
	, your income is %.2f\n", sum, tax, income);

				return 0;
	}
##*8.存疑*
    #include <stdio.h>
    int main(void)
    {
    	int hours, ch;
    	float sum, tax, income, rate;
    
    			printf("****************************************************************\n");
    			printf("Enter the number corresonding to the desired pay rate or action:\n");
    			printf("1) $8.75/hr                      2) $9.33\n");
    			printf("3) $10.00/hr                     4) $11.20\n");
    			printf("5) quit\n");
    			printf("****************************************************************\n");
    			
    	
    
    	while ((ch = getchar() - 48) < 1 || ch > 5)
    		{
    			printf("Enter correct choice:\n");
    			printf("****************************************************************\n");
    			printf("Enter the number corresonding to the desired pay rate or action:\n");
    			printf("1) $8.75/hr                      2) $9.33\n");
    			printf("3) $10.00/hr                     4) $11.20\n");
    			printf("5) quit\n");
    			printf("****************************************************************\n");
    	}
    	switch(ch)
    		{
    			case 1:
    				rate = 8.75;
    				break;
    				
    			case 2:
    				rate = 9.33;
    				break;
    			case 3:
    				rate = 10.00;
    				break;
    			case 4:
    				rate = 11.20;
    				break;
    			case 5:
    				printf("Bye!\n");
    				return 0;
    			}
    		
    	
    		printf("Enter your work time one week in hour:\n");
    		scanf("%d", &hours);
    		if (hours <= 40)
    			sum = rate * hours;
    		else
    			sum = rate * 40 + (hours - 40) * 1.5 * rate;
    		
    		if (sum <= 300)
    			tax = sum * .15;
    		if (sum <= 450)
    			tax = 45 + (sum - 300) * .2;
    		else
    			tax = 75 + (sum - 450) * .25;
    
    
    		income = sum - tax;
    
    	printf("Your gross income is %.2f, your tax is %.2f\
    , your income is %.2f\n", sum, tax, income);
    
    			return 0;
    }
#8.字符输入输出和输入验证
##*编程练习*
##*1.*
	#include <stdio.h>
	#include <ctype.h>
	int main(void)
	{
		int str_num = 0;
		char ch;
	
		printf("Enter a text:\n");
	
		while((ch = getchar()) != EOF)
		{
			if ((!isspace(ch)))
			str_num++;
			else
				continue;
			}
	
		printf("There are %d characters in this text.\n", str_num); 
	
		return 0;
		}
##*3.*
	#include <stdio.h>
	#include <ctype.h>
	int main(void)
	{
		char ch;
		int lower = 0, upper = 0;
	
		printf("Enter a text:\n");
	
		while ((ch = getchar()) != EOF)
		{
			if(islower(ch))
				lower++;
			if(isupper(ch))
				upper++;
			else
				continue;
		}
		printf("There are %d lowers and %d uppers in text.", lower, upper); 
			
	
		return 0;
		}
##*4.*
	#include <stdio.h>
	#include <ctype.h>
	int main(void)
	{
		char ch;
		int words = 0, characters = 0, flag = 1;
	
		printf("Enter a text:\n");
	
		while ((ch = getchar()) != EOF)
		{
			if(!(isspace(ch)) && !(ispunct(ch)))
				characters++;
	
			if(!(isspace(ch)) && flag)
				{
					words++;
					flag = 0;
					}
			if(!(isspace(ch) && !flag))
				continue;
			if(isspace(ch) && !flag)
				flag = 1;
	
	
		}
		printf("%d\n",characters);
		printf("There are %d characters in every word averagely.", characters / words); 
			
	
		return 0;
		}

##*5.*
	#include <stdio.h>
	int main(void)
	{
		int guess, high = 100, low = 1;
		char response;
	
		printf("Pick an integer from 1 tp 100. I will try to guees it.\n");
		printf("Respond with a y if my guess if right and with\n");
		printf("an n if it is wrong.\n");
		printf("Uh... Is your number %d?\n", guess = (low + high) / 2);
		while ((response = getchar()) != 'y')
		{
			if(response == 'n')
			{
				printf("Too big or too small? Respond b or s.\n");
				if(getchar() == 'b')
				{
					high = guess;
					printf("Well, then, is it %d?\n", guess = (low + high) / 2);
				}
				if(getchar() == 's')
				{
					low = guess;
					printf("Well, then, is it %d?\n", guess = (low + high) / 2);
				}
				else
				{
					high = guess;
					printf("Well, then, is it %d?\n", guess = (low + high) / 2);
				}
	
				}
			while(getchar() != '\n')
				continue;
			}
		printf("I know I cloud do it!\n");
		return 0;
		}

