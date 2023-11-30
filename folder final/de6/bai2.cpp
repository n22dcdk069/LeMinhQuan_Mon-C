#include <iostream>
#include <vector>
#include <string>

using namespace std;

class KhamBenh {
public:
    int ngay;
    int msbn;
    string loaiHoatDong;
    int phi;
    char loaiPhong;

    KhamBenh(int ngay, int msbn, string loaiHoatDong, int phi, char loaiPhong = ' ')
        : ngay(ngay), msbn(msbn), loaiHoatDong(loaiHoatDong), phi(phi), loaiPhong(loaiPhong) {}
};

class BenhNhan {
public:
    int msbn;
    string hoTen;
    int soNgayNamVien;
    char loaiPhong;

    BenhNhan(int msbn, string hoTen)
        : msbn(msbn), hoTen(hoTen), soNgayNamVien(0), loaiPhong(' ') {}

    int tinhPhi() const {
        if (loaiPhong == 'A') {
            return soNgayNamVien * (1400000 + 600000);
        } else if (loaiPhong == 'B') {
            return soNgayNamVien * (900000 + 600000);
        } else if (loaiPhong == 'C') {
            return soNgayNamVien * (600000 + 600000);
        } else {
            return 0;  // Bệnh nhân ngoại trú
        }
    }
};

class DanhSachBenhNhan {
public:
    vector<BenhNhan> danhSach;

    void themBenhNhan(int msbn, string hoTen) {
        BenhNhan bn(msbn, hoTen);
        danhSach.push_back(bn);
    }

    void xuLyHoatDong(const KhamBenh &hoatDong) {
        for (BenhNhan &bn : danhSach) {
            if (bn.msbn == hoatDong.msbn) {
                if (hoatDong.loaiHoatDong == "NV") {
                    bn.soNgayNamVien++;
                    bn.loaiPhong = hoatDong.loaiPhong;
                }
                break;
            }
        }
    }

    void inBangThongKe() const {
        int tongPhi = 0;
        int benhNhanNoiTru = 0;
        int benhNhanNgoaiTru = 0;

        cout << "+------------------+-------------------+---------------------+" << endl;
        cout << "| Mã số bệnh nhân | Họ tên bệnh nhân | Tổng viện phí (VNĐ) |" << endl;
        cout << "+------------------+-------------------+---------------------+" << endl;

        for (const BenhNhan &bn : danhSach) {
            cout << "| " << bn.msbn << "\t\t| " << bn.hoTen << "\t| " << bn.tinhPhi() << "\t\t\t|" << endl;
            tongPhi += bn.tinhPhi();
            if (bn.loaiPhong != ' ') {
                benhNhanNoiTru++;
            } else {
                benhNhanNgoaiTru++;
            }
        }

        cout << "+------------------+-------------------+---------------------+" << endl;
        cout << "| Tổng số bệnh nhân nội trú: " << benhNhanNoiTru << "\t\t\t|" << endl;
        cout << "| Tổng số bệnh nhân ngoại trú: " << benhNhanNgoaiTru << "\t\t|" << endl;
        cout << "| Tổng viện phí bệnh viện: " << tongPhi << "\t\t\t\t|" << endl;
        cout << "+------------------+-------------------+---------------------+" << endl;
    }
};

int main() {
    DanhSachBenhNhan dsBenhNhan;

    // Giả sử đã đọc dữ liệu từ tập tin nhật ký và lưu vào danh sách hoạt động
    vector<KhamBenh> danhSachHoatDong = {
        KhamBenh(1, 1, "KB", 20000),
        KhamBenh(2, 2, "NV", 100000, 'B'),
        KhamBenh(6, 3, "KB", 50000),
        KhamBenh(6, 1, "KB", 30000),
        KhamBenh(6, 4, "NV", 300000, 'C'),
        KhamBenh(7, 4, "XV", 0),
        KhamBenh(8, -1, "TKVP", 0)
    };

    // Xử lý hoạt động từ danh sách
    for (const KhamBenh &hoatDong : danhSachHoatDong) {
        if (hoatDong.ngay == -1 && hoatDong.loaiHoatDong == "TKVP") {
            dsBenhNhan.inBangThongKe();
            break;
        } else {
            dsBenhNhan.xuLyHoatDong(hoatDong);
        }
    }

    return 0;
}
