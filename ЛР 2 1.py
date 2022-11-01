import multiprocessing as mp
import requests
from bs4 import BeautifulSoup
import requests
import re
head = {'User-Agent': "агент""
    'Cookie:' "selector_args=selector_args=куки; _ga=куки; _gid=куки;"}

def print_temp_or_pressure_day_or_night(flag, t_p):
    for i, temp_for_day in enumerate(t_p, start=1):
        if i % 2 == flag:
            if i == 1:
                print(f'1: {temp_for_day.text.lstrip(" ")}')
                continue
            print(f'{i // 2 + flag}: {temp_for_day.text}')

#Какую дату изволите, Dear Modam/Monsier
year, month = input("Какую дату изволите, Dear Modam/Monsier?\nформат:(дд.мм)").split(".")
url = f'https://www.gismeteo.ru/diary/4368/{year}/{month}/'     #https://www.gismeteo.ru/diary/4368/2022/5/
print(url)

request = requests.get(url, headers=head)
#print(request.text)

soup = BeautifulSoup(request.text, 'lxml')
temp = soup.find_all('td', {'class':['first_in_group positive', 'first_in_group']})

pressure = soup.find_all('td', text=re.compile("(^7)"), class_='') #регулярка для вывода давления начинающегося с 7
print(pressure)

print("Температура днём:")
print_temp_or_pressure_day_or_night(1, temp)
print("Температура вечером:")
print_temp_or_pressure_day_or_night(0, temp)

print("Давление днём:")
print_temp_or_pressure_day_or_night(1, pressure)
print("Давление ночью:")
print_temp_or_pressure_day_or_night(0, pressure)

#print(temp)
'''
with mp.Pool(mp.cpu_count()) as pool:
    # res - это список результатов полученных от всех функций get
    res = pool.map(get, urls)
print(res)
'''    