import requests
import json

params = {"lat":40.779659, "lng":-73.968995, "date":"2019-11-27"}

f = r"https://api.sunrise-sunset.org/json?"

def sunrisesunset(f):
    a = requests.get(f, params=params)
    a = json.loads(a.text)
    a = a["results"]
    return (a["sunrise"], a["sunset"], a["day_length"])

print(sunrisesunset(f))
