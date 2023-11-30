#include <iostream>
using namespace std;

class MayXucTac {
private:
    static const int DON_GIA_THUE = 80000;  // Đơn giá thuê máy (đồng/h)
    static const int DON_GIA_HOA_CHAT = 10000;  // Đơn giá hóa chất (đồng/g)

    double congSuatLoc;  // Công suất lọc của máy (m3/h)
    double thoiGianSuDung;  // Thời gian sử dụng máy (h)
    double luongHoaChat;  // Lượng hóa chất sử dụng (g)

public:
    // Phương thức nhập thông tin sử dụng máy
    void nhap() {
        cout << "Nhap cong suat loc (m3/h): ";
        cin >> congSuatLoc;
        cout << "Nhap thoi gian su dung (h): ";
        cin >> thoiGianSuDung;
        cout << "Nhap luong hoa chat (g): ";
        cin >> luongHoaChat;
    }

    // Phương thức tính chi phí sử dụng máy
    double tinhChiPhi() {
        double chiPhiThue = DON_GIA_THUE * thoiGianSuDung;
        double chiPhiHoaChat = getDonGiaHoaChat() * luongHoaChat;
        return chiPhiThue + chiPhiHoaChat;
    }

    // Phương thức tính lượng nước lọc được
    double tinhLuongNuoc() {
        double congSuatLocThucTe;
        if (thoiGianSuDung < 10) {
            congSuatLocThucTe = congSuatLoc * (luongHoaChat / 100);
        } else {
            congSuatLocThucTe = congSuatLoc * (luongHoaChat / 100) / (thoiGianSuDung / 10);
        }
        return congSuatLocThucTe * thoiGianSuDung;
    }

    // Phương thức để truy cập DON_GIA_HOA_CHAT từ bên ngoài lớp
    static int getDonGiaHoaChat() {
        return DON_GIA_HOA_CHAT;
    }
};

int main() {
    cout << "Don gia hoa chat: " << MayXucTac::getDonGiaHoaChat() << endl;
    MayXucTac m;
    m.nhap();  // Nhập thông tin sử dụng của máy xúc tác này
    cout << "Chi phi su dung may: " << m.tinhChiPhi() << endl;
    cout << "Luong nuoc loc duoc: " << m.tinhLuongNuoc() << endl;

    return 0;
}
