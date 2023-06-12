"""
Calculate the security score and mark the security rank
Take password from user and calculate the security score:
If password length is greater than 8 and password includes normal characters 🡪 +10
If password includes upper characters	  🡪 +10
If password includes number		          🡪 +20
If password includes special characters	🡪 +30
If password includes all above	        🡪 +30
If password includes repeated characters	    🡪 -1 * repeated times
-----
Announce the security rank:
If score < 30	 🡪 Poor
If 30 < scores < 70	 🡪 Weak
If score >= 70 🡪 Strong
-----
If you can, please provide some stronger passwords for user which are based on
his / her origin password.
Ex: passwoord	-> Suggestions: P@s5wo0rd3431
"""
data = str(input("Enter password: "))
scores = 0

is_greater_than_8 = False
is_upper = False
is_numeric = False
is_special = False
is_repeated = False

if len(data) >= 8:
  is_greater_than_8 = True

times = {}

for i in data:
  if i in times:
    times[i] += 1
  else:
    times[i] = 1

  if i.isupper():
    is_upper = True
  if i.isnumeric():
    is_numeric = True
  # https://theasciicode.com.ar/
  if 31 < ord(i) < 48 or 57 < ord(i) < 65 \
    or 90 < ord(i) < 97 or 122 < ord(i) < 127:
    is_special = True

if is_greater_than_8:
  scores += 10
  print("+is_greater_than_8")
if is_upper:
  scores += 10
  print("+is_upper")
if is_numeric:
  scores += 20
  print("+is_numeric")
if is_special:
  scores += 30
  print("+is_special")
if is_greater_than_8 and is_upper and is_numeric and is_special:
  scores += 30
  print("+all")

for i in times:
  if times[i] > 1:
    scores -= times[i]
    is_repeated = True

print(scores)
suggestions = 'P@s5wo0rd324'
if scores < 30:
  print("--> Poor")
  print("Suggestions: ", suggestions)
elif 30 < scores < 70:
  print("--> Weak")
elif scores >= 70:
  print("--> Strong")
