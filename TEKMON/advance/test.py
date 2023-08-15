import requests


api_key = ""

url = "http://api.openweathermap.org/data/2.5/weather?q=hanoi&appid=f91efea1afefe27f7f61bc762d203f08"

res = requests.get(url)
data = res.json()
print(data)
