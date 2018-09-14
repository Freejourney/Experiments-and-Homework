"""  """

""" 1.6.2 from 模块名 import 对象名 [as 别名] """

from math import sin

print(sin(3))

from math import sin as f

print(f(3))

from os.path import isfile

print(isfile(r'C:\windows\notepad.exe'))



""" 1.6.3 from 模块名 import * """

from math import *

print(gcd(36, 18))  # 最大公约数
print(pi)   # π
print(log2(8))  # 以2为底数8的对数
print(log10(100))
print('角度180转弧度：', radians(180), '\n') # 角度转弧度


""" 2.1.1 常量与变量 """

x = 3
print('the type of x : ', type(x))
print('Is the type of x is equal to int? ', type(x) == int)
print('Is the type of x is an instance of int? ', isinstance(x, int))
x='Hello, world!'
print(x)

""" I omited something here """

print("9999^99 = ", 9999**99)

print("It's not accurate to minus straightly, for example: 0.4 - 0.1 = ", 0.4 - 0.1)
print("You shouldn't judge whether two numbers are equal in such a way, in which you "
      "compare a minus formula with anther number straightly: ")
print("0.4 - 0.2 == 1 : ", 0.4 - 0.2 == 1)
print("But you can compare them in a certain range: abs(0.4-0.1-0.3) < 1e-6 : ")
print(abs(0.4-0.1-0.3)<1e-6, "\n")

print("In addition, python also support plural : ")
x = 3 + 4j
y = 5 + 6j

print(x+y)
print(x*y)
print(abs(x))
print(x.imag)      # imaginary part
print(x.real)
print(x.conjugate())    # conjugate


""" 分数 """

from fractions import Fraction
x = Fraction(3, 5)
y = Fraction(3, 7)

print("The Fraction form of x(3/5) : ", x)
print(x**2)
print(x.numerator)  # 分子
print(x.denominator)  # 分母
print("A few basic operations in fraction : ")
print(x + y)
print(x - y)
print(x * y)
print(x / y)
print(x * 2)
print(Fraction(3.5))    # 将实数转换成分数
print("\n")


""" 高精度实数 """

from fractions import Decimal
print("common : ", 1/9)
print("Decimal : ", Decimal(1/9))
print(Decimal(1/9) + Decimal(1/3))
print("\n")


""" 字符串 与 字节串 """

x = 'Hello world'
x = "Python is a greate language"
x = ''' Tom said, "Let's go."'''    # In ''' ''', strs doesn't need \ anymore
print(x)

x = 'good''morning'
print(x)
x = 'good '
x = x + 'morning'
print("You can connnect str by add operation(+) : ", x)


""" zip() 可以将两段独立的数组对应合并成列表 """

I = list(zip('abcd', [1, 2, 3]))
print(I)
y = list(zip('abcd'))
print(y)
x = list(zip('123','abc',',.! f'))
print(x)
for item in zip('abcd', range(3)) :
    print(item)


""" eval() """

print(eval(b'3+5'))


""" 用户输入一个三位自然数，计算并输出其百位、十位和个位上的数字 """

# print("\n\n1.用户输入一个三位自然数，计算并输出其百位、十位和个位上的数字: ")
#
# x = input('请输入一个三位数：')
# print("利用input函数得到的字符串是str类型的, type(x) : ", type(x))
# x = int(x)
# a = x // 100
# b = x // 10 % 10
# c = x % 10
# print("百位：", a, "\n十位：", b, "\n个位：", c, "\n")
#
# x = input('请输入一个三位数：')
# x = int(x)
# a, b = divmod(x, 100)   # 用 x 除以 100，余数为b， 商为a
# b, c = divmod(b, 10)
# print(a, b, c)
#
# x = input('请输入一个三位数：')
# a, b, c = map(int, x)   # 将各位分别映射到a、b、c
# print(type(a))
# print(a, b, c)


""" 已知三角形的两边长及其夹角，求第三边长 """

# import math
#
# x = input('输入两边长及夹角(度): ')
# a, b, theta = map(float, x.split())     # 指定映射到float，split()参数为空，按空格划分
# c = math.sqrt(a**2+b**2-2*a*b*math.cos(theta*math.pi/180))
# print('c=', c)


""" 任意输入3个英文单词，按字典顺序输出 """

# s = input('x, y, z=')
# x, y, z = sorted(s.split(','))
# print(x, y, z)
