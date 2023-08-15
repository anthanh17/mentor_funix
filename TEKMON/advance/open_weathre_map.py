import requests

def get_weather_forecast(api_key, city):
    url = f"http://api.openweathermap.org/data/2.5/weather?q={city}&appid={api_key}"
    response = requests.get(url)
    data = response.json()

    if data["cod"] == "404":
        print("Không tìm thấy thành phố.")
        return
    # print(data)
    weather = data["weather"][0]["description"]
    temp = float(data["main"]["temp"]) -  273.15
    humidity = data["main"]["humidity"]

    print(f"Thời tiết ở {city}:")
    print(f" - Trạng thái thời tiết: {weather}")
    print(f" - Nhiệt độ: {temp}C")
    print(f" - Độ ẩm: {humidity}%")

# Thay thế 'YOUR_API_KEY' bằng khóa API của bạn từ OpenWeatherMap
api_key = "f91efea1afefe27f7f61bc762d203f08"
city = input("Nhập tên thành phố: ")
get_weather_forecast(api_key, city)


# file json
