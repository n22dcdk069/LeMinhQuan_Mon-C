#include <iostream>
#include <vector>
using namespace std;

class MayLoc {
public:
    virtual double tinhChiPhi() const = 0;
    virtual double tinhLuongNuoc() const = 0;
    virtual void nhap() = 0;  // Make it a pure virtual function
    virtual ~MayLoc() {}  // Add a virtual destructor
};

class MayLyTam : public MayLoc {
private:
    static const int DON_GIA_THUE = 50000;
    double luongXang;

public:
    MayLyTam() : luongXang(0) {}

    double getDonGiaThue() const {
        return DON_GIA_THUE;
    }

    void nhap() override {
        cout << "Nhap luong xang (lit): ";
        cin >> luongXang;
    }

    double tinhChiPhi() const override {
        return DON_GIA_THUE * luongXang;
    }

    double tinhLuongNuoc() const override {
        return 0;  // May ly tam không lọc nước
    }
};

class MayXucTac : public MayLoc {
private:
    static const int DON_GIA_THUE = 80000;
    static const int DON_GIA_HOA_CHAT = 10000;
    double congSuatLoc;
    double thoiGianSuDung;
    double luongHoaChat;

public:
    MayXucTac() : congSuatLoc(0), thoiGianSuDung(0), luongHoaChat(0) {}

    double getDonGiaThue() const {
        return DON_GIA_THUE;
    }

    void nhap() override {
        cout << "Nhap cong suat loc (m3/h): ";
        cin >> congSuatLoc;
        cout << "Nhap thoi gian su dung (h): ";
        cin >> thoiGianSuDung;
        cout << "Nhap luong hoa chat (g): ";
        cin >> luongHoaChat;
    }

    double tinhChiPhi() const override {
        double chiPhiThue = DON_GIA_THUE * thoiGianSuDung;
        double chiPhiHoaChat = DON_GIA_HOA_CHAT * luongHoaChat;
        return chiPhiThue + chiPhiHoaChat;
    }

    double tinhLuongNuoc() const override {
        double congSuatLocThucTe;
        if (thoiGianSuDung < 10) {
            congSuatLocThucTe = congSuatLoc * (luongHoaChat / 100);
        } else {
            congSuatLocThucTe = congSuatLoc * (luongHoaChat / 100) / (thoiGianSuDung / 10);
        }
        return congSuatLocThucTe * thoiGianSuDung;
    }
};

class AoChuaNuoc {
private:
    double soMetKhoiNuoc;
    vector<MayLoc*> mayLocs;

public:
    AoChuaNuoc() : soMetKhoiNuoc(0) {}

    void nhap() {
        cout << "Nhap so met khoi nuoc trong ao: ";
        cin >> soMetKhoiNuoc;

        int soMayLoc;
        cout << "Nhap so may loc: ";
        cin >> soMayLoc;

        for (int i = 0; i < soMayLoc; ++i) {
            char loaiMay;
            cout << "Nhap loai may (L: Ly Tam, X: Xuc Tac): ";
            cin >> loaiMay;

            MayLoc* may;
            if (loaiMay == 'L' || loaiMay == 'l') {
                may = new MayLyTam();
            } else if (loaiMay == 'X' || loaiMay == 'x') {
                may = new MayXucTac();
            } else {
                cout << "Loai may khong hop le. Bo qua may nay." << endl;
                continue;
            }

            may->nhap();
            mayLocs.push_back(may);
        }
    }

    void themMayLoc(MayLoc* mayLoc) {
        mayLocs.push_back(mayLoc);
    }

    double tinhChiPhiToanBoMayLoc() const {
        double tongChiPhi = 0;
        for (const auto& may : mayLocs) {
            tongChiPhi += may->tinhChiPhi();
        }
        return tongChiPhi;
    }

    double tinhLuongNuocLocDuoc() const {
        double tongLuongNuoc = 0;
        for (const auto& may : mayLocs) {
            tongLuongNuoc += may->tinhLuongNuoc();
        }
        return tongLuongNuoc;
    }

    void hienThiThongTin() const {
        cout << "Tong chi phi su dung may loc: " << tinhChiPhiToanBoMayLoc() << endl;
        cout << "Tong luong nuoc loc duoc: " << tinhLuongNuocLocDuoc() << " m3" << endl;
        if (tinhLuongNuocLocDuoc() >= soMetKhoiNuoc) {
            cout << "Ao co duoc loc het nuoc." << endl;
        } else {
            cout << "Ao khong duoc loc het nuoc." << endl;
        }
    }

    ~AoChuaNuoc() {
        for (const auto& may : mayLocs) {
            delete may;
        }
    }
};

int main() {
    AoChuaNuoc ao;
    ao.nhap();
    ao.hienThiThongTin();

    return 0;
}
