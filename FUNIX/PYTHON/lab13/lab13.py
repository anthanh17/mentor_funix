import requests, bs4, csv
from typing import Optional

def download_page(url: str) -> Optional[str]: # url can None => Optional
    res = requests.get(url)
    if res.status_code != requests.codes.ok:
        print(f'Cannot get page, eror: {res.status_code}')
        return
    return res.text

if __name__ == '__main__':
    html = download_page('https://py4e-data.dr-chuck.net/comments_1430669.html')
    if html is None: 
        print(f"Cannot get page.") 
    
    bs_obj = bs4.BeautifulSoup(html, 'html.parser')
    cmt = bs_obj.find_all('span', {'class' : 'comments'})
    ans = [int(i.get_text()) for i in cmt]

    cnt = 0
    for i in ans:
        cnt += i
    
    print(ans)
    print(len(ans))
    print(cnt)
    
