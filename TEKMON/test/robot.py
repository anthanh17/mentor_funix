#Bước 1
#Chat bot doi thoai
print('-----------------------------------------------------------')
print('Toi la Robot tinh tien tu dong.')
name = input('Ban ten la gi? ')
print('Hello', name, '!')
print('-----------------------------------------------------------')
#Khai bao cac san pham
print('Cac san pham hom nay gom co:')
gao = 20000
thit = 12000
rau = 5000
print('gao: ', gao, 'vnd/kg')
print('thit: ', thit, 'vnd/kg')
print('rau: ', rau, 'vnd/kg')
print()
#Bước 2
#Tao danh sach san pham
product = ['gao', 'thit', 'rau']
price = [gao, thit, rau]
#Tong tien
danh_sach = 'Chung ta da mua:\n'
sum = 0
rep = 'CO'
while rep == 'CO':
    ans = input('Ban muon mua gi? ')
    count = input('Ban muon mua bao nhieu ki-lo-gam? (nhap so tu nhien): ')
    amount = int(count)
    if ans == product[0]:
        sum = sum + price[0] * amount
        danh_sach = danh_sach + count + 'kg gao\n'
    elif ans == product[1]:
        sum = sum + price[1] * amount
        danh_sach = danh_sach + count + 'kg thit\n'
    elif ans == product[2]:
        sum = sum + price[2] * amount
        danh_sach = danh_sach + count + 'kg rau\n'
    else:
        print('Khong co', ans)
    rep = input('Nhap CO de tiep tuc mua do: ')
print(danh_sach)
print('So tien phai tra la:', sum, 'VND.')
#Bước 3
money = int(input('Ban co bao nhieu tien? '))
if money < sum:
    thieu = sum - money
    print('Ban con thieu :', thieu, 'VND.')
elif money == sum:
    print('May qua vua du', sum, 'VND.')
else:
    thua = money - sum
print('Con thua', thua, 'VND.')
print('Goodbye! See you again!')
