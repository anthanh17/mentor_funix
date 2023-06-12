import requests
from typing import Optional
import xml.etree.ElementTree as ET

def download_page(url: str) -> Optional[str]: # url can None => Optional
    res = requests.get(url)
    if res.status_code != requests.codes.ok:
        print(f'Cannot get page, eror: {res.status_code}')
        return
    return res.text

if __name__ == '__main__':
    html = download_page('https://py4e-data.dr-chuck.net/comments_1430671.xml')
    if html is None: 
        print(f"Cannot get page.") 
    
    
    mytree = ET.fromstring(html)
    a = mytree[1].findall('comment')
    #a = mytree[1].tag
    #print(a)
    cnt = 0
    for x in mytree[1].findall('comment'):
        item = x.find('count').text
        #print(item)
        cnt += int(item)
    print(cnt)
    


    
