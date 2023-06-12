def xep_loai(list_point):
  isXuatSac = True
  isGioi = True
  isKha = True
  isTBKha = True

  list_point = [float(x) for x in list_point]
  #          0     1   2    3     4    5   6    7
  # data = [Toan, Ly, Hoa, Sinh, Van, Anh, Su, Dia]

  for i in list_point:
    if i < 8.0:
      isXuatSac = False
      if i < 6.5:
        isGioi = False
        if i < 5.0:
          isKha = False
          if i < 4.5:
            isTBKha = False
  pointTB = ((list_point[0] + list_point[4] + list_point[5]) * 2.0
            + (list_point[1] + list_point[2] + list_point[3]
              + list_point[6] + list_point[7]) * 1.0) / 11.0
  # print("diem tb:", pointTB)
  if pointTB > 9.0 and isXuatSac:
    return "Xuat sac"
  elif pointTB > 8.0 and isGioi:
    return "Gioi"
  elif pointTB > 6.5 and isKha:
    return "Kha"
  elif pointTB > 6.0 and isTBKha:
    return "TB kha"
  else:
    return "TB"


def xeploai_hocsinh(dir : str):
  ans = {}
  with open(dir) as fp:
    line = fp.readline()
    cnt = 1
    while line:
      if cnt > 1:
        point = line.strip().split("; ")
        #print(point)
        ans[point[0]] = xep_loai(point[1:])
      line = fp.readline()
      cnt += 1
    #print("ans:", ans)
  return ans

def tu_nhien(diem: float) -> int:
  """
  Ở khối tự nhiên (A, A1, B)
    - Loại 1:  >= 24.
    - Loại 2:  < 24 và >= 18.
    - Loại 3:  < 18 và >= 12.
    - Loại 4:  < 12.
  """
  if diem >= 24:
    return 1
  elif diem < 24 and diem >= 18:
    return 2
  elif diem < 18 and diem >= 12:
    return 3
  elif diem < 12:
    return 4

def xa_hoi(diem: float) -> int:
  """
  Ở khối xã hội (C),
    - Loại 1 (>=21),
    - loại 2(<21 và >=15),
    - loại 3(<15 và >=12),
    - loại 4(<12).
  """
  if diem >= 21:
    return 1
  elif diem < 21 and diem >= 15:
    return 2
  elif diem < 15 and diem >= 12:
    return 3
  elif diem < 12:
    return 4

def co_ban(diem: float) -> int:
  """
  - Ở khối cơ bản (D):
    - Loại 1(>=32),
    - loại 2(<32 và >=24),
    - loại 3(<24 và >=20),
    - loại 4(<20)
    * điểm tiếng Anh có hệ số nhân đôi.
  """
  if diem >= 32:
    return 1
  elif diem < 32 and diem >= 24:
    return 2
  elif diem < 24 and diem >= 20:
    return 3
  elif diem < 20:
    return 4

def xep_loai_khoi(data):
  # [A, A1, B, C, D]
  data = [float(x) for x in data]
  ans = []

  #          0     1   2    3     4    5   6    7
  # data = [Toan, Ly, Hoa, Sinh, Van, Anh, Su, Dia]

  # Khoi A (Toán, Lý Hóa)
  a = (data[0] + data[1] + data[2])
  ans.append(tu_nhien(a))

  # A1(Toán, Lý, Anh)
  a1 = (data[0] + data[1] + data[4])
  ans.append(tu_nhien(a1))

  # B(Toán, Hóa, Sinh)
  b = (data[0] + data[2] + data[3])
  ans.append(tu_nhien(b))

  #          0     1   2    3     4    5   6    7
  # data = [Toan, Ly, Hoa, Sinh, Van, Anh, Su, Dia]
  # C(Văn, Sử Địa)
  c = (data[4] + data[6] + data[7])
  ans.append(xa_hoi(c))

  #  D(Toán, Văn, Anh)
  d = (data[0] + data[4] + data[5] * 2)
  ans.append(co_ban(d))

  return ans

def xeploai_thidaihoc_hocsinh(dir: str):
  ans = {}
  with open(dir) as fp:
    line = fp.readline()
    cnt = 1
    while line:
      if cnt > 1:
        point = line.strip().split("; ")
        #print(point)
        ans[point[0]] = xep_loai_khoi(point[1:])
      line = fp.readline()
      cnt += 1
  #print("ans:",ans)
  return ans
if __name__ == '__main__':
  dir = "diem_trungbinh.txt"
  data1 = xeploai_hocsinh(dir)
  data2 = xeploai_thidaihoc_hocsinh(dir)

  f = open('danhgia_hocsinh.txt', "w", encoding='utf8')

  line = ["Ma HS", "xeploai_TB chuan", "xeploai_A", "xeploai_A1",
          "xeploai_B", "xeploai_C", "xeploai_D"]
  line1 = ", ".join(line)
  f.write(line1 + "\n")
  print("----")
  print(line1)
  for key in data1:
      line = str(key)
      line += "; " + str(data1[key])
      for i in range(len(data2[key])):
          line += "; " + str(data2[key][i])
      print(line)
      f.write(line + "\n")
      line = ""
  f.close()
