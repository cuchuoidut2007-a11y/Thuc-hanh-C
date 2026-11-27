#include <iostream>
#include <string>

using namespace std;

class LichHoc {
private:
    string ma_lich;
    string ten_mon;
    string ma_lop;
    string giang_vien;
    int thu;
    int tiet_bat_dau;
    int so_tiet;
    string phong_hoc;

public:
    LichHoc() {
        ma_lich = "";
        ten_mon = "";
        ma_lop = "";
        giang_vien = "";
        thu = 0;
        tiet_bat_dau = 0;
        so_tiet = 0;
        phong_hoc = "";
    }

    void nhapThongTin() {
        cout << "Nhap ma lich hoc: "; 
        getline(cin, ma_lich);
        
        cout << "Nhap ten mon hoc: "; 
        getline(cin, ten_mon);
        
        cout << "Nhap ma lop: "; 
        getline(cin, ma_lop);
        
        cout << "Nhap ten giang vien: "; 
        getline(cin, giang_vien);
        
        do {
            cout << "Nhap thu trong tuan (tu thu 2 den thu 8): ";
            cin >> thu;
            cin.ignore(1000, '\n');
        } while (thu < 2 || thu > 8);

        do {
            cout << "Nhap tiet bat dau (tu 1 den 12): ";
            cin >> tiet_bat_dau;
            cin.ignore(1000, '\n'); 
        } while (tiet_bat_dau < 1 || tiet_bat_dau > 12);

        do {
            cout << "Nhap so tiet (tu 1 den 5): ";
            cin >> so_tiet;
            cin.ignore(1000, '\n');
        } while (so_tiet < 1 || so_tiet > 5);

        cout << "Nhap phong hoc: "; 
        getline(cin, phong_hoc);
    }

    void inThongTin() {
        cout << ma_lich << "\t| " 
             << ten_mon << "\t| " 
             << ma_lop << "\t| " 
             << giang_vien << "\t| Thu " 
             << thu << "\t| Tiet " 
             << tiet_bat_dau << "\t| " 
             << so_tiet << " tiet\t| " 
             << phong_hoc << endl;
    }

    void suaThongTin() {
        int chon;
        cout << "\n--- CHON THONG TIN CAN SUA ---\n";
        cout << "1. Sua lai toan bo thong tin\n";
        cout << "2. Sua Ten mon hoc\n";
        cout << "3. Sua Ma lop\n";
        cout << "4. Sua Giang vien\n";
        cout << "5. Sua Thu / Tiet / Phong hoc\n";
        cout << "Lua chon cua ban: ";
        cin >> chon;
        cin.ignore(1000, '\n');

        if (chon == 1) {
            nhapThongTin();
        } 
        else if (chon == 2) {
            cout << "Nhap Ten mon hoc moi: ";
            getline(cin, ten_mon);
        } 
        else if (chon == 3) {
            cout << "Nhap Ma lop moi: ";
            getline(cin, ma_lop);
        } 
        else if (chon == 4) {
            cout << "Nhap Giang vien moi: ";
            getline(cin, giang_vien);
        } 
        else if (chon == 5) {
            do {
                cout << "Nhap Thu moi (2-8): ";
                cin >> thu;
                cin.ignore(1000, '\n');
            } while (thu < 2 || thu > 8);

            do {
                cout << "Nhap Tiet bat dau moi (1-12): ";
                cin >> tiet_bat_dau;
                cin.ignore(1000, '\n');
            } while (tiet_bat_dau < 1 || tiet_bat_dau > 12);

            cout << "Nhap Phong hoc moi: ";
            getline(cin, phong_hoc);
        }
        cout << "=> Cap nhat thong tin thanh cong!\n";
    }

    string layMaLich() { return ma_lich; }
    string layTenMon() { return ten_mon; }
    string layMaLop() { return ma_lop; }
    string layGiangVien() { return giang_vien; }
    int layThu() { return thu; }
    int layTietBatDau() { return tiet_bat_dau; }
    int laySoTiet() { return so_tiet; }
    string layPhongHoc() { return phong_hoc; }
};

class QuanLyDanhSach {
private:
    LichHoc mang_lich_hoc[200];
    int so_luong;

public:
    QuanLyDanhSach() {
        so_luong = 0;
    }

    void nhapDanhSach() {
        do {
            cout << "Ban muon nhap bao nhieu lich hoc (0 < n < 200)? n = ";
            cin >> so_luong;
            cin.ignore(1000, '\n');
            if (so_luong <= 0 || so_luong >= 200) {
                cout << "So luong sai roi, nhap lai nhe!\n";
            }
        } while (so_luong <= 0 || so_luong >= 200);

        for (int i = 0; i < so_luong; i++) {
            cout << "\n--- Nhap lich hoc thu " << i + 1 << " ---\n";
            mang_lich_hoc[i].nhapThongTin();
        }
    }

    void inDanhSach() {
        if (so_luong == 0) {
            cout << "Danh sach dang trong!\n";
            return;
        }
        cout << "MA LICH\t| TEN MON\t| MA LOP\t| GIANG VIEN\t| THU\t| TIET BD\t| SO TIET\t| PHONG\n";
        cout << "--------------------------------------------------------------------------------------------------------\n";
        for (int i = 0; i < so_luong; i++) {
            mang_lich_hoc[i].inThongTin();
        }
    }

    void sapXep() {
        for (int i = 0; i < so_luong - 1; i++) {
            for (int j = i + 1; j < so_luong; j++) {
                if (mang_lich_hoc[i].layThu() > mang_lich_hoc[j].layThu() ||
                   (mang_lich_hoc[i].layThu() == mang_lich_hoc[j].layThu() && 
                    mang_lich_hoc[i].layTietBatDau() > mang_lich_hoc[j].layTietBatDau())) 
                {
                    LichHoc tam = mang_lich_hoc[i];
                    mang_lich_hoc[i] = mang_lich_hoc[j];
                    mang_lich_hoc[j] = tam;
                }
            }
        }
        cout << "\n=> Da sap xep xong! Ban hay chon in danh sach de xem.\n";
    }

    void timKiem() {
        int chon;
        cout << "\n1. Tim theo Ma lop\n2. Tim theo Ten mon\nChon cach tim (1 hoac 2): ";
        cin >> chon;
        cin.ignore(1000, '\n');

        string tu_khoa;
        cout << "Nhap tu khoa can tim: ";
        getline(cin, tu_khoa);

        bool thay = false;
        cout << "\n--- KET QUA TIM KIEM ---\n";
        for (int i = 0; i < so_luong; i++) {
            if ((chon == 1 && mang_lich_hoc[i].layMaLop() == tu_khoa) || 
                (chon == 2 && mang_lich_hoc[i].layTenMon() == tu_khoa)) {
                mang_lich_hoc[i].inThongTin();
                thay = true;
            }
        }
        
        if (thay == false) {
            cout << "=> Khong tim thay lich hoc nao.\n";
        }
    }

    void suaLich() {
        if (so_luong == 0) {
            cout << "Danh sach trong, khong co lich de sua!\n";
            return;
        }

        int vi_tri;
        cout << "\nBan muon sua lich hoc o vi tri thu may (tu 1 den " << so_luong << ")? ";
        cin >> vi_tri;
        cin.ignore(1000, '\n');

        if (vi_tri < 1 || vi_tri > so_luong) {
            cout << "Vi tri nay khong ton tai!\n";
            return;
        }
        cout << "\n--- THONG TIN HIEN TAI ---\n";
        mang_lich_hoc[vi_tri - 1].inThongTin();
        cout << "\n--- NHAP THONG TIN MOI ---\n";
        mang_lich_hoc[vi_tri - 1].nhapThongTin();
    }

    void themLich() {
        if (so_luong >= 199) {
            cout << "Danh sach day roi, khong them duoc nua!\n";
            return;
        }

        int vi_tri;
        cout << "\nBan muon them vao vi tri thu may (tu 1 den " << so_luong + 1 << ")? ";
        cin >> vi_tri;
        cin.ignore(1000, '\n');

        if (vi_tri < 1 || vi_tri > so_luong + 1) {
            cout << "Vi tri nay khong hop le.\n";
            return;
        }

        cout << "\n--- Nhap thong tin lich hoc moi ---\n";
        LichHoc lich_moi;
        lich_moi.nhapThongTin();

        for (int i = so_luong; i >= vi_tri; i--) {
            mang_lich_hoc[i] = mang_lich_hoc[i - 1];
        }
        
        mang_lich_hoc[vi_tri - 1] = lich_moi;
        so_luong++;
        cout << "=> Da them thanh cong!\n";
    }

    void xoaLich() {
        if (so_luong == 0) {
            cout << "Danh sach trong, khong co gi de xoa!\n";
            return;
        }

        int vi_tri;
        cout << "\nBan muon xoa lich o vi tri thu may (tu 1 den " << so_luong << ")? ";
        cin >> vi_tri;
        cin.ignore(1000, '\n');

        if (vi_tri < 1 || vi_tri > so_luong) {
            cout << "Vi tri nay khong ton tai.\n";
            return;
        }

        for (int i = vi_tri - 1; i < so_luong - 1; i++) {
            mang_lich_hoc[i] = mang_lich_hoc[i + 1];
        }
        
        so_luong--;
        cout << "=> Da xoa thanh cong!\n";
    }
};

int main() {
    QuanLyDanhSach ql;

    cout << "===============================================\n";
    cout << "    CHUONG TRINH QUAN LY LICH HOC!\n";
    cout << "===============================================\n";
    cout << "Truoc tien, ban can khoi tao danh sach lich hoc.\n";
    
    ql.nhapDanhSach();

    cout << "\n=================================================\n";
    cout << "      DANH SACH LICH HOC BAN VUA NHAP LA:\n";
    cout << "=================================================\n";
    ql.inDanhSach();

    int lua_chon;
    do {
        cout << "\n=================== MENU ===================\n";
        cout << "1. Xem danh sach lich hoc (dang bang)\n";
        cout << "2. Sap xep danh sach (theo Thu va Tiet)\n";
        cout << "3. Tim kiem lich hoc (theo Ma lop/Ten mon)\n";
        cout << "4. Bo sung (Them) 1 lich hoc vao danh sach\n";
        cout << "5. Xoa 1 lich hoc khoi danh sach\n";
        cout << "6. Sua thong tin 1 lich hoc\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "============================================\n";
        cout << "Chon chuc nang (0-6)? ";
        cin >> lua_chon;
        cin.ignore(1000, '\n'); 

        if (lua_chon == 1) {
            ql.inDanhSach();
        } 
        else if (lua_chon == 2) {
            ql.sapXep();
        } 
        else if (lua_chon == 3) {
            ql.timKiem();
        } 
        else if (lua_chon == 4) {
            ql.themLich();
        } 
        else if (lua_chon == 5) {
            ql.xoaLich();
        } 
        else if (lua_chon == 6) {
            ql.suaLich();
        }
        else if (lua_chon == 0) {
            cout << "Cam on ban da su dung chuong trinh. Tam biet!\n";
        } 
        else {
            cout << "Lua chon sai, vui long nhap lai!\n";
        }

    } while (lua_chon != 0);

    return 0;
}

