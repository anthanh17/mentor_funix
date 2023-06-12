pw = input("Enter pw: ")

diem = 0
is_len8 = False
if len(pw) >= 8:
  is_len8 = True
is_upper = False

for i in pw:
  if i.is_upper():
    is_upper = True

if is_len8:
  diem += 10
if is_upper:
  diem += 10

""" 10 10 20 30
if 31 < ord(i) < 48 or 57 < ord(i) < 65 \
    or 90 < ord(i) < 97 or 122 < ord(i) < 127:
    is_special = True
"""
