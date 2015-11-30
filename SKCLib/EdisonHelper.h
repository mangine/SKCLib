#ifndef EDISONHELPER_H_INCLUDED
#define EDISONHELPER_H_INCLUDED

class EdisonHelper{

    static void DisableWiFi(){
        system("systemctl stop wpa_supplicant");
    }

    static void EnableWiFi(){
        system("systemctl restart wpa_supplicant");
    }

    static void EnableBluetooth(){
        system("rfkill unblock bluetooth");
    }

    static void DisableBluetooth(){
        system("rfkill block bluetooth");
    }

};

#endif // EDISONHELPER_H_INCLUDED
