#include "TUBES.h"




//Menu
int Menu(){
    //IS : -
    //FS : Mengembalikan suatu nilai dari variabel opsi
    int opsi;
        cout << "==================== M E N U ======================" << endl;
        cout << "1. Tambah data Film" << endl;
        cout << "2. Tampilkan semua  data Film" << endl;
        cout << "3. Hapus data Film atau Penonton" << endl;
        cout << "4. Mencari data Film " << endl;
        cout << "5. Tambah data Penonton" << endl;
        cout << "6. Update data Film atau Penonton" << endl;
        cout << "7. Tampilkan semua data Film beserta Penontonya" << endl;
        cout << "8. Mencari data Penonton" << endl;
        cout << "9. Hitung total data Penonton" << endl;
        cout << "10.Input Test"<< endl;
        cout << "0. Exit" << endl;
        cout << "===================================================" << endl;

        cout << "Pilih opsi: ";
        cin >> opsi;
        return opsi;
};

void backtoMenu(int &opsi){
    //IS : Tersedia parameter opsi
    //FS : Mengembalikan nilai suatu variabel opsi dan kembali ke menu awal
    string pilihan;
    cout <<"Kembali ke Menu? YES/NO : ";
    cin >> pilihan;
    if(pilihan == "YES"){
        opsi = Menu();
    }else{
        opsi = 0;
    }
};

void pilihan(int opsi,List &L){
    //IS : Tersedia Pilihan menu berdasarkan opsi
    //FS : User dapat memilih opsi untuk menuju menu
    while(opsi!=0){
        if(opsi == 1){
                adrfilm P;
                infotypeF info;
                cout <<"Masukan judul: ";
                cin >> info.Judul;
                cout <<"Masukan rating: ";
                cin >> info.Rating;
                cout <<"Masukan sinopsis: ";
                cin >> info.Sinopsis;
                cout <<"Masukan batasan umur: ";
                cin >> info.Batasan_Umur;
                cout <<"Masukan genre: ";
                cin >> info.Genre;
                cout <<"Masukan durasi: ";
                cin >> info.Durasi;
                P = createElmFilm(info);
                inserLastFilm(L, P);
                backtoMenu(opsi);
        }else if(opsi == 2){
            showAllFilm(L);
            backtoMenu(opsi);
        }else if(opsi == 3){
             int pilihan;
             cout << "---------------------------------------------------" << endl;
             cout << "1.Hapus data film" << endl;
             cout << "2.Hapus data penonton" << endl;
             cout << "---------------------------------------------------" << endl;
             cout <<"Masukan pilihan: ";
             cin >> pilihan;
             if(pilihan == 1){
                deleteFilm(L);
                backtoMenu(opsi);
             }else if(pilihan == 2){
                deletePenonton(L);
                backtoMenu(opsi);
             }
        }else if(opsi == 4){
            string judul;
            cout <<"Masukan judul: ";
            cin >> judul;
            adrfilm P = searchFilm(L,judul);
            if(P!=NULL){
                cout << "Data yang dicari tersedia"<<endl;
                cout<<"=========================="<<endl;
                cout << "Judul  : " <<infoFilm(P).Judul <<endl;
                cout << "Rating : " <<infoFilm(P).Rating <<endl;
                cout << "Sinopsis :" <<infoFilm(P).Sinopsis <<endl;
                cout << "Batasan Umur Penonton : " <<infoFilm(P).Batasan_Umur <<endl;
                cout << "Genre : " <<infoFilm(P).Genre <<endl;
                cout << "Durasi : " <<infoFilm(P).Durasi <<endl;
                cout<<"=========================="<<endl;
                backtoMenu(opsi);
            }else{
                cout <<endl;
                cout << "========= judul tidak ditemukan ========" << endl;
                cout << "== Silahkan masukkan judul yang valid =="<< endl;
                cout <<endl;
                backtoMenu(opsi);
            }

        }else if(opsi == 5){
            adrPenonton P;
            adrfilm F;
            infotypeP data;
            cout <<"Masukan nama: ";
            cin >> data.Nama;
            cout <<"Masukan umur: ";
            cin >> data.Umur;
            P = createElmPenonton(data);
            string judul;
            cout <<"Masukan judul: ";
            cin >> judul;
            F = searchFilm(L,judul);
            if(F!=NULL){
                insertFirstPenonton(L,P,F);
                backtoMenu(opsi);
            }else{
                while(F==NULL){
                    cout <<endl;
                    cout << "========= judul tidak ditemukan ========" << endl;
                    cout << "== Silahkan masukkan judul yang valid =="<< endl;
                    cout <<endl;
                    cout <<"Masukan judul: ";
                    cin >> judul;
                    F = searchFilm(L,judul);
                }
                insertFirstPenonton(L,P,F);
                backtoMenu(opsi);
            }
        }else if(opsi == 6){
            int pilihan;
             cout << "---------------------------------------------------" << endl;
             cout << "1.Update data film" << endl;
             cout << "2.Update data penonton" << endl;
             cout << "---------------------------------------------------" << endl;
             cout <<"Masukan pilihan: ";
             cin >> pilihan;
             if(pilihan == 1){
                updateFilm(L);
                backtoMenu(opsi);
             }else if(pilihan == 2){
                updatePenonton(L);
                backtoMenu(opsi);
             }
        }else if(opsi == 7){
            showFilmdanPenonton(L);
            backtoMenu(opsi);
        }else if(opsi == 8){
            string nama;
            cout <<"Masukan nama: ";
            cin >> nama;
            adrPenonton P = searchPenontonInFilm(L,nama);
            if(P!=NULL){
                cout << "=======================================================================================================================" << endl;
                cout << "| Nama              |  Umur  |" << endl;
                cout << "=======================================================================================================================" << endl;
                cout << "| " << setw(17) << infoPenonton(P).Nama << " | "
                     << setw(6) << infoPenonton(P).Umur << " |" << endl;
                cout << "=======================================================================================================================" << endl;

                backtoMenu(opsi);
            }else{
                cout <<endl;
                cout << "========= Nama tidak ditemukan ========" << endl;
                cout << "== Silahkan masukkan nama yang valid =="<< endl;
                cout <<endl;
                backtoMenu(opsi);
            }
        }else if(opsi == 9){
            cout <<"Total penonton adalah: "<<countTotalPenonton(L)<<endl;
            Print_penonton(L);
            backtoMenu(opsi);
        }else if(opsi == 10){
            infotypeF data;
            infotypeP dataP;
            cout << "\033[32mInput test BERHASIL dijalankan gan!\033[0m" << endl;
            input_test(L,data,dataP);
            showFilmdanPenonton(L);
            backtoMenu(opsi);

        }
    }
    if (opsi == 0) {
            cout << "Anda telah keluar dari program." << endl;
        }
};





void createList(List &L){
    //IS : -
    //FS : Terbentuk list kosong
    first(L) = NULL;
};












//Film
adrfilm createElmFilm(infotypeF info){
    //IS : Tersedia piranti masukan dari info.
    //FS : Terbentuk suatu list beserta element.
    adrfilm P = new elmFilm;
    infoFilm(P) = info;
    nextFilm(P)=NULL;
    prevFilm(P)=NULL;
    firstPenonton(P) = NULL;
    return P;

};

void inserLastFilm(List &L, adrfilm P){
    // IS: List L mungkin kosong atau sudah berisi elemen film.
    // FS: Elemen film P telah ditambahkan ke akhir list L.
    if(first(L)==NULL){
        first(L)=P;
        last(L)=P;
    }else{
        nextFilm(last(L)) = P;
        prevFilm(P) = last(L);
        last(L) = P;

    }

};

void showAllFilm(List L) {
    // IS: List L mungkin kosong atau sudah berisi satu atau lebih elemen film.
    // FS: Semua data film dalam list L telah ditampilkan pada layar. Jika list kosong, tampilkan pesan "List kosong."
    adrfilm P;
    if (first(L) == NULL) {
        cout << "Data film kosong" << endl;
    } else {
        // Header table
        cout << "=======================================================================================================================" << endl;
        cout << "|  No | Judul                | Rating |  Batasan Umur |      Genre      |      Durasi     | Sinopsis                  |" << endl;
        cout << "=======================================================================================================================" << endl;
        int j = 1;
        P = first(L);
        while (P != NULL) {
            cout << "| " <<j<< "   | "
                 << left << setw(20) << infoFilm(P).Judul.substr(0, 20) << " | " // Potong judul jika lebih dari 20 karakter
                 << setw(6) << infoFilm(P).Rating << " | "
                 << setw(13) << infoFilm(P).Batasan_Umur << " | "
                 << setw(15) << infoFilm(P).Genre << " | "
                 << right << setw(13) << infoFilm(P).Durasi << "  | "
                 << left << setw(25) << (infoFilm(P).Sinopsis.size() > 25 ? infoFilm(P).Sinopsis.substr(0, 22) + "..." : infoFilm(P).Sinopsis) << " |" << endl;

            P = nextFilm(P);
            j++;
        }

        cout << "=======================================================================================================================" << endl;
        }
        cout << endl;
        cout << endl;
}



adrfilm searchFilm(List L, string judul){
    // IS: List L mungkin kosong atau berisi satu atau lebih elemen film.
    // FS: Jika ditemukan, fungsi mengembalikan alamat elemen film dengan judul yang cocok.
    //     Jika tidak ditemukan, fungsi mengembalikan NULL.
    adrfilm P = first(L);
    while(P!=NULL){
        if(infoFilm(P).Judul == judul){
           return P;
        }
        P = nextFilm(P);
    }
    return NULL;
};

void deleteFirstFilm(List &L, adrfilm &P){
    // IS: List L mungkin kosong, atau berisi satu atau lebih elemen film.
    // FS: Elemen pertama pada list telah dihapus.
    if(nextFilm(P)==NULL){
        P = first(L);
        first(L)=NULL;
        last(L)=NULL;
    }else{
        P = first(L);
        first(L) = nextFilm(P);
        prevFilm(first(L)) = NULL;
        nextFilm(P) = NULL;
    }
};

void deleteLastFilm(List &L, adrfilm &P){
    //List L memiliki elemen film minimal satu (tidak kosong).
    //Film terakhir dalam List L berhasil dihapus.
    P = last(L);
    last(L) = prevFilm(P);
    nextFilm(last(L)) = NULL;
    prevFilm(P) = NULL;
};

void deleteAfterFilm(List &L,adrfilm &P){
        //List L memiliki minimal tiga elemen film (tidak kosong dan tidak hanya dua elemen).
        //Elemen film yang berada pada posisi P berhasil dihapus dari List L.
        adrfilm prev = prevFilm(P);
        nextFilm(prev) = nextFilm(P);
        prevFilm(nextFilm(P)) = prev;
        nextFilm(P) = NULL;
        prevFilm(P) = NULL;
};

void deleteFilm(List &L){
    //List L memiliki minimal satu elemen film.
    //Film dengan judul yang dimasukkan telah dihapus sepenuhnya dari List L.
    string judul;
    cout <<"Masukan judul: ";
    cin >> judul;
    adrfilm P = searchFilm(L,judul);
    if(P!=NULL){
        while(firstPenonton(P)!=NULL){
            adrPenonton Q = firstPenonton(P);
            deleteFirstPenonton(P,Q);
        }
        if(P == first(L)){
            deleteFirstFilm(L,P);
        }else if(P == last(L)){
            deleteLastFilm(L,P);
        }else{
            deleteAfterFilm(L,P);
        }
        cout <<"Film dengan judul "<<infoFilm(P).Judul<<" telah berhasil dihapus"<<endl;
    }else{
        cout <<endl;
        cout << "========= judul tidak ditemukan ========" << endl;
        cout << "== Silahkan masukkan judul yang valid =="<< endl;
        cout <<endl;
        deleteFilm(L);
    }
};

void updateFilm(List &L){
    //List L memiliki minimal satu elemen film.]
    //Film yang sesuai dengan judul yang dimasukkan telah diperbarui.
    string judul;
    cout <<"Masukan judul: ";
    cin >> judul;
    adrfilm P = searchFilm(L,judul);
    if(P!=NULL){
        infotypeF info;
        cout <<"Masukan judul yang baru: ";
        cin >> info.Judul;
        infoFilm(P).Judul = info.Judul;
        cout <<"Masukan rating yang baru: ";
        cin >> info.Rating;
        infoFilm(P).Rating = info.Rating;
        cout <<"Masukan sinopsis yang baru: ";
        cin >> info.Sinopsis;
        infoFilm(P).Sinopsis = info.Sinopsis;
        cout <<"Masukan batasan umur yang baru: ";
        cin >> info.Batasan_Umur;
        infoFilm(P).Batasan_Umur = info.Batasan_Umur;
        cout <<"Masukan genre yang baru: ";
        cin >> info.Genre;
        infoFilm(P).Genre = info.Genre;
        cout <<"Masukan durasi yang baru: ";
        cin >> info.Durasi;
        infoFilm(P).Durasi = info.Durasi;
        cout<<endl;
        cout<<"Data film telah berhasil di update"<<endl;
    }else{
        cout <<endl;
        cout << "========= judul tidak ditemukan ========" << endl;
        cout << "== Silahkan masukkan judul yang valid =="<< endl;
        cout <<endl;
        updateFilm(L);
    }
};

void input_test(List &L, infotypeF data,infotypeP dataP) {
    //List L kosong (tidak memiliki elemen film atau penonton).
    //List L memiliki tiga elemen film.


    // Data film pertama
    data.Judul = "Dilan_1990";
    data.Batasan_Umur = 13;
    data.Durasi = "1 Jam 50 Menit";
    data.Rating = 7.6;
    data.Genre = "Romantis";
    data.Sinopsis = "Kisah cinta remaja Dilan dan Milea yang penuh romantisme di Bandung tahun 1990.";
    adrfilm x = createElmFilm(data);
    inserLastFilm(L,x);
    // Data film kedua
    data.Judul = "Pengabdi_Setan";
    data.Batasan_Umur = 17;
    data.Durasi = "1 Jam 47 Menit";
    data.Rating = 8.0;
    data.Genre = "Horor";
    data.Sinopsis = "Seorang ibu yang telah meninggal kembali menghantui keluarganya dalam teror penuh misteri.";
    x = createElmFilm(data);
    inserLastFilm(L,x);
    // Data film ketiga
    data.Judul = "Laskar_Pelangi";
    data.Batasan_Umur = 7;
    data.Genre = "Family";
    data.Durasi = "2 Jam 45 Menit";
    data.Rating = 7.8;
    data.Sinopsis = "Perjuangan anak-anak Belitung dalam menggapai mimpi melalui pendidikan meskipun hidup dalam keterbatasan.";
    x = createElmFilm(data);
    inserLastFilm(L,x);

    showAllFilm(L);


    adrPenonton y;
    adrfilm F;
    dataP.Nama = "Wahyu";
    dataP.Umur = 18;
    y = createElmPenonton(dataP);
    F = searchFilm(L,"Dilan_1990");
    insertFirstPenonton(L,y,F);

    dataP.Nama = "Budi";
    dataP.Umur = 25;
    y = createElmPenonton(dataP);
    F = searchFilm(L,"Laskar_Pelangi");
    insertFirstPenonton(L, y,F);

    dataP.Nama = "Siti";
    dataP.Umur = 30;
    y = createElmPenonton(dataP);
    F = searchFilm(L,"Pengabdi_Setan");
    insertFirstPenonton(L, y,F);

}




















//Penonton
adrPenonton createElmPenonton(infotypeP info){
    //
    //Elemen penonton baru (P) dikembalikan oleh fungsi sebagai hasil.
    adrPenonton P = new elmPenonton;
    infoPenonton(P).Nama = info.Nama;
    infoPenonton(P).Umur = info.Umur;
    nextPenonton(P) = NULL;
    return P;
};

void insertFirstPenonton(List &L, adrPenonton P, adrfilm F){
    //List L memiliki elemen film yang telah ada.
    //Elemen penonton baru (P) berhasil ditambahkan sebagai penonton pertama untuk film F.
    if(firstPenonton(F)==NULL){
        firstPenonton(F)=P;
    }else{
        nextPenonton(P) = firstPenonton(F);
        firstPenonton(F) = P;
    }
};


void deleteFirstPenonton(adrfilm &P, adrPenonton Q ){
    //Film P memiliki daftar penonton yang tidak kosong.
    //Elemen penonton pertama dihapus dari daftar.
    Q = firstPenonton(P);
    firstPenonton(P) = nextPenonton(Q);
    nextPenonton(Q) = NULL;
};

void deleteLastPenonton(adrfilm &P, adrPenonton Q){
    //Film P memiliki daftar penonton dengan minimal satu elemen.
    //Elemen penonton terakhir dari daftar telah dihapus.
    Q = firstPenonton(P);
    while(nextPenonton(nextPenonton(Q))!=NULL){
        Q = nextPenonton(Q);
    }
    nextPenonton(Q)=NULL;

};
void deleteAfterPenonton(adrfilm &P, adrPenonton Q){
    //Film P memiliki daftar penonton dengan lebih dari satu elemen.
    //Elemen penonton Q berhasil dihapus.
    adrPenonton prec = firstPenonton(P);
    while(nextPenonton(prec)!=Q){
        prec = nextPenonton(prec);
    }
    nextPenonton(prec) = nextPenonton(Q);
    nextPenonton(Q) = NULL;
};


adrPenonton searchPenontonInFilm(List L,string nama){
    //List L berisi elemen-elemen film.
    //Jika nama penonton yang dimasukkan ditemukan (infoPenonton(Q).Nama == nama), fungsi mengembalikan pointer Q yang menunjuk ke elemen penonton tersebut.
    //Jika nama penonton tidak ditemukan di seluruh film, fungsi mengembalikan NULL.
    adrfilm P = first(L);
    while(P!=NULL){
        adrPenonton Q = firstPenonton(P);
        while(Q!=NULL){
            if(infoPenonton(Q).Nama == nama){
                return Q;
            }
            Q = nextPenonton(Q);
        }
        P = nextFilm(P);
    }
    return NULL;
};

void deletePenonton(List &L){
    //List L berisi beberapa film dengan daftar penonton masing-masing.
    //Penonton yang sesuai dengan nama yang dimasukkan dihapus dari daftar penonton film.
    string judul;
    cout <<"Masukan judul film yang sedang ditonton: ";
    cin >> judul;
    adrfilm P = searchFilm(L,judul);
    if(P!=NULL){
        string nama;
        cout<<"Masukan nama penonton: ";
        cin >> nama;
        adrPenonton Q = searchPenontonInFilm(L,nama);
        while(Q==NULL){
                cout <<endl;
                cout << "========= Nama tidak ditemukan ========" << endl;
                cout << "== Silahkan masukkan nama yang valid =="<< endl;
                cout <<endl;
                string namaBaru;
                cout<<"Masukan nama penonton: ";
                cin >> namaBaru;
                Q = searchPenontonInFilm(L,namaBaru);

        }
            if(Q==firstPenonton(P)){
                deleteFirstPenonton(P,Q);
            }else if(nextPenonton(Q)==NULL){
                deleteLastPenonton(P,Q);
            }else{
                deleteAfterPenonton(P,Q);
            }
            cout <<"Penonton dengan nama " << infoPenonton(Q).Nama << " telah dihapus"<<endl;

    }else{
        cout <<endl;
        cout << "========= judul tidak ditemukan ========" << endl;
        cout << "== Silahkan masukkan judul yang valid =="<< endl;
        cout <<endl;
        deletePenonton(L);
    }
};

void updatePenonton(List &L){
    //Terdefinisi List L tidak kosong,List berisi film beserta penonton.
    //Data penonton yang ditemukan berhasil diupdate
    string nama;
    cout <<"Masukan nama penonton: ";
    cin >>nama;
    adrPenonton P = searchPenontonInFilm(L,nama);
    if(P!=NULL){
        infotypeP data;
        cout <<"Masukan nama yang baru: ";
        cin >> data.Nama;
        infoPenonton(P).Nama = data.Nama;
        cout <<"Masukan umur yang baru: ";
        cin >> data.Umur;
        infoPenonton(P).Umur = data.Umur;
        cout << endl;
        cout <<"Data penonton telah berhasil di update"<<endl;
    }else{
        cout << "Nama tidak ditemukan" << endl;
        cout << "== Silahkan masukkan nama yang valid =="<< endl;
        updatePenonton(L);
    }
};

int countTotalPenonton(List L){
    //List L berisi beberapa film dengan daftar penonton masing-masing.
    //menghitung total jumlah penonton yang ada di seluruh film dalam daftar
    int total = 0;
    adrfilm p = first(L);
    while(p != NULL){
        adrPenonton q = firstPenonton(p);
        while(q != NULL){
            total++;
            q = nextPenonton(q);
        }
        p = nextFilm(p);
    }
    return total;
};

void showFilmdanPenonton(List &L) {
    //List L berisi beberapa film, masing-masing dengan daftar penonton.
    //menampilkan daftar film dan penontonnya dalam format tabel yang terstruktur.
    adrPenonton P;
    adrfilm F;
    int i = 1;
    int j = 1;
    if (first(L) == NULL) {
        cout << "List film kosong" << endl;
    } else {
        F = first(L);
        while (F != NULL) {
            // Display film data
            cout << "\033[32m=======================================================================================================================\033[0m" << endl;
            cout << "=======================================================================================================================" << endl;

            cout << "|  No Film    | Judul             | Rating |  Batasan Umur |      Genre      |      Durasi    |      Sinopsis         |" << endl;
            cout << "=======================================================================================================================" << endl;
            cout << "| " << setw(11) << j << " | "
                 << setw(17) << infoFilm(F).Judul << " | "
                 << setw(6) << infoFilm(F).Rating << " | "
                 << setw(13) << infoFilm(F).Batasan_Umur << " | "
                 << setw(15) << infoFilm(F).Genre << " | "
                 << setw(6) << infoFilm(F).Durasi << " | "
                 << setw(18) << infoFilm(F).Sinopsis.substr(0, 18) << (infoFilm(F).Sinopsis.size() > 18 ? "..." : "") << " |" << endl;
            cout << "=======================================================================================================================" << endl;

            // Display data penonton
            P = firstPenonton(F);
            if (P == NULL) {
                cout << "\nTidak ada penonton untuk film ini." << endl;
            } else {
                cout << "=======================================================================================================================" << endl;
                cout << "| No Penonton | Nama              |  Umur  |" << endl;
                cout << "=======================================================================================================================" << endl;
                while (P != NULL) {
                    cout << "| " << setw(11) << i << " | "
                         << setw(17) << infoPenonton(P).Nama << " | "
                         << setw(6) << infoPenonton(P).Umur << " |" << endl;
                    i++;
                    P = nextPenonton(P);
                }
            cout << "=======================================================================================================================" << endl;
            cout << "\033[32m=======================================================================================================================\033[0m" << endl;
            }

            F = nextFilm(F);
            cout << "\n\n"; // Add spacing between films
            i = 1;
            j++;
        }
    }
}

void Print_penonton(List &L){
//List L berisi beberapa film, masing-masing dengan daftar penonton.
//Fungsi menampilkan tabel dengan dua kolom: Nama Penonton dan Umur.
adrfilm F;
adrPenonton P;

F = first(L);

// Menampilkan header tabel
cout << setw(20) << "Nama Penonton"
     << setw(10) << "Umur"
     << endl;
cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;

    while (F != NULL) {
        P = firstPenonton(F);
            while (P != NULL) {
                cout << setw(20) << infoPenonton(P).Nama
                    << setw(10) << infoPenonton(P).Umur
                    << endl;
        P = nextPenonton(P);
    }
    F = nextFilm(F);
}
}
