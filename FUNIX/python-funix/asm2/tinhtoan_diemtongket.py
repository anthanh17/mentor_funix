# Hàng đầu tiên gồm các đề mục: “Mã HS, Toán , Lý, Hóa, Sinh, Văn, Anh, Sử, Địa”
# Hàng thứ 2 trở đi là bảng điểm chi tiết cho từng sinh viên

# xM01916_PYB101x_asm2
def tinh_diem_tu_nhien_xa_hoi(title, point):
    p_sv = {}
    for i in range(1, len(point)):
        if i <= 4:
            natural_subj = [int(i) for i in point[i].split(",")]
            #print(natural_subj)
            p_sv[title[i]] = float("{:.2f}".format(0.05 *natural_subj[0] + 0.1*natural_subj[1] + 0.15*natural_subj[2] + 0.7*natural_subj[3]))
        else:
            social_subj = [int(i) for i in point[i].split(",")]
            #print(social_subj)
            p_sv[title[i]] = float("{:.2f}".format(0.05*social_subj[0] + 0.1*social_subj[1] + 0.1*social_subj[2] + 0.15*social_subj[3] + 0.6*social_subj[4]))
    return p_sv

def tinhdiem_trungbinh(dir : str):
    ans = {}
    title = []
    with open(dir) as fp:
        line = fp.readline()
        cnt = 1
        while line:
            if cnt < 2:
                title = line.strip().split(", ")
                # print(title)
            else:
                point = line.strip().split(";")
                point[1] = point[1][1:]
                #print(point)
                ans[point[0]] = tinh_diem_tu_nhien_xa_hoi(title, point)
            line = fp.readline()
            cnt += 1
    print(ans)
    return ans

def luudiem_trungbinh(data):
    f = open('diem_trungbinh.txt', "w", encoding='utf8')
    line1 = "Ma HS"
    for key in data['1']:
        line1 += ", " + str(key)
    f.write(line1 + "\n")

    for key in data:
        line = str(key)
        for i in data[key]:
            line += "; " + str(data[key][i])
        print(line)
        f.write(line + "\n")
        line = ""
    f.close()

if __name__ == '__main__':
    data = tinhdiem_trungbinh("diem_chitiet.txt")
    luudiem_trungbinh(data)
