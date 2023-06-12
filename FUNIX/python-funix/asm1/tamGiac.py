"""
Cho tọa độ 3 đỉnh A, B, C của hình tam giác trong mặt phẳng không gian Oxy. 
Bài tập yêu cầu học viên tính toán các thông số của hình tam giác từ đơn giản đến phức tạp 
thông qua ngôn ngữ lập trình Python như:

Xét xem A, B, C có đủ điều kiện tạo thành tam giác ABC hay không.
  - Tính toán độ dài các cạnh và độ lớn các góc của tam giác ABC.
  - Đưa ra kết luận tam giác ABC là tam giác nhọn, tam giác vuông hay tam giác tù.
  - Đưa ra kết luận tam giác ABC là tam giác cân, tam giác đều, tam giác vuông cân hay tam giác bình thường.
  - Tính diện tích của tam giác ABC.
  - Tính độ dài các đường cao của tam giác ABC xuất phát từ các đỉnh A, B, C.
  - Tính độ dài đường trung tuyến từ các đỉnh tương ứng trong tam giác ABC.
  - Tính tọa độ trọng tâm và trực tâm của tam giác ABC.

xA = float(input())
yA = float(input())

xB = float(input())
yB = float(input())

xC = float(input())
yC = float(input())
"""
import math

def distance(data):
    d_AB = math.sqrt(math.pow((data[2] - data[0]), 2) + math.pow((data[3] - data[1]), 2))
    d_AC = math.sqrt(math.pow((data[4] - data[0]), 2) + math.pow((data[5] - data[1]), 2))
    d_BC = math.sqrt(math.pow((data[4] - data[2]), 2) + math.pow((data[5] - data[3]), 2))

    #format
    d_AB = float("{:.2f}".format(d_AB))
    d_AC = float("{:.2f}".format(d_AC))
    d_BC = float("{:.2f}".format(d_BC))

    return [d_AB, d_AC, d_BC]

def kiemtra_tamgiac(data) -> bool: 
    length_of_edges = distance(data)
    d_AB = length_of_edges[0]
    d_AC = length_of_edges[1]
    d_BC = length_of_edges[2]

    if d_AB + d_AC > d_BC and d_AB + d_BC > d_AC and d_AC + d_BC> d_AB:
        return True
    return False

def goccanh_tamgiac(data):
    length_of_edges = distance(data)
    d_AB = length_of_edges[0]
    d_AC = length_of_edges[1]
    d_BC = length_of_edges[2]

    #                  0   1   2   3    4   5
    # ex: Nhập tọa độ [Ax, Ay, Bx, By, Cx, Cy]
    v_AB = [data[2] - data[0], data[3] - data[1]]
    v_AC = [data[4] - data[0], data[5] - data[1]]
    
    v_BA = [data[0] - data[2], data[1] - data[3]]
    v_BC = [data[4] - data[2], data[5] - data[3]]

    v_CA = [data[0] - data[4], data[1] - data[5]]
    v_CB = [data[2] - data[4], data[3] - data[5]]

    angleA = math.acos((v_AB[0] * v_AC[0] + v_AB[1] * v_AC[1]) / (d_AB * d_AC)) * (180.0 / math.pi)
    angleB = math.acos((v_BA[0] * v_BC[0] + v_BA[1] * v_BC[1]) / (d_AB * d_BC)) * (180.0 / math.pi)
    angleC = math.acos((v_CB[0] * v_CA[0] + v_CB[1] * v_CA[1]) / (d_AC * d_BC)) * (180.0 / math.pi)

    # format
    angleA = float("{:.2f}".format(angleA))
    angleB = float("{:.2f}".format(angleB))
    angleC = float("{:.2f}".format(angleC))
    #      [AB,   BC,   CA,   góc A,  góc B,  góc C ].
    return [d_AB, d_BC, d_AC, angleA, angleB, angleC]

def xet_tamgiac(coordinates):
    data = goccanh_tamgiac(coordinates)
    d_AB = data[0]
    d_BC = data[1]
    d_AC = data[2]
    angleA = data[3]
    angleB = data[4]
    angleC = data[5]

    if (d_AB == d_AC and d_AB == d_BC and d_AC == d_BC):
        print("Tam giac ABC deu")
    elif (d_AB == d_AC):
        if (angleA == 90):
            print("ABC la tam giac vuong can tai dinh A")
        else:
            print("ABC la tam giac can tai dinh A")
    elif (d_AB == d_BC):
        if (angleB == 90):
            print("ABC la tam giac vuong can tai dinh B")
        else:
            print("ABC la tam giac can tai dinh B")
    elif (d_AC == d_BC):
        if (angleC == 90):
            print("ABC la tam giac vuong can tai dinh C")
        else:
            print("ABC la tam giac can tai dinh C")
    elif (angleA == 90):
        print("ABC la tam giac vuong tai dinh A")
    elif (angleB == 90):
        print("ABC la tam giac vuong tai dinh B")
    elif (angleC == 90):
        print("ABC la tam giac vuong tai dinh C")
    elif (angleA > 90):
        print("ABC la tam giac tu tai dinh A")
    elif (angleB > 90):
        print("ABC la tam giac tu tai dinh B")
    elif (angleC > 90):
        print("ABC la tam giac tu tai dinh C")
    else:
        print("ABC la tam giac binh thuong")
    
def dientich_tamgiac(data):
    #                  0   1   2   3    4   5
    # ex: Nhập tọa độ [Ax, Ay, Bx, By, Cx, Cy]
    # S = 0.5*|(xB - xA)*(yC - yA) - (xC - xA)*(yB - yA)|
    xA = data[0]
    yA = data[1]

    xB = data[2]
    yB = data[3]

    xC = data[4]
    yC = data[5]

    return float("{:.2f}".format(0.5*abs((xB - xA)*(yC - yA) - (xC - xA)*(yB - yA))))

def tam_tamgiac(data):
    trongTamX = 1/3 * (data[0] + data[2] + data[4])
    trongTamY = 1/3 * (data[1] + data[3] + data[5])

    v_AC = [data[4] - data[0], data[5] - data[1]]
    v_AB = [data[2] - data[0], data[3] - data[1]]

    xAB = v_AB[0]
    yAB = v_AB[1]

    xAC = v_AC[0]
    yAC = v_AC[1]

    xC = data[4]
    yC = data[5]

    xB = data[2]
    yB = data[3]
    # Goi H(x, y) la truc tam
    # AH vuong goc BC
    # BH vuong goc AC 
    # vector(AH) * vector(BC) = 0
    # vector(BH) * vector(AC) = 0
    # giai he pt bac nhat 2 an bang pp Cramer
    D = xAB * yAC - xAC * yAB
    Dx = (xAB * xC + yAB * yC) * yAC - (xAC * xB + yAC * yB) * yAB
    Dy = (xAB * xC + yAB * yC) * xAB - (xAC * xB + yAC * yB) * xAC
    trucTamX = Dx / D
    trucTamY = Dy / D
    return [trongTamX, trongTamY, trucTamX, trucTamY]

def giaima_tamgiac(data):
    if (kiemtra_tamgiac(data)):
        print("A, B, C hop thanh 1 tam giac")
        gocCanh = goccanh_tamgiac(data)
        print("Chieu dai canh AB:", gocCanh[0])
        print("Chieu dai canh BC:", gocCanh[1])
        print("Chieu dai canh CA:", gocCanh[2])

        print("GocA:", gocCanh[3])
        print("GocB:", gocCanh[4])
        print("GocC:", gocCanh[5])

        xet_tamgiac(data)
        print("Dien tich tam giac ABC:", dientich_tamgiac(data))

        points = tam_tamgiac(data)
        print("Toa do trong tam:", points[0], ",", points[1])
        print("Toa do truc tam:", points[2], ",", points[3])
    else:
        print("A, B, C khong hop thanh 1 tam giac")

if __name__ == '__main__':
  #                  0   1   2   3    4   5
  # ex: Nhập tọa độ [Ax, Ay, Bx, By, Cx, Cy]
  points = []
  for _ in range(0,6):
    try:
        data = input()
    except:
        print("Error")
    points.append(float(data))
  giaima_tamgiac(points)