import requests
from typing import Optional

def download_page(url: str) -> Optional[str]: # url can None => Optional
    res = requests.get(url)
    if res.status_code != requests.codes.ok:
        print(f'Cannot get page, eror: {res.status_code}')
        return
    return res

if __name__ == '__main__':
    html = download_page('https://py4e-data.dr-chuck.net/comments_1430672.json')
    if html is None: 
        print(f"Cannot get page.") 
    
    cnt = 0
    data = html.json()['comments']
    for i in data:
        cnt += i['count']
        
    print(cnt)
    


    
